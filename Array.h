#pragma once

#include <iostream>

template <typename T>
class Array
{
private:
	T* elements;
	size_t size;
public:
	Array() : elements(nullptr), size(0) {};
	Array(int pSize) : elements(nullptr), size(pSize) { setSize(pSize); };
	Array(const std::initializer_list<T>& list);
	~Array();

	void setSize(int size, int grow = 1);
	size_t getSize() const { return size; }

	void add(const T& pElement);

	T& operator[](int);
	const T& operator[](int) const;

	friend std::ostream& operator<<(std::ostream& out, const Array& arr)
	{
		out << "[ ";
		for (int i = 0; i < arr.getSize(); i++)
		{
			out << arr[i];
			if (i < arr.getSize() - 1)
				out << ", ";
		}
		out << " ]";
		return out;
	}
};

template<typename T>
inline Array<T>::Array(const std::initializer_list<T>& list) : Array(list.size())
{
	for (int i = 0; i < list.size(); i++)
		elements[i] = *(list.begin() + i);
}

template<typename T>
inline Array<T>::~Array()
{
	if (elements)
		delete[] elements;
}

template<typename T>
inline void Array<T>::setSize(int pSize, int grow)
{
	int newSize = pSize % grow != 0 ? pSize / grow * grow + grow : pSize;
	T* newElements = new T[newSize];
	
	if (elements)
	{
		for (int i = 0; i < (size < pSize ? size : pSize); i++)
			newElements[i] = elements[i];
		delete[] elements;
	}
	size = newSize;
	elements = newElements;
}

template<typename T>
inline void Array<T>::add(const T& pElement)
{
	setSize(size + 1);
	elements[size - 1] = pElement;
}

template<typename T>
inline T& Array<T>::operator[](int index)
{
	return elements[index];
}

template<typename T>
inline const T& Array<T>::operator[](int index) const
{
	return elements[index];
}
