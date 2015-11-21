//
// Gong Jingwen
// ITP 165, Fall 2015
// Homework 10
// gongjing@usc.edu
//

#include "Animal.h"
#include <iostream>
#include <cstdlib>
#include <ctime>



void PrintStats(Animal& theAnimal){
    std::cout << "********************" << std::endl;
    std::cout << "Name: " << theAnimal.getName() << std::endl;
    std::cout << "Health: "<< theAnimal.getHealth() << std::endl;
    std::cout << "Power: " << theAnimal.getPower() << std::endl;
    std::cout << "Armour: "<< theAnimal.getArmour() << std::endl;
    std::cout << "********************" << std::endl;
}

int main() {
    std::srand(time(0));
    Animal* myAnimal = nullptr;
    std::cout <<"Welcome to ITP 165's Training Arena!" <<std::endl;
    std::cout <<"\n\tMENU OPTIONS:" <<std::endl;
    bool wan = true;
    while (wan){
        std::cout <<"0. Save and Quit" <<std::endl;
        std::cout <<"1. New Animal" <<std::endl;
        std::cout <<"2. Load Animal" <<std::endl;
        std::cout <<"3. Rename Animal" <<std::endl;
        std::cout <<"4. Print Stats" <<std::endl;
        std::cout <<"5. Heal Animal" <<std::endl;
        std::cout <<"6. Train Animal: COMING SOON" <<std::endl;
        std::cout <<"What would you like to do? ";
        int choice = 0;
        std::cin >> choice;
        switch ( choice ){
            case 0:
            {
                std::string txt0;
                std::cout <<"\nFile output name? ";
                std::cin >>txt0;
                myAnimal-> Save(txt0);
                std::cout <<"Save complete! Time to quit.\nThanks for playing! Goodbye."<<std::endl;
                wan = !wan;
                delete[] myAnimal;
                break;
            }
                
            case 1:
            {
                myAnimal = new Animal();
                std::cout <<"Creating new animal..."<<std::endl;
                std::cout <<"Welcome your new animal: "<<std::endl;
                PrintStats(*myAnimal);
                break;
            }

            case 2:
            {
                std::string txt2;
                std::cout <<"\nFile input name? ";
                std::cin >>txt2;
                myAnimal = new Animal;
                myAnimal -> Load(txt2);
                PrintStats(*myAnimal);
                break;
            }

            case 3:
            {
                std::string name;
                std::cout <<"\nNew name: ";
                std::cin.ignore();
                std::getline(std::cin, name);
                myAnimal -> setName(name);
                std::cout <<"New name set.\n"<<std::endl;
                PrintStats(*myAnimal);
                break;
            }

            case 4:
            {
                std::cout<<"\n";
                PrintStats(*myAnimal);
                std::cout<<"\n";
                break;
            }

            case 5:
            {
                int healnumber = std::rand()%10 + 1;
                std::cout <<"\nLet's see what your healing roll is..."<<std::endl;
                std::cout <<"Healed by "<<healnumber<<"!"<<std::endl;
                healnumber += myAnimal -> getHealth();
                myAnimal -> setHealth(healnumber);
                PrintStats(*myAnimal);
                
                break;
            }

            case 6:
            {
                std::cout<<"\nFeature coming soon!\n"<<std::endl;
                break;
            }

            default:
            {
                std::cout<<"\nInvalid choice. Try again.\n"<<std::endl;
                break;
            }
        }
        
    }

    return 0;
}
