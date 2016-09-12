//========================================================
//
//  File Name:  ppm_type.h
//
//  Author:  
//
//  Course and Assignment:  CSCI262 Assignment 1 Image Editor
//
//  Description:  Header for the ppm_type object
//
//=========================================================
#pragma once

#include <string.h> 
using namespace std;


//----------------------------------------------------------------------
//
// Object ppm_type
//
// Description: Class to hold and manipulate a ppm
//
//----------------------------------------------------------------------
class ppm_type
{
public:

// TODO: implement constructor and destructor, if needed, to initialize
// and clean up any storage used by your class

	bool load_ppm(string file);  // load a ppm from a file
// TODO: implement save method below
//	bool save_ppm(string file);  // save a ppm to a file

// TODO: implement public methods below for each image effect
//	void negate_red();
//  etc.

// TODO: get rid of method below once no longer needed.
	void not_implemented();

private:
// TODO: add in variables to store # of rows, # of columns, color depth,
// and the image data (see project 1 write up for hints).  You may also
// add in any private methods needed for your program.

};
