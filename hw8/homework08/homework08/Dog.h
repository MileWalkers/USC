#pragma once
#include <string>

using namespace std;

class Dog
{
public:
	void setHappy(int);
	int getHappy();
	void setHunger(int);
	int getHunger();
	void setName(string);
	string getName();
	void PrintStats();
	void Play();
	void Feed();

private:
	int mHunger;
	int mHappy;
	string petName;
};