#ifndef AALTO_SHOP_FUNCTIONS_H
#define AALTO_SHOP_FUNCTIONS_H

typedef struct {
	char name[31];
	float price;
	int in_stock;
} Product;


/* Compare two strings lexically (ASCII value-wise, same as strcmp())
 * The string "duck" is before "rabbit" in this order but
 *  "Rabbit" is before "duck" (see an ASCII chart)
 * IMPORTANT: Note that the parameters are ** and not *
 *  this is because qsort and bsearch operate on pointers to data.
 * Thus, when data is char*, a pointer to this data is char**.
 * Returns: 0 if the two strings are equal
 *          <0 if r > l
 *          >0 if l > r
 * Hint: strcmp
 */
int compareAlpha(const void* a, const void* b);

/* Same as compareAlpha but compares the product *in_stock* numerically.
 * If there are two or more products with same *in_stock* -value, they are compared lexically.
 */
int compareNum(const void* a, const void* b);

/* Finds a product from a sorted array of products
 * Returns: Whatever bsearch returned.
 * IMPORTANT: Remember that bsearch takes a pointer to a type as first parameter, and 
 * pointer to an array with same type elements as in first parameter.
 */
const Product* findProduct(const Product* p_array, const char* search_key, int (*cmp)(const void*, const void*));


#endif /* AALTO_SHOP_FUNCTIONS_H */
