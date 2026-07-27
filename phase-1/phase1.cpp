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

char M[100][4];  // Main memory (100 words of 4 characters)

char R[4];       // General-purpose register
char IR[4];      // Instruction register
int IC;          // Instruction counter / Instruction pointer
int C;           // Toggle register / Condition flag

int SI;          // Service interrupt
char buffer[41]; // Input buffer

// Execution statistics

int TTL=0;       // Total time limit
int TLL=0;       // Total line limit

// File streams

ifstream fin;
ofstream fout;