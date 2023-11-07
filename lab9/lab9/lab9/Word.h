#pragma once
#ifndef _WORD_H
#define _WORD_H
#include<string>
struct WordItem
{	// Struct with overloads, ascending variables for memory, overloads for comparison
	std::string word_;
	int frequency_;

	bool operator < (WordItem& comp)
	{
		int res = strcmp(this->word_.c_str(), comp.word_.c_str());
		return res < 0;
	}
	bool operator > (WordItem& comp)
	{
		int res = strcmp(this->word_.c_str(), comp.word_.c_str());
		return res > 0;
	}
	bool operator == (WordItem& comp)
	{
		int res = strcmp(this->word_.c_str(), comp.word_.c_str());
		return res == 0;
	}
	void operator ++ ()
	{
		frequency_++;
		return;
	}
};

#endif // !_WORD_H
