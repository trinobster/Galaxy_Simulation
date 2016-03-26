/* 
 * File:   Jedi.h
 * Author: Rossana
 *
 * Created on 19 marzo 2016, 18.41
 */

#ifndef JEDI_H
#define JEDI_H

#include <string>
#include <iostream>
#include <cstdlib>
#include <stdio.h>

    class Jedi{
    public:
        char sex;
        char mark;
        long int id;
        int age;
        std::string name;
        std::string planet;
        static int classID;
    
    public:
        Jedi();
        ~Jedi();
        virtual void aging();
        virtual void print();
        void setMark();
        bool isSith();
        virtual bool isOld();
    };


#endif /* JEDI_H */