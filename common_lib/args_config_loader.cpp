#include "pch.h"
#include "args_config_loader.h"
#include "config_manager.h"
#include <boost/tokenizer.hpp>




using namespace common_lib;

args_config_loader::args_config_loader(int argc, char* argv[])
	: argc_(argc)
{
	for (int i = 1; i < argc; ++i)
	{
		argv_vec_.push_back(argv[i]);
	}
}




void args_config_loader::Load()
{
	boost::char_separator<char> separator("=");

	for(const std::string& argv_str : argv_vec_)
	{
		boost::tokenizer<boost::char_separator<char>> tokens(argv_str, separator);
		
		std::vector<std::string> token_vec;
		for (auto& token : tokens) token_vec.push_back(token);

		if (token_vec.size() == 1)
		{
			config_manager::get_instance().set(token_vec[0], "true");
		}
		else
		{
			config_manager::get_instance().set(token_vec[0], token_vec[1]);
		}		
	}
}
