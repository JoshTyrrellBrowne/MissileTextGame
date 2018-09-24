/// <summary>
/// Author: Josh Tyrrell Browne
/// Date: 20/09/2018
/// 
/// </summary>

#include <iostream>
#include "Structs.h"
#include <time.h>       /* time */

int main()
{
	srand(time(NULL));
	Missile rocket;


	int warheadType;

	std::cout << "Select a Warhead type, Enter 1 for Explosive or 2 for Nuclear." << std::endl;
	std::cin >> warheadType;

	if (warheadType == 1)
	{
		rocket.payload = EXPLOSIVE;
	}
	if (warheadType == 2)
	{
		rocket.payload = NUCLEAR;
	}

	rocket.target.coordinates.x = rand() % 100;
	rocket.target.coordinates.y = rand() % 100;


	std::cout << "Enemy Target position has been found at: ";
	rocket.target.coordinates.print();
	


	system("pause");
}