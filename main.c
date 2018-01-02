#include "craps.h"
/*******************************************************************************************
* Programmer: Marco Arceo                                                                      
* Class: CptS 121, Fall  2017; Lab Section 21                                    
* Programming Assignment: Statistical Analysis of Student Records                                                    
* Date: October 6th, 2017                                                                         
* Description: Create the game of 'craps'
*******************************************************************************************/

// Majority of the code in this program is from my PA4 from CPTS 111, syntax changes were done.
// A copy of my python code has been attached under 'Python.txt'

int main(void)
{
	// Define all the variables used in the program
	double initial_balance = 0.0, wager = 0.0, current_balance = 0.0, wager_amount = 0.0;
	int die1 = 0, die2 = 0, sum = 0, point_value = 0, result = 0, roll = 0, roll_amount = 0, games = 0;

	// Used to give the dice different results since it alters the time
	srand((unsigned int)time(NULL));

	// Basic functions that are not part of the loop
	print_game_rules();
	printf("\nThe objective of this game is accumalate as many games played before becoming bankrupt!\n\n");
	initial_balance = get_bank_balance();
	current_balance = initial_balance;

	// I tried implementing a similar format of code as my python code but i realized that do while's could make this easier since i spent 4+ hours figuring a way to copy my old code
	// This main loop is literally the reseaon why i submitted this late, i over thought it.

	while (current_balance > 0) // As long as the player has money, then the game continues
	{
		// Functions that check the first roll
		wager = get_wager();
		wager = check_wager_amount(wager, current_balance);
		wager_amount += wager;
		die1 = roll_die();
		die2 = roll_die();
		printf("\ndie1: %d die2: %d \n", die1, die2);
		roll_amount += 1;
		sum = calculate_sum_dice(die1, die2);
		printf("Sum of the dice: %d \n", sum);
		roll = is_win_loss_or_point(sum);

		// Jumps into this statement if a point is produced
		if (roll == -1)
		{
			point_value = sum;
			do
			{
				// This was copied from my attempted 'craps_loop' function
				// craps_loop(current_balance, wager, wager_amount, die1, die2, sum, point_value);
				printf("\n");
				wager = get_wager();
				wager = check_wager_amount(wager, current_balance);
				wager_amount += wager;
				die1 = roll_die();
				die2 = roll_die();
				printf("\ndie1: %d die2: %d \n", die1, die2);
				roll_amount += 1;
				sum = calculate_sum_dice(die1, die2);
				printf("Sum of the dice: %d \n", sum);

			} while (is_point_loss_or_neither(sum, point_value) == -1); // I was told to implement something like this into my code by a TA, forgot the persons name
			
			result = is_point_loss_or_neither(sum, point_value);

			if (result == 1)
			{
				printf("YOU WON! $$$\n\n");
			}
			else
			{
				printf("YOU LOST!\n\n");
			}
		}

		else
		{
			result = roll;
		}

		// Displays end of game information
		current_balance = adjust_bank_balance(current_balance, wager_amount, result);
		games += 1;
		chatter_messages(roll_amount, roll, initial_balance, current_balance, games);
		wager_amount = 0;
		roll_amount = 0;

	}
}