#pragma once

#ifndef SHELF_H
#define SHELF_H
#define CAPACITY 10

#include<iostream>
#include "Movie.h"


class Shelf
{

private:

	size_t shelfsize_;
	std::unique_ptr<Movie> shelf_[CAPACITY];

public:
	Shelf();
	~Shelf();

	class ShelfFull_ {};
	class ShelfEmpty_ {};
	class SlotEmpty_ {};

	void addToShelf_(std::unique_ptr<Movie>&);
	std::unique_ptr<Movie> removeFromShelf_(int);

	int moviesOnShelf();
	void shelfDetails_();

};

#endif // !SHELF_H