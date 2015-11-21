//
// Gong Jingwen
// ITP 165, Fall 2015
// Homework 10
// gongjing@usc.edu
//

#include "Animal.h"
#include <string>
#include <iostream>
#include <fstream>
/**********Constructors**********/
//mName: "Animal"
//mHealth: 70
//mPower: 60
//mArmour: 50
Animal::Animal()
{
    mName =  "Animal";
    mHealth = 70;
    mPower = 60;
    mArmour = 50;
}
//Non-Default Constructor: will set private member variables via parameters
//mName: name
//mHealth: health
//mPower: power
//mArmour: armour
Animal::Animal(std::string name, int health, int power, int armour)
{
    mName = name;
    mHealth = health;
    mPower = power;
    mArmour = armour;
}

//Non-Default Constructor: will set private member variables from data in file
//calls implemented Load(fileName) function
Animal::Animal(std::string fileName)
{
    Load (fileName);
}

/**********Getters**********/
std::string Animal::getName()
{
    return mName;
}
int Animal::getHealth()
{
    return mHealth;
}
int Animal::getPower()
{
    return mPower;
}
int Animal::getArmour()
{
    return mArmour;
}

/**********Setters**********/
void Animal::setName(std::string name)
{
    mName = name;
}
void Animal::setHealth(int health)
{
    if (health > 100)
    {
        mHealth = 100;
    }
    else if(health < 0 )
    {
        mHealth = 0;
    }
    else
    {
        mHealth = health;
    }
}
void Animal::setPower(int power)
{
    if (power > 100)
    {
        mPower = 100;
    }
    else if(power < 0 )
    {
        mPower = 0;
    }
    else
    {
        mPower = power;
    }

}
void Animal::setArmour(int armour)
{
    if (armour > 100)
    {
        mArmour = 100;
    }
    else if (armour < 0)
    {
        mArmour = 0;
    }
    else
    {
        mArmour = armour;
    }
}

/**********Other functions**********/
//Name: Load
//Purpose: Opens file to read in animal data to temporary variables, CLOSES the file,
//		   then sets animal data with temp variable values - sets animal data to default values if file open failed
//Parameters: string of file name to be opened
//Return: none
void Animal::Load(std::string fileName)
{
    std::ifstream fin (fileName);
    if (fin.is_open())
    {
        int health;
        int power;
        int armour;
        std::string name;
        fin >> health;
        fin >> power;
        fin >> armour;
        fin.ignore();
        std::getline(fin, name);
        fin.close();
        setHealth(health);
        setPower(power);
        setArmour(armour);
        setName(name);
        std::cout<<"Animal loaded!"<<std::endl;
    }
    else
    {
        std::cout<<"Sorry, open file failed"<<std::endl;
        Animal();
    }
}

//Name: Save
//Purpose: Opens a file to write CURRENT animal data to, then CLOSES the file, does nothing if file open failed
//Parameters: string of file name to be opened
//Return: none
void Animal::Save(std::string fileName)
{
    std::ofstream fout (fileName);
    if (fout.is_open())
    {
        fout << mHealth << std::endl;
        fout << mPower <<std::endl;
        fout << mArmour <<std::endl;
        fout << mName <<std::endl;
    }
}











