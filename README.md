# Get Next Line

[![SUCCESS](https://i.postimg.cc/NM792Qfc/Screen-Shot-2023-12-03-at-9-39-23-AM.png)](https://postimg.cc/9R0Fv578)

## Project Overview

This project focuses on implementing a function named `get_next_line` in the C programming language. The function is designed to read a line from a file descriptor (`fd`). The project introduces the use of static variables and aims to provide a convenient way to read text from a file or standard input one line at a time.

## Table of Contents

- [Goals](#goals)
- [Common Instructions](#common-instructions)
- [Mandatory Part](#mandatory-part)
- [Bonus Part](#bonus-part)
- [Submission and Peer-Evaluation](#submission-and-peer-evaluation)

## Goals

This project serves two main goals:

1. **Functionality Enhancement:** Adding a convenient function (`get_next_line`) to the developer's toolkit for reading lines from a file descriptor.
2. **Learning Concept:** Introducing the concept of static variables in C programming.

## Common Instructions

The project follows certain common instructions to ensure consistency and reliability:

- Written in C.
- Compliance with the Norm to avoid norm errors during evaluation.
- Avoid unexpected program terminations (segmentation fault, bus error, etc.).
- Proper memory management to prevent memory leaks.
- Submission of a Makefile to compile source files with specified flags.
- Encouragement to create test programs for better code validation.

## Mandatory Part

### Function: `get_next_line`

- Prototype: `char *get_next_line(int fd);`
- Files to submit: `get_next_line.c`, `get_next_line_utils.c`, `get_next_line.h`
- Parameters: `fd` - File descriptor to read from
- Return value:
  - Read line: correct behavior
  - `NULL`: Nothing else to read, or an error occurred
- External functions: `read`, `malloc`, `free`

**Description:**

- Repeated calls to `get_next_line()` should let you read the text file pointed to by the file descriptor, one line at a time.
- The function should return the line that was read.
- If there is nothing else to read or if an error occurred, it should return `NULL`.
- Works with both file and standard input.
- The returned line should include the terminating `\n` character, except if the end of file was reached and does not end with a `\n` character.
- Header file `get_next_line.h` must contain the prototype of the `get_next_line()` function.
- Helper functions should be added in the `get_next_line_utils.c` file.

**Compiler Option:**

- Add the option `-D BUFFER_SIZE=n` to the compiler call, where `n` defines the buffer size for `read()`.

**Additional Notes:**

- `get_next_line()` has undefined behavior if the file pointed to by the file descriptor changed since the last call whereas `read()` didn't reach the end of file.
- Undefined behavior when reading a binary file.
- Implement a logical way to handle the behavior if desired.

**Forbidden:**

- Use of `libft`.
- `lseek()` is forbidden.
- Global variables are forbidden.

## Bonus Part

This part aims to add further complexity and challenge to the project:

- Develop `get_next_line()` using only one static variable.
- `get_next_line()` should manage multiple file descriptors simultaneously.
- The bonus part will only be assessed if the mandatory part is perfect.

**Bonus Files to Submit:**

- `get_next_line_bonus.c`
- `get_next_line_bonus.h`
- `get_next_line_utils_bonus.c`

## Submission and Peer-Evaluation

- Submit the assignment to the assigned Git repository.
- Only the work inside the Git repository will be evaluated during the defense.
- Double-check file names for correctness.
- When creating tests, consider diverse values for both buffer size and line size.
- A file descriptor does not only point to regular files, so ensure comprehensive testing.

**Note:** After passing, consider adding `get_next_line()` to your `libft`.

Feel free to reach out for clarification or assistance during the development process. Good luck with your project!
