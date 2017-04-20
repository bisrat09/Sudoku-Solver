/* sudokuFactory.h
By Bisrat Belayneh
Mar 8,2017
sudokuFactory.h contains the class definitions  of the functions implemented in sudokuFactory.cpp
*/
#pragma once
#include<iostream>
#include"puzzleFactory.h"
#include "vector"
using namespace std;

class sudokuFactory : public puzzleFactory

{

public:
	//---------------------------------------------------------------------------------
	//createpuzzle
	//when provided at construction time with a sudokuOffspring object,
	//it uses this object to create new instances of sudoku 
	//takes nothing and returns a puzzle 

	puzzle& createPuzzle();
	//---------------------------------------------------------------------------------
	// destructor 
	//frees the memory used by list by deleting the contents of the list 
	
	~sudokuFactory();  

	vector<puzzle*> list;    // a list of puzzle pointers to store sudokus as created


};