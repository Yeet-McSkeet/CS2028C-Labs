#include<iostream>
#include<random>
#include"Ordered_List.h"

template<typename T>
T randomGenerator(T range_from, T range_to)
{
	std::random_device                  rand_dev;
	std::mt19937                        generator(rand_dev());
	std::uniform_int_distribution<T>    distr(range_from, range_to);
	return distr(generator);
}


int main() {

	Ordered_List<int> list;

	for (int i = 0; i < 25; ++i)
	{
		int* item = new int;
		*item = randomGenerator(0, 50);	// Item can now be added to all lists simultaneously

		
		list.addItem(item);
	}


	int asdfghjkl = 0;

	list.makeEmpty();


	return 0;
}