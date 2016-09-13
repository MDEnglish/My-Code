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
//  Collaborators: Colin Munroe, Austin Uhing, Kyle Voris, Christopher Painter-Wakefield
//
//=========================================================

//----- Includes and Namespace ----------

#include <string> 
#include <iostream>
#include <cctype>
#include "ppm_type.h"
#include <vector>

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
    ppm_type ppm_obj;  // the ppm


                       // loop through a command loop to load data and edit data
    while (true) // basically, an infinite loop
    {
        // get the command
        cout << endl << "Select command (LOAD, SAVE, NEGATE, FLATTEN, FLIP, GRAY, CONTRAST, VERTICAL QUIT): ";

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
                cout << "PPM failed to load." << endl;
                return 1;
            }
        }  // end if

           // save ppm to file 
        if (cmd == "SAVE")
        {
            string ppm_name;

            cout << "Enter the name of the new PPM file: ";
            getline(cin, ppm_name);
            ppm_obj.save_ppm(ppm_name);

        }
        if (cmd == "NEGATE")
        {


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

        }  // end if		

        if (cmd == "FLATTEN")
        {



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

        }  // end if		

           // flip the image horizontally
        if (cmd == "FLIP")
        {



            ppm_obj.flipHorozontal();
            cout << "Image was flipped." << endl;

        }  // end if	

        if (cmd == "VERTICAL")
        {



            ppm_obj.flipVertical();
            cout << "Image was flipped." << endl;

        }  // end if

           // gray scale the image
        if (cmd == "GRAY")
        {
            ppm_obj.grayscale();
            cout << "Image was gray scaled." << endl;

        }  // end if	

        if (cmd == "CONTRAST")
        {

            ppm_obj.contrast();
            cout << "Image was set to extreme contrast." << endl;

        }  // end if	

           // quit the program
        if (cmd == "QUIT")
        {
            break;  // exit the loop
        }

    }  // end do

    return 0;

}// end main
