#define  _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstdlib>
#include <ctime>


int roll(){
	return std::rand()%6+1;
}

void roll(int diceRolls[], int sizeOfArray){
	int i;
	for (i = 0; i < sizeOfArray; i++)
		diceRolls[i] = roll();
	return;
}

void displayroll(int diceRolls[], int sizeOfArray){
	int i;
	for (i = 0; i < sizeOfArray; i++)
		std::cout << "\t" << diceRolls[i]<<"\n";
}

int computeBetResult(int diceRolls[], int sizeOfArray, int amountUserBet, int numberBetOn){
	int i, amountUserWon=0;
	for (i = 0; i < sizeOfArray; i++){
		if (numberBetOn == diceRolls[i])
			amountUserWon++;
		}
	std::cout << "You matched " << amountUserWon << " dice!\n";
	return amountUserWon;
}

void main(){
	std::srand(time(0));
	const int sizeOfArray = 3;
	int diceRolls[sizeOfArray], userMoney = 100, amountUserBet, theNumberUserBet;
	char playAgain='y';
	std::cout << "STE RIGHT UP AND PLAY SOME CHUCK-A-LUCK!\n";
	std::cout << "You have " << userMoney << "\n";
	while (playAgain == 'y'){
		std::cout << "Enter a bet amount: $";
		std::cin >> amountUserBet;
		while (amountUserBet<1 || amountUserBet>userMoney){
			std::cout << "Invalid bet. Please enter an amount from $1 to $" << userMoney;
			std::cout << " Enter a bet amount: $";
			std::cin >> amountUserBet;
		}
		std::cout << "What number do you want to bet on (1-6)? ";
		std::cin >> theNumberUserBet;
		while (theNumberUserBet<1 || theNumberUserBet>6) {
			std::cout << "Invalid number. Must be between 1 and 6.\n";
			std::cout << "What number do you want to bet on (1-6)? ";
			std::cin >> theNumberUserBet;
		}
		std::cout << "You bet $" << amountUserBet << " on " << theNumberUserBet << "\n";
		userMoney -= amountUserBet;
		roll(diceRolls, sizeOfArray);
		std::cout << "You rolled:\n";
		displayroll(diceRolls, sizeOfArray);
		int result = computeBetResult(diceRolls, sizeOfArray, amountUserBet, theNumberUserBet);
		int moneyUserWin;
		if (result == 1)
			moneyUserWin = amountUserBet;
		else if (result == 2)
			moneyUserWin = 3 * amountUserBet;
		else if (result == 3)
			moneyUserWin = 10 * amountUserBet;
		if (result == 0)
			std::cout << "You lost your bet :(\n" << "You now have " << userMoney << "\n";
		else{
			userMoney += moneyUserWin + amountUserBet;
			std::cout << "YOU WIN $" << moneyUserWin << "\n" << "You now have " << userMoney<< "\n";
		}
		if (userMoney == 0){
			std::cout << "You lost the game!\n";
			return;
		}
		std::cout << "Would you like to play again(y/n)?";
		std::cin >> playAgain;
	}
	std::cout << "You ended the game with $" << userMoney << "\n";
}