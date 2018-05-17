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
enum class OperationsEnum : char { SUM = '+', SUB = '-', MUL = '*', DIV = '/' };

std::ostream& operator<<(std::ostream& os, OperationsEnum e)
{
    return os << static_cast<char>(e);
}

#endif /* OPERATIONSENUM_H */

