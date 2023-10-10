#include <iostream>
#include<vector>
#include "movie.h"
#include "Shelf.h"

int main() {

	Shelf shelf;
	
	while (true) {
		int sel;
		std::cout << "Press 1 to add a movie to the shelf. \n"
			<< "Press 2 remove a movie from the shelf. \n"
			<< "Press 3 see how many movies are currently on the shelf. \n"
			<< "Press 4 to quit."
			<< std::endl;
		std::cin >> sel;
		if (sel == 1)
		{
			try
			{
				std::unique_ptr<Movie> movie = std::make_unique<Movie>();
				shelf.addToShelf_(movie);
			}
			catch (Shelf::ShelfFull_ e)
			{
				system("CLS");
				std::cout << "Shelf is full, cannot add movie. " << std::endl;
				continue;
			}
			system("CLS");
			std::cout << "Movie added to shelf. " << std::endl;
			continue;
		}
		else if(sel == 2)
		{
			try
			{
				shelf.shelfDetails_();
				int sel2 = 1;
				std::cout << "select a movie slot to take: ";
				std::cin >> sel2;
				std::unique_ptr<Movie> movie = shelf.removeFromShelf_(sel2);
				movie->details_();
			}
			catch (Shelf::ShelfEmpty_ e)
			{
				system("CLS");
				std::cout << "Shelf is empty. Cannot take a movie. " << std::endl;
				continue;
			}
			catch (Shelf::SlotEmpty_ e)
			{
				system("CLS");
				std::cout << "Cannot take a movie from an empty slot. " << std::endl;
				continue;
			}
			system("CLS");
			std::cout << "Movie removed from shelf." << std::endl;
			continue;
		}
		else if (sel == 3) 
		{ 
			system("CLS");
			std::cout << shelf.moviesOnShelf() << " Movies on the shelf. " << std::endl;
		}
		else if (sel == 4) { return 0; }
		else { system("CLS"); continue; }
	}


	return 0;
}