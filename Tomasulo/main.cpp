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



#include <iostream>
#include <vector>
#include <array>
#include <string>
#include <cstdlib>
#include <sstream>
#include <iomanip>



//############################################
// Configuraciones de latencia
const int ADD_LATENCY = 2;
const int SUB_LATENCY = 2;
const int LOAD_LATENCY = 2;
const int MULT_LATENCY = 10;
const int DIV_LATENCY = 40;
//
//###########################################
//###########################################
// Variables globales de control
int GLOBAL_CLOCK = 0;
int instructionsIssued = 0;
int totalInstIssued = 0;
bool finish = false;
//
//############################################

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
int issue (vector<Instruction>& instr,
          vector<ReservationStation>& reserStations,
          vector<FPointRegister>& fPRegs,
          vector<RRegisters>& rRegs);



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
    
    vector<Instruction> instructionsVector = {I0,I1,I2,I3,I4,I5};
    
    printInstructions (instructionsVector);
    
    
    
    //######################################################################
    //  Inicialización de las estaciones de Reserva
    
    ReservationStation ADD1 = ReservationStation (TagsReprise::ADD1, OperationsEnum::ADD);
    ReservationStation ADD2 = ReservationStation (TagsReprise::ADD2, OperationsEnum::ADD);
    ReservationStation ADD3 = ReservationStation (TagsReprise::ADD3, OperationsEnum::ADD);
    ReservationStation MUL1 = ReservationStation (TagsReprise::MUL1, OperationsEnum::MUL);
    ReservationStation MUL2 = ReservationStation (TagsReprise::MUL2, OperationsEnum::MUL);
    ReservationStation LOAD1 = ReservationStation (TagsReprise::LOAD1, OperationsEnum::LOAD);
    ReservationStation LOAD2 = ReservationStation(TagsReprise::LOAD2, OperationsEnum::LOAD);
    ReservationStation LOAD3 = ReservationStation(TagsReprise::LOAD3, OperationsEnum::LOAD);
    ReservationStation LOAD4 = ReservationStation(TagsReprise::LOAD4, OperationsEnum::LOAD);
    ReservationStation LOAD5 = ReservationStation(TagsReprise::LOAD5, OperationsEnum::LOAD);
    
    
    vector<ReservationStation> functionalUnits = {ADD1, ADD2, ADD3, 
                                          MUL1, MUL2, LOAD1,
                                          LOAD2, LOAD3, LOAD4,
                                           LOAD5};
    printFunctionalUnits (functionalUnits);
    
    //
    //########################################################################
    
    //#######################################################################
    //  Inicializacion de los R- Registers
    
    RRegisters R0 = RRegisters(RRegistersNames::R0);
    RRegisters R1 = RRegisters(RRegistersNames::R1);
    RRegisters R2 = RRegisters(RRegistersNames::R2);
    RRegisters R3 = RRegisters(RRegistersNames::R3);
    vector<RRegisters> rRegisters = {R0,R1,R2,R3};

    printRRegisters (rRegisters);
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


    vector<FPointRegister> fPointRegisters = {F0,F1,F2,F3, F4, F5};
    
    printFPRegisters (fPointRegisters);
    // 
    //########################################################################
    cout << "Comienzo de la simulacion: "<<endl<<endl<<endl;
    
    do
    {   
       GLOBAL_CLOCK++;
       issue (instructionsVector, functionalUnits,fPointRegisters,rRegisters);
       printFPRegisters (fPointRegisters);
       printFunctionalUnits (functionalUnits);
        
        
    }while (!finish);
    
    return 0;
}

 
int issue (vector<Instruction>& instr,
          vector<ReservationStation>& reserStations,
          vector<FPointRegister>& fPRegs,
          vector<RRegisters>& rRegs)
{
    
    bool banderaIssue = false; //Permite saber si se encontro una estacion de 
                               //reserva libre
    int auxIndex = 0;  //Se guarda el indice de la estacion libre
    //Si todas las instrucciones ya fueron issued, hay que retornar.
    if (instructionsIssued >= instr.size())
    {
        //!!!!!!!!!!!!!!!!!!!!!!!
        //sacar la linea DONE = TRUE
        finish = true;
        return 0;
    }
        
    
    
    
    //A partir de la instruccion a leer , se le retira el operando
    OperationsEnum operando = instr [instructionsIssued].getOpCode();
    switch (operando)
    {
        case OperationsEnum::ADD :
            for (int i = 0; i < reserStations.size(); i++)
            {
                //Comprobar que existe una estacion de reserva del tipo
                //solicitado que este libre
                if (reserStations[i].getType() == OperationsEnum::ADD && 
                    !reserStations[i].isBusy())
                {
                    auxIndex = i;
                    instructionsIssued++;
                    reserStations [i].setOperation(operando);
                    banderaIssue = true;
                    break;
                }      
            }
            //Ninguna estacion de reserva esta libre, volver al main
            if (!banderaIssue)
                return 1;
            break;
        case OperationsEnum::SUB:
            for (int i = 0; i < reserStations.size(); i++) 
            {
                if (reserStations[i].getType() == OperationsEnum::ADD &&
                        !reserStations[i].isBusy()) 
                {
                    auxIndex = i;
                    instructionsIssued++;
                    reserStations [i].setOperation(operando);
                    banderaIssue = true;
                    break;
                }
            }
            //Ninguna estacion de reserva esta libre, volver al main
            if (!banderaIssue)
                return 1;
            break;
        case OperationsEnum::MUL:
            for (int i = 0; i < reserStations.size(); i++) 
            {
                if (reserStations[i].getType() == OperationsEnum::MUL &&
                        !reserStations[i].isBusy()) 
                {
                    auxIndex = i;
                    instructionsIssued++;
                    reserStations [i].setOperation(operando);
                    banderaIssue = true;
                    break;
                }
            }
            //Ninguna estacion de reserva esta libre, volver al main
            if (!banderaIssue)
                return 1;
            break;
        case OperationsEnum::DIV:
            for (int i = 0; i < reserStations.size(); i++) {
                if (reserStations[i].getType() == OperationsEnum::MUL &&
                        !reserStations[i].isBusy()) {
                    auxIndex = i;
                    instructionsIssued++;
                    reserStations [i].setOperation(operando);
                    banderaIssue = true;
                    break;
                }
            }
            //Ninguna estacion de reserva esta libre, volver al main
            if (!banderaIssue)
                return 1;
            break;
        case OperationsEnum::LOAD:
            for (int i = 0; i < reserStations.size(); i++) {
                if (reserStations[i].getType() == OperationsEnum::LOAD &&
                        !reserStations[i].isBusy()) {
                    auxIndex = i;
                    instructionsIssued++;
                    reserStations [i].setOperation(operando);
                    banderaIssue = true;
                    break;
                }
            }
            //Ninguna estacion de reserva esta libre, volver al main
            if (!banderaIssue)
                return 1;
            break;
        default: 
            break;
    }
    FPRegNames name_rd = instr [instructionsIssued - 1].getRd();

    if (operando != OperationsEnum::LOAD)
    {
        FPRegNames name_rs = instr [instructionsIssued - 1].getRsFp();
        FPRegNames name_rt = instr [instructionsIssued - 1].getRtFp();
        for (int i = 0; i < fPRegs.size(); i++)
        {
            if (name_rs == fPRegs [i].getName())
            {
                if (fPRegs [i].getTag() == TagsReprise::NON)
                {
                    reserStations[auxIndex].setVj(fPRegs [i].getValue());
                    reserStations[auxIndex].setQj(TagsReprise::NON);
                }
                else
                {
                    reserStations[auxIndex].setQj(fPRegs[i].getTag());
                }
            }
            if (name_rt == fPRegs [i].getName())
            {
                if (fPRegs [i].getTag() == TagsReprise::NON) {
                    reserStations[auxIndex].setVk(fPRegs [i].getValue());
                    reserStations[auxIndex].setQk(TagsReprise::NON);
                } else {
                    reserStations[auxIndex].setQk(fPRegs[i].getTag());
                }
            }
           
        }
    }
    else
    {
        RRegistersNames offset_register = instr [instructionsIssued -1].getRtR();
        int immediate = instr [instructionsIssued - 1].getRsVal();
        for (int i = 0; i < rRegs.size(); i++)
        {
            if (offset_register == rRegs[i].getRegisterName() )
            {
                reserStations [auxIndex].setVj(rRegs[i].getRegisterValue());
                reserStations [auxIndex].setAddress(immediate);
            }
        }
    }
    reserStations [auxIndex].setBusy(true);
    instr [instructionsIssued -1].setIssueClock(GLOBAL_CLOCK);
    for (int i = 0; i < fPRegs.size(); i++)
    {
        if (name_rd == fPRegs [i].getName()) 
        {
            fPRegs [i].setBusy(true);
            fPRegs [i].setTag(reserStations [auxIndex].getName());
        }
    }
    return 2;
}









void printFunctionalUnits (vector<ReservationStation> functionalUnits)
{
    cout << "Estado de las estaciones de reserva" << endl;
    for (int i = 0; i < functionalUnits.size(); i++)
    {
        functionalUnits [i].toPrint();   
    }
    cout<<endl;
}

void printRRegisters (vector <RRegisters> rRegisters)
{
    cout << "Estado de los R- Registers" << endl;
    for (int i = 0; i < rRegisters.size(); i++)
    {
        rRegisters[i].toPrint();
    }
    cout<<endl;
}

void printFPRegisters (vector <FPointRegister> fPointRegisters)
{
    cout << "Estado de los FP Registers" << endl;
    for (int i = 0; i < fPointRegisters.size(); i++)
    {
        fPointRegisters [i].toPrint();
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

