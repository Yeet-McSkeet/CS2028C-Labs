#include<iostream>
#include<random>
#include<string>
#include"linked_list_template.h"
#include"Product.h"
#include"randomgenerator.h"

int main() {

	List<Product> list;
	
	std::string main_prompt = " Enter the number of the action:\n1: Create a new item\n2: Get item from list\n3: See next item in list\n4: See previous item in list\n5: See if item is in list\n";

	do
	{
		std::cout << main_prompt;
		std::string sel;
		std::getline(std::cin, sel);
		if (sel == "1")
		{
			std::string uom;
			std::cout << "Enter the number corresponding to the unit:\n1: each\n2: foot\n3: pound \n";
			std::getline(std::cin, uom);

			std::string price;
			std::cout << "Enter the price (as a float)" ;
			std::getline(std::cin, price);

			std::string SKU;
			std::cout << "Enter the SKU (as an integer)" ;
			std::getline(std::cin, SKU);

			Product* prod = new Product(atoi(uom.c_str()), " default description", atof(price.c_str()), atoi(SKU.c_str()));
			list.addItem(prod);
			system("CLS");
		}
		else if (sel == "2")
		{
			std::string SKU;
			std::cout << "Enter the SKU (as an integer)";
			std::getline(std::cin, SKU);

			Product* prod = new Product(0, "", 0, atoi(SKU.c_str()));
			Node<Product>* item = new Node<Product>{prod, nullptr, nullptr};
			Node<Product>* item2 = list.getItem(item);
			if (item2)
			{
				delete item;
				system("CLS");
				std::cout << item2->data_->getPartInfo();
				list.addItem(item2->data_);
				delete item2;
			}
			else
			{
				system("CLS");
				std::cout << "Item does not exist." << std::endl;
			}
		}
		else if (sel == "3")
		{
			Node<Product>* next = list.seeNext();
			system("CLS");
			if (next)
			{
				std::cout << next->data_->getPartInfo();
			}
			else
			{
				std::cout << "No next item." << std::endl;
			}
			next = nullptr;
		}
		else if (sel == "4")
		{
			Node<Product>* prev = list.seePrev();
			system("CLS");
			if (prev)
			{
				std::cout << prev->data_->getPartInfo();
			}
			else
			{
				std::cout << "No previous item." << std::endl;
			}
			prev = nullptr;
		}
		else if (sel == "5")
		{
			std::string idx;
			std::cout << "Enter the index (as an integer)";
			std::getline(std::cin, idx);
			Node<Product>* cur = list.seeAt(atoi(idx.c_str()));
			system("CLS");
			if (cur)
			{
				std::cout << cur->data_->getPartInfo();
			}
			else
			{
				std::cout << "No item exists at that index." << std::endl;
			}
			cur = nullptr;
		}
		else
		{
			break;
		}
	} while (true);

	return 0;
}