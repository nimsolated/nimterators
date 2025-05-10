#pragma once

#include <iostream>

template <typename Array>
class ArrayIterator {
public:
	using ValueType = typename Array::ValueType;
	using PointerType = ValueType*;
	using ReferenceType = ValueType&;
public:
	ArrayIterator(PointerType _ptr) : ptr(_ptr) {}

	ArrayIterator& operator++() {
		ptr++;
		return *this;
	}
	ArrayIterator operator++(int) {
		ArrayIterator iterator = *this;
		++(*this);
		return iterator;
	}
	ArrayIterator& operator--() {
		ptr--;
		return *this;
	}
	ArrayIterator operator--(int) {
		ArrayIterator iterator = *this;
		--(*this);
		return iterator;
	}

	ReferenceType operator[](int index) {
		return *(ptr + index);
	}
	PointerType operator->() {
		return ptr;
	}
	ReferenceType operator*() {
		return *ptr;
	}

	bool operator==(const ArrayIterator& other) const {
		return ptr == other.ptr;
	}
	bool operator!=(const ArrayIterator& other) const {
		return ptr != other.ptr;
	}
private:
	PointerType ptr;
};

template <typename T>
class Array {
private:
	T* m_arr;
	size_t m_size;
public:
	using ValueType = T;
	using Iterator = ArrayIterator<Array<T>>;
public:
	Array(const size_t& _size) {
		try {
			if (_size < 1) {
				throw std::runtime_error("Illegal size for construction of Array.");
			}
			m_arr = new T[_size];
			m_size = _size;
		}
		catch (std::runtime_error& e) {
			std::cout << this << ": " << e.what() << std::endl;
			exit(1);
		}
	}
	Array(size_t&& _size) {
		try {
			if (_size < 1) {
				throw std::runtime_error("Illegal size for construction of Array.");
			}
			m_arr = new T[_size];
			m_size = _size;
		}
		catch (std::runtime_error& e) {
			std::cout << this << ": " << e.what() << std::endl;
			exit(1);
		}
	}
	~Array() {
		delete[] m_arr;
	}

	size_t size() const {
		return m_size;
	}

	T& operator[](const size_t& i) {
		try {
			if (i >= m_size || i < 0) {
				throw std::runtime_error("Tried to access out of bounds.");
			}
			return m_arr[i];
		}
		catch (std::runtime_error& e) {
			std::cout << this << ": " << e.what() << std::endl;
			exit(1);
		}

	}
	const T& operator[](const size_t& i) const {
		try {
			if (i >= m_size || i < 0) {
				throw std::runtime_error("Tried to access out of bounds.");
			}
			return m_arr[i];
		}
		catch (std::runtime_error& e) {
			std::cout << this << ": " << e.what() << std::endl;
			exit(1);
		}
	}

	T& at(const size_t& i) {
		try {
			if (i >= m_size || i < 0) {
				throw std::runtime_error("Tried to access out of bounds.");
			}
			return m_arr[i];
		}
		catch (std::runtime_error& e) {
			std::cout << this << ": " << e.what() << std::endl;
			exit(1);
		}

	}
	const T& at(const size_t& i) const {
		try {
			if (i >= m_size || i < 0) {
				throw std::runtime_error("Tried to access out of bounds.");
			}
			return m_arr[i];
		}
		catch (std::runtime_error& e) {
			std::cout << this << ": " << e.what() << std::endl;
			exit(1);
		}
	}

	Iterator begin() {
		return ArrayIterator<Array<T>>(m_arr);
	}
	Iterator end() {
		return ArrayIterator<Array<T>>(m_arr + m_size);
	}
};