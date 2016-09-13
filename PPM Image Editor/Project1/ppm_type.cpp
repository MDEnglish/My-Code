//========================================================
//
//  File Name:  ppm_type.cpp - Definitions for ppm_type class
//
//  Author:  Mason English
//
//  Course and Assignment:  CSCI262 Assignment 1 Image Editor
//
//  Description:  This code creates and edits a ppm.
//
//
//=========================================================

#include <iostream>
#include <fstream>
#include <string>
#include "ppm_type.h"

using namespace std;


// TODO: Finish the load_ppm() method below, and implement all the rest
// of the methods from ppm_type.h

//------------------------------------------------------------------------
// Name: ppm_type::load_ppm()
//
// Description: Load a ppm from a file
//
// Arguments: string filename - file to laod
//
// Modifies: ppm data is initialzed and loaded
// 
// Returns: true for success
//
//--------------------------------------------------------------------
bool ppm_type::load_ppm(string filename)
{
	ifstream infile;   // pointer to input file
	string   magic;    // magic value from file

	// open input filestream
	infile.open(filename);

	// check for errors
	if (infile.fail()) 
	{
		cerr << "Error opening input file '";
		cerr << filename << "', exiting!" << endl;
		return false;
	}

	// read ppm type
	infile >> magic;

	// check for error
	if (magic != "P3") 
	{
		cerr << "Input file '" << filename ;
		cerr << "' appears to not be a PPM, exiting!" << endl;
		infile.close();
		return false;
	}

	// TODO: read # of cols, # of rows, color depth
	
	// TODO: set up data structure for image pixel data, then read in all
	// of the pixel data
	
	// TODO: close the input file
	infile.close();

	// success
	return true;
} 


//------------------------------------------------------------------------
// Name:  ppm_type::not_implemented()
//
// Description: Prints a message for effects not yet implemented
//
// Arguments: none
//
// Modifies: none
// 
// Returns: nothing
//
//--------------------------------------------------------------------
void ppm_type::not_implemented() 
{
	cout << "This method has not yet been implemented." << endl;
}


