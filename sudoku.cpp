/* sudoku.cpp
By Bisrat Belayneh
Mar 8,2017
sudoku.cpp contains the implementations of the functions defined in sudoku.h
*/

#include<iostream>
#include"sudoku.h"
#include<fstream>
#include<istream>
#include<ostream>
#include"string"
#include <stdio.h>
#include"vector"
#include "sudokuFitness.h"

using namespace std;

//---------------------------------------------------------------------------------------------------
//constructor 
// makes a soduku puzzle setting all elements 0
// obtains the fitness of the the sudoku puzzle from fitness.cpp 
// sets the member variable array isFixed to false
sudoku::sudoku()

{
	grid = new int*[9];                             // make a new grid array
	isFixed = new bool*[9];							// make a new grid array

	for (int i = 0; i < 9; i++)						// make it a two dimensional array
	{
		grid[i] = new int[9];
		isFixed[i] = new bool[9];

		for (int j = 0; j < 9; j++)            // set all grid elements to zero
		{
			grid[i][j] = 0;                    
			isFixed[i][j] = false;             // set all isFixed to false 
		}
	}
	fitnessScore = fitnessObject.howFit(*this);    // get the fitness of this sudoku 
}
//------------------------------------------------------------------------
//destructor
//frees the memory used by grid and isFixed arrays after use

sudoku::~sudoku()
{
	for (int i = 0; i < 9; i++)    // iterate through the grid and IsFixed array
	{
		delete[] grid[i];           // free up the memory
		delete[] isFixed[i];
	}

	delete[] grid;					 // free up the memory
	delete[] isFixed;
	
}
//----------------------------------------------------------------------
// operator>>
// stream input operator that reads a sequence of 81 integers from user 
//makes use of helperStreaminput helper method
// takes istream and sudoku and returns istream 
istream& operator>>(istream& in, sudoku &input)
{
	input.helperStreamInput(in);        // read stream and put it in input using helper 
	return in;
}
//-----------------------------------------------------------------------------
//operator<<
//stream output  operator that prints the sudoku puzzle as a formatted text
// takes ostream object and sudoku object  and returns ostream 
//makes use of a helper method called helperstreamOutput
ostream& operator<<(ostream& out, const sudoku &p)
{
	 
	out << p.helperStreamOutput();    // print the sudoku puzzle using helper method
	return out;
}
//-------------------------------------------------------------------------------------
// helperStreamInput 
//reads the input stream of integers as characters 
// marks them as fixed and variable ,converts back to ints and fills up the grid
//takes istream input and returns nothing
void sudoku::helperStreamInput(istream& in)
{

	int column = 0;
	int row = 0;
	char c;
	
	while (in.get(c) && row < 9)

	{                                            // as long as there is input and not read past the end of a row 
		if (c <= '9' && c >= '0')
		{
			if (c == '0')
			{
				isFixed[column][row] = false ;     //  input is 0, mark it as variable 
			}
			else
			{
				isFixed[column][row] = true;   /// input is not zero ,mark fixed cells
			}
			grid[column][row] = (c - '0');      // convert back to int and store it in the grid
			column++;
			if (column > 8)
			{
				column = 0;
				row++;
			}

		}
	}

	fitnessScore = fitnessObject.howFit(*this);  // get the fitness of this puzzle 

}
//------------------------------------------------------------------------------------
//helperStreamOutput
//prints out a formatted sudoku puzzle with 81 integers
//takes nothing and returns a string representation of the sudoku

string sudoku::helperStreamOutput() const

{
	string retval ;                                //  declare string object to return 
	retval += "+-------+-------+-------+\n";    // print upper boarder of the table 
	for (int i = 0; i < 9; i++)
	{
		if (i == 3|| i == 6)
		{
			retval += "+-------+-------+-------+\n";   // place inner  horizontal separators
		}
		retval += "| ";
		for (int j = 0; j < 9; j++)
		{
			char c = grid[j][i] + '0';				// change grid ints to chars 
			retval.push_back(c);                   // add them to string object 
				retval += " ";
		
			if ( j == 2 || j == 5|| j == 8)        // place vertical  separators for the grid 
			{
				retval += "| ";

			}
			
		}
		retval += "\n";

	}
	retval += "+-------+-------+-------+\n";			//// print lower boarder of the table 
	return retval;
}
// howfit
//gets the fitness of this sudoku from howFit function in fitness class
//takes nothing and returns integer
int sudoku::howFit()
{
	fitnessScore = fitnessObject.howFit(*this);     // get the fitness of this sudoku.
	return fitnessScore;
}