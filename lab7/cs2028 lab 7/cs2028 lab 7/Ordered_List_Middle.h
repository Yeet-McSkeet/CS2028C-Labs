#pragma once
#ifndef _ORDERED_LIST_MIDDLE_H
#define _ORDERED_LIST_MIDDLE_H
#include"Ordered_List.h"
#include<cmath>

template<typename T>
class Ordered_List_Middle : public Ordered_List<T>
{
public:
		
	Ordered_List_Middle() : Ordered_List<T>() {}

	
	void addItem(std::shared_ptr<int> item)	// Adds an item via a pointer
	{

		if (this->list_[0] && this->list_[this->list_.size() - 1]) { throw arrayFull_; }

		bool left = false;
		bool right = false;
		int index = floor(this->list_.size()/2);
		int max_index;
		while (this->list_[index])
		{
			/*
			move left or right depending on if item is < or > current item in list
			move until opposite is true
			move items out of the way in the direction needed
			place item
			*/
			if (*item > *this->list_[index]) 
			{
				if (left) { break; }
				right = true;
				++index;
			}
			else if (*item < *this->list_[index])
			{
				if (right) { break; }
				left = true;
				--index;
			}
		}
		
		if (left)
		{

			if (this->list_[0])
			{

				for (int i = list.size()-1; i >= index; --i)
				{



				}
				
			}

		}

		this->list_[index] = item;

	}

};


#endif // !ORDERED_LIST_MIDDLE_H