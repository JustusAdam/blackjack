#include "CCourse6.h"

int main(){
	int i;
	card deckarray[32]; makedeck(deckarray);
	for(i=0;i<32;i++){
		printname(deckarray[i].name);
		printf(" of ");
		printcolor(deckarray[i].color);
		printf("  %i points\n",deckarray[i].cardvalue);
	}
	deck standart[32]; 
	filldeck(deckarray, standart);
	deck *first = &standart[0];
	card mycard = *drawncard(&first,10);
	printcolor(mycard.color); printf("\n");
	printname(mycard.name);
	//printf("%d\n",standart[5].nextcard -> thiscard -> cardvalue);
	
	
	return 0;
}
void printcolor(value){
	switch (value){
		case 0: printf("Hearts"); break;
		case 1: printf("Diamonds"); break;
		case 2: printf("Clubs"); break;
		case 3: printf("Spades"); break;
	}
}
void printname(value){
	switch (value){
		case 3: printf("Jack"); break;
		case 4: printf("Queen"); break;
		case 5: printf("King"); break;
		case 6: printf("Ace"); break;
		case 7: printf("Seven"); break;
		case 8: printf("Eight"); break;
		case 9: printf("Nine"); break;
		case 10: printf("Ten"); break;}
}

void makedeck(card* k){
	int i,o;
	for(i=0;i<4;i++){
		for (o=0;o<8;o++){
			int position = i*8 + o;
			k[position].color = i ;
			k[position].name = o +3 ;
			if (k[position].name >= 7) k[position].cardvalue = k[position].name;
			else if (k[position].name == 6) k[position].cardvalue = 11;
			else k[position].cardvalue = 10; 
		}
	}
}
void filldeck(card* origin, deck* standart){
	int i;
	for(i=32;i>=0;i--){
		standart[i].nextcard = &standart[i + 1];
		standart[i].thiscard = &origin[i];	
	}
	standart[32].nextcard = &standart[0];
}
card *drawncard(pointer *metastandart, int number){
	deck *standart = *metastandart;
	if(standart -> nextcard == NULL){printf("NULL"); return NULL;}
	else if(standart == standart -> nextcard){
		standart -> nextcard = NULL;
		return standart -> nextcard -> thiscard;
		}
	else if(number != 0){ 
		*metastandart = standart -> nextcard;
		return drawncard(metastandart, number - 1);
	}
	else {
		standart -> nextcard = standart -> nextcard -> nextcard;
		return standart -> nextcard -> thiscard;
	}
}
