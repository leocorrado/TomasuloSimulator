/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   LoadBuffer.h
 * Author: leo
 *
 * Created on 17 de mayo de 2018, 21:24
 */

#ifndef LOADBUFFER_H
#define LOADBUFFER_H
#include <string>
#include <array>
#include <utility>
#include <stdio.h>

class LoadBuffer {
public:
    LoadBuffer();
    LoadBuffer(const LoadBuffer& orig);
    virtual ~LoadBuffer();
private:
    int direccion;
    int valor;

};

#endif /* LOADBUFFER_H */

