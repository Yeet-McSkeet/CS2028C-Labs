#include<iostream>
#include"Ordered_List.h"


int main() {

	Ordered_List<int> list;
	int* a = new int;
	*a = 4;
	int* b = new int;
	*b = 7;
	int* c = new int;
	*c = 5;
	int* d = new int;
	*d = 2;
	list.addItem(a);
	list.addItem(d);
	list.addItem(b);
	list.addItem(c);

	int asdfghjkl = 0;

	list.makeEmpty();

	list.addItem(a);
	list.addItem(d);
	list.addItem(b);
	list.addItem(c);

	return 0;
}