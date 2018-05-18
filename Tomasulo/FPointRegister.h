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
class FPointRegister {
public:
    FPointRegister();
    FPointRegister (float val);

    FPointRegister(const FPointRegister& orig);
    virtual ~FPointRegister();
    void setValue (float val);
    float getValue ();
    TagsReprise getTag();
    void setTag (TagsReprise obj);
private:
    float value;
    TagsReprise tag;
};

#endif /* FPOINTREGISTER_H */

