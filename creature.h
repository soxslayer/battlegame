/***********************************************************
 * Author:			   Ian Bender
 * Date Created:     8/1/2014		
 * Last Modified:    8/3/2014	
 * Description:      Assignment 3
 * Filename:		   Creature.h
 *
 * Overview: Interface for Creature class.
 **********************************************************/	

#ifndef CREATURE_H
#define CREATURE_H

namespace Bender
{
   //parent Creature class
   class Creature 
   {
   public:
   //constructors
      Creature();
      Creature(int nArmor, int nStrength);
   //accessors
      std::string getName();
      int getAttack();
      int getDefense();
      int getArmor();
      int getStrength();
   //mutator for strength
      void setStrength(int damage);
   //functions for dice rolls
      int rollAttack();
      int rollDefense();

   protected:
      std::string name;
      int attack;
      int defense;
      int armor;
      int strength;
      int attack_rolls, defense_rolls; //number of dice rolls
      int attack_sides, defense_sides; //number of dice sides
   };

   //derived goblin class
   class goblin : public Creature
   {
   public:
      goblin();
   };

   //derived barbarian class
   class barbarian : public Creature
   {
   public:
      barbarian();
   };

   //derived reptile people class
   class reptile : public Creature
   {
   public:
      reptile();
   };

   //derived blue men class
   class blueman : public Creature
   {
   public:
      blueman();
   };
}

#endif

