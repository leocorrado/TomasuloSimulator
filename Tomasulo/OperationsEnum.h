/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   OperationsEnum.h
 * Author: leo
 *
 * Created on 16 de mayo de 2018, 21:38
 */

#ifndef OPERATIONSENUM_H
#define OPERATIONSENUM_H

#include <ostream>

enum class OperationsEnum :  char { SUM = '+', SUB = '-', MUL = '*', DIV = '/',
                                    LOAD = 'L', UNDEF = 'U' };

inline std::ostream& operator<<(std::ostream& os, OperationsEnum obj)
 {
    return os << static_cast<char>(obj);
 }
#endif /* OPERATIONSENUM_H */

