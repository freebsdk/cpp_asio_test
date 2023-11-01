#pragma once
#include <iostream>
#include <string>
#include "abstract_config_loader.h"




namespace common_lib
{

	class json_config_loader : abstract_config_loader
	{
	private:

		std::string file_name_;

	public:

		json_config_loader(const std::string& file_name);


		// Inherited via iconfig_loader
		void Load() override;
	};
}