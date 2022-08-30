////////////////////////////////////////////////////////////////////////
/// \file      module_handler.hpp
/// \copyright Copyright (c) 2022 标准模型投资有限公司.
///            All rights reserved.
///            Licensed under the MIT License.
/// \author    金小海
/// \date      2022年08月30日, Tue, 14:15
/// \version   1.0
/// \brief
#ifndef MODULE_HANDLER_HPP
#define MODULE_HANDLER_HPP

#include "dlfcn.h"
#include "base_class.hpp"

namespace Linux
{
    ////////////////////////////////////////////////////////////////////////
    /// \brief
    class base_module_handler
    {
    protected:
        static void *load(const std::string &lib_path)
        {
            void *ptrHandle = dlopen(lib_path.c_str(), RTLD_LAZY);
            if (!ptrHandle)
            {
                printf("dlopen - %s\n", dlerror());
                std::cout << "load " + lib_path + " failed!" << std::endl;
            }
            return ptrHandle;
        }
    };

    ////////////////////////////////////////////////////////////////////////
    /// \brief
    class module_handler : private base_module_handler
    {
    public:
        static base_class *create(const std::string &lib_path, const std::string &params)
        {
            void *pHandle = load(lib_path);
            // 生成函数指针
            auto create_handler = (base_class *(*)(const std::string &params)) dlsym(pHandle, "create_derived_class");
            return create_handler(params);
        }
    };
}

#endif //MODULE_HANDLER_HPP