#include "CCourse6.h"

int main(){
	int i;
	card deck[32]; makedeck(deck);
	for(i=0;i<32;i++){
		printf("%i %i\n",deck[i].color,deck[i].name);
	}
	
	
	return 0;
}

void makedeck(card* k){
	int i,o;
	for(i=0;i<4;i++){
		for (o=0;o<8;o++){
			int position = i*8 + o;
			k[position].color = i ;
			k[position].name = o +3 ;
			
		}
	}

	}

/*card nextCard(enum cardtype color, enum cardclass name){
	card.color = color;
	card.name = name;
	}*/
