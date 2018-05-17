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

bool ReservationStation::getBusy()
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