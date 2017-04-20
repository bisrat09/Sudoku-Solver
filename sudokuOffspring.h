/* sudoku.h
By Bisrat Belayneh
Mar 8,2017
sudokuOffspring.h contains the class definitions  of the functions implemented in sudokuOffspring.cpp
*/
#pragma once
#include<iostream>
#include"reproduction.h"
#include "sudoku.h"
#include "sudokuFactory.h"
using namespace std;

class sudokuOffspring : public reproduction
{

	
public:
	//---------------------------------------------------------------------------------------------
	// makeOffspring
	// makes new puzzles from old ones 
	// uses genetic opreration called mutation
	// makes a copy of the original sudoku with the probability of 
	// 5% changing each variable number in the puzzle as it is copied 
	// takes puzzle pointer and returns a puzzle pointer

	puzzle* makeOffspring(puzzle*);
	//-----------------------------------------------------------------------------------------------
	//bootsrap
	// takes an orignal sudoku ,replaces its zeros with random numbers from 1-9
	//takes a soduku puzzle and returns a new soduku
	sudoku* bootstrap(sudoku*);
private :
	sudokuFactory sf;     // private member sudokuFactory  object to make offsprings

};