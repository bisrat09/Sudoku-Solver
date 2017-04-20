/* reproduction.h
By Bisrat Belayneh
March 8, 2017

reproduction.h contains the class definition for vitrual method makeoffspring().
*/
#pragma once
#include<iostream>
#include"puzzle.h"
#include "sudoku.h"
using namespace std;
/*Reproduction is used by PuzzleFactory to create new Puzzles from old ones.
Reproduction and its subclasses are also implementations of the strategy design pattern. 
Reproduction subclasses must implement a "makeOffspring" method, 
which takes a Puzzle and returns a new Puzzle.*/
class reproduction
{
public :
	virtual puzzle* makeOffspring(puzzle*) = 0;

private:

};