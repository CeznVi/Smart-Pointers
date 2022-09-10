#include <iostream>
#include <Windows.h>
#include "Student.h"
#include "Pointers.h"


int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    cout.setf(ios::boolalpha);
    //SmartPointer - базовий клас розумного покажчика.
    //UniqPtr - похідний клас розумного покажчика(походить від SmartPointer)
    //SharedPtr - похідний клас розумного покажчика(походить від SmartPointer)

    ////Тест SmartPointer
    {
        std::cout << "ТЕСТ смарт птр\n";
        SmartPointer<Student> pp = new Student("Петро Смартович", 55);
        SmartPointer<Student> p = new Student("Петро Унікович", 55);
        SmartPointer <Student> p1;
        std::cout << "Is empty p = " << p.isEmpty() << '\n';
        std::cout << "Is empty p1 = " << p1.isEmpty() << '\n';

        //ERROR!!
        p1 = p;
        cout << "P print =";
        if (!p.isEmpty())
            p->print();
        else
            cout << "= nullptr";
        cout << "P1 print = ";
        p1->print();
        std::cout << "Is empty p = " << p.isEmpty() << '\n';
        std::cout << "Is empty p1 = " << p1.isEmpty() << '\n';

    }
    system("pause");
    system("cls");

    ////Тест UniqPtr
    {
        std::cout << "ТЕСТ унік птр\n";
        UniqPtr<Student> p = new Student("Петро Олексійович", 55);
        UniqPtr<Student> p1;
        std::cout << "Чи пустий покажчик p = " << p.isEmpty() << '\n';
        std::cout << "Чи пустий покажчик p1 = " << p1.isEmpty() << '\n';
        std::cout << "Перевірка метода гет р: " << p.get() << '\n';
        std::cout << "Перевірка метода гет р1: " << p1.get() << '\n';
        std::cout << "Робимо мув\n";
        ////ERROR!
        ////p1 = p;
        p1 = move(p);
        std::cout << "Чи пустий покажчик p = " << p.isEmpty() << '\n';
        std::cout << "Чи пустий покажчик p1 = " << p1.isEmpty() << '\n';
        std::cout << "Перевірка метода гет р: " << p.get() << '\n';
        std::cout << "Перевірка метода гет р1: " << p1.get() << '\n';

    }
    system("pause");
    system("cls");

    ////Тест SharedPtr
    {
    std::cout << "ТЕСТ шаред птр\n";
    SharedPtr<Student> p = new Student("Петро Олексійович", 55);
    SharedPtr<Student> p1, p2;

    std::cout << "Чи пустий покажчик p = " << p.isEmpty() << '\n';
    std::cout << "Чи пустий покажчик p1 = " << p1.isEmpty() << '\n';
    std::cout << "Чи пустий покажчик p2 = " << p2.isEmpty() << '\n';


    std::cout << "Присвоєння покажчикам р1,р2 значення р\n";
    p1 = p;
    p2 = p;

    std::cout << "Чи пустий покажчик p = " << p.isEmpty() << '\n';
    std::cout << "Чи пустий покажчик p1 = " << p1.isEmpty() << '\n';
    std::cout << "Чи пустий покажчик p2 = " << p2.isEmpty() << '\n';
    std::cout << "p гет = " << p.get() << '\n';
    std::cout << "p1 гет = " << p1.get() << '\n';
    std::cout << "p2 гет = " << p2.get() << '\n';
    std::cout << "p гет коунт = " << p.get_count() << '\n';
    std::cout << "p1 гет коунт = " << p1.get_count() << '\n';
    std::cout << "p2 гет коунт = " << p2.get_count() << '\n';
    std::cout << "Clear р1,р2 \n";
    p2.clear();
    p1.clear();
    std::cout << "Чи пустий покажчик p = " << p.isEmpty() << '\n';
    std::cout << "Чи пустий покажчик p1 = " << p1.isEmpty() << '\n';
    std::cout << "Чи пустий покажчик p2 = " << p2.isEmpty() << '\n';
    std::cout << "p гет = " << p.get() << '\n';
    std::cout << "p1 гет = " << p1.get() << '\n';
    std::cout << "p2 гет = " << p2.get() << '\n';
    std::cout << "p гет коунт = " << p.get_count() << '\n';

    /////error
    ///p2->print();


    p->print();

    if (p1.isEmpty() != 1)
        p1->print();
    else
        std::cout << "P1 пустий\n";

    std::cout << "КІНЕЦЬ" << '\n';

    }

    return 0;
}

