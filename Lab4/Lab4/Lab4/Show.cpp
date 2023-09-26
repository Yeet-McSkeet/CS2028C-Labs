#include "Show.h"

Show::Show()
{
	title_ = "default_title";
	description_ = "default_description";
}

Show::Show(std::string title, std::string description)
{
	title_ = title;
	description_ = description;
}

void Show::play_()
{
	std::cout << "Playing show..." << std::endl;
	this->details_();
}

void Show::details_()
{
	std::cout << "Show Details: " << std::endl;
	std::cout << title_ << std::endl;
	std::cout << description_ << std::endl;
	std::cout << std::endl;
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
