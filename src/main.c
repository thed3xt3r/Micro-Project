#include <reg51.h>
#include <stdio.h>

int check_amount(int *choice, int *amount)
{
	int price[] = {20,10,5};
	int change = *amount - price[*choice-1];
	
	if (change < 0) return -1;
	
	puts("Sold");
	
	return change;
}

void main() {
	SCON  = 0x50;
	TMOD |= 0x20;
	TH1   = 0xf3;
	TR1   = 1;
	TI    = 1;
	
	puts("Choose a chocolate already!");
	
	while(1) {
		int c, a, r;
		
		scanf("%d", &c);
		
		switch(c) {
			case 1:
				puts("You chose Perk");
				break;
			case 2:
				puts("You chose 5-Star");
				break;
			case 3:
				puts("You chose Toblerone");
				break;
			default:
				puts("Wrong choice mate");
		}
		
		puts("Enter amount: ");
		scanf("%d", &a);
		r = check_amount(&c, &a);
		puts("Done!");
	}
}