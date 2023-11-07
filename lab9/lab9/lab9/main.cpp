#include<iostream>
#include<fstream>
#include<iomanip>
#include<string>
#include<sstream>
#include"Word.h"
#include"BinaryTree.h"



int main()
{
	BinaryTree<std::string> wordtree;

	std::string filename;
	std::cout << "Enter a filename and extension to analyze: ";
	getline(std::cin, filename);

	std::ifstream book;
	book.open(filename, std::ios::in);
	if (!book) {
		std::cout << "Book not found. Filename is incorrect or file does not exist." << std::endl;
		return 0;
	}
	else { system("CLS"); }

	// Start with one line for now

	std::string line;

	
	while (!book.eof())
	{
		getline(book, line);
		line.append(" ");	// So that it finds a word
		for (auto& i : line)
		{	// Fix the string to be all lowercase words, all punctuation removed. 
			if (i == '\0')
			{	// Break if it reaches the newline character
				break;
			}
			if (isupper(i))
			{
				i += 32;
			}
			else if (!islower(i) && i != ' ')
			{
				line.erase(line.find(i), 1);

			}
		}

		stringstream text(line);
		std::string word;
		//Rebalance tree each line, adding will be more efficient in theory
		while (text >> word)
		{
			auto found_word = wordtree.searchNode(word);
			if (found_word)
			{
				++found_word->frequency;
				found_word = nullptr;
			}
			else
			{
				wordtree.insertNode(word);
			}

		}
	}

	wordtree.displayInOrder();

	int a = 0;

	return 0;

}
