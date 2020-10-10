#include <reg51.h>
#include <stdio.h>

void main() {
	SCON  = 0x50;                   /* SCON: mode 1, 8-bit UART, enable rcvr    */
	TMOD |= 0x20;                   /* TMOD: timer 1, mode 2, 8-bit reload      */
	TH1   = 0xf3;                   /* TH1:  reload value for 2400 baud         */
	TR1   = 1;                      /* TR1:  timer 1 run                        */
	TI    = 1;                      /* TI:   set TI to send first char of UART  */

	
	puts("Choose a chocolate already!");
	
	while(1) {
		unsigned int choice;
		unsigned int amount;
		
		scanf("%d", &choice);
		
		switch(choice) {
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
		scanf("%d", &amount);
		
		puts("You are rich mate");
	}
}