#pragma once
template <class T>
class Vector
{
	int size, capasity;
	T* elements;
	void upgradeSize();
public:
	Vector() : size(0), capasity(0), elements(nullptr) {}
	Vector(const Vector&);
	~Vector() { delete[] elements; }

};

