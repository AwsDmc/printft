*This activity has been created as part of the 42 curriculum by abaoni.*

## Description
This project is a custom implementation of the standard C library function `printf`. The goal is to learn how to handle variadic arguments (functions that take a variable number of parameters).

The function `ft_printf` mimics the real `printf` behaviors for the following conversions:
* `%c`: Prints a single character.
* `%s`: Prints a string.
* `%p`: Prints a void * pointer in hexadecimal format.
* `%d` / `%i`: Prints a decimal (base 10) number.
* `%u`: Prints an unsigned decimal (base 10) number.
* `%x`: Prints a number in hexadecimal (base 16) lowercase format.
* `%X`: Prints a number in hexadecimal (base 16) uppercase format.
* `%%`: Prints a percent sign.

## Instructions

### Compilation
The project uses a Makefile to compile the library `libftprintf.a`.
1.  Run `make` to compile.
2.  Run `make clean` to remove object files.
3.  Run `make fclean` to remove object files and the library.
4.  Run `make re` to re-compile everything.

### Usage
To use this in your code:
1.  Include the header: `#include "ft_printf.h"`
2.  Compile your file with the library:
    `cc -Wall -Werror -Wextra main.c libftprintf.a`
3.  Run your program:
    `./a.out`

## Resources

* **Manuals:** `man 3 printf` and documentation for `<stdarg.h>`.
* **AI Usage:** AI was used in this project to help clarify specific edge cases (such as handling NULL pointers), to check the logic for the Makefile, and to verify the recursive logic for hexadecimal conversion.

## Algorithm and Data Structures

### Data Structure: `va_list`
The main data structure used is `va_list` from the `<stdarg.h>` library. Since `ft_printf` does not know how many arguments it will receive beforehand, `va_list` allows the program to access arguments one by one as they are needed during the printing process.

### Algorithm
The logic follows a simple linear parsing approach:
1.  **Iterate:** The function loops through the format string one character at a time.
2.  **Check:** If the character is `%`, it looks at the next character to decide what to do.
3.  **Dispatch:** Based on the type (e.g., `s`, `d`, `x`), it calls a specific helper function (like `ft_print_str` or `ft_print_hex`).
4.  **Recursion:** For printing numbers (decimals and hexadecimals), a recursive function is used. The number is divided by the base (10 or 16) repeatedly until it is reduced to a single digit, which is then printed. This avoids using complex arrays or buffers.
