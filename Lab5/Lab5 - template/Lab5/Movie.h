#pragma once

#ifndef MOVIE_H
#define MOVIE_H

#include<iostream>
#include<vector>


struct Credits
{
    std::string producer_;
    std::string writer_;
    std::string actor_;
};


class Movie
{
private:
    std::string title_;
    std::string description_;
    Credits openingcredits_;
public:
    Movie();
    Movie(std::string, std::string, std::string, std::string, std::string);

    void play_();
    void details_();
};

#endif // !MOVIE_H