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
#include <fstream>
#include <string>
#include "ppm_type.h"

using namespace std;



void negate_red() {


}




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

ppm_type::ppm_type() {
}

bool ppm_type::load_ppm(string filename)
{
    ifstream infile;   // pointer to input file


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
        cerr << "Input file '" << filename;
        cerr << "' appears to not be a PPM, exiting!" << endl;
        infile.close();
        return false;
    }

    infile >> columns;
    infile >> rows;
    infile >> max;

    image.resize(columns);

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            pixel temp;

            infile >> temp.red;;
            infile >> temp.green;
            infile >> temp.blue;

            image.at(j).push_back(temp);
        }
    }

    infile.close();

    // success
    return true;
}

bool ppm_type::save_ppm(string file) {
    ofstream save;

    save.open(file);

    save << magic << endl << columns << " " << rows << endl << max << endl;


    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            save << image.at(j).at(i).red;
            save << " ";
            save << image.at(j).at(i).green;
            save << " ";
            save << image.at(j).at(i).blue;
            save << " ";
        }
    }

    return true;
}
//inverts red value
void ppm_type::negate_red() {
    for (int i = 0; i < columns; i++) {
        for (int j = 0; j < rows; j++) {
            image.at(i).at(j).red = max - image.at(i).at(j).red;
        }
    }
    return;
}
//inverts green value
void ppm_type::negate_green() {
    for (int i = 0; i < columns; i++) {
        for (int j = 0; j < rows; j++) {
            image.at(i).at(j).green = max - image.at(i).at(j).green;
        }
    }

    return;
}
//inverts blue value
void ppm_type::negate_blue() {
    for (int i = 0; i < columns; i++) {
        for (int j = 0; j < rows; j++) {
            image.at(i).at(j).blue = max - image.at(i).at(j).blue;
        }
    }

    return;
}
//sets red value to zero 
void ppm_type::flatten_red() {
    for (int i = 0; i < columns; i++) {
        for (int j = 0; j < rows; j++) {
            image.at(i).at(j).red = 0;
        }
    }
    return;
}
//sets green value to zero 
void ppm_type::flatten_green() {
    for (int i = 0; i < columns; i++) {
        for (int j = 0; j < rows; j++) {
            image.at(i).at(j).green = 0;
        }
    }

    return;
}

//sets blue value to zero 
void ppm_type::flatten_blue() {
    for (int i = 0; i < columns; i++) {
        for (int j = 0; j < rows; j++) {
            image.at(i).at(j).blue = 0;
        }
    }
    return;
}

//flips the image horozontally
void ppm_type::flipHorozontal() {

    pixel placeholder;
    for (int j = 0; j < rows; j++) {
        for (int i = 0; i < columns / 2; i++) {
            placeholder = image.at(i).at(j);
            image.at(i).at(j) = image.at(columns - 1 - i).at(j);
            image.at(columns - 1 - i).at(j) = placeholder;
        }
    }

    return;

}

void ppm_type::flipVertical() {

    pixel placeholder;
    for (int j = 0; j < rows / 2; j++) {
        for (int i = 0; i < columns; i++) {
            placeholder = image.at(i).at(j);
            image.at(i).at(j) = image.at(i).at(rows - 1 - j);
            image.at(i).at(rows - 1 - j) = placeholder;
        }
    }

    return;
}
//sets all colors to the average of origional color values
void ppm_type::grayscale() {
    int avg;
    for (int i = 0; i < columns; i++) {
        for (int j = 0; j < rows; j++) {
            avg = (image.at(i).at(j).red + image.at(i).at(j).green + image.at(i).at(j).blue) / 3;
            image.at(i).at(j).red = avg;
            image.at(i).at(j).green = avg;
            image.at(i).at(j).blue = avg;
        }
    }
    return;
}

//sets values to max if over 1/2 of max possible value, otherwise sets to 0
void ppm_type::contrast() {
    int midpoint = max / 2;

    for (int i = 0; i < columns; i++) {
        for (int j = 0; j < rows; j++) {



            image.at(i).at(j).blue = 0;

            if (image.at(i).at(j).red > midpoint) {
                image.at(i).at(j).red = max;
            }
            else {
                image.at(i).at(j).red = 0;
            }

            if (image.at(i).at(j).green > midpoint) {
                image.at(i).at(j).green = max;
            }
            else {
                image.at(i).at(j).green = 0;
            }

            if (image.at(i).at(j).blue > midpoint) {
                image.at(i).at(j).blue = max;
            }
            else {
                image.at(i).at(j).blue = 0;
            }
        }
    }

    return;
}