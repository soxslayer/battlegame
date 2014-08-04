/***********************************************************
 * Author:			   Ian Bender
 * Date Created:     8/1/2014		
 * Last Modified:    8/3/2014	
 * Description:      Assignment 3
 * Filename:		   Creature.cpp	
 *
 * Overview: Implementation for Creature class.
 **********************************************************/	

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include "creature.h"

namespace Bender
{
//default constructor
   Creature::Creature() : attack(0), defense(0), armor(0), strength(0)
   {
      //default dice to 2 rolls and 6 sides
      attack_rolls = 2;
      defense_rolls = 2;
      attack_sides = 6;
      defense_sides = 6;
   }

//constructor with parameters for armor and strength
   Creature::Creature(int nArmor, int nStrength)
               : attack(0), defense(0), armor(nArmor), strength(nStrength)
   {
      //default dice to 2 rolls and 6 sides
      attack_rolls = 2;
      defense_rolls = 2;
      attack_sides = 6;
      defense_sides = 6;
   }

//accessor for creature string variable
   std::string Creature::getName()
   {
      return name;
   }

//accessor for creature attack variable
   int Creature::getAttack()
   {
      return attack;
   }

//accessor for creature defense variable
   int Creature::getDefense()
   {
      return defense;
   }

//accessor for creature armor variable
   int Creature::getArmor()
   {
      return armor;
   }
   
//mutator to set creature strength
   void Creature::setStrength(int damage)
   {
      //subtract armor from damage
      damage -= armor;
      if (damage >= 0)
      {
         strength -= damage;
      } //else damage is negative, no effect
   }

//accessor for creature strength value
   int Creature::getStrength()
   {
      return strength;
   }

//roll dice for attack value
   int Creature::rollAttack()
   {
      int roll;

      attack = 0;
      for (int i = 1; i <= attack_rolls; i++)
      {
         //attack = 2;
         roll = rand() % attack_sides + 1;
         attack += roll;
         std::cout << "Roll " << i << ": " << roll;
         if (i < attack_rolls) { std::cout << " ... "; }
      }
      std::cout << std::endl;

      return attack;
   }

//roll dice for defense value
   int Creature::rollDefense()
   {
      int roll;

      defense = 0;
      for (int i = 1; i <= defense_rolls; i++)
      {
         //defense = 2;
         roll = rand() % defense_sides + 1;
         defense += roll;
         std::cout << "Roll " << i << ": " << roll;
         if (i < defense_rolls) { std::cout << " ... "; }
      }
      std::cout << std::endl;

      return defense;
   }

//constructor for goblin, only 1 roll for defense
   goblin::goblin() : Creature(3, 8)   
   {
      name = "Goblin";
      defense_rolls = 1;
   }

//constructor for barbarian
   barbarian::barbarian() : Creature(0, 12)
   {  
      name = "Barbarian";
   }

//constructor for reptile men, 3 rolls for attack and 1 for defense
   reptile::reptile() : Creature(7, 18) 
   {
      name = "Reptile Person";
      attack_rolls = 3;
      defense_rolls = 1;
   }

//constructor for blue men, 10-sided dice for attack and 3 defense rolls
   blueman::blueman() : Creature(3, 12) 
   {  
      name = "Blue Men";
      attack_sides = 10;
      defense_rolls = 3;
   }
}
