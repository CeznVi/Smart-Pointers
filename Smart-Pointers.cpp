#include <iostream>
#include <Windows.h>
#include "Student.h"
#include "Pointers.h"


int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);


    //SmartPointer - базовий клас розумного покажчика.
    //UniqPtr - похідний клас розумного покажчика(походить від SmartPointer)

    UniqPtr<Student> p = new Student("Петро Олексійович", 55);
    UniqPtr<Student> p1;

    std::cout << "Is empty p = " << p.isEmpty() << '\n';
    std::cout << "Is empty p1 = " << p1.isEmpty() << '\n';

    p1 = (p);

    cout << "P print =";

    if (!p.isEmpty())
        p->print();
    else
        cout << "= nullptr";

    cout << "\nP1 print = ";
    p1->print();

        
    std::cout << "Is empty p = " << p.isEmpty() << '\n';
    std::cout << "Is empty p1 = " << p1.isEmpty() << '\n';




    return 0;
}

