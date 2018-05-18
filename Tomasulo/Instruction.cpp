/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Instruction.cpp
 * Author: leo
 * 
 * Created on 17 de mayo de 2018, 23:16
 */

#include "Instruction.h"

Instruction::Instruction() {
    rd = 0;
    rs = 0;
    rt = 0;
    opCode = OperationsEnum::UNDEF;
    issueClock = 0;
    executeClockBegin = 0;
    executeClockEnd = 0;
    writeBackClock = 0;
}

Instruction::Instruction(int RD, int RS, int RT,
                         OperationsEnum OPCODE) {
    rd = RD;
    rs = RS;
    rt = RT;
    opCode = OPCODE;
    issueClock = 0;
    executeClockBegin = 0;
    executeClockEnd = 0;
    writeBackClock = 0;
}

Instruction::Instruction(const Instruction& orig) {
}

Instruction::~Instruction() {
}

int Instruction::getExecuteClockBegin()
{
    return executeClockBegin;
}

int Instruction::getExecuteClockEnd()
{
    return executeClockEnd;
}

int Instruction::getIssueClock()
{
    return issueClock;
}

OperationsEnum Instruction::getOpCode()
{
    return opCode;
}

int Instruction::getRd()
{
    return rd;
}

int Instruction::getRs()
{
    return rs;
}

int Instruction::getRt()
{
    return rt;
}

int Instruction::getWriteBackClock()
{
    return writeBackClock;
}

void Instruction::setExecuteClockBegin(int clk)
{
    executeClockBegin = clk;
}

void Instruction::setExecuteClockEnd(int clk)
{
    executeClockEnd = clk;
}

void Instruction::setIssueClock(int clk)
{
    issueClock = clk;
}

void Instruction::setWriteBackClock(int clk)
{
    writeBackClock = clk;
}