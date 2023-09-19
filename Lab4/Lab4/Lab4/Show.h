#pragma once
#ifndef SHOW_H
#define SHOW_H
#include<iostream>

class Show
{
private:

	std::string title_;
	std::string description_;

public:
	
	Show();
	Show(std::string, std::string);

	virtual void playShow_();		// Available if overwritten
	void showDetails_();			// Available

	// getters (DEBUG ONLY)
	std::string getTitle_();		// Available
	std::string getDescription_();	// Available

};

#endif // !SHOW_H