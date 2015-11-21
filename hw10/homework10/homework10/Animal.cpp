#include "Animal.h"
#include <fstream>
#include <string>
#include <iostream>

using namespace std;

Animal::Animal(){
	mName = "Animal";
	mHealth = 70;
	mPower = 60;
	mArmour = 50;
}

Animal::Animal(string name, int health, int power, int armour){
	mName = name;
	mHealth = health;
	mPower = power;
	mArmour = armour;
}

Animal::Animal(string filename){
	Load(filename);
}

string Animal::getName(){
	return mName;
}

int Animal::getHealth(){
	return mHealth;
}

int Animal::getPower(){
	return mPower;
}

int Animal::getArmour(){
	return mArmour;
}

void Animal::setName(string name){
	mName = name;
}

void Animal::setHealth(int health){
	if (health > 100)
		mHealth = 100;
	else if (health < 0)
		mHealth = 0;
	else
		mHealth = health;
}

void Animal::setPower(int power){
	if (power > 100)
		mPower = 100;
	else if (power < 0)
		mPower = 0;
	else
		mPower = power;
}

void Animal::setArmour(int armour){
	if (armour > 100)
		mArmour = 100;
	else if (armour < 0)
		mArmour = 0;
	else
		mArmour = armour;
}

void Animal::Load(string fileName){
	ifstream inFile(fileName);
	if (inFile.is_open()){
		int health, power, armour;
		string name;
		inFile >> health;
		setHealth(health);
		inFile >> power;
		setPower(power);
		inFile >> armour;
		setArmour(armour);
		inFile.ignore();
		getline(inFile, name);
		setName(name);
		inFile.close();
		cout << "Animal loaded!" << endl;
	}
	else{
		cout << "Sorry, open file failed" << endl;
		Animal();
	}
}

void Animal::Save(string fileName){
	int health, power, armour;
	ofstream outFile(fileName);
	if (outFile.is_open()){
		outFile << getHealth() << endl;
		outFile << getPower() << endl;
		outFile << getArmour() << endl;
		outFile << getName() << endl;
		outFile.close();
	}
}

