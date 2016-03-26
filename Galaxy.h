/* 
 * File:   Galaxy.h
 * Author: Rossana
 *
 * Created on 19 marzo 2016, 18.42
 */

#ifndef GALAXY_H
#define GALAXY_H

#include <vector>
#include "Jedi.h"
#include "Sith.h"

class Galaxy {
public:
    std::vector<Jedi*> population;
public:
    Galaxy(int init);
    void printGalaxy();
    Jedi* getJedi(int i);
    void agingGalaxy();
    void setMarks();
    bool look4M();
    std::vector<Jedi*> getMothers();
    void newBorn();
    void createJedi(Jedi mother, bool isSith);
    bool newSith();
    void death(int i);
    void sithParty();
    int rndGenerator(int value, int sum);
    void checkAge();
    void deathById(int posizione);
    void checkLaziness();
    std::vector<Sith*> getSith();
    bool isAnyJediAlive();
};

#endif /* GALAXY_H */

