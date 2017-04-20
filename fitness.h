/* 
By Bisrat Belayneh
March 8,2017
finess.h contains the definition for howFit method
*/
#pragma once

#include <iostream>
#include "puzzle.h"
using namespace std;

// Fitness class
// Abstract class for evaluating the fitness of individual puzzles
// fitnesss and its subclass soduku fitness are implimented using strategy design pattern
class fitness
{
public:
//------------------------------------------------------------------------------------
//howfit:
//takes puzzle object and returns integer
// count the total number of conflicts in a puzzle: how many duplicate entries
//there are in each row, column, and 3-by-3 block.

	virtual int howFit(const puzzle&) = 0;    
};

// end fitness.h