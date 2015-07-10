
#include <iostream>
#include <string> 
#include <time.h>
using namespace std;

class playerMove
{
public:
	string name;
	double damageModifier; 
	double accuracyModifier;

	playerMove(){
		name = "";
		damageModifier = 0;
		accuracyModifier = 0;
	}
	playerMove(string n, double d, double a)
	{
		name = n;
		damageModifier = d;
		accuracyModifier = a;
	}
	double getDamageModifier()
	{
		return damageModifier;
	}
	double getAccuracyModifier()
	{
		return accuracyModifier;
	}
	string getName()
	{
		return name;
	}
};

