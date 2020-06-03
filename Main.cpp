#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>
#include "Bank.h"
#include "Timer.h"
#include "ID.h"
#include "Tools.h"
//#define P(x) #x;

int main(int argc, char* argv[]) {
    switch (argc) {
    case 1:     // Default file
        try {
            ifstream settings;
            int arguments[12] = {};
            
            settings.open("settings.txt");
            if (!settings.good())
                throw FileNotFound("Default settings file not found");

            for (int n = 1; !settings.eof(); n++) {
                settings >> arguments[n];
                if (settings.fail() || arguments[n] < 0)
                    throw BadOperation("Settings have wrong format.");
            }
            settings.close();
            Timer timer(arguments[10], "log.txt", BankSetup { arguments[1], arguments[2], arguments[3], arguments[4], arguments[5], arguments[6], arguments[7], arguments[8], arguments[9]}, arguments[11]);
            timer.runSimulation();
        }
        catch (BadOperation ex) {
            cout << "Wrong operation: " << ex << endl;
        }
        catch (FileNotFound ex) {
            cout << "Default settings file not found" << endl;
        }
        break;
    case 2:     // File
        try {
            ifstream settings;
            int arguments[12] = {};

            settings.open(argv[1]);
            if (!settings.good())
                throw FileNotFound("Settings file not found");

            for (int n = 1; !settings.eof(); n++) {
                settings >> arguments[n];
                if (settings.fail() || arguments[n] < 0)
                    throw BadOperation("Settings have wrong format.");
            }
            settings.close();
            Timer timer(arguments[10], "log.txt", BankSetup{ arguments[1], arguments[2], arguments[3], arguments[4], arguments[5], arguments[6], arguments[7], arguments[8], arguments[9] }, arguments[11]);
            timer.runSimulation();
        }
        catch (BadOperation ex) {
            cout << "Wrong operation: " << ex << endl;
        }
        catch (FileNotFound ex) {
            cout << "Default settings file not found" << endl;
        }
        break;
    case 11:    // Direct arguments
        try {
            int arguments[12] = {};

            for (int n = 1; n < argc; n++) {
                arguments[n] = stoi(argv[n]);
                if (arguments[n] < 0) {
                    throw BadOperation("Settings have wrong format.");
                }
            }
           

            Timer timer(arguments[10], "log.txt", BankSetup{ arguments[1], arguments[2], arguments[3], arguments[4], arguments[5], arguments[6], arguments[7], arguments[8], arguments[9] }, arguments[11]);
            timer.runSimulation();
        }
        catch (invalid_argument ex) {
            cout << "Settings have wrong format.";
        }
        catch (BadOperation ex) {
            cout << "Wrong operation: " << ex << endl;
        }
        break;
    }
    return 0;
}

