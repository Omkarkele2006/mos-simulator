# Multiprogramming OS Simulator

A C++ project I'm building to understand how a multiprogramming operating system works - starting from basic instruction execution and eventually adding paging, interrupts, and I/O spooling. Built incrementally across three phases as part of my Operating Systems coursework.

## Interactive Simulator

Try the visual MOS simulator here: https://mos-by-omkarkele.lovable.app

The frontend was generated using Lovable and is being refined alongside the C++ implementation. If you have suggestions, ideas, or find any issues, feel free to reach out at theomkarkele@gmail.com.

## Documentation
- Phase 1: [docs/phase-1.md](docs/phase-1.md)
- Phase 2: [docs/phase-2.md](docs/phase-2.md) *(Work in Progress)*

## Progress
- [x] Phase 1 – Basic MOS
- [🚧] Phase 2 – Paging & Interrupt Handling *(In Progress)*
- [ ] Phase 3 – Multiprogramming & I/O Spooling

## Build & Run

Phase 1

```bash
g++ phase-1/phase1.cpp -o mos
./mos
```

Phase 2

```bash
g++ phase-2/phase2.cpp -o mos
./mos
```
(Swap the path for whichever phase you're testing.)

## About the Code
Nothing fancy here - just clear variable names and comments so it's easy to follow along, since the main goal is learning, not writing production-grade code.

## Acknowledgements
Thanks to my OS professor, Saraswati Patil Ma'am, for the guidance and teaching that made this project possible.

## License
This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.

## Academic Integrity
Feel free to use this as a reference, but if you're using it for your own coursework, make sure you actually understand what it's doing and follow your institution's academic integrity rules.