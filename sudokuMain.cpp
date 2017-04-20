
/* sudokuMain.cpp
By Bisrat Belayneh
Mar 8,2017
purpose: contains main() ,its the driver of the program ,
takes input from cin and prints out the output to cout.
implements  genetic Algorithm creates soduko population sets off the iterations 
*/

#include <iostream>
#include <cstdlib>
#include"sudoku.h"
#include"string"
#include "sudokuFitness.h"
#include "sudokuOffspring.h"
#include "sudokuPopulation.h"
using namespace std;
//-------------------------------------------------------------------------------------------------------------------------
/*

The purpose of this sudoku solver program is to make use of abstract factory and 
strategy O-O design patterns to  implement a set of classes that define the abstractions 
necessary to solve any kind of puzzle in general, and produce concrete subclasses that implement
these interfaces to solve a sudoku puzzle in particular.
the program also uses randomized algorithm called Genetic Algorithm(GA).  


Implementation and assumptions :
--the user will input population size and the maxmimum generation from console
--the user will type 81 digits as an input for the original sudoku to be solved
--Asks the Population for the bestFitness, halting iterations if a solution has been found 
	or if the maximum number of generations limit has been reached,
	command the Population to cull 90\% of its Puzzles,
	and command the Population to reproduce a newGeneration.

INPUT :The  program takes  two command line arguments: the size of the population and the maximum number of generations.
       It also reads the sudoku puzzle from cin in a compact text format. The format consists of a sequence of 81 integers,
	   as ASCII text, each corresponding to the contents of one square in the puzzle grid, in row-major order
	   (i.e., starting at the upper left corner, reading across each row and then continuing with the next row, 
	   ending at the bottom right corner)

OUTPUT : The program outputs the best puzzle found with its fitness value in the following format to cout.
				Fitness Value of the best puzzle : X
*/



int main(int argc, char* argv[])
{
	string text = "";
	int populationSize = atoi(argv[1]);     // change integer to char to recieve command line inputs 
	int MaxGeneration = atoi(argv[2]);       //change integer to char to recieve command line inputs 

	sudoku s1;                            // make a new sudoku puzzle 
	sudokuFitness sf;                     // make a fitness object 
	sudokuOffspring so;                   // make an offspring object


	cin >> s1;                          // read input from console to s1

	sudokuPopulation sp(populationSize);   // make a population of size populationSize;
	sp.setup(&s1);                              // takes puzzle  and make copies with  
// genetic algorithm 
//*ask the Population for the bestFitness, halting iterations if a solution has been found 
// or if the maximum number of generations limit has been reached,
// command the Population to cull 90\% of its Puzzles, and
//command the Population to reproduce a newGeneration.
	while (sp.bestFitness() != 0 && sp.getGenerationCount() != MaxGeneration)   // until fitness is zero or excedded max generation 
	{
		sp.newGeneration();     // make a new generation
		MaxGeneration++;        // update counter

    }
	
	cout << *(sp.bestIndividual());      // print out the best sudoku puzzle from the population
	cout << " fitness value of best puzzle " << sp.bestFitness() << endl; // print its fitness

	return 0;
}