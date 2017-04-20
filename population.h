
/* population.h
By Bisrat Belayneh
March 8, 2017
population.h contains the class definition for vitrual method cull.
*/
#pragma once
#include<iostream>
#include"vector"
using namespace std;

// popluation is an abstract class that contains a number of puzzles
//it uses fitness strategy to evaluate the fitness of a puzzzle
class population
{
public :
	// constructor
	population(){}
	// destructor
	~population(){}
	int size;   // member variable to hold population size
	int maxGeneration; // member variale to hold maximum generations input by user
	//-----------------------------------------------------------------------------------
	//cull
	//eliminates the 90% least fit members of a generation
	//takes nothing and returns void
	// populates the populaton with the top ten percent fit puzzles
	virtual void cull() = 0;
private:
	int* puzzleFactoryPtr;   //  member variable to hold a reference to puzzle factory  object
	int *fitnessPtr;         // member variable to hold a reference to fitness object

};