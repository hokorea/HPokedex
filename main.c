#include <stdio.h>
#include <string.h>

#define MAX_POKEMON 151

typedef struct{
	int number;
	char name[16];
	char type1[16];
	char type2[16];
	char category[32];
	float height;
	float weight;
	char description[512];
} Pokemon;

void printPokedexList(Pokemon pokedex[], int pokemon_count);

int main(void){
	Pokemon pokedex[MAX_POKEMON];
	int pokemon_count = 3;

	Pokemon bulbasaur = {
		1, "이상해씨",
		"풀", "독", "씨앗", 0.7, 6.9, 
		"태어났을 때부터 등에 식물의 씨앗이 있으며 조금씩 크게 자란다."
	};
	Pokemon charmander = {
		4, "파이리",
		"불꽃", "", "도마뱀", 0.6, 8.5,
		"태어날 때부터 꼬리에 불꽃이 타오르고 있으며 불꽃이 꺼지면 생명이 위험해진다."
	};
	
	Pokemon squirtle = {
		7, "꼬부기",
		"물", "", "꼬마거북", 0.5, 9.0,
		"위험을 느끼면 등껍질 안에 몸을 숨기고 입에서 물을 뿜어 공격한다."
		};
	
	pokedex[0] = bulbasaur;
	pokedex[1] = charmander;
	pokedex[2] = squirtle;
	
	printf("HPokedex Start!!!\n");

	printPokedexList(pokedex, pokemon_count);
	
	return 0;
}

void printPokedexList(Pokemon pokedex[], int pokemon_count){
	for(int i = 0; i < pokemon_count; i++)
		printf("%04d %s\n", pokedex[i].number, pokedex[i].name);
}
