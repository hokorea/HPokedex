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

void printMenu(void);
void printPokedexList(Pokemon pokedex[], int pokemon_count);
void printPokemonInfo(Pokemon pokemon);

int main(void){
	Pokemon pokedex[MAX_POKEMON];
	int pokemon_count = 3;
	int choice = 0;

	while(1){
		printMenu();

		printf("> ");
		scanf("%d", &choice);

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

		if(choice == 1){
			printPokedexList(pokedex, pokemon_count);
		}
		else if(choice == 2){
			int number;
			int found = 0;

			printf("도감 번호 입력 : ");
			scanf("%d", &number);

			for(int i = 0; i < pokemon_count; i++){
				if(pokedex[i].number == number){
					printPokemonInfo(pokedex[i]);
					found = 1;
					break;
				}
			}
			if(found == 0){
				printf("해당 포켓몬이 존재하지 않습니다.\n");
			}
		}
		else if(choice == 3){
			printf("HPokedex 종료!\n");
			break;
		}
	}
	
	return 0;
}

void printMenu(void){
	printf("\n=== HPokedex ===\n");
	printf("1. 도감 목록 보기\n");
	printf("2. 포켓몬 상세 보기\n");
	printf("3. 종료\n");
}

void printPokedexList(Pokemon pokedex[], int pokemon_count){
	for(int i = 0; i < pokemon_count; i++)
		printf("%04d %s\n", pokedex[i].number, pokedex[i].name);
}

void printPokemonInfo(Pokemon pokemon){
	printf("\nNo.%04d %s\n", pokemon.number, pokemon.name);
	printf("분류 : %s포켓몬\n", pokemon.category);
	if(strlen(pokemon.type2) == 0)
		printf("타입 : %s\n", pokemon.type1);
	else
		printf("타입 : %s / %s\n", pokemon.type1, pokemon.type2);
	printf("키 : %.1fm\n", pokemon.height);
	printf("몸무게 : %.1fkg\n", pokemon.weight);
	printf("\n설명\n%s\n", pokemon.description);
}
