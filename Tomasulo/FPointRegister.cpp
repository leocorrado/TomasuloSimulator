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
}

FPointRegister::FPointRegister (float val)
{
    value = val;
    tag = TagsReprise::NON;
}

FPointRegister::FPointRegister(const FPointRegister& orig) {
}

FPointRegister::~FPointRegister() {
}

void FPointRegister::setTag(TagsReprise obj)
{
    tag = obj;
}

void FPointRegister::setValue(float val)
{
    value = val;
}

float FPointRegister::getValue()
{
    return value;
}

TagsReprise FPointRegister::getTag()
{
    return tag;
}
