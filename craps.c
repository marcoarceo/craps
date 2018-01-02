/*******************************************************************************************
* Programmer: Marco Arceo                                                                      
* Class: CptS 121, Fall  2017; Lab Section 21                                    
* Programming Assignment: Statistical Analysis of Student Records                                                    
* Date: October 6th, 2017                                                                         
* Description: Create the game of 'craps'
*******************************************************************************************/

#include "craps.h"

// Prints out the rules of the game of "craps".
void print_game_rules(void)
{
	printf("A player rolls two dice. Each die has six faces. These faces contain 1, 2, 3, 4, 5, and 6 spots. After the dice have come to rest, the sum of the spots on the two upward faces is calculated.\n"); 
	printf("If the sum is 7 or 11 on the first throw, the player wins. If the sum is 2, 3, or 12 on the first throw (called craps), the player loses (i.e. the house wins).\n");
	printf("If the sum is 4, 5, 6, 8, 9, or 10 on the first throw, then the sum becomes the player's point.\n");
	printf("To win, you must continue rolling the dice until you make your point.The player loses by rolling a 7 before making the point. \n\n");
}

// Prompts the player for an initial bank balance from which wagering will be added or subtracted. 
// The player entered bank balance (in dollars, i.e. $100.00) is returned.
double get_bank_balance(void)
{
	double initial_balance = 0.0;
	printf("Enter your starting balance: $");
	scanf(" %lf", &initial_balance);
	return initial_balance;
}

// Prompts the player for a wager on a particular roll. The wager is returned
double get_wager(void)
{
	double wager = 0.0;
	printf("Enter your wager: $");
	scanf(" %lf", &wager);
	return wager;
}

// Checks to see if the wager is within the limits of the player's available balance. 
// If the wager exceeds the player's allowable balance, then 0 is returned; otherwise 1 is returned.
int check_wager_amount(double wager, double balance)
{
	// Following code was from my PA4 CPTS 111, Oct 12, 2016
	bool correct = true; // TA Ryan Manny
	while (correct)
	{
		if (wager <= balance)
		{
			correct = false;
		}
		else
		{
			system("cls");
			print_game_rules();	
			printf("Balance = $%.2lf \n\n", balance);
			printf("Enter a valid wager!\n");
			wager = get_wager();
		}
	}
	return wager;
}

// Rolls one die. This function should randomly generate a value between 1 and 6, inclusively. Returns the value of the die.
int roll_die(void)
{
	// Andy O'fallon Class Code
	int dieValue = 0; 

	dieValue = ((rand() % 6) + 1);

	return dieValue;
}

// Sums together the values of the two dice and returns the result. Note: this result may become the player's point in future rolls.
int calculate_sum_dice(int die1, int die2)
{
	int sum = 0;

	sum = die1 + die2;

	return sum;
}

// Determines the result of the first dice roll.
int is_win_loss_or_point(int sum)
{
	int win_loss = 0;

	if ((sum == 7) || (sum == 11))
	{
		printf("Congrats! You won money! $$$\n\n");
		win_loss = 1;
	}
	else if ((sum == 2) || (sum == 3) || (sum == 12))
	{
		printf("Holy 'CRAPS'! You lost!\n\n");
		win_loss = 0;
	}
	else
	{
		printf("POINT!\n");
		win_loss = -1;
	}
	return win_loss;
}

// Determines the result of any successive roll after the first roll.
int is_point_loss_or_neither(int sum, int point_value)
{
	int point_loss = 0;
	if (sum == point_value)
	{
		// printf("You matched your point! $$$\n\n");
		point_loss = 1;
	}
	else if (sum == 7)
	{
		// printf("Well, that money belongs to me now!\n\n");
		point_loss = 0;
	}
	else
	{
		point_loss = -1;
	}
	return point_loss;
}

// Updates the bank balance and notifies the player how much they won
double adjust_bank_balance(double current_balance, double wager_amount, int result)
{
	double round_earnings = 0;

	if (result == 1)
	{
		current_balance = current_balance + wager_amount;
		round_earnings = wager_amount;
		printf("Your total earnings for this round was $%.2lf\n", round_earnings);
	}
	else if (result == 0)
	{
		current_balance = current_balance - wager_amount;
		round_earnings = wager_amount;
		printf("Your total dedcution for this round was $%.2lf\n", round_earnings);
	}
	return current_balance;
}

// Tried making a function to place into the do while loop... failed.

//void craps_loop(double current_balance, double wager, double wager_amount, int die1, int die2, int sum, int point_value)
//{
//	wager = get_wager();
//	wager = check_wager_amount(wager, current_balance);
//	wager_amount += wager;
//	die1 = roll_die();
//	die2 = roll_die();
//	printf("die1: %d die2: %d \n", die1, die2);
//	sum = calculate_sum_dice(die1, die2);
//	printf("%d \n", sum);
//	return wager_amount;
//}

//Prints an appropriate message dependent on the number of rolls taken so far by the player, the current balance.
void chatter_messages(int roll_amount, int roll, double initial_balance, double current_balance, int games)
{
	printf("Cumulative games played: %d\n", games);
	printf("Total rolls this round: %d\n\n", roll_amount);
	printf("You began the game with a total of $%.2lf and your current balance is $%.2lf\n", initial_balance, current_balance);
}