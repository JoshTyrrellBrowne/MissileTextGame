/// <summary>
/// Author: Josh Tyrrell Browne
/// Date: 20/09/2018
/// 
/// </summary>



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

	typedef struct Position
	{
		int x;
		int y;

		void print()
		{
			cout << x << y << endl;
		}

	}Coordinates;

	enum Warhead {EXPLOSIVE, NUCLEAR};

	typedef struct Enemy
	{
		Coordinates coordinates;
	}Target;

};