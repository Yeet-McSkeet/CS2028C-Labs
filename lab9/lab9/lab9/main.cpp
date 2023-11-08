#include<iostream>
#include<fstream>
#include<iomanip>
#include<string>
#include<sstream>
#include"Word.h"
#include"BinaryTree.h"



int main()
{
	BinaryTree<WordItem> wordtree;

	std::string filename;
	std::cout << "Enter a filename and extension to analyze: ";
	getline(std::cin, filename);
	//filename = "PeterPan.txt";

	std::ifstream book;
	book.open(filename, std::ios::in);
	if (!book) {
		std::cout << "Book not found. Filename is incorrect or file does not exist." << std::endl;
		return 0;
	}
	else { system("CLS"); }


	std::string line;

	
	while (!book.eof())
	{
		getline(book, line);
		line.append(" ");	// So that it finds a word
		for (int i = 0; i < line.length(); ++i)
		{	// Fix the string to be all lowercase words, all punctuation removed. 
			if (line[i] == '\0')
			{	// Break if it reaches the newline character
				break;
			}
			if (isupper(line[i]))
			{
				line[i] += 32;
			}
			else if (!islower(line[i]) && line[i] != ' ')
			{
				line.erase(line.find(line[i]), 1);
				--i;
			}
		}

		stringstream text(line);
		std::string word;
		//Rebalance tree each line, adding will be more efficient in theory
		while (text >> word)
		{
			WordItem item{ word,1 };
			auto found_word = wordtree.searchNode(item);
			if (found_word)
			{
				++found_word->value;
				found_word = nullptr;
			}
			else
			{
				wordtree.insertNode(item);
			}

		}
	}
	
	std::vector<TreeNode<WordItem>*> ascending = wordtree.displayOrderAscending();
	for (auto& i : ascending)
	{
		cout << i->value << endl;;
	}

	cout << "\n\n\n\n\n";

	std::vector<TreeNode<WordItem>*> descending = wordtree.displayOrderDescending();
	for (auto& i : descending)
	{
		cout << i->value << endl;
	}


	

	int a = 0;

	return 0;

}
