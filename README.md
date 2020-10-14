# Reverse Game

## Table of Contents

- [Description](#Description)  
- [Methods/Tech](#Methods/Tech)
- [Usage](#Usage)

## Description

- This is a simple, command line game. The user is prompted to choose a "board
size", then given a list of numbers in a scrambled order. The user then chooses
a number of numbers to reverse their order. 
    - For example:
        - The board could read: "1 3 5 4 2"
        - If the user enters: 2
        - The board will be re-presented as: "3 1 5 4 2"
            - Since the user entered 2, the first 2 numbers were reversed.
- The objective of the game is to have a board completely in order:
    - In the example, a winning board would be: "1 2 3 4 5"

## Methods/Tech

- This project was created in the C language, using:
    - stdio.h, stdlib.h, and time.h header files
    - clang compiler

## Usage

- Download or copy the source code: reverse.c
- After compiling, run the program on the command line and follow the game prompts.

### Have fun!