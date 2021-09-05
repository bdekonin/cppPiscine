/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: bdekonin <bdekonin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/02/19 14:59:04 by bdekonin      #+#    #+#                 */
/*   Updated: 2021/09/03 11:01:53 by bdekonin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"
#include <time.h>
#include <iostream>

#define MAX_VAL 750

template<typename T>
void print(T const list)
{
	list[0] = 3;
	for (int i = 0; i < (int)list.size(); i++)
		std::cout << list[i] << std::endl;
}

int main(int, char**)
{
	Array<int> list(3);

	list[0] = 0;
	list[1] = 1;
	list[2] = 2;

	print(list);
}
