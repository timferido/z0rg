#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
#include <chrono>
#include <thread>
#include <vector>

using namespace std;
using namespace std::this_thread; // sleep_for, sleep_until
using namespace std::chrono; // nanoseconds, system_clock, seconds

class Game {

private:
    string playerName;
    int score;
    ofstream outfile;
    vector<string> inventory;
    bool dead;

public:

    //default constructor
    Game() : playerName("player"), score(0), dead(false) {};

    //beginning prompt
    void prompt() {

        //declarations
        char choice;
        bool valid = false;

        cout << endl << endl;
        cout << setw(40) << "  NVWERWMN   AMXVML   MNBVFRL    ABVBVL   " << endl;
        cout << setw(40) << "       //   AQ    BM  BM    MN  (U    TE  " << endl;
        cout << setw(40) << "      //    KM    OM  NM    WR  XA        " << endl;
        cout << setw(40) << "     //     KL    KM  MNBWREV   OJ        " << endl;
        cout << setw(40) << "    //      OL    MN  BMAL      OK  YML   " << endl;
        cout << setw(40) << "   //       YM    NY  NW  AL    BM    B#  " << endl;
        cout << setw(40) << "  MMXXXXMM   VWERVV   WR    AL   V&$#@V   " << endl;
        cout << endl << endl;
        cout << setw(40) << "------------------------------------------" << endl;
        cout << setw(40) << "*            Welcome to z0rg!            *" << endl;
        cout << setw(40) << "*      pL3ase s3L3c+ A ch01ce b3L0w      *" << endl;
        cout << setw(40) << "------------------------------------------" << endl;
        cout << endl << endl;

        //choice selection
        while (!valid) {
            cout << setw(40) << " (s) Start Game!                          " << endl;
            cout << setw(40) << " (v) View Hi Scores                       " << endl;
            cout << setw(40) << " (c) Credits                              " << endl;
            cout << setw(40) << " (q) Quit :(                              " << endl;
            cout << endl << endl;
            cin >> choice;
            switch (choice) {
                case 's':
                    valid = true;
                    clearScreen();
                    playGame();
                    break;
                case 'v':
                    valid = false;
                    clearScreen();
                    cout << setw(40) << "------------------------------------------" << endl;
                    cout << setw(40) << "* Sorry, that feature doesn't exist yet! *" << endl;
                    cout << setw(40) << "*      pL3ase s3L3c+ A ch01ce b3L0w      *" << endl;
                    cout << setw(40) << "------------------------------------------" << endl;
                    cout << endl << endl;
                    break;
                case 'c':
                    valid = false;
                    clearScreen();
                    cout << "By Tim Ferido" << endl;
                    cout << "https://github/timferido" << endl << endl << endl;
                    break;
                case 'q':
                    valid = true;
                    return;
                default:
                    cout << "Please enter a valid choice" << endl;
                    valid = false;
                    break;
            }   //end of switch
        }   //end of while 
    }   //end of prompt()

    /*---main---*/
    void playGame() {
        //declarations
        string user;
        char c;
        bool init = false;

        while ((c != 'y' || c != 'n' || c != 'N' || c != 'Y') && (!init)) {
            cout << endl << "Please enter your name: ";
            cin >> user;
            setName(user);
            cout << endl << "Hello, " << user << "!" << endl;
            cout << "Are you satisfied with your name? (y/n)" << endl << endl;
    
            cin >> c;
            switch (c) {
                case 'y':
                    init = true;
                    cout << endl << "Okay, let's embark!" << endl;
                    break;
                case 'Y':
                    init = true;
                    cout << endl << "Okay, let's embark!" << endl;
                    break;
                case 'n':
                    init = false;
                    cout << endl << "Okay, ";
                    break;
                case 'N':
                    init = false;
                    cout << endl << "Okay, ";
                    break;
                default:
                    init = false;
                    tryAgain();
                    break;
            }   // end of switch statement
        }   // end of while loop

        //pause for a second to give the illusion of loading! Haha >:)
        cout << "loading" << endl;
        for (int i = 0; i < 10; i++) {
            // sleep_for(nanoseconds(20));
            sleep_until(system_clock::now() + seconds(1));
            cout << "." << endl;
        }
        clearScreen();

        //


    }   // end of playGame()

    /*---setters---*/
    void setScore(int n) { score = n; }
    void setName(string s){ playerName = s; }
    void setOutput(string s) { outfile.open(s); }

    /*---getters---*/
    int getScore(){ return score; }
    string getName(){ return playerName; }

    /*---utility---*/
    void clearScreen() { for (int i = 0; i < 200; i++) { cout << endl; } }
    void tryAgain() { cout << "Try again" << endl; }

};
