/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: leo
 *
 * Created on 16 de mayo de 2018, 20:23
 */

//#include <cstdlib>
//#include <string>
#include <iostream>

//#include "FPregisters.h"
#include "OperationsEnum.h"
#include "TagsReprise.h"

using namespace std;


int main(int argc, char** argv) {

    TagsReprise obj;
    obj = TagsReprise::W;
    OperationsEnum op;
    op = OperationsEnum::UNDEF;
    cout << obj;
    cout << op;

    return 0;
}

 
    