#include<iostream>
#include<string>
#include<vector>
#include"Stack.h"
#include"Queue.h"



void reverseWords(Queue<Stack<char>>& task3)
{

	for (int i = 0; i < task3.length_(); ++i)
	{
		for (int j = 0; j < task3.frontItem_()->length_(); ++j)
		{
			std::cout << task3.frontItem_()->pop_();
		}
		task3.dequeue_();
	}

}



int main()
{
	std::cout << "Press 1 for File Entry \nPress 2 for console entry \npress 3 to exit" << std::endl;
	std::string selection;
	getline(std::cin, selection);
	if (selection == "1")
	{
		return 0;
	}
	else if (selection == "2")
	{
		int wordcount = 1;
		
		std::string sentence;
		getline(std::cin, sentence);
		for (auto& i : sentence) { if (i == ' ') ++wordcount; }
		Queue<Stack<char>> task3(wordcount);
		for (int i = 0; i < sentence.size(); ++i) // Create the queue object
		{ 
			if (sentence[i] == ' ')
			{
				std::string temp = sentence.substr(0, i);
				Stack<char> word(temp.size());
				for (auto& i : temp) 
				{ 
					word.push_(&i); 
				}
				task3.enqueue_(&word);
				sentence = sentence.substr(i + 1, sentence.size());
				i = 0;
			}
		}
		reverseWords(task3);
		

	}
	return 0;
}