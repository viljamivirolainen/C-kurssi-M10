#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "shopfunctions.h"

int compareAlpha(const void* a, const void* b)
{
	return (strcmp(((Product *)a)->name, ((Product *)b)->name));
}

int compareNum(const void* a, const void* b)
{
	if (((Product *)a)->in_stock < ((Product *)b)->in_stock) 
	{
		return 1;
	}
	else if (((Product *)a)->in_stock == ((Product *)b)->in_stock)
	{
		return (compareAlpha(a,b));
	} else return -1;

}

const Product* findProduct(const Product* p_array, const char* search_key, int (*cmp)(const void*, const void*))
{
	int num = 0;
	while(p_array[num].name[0] != 0)
	{
		num++;
	}
	Product *key_element = malloc(sizeof(Product));
	key_element->in_stock = 0;
	key_element->price = 0.0;
	strcpy(key_element->name,search_key);
	Product *result = bsearch(key_element,p_array, num, sizeof(Product), cmp);
	free (key_element);
	return result;
}

