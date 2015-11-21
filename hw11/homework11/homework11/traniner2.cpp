#include <iostream>
#include <ctime>
#include "Animal.h"
#include <cstdlib>
#include <vector>

using namespace std;

Animal* RandOpponent(){
	Animal* animalPtr = new Animal;
	animalPtr->setHealth(50);
	animalPtr->setLevel(rand() % 5 + 1);
	animalPtr->setPower(rand() % 20 + 20);
	animalPtr->setArmour(rand() % 20 + 20);
	animalPtr->setXP(0);
	animalPtr->setName("EvilCorp");
	return animalPtr;
}

int main(){
	int option = -1;
	string name;
	srand(time(0));

	Animal* animalPtr;
	vector<Animal*> oppVector;
	animalPtr = new Animal;
	cout << "Welcome to the Training Arena!" << endl;
	cout << "Animal name? ";
	cin >> name;
	animalPtr->setName(name);
	while (option != 0){
		string name;
		int random;
		cout << "		MENU OPTIONS: " << endl;
		cout << "0. Quit" << endl;
		cout << "1. Print Stats" << endl;
		cout << "2. Heal Animal" << endl;
		cout << "3. Train Animal" << endl;
		cout << "What would you like to do ? ";
		cin.ignore();
		cin >> option;
		cout << endl;
		char a;
		int counter = 1;
		switch (option){
		case 0:
			oppVector.clear();
			cout << "Quiting program...\n" << endl;
			cout << "Thanks for playing!" << endl;
			break;

		case 1:
			animalPtr->PrintStats();
			break;

		case 2:
			random = rand() % 40 + 10;
			animalPtr->setHealth(animalPtr->getHealth() + random);
			cout << "Healed by " << random << "!" << endl;
			break;

		case 3:
			random = rand() % 3 + 1;
			for (int i = 0; i < random; i++){
				oppVector.push_back(RandOpponent());
			}

			cout << "Let's get ready to train your animal!" << endl;
			cout << random << " opponents generated!" << endl;
			if (animalPtr->isAwake()){
				while (counter <= random){
					cout << "Ready for Round " << counter << "? ";
					cin.ignore();
					cin >> a;
					cout << "******* Round " << counter << " *******" << endl;
					oppVector[counter - 1]->PrintStats();
					cout << "       VERSUS" << endl;
					animalPtr->PrintStats();
					animalPtr->FightOpponent(oppVector[counter - 1]);
					counter++;
				}
			}
			else{
				cout << "Oops...Your animal need to be healed.\n" << endl;
				break;
			}
			counter = 1;
			oppVector.clear();
			break;

		default:
			cout << "Oops! You enter a wrong nummber. Please try again!" << endl;
			break;
		}

	}
		return 0;
}