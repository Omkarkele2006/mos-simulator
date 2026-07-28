/**
 * @file phase1.cpp
 * @brief Phase 1 implementation of the Multiprogramming Operating System (MOS).
 *
 * This program simulates a basic operating system capable of loading,
 * executing, and terminating user programs. It supports memory operations,
 * simple instruction execution, and supervisor services through MOS.
 */

#include <iostream>
#include <fstream>
using namespace std;

// Global memory and CPU registers

char M[100][4]; // Main memory (100 words of 4 characters)

char R[4];  // General-purpose register
char IR[4]; // Instruction register
int IC;     // Instruction counter / Instruction pointer
int C;      // Toggle register / Condition flag
int m;      // Memory pointer

int SI;          // Service interrupt
char buffer[41]; // Input buffer

// Execution statistics

int TTL = 0; // Total time limit
int TLL = 0; // Total line limit

// File streams

ifstream fin;
ofstream fout;

/**
 * Initializes the operating system state for a new job
 */
void INIT() {}

/**
 * Starts execution of the loaded user program
 */
void STARTEXECUTION() {}

/**
 * Loads the input job into memory
 */
void LOAD()
{
    fin.open("input.txt");
    fout.open("output.txt");

    m = 0;

    while (fin.getline(buffer, 41))
    {
        if (buffer[0] == '$')
        {
            switch (buffer[1])
            {
            case 'A':
            {
                INIT(); // Start of a new job
                break;
            }
            case 'D':
            {
                STARTEXECUTION(); // Execute after all program cards are loaded
                break;
            }
            case 'E':
            {
                fout << endl << endl; // Separate outputs of different jobs
                break;
            }
            }
        }
        else
        {
            // Load one program card into memory
            int k = 0;
            while (buffer[k])
            {
                for (int i = 0; i < 4; i++)
                {
                    M[m][i] = buffer[k] ? buffer[k++] : '*';
                }
                m++;
            }
        }
    }
    fin.close();
    fout.close();
}
int main()
{
    LOAD();
    return 0;
}