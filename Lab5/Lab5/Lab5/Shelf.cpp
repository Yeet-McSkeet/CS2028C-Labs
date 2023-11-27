#include "Shelf.h"

Shelf::Shelf()
{
	shelfsize_ = 0;
	for (auto& i : shelf_) { i = nullptr; }
}

Shelf::~Shelf()
{
}

void Shelf::addToShelf_(std::unique_ptr<Movie>& movie)
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

std::unique_ptr<Movie> Shelf::removeFromShelf_(int movie)
{	// Given the position on the shelf, move ownership to the return
	if (shelfsize_ > 0) {
		--shelfsize_;
		if (shelf_[movie-1] != nullptr) { return std::move(shelf_[movie - 1]); }
		else { throw(SlotEmpty_()); }
	}
	else { throw(ShelfEmpty_()); }
}

int Shelf::moviesOnShelf() { return shelfsize_; }

void Shelf::shelfDetails_()
{
	int slot = 1;
	for (auto& i : shelf_)
	{
		std::cout << "\nShelf slot " << slot << "\n{" << std::endl;
		if (i == nullptr) { std::cout << "<empty>" << std::endl; }
		else { i->details_(); }
		std::cout << "}" << std::endl;
		++slot;
	}
}

