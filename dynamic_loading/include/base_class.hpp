////////////////////////////////////////////////////////////////////////
/// \file      base_class.hpp
/// \copyright Copyright (c) 2022 标准模型投资有限公司.
///            All rights reserved.
///            Licensed under the MIT License.
/// \author    金小海
/// \date      2022年08月30日, Tue, 14:08
/// \version   1.0
/// \brief
#ifndef BASE_CLASS_HPP
#define BASE_CLASS_HPP

namespace Linux
{
    class base_class
    {
    public:
        virtual ~base_class() = default;

    public:
        virtual std::string get_name() = 0;

        virtual float calculate(float x1, float x2) = 0;
    };
}

#endif //BASE_CLASS_HPP