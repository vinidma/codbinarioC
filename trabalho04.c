#include<stdio.h>
#include<locale.h>
#include<stdbool.h>
#include<string.h>


struct perso {
    char nome[20];
    bool evolucao;
    int quantClasses;
    };
    

int main(){
	
setlocale(LC_ALL, "Portuguese");
    
int t = 2;
int i;
struct perso vet[t];

FILE *trabalho04;
trabalho04 = fopen("arqBinario.txt", "wb");

printf("Digite a entrada de %d personagens: \n", t);

for (i = 0; i < t; i++) {
    printf("Digite o nome do Personagem %d \n", i+1);
    fgets(vet[i].nome, 20, stdin);
    strtok(vet[i].nome, "\n");

    printf("Diga se o Personagem tem evolu��es (1 - Sim  2 - N�o): \n", i+1);
    scanf("%d", &vet[i].evolucao);

    printf("Diga quantas evolu��es o Personagem tem:\n");
    scanf("%d", &vet[i].quantClasses);
    
    
    while(getchar() != '\n');
    
      fwrite(&vet[i], sizeof(vet[i]), 1, trabalho04);
    }
//    
//for (i = 0; i < t; i++) {
//    if (vet[i].evolucao == 1) {
//        printf("O Personagem %s possui %d evolu��o. O nome da classe � %s:\n", vet[i].nome, vet[i].quantClasses, vet[i].qualClasse);
//        }
//    else {
//        printf("O Personagem %s nao possui evolu��o.\n", vet[i].nome);
//        }
//    }
//  
  fclose (trabalho04);
  
printf ("Digite o numero do Personagem para mais informa��es:\n");
scanf("%d", &t);
printf("O Personagem %s possui %d evolu��es de classe.\n", vet[t].nome, vet[t].quantClasses);

  
    }

