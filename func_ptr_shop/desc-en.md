### Task 10.3: Function pointers (20 pts)

**Object**: Practise the function pointers using standard functions qsort and
bsearch.

The object of this task is to practise the use of two standard function pointers;
qsort and bsearch. As a help we use the same scheme as in last round's task "Shop".
This time the shopkeeper should implement a system, which allows them to sort
their products alphabetically or sort them in descending order depending on how
many products are in stock. The product structrure is implemented the same way
as in the last round so that the last element's name's first character is the
terminating null character (\\0).

In this task you must implement two comparing functions and a search function;
**compareAlpha**, **compareNum** and **findProduct**.

**int compareAlpha(const void* a, const void* b)** function compares the given
Product parameters (**a** and **b**) by their **name** fields. The comparison
is done according to their ASCII values, which means you can use the strcmp
funktion. The function returns the value returned by strcmp. Note that the
parameters are of type **const void ***.

**int compareNum(const void* a, const void* b)** function compares the **in_stock**
fields of the Product parameters. Numerically larger should come first in the
ordering. The function returns a negative number if **b** should be after **a**
in the ordering and a positive number in the opposite case. If the two values
are the same, the ordering is determined by compareAlpha.

**const Product* findProduct(const Product* p_array, const char* searchkey, int (\*cmp)(const void\*, const void\*))**
function find one product from the sorted **Product** array. You are supposed to
use the bsearch function and return the value returned by bsearch. The given
**searchkey** is the name of the product to be found. It cannot be given directly
to the bsearch function because bsearch requires that the element to be found
is of the same type as the elements in the array.

The interfaces of these functions are explained in the header file.
A small testing program is given with **main.c** and the function
declarations and the interfaces explained in the **shopfunctions.h** header file.

You should read how bsearch works from here:
**[bsearch](http://www.cplusplus.com/reference/cstdlib/bsearch/)**

When the program is coded correctly, the output of the main function should be as
shown.

    sorted lexically:
    product: bread price: 2.700000 in stock: 12
    product: butter price: 4.200000 in stock: 5
    product: cereals price: 3.200000 in stock: 12
    product: cookies price: 12.300000 in stock: 23
    product: peanut butter price: 1.200000 in stock: 5
    Found product:
    cookies
    Product not found!
    sorted by in stock:
    product: cookies price: 12.300000 in stock: 23
    product: bread price: 2.700000 in stock: 12
    product: cereals price: 3.200000 in stock: 12
    product: butter price: 4.200000 in stock: 5
    product: peanut butter price: 1.200000 in stock: 5

**Hints**

- Remember, that bsearch takes a pointer to a single data type as its first
parameter, and the second parameter should be a list which consists of the same
type of data types.
- Recall that you cannot get the length of the array by using sizeof(array-pointer),
because this only returns the size of the pointer itself, not the length of the array.
