# This project has been created as part of the 42 curriculum by echarmai

# so_long

## Description

**so_long** is a small 2D game project developed in C using the **MiniLibX** graphical library.  
The goal of the project is to create a simple top-down game where the player must collect all collectibles on the map and then reach the exit to win.

The game is based on a map file describing walls, empty spaces, collectibles, the player’s starting position, and the exit.  
The project focuses on graphical rendering, event handling, memory management, and strict map validation.

---

## Instructions

# Requirements
- GNU/Linux or WSL
- `gcc`
- `make`
- MiniLibX (provided by 42)

# Compilation

Clone the repository and compile the project using:

```bash
make

# Execution

./so_long maps/example.ber

# Controls

W A S D key's to move the player 
ESC key's to close the window

# Map Rules

Be rectangular
Be surrounded by walls
Contain 1 player
Contain 1 exit
Contain at least 1 collectible
Contain only valid characters (1, 0, P, E, C)
be solvable

# Library description

usage of minilibX, a lightweight graphical library provided by 42
used to :
Create and manage window
Load and display images (XPM)
Handle keyboard and window events
Render game elements in real time
