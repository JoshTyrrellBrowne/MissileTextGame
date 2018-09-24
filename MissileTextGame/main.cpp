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

	bool hitTarget = false;

	while (hitTarget == false)
	{
		Missile rocket;

		int launchCode = rand() % 8999 + 1000;
		int inputCode = 0;
		int warheadType = 0;
		int missileFire = 0;
		//bool hitTarget = false;

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

		std::cout << "To fire missile, enter the Launch Code: " << launchCode << std::endl;
		std::cin >> inputCode;

		while (inputCode != launchCode)
		{
			std::cout << "To arm the missile, enter the Launch Code: " << launchCode << std::endl;
			std::cin >> inputCode;
		}

		rocket.arm();
		rocket.coordinates.x = 0;
		rocket.coordinates.y = 0;

		std::cout << "The missile is armed, enter 1 to fire missile." << std::endl;
		std::cin >> missileFire;

		while (missileFire != 1)
		{
			std::cout << "The missile is armed, enter 1 to fire missile." << std::endl;
			std::cin >> missileFire;
		}


		while (rocket.coordinates.y <= rocket.target.coordinates.y)
		{
			rocket.update();
			if (rocket.coordinates.y == rocket.target.coordinates.y)
			{
				if (rocket.coordinates.x == rocket.target.coordinates.x)
				{
					hitTarget = true;
				}
			}
		}

		if (hitTarget == false)
		{
			std::cout << "You have missed the target, try again!" << std::endl;
		}

	}

	if (hitTarget == true)
	{
		std::cout << "You have hit and destroyed your target!!" << std::endl;
	}



	system("pause");
}