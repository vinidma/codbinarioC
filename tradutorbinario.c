#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>

struct perso {
    char nome[20];
    bool evolucao;
    int quantClasses;
    } ;
    
int i;

int main(){
	
int t = 2;
struct perso vet[t];

FILE *trabalho04;
trabalho04 = fopen("arqBinario.txt", "rb");


for (i = 0; i < t; i++) {
    (fread(&vet[i], sizeof(vet[i]), 1, trabalho04));{
    printf("%s, %d, %d\n", vet[i].nome, vet[i].evolucao, vet[i].quantClasses);

    if (vet[i].evolucao == 1) {
        printf("O personagem %s possui %d evolucoes.\n", vet[i].nome, vet[i].quantClasses);
        }
    else {
        printf("O personagem %s nao possui evolucao.\n", vet[i].nome);
        }
}

}

fclose(trabalho04);


}

