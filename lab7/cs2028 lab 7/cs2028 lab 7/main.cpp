#include<iostream>
#include<iomanip>
#include<random>
#include"Ordered_List.h"
#include"Ordered_List_Middle.h"

template<typename T>
T randomGenerator(T range_from, T range_to)
{
	std::random_device                  rand_dev;
	std::mt19937                        generator(rand_dev());
	std::uniform_int_distribution<T>    distr(range_from, range_to);
	return distr(generator);
}


int main() {

	Ordered_List_Middle<int> list;

	for (int i = 0; i < list.size(); ++i)
	{
		std::shared_ptr<int> item = std::make_shared<int>( randomGenerator<int>(0,50) );
		
		list.addItem(item);

	}

	int randomindex = randomGenerator<int>(0, list.length() - 1);
	list.removeItem(randomindex);


	int asdfghjkl = 0;

	list.makeEmpty();

	asdfghjkl = 0;

	return 0;
}