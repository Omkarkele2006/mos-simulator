# Operating System Course Project (OS-CP) - Phase 1

## Basic Information

1. Phase 1 models a simple batch operating system, where jobs are provided through `input.txt`.
2. There are three types of cards:
   - **Program Card** – Contains the program instructions.
   - **Control Cards** – `$AMJ` (start of a new job), `$DTA` (beginning of data), `$END` (end of the job).
   - **Data Card** – Contains the input data required by the program.
3. The CPU consists of four registers:
   - `R` (4 bytes) – General-purpose register
   - `IR` (4 bytes) – Instruction register
   - `IC` (2 bytes) – Instruction counter/Instruction pointer
   - `C` (1 byte) – Toggle register/condition flag
4. Main memory consists of **100 words**, where each word stores **4 characters**. Memory is organized into **10 blocks**, with each block containing **10 words**.
5. The card reader reads one card (**10 words**) at a time, while the line printer prints one block (**10 words**) at a time.
6. Each program card stores a maximum of **40 characters (10 words)**. Programs longer than 40 characters continue on the next program card (next memory block).

   Example ([`phase-1/input.txt`](phase-1/input.txt)):

   ```text
   GD30GD40LR30NR40SR50LR30OR40SR60LR30XR40  ← 40 characters
   SR70PD50PD60PD70H                         ← Remaining instructions of same job
7. `$AMJ` follows the format:

   ```text
   $AMJJJJJTTTTLLLL
   ```

   where:

   - `JJJJ` – 4-digit Job ID (Starting from 0001)
   - `TTTT` – Total Time Limit (maximum number of instructions allowed to execute)
   - `LLLL` – Total Line Limit (maximum number of output lines that can be printed)
8. `$END` follows the format:

   ```text
   $ENDJJJJ
   ```

   where:

   - `JJJJ` – 4-digit Job ID corresponding to the current job.

## Assumptions

1. `input.txt` contains syntactically correct input.
2. Consecutive jobs are stored without any physical separation.

   ```text
   $AMJ000100010001
   ...
   $END0001
   $AMJ000200010002
   ...
   $END0002
   ```

3. Outputs of consecutive jobs are separated by two blank lines in `output.txt`.

   ```text
   HELLO OM


   I LIKE CATS
   ```

4. Only one program is loaded and executed at a time (Uniprogramming).
5. Execution of every job starts from memory location `00`.
6. Each instruction occupies exactly one memory word (4 characters).
7. Supported instructions:
   - Supervisor instructions: `GD`, `PD`, `H` – Get Data, Print Data, Halt
   - User instructions: `LR`, `SR`, `CR`, `BT`, `N`, `O`, `X` – Load to Register, Store from Register, Compare Register, Branch if True, AND, OR, XOR
8. Instructions are decoded using only the first character `IR[0]`, while
   control cards are identified using the second character after `$` (`buffer[1]`).    