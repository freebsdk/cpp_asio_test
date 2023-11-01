#pragma once
#include <iostream>
#include <map>
#include <optional>


namespace common_lib
{
	class config_manager
	{
	private:

		std::map< std::string, std::string > cfg_map_;

	public:

		static config_manager& get_instance()
		{
			static config_manager instance;
			return instance;
		}

		void set(const std::string& cfg_key, const std::string& cfg_val);
		const std::optional<std::string*> find(const std::string& cfg_key);
		void remove(const std::string& cfg_key);

	};

}