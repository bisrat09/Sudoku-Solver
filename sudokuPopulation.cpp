/* sudokuPopulation.cpp
By Bisrat Belayneh
Mar 8,2017
sudokuPopulation.cpp contains the implementations of the functions defined in sudokuPopulation.h
*/
#include <iostream>
#include"sudokuFitness.h"
#include"sudokuPopulation.h"
#include"sudokuFactory.h"
#include"sudokuOffspring.h"
#include <vector>

using namespace std;
//--------------------------------------------------------------------------------------
//constructor
// constructs a an array of soduku puzzles with the specified size 
// and initalizes them to 0.
//takes size of population
sudokuPopulation::sudokuPopulation(int size)
{
	populationSize = size;
	generationCount = 0;
	for (int i = 0; i < populationArray.size(); i++)
	{
		populationArray[i] = 0;
	}
}
//----------------------------------------------------------------------------------------
// destructor
sudokuPopulation::~sudokuPopulation()
{
}
//-----------------------------------------------------------------------------------------
// setup
//kickof populating the populationArray with sudokus from bootsrap
// takes a sudoku pointer and returns nothing

void sudokuPopulation::setup( sudoku* soriginal)
{
	
	sudoku* s;

	for (int i = 0; i < populationSize; i++)
	{
		s = so.bootstrap(soriginal);            // replace the zeros with random integer
		populationArray.push_back(s);           // put the sudoku in to the population array
	}
}
//-----------------------------------------------------------------------------------
//cull
//eliminates the 90% least fit members of a generation
//takes nothing and returns void
// populates the populaton with the top ten percent fit puzzles
void sudokuPopulation::cull()
{
	
	sudoku*s;                // make a soduko object 
	
	topTenArray.clear();      // delete the contents of topTen Array member

	for (int i = 0; i < populationArray.size() / 10; i++)  // iterate through the  one tenth of the population array 
	{
		s = bestIndividual();                  //  store the highest fiteness puzzle  in s
        topTenArray.push_back(s);               // append it to topten array
		for (int j = 0; j < populationArray.size(); j++)  // iterate through the population array 
		{
		
			if (populationArray[j] == s)              // if it has the highest fitness
			{
				populationArray.erase(populationArray.begin() + j);   // remove the rest of the puzzles begining from the highest fitness
				break;     
			}
		}
	}
	
}
//--------------------------------------------------------------------------------------------------
//newGeneration
//produces a new generation with N individuals for every single individual in the old generation
//after the population has been culled.
//takes nothing and returns nothing 
//updates the generation count 
void sudokuPopulation::newGeneration()
{
	//cout << "just started generation" << endl;
	cull();
	populationArray.clear();                           // delete elements of the array                    	
	puzzle* s;                                         // make a new puzzle
	

	while (populationArray.size() < populationSize)    // keep going until populationArray is less than population size
	{
		for (int i = 0; i < topTenArray.size(); i++)    //iterate through the topten array
		{
			s = so.makeOffspring(topTenArray[i]);    // makes children puzzles of the top ten puzzles
			populationArray.push_back(static_cast<sudoku*>(s)); // adds them to the population array
			
		}
	}
	
	generationCount++;                               // update the number of generations 
	
}
//----------------------------------------------------------------------------------------------------
//getGenerationCount 
// getter method for the private generationCount member variable
// takes nothing and returns integer

int sudokuPopulation::getGenerationCount()
{
	
	return generationCount;
}
//-----------------------------------------------------------------------------------------
//bestFitness
//returns the fitness of the best Puzzle in the current generation
//takes nothing and returns integer
int sudokuPopulation::bestFitness()
{
	int FitnessResult = 1000000;
	for (int i = 0; i < populationArray.size(); i++)
	{
		if (populationArray[i]->howFit() < FitnessResult)
		{
			FitnessResult = populationArray[i]->howFit();
			
		}
			
      }
	return FitnessResult;

}
//---------------------------------------------------------------------------------
// bestindividual
// picks up the Puzzle with the highest fitness
// takes nothing and returns the pointer for  most fit sudoku
sudoku* sudokuPopulation:: bestIndividual()
{
	sudoku* p = nullptr;
	int FitnessResult = 1000000;
	for (int i = 0; i < populationArray.size(); i++) 
	{
		if (populationArray[i]->howFit() < FitnessResult)
		{
			FitnessResult = populationArray[i]->howFit();
			p = populationArray[i];
		}

	}
	return p;
}