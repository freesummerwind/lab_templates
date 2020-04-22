#include "Vector.h"

template <class T>
Vector<T>::Vector(const Vector<T>& v)
{
	size = v.size;
	capasity = v.capasity;
	elements = new T[capasity];
	for (int i = 0; i < size; ++i) elements[i] = v.elements[i];
}
