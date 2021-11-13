# Simple Chess AI

The projects uses the `ncurses` API to manage all terminal GUI, and I am not exactly sure that I did things exactly right since I am very novice in terms of `ncurses`, however it seems like the program does the job, at least in my machine. Note that the project is still in development.

## Installation

Use the following commands to pull and build the project:
```bash
git pull https://github.com/ehurturk/chessai.git
cd chessai
g++ src/main.cpp -o main -Iinclude/engine.h src/engine.cpp -Iinclude/term.h src/term.cpp -lncurses -Wall -g
```
And just run the `main` binary output to run the program.

## Roadmap + TODO
- [x] Game UI
- [ ] Game mechanics (currently being worked on)
- [ ] Game AI

Thanks for being interested in.
