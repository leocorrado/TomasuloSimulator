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

//#include <cstdlib>
//#include <string>
#include <iostream>
#include <vector>
#include <array>
#include <string>
#include <cstdlib>
#include <sstream>
#include <iomanip>
//#include "FPregisters.h"
#include "OperationsEnum.h"
#include "TagsReprise.h"
#include "Instruction.h"
#include "ReservationStation.h"

const int ADD_LATENCY = 2;
const int SUB_LATENCY = 2;
const int LOAD_LATENCY = 2;
const int MULT_LATENCY = 10;
const int DIV_LATENCY = 40;

using namespace std;


//######################################################################
/*
 El sistema posee 6 registros FP y por ahora no soporta operaciones 
 de load o store.
 Se supone tambien que se utilizan 6 registros de tipo R.
 Las instrucciones deben ser creadas en el main
 * 
 
 
 */
//#####################################################################
void printFunctionalUnits ( vector<ReservationStation*> );

int main(int argc, char** argv) 
{
    Instruction instruction1 (0,1,2, OperationsEnum::SUM),
            instruction2 (4,3,5, OperationsEnum::MUL);
    
    ReservationStation ADD1 = ReservationStation (TagsReprise::ADD1);
    ReservationStation ADD2 = ReservationStation (TagsReprise::ADD2);
    ReservationStation ADD3 = ReservationStation (TagsReprise::ADD3);
    ReservationStation MUL1 = ReservationStation (TagsReprise::MUL1);
    ReservationStation MUL2 = ReservationStation (TagsReprise::MUL2);

    
    vector<ReservationStation*> FUNITS = {&ADD1, &ADD2, &ADD3, &MUL1, &MUL2};
    printFunctionalUnits (FUNITS);
    
  

    
    

    return 0;
}

 
void printFunctionalUnits (vector<ReservationStation*> FUNITS)
{
    for (int i = 0; i < FUNITS.size(); i++)
    {
        cout << FUNITS [i]->toPrint();   
    }
}