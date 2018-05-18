/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Instruction.h
 * Author: leo
 *
 * Created on 17 de mayo de 2018, 23:16
 */

#ifndef INSTRUCTION_H
#define INSTRUCTION_H
#include "OperationsEnum.h"

class Instruction {
public:
    Instruction();
    Instruction(int RD, int RS, int RT,
                         OperationsEnum OPCODE);
    Instruction(const Instruction& orig);
    virtual ~Instruction();
    int getRd ();
    int getRs ();
    int getRt ();
    OperationsEnum getOpCode ();
    int getIssueClock ();
    int getExecuteClockBegin ();
    int getExecuteClockEnd ();
    int getWriteBackClock ();
    void setIssueClock (int clk);
    void setExecuteClockBegin (int clk);
    void setExecuteClockEnd (int clk);
    void setWriteBackClock (int clk);
private:
    int rd;
    int rs;
    int rt;
    OperationsEnum opCode;
    int issueClock;
    int executeClockBegin;
    int executeClockEnd;
    int writeBackClock;

};

#endif /* INSTRUCTION_H */

