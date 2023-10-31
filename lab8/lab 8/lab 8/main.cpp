#include<iostream>
#include<random>
#include"linked_list_template.h"
#include"Product.h"
#include"randomgenerator.h"

int main() {

	List<int> list;
	
	for (int i = 0; i < 5; ++i)
	{
		list.addItem(new int(randomGenerator(0, 50)));
	}

	return 0;
}