#include <iostream>
#include <cstdlib>
#include "foo.hpp"
#include "cpu6502.hpp"

// foo nice;
int main(void){
    foo *nice = new foo();
    cpu6502 state_6502;
    std:: cout << "Hello, World!" << std:: endl;
    // std:: free(&nice);


    delete nice;
    std:: cout << "nice" << std:: endl;
    // std:: free(nice);
    return 0;
}