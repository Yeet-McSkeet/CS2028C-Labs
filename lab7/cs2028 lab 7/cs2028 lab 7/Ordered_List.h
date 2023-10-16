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
		// Initialize whole array to nullptr to avoid fucky memory
		for (auto& i : list_)
		{
			i = new int;
			i = nullptr;
		}
		
		length_ = 0;
	}		

	void addItem(T* item)	// Adds an item via a pointer
	{ 
		int index = 0;
		while (list_[index]) {
			if (*item < *list_[index] || index > length_) 
			{ break; }
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

	void makeEmpty() {
		for (auto& i : list_) {
			delete i;
			i = nullptr;
		}
		length_ = 0;
	}
	
	class arrayFull_;
	class arrayEmpty_;
};

#endif // !_ORDERED_LIST_H

