
/* 
 * File:   Sith.cpp
 * Author: Rossana
 * 
 * Created on 20 marzo 2016, 16.20
 */

#include "Sith.h"
#include <iomanip>
#include "Jedi.h"
#include <iostream>


Sith::Sith() : Jedi(){
    std::string sithNames[5] = {"Anakin", "Maul", "Kylo Ren", "Jar Jar Binks", "Sidious"};
    
    int rnd = rand() % 5;
    this->name = sithNames[rnd];
    this->mark = 'S';
    this->setTimeNoBite(0);
}

Sith::~Sith() {
}

void Sith::print() {
    std::cout << std::right << "id: " << std::setw(10) << id 
                      << " | Name: " << std::setw(13) << name
                      << " | Planet :  " << std::setw(10) << planet 
                      << " | Age: " << age 
                      << " | Mark: " << mark
                      << " | Time no bite: " << timeNobite << " |\n";

}

int Sith::getTimeNoBite(){
    return timeNobite;
}

void Sith::setTimeNoBite(int time){
    timeNobite = time;
}

bool Sith::isOld(){
    if((this->age > 50)) 
        return true;
    return false;
}

bool Sith::isLazy(){
    int laziness = this->getTimeNoBite();
    if(laziness > 15)
        return true;
    return false;
}