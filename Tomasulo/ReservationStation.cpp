/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ReservationStation.cpp
 * Author: leo
 * 
 * Created on 16 de mayo de 2018, 23:18
 */

#include "ReservationStation.h"

ReservationStation::ReservationStation() {
    operation = OperationsEnum::UNDEF;
    qj = TagsReprise::NON;
    qk = TagsReprise::NON;
    vj = 0.0;
    vk = 0.0;
    busy = false;
    name = TagsReprise::NON;
    type = OperationsEnum::UNDEF;
    address = 0;
}

ReservationStation::ReservationStation(TagsReprise nname, OperationsEnum typ)
{
    operation = OperationsEnum::UNDEF;
    qj = TagsReprise::NON;
    qk = TagsReprise::NON;
    vj = 0.0;
    vk = 0.0;
    busy = false;
    name = nname;
    type = typ;
    address = 0;
}



ReservationStation::~ReservationStation() {
}

float ReservationStation::getVj ()
{
    return vj;
}

float ReservationStation::getVk ()
{
    return vk;
}

int ReservationStation::getAddress ()
{
   return address; 
}


bool ReservationStation::isBusy()
{
    return busy;
}

TagsReprise ReservationStation::getQj() 
{
    return qj;
}

TagsReprise ReservationStation::getQk ()
{
    return qk;
}

OperationsEnum ReservationStation::getOperation()
{
    return operation;
}

OperationsEnum ReservationStation::getType ()
{
    return type;
}


void ReservationStation::setBusy(bool value)
{
    this->busy = value;
}

void ReservationStation::setOperation(OperationsEnum op)
{
    this->operation = op;
}

void ReservationStation::setQj(TagsReprise tagQj)
{
    this->qj = tagQj;
}

void ReservationStation::setQk (TagsReprise tagQk)
{
    this->qk = tagQk;
}

void ReservationStation::setVj(float value)
{
    this->vj = value;
}

void ReservationStation::setVk (float value)
{
    this->vk = value;
}

TagsReprise ReservationStation::getName()
{
    return name;
}

void ReservationStation::setAddress (int addr)
{
    address = addr;
}

void ReservationStation::toPrint()
{
    if (this->getType() != OperationsEnum::LOAD)
    {
    std::cout << "RS #: " << this->getName() << "  Busy: " << this->isBusy() << 
            "  op: "<< this->getOperation() << "  Vj: " << std::setw(3) << 
            this->getVj() << "  Vk: " << std::setw(3) <<
               this->getVk() << "  Qj: " << this->getQj() << "  Qk: " <<
                this->getQk() << "\n";
    }
    else
    {
        std::cout << "RS #: " << this->getName() << "  Busy: " << this->isBusy() << 
            "  op: "<< this->getOperation() << "  Vj: " << std::setw(3) << 
            this->getVj() << " Address: " << this->getAddress() << " \n";
    }
}

