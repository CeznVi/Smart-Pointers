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
	}
	~SmartPointer()
	{ 
		//if (!ptr)
		//	return;

		delete this->ptr; 
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


template<class T>
class SharedPtr 
{
	//лічильник
	size_t* count = nullptr;
	T* ptr = nullptr;

public:
	SharedPtr(T* p = nullptr)
	{
		this->ptr = p;
		this->count = new size_t(1);
	}
	~SharedPtr() { this->clear(); }
	SharedPtr(const SharedPtr& p)
	{
		this->ptr = p.ptr;
		this->count = p.count;

		if (count)
			++* count;
	}
	SharedPtr(SharedPtr&& p)
	{
		this->ptr = p.ptr;
		this->count = p.count;

		p.ptr = nullptr;
		p.count = nullptr;
	}
	T* operator->() const noexcept { return get(); }
	T& operator*() const noexcept { return *get(); }
	SharedPtr& operator= (const SharedPtr<T>& p)
	{
		if (this == &p)
			return *this;
		
		if(this != &p)
			this->clear();

		this->ptr = p.ptr;
		this->count = p.count;

		if (count)
			++*count;

		return *this;
	}
	//Метод очистки
	void clear()
	{
		if (!count)
			return;

		--*count;

		if (!(*count))
		{
			delete this->ptr;
			delete this->count;
			cout << "Видалення птр та коунт\n";
		}
		else
		{
			this->ptr = nullptr;
			this->count = nullptr;
		}
	}
	bool isEmpty() { return this->ptr == nullptr; }
	T* get() const noexcept { return this->count ? this->ptr : NULL; }
	size_t get_count() const noexcept { return this->count ? *count : NULL; }


};