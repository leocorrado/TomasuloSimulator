/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: leo
 *
 * Created on 16 de mayo de 2018, 20:23
 */

#include <cstdlib>
#include <string>
#include <iostream>
#include "FPregisters.h"
#include "OperationsEnum.h"

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {

    FPregisters * fpRegisters = new FPregisters ();
    fpRegisters ->fillWithValue(2.0);
    OperationsEnum enumerador;;
    enumerador = OperationsEnum::SUM;
    for (int i = 0; i < fpRegisters->getSize(); i++)
    {
        cout << fixed << fpRegisters->getFloatValue(i) << " ";
    }
    std::cout << enumerador << '\n';
    return 0;
}

