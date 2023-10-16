#include<iostream>
#include"Ordered_List.h"


int main() {

	Ordered_List<int> list;
	int a = 4;
	int b = 7;
	int c = 2;
	int d = 5;
	list.addItem(&a);
	list.addItem(&b);
	list.addItem(&d);
	list.addItem(&c);
	list.addItem(&b);
	list.addItem(&a);
	list.addItem(&c);
	list.addItem(&d);

	int asdfghjkl = 0;

	return 0;
}