#include <iostream>

#include "Pointers.h"


int main()
{


    SmartPointer<int> p(new int{1});
    SmartPointer<int> p1;

    std::cout << p.isEmpty() << '\n';
    std::cout << p1.isEmpty() << '\n';

    p1 = p;


    std::cout << p.isEmpty() << '\n';
    std::cout << p1.isEmpty() << '\n';

    return 0;
}

