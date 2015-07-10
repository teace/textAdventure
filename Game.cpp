#include <iostream>
#include <string> 
#include <time.h>
#include <fstream>
#include "monster.h"
#include "playerMove.h"
using namespace std;

void game();
void chapter1();
void battle(monster opponent, playerMove playerMove1, playerMove playerMove2, playerMove playerMove3);

string name;
double playerDamage;
double playerAccuracy;
double playerHealth;
double playerEvasiveness;
char userChoice;

int main()
{
	cout << "What is your name?" << endl;
	cin >> name;
	cout << name << ", what is your gender?" << endl;
	cout << "1) Male" << endl;
	cout << "2) Female" << endl;
	cin >> userChoice;

	if (userChoice == 1){
		playerDamage = 5;
		playerEvasiveness = 15;
	}
	else{
		playerDamage = 4;
		playerEvasiveness = 20;
	}
	
	playerAccuracy = 85;
	playerHealth = 30;

	cout << "With this information, you may begin your journey." << endl;
	cout << "Start?   y/n" << endl;
	cin >> userChoice;
	switch (userChoice)
	{
	case 'y':
		cout << "Begin" << endl;
		game();
		break;
	case 'n':
		cout << "Goodbye" << endl;
		return 0;
		break;
	default:
		cout << "That is not an option" << endl;
		return 0;
		break;
	}
}

void game()
{
	chapter1();
}

void chapter1()
{
	char Continue;
	cout << "Initiate = simulation.'" << endl;
	cin >> Continue;

	cout << ". . . . . . . . . . . . . . . . . . . . . . . . . . . ." << endl;
	cin >> Continue;

	cout << "You wake to darkness. You feel stone, damp and smooth. You stand, naked but" << endl;
	cout << "for ragged clothes." << endl;
	cin >> Continue;

	cout << "As your eyes adjust to the dark, you notice your placement in a circular" << endl;
	cout << "cave. You feel that beside you there lies a rusty sword, perhaps lying here for hundreds of years." << endl;
	cin >> Continue;

	cout << "There are three tunnels that penetrate the otherwise smooth stone." << endl;
	cin >> Continue;

	cout << "Covering the left tunnel in detailed design are webs, and a lightless" << endl;
	cout << "void of darkness." << endl;
	cin >> Continue;

	cout << "The middle tunnel holds no cobwebs, and you can hear very faint voices coming from the tunnel. Blank blue banners cover the wall." << endl;
	cin >> Continue;

	cout << "To the right is a clear tunnel with nought but few cobwebs, you see dim light." << endl;
	cin >> Continue;

	cout << "Where do you proceed, " << name << "?" << endl;
	cout << "1) The Left Tunnel" << endl;
	cout << "2) The Middle Tunnel" << endl;
	cout << "3) The Right Tunnel" << endl;
	cin >> userChoice;

	if (userChoice == '1'){
		cout << "You encounter a large spider." << endl;
		ifstream lSpider;
		string output;
		lSpider.open("spiderASCII.txt");
		if (lSpider.is_open()){
			while (getline(lSpider, output)){
				cout << output << endl;
			}
		}
		monster largeSpider = spider(15, 2, 90, 25, "Spider");
		playerMove spider1 = playerMove("Stab the spider.", 2.0, 5.0);
		playerMove spider2 = playerMove("Cut the spider's legs.", 5.0, -15.0);
		playerMove spider3 = playerMove("Run away", -playerDamage, -playerAccuracy);
		battle(largeSpider, spider1, spider2, spider3);
	}
	if (userChoice == '2'){
		
	}

}

void battle(monster opponent, playerMove playerMove1, playerMove playerMove2, playerMove playerMove3)
{
	while (opponent.getHealth() > 0){
		cout << "What would you like to do?" << endl
			<< "1) " << playerMove1.getName() << endl
			<< "2) " << playerMove2.getName() << endl
			<< "3) " << playerMove3.getName() << endl;
		int userInput;
		playerMove userMove;
		cin >> userInput;
		bool invalidplayerMove = false;
		do{
			switch (userInput){
			case 1:
				cout << "You attack the " << opponent.getName() << "." << endl;
				userMove = playerMove1;
				break;
			case 2:
				cout << "You attack the " << opponent.getName() << "." << endl;
				userMove = playerMove2;
				break;
			case 3:
				userMove = playerMove3;
				break;
			default:
				cout << "Invalid player move." << endl;
				invalidplayerMove = true;
			}
		} while (invalidplayerMove == true);

			if (rand() % 100 < (userMove.getAccuracyModifier() + playerAccuracy - opponent.getEvasiveness())){
				cout << "You hit and deal " << playerDamage + userMove.getDamageModifier() << " to the " << opponent.getName() << endl;
				opponent.changeHealth(playerDamage + userMove.getDamageModifier());
			}
			else if (userInput == 3){
				cout << "You run away, but " << opponent.getName() << "chases you." << endl;
			}
			else{
				cout << "You missed!" << endl;
			}

			if (opponent.getHealth() > 0){
				if (rand() % 100 < (opponent.getAccuracy() - playerEvasiveness)){
					cout << "The " << opponent.getName() << " " << opponent.getPlayerMove() << " and deals " << opponent.getDamage() << " damage!" << endl;
					playerHealth -= opponent.getDamage();
				}
				else{
					cout << "The " << opponent.getName() << " " << opponent.getPlayerMove() << " but misses!" << endl;
				}
			}
		cout << "You now have " << playerHealth << " health." << endl;
		if (userInput == 3){
			cout << "You have successfully ran away." << endl;
			opponent.changeHealth(opponent.getHealth());
		}
	}
}

