
/* 
 * File:   Galaxy.cpp
 * Author: Rossana
 * 
 * Created on 19 marzo 2016, 18.42
 */

#include "Galaxy.h"
#include "Sith.h"
#include <stdlib.h>
#include <stdio.h>

using namespace std;

Galaxy::Galaxy(int init) {
    for(int i = 0; i < init; i++){
        Jedi *jedi = new Jedi();
        this->population.push_back(jedi);
    }
}

void Galaxy::printGalaxy(){
    for(int i = 0; i < population.size(); i++){
        this->population.at(i)->print();
    }
}

Jedi* Galaxy::getJedi(int i){
    Jedi *j;
    j = population.at(i);
    return j;
}

void Galaxy::agingGalaxy(){
    for(unsigned i = 0; i < this->population.size(); i++){
        Jedi *j = this->getJedi(i);
        j->aging();
    }
}

void Galaxy::setMarks(){
    for(unsigned i = 0; i < this->population.size(); i++){
        Jedi *j = this->getJedi(i);
        j->setMark();
    }
}

bool Galaxy::look4M(){
    for(unsigned i = 0; i < this->population.size(); i++){
        Jedi *j = this->getJedi(i);
        if((j->mark) == 'M'){
            return true;
        }
    }
    return false;
}

std::vector<Jedi*> Galaxy::getMothers(){
    vector<Jedi*> mothers;
    for(unsigned i = 0; i < this->population.size(); i++){
        Jedi *j = this->getJedi(i);
        if((j->mark) == 'F'){
            mothers.push_back(j);
        }
    }
    return mothers;
}

void Galaxy::createJedi(Jedi mother, bool isSith){
    int id = this->population.size();
    
    if(isSith){
        Sith *s = new Sith();
        s->planet = mother.planet;
        this->population.push_back(s);
    } else{
        Jedi *j = new Jedi();
        j->planet = mother.planet;
        this->population.push_back(j);
    }
}

bool Galaxy::newSith(){
    int rnd = rndGenerator(100, 1);
    if(rnd <= 25)
        return true;
    return false;
}

void Galaxy::newBorn(){
    if(this->look4M()){
        vector<Jedi*> mothers = this->getMothers();
        for(int i = 0; i < mothers.size(); i++){
            Jedi *mother = (mothers.at(i));
            createJedi(*mother, newSith());
        }
    }
}

void Galaxy::death(int i){
    this->population.erase(this->population.begin() + i); //elimina l'i+1-esimo elemento
}

int Galaxy::rndGenerator(int value, int sum){
    int rnd = rand() % value + sum;
    return rnd;
}

void Galaxy::sithParty(){
    int killProbab;
    int index;
    int rndTarget;
    Sith *s;
    int targetID;
    int sithID;
    vector<Sith*> sith = this->getSith();
    
    for(int i = 0; i < sith.size(); i++){   // scorre la lista dei sith presenti nella galassia
        index = this->population.size();
        rndTarget = rndGenerator(index, 0); // decide il nuovo target da uccidere
        targetID = (this->getJedi(rndTarget))->id;
        
        s = sith.at(i);
        sithID = s->id;
        
        killProbab = rndGenerator(100, 1);
        
        if((targetID != sithID) && (killProbab <= 80)){             // se l'ID del target è diverso da quello del sith
                this->death(rndTarget);     // uccisione del target
                cout << "\nOh no! " << s->id << " killed " << targetID << "!\n";
        } else{
            int timeNoBite = s->getTimeNoBite();
            s->setTimeNoBite(timeNoBite + 1); // se il sith non uccide il target, il suo time no bite aumenta di 1
        }
    }
}

vector<Sith*> Galaxy::getSith(){
    vector<Sith*> sith;
    for(int i = 0; i < this->population.size(); i++){
        Jedi *j = this->getJedi(i);
        Sith *s;
        /*mChild *pChild =  (Child *) &parent;
          Parent *pParent = &child; */
        if(j->isSith()){
            s = (Sith *) j;
            sith.push_back(s);
        }
    }
    return sith;
}

void Galaxy::checkAge(){
    int i = 0;
    while(i < this->population.size()){
        Jedi *j = this->getJedi(i);
        if(j->isOld()){
            cout << "\n\n " << j->id << " was old and died\n";
            this->deathById(j->id);
        } else{
            i++;
        }
    }
}

void Galaxy::deathById(int id){
    for(int i = 0; i < this->population.size(); i++){
        Jedi *j = this->getJedi(i);
        if(j->id == id){
            death(i);
        }
    }
}

void Galaxy::checkLaziness(){
    vector<Sith*> sith = this->getSith();
    Sith *s;
    
    for(int i = 0; i < sith.size(); i++){
        s = sith.at(i);
        if(s->isLazy()){
            cout << "\n" << s->id << " was too inactive and died\n";
            this->deathById(s->id);
        }
    }
}

bool Galaxy::isAnyJediAlive(){
    if((this->population.size()) > 0)
        return true;
    return false;
}