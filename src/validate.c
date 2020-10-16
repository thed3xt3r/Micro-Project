#include <string.h>
#include <stdio.h>

int check_amount(int *choice, int *amount)
{
	int price[] = {20,10,5};
	int change = *amount - price[*choice-1];
	
	char *msg;
	strcpy(msg, "The change is: ");
	strncat(msg, (char *)change, 1);
	puts(msg);
	
	if (change < 0) return -1;
	
	return change;
}
