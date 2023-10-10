#pragma once
#ifndef QUEUE_H
#define QUEUE_H
#include<iostream>
template<typename T>
class Queue
{
private:
	int	size_;
	int	front_;
	int rear_;
	T**	data_;
public:
	Queue(int size)
	{
		data_	= new T * [size];
		size_	= size;
		front_	= -1;
		rear_	= -1;
	}

	T* frontItem_() { return data_[front_]; }

	void enqueue_(T* data)	// Place data in first empty spot (end of line)
	{
		if (front_ > size_ - 1) { throw QueueOverflow_(); }
		++rear_;
		data_[rear_] = data;
		if (front_ = -1) { front_ = 0; }
	}
	T* dequeue_()			// Remove and return the first item
	{
		if (front_ == -1 || front_ > rear_) { throw QueueUnderflow_(); }
		T* temp = data_[front_];
		delete data_[front_];
		++front_;
		return temp;
	}
	void makeEmpty_()		
	{
		delete[] data_;
		front_ = -1;
		rear_ = -1;
	}
	int length_() { return rear_ - front_ + 1; }

	class QueueOverflow_ {};
	class QueueUnderflow_ {};
};
#endif // !QUEUE_H