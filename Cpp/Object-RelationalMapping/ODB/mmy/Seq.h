/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Seq.h
 * Author: alfaceor
 *
 * Created on 19 de Junho de 2019, 13:31
 */

#ifndef SEQ_H
#define SEQ_H
#include <odb/core.hxx>
#include <string>

#pragma db object
class Seq {
public:
    Seq();
    Seq(const Seq& orig);
    virtual ~Seq();
private:
    friend class odb::access;

    #pragma db id auto
    unsigned long id_;
    std::string description_;
    std::string sequence_;

};

#endif /* SEQ_H */


