/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   FPregisters.h
 * Author: leo
 *
 * Created on 16 de mayo de 2018, 20:27
 */

#ifndef FPREGISTERS_H
#define FPREGISTERS_H

#include <string>
#include <array>
#include <utility>
#include <stdio.h>
#include "OperationsEnum.h"
#include "TagsReprise.h"

class FPregisters {
public:
    FPregisters();
    FPregisters(const FPregisters& orig);
    virtual ~FPregisters();
    std::pair <TagsReprise,float> getPair (int index);
    int getIndexOfTag (TagsReprise tag);
    float getValueByTag (TagsReprise tag);
    void setValueByTag (TagsReprise tag ,float value);
    void setTag (TagsReprise newVal, TagsReprise oldVal);
    
   
private:
    std::array< std::pair<TagsReprise,float>, 4 > fpRegister {{}} ;  
};

#endif /* FPREGISTERS_H */

