//========================================================
//
//  File Name:  main.cpp
//
//  Author:Mason English
//
//  Course and Assignment:  CSCI262 Assignment 1 Image Editor
//
//  Description:  This program reads PPM (portable pixmap 
//                images, applies effect filters, and saves
//                the result.
//
//=========================================================

//----- Includes and Namespace ----------

#include <string> 
#include <iostream>
#include <cctype>
#include "ppm_type.h"

using namespace std;

//----------------------------------------------------------------------
//
// Name:  main()
//
// Description: Image editor for ppm_type
//
// Inputs:
//    none
//
// Outputs:
//    returns 0
//
// Assumptions:
//    none
//
//----------------------------------------------------------------------
int main()
{
	cout << "Portable Pixmap (PPM) Image Editor!!" << endl;

	string cmd;  // command string
	ppm_type ppm_obj ;  // the ppm

	// loop through a command loop to load data and edit data
	while (true) // basically, an infinite loop
	{
		// get the command
		cout << endl << "Select command (LOAD, SAVE, NEGATE, FLATTEN, FLIP, GRAY, CONTRAST, QUIT): ";
		getline(cin, cmd);

		// uppercase the command (allowing users to enter in any case)
		for (int i = 0; i < cmd.length(); i++)
		{
			cmd[i] = toupper(cmd[i]);
		}
		

		// load ppm from file
		if (cmd == "LOAD")
		{
			cout << "Enter the name of the PPM file: ";
			getline(cin, cmd);

			if (ppm_obj.load_ppm(cmd))
			{
				cout << "PPM successfully loaded." << endl;
			}
			else
			{
				cout << "PPM failed to load." << endl ;
			}
		}  // end if

		// save ppm to file 
		if (cmd == "SAVE")
		{
// TODO: get rid of not_implemented call and uncomment code below when 
// your save method is finished
			ppm_obj.not_implemented();
/*
			cout << "Enter the name of the PPM file: ";
			getline(cin, cmd);

			if (ppm_obj.save_ppm(cmd))
			{
				cout << "PPM successfully saved." << endl;
			}
			else
			{
				cout << "PPM failed to save." << endl ;
			}
*/
		}  // end if

		if (cmd == "NEGATE")
		{
// TODO: get rid of not_implemented call and uncomment code below when 
// your negate methods are finished
			ppm_obj.not_implemented();
/*
			cout << "Enter the color to negate (R,G,B): ";
			getline(cin, cmd);

			if (cmd == "R" || cmd == "r")
			{
				ppm_obj.negate_red();
				cout << "Red was negated." << endl;
			}
			else if (cmd == "G" || cmd == "g")
			{
				ppm_obj.negate_green();
				cout << "Green was negated." << endl;
			}
			else if (cmd == "B" || cmd == "b")
			{
				ppm_obj.negate_blue();
				cout << "Blue was negated." << endl;
			}
			else
			{
				cout << "Invalid color selection." << endl;
			}
*/
		}  // end if		

		if (cmd == "FLATTEN")
		{
// TODO: get rid of not_implemented call and uncomment code below when 
// your flatten methods are finished
			ppm_obj.not_implemented();
/*
			cout << "Enter the color to flatten (R,G,B): ";
			getline(cin, cmd);

			if (cmd == "R" || cmd == "r")
			{
				ppm_obj.flatten_red();
				cout << "Red was flattened." << endl;
			}
			else if (cmd == "G" || cmd == "g")
			{
				ppm_obj.flatten_green();
				cout << "Green was flattened." << endl;
			}
			else if (cmd == "B" || cmd == "b")
			{
				ppm_obj.flatten_blue();
				cout << "Blue was flattened." << endl;
			}
			else
			{
				cout << "Invalid color selection." << endl;
			}
*/
		}  // end if		
		
		// flip the image horizontally
		if (cmd == "FLIP")
		{
// TODO: get rid of not_implemented call and uncomment code below when 
// your flip method is finished
			ppm_obj.not_implemented();
/*
			ppm_obj.flip();
			cout << "Image was flipped." << endl;
*/
		}  // end if	
		   
		// gray scale the image
		if (cmd == "GRAY")
		{
// TODO: get rid of not_implemented call and uncomment code below when 
// your gray method is finished
			ppm_obj.not_implemented();
/*
			ppm_obj.gray();
			cout << "Image was gray scaled." << endl;
*/
		}  // end if	

		if (cmd == "CONTRAST")
		{
// TODO: get rid of not_implemented call and uncomment code below when 
// your flip method is finished
			ppm_obj.not_implemented();
/*
			ppm_obj.contrast();
			cout << "Image was set to extreme contrast." << endl;
*/
		}  // end if	

		// quit the program
		if (cmd == "QUIT")
		{
			break;  // exit the loop
		}
		
	}  // end do

	return 0;
} // end main
