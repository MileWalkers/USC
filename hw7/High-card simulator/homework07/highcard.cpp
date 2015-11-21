# include <iostream>
# include <string>
# include <time.h>
# include <cstdlib>


struct Card{
	int rank;
	std::string suit;
};

std::string cardToString(Card inputCard){
	std::string returnValue;
	if (inputCard.rank >= 2 && inputCard.rank <= 10){
		char temp[20];
		_itoa_s(inputCard.rank, temp, 10);
		returnValue += temp;
	}
	else if (inputCard.rank == 11)
		returnValue += "Jack";
	else if (inputCard.rank == 12)
		returnValue += "Queen";
	else if (inputCard.rank == 13)
		returnValue += "King";
	else if (inputCard.rank == 14)
		returnValue += "Ace";
	returnValue += " of " + inputCard.suit;
	return returnValue;
} 

Card makeCard(int rankOfFinalCard, std::string suitOfFinalCard){
	Card cardPile;
	cardPile.rank = rankOfFinalCard;
	cardPile.suit = suitOfFinalCard;
	return cardPile;
}

int getRandRank(){
	int randRank = std::rand() % 12 + 2;
	return randRank;
}

std::string getRandSuit(){
	int randSuitNumber = std::rand() % 4;
	std::string randSuit;
	if (randSuitNumber == 0)
		randSuit += "Diamonds";
	else if (randSuitNumber == 1)
		randSuit += "Clubs";
	else if (randSuitNumber == 2)
		randSuit += "Hearts";
	else if (randSuitNumber == 3)
		randSuit += "Spades";
	return randSuit;
}

bool isEqual(Card firstCard, Card secondCard){
	if (firstCard.rank == secondCard.rank)
		return true;
	else
		return false;
}

bool isLess(Card firstCard, Card secondCard){
	if (firstCard.rank < secondCard.rank)
		return true;
	else
		return false;
}

bool isGreater(Card firstCard, Card secondCard){
	if (firstCard.rank > secondCard.rank)
		return true;
	else
		return false;
}
int main(){
	std::srand(time(0));

	int counter=1;
	std::string player1Name, player2Name;
	int player1Score=0, player2Score=0;
	Card player1, player2;
	std::cout << "What's the name of player1? ";
	std::cin >> player1Name;
	std::cout << "What's the name of player2? ";
	std::cin >> player2Name;
	std::cout << "Welcome to the ESPN's coverage of the world champion High-card tournament finals!\n";
	std::cout << "It's a match between " << player1Name <<" and " << player2Name << "!\n";
	std::string goAgain = "y";
	while (goAgain == "y" || goAgain == "Y"){
		std::cout << "\nThey're starting round " << counter << ".\nThe players are shuffling...\n";
		if (std::rand() % 2 == 0)
			std::cout << "Isn't this exciting!\n";
		else
			std::cout << "Look at that!\n";
		player1 = makeCard(getRandRank(), getRandSuit());
		player2 = makeCard(getRandRank(), getRandSuit());
		if (isGreater(player1, player2)){
			std::cout << player1Name << "'s " << cardToString(player1) << " beat " << player2Name << "'s " << cardToString(player2) << " !\n";
			player1Score++;
		}
		if (isLess(player1, player2)){
			std::cout << player2Name << "'s " << cardToString(player2) << " beat " << player1Name << "'s " << cardToString(player1) << " !\n";
			player2Score++;
		}
		if (isEqual(player1, player2)){
			std::cout << player1Name << " drew a " << cardToString(player1) << " to match " << player2Name << "'s " << cardToString(player2) << " !\n";
			std::cout << "It's a DRAW!\n";
		}
		std::cout << "The socre is...\n";
		std::cout << player1Name << " : " << player1Score << ", " << player2Name << " : " << player2Score << "\n";
		counter++;
		std::cout << "Should the 2 players go again (y/n)?";
		std::cin >> goAgain;
	}

	std::cout << "\nWell that's all we have time for tonight.\nFor ESPN, this is Garrett Wang, reporting live!\n";
	return 0;


}