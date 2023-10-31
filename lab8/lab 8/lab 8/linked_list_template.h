#pragma once
#ifndef _linked_list_template_h
#define _linked_list_template_h

template<typename T>
struct Node
{
	T*	data_;
	Node<T>* next_;
	Node<T>* prev_;
};

template<typename T>
class List
{

private:

	Node<T>*	head_;
	Node<T>*	location_;
	int			length_;
	

public:

	List() 
	{
		head_ = nullptr;
		location_ = head_;
		length_ = 0;
	}
	

	bool isEmpty() { return head_ != nullptr; }
	int length() { return length_; }
	void reset() { location_ = head_; }	

	Node<T>* removeItem(Node<T>* item)
	{	// Removes the item at location, does not clear its memory
		if (head_ == item)
		{
			head_ = item->next_;
		}
		if (item->next_)
		{
			item->next_->prev_ = item->prev_;
		}
		if (item->prev_)
		{
			item->prev_->next_ = item->next_;
		}
		return item;
	}

	void addItem(T* item)
	{
		reset();
		//Node<T>* newnode = new Node<T>{ item, nullptr, nullptr };	// Make new node with data
		if (!head_)
		{	// Set head if not set
			head_ = new Node<T>{ item, nullptr, nullptr };
			return;
		}

		while (location_) 
		{	// Add item to list
			if (*item < *location_->data_)
			{	// If new data is less than current location data, add item before current location (push list back)
				Node<T>* newnode = new Node<T>{ item, location_, location_->prev_ };	// Make new node with data

				if (location_->prev_)
				{	// Set the previous item's next pointer to newnode
					location_->prev_->next_ = newnode;
				}

				location_->prev_ = newnode;	// Location's previous becomes newnode

				if (!newnode->prev_)
				{	//check if new head
					head_ = newnode;
				}
				return;
			}
			else if (!location_->next_)
			{
				Node<T>* newnode = new Node<T>{ item, nullptr, location_ };	// Make new node with data
				location_->next_ = newnode;
				return;
			}

			// Next item if none are true
			location_ = location_->next_;
		}
		return;
		
	}

	bool isInList(Node<T>* item)
	{
		reset();
		while (location_)
		{
			if (*item->data_ == *location_->data_)
			{
				return true;
			}
			location_ = location_->next_;
		}
		return false;
	}

	Node<T>* getItem(Node<T>* item)
	{
		reset();
		while (location_)
		{
			if (*item->data_ == *location_->data_)
			{
				return removeItem(location_);
			}
			location_ = location_->next_;
		}
		return nullptr;
	}

	Node<T>* seeAt(int index)
	{	// Go to the index if it exists
		if (index > length_) { return nullptr; }
		location_ = head_;
		for (auto i = 0; i < index; ++i)
		{
			if (!location_->next_)
			{
				return nullptr;
			}
			location_ = location_->next_;
		}
		return location_;
	}
	Node<T>* seeNext()
	{	// Get the next item if it exists
		if (location_->next_)
		{
			return location_->next_;
		}
		return nullptr;
	}
	Node<T>* seePrev()
	{
		if (location_->prev_)
		{
			return location_->prev_;
		}
		return nullptr;
	}
	
	bool operator < (List<T>* comp) 
	{
		return this->length_ < comp->length_;
	}
	bool operator > (List<T>& comp)
	{
		return this->length_ > comp->length_;
	}
	bool operator == (List<T>& comp)
	{
		return this->length_ == comp->length_;
	}

	~List ()
	{
		reset();
		while (location_->next_)
		{	// Set the next item to a temporary node, delete location, point location to temp and point temp to null.
			Node<T>* temp = location_->next_;
			delete location_;
			location_ = temp;
			temp = nullptr;
		}
	}
};

#endif // !_linked_list_template_h