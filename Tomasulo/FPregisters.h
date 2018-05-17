/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   FPregisters.h
 * Author: leo
 *
 * Created on 16 de mayo de 2018, 20:27
 */

#ifndef FPREGISTERS_H
#define FPREGISTERS_H

#include <string>
#include <iterator>
#include <iostream>
#include <algorithm>
#include <array>


class FPregisters {
public:
    FPregisters();
    FPregisters(const FPregisters& orig);
    virtual ~FPregisters();
    float getFloatValue (int index);
    void setFloatValue (int index, float value);
    int getSize ();
    void fillWithValue (float value);
private:
    std::array<float,4> fpRegister;
       
};

#endif /* FPREGISTERS_H */

