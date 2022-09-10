﻿#include <iostream>
#include <Windows.h>
#include "Student.h"
#include "Pointers.h"


int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);


    //SmartPointer - базовий клас розумного покажчика.
    //UniqPtr - похідний клас розумного покажчика(походить від SmartPointer)


    ////Тест ЮнікПТР
    {
        //SmartPointer<Student> pp = new Student("Петро Смартович", 55);
        //SmartPointer<Student> p = new Student("Петро Унікович", 55);
        //SmartPointer <Student> p1;
        //std::cout << "Is empty p = " << p.isEmpty() << '\n';
        //std::cout << "Is empty p1 = " << p1.isEmpty() << '\n';
        //move ф-ція з простору імен СТД (робить об'кт R-value, та спрацьовує оператор переносу)
        //p1 = move(p);
        //ERROR!!
        //p1 = p;
        //cout << "P print =";
        //if (!p.isEmpty())
        //    p->print();
        //else
        //    cout << "= nullptr";
        //cout << "\nP1 print = ";
        //p1->print();
        //std::cout << "Is empty p = " << p.isEmpty() << '\n';
        //std::cout << "Is empty p1 = " << p1.isEmpty() << '\n';
    }


    ////Тест ШаредПТР
    {
        //UniqPtr<Student> p = new Student("Петро Олексійович", 55);
        //UniqPtr<Student> p1;
        //std::cout << "Чи пустий покажчик p = " << p.isEmpty() << '\n';
        //std::cout << "Чи пустий покажчик p1 = " << p1.isEmpty() << '\n';
        //std::cout << "Перевірка метода гет р: " << p.get() << '\n';
        //std::cout << "Перевірка метода гет р1: " << p1.get() << '\n';
        //std::cout << "Робимо мув\n";
        //////ERROR!
        //////p1 = p;
        //p1 = move(p);
        //std::cout << "Чи пустий покажчик p = " << p.isEmpty() << '\n';
        //std::cout << "Чи пустий покажчик p1 = " << p1.isEmpty() << '\n';
        //std::cout << "Перевірка метода гет р: " << p.get() << '\n';
        //std::cout << "Перевірка метода гет р1: " << p1.get() << '\n';
    }

    return 0;
}

