/* sudokuFitness.cpp
By Bisrat Belayneh
Mar 8,2017
sudokuFitness.cpp contains the implementations of the functions defined in sudokuFitness.h
*/
#include <iostream>
#include "puzzle.h"
#include "sudoku.h"
#include "sudokuFitness.h"
using namespace std;
//------------------------------------------------------------------------------------
//howfit:
//takes puzzle object and returns integer 
// count the total number of conflicts in a puzzle: how many duplicate entries
//there are in each row, column, and 3-by-3 block.

int sudokuFitness::howFit(const puzzle &p)
{
	const puzzle* pp = &p;                                 // copy the puzzle in to a pointer 
	const sudoku& s = *(static_cast<const sudoku*>(pp));   // type cast it to sudoku refernce object

	int fitnessNumber = 0;                               
	fitnessNumber += checkRowDuplicates(s);                // count duplictes from the row and update fitness

	fitnessNumber += checkcolumnDuplicates(s);				// count duplictes from the column and update fitness

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			fitnessNumber += checkBoxduplicates(i, j, s);  // for every 3x3 grid count duplictes and update fitness 
		}
	}

	return fitnessNumber;
}
//----------------------------------------------------------------------------------------------------
// checkRowDuplicates 
// counts the number of duplicate entries in each row of sudoku and update the fitness number
//takes a sudoku puzzle and returns an integer
int sudokuFitness::checkRowDuplicates(const sudoku &s)
{
	int fitnessNumber = 0;
	// check duplictes in every row 0-8
	int row = 0;

	while (row < 9)                                     // process row one by one 
	{
		for (int column = 0; column < 9; column++)     // iterate through the column 
		{
			for (int i = column + 1; i < 9; i++)
			{
				if (s.grid[row][i] == s.grid[row][column])       ///found a duplicate update fitnessnumber 
				{
					fitnessNumber++;
				}
			}
		}
		row++;
	}
	return fitnessNumber;
}

//-------------------------------------------------------------------------------------------------------------
//checkcolumnDuplicates
// check for duplicates in every column of sudoku and update the fitness number
//takes a sudoku and returns integer
int sudokuFitness::checkcolumnDuplicates(const sudoku &s)
{
	int fitnessNumber = 0;
	int column = 0;
	while (column < 9)                              // process column one by one 
	{
		for (int row = 0; row < 9; row++)			// iterate through each row 
		{
			for (int i = row + 1; i < 9; i++)       
			{
				if (s.grid[i][column] == s.grid[row][column])   // found a duplicate update fitnessnumber 
				{
					fitnessNumber++;
				}
			}
		}
		column++;
	}
	return fitnessNumber;

}


//----------------------------------------------------------------------------------------------------------------
//checkBoxduplicates
// check duplicates in 3X3 grids of sudoku and updates the fitness number 
// takes sudoku , x and y coordinates of a 3X3 grid and returns integer 
int sudokuFitness::checkBoxduplicates(int coordinateX, int coordinateY, const sudoku & s)
{

	int temp[9];
	int k = 0;
	int fitnessNumber = 0;

	int startx = 3 * coordinateX;
	int starty = 3 * coordinateY;

		for (int row = 0; row < 3; row++)                             // iterate through every element of a 3x3 grid
		{
			for (int column = 0; column < 3; column++)
			{
				temp[k] = s.grid[startx + row][starty + column];   // copy elements of a 3X3 to temp
				k++;
			}

		}
			// check for duplictes in the temp array
	for (int i = 0; i < 9; i++)     // iterate through the column 
			{
				for (int j = i + 1; j < 9; j++)
				{
					if (temp[i] == temp[j])       //found a duplicate update fitnessnumber 
					{
						fitnessNumber++;
					}
				}
			}

		
	
	return fitnessNumber;
}



	
		
