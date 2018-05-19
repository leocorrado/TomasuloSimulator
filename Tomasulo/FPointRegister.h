/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   FPointRegister.h
 * Author: leo
 *
 * Created on 18 de mayo de 2018, 00:21
 */

#ifndef FPOINTREGISTER_H
#define FPOINTREGISTER_H
#include "TagsReprise.h"
#include "FPRegNames.h"


#include <iostream>



class FPointRegister {
public:
    FPointRegister();
    FPointRegister (float val, FPRegNames nam);
    FPointRegister (FPRegNames nam);
    virtual ~FPointRegister();
    void setValue (float val);
    bool isBusy();
    float getValue ();
    TagsReprise getTag();
    FPRegNames getName();
    void setName (FPRegNames nam);
    void setTag (TagsReprise obj);
    void setBusy (bool bus);
    void toPrint();
private:
    float value;
    TagsReprise tag;
    bool busy;
    FPRegNames name;
    
};

#endif /* FPOINTREGISTER_H */

