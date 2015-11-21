//
// Gong Jingwen
// ITP 165, Fall 2015
// Homework 06
// gongjing@usc.edu
//


//不再进行的话没有显示输了多少钱
//再进行的话多显示了两行

#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

int roll()
{
    return std::rand()%6+1;
}
void roll(int diceRoll[], int arrSize)
{
    for(int i = 0; i < arrSize; i ++)
    {
        diceRoll[i] = roll();
    }
}
void displayRoll(int diceRoll[], int arrSize)
{
    std::cout<<"You rolled: "<<std::endl;
    for (int i = 0; i < arrSize; i ++)
        std::cout<<"\t"<<diceRoll[i]<<std::endl;
}
int computeBetResults(int diceRoll[], int arrSize, int money_bet, int number_bet)
{
    int number_matched = 0;
    for (int i = 0; i< arrSize; i++)
    {
        if(number_bet == diceRoll[i])
            number_matched ++;
    }
    std::cout<<"You matched "<<number_matched<<" dice!"<<std::endl;
    return number_matched;
}

int main()
{
    std::srand(time(0));
    const int arrSize = 3;
    int money_all = 100;
    int money_bet=0;
    int number_bet=0;
    int diceRoll[arrSize];
    std::string yes_no = "y";
    
    while (yes_no == "Y" ||yes_no =="y")
    {
        std::cout<<"STEP RIGHT UP AND PLAY SOME CHUCK-A-LUCK!\nYou have $"<<money_all;
        std::cout<<"\nEnter a bet amount: $";
        std::cin>>money_bet;
        while (money_bet> money_all ||money_bet<=0)
        {
            std::cout<<"Invalid bet. Please enter an amount from $1 to $"<<money_all<<std::endl;
            std::cout<<"Enter a bet amount: $";
            std::cin>>money_bet;
        }
        std::cout<<"What number do you want to bet on (1-6)? ";
        std::cin>>number_bet;
        while (number_bet>6 || number_bet<1)
        {
            std::cout<<"Invalid number. Must be between 1 and 6.\nWhat number do you want to bet on (1-6)? ";
            std::cin>>number_bet;
        }
        std::cout<<"You bet $"<<money_bet<<" on "<<number_bet<<std::endl;
        money_all -= money_bet;
        
        
        
        roll(diceRoll, arrSize);
        displayRoll(diceRoll, arrSize);
        int reSult = computeBetResults(diceRoll, arrSize, money_bet, number_bet);
        int money_win=0;
        if (reSult == 1)
            money_win = money_bet;
        else if (reSult == 2)
            money_win = 3 * money_bet;
        else if (reSult == 3)
            money_win = 10 * money_bet;
        if (reSult == 0)
            std::cout << "You lost your bet :(\n" << "You now have " << money_all << "\n";
        else
        {
            money_all += money_win + money_bet;
            std::cout << "YOU WIN $" << money_win << std::endl;
            std::cout<< "You now have $" << money_all<<std::endl;
        }
        if (money_all == 0){
            std::cout << "You lost the game!\n";
            break;
        }
        std::cout<<"Would you like to play again (y/n)? ";
        std::cin>>yes_no;
    }
        
    
    
    
    
    
    
    
    
    return 0;
}
