#include "TV.h"

TV::TV() : Show() {
	Show* default_show = new Show;
	std::vector<Show*> season = { default_show, default_show };
	seasonsEpisodes_.push_back(season);
	seasonsEpisodes_.push_back(season);
	seasonsEpisodes_.push_back(season);
}

TV::TV(std::string title, std::string description, std::vector<std::vector<Show*>> seasonEpisodes) : Show(title, description) {

	seasonsEpisodes_ = seasonEpisodes;

}


void TV::play_()
{
	int season, episode;
	std::cout << "Show Viewer: " << std::endl;
	std::cout << this->getTitle_() << " has " << this->seasonsEpisodes_.size() << " season(s). \nWhich season would you like to view? ";
	std::cin >> season;
	std::cout << "Showing season " << season << "..." << std::endl;

	for (auto& i : seasonsEpisodes_[season - 1])	// show episodes
	{
		std::cout << "EPISODE TITLE: " << i->getTitle_() << std::endl;
		std::cout << "DESCRIPTION: " << i->getDescription_() << std::endl;
		std::cout << std::endl;
	}
	std::cout << "Which number episode would you like to view? ";
	std::cin >> episode;
	seasonsEpisodes_[season-1][episode-1]->play_();
}

void TV::details_() 
{
	this->Show::details_();	// Gives the detaisl of the TV object via its base class, Show.

	for (int i = 0; i < seasonsEpisodes_.size(); ++i)
	{
		std::cout << "Season " << i << ": " << seasonsEpisodes_[i].size() << " Episodes." << std::endl;
		for (auto& j : seasonsEpisodes_[i]) 
		{ 
			j->details_();
			std::cout << std::endl; 
		}
	}

}
