### Task 10.2: Printer (25 pts)

**Objective**: Learn variable length argument lists

Implement function `int myprint(const char *str, ...)` that prints a variable number of
integers to standard output stream following the format indicated by a
given format string. The function can take variable number of
arguments: **the first argument is always a (constant) format string**
(as in *printf*), but the number of other arguments depends on the
format string. Our output function is a simpler version of *printf*:
it can only print integers. *myprint* differs from traditional
*printf* by using character `&` as the format specifier that should be
substituted by the integer indicated at the respective position in the
argument list. Because we only output integers, this simple format
specifier will suffice.

For example, this is one valid way of calling the function:
`myprint("Number one: &, number two: &\n", 120, 1345);`

**The function should return an integer**, that indicates how many
  format specifiers (and integer arguments) were included in the given
  format string.

If your implementation works correctly, the main function will output the
following:

    Hello!
    Number: 5
    Number one: 120, number two: 1345
    Three numbers: 12 444 5555
    I just printed 3 integers

**Hint:** As a reminder,
*[strchr](http://www.cplusplus.com/reference/cstring/strchr/?kw=strchr)* will
return pointer to the next instance of given character from a string, and
*[fputc](http://www.cplusplus.com/reference/cstdio/fputc/?kw=fputc)* will output
one character at a time. You may or may not want to use these
functions.
