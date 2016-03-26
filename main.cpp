
/* 
 * File:   main.cpp
 * Author: Rossana
 *
 * Created on 19 marzo 2016, 14.42
 */

#include "Jedi.h"
#include "Galaxy.h"
#include "Sith.h"
#include <time.h>

using namespace std;
string WELCOME = "\nA long time ago in a galaxy far, far away...\n\n";
string LATER = " years later...\n\n";
string CONTINUE = "\n\nPress 'q' to quit, 'c' to continue >> ";
string ALLDEAD = "\nAny jedi in the galaxy is dead, so the program quit.\n";
int JEDI = 5;
int Jedi::classID = 0;
char c;

void goOn(){
    cout << CONTINUE;
    cin >> c;
    cout << c << "\n\n";
}

int main(int argc, char** argv) {
 
    int i = 1;
    cout << WELCOME;
    srand(time(NULL));    
    Galaxy galassia(JEDI);  
    galassia.printGalaxy();    
    goOn();
    
    while(c != 'q'){
        cout << "\n" << i << LATER;
        galassia.agingGalaxy();
        galassia.setMarks();
        galassia.newBorn();
        galassia.printGalaxy();
        galassia.sithParty();
        galassia.checkLaziness();
        galassia.checkAge();
        
        if(galassia.isAnyJediAlive()){
            i++;
            goOn();
        } else{
            c = 'q';
            cout << ALLDEAD;
        }
    }
    
    return 0;
}