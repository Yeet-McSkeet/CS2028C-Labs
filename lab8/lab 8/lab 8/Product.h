#pragma once
#ifndef _PRODUCT_H
#define _PRODUCT_H
#include<string>
#include"randomgenerator.h"

class Product
{

private:
	int sku_;
	std::string	description_;
	float price_;
	int uom_;
	int quantity_;
	int leadtime_;

public:

	Product(int uom, std::string desc, float price, int sku, int quantity = 0)
	{
		uom_ = uom;
		description_ = desc;
		price_ = price;
		sku_ = sku;
		quantity_ = quantity;
		leadtime_ = randomGenerator<int>(1, 21);	// I admit, this is a little over the top
	}

	std::string getPartInfo() { return std::to_string(sku_) + description_; }
	float getPrice() { return price_; }
	bool inStock() { return quantity_ > 0; }

	bool operator <  (Product& prod){ return (this->sku_ <  prod.sku_); }
	bool operator >  (Product& prod){ return (this->sku_ >  prod.sku_); }
	bool operator == (Product& prod){ return (this->sku_ == prod.sku_); }
	

};

#endif // !_PRODUCT_H

