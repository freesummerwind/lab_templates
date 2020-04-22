#pragma once
template <class T>
class Vector
{
	size_t size, capasity;
	T* elements;
	void upgradeSize();
public:
	Vector() : size(0), capasity(0), elements(nullptr) {}
	Vector(const Vector&);
	~Vector() { delete[] elements; }
	Vector& operator=(const Vector&);
	T& operator[](const size_t);
	const T& operator[](const size_t) const;
	T& at(const size_t);
	const T& at(const size_t) const;
	T& front();
	const T& front() const;
	T& back();
	const T& back() const;
	T* data() noexcept;
	const T* data() const noexcept;
	bool empty() const;
};