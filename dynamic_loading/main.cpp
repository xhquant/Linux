#include <iostream>
#include <vector>

#include "base_class.hpp"
#include "module_handler.hpp"

int main(int argc, char **argv)
{
    std::vector<Linux::base_class *> vec;

    Linux::base_class *baseClass;

    baseClass = Linux::module_handler::create("../lib/libderived_class_1.so", "加法派生类");
    vec.push_back(baseClass);
    baseClass = Linux::module_handler::create("../lib/libderived_class_2.so", "乘法派生类");
    vec.push_back(baseClass);

    for (auto e: vec)
    {
        std::cout << e->get_name() << "   " << e->calculate(2, 4) << std::endl;
    }

    return 0;
}