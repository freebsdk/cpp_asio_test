#pragma once



namespace common_lib
{
	class abstract_config_loader
	{
	public:

		virtual void Load() = 0;
	};
}