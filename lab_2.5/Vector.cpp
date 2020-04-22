#include "Vector.h"
#include <stdexcept>
#include <string>

template Vector<char>;
template Vector<bool>;
template Vector<int>;
template Vector<float>;
template Vector<double>;
template Vector<std::string>;

template <class T>
Vector<T>::Vector(const Vector<T>& v)
{
	sizeOfVector = v.sizeOfVector;
	capacityOfVector = v.capacityOfVector;
	if (v.elements == nullptr) elements = nullptr;
	else
	{
		elements = new T[capacityOfVector];
		for (size_t i = 0; i < sizeOfVector; ++i) elements[i] = v.elements[i];
	}
}

template <class T>
Vector<T>& Vector<T>::operator=(const Vector<T>& v)
{
	if (this != &v)
	{
		if(elements != nullptr) delete[] elements;
		sizeOfVector = v.sizeOfVector;
		capacityOfVector = v.capacityOfVector;
		if (v.elements == nullptr) elements = nullptr;
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
	if (!(pos < sizeOfVector)) throw std::out_of_range("position is bigger than Vector's size");
	return elements[pos];
}

template <class T>
const T& Vector<T>::at(const size_t pos) const
{
	if (!(pos < sizeOfVector)) throw std::out_of_range("position is bigger than Vector's size");
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
	if (sizeOfVector != 0) return elements[sizeOfVector - 1];
}

template <class T>
const T& Vector<T>::back() const
{
	if (sizeOfVector != 0) return elements[sizeOfVector - 1];
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
	if (new_cap > std::numeric_limits<size_t>::max()) 
		throw std::length_error("Capacity of Vector couldn't be so big");
	capacityOfVector = new_cap;
	T* elem = new T[capacityOfVector];
	for (size_t i = 0; i < sizeOfVector; ++i) elem[i] = elements[i];
	if(elements != nullptr) delete[] elements;
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
		size_t cap = 0;
		if (capacityOfVector == 0) cap = 1;
		else
		{
			if (capacityOfVector == 1) cap = 2;
			else if (capacityOfVector >= 2) cap = sizeOfVector * 1.5;
		}
		reserve(cap);
	}
	++sizeOfVector;
	T tmp = value;
	for (size_t i = pos; i < sizeOfVector; ++i)
	{
		T temp = elements[i];
		elements[i] = tmp;
		tmp = temp;
	}
	tmp = elements[pos];
}

template <class T>
void Vector<T>::erase(const size_t pos)
{
	if (pos < sizeOfVector)
	{
		T* elem = new T[capacityOfVector];
		for (size_t i = 0; i < sizeOfVector - 1; ++i)
		{
			if (i < pos) elem[i] = elements[i];
			else elem[i] = elements[i + 1];
		}
		--sizeOfVector;
		delete[] elements;
		elements = elem;
	}
}

template <class T>
void Vector<T>::erase(const size_t first, const size_t last)
{
	if (last < sizeOfVector && first <= last && first >= 0)
	{
		T* elem = new T[capacityOfVector];
		for (size_t i = first; i < sizeOfVector - (last - first + 1); ++i)
		{
			if (i < first) elem[i] = elements[i];
			else elem[i] = elements[i + (last - first + 1)];
		}
		sizeOfVector -= (last - first + 1);
		delete[] elements;
		elements = elem;
	}
}

template <class T>
void Vector<T>::push_back(const T& value)
{
	if (sizeOfVector + 1 > capacityOfVector)
	{
		size_t cap = 0;
		if (capacityOfVector == 0) cap = 1;
		else
		{
			if (capacityOfVector == 1) cap = 2;
			else if (capacityOfVector >= 2) cap = sizeOfVector * 1.5;
		}
		reserve(cap);
	}
	++sizeOfVector;
	elements[sizeOfVector - 1] = value;
}

template <class T>
void Vector<T>::pop_back()
{
	erase(sizeOfVector - 1);
}

template <class T>
void Vector<T>::resize(size_t count)
{
	if (count < 0) return;
	sizeOfVector = count;
	capacityOfVector = sizeOfVector * 1.5;
	if (capacityOfVector == 0)
	{
		delete[] elements;
		elements = nullptr;
		return;
	}
	T* res = new T[capacityOfVector];
	for (size_t i = 0; i < sizeOfVector; ++i) res[i] = elements[i];
	delete[] elements;
	elements = res;
}

template <class T>
void Vector<T>::swap(Vector<T>& other) noexcept
{
	size_t temp = sizeOfVector;
	sizeOfVector = other.sizeOfVector;
	other.sizeOfVector = temp;
	temp = capacityOfVector;
	capacityOfVector = other.capacityOfVector;
	other.capacityOfVector = temp;
	T* temp1 = elements;
	elements = other.elements;
	other.elements = temp1;
}