/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   FPointRegister.cpp
 * Author: leo
 * 
 * Created on 18 de mayo de 2018, 00:21
 */

#include "FPointRegister.h"

FPointRegister::FPointRegister() 
{
    value = 5000;
    tag = TagsReprise::NON;
    busy = false;
    name = FPRegNames::NON;
}

FPointRegister::FPointRegister (float val, FPRegNames nam)
{
    value = val;
    tag = TagsReprise::NON;
    busy = false;
    name = nam;
}

FPointRegister::FPointRegister(FPRegNames nam)
{
    value = 5000;
    tag = TagsReprise::NON;
    busy = false;
    name = nam;
}


FPointRegister::~FPointRegister() {
}

void FPointRegister::setTag(TagsReprise obj)
{
    tag = obj;
}

void FPointRegister::setBusy(bool bus)
{
    busy = bus;
}

void FPointRegister::setValue(float val)
{
    value = val;
}

void FPointRegister::setName(FPRegNames nam)
{
    name = nam;
}

float FPointRegister::getValue()
{
    return value;
}

TagsReprise FPointRegister::getTag()
{
    return tag;
}

bool FPointRegister::isBusy()
{
    return busy;
}

FPRegNames FPointRegister::getName()
{
    return name;
}

void FPointRegister::toPrint()
{
    std::cout<< "FP Register #: " << this->getName() << " Value: "<< this->getValue() 
            << " Busy: " << this->isBusy() << " Associated Reserv.Station: " 
            << tag << std::endl;
}
