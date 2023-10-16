#pragma once



#ifndef _ORDERED_LIST_H
#define _ORDERED_LIST_H
#include<array>
template<typename T>
class Ordered_List
{
private:

	std::array<T*, 25> list_;
	int length_;
	

public:

	Ordered_List()// Default (only) constructor
	{
		int a = 0;	// random zero value to not compare int to nullptr
		// Initialize whole array to nullptr to avoid fucky memory
		for (auto& i : list_)
		{
			i = &a;
		}
		
		list_[0] = &a;	// Set next item in list to zero to not compare int to ptr
		length_ = 0;
	}		

	~Ordered_List()		// Destructor will call makeEmpty(), just to ensure the list is cleared
	{
		makeEmpty();
	}

	void addItem(T* item)	// Adds an item via a pointer
	{ 
		int index = 0;
		while (*item > *list_[index] && index < length_) {
			++index;
		}	// break when item >= list_[index] or when index hits length
		
		for (int i = length_; i >= index + 1; i--) {
			list_[i] = list_[i - 1];
		}
		list_[index] = item;
		++length_;
	}	


	void removeItem();		// remove an item from the list (how?)

	bool isEmpty();			// Check first item in list for empty or zero
	bool isFull();			// Check last item in list for empty or zero

	void makeEmpty()
	{
		int a = 0;
		for (auto& i : list_)
		{
			delete i;
			i = &a;
		}
	}
	
	class arrayFull_;
	class arrayEmpty_;
};

#endif // !_ORDERED_LIST_H

