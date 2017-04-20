/* sudoku.h
By Bisrat Belayneh
Mar 8,2017
sudokuFitness.h contains the class definitions of the functions implemented in sudokuFitness.cpp
*/
#pragma once
#include<iostream>
#include "fitness.h"
#include "puzzle.h"
//#include"sudoku.h"
using namespace std;

class sudoku;                                 // forward declare sudoku to use it later 

class sudokuFitness : public fitness
{
public:
	//------------------------------------------------------------------------------------
	//howfit:
	// count the total number of conflicts in a puzzle: how many duplicate entries
	//there are in each row, column, and 3-by-3 block.
	int howFit(const puzzle&);

	//----------------------------------------------------------------------------------------------------
	// checkRowDuplicates 
	// counts the number of duplicate entries in each row of sudoku and update the fitness number
	//takes a sudoku puzzle and returns an integer

	int checkRowDuplicates(const sudoku &s);
	//-------------------------------------------------------------------------------------------------------------
	//checkcolumnDuplicates
	// check for duplicates in every column of sudoku and update the fitness number
	//takes a sudoku and returns integer
	int checkcolumnDuplicates(const sudoku &s);
	//----------------------------------------------------------------------------------------------------------------
	//checkBoxduplicates
	// check duplicates in 3X3 grids of sudoku and updates the fitness number 
	// takes sudoku , x and y coordinates of a 3X3 grid and returns integer 
	int checkBoxduplicates(int , int , const sudoku & s);
	

};