### Task 10.1: Macros (20 pts)

**Objective:** Practice use of parametrized macros.

This exercise does not contain other *.c files than
**main.c**. Instead, the relevant code you'll
need to implement is in **macros.h** header, where you need to
place the following two macros:

**Exercise (a): EQ3(a,b,c)** takes three parameters and evaluates their
  equality. Evaluates to 1 if all parameters are equal (==) to each other.
  Evaluates to 0 otherwise. May evaluate any parameter more than once.

**Exercise (b): MIN3(a,b,c)** that evaluates which one of the parameters is
  smallest. Returns the smallest one.

**Hint:** Use the *[ternary](https://en.wikipedia.org/wiki/%3F:#C)* operator
instead of if-else.
