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
}

ReservationStation::ReservationStation(TagsReprise nname)
{
    operation = OperationsEnum::UNDEF;
    qj = TagsReprise::NON;
    qk = TagsReprise::NON;
    vj = 0.0;
    vk = 0.0;
    busy = false;
    name = nname;
}

ReservationStation::ReservationStation(const ReservationStation& orig) {
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
std::string ReservationStation::toPrint()
{
    std::ostringstream stream;
    std::string aux;
    stream << "RS #: " << this->getName() << "  Busy: " << this->isBusy() << "  op: "<<
               this->getOperation() << "  Vj: " << std::setw(3) << this->getVj() << "  Vk: " << std::setw(3) <<
               this->getVk() << "  Qj: " << this->getQj() << "  Qk: " <<
                this->getQk() << "\n";
    aux = stream.str();
    return aux;
}

