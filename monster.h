
#include <iostream>
#include <string> 
#include <time.h>
using namespace std;

class monster
{
public: double health;
		double damage;
		double accuracy;
		double evasiveness;
		string name;

		double getHealth()
		{
			return health;
		}
		double getDamage()
		{
			return damage;
		}
		double getAccuracy()
		{
			return accuracy;
		}
		double getEvasiveness()
		{
			return evasiveness;
		}
		string getName()
		{
			return name;
		}
		void changeHealth(double dmg)
		{
			health = health - dmg;
		}
		virtual string getPlayerMove(){
			return "";
		}
};

class spider : public monster{
public:
	spider()
	{
		health = 0;
		damage = 0; 
		accuracy = 0;
		evasiveness = 0;
		name = "";
	}
	spider(double h, double d, double a, double e, string n)
	{
		health = h;
		damage = d;
		accuracy = a;
		evasiveness = e;
		name = n;
	}
	string getPlayerMove()
	{
		string dialogs[3] = { "rams you into the wall", "sinks its sharp teeth into your arm", "knocks you into the webbing, ravaging you" };
		
		return dialogs[rand() % 3];
	}
};

class dragon : public monster{
public:
	dragon()
	{
		health = 0;
		damage = 0;
		accuracy = 0;
		evasiveness = 0;
		name = "";
	}
	dragon(double h, double d, double a, double e, string n)
	{
		health = h;
		damage = d;
		accuracy = a;
		evasiveness = e;
		name = n;
	}

	string getPlayerMove()
	{
		string dialogs[3] = { "spits out a fireball", "kicks you in the face", "flaps his wings and knocks you back" };

		return dialogs[rand() % 3]; //
	}
};