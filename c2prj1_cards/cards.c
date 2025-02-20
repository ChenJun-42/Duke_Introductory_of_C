#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include "cards.h"


void assert_card_valid(card_t c) {
  assert(c.value >= 2 && c.value <= VALUE_ACE);
  assert(c.suit >= SPADES && c.suit <= CLUBS);
}

const char * ranking_to_string(hand_ranking_t r) {
  switch (r){
    case STRAIGHT_FLUSH:
	    return "STRAIGHT_FLUSH";
    case FOUR_OF_A_KIND: 
	    return "FOUR_OF_A_KIND";
    case FULL_HOUSE: 
	    return "FULL_HOUSE";
    case FLUSH: 
	    return "FLUSH";
    case STRAIGHT: 
	    return "STRAIGHT";
    case THREE_OF_A_KIND: 
	    return "THREE_OF_A_KIND";
    case TWO_PAIR: 
	    return "TWO_PAIR";
    case PAIR: 
	    return "PAIR";
    case NOTHING: 
	    return "NOTHING";
    default: 
	    return "Unknown Ranking";
  }
}

char value_letter(card_t c) {
  if (c.value >= 2 && c.value <= 9) return ('0' + c.value);
  switch (c.value)
  {
  case 10: return '0';
  case VALUE_JACK: return 'J';
  case VALUE_QUEEN: return 'Q';
  case VALUE_KING: return 'K';
  case VALUE_ACE: return 'A';
  default: return '?';
  }
}


char suit_letter(card_t c) {
  switch (c.suit)
  {
  case SPADES: return 's';
  case HEARTS: return 'h';
  case DIAMONDS: return 'd';
  case CLUBS: return 'c';
  default: return '?';
  }
}

void print_card(card_t c) {
printf("%c%c", value_letter(c), suit_letter(c));
}

card_t card_from_letters(char value_let, char suit_let) {
  card_t c;
  switch (value_let){
    case '2': c.value = 2; break;
    case '3': c.value = 3; break;
    case '4': c.value = 4; break;
    case '5': c.value = 5; break;
    case '6': c.value = 6; break;
    case '7': c.value = 7; break;
    case '8': c.value = 8; break;
    case '9': c.value = 9; break;
    case '0': c.value = 10; break;
    case 'J': c.value = VALUE_JACK; break;
    case 'Q': c.value = VALUE_QUEEN; break;
    case 'K': c.value = VALUE_KING; break;
    case 'A': c.value = VALUE_ACE; break;
    default: assert(0);
  }
  switch (suit_let)
  {
  case 's': c.suit = SPADES; break;
  case 'h': c.suit = HEARTS; break;
  case 'd': c.suit = DIAMONDS; break;
  case 'c': c.suit = CLUBS; break;
  default: assert(0);
  }
  return c;
}

card_t card_from_num(unsigned c) {
  card_t temp;
  assert(c < 52);
  temp.value = (c % 13) + 2;
  temp.suit = c / 13;
  return temp;
}
