#include "pch.h"
#include "json_config_loader.h"
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/json_parser.hpp>
#include "config_manager.h"





using namespace common_lib;

json_config_loader::json_config_loader(const std::string& file_name)
	: file_name_(file_name)
{

}




void json_config_loader::Load()
{
	boost::property_tree::ptree pt;

    try 
    {
        boost::property_tree::read_json(file_name_, pt);

        for (const auto& item : pt) 
        {
            auto cfg_key = item.second.get<std::string>("key");
            auto cfg_val = item.second.get<std::string>("value");
         
            config_manager::get_instance().set(cfg_key, cfg_val);
        }
    }
    catch (const std::exception& e) 
    {
        std::cerr << "Error: " << e.what() << std::endl;
    }
}
