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
#include "OperationsEnum.h"
#include "TagsReprise.h"
#include "RRegistersNames.h"
#include "FPRegNames.h"
#include "Instruction.h"
#include "ReservationStation.h"
#include "RRegisters.h"
#include "FPointRegister.h"
//#include <string>



#include <iostream>
#include <vector>
#include <array>
#include <string>
#include <cstdlib>
#include <sstream>
#include <iomanip>





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
void printFunctionalUnits ( vector<ReservationStation> );
void printRRegisters (vector <RRegisters>);
void printFPRegisters (vector <FPointRegister>);
void printInstructions (vector <Instruction>);

int main(int argc, char** argv) 
{
    //#######################################################################
    // Inicializacion de las instrucciones a ejecutar
    
    Instruction I0 = Instruction (FPRegNames::FP1, 34,  RRegistersNames::R2,
                                    OperationsEnum::LOAD);      
    Instruction I1 = Instruction (FPRegNames::FP2, 45, RRegistersNames::R3,
                                     OperationsEnum::LOAD);
    Instruction I2 = Instruction (FPRegNames::FP3, FPRegNames::FP2, 
                                  FPRegNames::FP4, OperationsEnum::MUL);
    Instruction I3 = Instruction (FPRegNames::FP5, FPRegNames::FP1,
                                  FPRegNames::FP2, OperationsEnum::SUB);
    Instruction I4 = Instruction (FPRegNames::FP0, FPRegNames::FP3, 
                                  FPRegNames::FP1, OperationsEnum::DIV);
    Instruction I5 = Instruction(FPRegNames::FP1, FPRegNames::FP5,
            FPRegNames::FP2, OperationsEnum::ADD);
    
    vector<Instruction> INSTRUCTIONS = {I0,I1,I2,I3,I4,I5};
    
    printInstructions (INSTRUCTIONS);
    
    
    
    //######################################################################
    //  Inicialización de las estaciones de Reserva
    
    ReservationStation ADD1 = ReservationStation (TagsReprise::ADD1);
    ReservationStation ADD2 = ReservationStation (TagsReprise::ADD2);
    ReservationStation ADD3 = ReservationStation (TagsReprise::ADD3);
    ReservationStation MUL1 = ReservationStation (TagsReprise::MUL1);
    ReservationStation MUL2 = ReservationStation (TagsReprise::MUL2);
    ReservationStation LOAD1 = ReservationStation (TagsReprise::LOAD1);
    ReservationStation LOAD2 = ReservationStation(TagsReprise::LOAD2);
    ReservationStation LOAD3 = ReservationStation(TagsReprise::LOAD3);
    ReservationStation LOAD4 = ReservationStation(TagsReprise::LOAD4);
    ReservationStation LOAD5 = ReservationStation(TagsReprise::LOAD5);
    
    
    vector<ReservationStation> FUNITS = {ADD1, ADD2, ADD3, 
                                          MUL1, MUL2, LOAD1,
                                          LOAD2, LOAD3, LOAD4,
                                           LOAD5};
    printFunctionalUnits (FUNITS);
    
    //
    //########################################################################
    
    //#######################################################################
    //  Inicializacion de los R- Registers
    
    RRegisters R0 = RRegisters(RRegistersNames::R0);
    RRegisters R1 = RRegisters(RRegistersNames::R1);
    RRegisters R2 = RRegisters(RRegistersNames::R2);
    RRegisters R3 = RRegisters(RRegistersNames::R3);
    vector<RRegisters> RREGS = {R0,R1,R2,R3};

    printRRegisters (RREGS);
    //
    //#######################################################################

    //######################################################################
    //  Inicialiacion de los FP- Registers
    // 
    
    FPointRegister F0 = FPointRegister (FPRegNames::FP0);
    FPointRegister F1 = FPointRegister (FPRegNames::FP1);
    FPointRegister F2 = FPointRegister (FPRegNames::FP2);
    FPointRegister F3 = FPointRegister (FPRegNames::FP3);
    FPointRegister F4 = FPointRegister (FPRegNames::FP4);
    FPointRegister F5 = FPointRegister (FPRegNames::FP5);


    vector<FPointRegister> FPREGS = {F0,F1,F2,F3, F4, F5};
    
    printFPRegisters (FPREGS);
    // 
    //########################################################################
    
    return 0;
}

 
void printFunctionalUnits (vector<ReservationStation> FUNITS)
{
    cout << "Estado de las estaciones de reserva" << endl;
    for (int i = 0; i < FUNITS.size(); i++)
    {
        FUNITS [i].toPrint();   
    }
    cout<<endl;
}

void printRRegisters (vector <RRegisters> RREGS)
{
    cout << "Estado de los R- Registers" << endl;
    for (int i = 0; i < RREGS.size(); i++)
    {
        RREGS[i].toPrint();
    }
    cout<<endl;
}

void printFPRegisters (vector <FPointRegister> FPREGS)
{
    cout << "Estado de los FP Registers" << endl;
    for (int i = 0; i < FPREGS.size(); i++)
    {
        FPREGS [i].toPrint();
    }
    cout << endl;
}

void printInstructions (vector <Instruction> INSTRUCTIONS)
{
    cout << "Instrucciones a Ejecutar" << endl;
    for (int i = 0; i < INSTRUCTIONS.size(); i++)
    {
        INSTRUCTIONS [i].toPrint();
    }
    cout << endl;
}

