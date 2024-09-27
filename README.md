# 0x19. C - Stacks, Queues - LIFO, FIFO

## Description
This project focuses on the implementation of stacks and queues using the Last-In-First-Out (LIFO) and First-In-First-Out (FIFO) concepts. It involves creating an interpreter for Monty ByteCodes files, where Monty is a scripting language that operates on a unique stack structure.

### Group Members:
- **Sam Salimu**
- **Dzeble Frank Kwame**

### Project Start: 
September 24, 2024, 6:00 PM

### Deadline: 
September 27, 2024, 6:00 PM

### Weight:
2

---

## Learning Objectives
By the end of this project, you should be able to explain the following concepts without any external help:

- The meanings of LIFO and FIFO
- The definition of stacks and queues, and when to use each
- Common implementations of stacks and queues
- Common use cases for stacks and queues
- Proper ways to use global variables

## Resources
For additional learning, please refer to the following resources:
- [Google](https://www.google.com)
- How to use `extern` to share variables between source files in C
- Stacks and Queues in C
- Stack operations and Queue operations

---

## Requirements

### General
- Use the allowed editors: `vi`, `vim`, or `emacs`.
- All code will be compiled on Ubuntu 20.04 LTS using `gcc` with the flags: `-Wall -Werror -Wextra -pedantic -std=c89`.
- All files must end with a new line.
- Your code should follow the Betty coding style, which will be checked using `betty-style.pl` and `betty-doc.pl`.
- You are allowed to use only **one global variable**.
- No more than **five functions per file**.
- Use of the C standard library is allowed.
- All function prototypes should be included in a header file named `monty.h`.
- All header files must be include-guarded.
- The project tasks must be completed in the order presented.

### Compilation and Execution
The program will be compiled with:
```bash
gcc -Wall -Werror -Wextra -pedantic -std=c89 *.c -o monty


/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
    int n;
    struct stack_s *prev;
    struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
    char *opcode;
    void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;


Project Tasks
push, pall

Description: Implement the push and pall opcodes.
Details: The push opcode adds an element to the stack. The pall opcode prints all the values in the stack from the top.
pint

Description: Implement the pint opcode.
Details: Prints the value at the top of the stack.
pop

Description: Implement the pop opcode.
Details: Removes the top element of the stack.
swap

Description: Implement the swap opcode.
Details: Swaps the top two elements of the stack.
add

Description: Implement the add opcode.
Details: Adds the top two elements of the stack and stores the result in the second top element, then removes the top element.
nop

Description: Implement the nop opcode.
Details: The nop opcode does nothing.
Error Handling
If no file or more than one argument is passed to the program, it should print USAGE: monty file and exit with status EXIT_FAILURE.
If the file can't be opened, it should print Error: Can't open file <file>, followed by a new line, and exit with status EXIT_FAILURE.
If an invalid instruction is found, the program should print L<line_number>: unknown instruction <opcode>, followed by a new line, and exit with status EXIT_FAILURE.
If a malloc fails, it should print Error: malloc failed and exit with status EXIT_FAILURE.
