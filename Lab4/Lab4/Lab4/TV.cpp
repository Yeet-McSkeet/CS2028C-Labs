#include "TV.h"

TV::TV() : Show() {}

TV::TV(std::string title, std::string description) : Show(title, description) {



}


void TV::playShow_()
{
	int season, episode;
	std::cout << this->getTitle_() << " has " << this->seasonsEpisodes_.size() << " seasons. \nWhich season would you like to view? ";
	std::cin >> season;

	for (auto& i : seasonsEpisodes_[season - 1])
	{
		std::cout << "Showing season " << season << "..." << std::endl;
		std::cout << "TITLE: " << i.getTitle_() << std::endl;
		std::cout << "DESCRIPTION: " << i.getDescription_() << std::endl;
		std::cout << std::endl;
	}
	std::cout << "Which number episode would you like to view? ";
	std::cin >> episode;
	std::cout << "Now playing: Season " << season << ", Episode " << episode << "." << std::endl;
}

void TV::showDetails_() 
{
	std::cout << this->getDescription_();

	for (int i = 0; i < seasonsEpisodes_.size(); ++i)
	{
		std::cout << "Season " << i << ": " << seasonsEpisodes_[i].size() << " Episodes." << std::endl;
	}

}
