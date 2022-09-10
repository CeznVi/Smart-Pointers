#pragma once

template<class T>
class SmartPointer
{
protected:
	T* ptr = nullptr;
	
public:
	SmartPointer(T* p = nullptr)
	{
		this->ptr = p;
		cout << "Робота конструктора SmartPointer\n";
	}
	~SmartPointer()
	{ 
		if (!ptr)
			return;

		delete this->ptr; 
		cout << "Робота деструктора розумноно покажчика SmartPointer\n";
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
	SmartPointer& operator=(const SmartPointer<T>& p)
	{
		if (this == &p)
			return *this;

		delete this->ptr;

		this->ptr = new T;
		*(this->ptr) = *p.ptr;

		return *this;
	}
	SmartPointer& operator=(SmartPointer<T>&& p)
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
	UniqPtr(T* p = nullptr)
	{
		this->ptr = p;
		cout << "Робота конструктора UniqPtr\n";
	}
	UniqPtr(const UniqPtr& obj) = delete;
	UniqPtr& operator=(const UniqPtr& p) = delete;
	UniqPtr& operator = (UniqPtr<T>&& p) noexcept
	{
		reset(p.release());
		return *this;
	}
	UniqPtr(UniqPtr<T>&& p) noexcept 
	{
		this->ptr(p.release());
	}
	T* release() {
		T* tmp = this->ptr;
		this->ptr = nullptr;
		return tmp;
	}
	void reset(T* p) {
		delete this->ptr;
		this->ptr = p;
	}
	T* get() const noexcept;

};

template<class T>
T* UniqPtr<T>::get() const noexcept
{
	return this->ptr ? this->ptr: NULL;
}
