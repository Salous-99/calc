# calc
A simple C++ program that takes in a mathematical expression and outputs the answer.

It was written to provide a quick and easy way to do math on the command line without needing to use the calculator on the laptop.
Perfect for people who are used to working in terminal and need to do a quick calculation.

SETUP:
  - Download calc.cpp
  - Compile the cpp file natively by running this command: g++ calc.cpp -o calc
  - Move the executable to /bin (bash looks here to find the executable when you enter a command) by running this command: sudo mv calc /bin

USAGE:
  - Enter "calc" in your terminal, this will start the program and prompt you for input
  - Enter the mathematical expression you are trying to compute (for example: 2 * (-2 + 5) and press enter
  - The answer will be displayed on a new line
  - To exit the program enter the end-of-file character, for linux this is given by ctrl+D

PRACTICAL LIMITS:
  - Supports the use of parenthesis, so entering 2 * (4 - 1) will give you 6
  - The placement of spaces does not matter which means that 2 + 4 * -1 will give the same answer as 2+4*-1
  - Supports usage of floating point numbers so 12.51 + 1.2 will give you 12.71
  - Supports negative numbers
  - Supported operations are:
    > addition (+)
    > subtraction (-)
    > multiplication (*)
    > division (/)
    > power (^)
    > modulus (%) -> only supported for integers. If a floating point number is used, it will be cast as an integer (so 6.8 % 5 is equivalent to 6 % 5) 
