#include "Vector.h"

template <class T>
Vector<T>::Vector(const Vector<T>& v)
{
	sizeOfVector = v.sizeOfVector;
	capacityOfVector = v.capacityOfVector;
	if (v.elements = nullptr) elements = nullptr;
	else
	{
		elements = new T[capacityOfVector];
		for (size_t i = 0; i < sizeOfVector; ++i) elements[i] = v.elements[i];
	}
}

template <class T>
Vector<T>& Vector<T>::operator=(const Vector<T>& v)
{
	if (*this != v)
	{
		if(elements != nullptr) delete[] elements;
		sizeOfVector = v.sizeOfVector;
		capacityOfVector = v.capacityOfVector;
		if (v.elements = nullptr) elements = nullptr;
		else
		{
			elements = new T[capacityOfVector];
			for (size_t i = 0; i < sizeOfVector; ++i) elements[i] = v.elements[i];
		}
	}
	return *this;
}

template <class T>
T& Vector<T>::operator[](const size_t pos)
{
	if (pos < sizeOfVector) return elements[pos];
}

template <class T>
const T& Vector<T>::operator[](const size_t pos) const
{
	if (pos < sizeOfVector) return elements[pos];
}

template <class T>
T& Vector<T>::at(const size_t pos)
{
	if (!(pos < sizeOfVector)) throw std::out_of_range;
	return elements[pos];
}

template <class T>
const T& Vector<T>::at(const size_t pos) const
{
	if (!(pos < sizeOfVector)) throw std::out_of_range;
	return elements[pos];
}

template <class T>
T& Vector<T>::front()
{
	if (sizeOfVector != 0) return elements[0];
}

template <class T>
const T& Vector<T>::front() const
{
	if (sizeOfVector != 0) return elements[0];
}

template <class T>
T& Vector<T>::back()
{
	if (sizeOfVector != 0) return elements[size - 1];
}

template <class T>
const T& Vector<T>::back() const
{
	if (sizeOfVector != 0) return elements[size - 1];
}

template <class T>
T* Vector<T>::data() noexcept
{
	if (sizeOfVector != 0) return &(elements[0]);
	else return nullptr;
}

template <class T>
const T* Vector<T>::data() const noexcept
{
	if (sizeOfVector != 0) return &(elements[0]);
	else return nullptr;
}

template <class T>
bool Vector<T>::empty() const noexcept
{
	return (sizeOfVector == 0);
}

template <class T>
size_t Vector<T>::size() const noexcept
{
	return sizeOfVector;
}

template <class T>
void Vector<T>::reserve(size_t new_cap)
{
	if (new_cap <= capacityOfVector) return;
	if (new_cap > std::numeric_limits<size_t>::max()) throw std::length_error;
	capacityOfVector = new_cap;
	T* elem = new T[capacityOfVector];
	if (elements != nullptr)
	{
		for (size_t i = 0; i < sizeOfVector; ++i) elem[i] = elements[i];
		delete[] elements;
	}
	elements = elem;
}

template <class T>
size_t Vector<T>::capacity() const noexcept
{
	return capacityOfVector;
}

template <class T>
void Vector<T>::clear() noexcept
{
	sizeOfVector = 0;
	capacityOfVector = 0;
	delete[] elements;
	elements = nullptr;
}

template <class T>
void Vector<T>::insert(const size_t pos, const T& value)
{
	if (sizeOfVector + 1 > capacityOfVector)
	{
		if (capacityOfVector = 0) capacityOfVector = 1;
		if (capacityOfVector = 1) capacityOfVector = 2;
		if (capacityOfVector > 2) capacityOfVector = sizeOfVector * 1.5;
		reserve(capacityOfVector);
	}
	++sizeOfVector;
	for (size_t i = pos; i < sizeOfVector; ++i)
	{
		size_t temp = elements[i];
		elements[i] = value;
		value = temp;
	}
	value = elements[pos];
}