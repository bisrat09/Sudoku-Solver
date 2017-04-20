
/* sudokuOffspring.cpp
By Bisrat Belayneh
Mar 8,2017
sudokuOffspring.cpp contains the implementations of the functions defined in sudokuOffspring.h
*/
#include <iostream>
#include "sudoku.h"
#include "puzzle.h"
#include "sudokuOffspring.h"
#include <cstdlib>
using namespace std;

//---------------------------------------------------------------------------------------------
// makeOffspring
// makes new puzzles from old ones 
// uses genetic opreration called mutation
// makes a copy of the original sudoku with the probability of 
// 5% changing each variable number in the puzzle as it is copied 
// takes puzzle pointer and returns a puzzle pointer

puzzle* sudokuOffspring::makeOffspring( puzzle* p )
{

	//const puzzle* pp = &p;
	const sudoku* s = static_cast<const sudoku*>(p);
	
	//sudoku retval;
	puzzle* p2 = &(sf.createPuzzle());
	sudoku *retval = static_cast<sudoku*>(p2);
	//cout << " s from makeOffspring = " << endl << s << endl;

	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			retval->isFixed[i][j] = s->isFixed[i][j];  // copy the fixed cells
			if (rand() % 20 == 0 && !s->isFixed[i][j])  // change variable cell if it is in the 5%
			{
				//cout << "random nhmber" << endl;
				retval->grid[i][j] = 1 + rand() % 9;
			}
			else
			{
				retval->grid[i][j] = s->grid[i][j];  /// copy the rest of the cells as they are
			}
		}
	}
	retval->howFit();
	return retval;
}
//-----------------------------------------------------------------------------------------------
//bootsrap
// takes an orignal sudoku ,replaces its zeros with random numbers from 1-9
//takes a soduku puzzle and returns a new soduku

sudoku* sudokuOffspring::bootstrap(sudoku* s )
{
	puzzle* p2 = &(sf.createPuzzle());             // create a puzzle using factory
	sudoku* retval = static_cast<sudoku*>(p2);  // casts it in to a soduku

	for (int i = 0; i < 9; i++)           // iterate through the sudoku elements
	{
		for (int j = 0; j < 9; j++)
		{
			retval->isFixed[i][j] = s->isFixed[i][j];  // copy the fixed cells
			if (s->grid[i][j] == 0)
			{
				retval->grid[i][j] = 1 + rand() % 9;    // cell is zero replace it with a random int
			}
			else
			{
				retval->grid[i][j] = s->grid[i][j];       //  cell is not zero, copy as is
			}
		}
	}

	return retval;
}