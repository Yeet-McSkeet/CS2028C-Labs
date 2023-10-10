#include "Movie.h"

Movie::Movie()
{
	title_ = "default title";
	description_ = "default description";
	openingcredits_ = { "producer", "writer", "actor" };
}

Movie::Movie(std::string title, std::string description, std::string producer, std::string writer, std::string actor)
{
	title_ = title;
	description_ = description;
	openingcredits_ = { producer, writer, actor };
}

void Movie::play_()
{
	std::cout << "Credits: " << std::endl;
	std::cout << "Produced by: " << openingcredits_.producer_ << std::endl;
	std::cout << "Written by: " << openingcredits_.writer_ << std::endl;
	std::cout << "Leading actor: " << openingcredits_.actor_ << std::endl;

	std::cout << "NOW PLAYING" << std::endl;
	this->details_();
}

void Movie::details_()
{
	std::cout << "Show Details: " << std::endl;
	std::cout << title_ << std::endl;
	std::cout << description_ << std::endl;
}


