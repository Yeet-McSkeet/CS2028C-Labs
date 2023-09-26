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

void Show::play_()
{
	std::cout << "Playing show..." << std::endl;
	this->details_();
	std::cout << "Called from show" << std::endl;
}

void Show::details_()
{
	std::cout << title_ << std::endl;
	std::cout << description_ << std::endl;
	std::cout << "Called from show" << std::endl;
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
