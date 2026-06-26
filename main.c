#include <stdio.h>
#include <string.h>
#include <stdlib.h>

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

void clearScreen(void);
void printTitle(void);
void pauseScreen(void);
void printMenu(void);

int loadPokedexFromCSV(Pokemon pokedex[], const char *filename);

void printPokedexList(Pokemon pokedex[], int pokemon_count);
void printPokemonInfo(Pokemon pokemon);

int main(void){
	Pokemon pokedex[MAX_POKEMON];
	int pokemon_count = 3;
	int choice = 0;

	while(1){
		clearScreen();
		printMenu();
		scanf("%d", &choice);

		if(choice == 1){
			clearScreen();
			printTitle();
			printPokedexList(pokedex, pokemon_count);
			pauseScreen();
		}
		else if(choice == 2){
			clearScreen();
			printTitle();
			int number;
			int found = 0;

			printf("도감 번호 입력 : ");
			scanf("%d", &number);

			clearScreen();
			printTitle();

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
			pauseScreen();
		}
		else if(choice == 3){
			printf("HPokedex 종료!\n");
			break;
		}
	}
	
	return 0;
}

void clearScreen(void){
	system("clear");
}

void printTitle(void){
	printf("+----------------------------+\n");
	printf("|        H Pokedex           |\n");
	printf("+----------------------------+\n");
}

void pauseScreen(void){
	printf("\nEnter를 누르면 계속합니다...");
	(void)getchar();
	(void)getchar();
}

void printMenu(void){
	printTitle();
	printf("| 1. 도감 목록 보기          |\n");
	printf("| 2. 번호 검색               |\n");
	printf("| 3. 종료                    |\n");
	printf("+----------------------------+\n");
	printf("> ");
}

int loadPokedexFromCSV(Pokemon pokedex[], const char *filename){
	
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
