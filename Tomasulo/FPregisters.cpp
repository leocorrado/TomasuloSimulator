/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   FPregisters.cpp
 * Author: leo
 * 
 * Created on 16 de mayo de 2018, 20:27
 */

#include "FPregisters.h"

using namespace std;

FPregisters::FPregisters() 
{
    for (int i = 0; i < fpRegister.size(); i++)
    {
        fpRegister [i] = make_pair (TagsReprise::NON, 0.0);
    }
}

FPregisters::FPregisters(const FPregisters& orig) {
}

FPregisters::~FPregisters() {
}

/**
 *  @return float que represeta el valor que es 
 *  el par del @param tag de argumento.
 * 
 */ 
float FPregisters::getValueByTag(TagsReprise tag)
{
    int i = getIndexOfTag (tag);
    return fpRegister [i].second; //maybe error if index is not found
}

/**
 * 
 * @return par Tag, flotante que corresponde
 * al elemento seleccionado mediante @param index.
 * 
 */
pair <TagsReprise, float> FPregisters::getPair(int index)
{
    return fpRegister.at (index);
}


/**
 * 
 * @param tag
 * @return int que representa el indíce del elemento
 * que contiene el tag pasado como argumento.
 */
int FPregisters::getIndexOfTag(TagsReprise tag)
{
    std::pair <TagsReprise, float> aux;
    int tmp = -1;
    for (int i = 0; i < fpRegister.size(); i++)
    {
        aux = fpRegister [i];
        if (aux.first == tag)
        {
            tmp = i;
            break;
        }
    }
    return tmp;
}

/**
 * 
 * @param tag
 * @param value 
 * Modifica el valor flotante del registro que contiene el tag
 * pasado como argumento.
 */
void FPregisters::setValueByTag(TagsReprise tag, float value)
{
    int i;
    i = getIndexOfTag (tag); //maybe error if index is not found
    fpRegister [i].second = value;
} 


