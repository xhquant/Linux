////////////////////////////////////////////////////////////////////////
/// \file      derived_class_2.cpp
/// \copyright Copyright (c) 2022 标准模型投资有限公司.
///            All rights reserved.
///            Licensed under the MIT License.
/// \author    金小海
/// \date      2022年08月30日, Tue, 14:35
/// \version   1.0
/// \brief
#ifndef DERIVED_CLASS_2_CPP
#define DERIVED_CLASS_2_CPP

#include <string>
#include <iostream>

#include "base_class.hpp"

namespace Linux
{
    class derived_class_2 : public base_class
    {
    public:
        explicit derived_class_2(std::string _name);

        ~derived_class_2() override = default;

    public:
        std::string get_name() override;

        float calculate(float x1, float x2) override;

    private:
        std::string name;
    };


    ////////////////////////////////////////////////////////////////////////
    /// \brief
    /// \param _name
    inline
    derived_class_2::derived_class_2(std::string _name)
    {
        name = std::move(_name);
    }


    ////////////////////////////////////////////////////////////////////////
    /// \brief
    /// \return
    inline
    std::string derived_class_2::get_name()
    {
        return name;
    }


    ////////////////////////////////////////////////////////////////////////
    /// \brief
    /// \param x1
    /// \param x2
    /// \return
    inline
    float derived_class_2::calculate(float x1, float x2)
    {
        std::cout << "执行乘法运算: x1 * x2 = " << x1 * x2 << std::endl;
        return x1 * x2;
    }
}

extern "C" {
Linux::base_class *create_derived_class(const std::string &params)
{
    return new Linux::derived_class_2(params);
}
}


#endif //DERIVED_CLASS_2_CPP