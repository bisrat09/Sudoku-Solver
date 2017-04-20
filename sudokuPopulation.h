
/* sudokupopulation.h
By Bisrat Belayneh
Mar 8,2017
sudokuPopulation.h contains the definitions of the functions implemented in sudokuPopulation.cpp
*/
#pragma once
#include <iostream>
#include"population.h"
#include "puzzle.h"
#include"reproduction.h"
#include"puzzleFactory.h"
#include <vector>
#include"sudokuOffspring.h"
using namespace std;

class sudokuPopulation : public population
{

public:
	//--------------------------------------------------------------------------------------
	//constructor
	// constructs a an array of soduku puzzles with the specified size 
	// and initalizes them to 0.
	//takes size of population
	sudokuPopulation(int);
	//----------------------------------------------------------------------------------------
	// destructor
	~sudokuPopulation();
	//-----------------------------------------------------------------------------------
	//cull
	//eliminates the 90% least fit members of a generation
	//takes nothing and returns void
	// populates the populaton with the top ten percent fit puzzles
	void cull();
	//--------------------------------------------------------------------------------------------------
	//newGeneration
	//produces a new generation with N individuals for every single individual in the old generation
	//after the population has been culled.
	//takes nothing and returns nothing 
	//updates the generation count 
	void newGeneration();
	//-----------------------------------------------------------------------------------------
	//bestFitness
	//returns the fitness of the best Puzzle in the current generation
	//takes nothing and returns integer
	int bestFitness();
	//---------------------------------------------------------------------------------
	// bestindividual
	// picks up the Puzzle with the highest fitness
	// takes nothing and returns the pointer for  most fit sudoku
	sudoku* bestIndividual();
	//----------------------------------------------------------------------------------------------------
	//getGenerationCount 
	// getter method for the private generationCount member variable
	// takes nothing and returns integer
	int getGenerationCount();
	//-----------------------------------------------------------------------------------------
	// setup
	//kickof populating the populationArray with sudokus from bootsrap function
	// takes a sudoku pointer and returns nothing

	void setup(sudoku*);
private:
 	vector<sudoku*> populationArray;         // private population made up of an array of sudokus 

	sudokuOffspring so;						// private offspring member variable used to make baby sudokus
	int populationSize;						//member to hold the size of population
	int generationCount;                    // holds the number of generations in the population
	vector<sudoku*> topTenArray;            // am array to hold the top ten percent of the population interms of fitness
	sudoku* originalSudoku;					// pointer to the first sudoku puzzle for the population
};