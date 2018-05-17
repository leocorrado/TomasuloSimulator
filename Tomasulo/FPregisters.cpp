/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   FPregisters.cpp
 * Author: leo
 * 
 * Created on 16 de mayo de 2018, 20:27
 */

#include "FPregisters.h"

using namespace std;

FPregisters::FPregisters() {
    fpRegister.fill(0.0);
}

FPregisters::FPregisters(const FPregisters& orig) {
}

FPregisters::~FPregisters() {
}

float FPregisters::getFloatValue(int index) {
    return fpRegister.at (index);
    
}

void FPregisters::setFloatValue(int index, float value) {
    fpRegister [index] = value;
}

int FPregisters::getSize(){
    return fpRegister.size();
}

void FPregisters::fillWithValue(float value) {
    fpRegister.fill(value);
}