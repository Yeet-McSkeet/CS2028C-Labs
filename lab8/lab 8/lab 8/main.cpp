#include"linked_list_template.h"
#include<iostream>
#include<random>

template<typename T>
T randomGenerator(T range_from, T range_to)
{
	std::random_device                  rand_dev;
	std::mt19937                        generator(rand_dev());
	std::uniform_int_distribution<T>    distr(range_from, range_to);
	return distr(generator);
}

int main() {

	List<int> list;
	
	for (int i = 0; i < 5; ++i)
	{
		list.addItem(new int(randomGenerator(0, 50)));
	}

	return 0;
}