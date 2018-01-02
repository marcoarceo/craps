/*******************************************************************************************
* Programmer: Marco Arceo                                                                      
* Class: CptS 121, Fall  2017; Lab Section 21                                    
* Programming Assignment: Statistical Analysis of Student Records                                                    
* Date: October 6th, 2017                                                                         
* Description: Create the game of 'craps'
*******************************************************************************************/

#ifndef CRAPS_H // I dont know if this is necessary, i just copied it from O'Fallon's PA help
#define CRAPS_H // Same as above

#include <stdio.h>
#include <stdlib.h> // rand (), srand ()
#include <time.h> // time ()
#include <stdbool.h> // TA Ryan Manny 

void print_game_rules(void);
double get_bank_balance(void);
double get_wager(void);
int check_wager_amount(double wager, double balance);
int roll_die(void);
int calculate_sum_dice(int die1, int die2);
int is_win_loss_or_point(int sum);
int is_point_loss_or_neither(int sum, int point_value);
double adjust_bank_balance(double balance, double wager_amount, int result);
// void craps_loop(double current_balance, double wager, double wager_amount, int die1, int die2, int sum, int point_value);
void chatter_messages(int roll_amount, int , double initial_balance, double current_balance, int games);

#endif