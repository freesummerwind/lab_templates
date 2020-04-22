#include "Vector.h"

template <class T>
Vector<T>::Vector(const Vector<T>& v)
{
	size = v.size;
	capasity = v.capasity;
	if (v.elements = nullptr) elements = nullptr;
	else
	{
		elements = new T[capasity];
		for (int i = 0; i < size; ++i) elements[i] = v.elements[i];
	}
}

template <class T>
Vector<T>& Vector<T>::operator=(const Vector<T>& v)
{
	if (*this != v)
	{
		if(elements != nullptr) delete[] elements;
		size = v.size;
		capasity = v.capasity;
		if (v.elements = nullptr) elements = nullptr;
		else
		{
			elements = new T[capasity];
			for (int i = 0; i < size; ++i) elements[i] = v.elements[i];
		}
	}
	return *this;
}

template <class T>
T& Vector<T>::operator[](const size_t pos)
{
	if (pos < size) return elements[pos];
}

template <class T>
const T& Vector<T>::operator[](const size_t pos) const
{
	if (pos < size) return elements[pos];
}

template <class T>
void Vector<T>::upgradeSize()
{
	if (size = 1) capasity = 1;
	if (size = 2) capasity = 2;
	if (size > 2) capasity = (size - 1) * 1.5;
	T* elem = new T[capasity];
	if (elements != nullptr)
	{
		for (int i = 0; i < size - 1; ++i) elem[i] = elements[i];
		delete[] elements;
	}
	elements = elem;
}

template <class T>
T& Vector<T>::at(const size_t pos)
{
	if (!(pos < size)) throw std::out_of_range;
	return elements[pos];
}

template <class T>
const T& Vector<T>::at(const size_t pos) const
{
	if (!(pos < size)) throw std::out_of_range;
	return elements[pos];
}

template <class T>
T& Vector<T>::front()
{
	if (size != 0) return elements[0];
}

template <class T>
const T& Vector<T>::front() const
{
	if (size != 0) return elements[0];
}

template <class T>
T& Vector<T>::back()
{
	if (size != 0) return elements[size - 1];
}

template <class T>
const T& Vector<T>::back() const
{
	if (size != 0) return elements[size - 1];
}

template <class T>
T* Vector<T>::data() noexcept
{
	if (size != 0) return &(elements[0]);
	else return nullptr;
}

template <class T>
const T* Vector<T>::data() const noexcept
{
	if (size != 0) return &(elements[0]);
	else return nullptr;
}

template <class T>
bool Vector<T>::empty() const
{
	return (size == 0);
}