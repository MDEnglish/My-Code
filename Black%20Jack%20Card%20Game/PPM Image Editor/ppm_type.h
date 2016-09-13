//========================================================
//
//  File Name:  ppm_type.h
//
//  Author:  Mason English
//
//  Course and Assignment:  CSCI262 Assignment 1 Image Editor
//
//  Description:  Header for the ppm_type object
//
//=========================================================
#pragma once
#include <fstream>
#include <string.h>
#include <vector>

using namespace std;

struct pixel {
    int red = 0;
    int green = 0;
    int blue = 0;
};


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

    ppm_type();

    vector<vector<pixel>> image;


    bool load_ppm(string file);  // load a ppm from a file
    bool save_ppm(string file);  // save a ppm to a file
    void negate_red();
    void negate_green();
    void negate_blue();
    void flatten_red();
    void flatten_green();
    void flatten_blue();
    void flipHorozontal();
    void grayscale();
    void contrast();
    void flipVertical();



private:

    int columns;
    int rows;
    int max;
    string magic;

};
