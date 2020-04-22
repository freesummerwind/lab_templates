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
T Vector<T>::operator[](const int pos)
{
	if (pos < size) return elements[pos];
}