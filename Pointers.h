#pragma once



template<class T>
class SmartPointer
{
protected:
	T* ptr = nullptr;

public:
	SmartPointer(T* p = nullptr) : ptr(p) {}
	~SmartPointer() { delete ptr; }
	SmartPointer(SmartPointer& p)
	{
		ptr = new T;
		*ptr = *p.ptr;
	}
	SmartPointer(SmartPointer&& p)
	{
		ptr = p.ptr;
		p.ptr = nullptr;
	}
	SmartPointer& operator=(const SmartPointer& p)
	{
		if (this == &p)
			return *this;

		delete ptr;

		ptr = new T;
		*ptr = *p.ptr;

		return *this;
	}
	SmartPointer& operator=(SmartPointer&& p)
	{
		if (this == &p)
			return *this;

		delete ptr;

		ptr = p.ptr;
		p.ptr = nullptr;

		return *this;
	}
	T& operator*() { return *ptr; }
	T* operator->() { return ptr; }
	bool isEmpty() { return ptr == nullptr; }

};

template<class T>
class UniqPtr : public SmartPointer<T>
{

//public:


};