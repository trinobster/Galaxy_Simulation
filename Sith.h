
/* 
 * File:   Sith.h
 * Author: Rossana
 *
 * Created on 20 marzo 2016, 16.19
 */

#ifndef SITH_H
#define SITH_H

#include "Jedi.h"
#include <string>
#include <iostream>
#include <cstdlib>
#include <stdio.h>

class Sith : public Jedi{
    
    private:
        int timeNobite;
    
    public:
        Sith();
        ~Sith();
        int getTimeNoBite();
        void setTimeNoBite(int time);
        bool isOld();
        bool isLazy();
        void print();
};

#endif /* SITH_H */

