#include "pch.h"
#include "config_load_helper.h"





using namespace common_lib;

std::list< abstract_config_loader* > config_load_helper::loaders_;




void config_load_helper::register_loader(abstract_config_loader* loader)
{
	loaders_.push_back(loader);
}





void config_load_helper::load()
{
	for (auto loader : loaders_)
	{
		loader->Load();
	}
}
