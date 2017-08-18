#include <iostream>

#include "selfea/config.hpp"

int main(void)
{
    std::cout << "Welcome to SELFEA!" << std::endl;
    std::cout << "BUILD_DATE: " << BUILD_DATE << std::endl;
    std::cout << "BUILD_TIME: " << BUILD_TIME << std::endl;
    std::cout << "BUILD_TYPE: " << BUILD_TYPE << std::endl;
    std::cout << "SYSTEM: " << SYSTEM << std::endl;
    std::cout << "SYSTEM_NAME: " << SYSTEM_NAME << std::endl;
    std::cout << "PROCESSOR: " << PROCESSOR << std::endl;
    std::cout << "COMPILER_ID: " << COMPILER_ID << std::endl;
    std::cout << "PACKAGE_NAME: " << PACKAGE_NAME << std::endl;
    std::cout << "VERSION: " << VERSION << std::endl;

    std::cout << "INT: " << SELFEA_SIZEOF_INT << std::endl;
    std::cout << "LONG: " << SELFEA_SIZEOF_LONG << std::endl;
    std::cout << "CHAR: " << SELFEA_SIZEOF_CHAR << std::endl;
    std::cout << "SHORT: " << SELFEA_SIZEOF_SHORT << std::endl;
    std::cout << "LONG_LONG: " << SELFEA_SIZEOF_LONG_LONG << std::endl;
    std::cout << "FLOAT: " << SELFEA_SIZEOF_FLOAT << std::endl;
    std::cout << "DOUBLE: " << SELFEA_SIZEOF_DOUBLE << std::endl;
    std::cout << "LONG_DOUBLE: " << SELFEA_SIZEOF_LONG_DOUBLE << std::endl;

    Real_t r = 5.0;

    std::cout << "Real_t works! " << r << std::endl;
    
    return(0);
}
