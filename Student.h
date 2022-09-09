#pragma once
#include<iostream>
#include<fstream>
#include"Library/Func.h"

using namespace std;

class Student
{

	char* name = nullptr;
	int age;
	int* mark = nullptr;
	int sizeMark = 0;

public:
	Student() : Student("No name", 0) { cout << "Створення студента 0 param" << endl; }
	Student(const char* n, int a);
	Student(const Student& obj);
	Student& operator=(const Student& obj);
	~Student();
	void print() const;
	void setAge(int a);
	void setName(const char* n);
	int  getAge() const;
	char* getName() const;
	void setMark(int m);
	void save(ofstream& out);
	void load(ifstream& in);
};


Student::Student(const char* n, int a)
{
	cout << "Створення студента 2 param" << endl;
	this->setAge(a);
	this->setName(n);
}

inline Student::Student(const Student& obj)
{
	cout << "Конструктор копіювання студента" << endl;
	this->setName(obj.name);
	this->age = obj.age;
	this->sizeMark = obj.sizeMark;
	this->mark = new int[obj.sizeMark];
	for (size_t i = 0; i < obj.sizeMark; i++)
	{
		this->mark[i] = obj.mark[i];
	}
}

Student& Student::operator=(const Student& obj)
{
	if (this == &obj)
		return *this;

	this->~Student();

	this->setName(obj.name);
	this->age = obj.age;
	this->sizeMark = obj.sizeMark;
	this->mark = new int[obj.sizeMark];
	for (size_t i = 0; i < obj.sizeMark; i++)
	{
		this->mark[i] = obj.mark[i];
	}

	return *this;
}

Student::~Student()
{
	cout << "Деструктор студента " << name << endl;
	delete name;
	name = nullptr;
	delete[] mark;
	mark = nullptr;
}

void Student::print() const
{
	cout << "Ім`я: " << this->name << ", Вік: " << age << ", Оцінки: ";
	printArray(mark, sizeMark);
}

void Student::setAge(int a)
{
	if (a < 0 || a > 110)
	{
		cout << "Не вірні дані" << endl;
		age = 0;
		return;
	}
	age = a;
}

void Student::setName(const char* n)
{
	//delete name;
	name = new char[strlen(n) + 1];
	strcpy_s(name, strlen(n) + 1, n);
}

int Student::getAge() const
{
	return age;
}

char* Student::getName() const
{
	return name;
}

void Student::setMark(int m)
{
	//int m;
	//cout << "Введіть нову оцінку: ";
	//cin >> m;
	addElemArray(mark, sizeMark, m);
}

void Student::save(ofstream& out)
{
	out.write((char*)this, sizeof(Student));
	size_t len = strlen(this->name);
	out.write((char*)&len, sizeof(int));
	out.write((char*)this->name, len);
	for (size_t i = 0; i < this->sizeMark; i++)
	{
		out.write((char*)&mark[i], sizeof(int));
	}
}

void Student::load(ifstream& in)
{
	delete name;
	in.read((char*)this, sizeof(Student));
	name = nullptr;
	int l;
	in.read((char*)&l, sizeof(int));
	char buffer[80];
	in.read((char*)buffer, l);
	buffer[l] = '\0';
	this->setName(buffer);
	mark = new int[sizeMark];
	for (size_t i = 0; i < sizeMark; i++)
	{
		in.read((char*)&mark[i], sizeof(int));
	}
}

int getAvgAgeStudent(Student* st, int n)
{
	int avg = 0;
	for (size_t i = 0; i < n; i++)
	{
		avg += st[i].getAge();
	}
	return avg / n;
}