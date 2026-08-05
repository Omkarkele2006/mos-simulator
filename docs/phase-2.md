# Operating System Course Project (OS-CP) - Phase 2

## Overview

Phase 2 extends the Phase 1 MOS by introducing paging, address translation, interrupt handling, and program error handling. Unlike Phase 1, jobs are no longer assumed to be error-free, and the operating system is responsible for detecting and handling runtime errors.

## What's New in Phase 2

- Paging is introduced for program loading and memory access.
- Virtual addresses are translated to real addresses using a page table.
- Program Interrupt (PI) and Time Interrupt (TI) are added.
- A Process Control Block (PCB) is maintained for each job.
- Runtime errors such as opcode errors, operand errors, page faults, and time limit violations are handled by the OS.
- Detailed termination information is printed after every job.

## Basic Information

1. The logical (virtual) memory consists of **100 words** (addresses `00–99`).
2. The real (physical) memory consists of **300 words**, divided into **30 page frames** of **10 words** each.
3. Each page/frame stores **10 words**, with each word containing **4 characters**.
4. One program card occupies at most **one page (40 characters / 10 words)**. Longer programs continue on the next program card.
5. One job is loaded and executed at a time (Uniprogramming).

> **Why is physical memory larger than virtual memory?**
>
> This project uses a fixed 4-character instruction format, where the first two characters represent the opcode and the remaining two represent the operand (memory address). Since only two digits are available for addresses, programs can reference virtual addresses `00–99` only. To demonstrate paging and address translation, the simulator provides a larger physical memory of **300 words**.

## Job Cards

### `$AMJ`

```text
$AMJJJJJTTTTLLLL
```

where:

- `JJJJ` – 4-digit Job ID
- `TTTT` – Total Time Limit (TTL)
- `LLLL` – Total Line Limit (TLL)

Unlike Phase 1, **TTL is not equal to the number of instructions**.

Instruction execution time:

| Instruction | Time Units |
|-------------|-----------:|
| `GD` | 2 |
| `SR` | 2 |
| All others | 1 |

### `$END`

```text
$ENDJJJJ
```

where:

- `JJJJ` – Job ID corresponding to the current job.

## New Registers

Along with the registers introduced in Phase 1, Phase 2 adds:

- `PTR` – Page Table Register
- `PI` – Program Interrupt
- `TI` – Time Interrupt
- `TTC` – Total Time Counter
- `LLC` – Line Limit Counter

## Interrupts

### Supervisor/Service Interrupt (SI)

- `1` – GD
- `2` – PD
- `3` – H

### Program Interrupt (PI)

- `1` – Operation Code Error
- `2` – Operand Error
- `3` – Page Fault

### Time Interrupt (TI)

- `2` – Time Limit Exceeded

## Error Types

The operating system handles the following runtime errors:

1. Out of Data
2. Line Limit Exceeded
3. Time Limit Exceeded
4. Operation Code (Opcode) Error
5. Operand Error
6. Invalid Page Fault

## Assumptions

1. Jobs may contain program errors.
2. Consecutive jobs are stored without any physical separation.
3. Outputs of consecutive jobs are separated by two blank lines.
4. Programs use virtual addresses (`00–99`) only.
5. Program pages are allocated to random free page frames.
6. The page table is stored in real memory.
7. One program is loaded and executed at a time.