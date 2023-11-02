#include "main.h"
#include <iostream>
#include <list>
#include "tcp_server.h"
#include "../common_lib/args_config_loader.h"
#include "../common_lib/config_load_helper.h"
#include "../common_lib/config_manager.h"




void load_config(int argc, char* argv[])
{   
    auto args_loader = new common_lib::args_config_loader(argc, argv);
    common_lib::config_load_helper::register_loader(args_loader);

    
    common_lib::config_load_helper::load();
    auto& val = common_lib::config_manager::get_instance().find("PORT");
}




void run_server()
{
    boost::asio::io_context io_context;
    tcp_server server(io_context);
    io_context.run();
}




int main(int argc, char* argv[])
{
    try
    {
        load_config(argc, argv);
        run_server();
    }
    catch (std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}
