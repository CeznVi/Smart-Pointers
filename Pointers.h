#pragma once

template<class T>
class SmartPointer
{
protected:
	T* ptr;

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
class UniqPtr
{
protected:
	T* ptr;

public:
	UniqPtr(T* p = nullptr) : ptr(p) { cout << "Робота конструктора UniqPtr\n"; }
	~UniqPtr() 
	{
		cout << "Робота деструктора UniqPtr\n";
		delete ptr; 
	
	}
	UniqPtr(const UniqPtr& p)
	{
		cout << "Робота конструктора копіювання\n";
		ptr = new T;
		*ptr = *p.ptr;
	}
	UniqPtr(UniqPtr&& p)
	{
		cout << "Робота конструктора переміщення\n";
		ptr = p.ptr;
		p.ptr = nullptr;
	}

	//UniqPtr& operator=(UniqPtr& p) = delete;

	//UniqPtr& operator=(UniqPtr& p)
	//{
	//	cout << "Робота оператора присвоення L-value\n";
	//	if (this == &p)
	//		return *this;

	//	delete ptr;

	//	ptr = new T;
	//	*ptr = *p.ptr;

	//	return *this;

	//}

	UniqPtr& operator=(UniqPtr& p)
	{
		cout << "Робота оператора присвоення L-value\n";
		if (this == &p)
			return *this;

		delete ptr;

		ptr = move(p.ptr);
		p.ptr = nullptr;

		return *this;

	}

	UniqPtr& operator=(UniqPtr&& p) noexcept
	{
		cout << "Робота оператора присвоення R-value\n";
		if (this == &p)
			return *this;

		delete ptr;

		ptr = p.ptr;
		p.ptr = nullptr;

		return *this;
	}
	T& operator*() { return *ptr; }
	T* operator->()
	{ 
		if (ptr)
			return ptr;
	}
	bool isEmpty() { return ptr == nullptr; }
};
