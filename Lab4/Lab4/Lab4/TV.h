#pragma once

#ifndef TV_H
#define TV_H
#include "Show.h"
#include <vector>
class TV : public Show
{
private:

	std::vector<std::vector<Show>> seasonsEpisodes_;

public:
	TV();
	TV(std::string, std::string);

	void playShow_();
	void showDetails_();

};

#endif // !TV_H