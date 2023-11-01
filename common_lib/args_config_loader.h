#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "abstract_config_loader.h"


namespace common_lib
{
	class args_config_loader : abstract_config_loader
	{
	private:

		int argc_;
		std::vector<std::string> argv_vec_;

	public:

		args_config_loader(int argc, char* argv[]);

		// Inherited via abstract_config_loader
		void Load() override;

	};




}
