#pragma once

template<class T>
class SmartPointer
{
protected:
	T* ptr = nullptr;
	
public:
	explicit SmartPointer(T* p = nullptr)
	{
		this->ptr = p;
		cout << "������ ������������ Ptr\n";
	}
	//SmartPointer(T* p = nullptr) : ptr(p) 
	//{
	//	cout << "������ ������������ ��������� ���������\n";
	//}
	~SmartPointer()
	{ 
		delete this->ptr; 
		cout << "������ ����������� ��������� ���������\n";
	}
	SmartPointer(SmartPointer& p)
	{
		this->ptr = new T;
		*(this->ptr) = *p.ptr;
	}
	SmartPointer(SmartPointer&& p)
	{
		this->ptr = p.ptr;
		p.ptr = nullptr;
	}
	SmartPointer& operator=(const SmartPointer& p)
	{
		if (this == &p)
			return *this;

		delete this->ptr;

		this->ptr = new T;
		*(this->ptr) = *p.ptr;

		return *this;
	}
	SmartPointer& operator=(SmartPointer&& p)
	{
		if (this == &p)
			return *this;

		delete this->ptr;

		this->ptr = p.ptr;
		p.ptr = nullptr;

		return *this;
	}
	T& operator*() { return *ptr; }
	T* operator->() { return this->ptr; }
	bool isEmpty() { return this->ptr == nullptr; }
};

template<class T>
class UniqPtr : public SmartPointer <T>
{

public:
	//UniqPtr(T* p = nullptr)
	//{
	//	this->ptr = p;
	//	cout << "������ ������������ UniqPtr\n";
	//}

	virtual UniqPtr& operator=(const UniqPtr& p) = delete;

};

