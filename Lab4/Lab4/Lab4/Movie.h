#pragma once

#ifndef MOVIE_H
#define MOVIE_H


#include "Show.h"
#include<vector>
class Movie :
    public Show
{

private:

    std::vector<std::string> opening_credits_;

public:

    Movie();
    Movie(std::string title, std::string description, std::vector<std::string> opening_credits);

    void play_();

    void setCredits(std::vector<std::string>);
    std::vector<std::string> getCredits();

};


#endif // !MOVIE_H
