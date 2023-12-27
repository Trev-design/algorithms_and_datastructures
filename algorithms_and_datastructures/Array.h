#pragma once
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


};

