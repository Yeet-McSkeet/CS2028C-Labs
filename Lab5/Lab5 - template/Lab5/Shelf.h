#pragma once

#ifndef ENTERTAINMENTCOLLECTION_H
#define ENTERTAINMENTCOLLECTION_H

//#define CAPACITY 10

#include "Movie.h"

template<typename T>
class EntertainmentCollection

{

private:

	size_t shelfsize_;

	std::unique_ptr<T> shelf_[10];

public:
	EntertainmentCollection()
	{
		shelfsize_ = 0;
		for (auto& i : shelf_) { i = nullptr; }
	}
	~EntertainmentCollection() {}

	class ShelfFull_ {};
	class ShelfEmpty_ {};
	class SlotEmpty_ {};

	void addToShelf_(std::unique_ptr<T>& movie)
	{	// If shelf is not full, find the first available place to put the movie
		if (shelfsize_ < 10) {
			++shelfsize_;
			for (auto& i : shelf_) {
				if (i == nullptr) {
					i = std::move(movie);	// Move ownership of the pointer
					return;
				}
			}
		}
		else { throw(ShelfFull_()); }		// Shelf is full
	}
	std::unique_ptr<T> removeFromShelf_(int movie)
	{	// Given the position on the shelf, move ownership to the return
		if (shelfsize_ > 0) {
			--shelfsize_;
			if (shelf_[movie - 1] != nullptr) { return std::move(shelf_[movie - 1]); }
			else { throw(SlotEmpty_()); }
		}
		else { throw(ShelfEmpty_()); }
	}

	int moviesOnShelf() { return shelfsize_; }

	void collectionDetails_()
	{
		int slot = 1;
		for (auto& i : shelf_)
		{
			std::cout << "Shelf slot " << slot << " {" << std::endl;
			if (i == nullptr) { std::cout << "<empty>" << std::endl; }
			else { i->details_(); }
			std::cout << "}" << std::endl;
			++slot;
		}
	}
};

#endif // !ENTERTAINMENTCOLLECTION_H