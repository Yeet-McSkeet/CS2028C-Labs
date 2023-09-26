#include "TV.h"

TV::TV() : Show() {
	Show* default_show = new Show;
	std::vector<Show*> season = { default_show };
	seasonsEpisodes_.push_back(season);
}

TV::TV(std::string title, std::string description, std::vector<std::vector<Show*>> seasonEpisodes) : Show(title, description) {

	seasonsEpisodes_ = seasonEpisodes;

}


void TV::play_()
{
	int season, episode;
	std::cout << this->getTitle_() << " has " << this->seasonsEpisodes_.size() << " seasons. \nWhich season would you like to view? ";
	std::cin >> season;

	for (auto& i : seasonsEpisodes_[season - 1])
	{
		std::cout << "Showing season " << season << "..." << std::endl;
		std::cout << "TITLE: " << i->getTitle_() << std::endl;
		std::cout << "DESCRIPTION: " << i->getDescription_() << std::endl;
		std::cout << std::endl;
	}
	std::cout << "Which number episode would you like to view? ";
	std::cin >> episode;
	seasonsEpisodes_[season-1][episode-1]->play_();
}

void TV::details_() 
{
	std::cout << this->getDescription_();

	for (int i = 0; i < seasonsEpisodes_.size(); ++i)
	{
		std::cout << "Season " << i << ": " << seasonsEpisodes_[i].size() << " Episodes." << std::endl;
		for (auto& j : seasonsEpisodes_[i]) {j->details_();}
	}

}
