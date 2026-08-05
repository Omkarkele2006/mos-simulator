/**
 * @file phase2.cpp
 * @brief Phase 2 implementation of the Multiprogramming Operating System (MOS).
 *
 * Phase 2 extends the basic MOS by introducing paging,
 * address translation, interrupt handling, process control
 * blocks, and program error handling.
 */

#include <iostream>
#include <fstream>
using namespace std;

// Global memory

char M[300][4]; // Real memory (300 words of 4 characters)

// CPU registers
char R[4];
char IR[4];
int IC;
int C;

int PTR; // Page table register

// Interrupts
int SI;
int PI;
int TI;

// Address translation
int VA;
int RA;

// Input buffer
char buffer[41];

// Process Control Block (PCB)

struct PCB
{
    int jobId;

    int TTL;
    int TLL;

    int TTC;
    int LLC;
};

PCB pcb;

// File streams

ifstream fin;
ofstream fout;

// Function declarations

int ALLOCATE();

int ADDRESSMAP(int VA);

void INIT();

void LOAD();

void STARTEXECUTION();

void EXECUTEUSERPROGRAM();

void MOS();

void READ();

void WRITE();

void TERMINATE(int errorCode);


int main()
{
    LOAD();
    return 0;
}