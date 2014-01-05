#include <stdio.h>
#include <stdlib.h>
#include <time.h>

enum cardtype {HEART,DIAMOND,CLUB,SPADE};
enum cardclass {JACK = 3,QUEEN,KING,ACE, SEVEN,EIGHT,NINE,TEN};

typedef struct cards{
	enum cardtype color;
	enum cardclass name;
	int cardvalue;
} card;

typedef struct deck *pointer;
typedef struct deck{
	card *thiscard;
	pointer nextcard;
} deck;

void makedeck(card* k);
void printname(int value);
void printcolor(int value);
void filldeck(card *origin, deck *standart);
card *drawncard(pointer *metastandart, int number);
