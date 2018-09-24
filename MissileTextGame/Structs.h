#pragma once
/// <summary>
/// the header file for structs
/// </summary>

#include <iostream>



typedef struct Position
{
	int x;
	int y;

	void print()
	{
		std::cout << x << y << std::endl;
	}

}Coordinates;

enum Warhead { EXPLOSIVE, NUCLEAR };

typedef struct Enemy
{
	Coordinates coordinates;
}Target;



struct Missile
{
	Warhead payload;

	Coordinates coordinates;

	Target target;

	bool armed;

	void arm()
	{
		if (armed)
			armed = false;
		else
			armed = true;
	}

	void update()
	{
		coordinates.x += 1;
		coordinates.y += 2;
	}

};