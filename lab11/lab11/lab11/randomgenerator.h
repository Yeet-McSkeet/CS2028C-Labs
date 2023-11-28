#pragma once
/*------------------------------------------*
 *											|
 *	This header includes a random generator	|
 *	based off of the mt19937 generator.		|
 *											|
 *	There are 19937 different possible		|
 *	outcomes, this garnering the name.		|
 *											|
 *------------------------------------------*/
#ifndef _RANDOM_H
#define _RANDOM_H
#include<random>
template<typename T>
T randomGenerator(T range_from, T range_to)
{
	std::random_device                  rand_dev;
	std::mt19937                        generator(rand_dev());
	std::uniform_int_distribution<T>    distr(range_from, range_to);
	return distr(generator);
}
#endif // !_RANDOM_H