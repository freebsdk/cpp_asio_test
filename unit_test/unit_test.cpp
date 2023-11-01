#include "pch.h"
#include "CppUnitTest.h"
#include "../common_lib/config_manager.h"


using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace common_lib;

namespace unittest
{
	TEST_CLASS(unittest)
	{
	public:

		TEST_METHOD(SingleSet)
		{
			config_manager::get_instance().set("abcd", "1234");
			auto found_val = config_manager::get_instance().find("abcd");

			Assert::AreEqual("1234", (*found_val)->c_str());
		}




		TEST_METHOD(DuplicateSet)
		{
			config_manager::get_instance().set("abcd", "1234");
			config_manager::get_instance().set("abcd", "4567");
			auto found_val = config_manager::get_instance().find("abcd");

			Assert::AreEqual("4567", (*found_val)->c_str());
		}




		TEST_METHOD(Remove)
		{
			config_manager::get_instance().set("abcd", "1234");
			config_manager::get_instance().remove("abcd");

			auto found_val = config_manager::get_instance().find("abcd");

			Assert::IsFalse(found_val.has_value());
		}
	};
}