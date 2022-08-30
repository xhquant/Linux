#include <iostream>
#include <vector>

#include "tinyxml2.h"

#include "base_class.hpp"
#include "module_handler.hpp"

int main(int argc, char **argv)
{
    Linux::base_class *baseClass;
    std::vector<Linux::base_class *> manager;

    tinyxml2::XMLDocument doc;
    if (tinyxml2::XML_SUCCESS != doc.LoadFile("../dynamic_loading/config/config.xml")) return -1;

    auto *cfg = doc.RootElement();
    if (cfg)
    {
        auto lib = cfg->FirstChildElement("lib");
        while (lib)
        {
            std::string lib_path = lib->Attribute("lib_path");
            std::string params = lib->Attribute("params");

            baseClass = Linux::module_handler::create(lib_path, params);
            manager.push_back(baseClass);
            std::cout << "加载动态库: " << lib_path << std::endl;

            lib = lib->NextSiblingElement();
        }
    }

    for (auto ele: manager)
    {
        // std::cout << ele->get_name() << std::endl;
        ele->calculate(2, 4);
    }

    return 0;
}