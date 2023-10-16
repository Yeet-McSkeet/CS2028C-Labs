#pragma once

#ifndef _ORDERED_LIST_H
#define _ORDERED_LIST_H
#include<array>
template<typename T>
class Ordered_List
{
private:

	std::array<std::shared_ptr<T>, 25> list_;
	int length_;

public:

	Ordered_List()
	{
		length_ = 0;

		//	Set all dangling pointers in array to nullptr
		for (auto& i : list_)
		{
			i = nullptr;
		}
	}		

	void addItem(std::shared_ptr<int> item)	// Adds an item via a pointer
	{ 
		int index = 0;
		while (list_[index]) 
		{
			if (*item < *list_[index] || index > length_) { break; }
			++index;
		}	// break when item >= list_[index] or when index hits length
		
		for (int i = length_; i >= index + 1; i--)
		{
			list_[i] = list_[i - 1];
		}	//	Move bitch, get out the way


		list_[index] = item;
		++length_;
	}	
	void removeItem();		// remove an item from the list (how?)

	void makeEmpty() 
	{	// Make the whole list empty. Reset the shared pointer to new T, set dangling pointer to null.
		for (auto& i : list_)
		{
			i.reset(new T);
			i = nullptr;
		}
		length_ = 0;
	}

	int length()	{ return length_; }						// Return the length as an integer
	bool isEmpty()	{ return length_ == 0; }				// Check first item in list for empty or zero
	bool isFull()	{ return length_ == list_.size(); };	// Check last item in list for empty or zero

	class arrayFull_;
	class arrayEmpty_;
};

#endif // !_ORDERED_LIST_H

