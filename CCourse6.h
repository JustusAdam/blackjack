#include <stdio.h>

enum cardtype {HEART,DIAMOND,CLUB,SPADE};
enum cardclass {JACK = 3,QUEEN,KING,ACE, SEVEN,EIGHT,NINE,TEN};

typedef struct cards{
	enum cardtype color;
	enum cardclass name;
	int cardvalue;
	} card;

void makedeck(card* k);
//card nextCard(enum cardtype color, enum cardclass name);

