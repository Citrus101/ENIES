#include <iostream>
#include "foo.hpp"

foo::foo(/* args */)
{
    std:: cout << "foo has been created" << std:: endl; 
}

foo::~foo()
{
    std:: cout << "foo has been destroyed" << std:: endl; 
}
