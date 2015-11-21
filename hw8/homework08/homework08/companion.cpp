#include <iostream>
#include <string>
#include <fstream>
#include "Dog.h"

using namespace std;

void Dog::setHappy(int newHappy){
	mHappy = newHappy;
}
int Dog::getHappy(){
	return mHappy;
}
void Dog::setHunger(int newHunger){
	mHunger = newHunger;
}

int Dog::getHunger(){
	return mHunger;
}
void Dog::setName(string newName){
	petName = newName;
}
string Dog::getName(){
	return petName;
}

void Dog::PrintStats(){
	cout << "****************" << endl;
	cout << "Name: " << petName << endl;
	cout << "Health: " << mHunger << endl;
	cout << "Happyiness: " << mHappy << endl;
	cout << "****************" << endl;
}

void Dog::Play(){
	mHunger += 5;
	mHappy += 10;
}

void Dog::Feed(){
	mHunger -= 10;
}

int main(){
	Dog dog;
	int hunger, happy;
	string name, filePath;
	cout << "What is the input file? ";
	getline(cin, filePath);
	ifstream inFile(filePath);
	if (inFile.is_open()){
		while (inFile.eof() != true){
			string name;
			inFile >> hunger;
			dog.setHunger(hunger);
			inFile >> happy;
			dog.setHappy(happy);
			inFile.ignore();
			getline(inFile, name);
			dog.setName(name);
		}
		inFile.close();
	}
	else{
		cout << "File not found!\nQuitting..." << endl;
	}
	int move = -1;
	while (move != 0){
		cout << "1. Play with the animal" << endl;
		cout << "2. Feed the animal" << endl;
		cout << "3. Rename the animal" << endl;
		cout << "4. Print the stats of animal" << endl;
		cout << "0. Save and Quit" << endl;
		cout << "What would you like to do with your doggie? ";
		cin >> move;
		string newName;
		switch (move){
			case 1:
				dog.Play();
				cout << "Woof! Woof! You have now played with Fido the Dog!" << endl;
				break;
			case 2:
				dog.Feed();
				cout << "Yummy! You have just fed " << dog.getName() << endl;
				break;
			case 3:
				cout << "New name: ";
				cin.ignore();
				getline(cin, newName);
				dog.setName(newName);
				break;
			case 4:
				dog.PrintStats();
				break;
			case 0:
				cout << "Time to save your doggie!" << endl;
				break;
		}
	}
	cout << "What is the output file? ";
	cin.ignore();
	getline(cin, filePath);
	ofstream outFile(filePath);
	if (outFile.is_open()){
		outFile << dog.getHunger() << endl;
		outFile << dog.getHappy() << endl;
		outFile << dog.getName() << endl;
		outFile.close();
		cout << "Saved your doggie to " << filePath << endl;
		cout << "Quitting..." << endl;
	}
	else{
		cout << "Save failed.\nQuitting..." << endl;
	}

	return 0;
}
