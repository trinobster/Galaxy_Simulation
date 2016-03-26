
/* 
 * File:   Jedi.cpp
 * Author: Rossana
 * 
 * Created on 19 marzo 2016, 18.41
 */

#include "Jedi.h"
#include <iomanip>


using namespace std;

Jedi::Jedi() {
        
    string jediNames[10] = {"Leia", "Rey", "Padme", "Daisy", "Carrie", "Han", "Luke", "Obi-Wan", "Yoda", "Qui-Gon Jinn"};
    string planets[5] = {"Alderaan", "Bespin", "Dagobah", "Hoth", "Tatooine"};
    
    this->id = classID++;
    this->age = 0;
    
    int rndGender = rand() % 10;
    if(rndGender > 4){
        this->sex = 'm';
        this->mark = 'm';
    } else{
        this->sex = 'f';
        this->mark = 'f';
    }
    this->name = jediNames[rndGender];
    
    int rndPlanet = rand() % 5;
    this->planet = planets[rndPlanet];
}

Jedi::~Jedi() {
}

void Jedi::aging(){
    this->age += 1;
}

void Jedi::print(){
    cout << std::right << "id: " << std::setw(10) << id 
                      << " | Name: " << std::setw(13) << name
                      << " | Planet :  " << std::setw(10) << planet 
                      << " | Age: " << age 
                      << " | Mark: " << mark << " |\n";
}

void Jedi::setMark(){
    if(this->age >= 2){
        if(this->mark == 'f'){
            this->mark = 'F';
        } else if(this->mark == 'm'){
            this->mark = 'M';
        }
    }
}

bool Jedi::isOld(){
    if(this->age > 10)
        return true;
    return false;
}

bool Jedi::isSith(){
    if(this->mark == 'S')
        return true;
    return false;
}