#pragma once
#ifndef STACK_H
#define STACK_H
#include<iostream>

template<typename T>
class Stack
{
private:
	int	size_;
	int top_;
	T**	data_;
public:
	Stack(int size)
	{
		size_ = size;
		data_ = new T * [size];
		top_ = -1;
	}
	
	T* topValue_() { return data_[0]; }

	void push_(T* data)		// Push an item to the front of the array
	{
		if (top_ == size_-1) { 
			throw StackOverflow_() ;
		}
		++top_;
		data_[top_] = data;
		
	}
	T* pop_()				// Remove and return the first item
	{
		if (top_ == -1) { throw StackUnderflow_() ; }
		T* temp = data_[top_];
		delete data_[top_];
		--top_;
		return temp;
	}
	void makeEmpty_()
	{
		delete[] data_;
	}
	int length_() { return top_ + 1; }

	class StackOverflow_ {};
	class StackUnderflow_ {};
};

#endif // !STACK_H