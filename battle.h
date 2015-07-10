#include <iostream>
#include <string> 
#include <time.h>
#include "monster.h"
#include "move.h"
using namespace std;

class battle
{
public:
	monster opponent;
	move moveA;
	move moveB;
	move moveC;

	battle(monster opponent, move move1, move move2, move move3)
	{
		cout << "What would you like to do?" << endl
			<< "1) " << move1 << endl
			<< "2) " << move2 << endl
			<< "3) " << move3 << endl;
		int userInput;
		cin >> userInput;
		
		switch (userInput){
		case 1:
			cout << "You attack the " << opponent.getName() << "." << endl;
			
		case 2:
		case 3:
		default:
		}

		if (//accuracy forumla)
		{
			cout << "You hit and deal " << playe
		}
	}

	string action()
	{
		
	}
};

