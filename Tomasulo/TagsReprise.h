/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   TagsReprise.h
 * Author: leo
 *
 * Created on 17 de mayo de 2018, 01:31
 */

#ifndef TAGSREPRISE_H
#define TAGSREPRISE_H
#include <ostream>
enum class TagsReprise : char { X = 'X' , Y = 'Y', Z = 'Z', W = 'W' , NON = 'N'};

std::ostream& operator<<(std::ostream& os, TagsReprise obj)
 {
    return os << static_cast<char>(obj);
 }

#endif /* TAGSREPRISE_H */

