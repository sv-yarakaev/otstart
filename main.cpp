#include "lib.h"

#include <iostream>

int main()
{
    //auto logger = spdlog::stdout_logger_mt("console");
    std::cout <<"version " <<version() <<  " was started" << std::endl;

    return 0;
}
