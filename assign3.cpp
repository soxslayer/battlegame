/***********************************************************
 * Author:			   Ian Bender
 * Date Created:     8/1/2014		
 * Last Modified:    8/1/2014	
 * Description:      Assignment 3
 * Filename:		   assign3.cpp	
 *
 * Overview: A simple fantasy game featuring four characters
 *    with characteristics for attack, defense, armor, and
 *    strength.
 *
 * Input: User selects two characters for combat. Gameplay generates
 *    two dice rolls to determine attack and defense values.
 *
 * Output: Battle continues until one character is left with no
 *    strength (dead). Each turn will display updated character stats.
 **********************************************************/	

#include <iostream>
#include <cstdlib>
#include <ctime>
#include "creature.h"

using std::cout;
using std::cin;
using std::endl;

//test user input for valid menu selection
bool validInt(int selection, int limit);
//show character menu
void showMenu();
//get user selection for character choice
Bender::Creature* playerChoice(int playerNum);
//run battle simulation
void startBattle(Bender::Creature *p1, Bender::Creature *p2);
//attack and defense with screen output
void playerAttack(Bender::Creature *p1, Bender::Creature *p2);

int main()
{
   Bender::Creature *p1;
   Bender::Creature *p2;
   char play_again;

   srand(time(0)); 

   cout << std::string(30, '\n') 
        << "***ASSIGNMENT 3: FANTASY COMBAT***\n";
   
   //display menu, get user input
   do 
   {
      showMenu();

      //select characters for battle
      p1 = playerChoice(1);
      p2 = playerChoice(2);

      cin.ignore();
     
      //battle between two Creature objects
      startBattle(p1, p2);

      cout << "Would you like to play again? (y/n): ";
      cin >> play_again;
   } while (play_again == 'Y' || play_again == 'y');

   cout << "Game over.\n";
   
   return 0;
}

/***************************************************
 * Name:    validInt 
 * Entry:   Parameters for user selection, integer limit.
 * Exit:    Returns false if selection is not a valid integer or
 *             not within the necessary range, otherwise true.
 * Purpose: Check for valid integer input from the user. 
 *************************************************/
bool validInt(int selection, int limit) //check for valid integer
{
   using std::cout; 
   using std::cin;

   bool valid = true;

   if (cin.fail() || cin.peek() != '\n') //not an integer
   {
      cin.clear();
      cin.ignore(1000, '\n');
      valid = false;
   }
   else if (selection < 1 || selection > limit) //input out of range
   {
      valid = false;
   }

   if (!valid)
   {
      cout << "Not a valid selection.\n\n";
   }

   return valid;
}

/***************************************************
 * Name:    showMenu
 * Entry:   no parameters 
 * Exit:    Output to screen. 
 * Purpose: Display list of available characters. 
 *************************************************/
void showMenu()
{
   cout << "Choose from these available characters:\n"
        << " 1. Goblin\n"
        << " 2. Barbarian\n"
        << " 3. Reptile People\n"
        << " 4. Blue Men\n";

   return;
}

/***************************************************
 * Name:    playerChoice
 * Entry:   Integer for player number
 * Exit:    Returns Creature object of user selection. 
 * Purpose: Get menu selection for character choice. 
 *************************************************/
Bender::Creature* playerChoice(int playerNum)
{
   int selection;
   Bender::Creature *player;

   do //loop until a valid selection is made
   {
      cout << "Select a character for player " << playerNum << ": "; 
      cin >> selection;
   } while (!validInt(selection, 4));

   //create Creature object from specified derived class
   switch (selection)
   {
   case 1:
         player = new Bender::goblin;
         break;
   case 2:
         player = new Bender::barbarian;
         break;
   case 3:
         player = new Bender::reptile;
         break;
   case 4:
         player = new Bender::blueman;
         break;
   }

   return player;
}

/***************************************************
 * Name:    startBattle 
 * Entry:   Parameters for two Characters objects. 
 * Exit:    Characters objects member variables for life
 *             are modified.
 * Purpose: Battle sequence between player 1 and player 2. 
 *************************************************/
void startBattle(Bender::Creature *p1, Bender::Creature *p2)
{
   do //loop while both players are still alive
   {
      playerAttack(p1, p2); //p1 attack, p2 defends
      playerAttack(p2, p1); //p2 attack, p1 defends

      //both players kill each other
      if (p1->getStrength() <= 0 && p2->getStrength() <= 0)
      {
         cout << "The battle is over! The players have mutually "
              << "destroyed each other!\n";
      }
      //player 1 dies
      else if (p1->getStrength() <= 0)
      {
         cout << "Player 1's " << p1->getName()
              << " has died! Player 2's " << p2->getName() 
              << " is the victor!\n";
      }
      //player 2 dies
      else if (p2->getStrength() <= 0)
      {
         cout << "Player 2's " << p2->getName()
              << " has died! Player 1's " << p1->getName() 
              << " is the victor!\n";
      }
   } while (p1->getStrength() > 0 && p2->getStrength() > 0);

   cout << endl;
   return;
}

void playerAttack(Bender::Creature *p1, Bender::Creature *p2)
{
   int attack;
   int defense;
   int damage;

   cout << std::string(30, '\n')
        << "** " << p1->getName() << " ATTACKS **\n";
   
   cout << p1->getName() << "'s turn -- ";
   //roll dice for attack
   attack = p1->rollAttack();
   cout << p1->getName() << " rolls an attack of " 
        << attack << ".\n\n"; 

   cout << p2->getName() << "'s turn -- ";
   //roll dice for defense
   defense = p2->rollDefense();
   cout << p2->getName() <<  " rolls a defense of " 
        << defense << ".\n\n";

   //display battle outcome
   damage = attack - defense; 
   p2->setStrength(damage);
   cout << "Total Attack Damage: " << damage << endl
        << p2->getName() << " Armor Value: " 
        << p2->getArmor() << endl
        << p2->getName() << " Remaining Strength: " 
        << p2->getStrength() << endl << endl;

   //pause for user
   cout << "Press ENTER to continue.\n";
   cin.ignore();

   return;
}

