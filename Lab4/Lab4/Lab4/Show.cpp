#include "Show.h"

Show::Show()
{
	title_ = "_default_";
	description_ = "_default_";
}

Show::Show(std::string title, std::string description)
{
	title_ = title;
	description_ = description;
}

void Show::playShow_()
{
	std::cout << "Playing show... \nNo content to play." << std::endl;
}

void Show::showDetails_()
{
	std::cout << title_ << std::endl;
	std::cout << description_ << std::endl;
}


// DEBUG ONLY
std::string Show::getTitle_()
{
	return title_;
}

std::string Show::getDescription_()
{
	return description_;
}
