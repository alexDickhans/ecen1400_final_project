# Pickle Pickler
*Name inspired by Quinn Hedge*

Alex Dickhans ECEN1310 Final project

## Overview

This game is very similar to a game that many people have played before but with pickles, that you have to pickle. 

## Game objectives

Collect as many pickles as one can acquire.

Start the game by pickling until you can hire your first jr. pickler. The objects you can buy are the following with their price curves

1. Jr. Pickler, cost 15 pickles, makes 0.1 pickle/s
2. Sr. Pickler, cost 100 pickles, makes 1 pickle/s
3. Pickle Farm, cost 1,100 pickles, makes 8 pickle/s
4. Pickle Factory, cost 15k pickles, makes 100 pickles/s
5. Pickle World, cost 120k pickles, makes 1k pickle/s

## Game Interactions

All the interactions are done through the command line with a single character. 

## Documentation

### File tree (planned layout)

* `include/` — public headers  
    * `factory/factory.h` — factory create/destroy API (future: rates, tier).
    * `utils/utils.h` — UI helpers (e.g. clear screen, clean exit).  
    * `utils/help.h` — in-game help text.  
    * `player.h` - Holds player logic and controls the user's factories and balance
* `src/` — implementations matching the headers above (`main.c` entry point).

Build with `make` (see `Makefile` for objects and flags).

### Testing

Test with `make test`, builds and runs unit tests automatically.

### Memory leaks

Tested with apple's native tool `leaks` and no leaks were found during this testing!
