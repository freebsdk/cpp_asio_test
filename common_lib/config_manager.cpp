#include "pch.h"
#include "config_manager.h"

using namespace common_lib;




void config_manager::set(const std::string& cfg_key, const std::string& cfg_val)
{
	if (cfg_key.empty()) return;
	cfg_map_[cfg_key] = cfg_val;
}




const std::optional<std::string*> config_manager::find(const std::string& cfg_key)
{
	auto iter = cfg_map_.find(cfg_key);
	if (iter == cfg_map_.end()) return std::nullopt;

	return std::optional<std::string*>(&iter->second);
}




void config_manager::remove(const std::string& cfg_key)
{
	if (cfg_map_.find(cfg_key) == cfg_map_.end()) return;
	cfg_map_.erase(cfg_key);
}