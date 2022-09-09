#include <iostream>
#include <Windows.h>

#include "Pointers.h"


int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    UniqPtr<int> p(new int (3));
    UniqPtr<int> p1;

    std::cout << p.isEmpty() << '\n';
    std::cout << p1.isEmpty() << '\n';

    p1 = p;

        
    std::cout << p.isEmpty() << '\n';
    std::cout << p1.isEmpty() << '\n';




    return 0;
}

