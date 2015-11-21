#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include "Animal.h"

using namespace std;

void PrintStats(Animal& animal){
	cout << "*******************" << endl;
	cout << "Name: " << animal.getName() << endl;
	cout << "Health: " << animal.getHealth() << endl;
	cout << "Power: " << animal.getPower() << endl;
	cout << "Armour: " << animal.getArmour() << endl;
	cout << "*******************" << endl;
}

int main(){
	srand(time(0));

	Animal myAnimal;
	Animal* animalPtr = &myAnimal;
	int option = -1;
	string filepath;
	cout << "Welcome to ITP 165's Training Arena!" << endl;
	while (option != 0){
		string name;
		int random;
		cout << endl;
		cout << "		MENU OPTIONS: " << endl;
		cout << "0. Save and Quit" << endl;
		cout << "1. New Animal" << endl;
		cout << "2. Load Animal" << endl;
		cout << "3. Rename Animal" << endl;
		cout << "4. Print Stats" << endl;
		cout << "5. Heal Animal" << endl;
		cout << "6. Train Animal: COMING SOON" << endl;
		cout << "What would you like to do ? ";
		cin >> option;
		cout << endl;
		switch (option){
		case 0:
			cout << "File output name? ";
			cin.ignore();
			getline(cin, filepath);
			animalPtr->Save(filepath);
			cout << "Save complete! Time to quit." << endl;
			cout << "Thanks for playing! Goodbye." << endl;
			delete(animalPtr);
			break;

		case 1:
			cout << "Creating new animal..." << endl;
			cout << "Welcome your new animal: " << endl;
			animalPtr = new Animal;
			PrintStats(*animalPtr);
			break;

		case 2:
			cout << "File input name? ";
			cin.ignore();
			getline(cin, filepath);
			animalPtr = new Animal;
			animalPtr->Load(filepath);
			PrintStats(*animalPtr);
			break;

		case 3:
			cout << "New name: ";
			cin.ignore();
			getline(cin, name);
			animalPtr->setName(name);
			PrintStats(*animalPtr);
			break;

		case 4:
			PrintStats(*animalPtr);
			break;

		case 5:
			cout << "Let's see what your healing roll is..." << endl;
			random = rand() % 10 + 1;
			cout << "Healed by " << random << "!" << endl;
			animalPtr->setHealth(animalPtr->getHealth() + random);
			PrintStats(*animalPtr);
			break;
		case 6:
			cout << "Feature coming soon!" << endl;
			break;
		default:
			option = -1;
			cout << "Invalid choice. Try again." << endl;
			break;
		}
	}


	return 0;
}