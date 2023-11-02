#pragma once
#include <list>
#include <memory>
#include "abstract_config_loader.h"




namespace common_lib 
{
	class config_load_helper
	{
	private:

		static std::list< abstract_config_loader* > loaders_;

	public:

		static void register_loader(abstract_config_loader* loader);
		static void load();
	};
}