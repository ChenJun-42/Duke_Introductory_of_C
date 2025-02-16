#include "cards.h"
#include <stdio.h>

int main() {
	card_t c = card_from_letters('A', 's');
	print_card(c);
	printf("\n");

	card_t c2 = card_from_num(51);
	print_card(c2);
	printf("\n");

	return 0;
}
