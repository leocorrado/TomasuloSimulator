/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   RRegisters.h
 * Author: leo
 *
 * Created on 18 de mayo de 2018, 00:01
 */

#ifndef RREGISTERS_H
#define RREGISTERS_H

#include <vector>


class RRegisters {
public:
    RRegisters();
    RRegisters(const RRegisters& orig);
    virtual ~RRegisters();
    int getRegisterValue (int index);
    void setRegisterValue (int index, int value);
private:
    
};

#endif /* RREGISTERS_H */

