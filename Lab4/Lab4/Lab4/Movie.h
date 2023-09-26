#pragma once

#ifndef MOVIE_H
#define MOVIE_H


#include "Show.h"
#include<vector>
class Movie : public Show
{

private:

    std::vector<std::string> opening_credits_;

public:

    Movie();
    Movie(std::string title, std::string description, std::vector<std::string> opening_credits);

    void play_() override;

    void setCredits_(std::vector<std::string>);
    std::vector<std::string> getCredits_();

};


#endif // !MOVIE_H
