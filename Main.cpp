#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>
#include "Bank.h"
#include "Timer.h"
#include "ID.h"
#include "Tools.h"
#include "Error.h"
//#define P(x) #x;

int main(int argc, char* argv[]) {
    switch (argc) {
    case 1:     // Plik domyœlny settings.txt
        try {
            ifstream settings;
            int arguments[11] = {}; // Pusta tablica na argumenty, umieszczenie tak, ¿e arguments[1] - pierwszy argument, a arguments[11] - 10ty argument 
            
            settings.open("settings.txt"); 
            if (!settings.good())
                throw FileNotFound("Default settings file not found");

            for (int n = 1; !settings.eof(); n++) {
                settings >> arguments[n];
                if (settings.fail() || arguments[n] < 0)
                    throw BadOperation("Settings have wrong format.");
            }
            // Wczytywanie argumentów do tablicy, z wykrywaniem b³êdów
            settings.close();
            Timer timer(1, "log.txt", BankSetup { arguments[1], arguments[2], arguments[3], arguments[4], arguments[5], arguments[6], arguments[7], arguments[8], arguments[9]}, arguments[10]);
            // Argumenty podane do Timera
            timer.runSimulation();
        }
        catch (BadOperation ex) {
            cout << "Wrong operation: " << ex << endl;
        }
        catch (FileNotFound ex) {
            cout << "Default settings file not found" << endl;
        }
        break;
    case 2:     // Podany plik
        try {
            ifstream settings;
            int arguments[11] = {}; // Pusta tablica na argumenty, umieszczenie tak, ¿e arguments[1] - pierwszy argument, a arguments[11] - 10ty argument 

            settings.open(argv[1]);
            if (!settings.good())
                throw FileNotFound("Settings file not found");

            for (int n = 1; !settings.eof(); n++) {
                settings >> arguments[n];
                if (settings.fail() || arguments[n] < 0)
                    throw BadOperation("Settings have wrong format.");
            }
            settings.close();
            // Wczytywanie argumentów do tablicy, z wykrywaniem b³êdów
            Timer timer(1, "log.txt", BankSetup{ arguments[1], arguments[2], arguments[3], arguments[4], arguments[5], arguments[6], arguments[7], arguments[8], arguments[9] }, arguments[10]);
            // Argumenty podane do Timera
            timer.runSimulation();
        }
        catch (BadOperation ex) {
            cout << "Wrong operation: " << ex << endl;
        }
        catch (FileNotFound ex) {
            cout << "Default settings file not found" << endl;
        }
        break;
    case 11:    // Argumenty bezpoœrednie
        try {
            int arguments[11] = {}; // Pusta tablica na argumenty, umieszczenie tak, ¿e arguments[1] - pierwszy argument, a arguments[11] - 10ty argument 

            for (int n = 1; n < argc; n++) {
                arguments[n] = stoi(argv[n]);
                if (arguments[n] < 0) {
                    throw BadOperation("Settings have wrong format.");
                }
            }
            // Wczytywanie argumentów do tablicy, z wykrywaniem b³êdów
            Timer timer(1, "log.txt", BankSetup{ arguments[1], arguments[2], arguments[3], arguments[4], arguments[5], arguments[6], arguments[7], arguments[8], arguments[9] }, arguments[10]);
            // Argumenty podane do Timera
            timer.runSimulation();
        }
        catch (invalid_argument ex) {
            cout << "Settings have wrong format.";
        }
        catch (BadOperation ex) {
            cout << "Wrong operation: " << ex << endl;
        }
        break;
    default:
        cout << "Wrong amount of arguments" << endl;
        break;
    }
    
    return 0;
}

