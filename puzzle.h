/* puzzle.h
By Bisrat Belayneh
March 8, 2017
puzzle.h contains the class definition for vitrual method helperStream input.
*/
//The Puzzle class defines the abstract interface for any puzzle to be used by the GA framework
#pragma once
#include<iostream>
using namespace std;

class puzzle
{
	friend istream& operator>>(istream&, puzzle &p);
	friend ostream& operator<<(ostream&, puzzle &p);
public:
	
	puzzle(){} // constructor
	~puzzle(){} // destructor 
	//-------------------------------------------------------------------------------------
	// helperStreamInput 
	//reads the input stream of integers as characters 
	// marks them as fixed and variable ,converts back to ints and fills up the grid
	//takes istream input and returns nothing
		
		virtual void helperStreamInput(istream&) = 0;
		

};