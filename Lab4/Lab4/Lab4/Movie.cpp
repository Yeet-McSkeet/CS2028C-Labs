#include "Movie.h"

Movie::Movie() : Show()
{
	opening_credits_.push_back("Producer");
	opening_credits_.push_back("Writer");
	opening_credits_.push_back("actors");
}

Movie::Movie(std::string title, std::string description, std::vector<std::string> opening_credits) : Show(title, description)
{
	opening_credits_ = opening_credits;
}

void Movie::play_()
{
	std::cout << "Credits: " << std::endl;
	for (auto& i : opening_credits_) { std::cout << i << std::endl; }

	std::cout << "NOW PLAYING" << std::endl;
	this->details_();
}

void Movie::setCredits_(std::vector<std::string> opening_credits)
{
	this->opening_credits_ = opening_credits;
}

std::vector<std::string> Movie::getCredits_()
{
	return this->opening_credits_;
}
