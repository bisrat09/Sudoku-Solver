/* sudoku.h
By Bisrat Belayneh
Mar 8,2017
sudoku.h contains the class definitions  of the functions implemented in sudoku.cpp
*/
#pragma once
#include<iostream>
#include"puzzle.h"
#include"string"
#include"sudokuFitness.h"


class sudoku : public puzzle
{ 
	//----------------------------------------------------------------------
	// operator>>
	// stream input operator that reads a sequence of 81 integers from user 
	//makes use of helperStreaminput helper method
	// takes istream and sudoku and returns istream 
	friend istream& operator>>(istream&, sudoku &p);
	//-----------------------------------------------------------------------------
	//operator<<
	//stream output  operator that prints the sudoku puzzle as a formatted text
	// takes ostream object and sudoku object  and returns ostream 
	//makes use of a helper method called helperstreamOutput
	friend ostream& operator<<(ostream&, const sudoku &p);

	friend class sudokuOffspring;   // so that we can use private members of sudokuOffspring.h
	friend class sudokuFitness;     // so that we can use private members of sudokuOffspring.h

public:
	//---------------------------------------------------------------------------------------------------
	//constructor 
	// makes a soduku puzzle setting all elements 0
	// obtains the fitness of the the sudoku puzzle from fitness.cpp 
	// sets the member variable array isFixed to false
	sudoku();
	//------------------------------------------------------------------------
	//destructor
	//frees the memory used by grid and isFixed arrays after use
	~sudoku();
	
	//-------------------------------------------------------------------------------------
	// helperStreamInput 
	//reads the input stream of integers as characters 
	// marks them as fixed and variable ,converts back to ints and fills up the grid
	//takes istream input and returns nothing

    void helperStreamInput(istream&) ;
	//------------------------------------------------------------------------------------
	//helperStreamOutput
	//prints out a formatted sudoku puzzle with 81 integers
	//takes nothing and returns a string representation of the sudoku
	
	string helperStreamOutput() const;
	//----------------------------------------------------------------------------------------
	// howfit
	//gets the fitness of this sudoku from howFit function in fitness class
	//takes nothing and returns integer

	int howFit();
	//------------------------------------------------------------------------------------
	// 2 dimensional array pointer member variable to store fixed/varable state
	bool **isFixed;
	

private :
	int **grid;     // 2 dimensional array pointer member variable to store soduku digits

	int fitnessScore; // to store the fitess of each sudoku
	sudokuFitness fitnessObject; // to communicate with sudokuFitness to get fitnesses

};