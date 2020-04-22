#pragma once
template <class T>
class Vector
{
	size_t sizeOfVector, capacityOfVector;
	T* elements;
public:
	Vector() : sizeOfVector(0), capacityOfVector(0), elements(nullptr) {}
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
	bool empty() const noexcept;
	size_t size() const noexcept;
	void reserve(size_t);
	size_t capacity() const noexcept;
	void clear() noexcept;
	void insert(const size_t, const T&);
	void erase(const size_t);
	void erase(const size_t, const size_t);
	void push_back(const T&);
	void pop_back();
	void resize(size_t);
	void swap(Vector&) noexcept;
};