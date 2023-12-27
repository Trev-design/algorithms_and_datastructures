#pragma once

#include<stdexcept>
#include<iostream>

template<typename Type>
class Array
{
private:
	Type* moptrData;
	size_t mSize;
	size_t mCapacity;

public:
	Array() noexcept : mCapacity(1), mSize(0), moptrData(new Type[mCapacity]) {}
	Array(const size_t capacity) noexcept : mCapacity(capacity), mSize(0), moptrData(new Type[capacity]) {}
	~Array() noexcept { delete[] moptrData; }

	inline size_t Size() const { return mSize; }

	Type& operator [] (size_t index);
	const Type operator [] (size_t index) const;

	void Push(const Type& item);
	Type Pop();
private:
	Type GetItem(size_t index) const;
	void Resize(size_t newCapacity);
};

template<typename Type>
inline Type& Array<Type>::operator[](size_t index)
{
	return GetItem(index);
}

template<typename Type>
inline const Type Array<Type>::operator[](size_t index) const
{
	return GetItem(index);
}

template<typename Type>
inline void Array<Type>::Push(const Type& item)
{
	moptrData[mSize] = item;
	++mSize;
}

template<typename Type>
inline Type Array<Type>::Pop()
{
	if (mSize <= 0) { throw std::underflow_error("No items in this array"); }
	if (mSize < (mCapacity / 4)) { Resize(mCapacity / 2); }

	Type item = moptrData[mSize];
	--mSize;
	return item;
}

template<typename Type>
inline Type Array<Type>::GetItem(size_t index) const
{
	if (index > mSize) { throw std::overflow_error("index to high"); }
	return moptrData[index];
}

template<typename Type>
inline void Array<Type>::Resize(size_t newCapacity)
{
	Type* newArray = new Type[new newCapacity];
	for (size_t index = 0; index < mSize, ++index)
	{
		newArray[index] = moptrData[index];
	}

	delete[] moptrData;
	mCapacity = newCapacity;
	moptrData = newArray;
}
