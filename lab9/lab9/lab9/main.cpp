#include<iostream>
#include<fstream>
#include<iomanip>
#include<string>
#include"Word.h"
#include"BinaryTree.h"



int main()
{
	BinaryTree<std::string> wordfrequency;

	std::string filename;
	std::cout << "Enter a filename and extension to analyze: ";
	//getline(std::cin, filename);
	filename = "a.txt";

	std::ifstream book;
	book.open(filename, std::ios::in);
	if (!book) {
		std::cout << "Book not found. Filename is incorrect or file does not exist." << std::endl;
		return 0;
	}
	else { system("CLS"); }

	// Start with one line for now

	std::string line;

	/********************	Use later
	while (!book.eof())	|
	{ }					|
	********************/

	getline(book, line);
	line.append(" ");	// So that it finds a word
	for (auto& i : line)
	{	// Fix the string to be all lowercase words, all punctuation removed. 
		if (isupper(i))
		{
			i += 32;
		}
		else if (!islower(i) && i != ' ')
		{
			line.erase(line.find(i), 1);
		}
	}

	//Rebalance tree each line, adding will be more efficient in theory
	for (int i = 1; i < line.length(); ++i)
	{



	}



	// Take each word and add it to the tree
	// Sort the tree




	return 0;

}