#include<stdio.h>
#include<locale.h>
#include<stdbool.h>
#include<string.h>
#include<stdlib.h>

struct perso {
    char nome[20];
    bool evolucao;
    int quantClasses;
    };
    

int main(){
	
setlocale(LC_ALL, "Portuguese");
    
int t = 2;
int p;
int i;
struct perso vet[t];

FILE *trabalho04;
trabalho04 = fopen("arqBinario.txt", "rb+");

///////////////////////////EDITAR ENTRADA////////////////////////////////////////////////////

int y=0;
    while(fread(&vet[i], sizeof(vet[i]), 1, trabalho04)){
    printf("ID: %d\n Nome: %s\n Tem evolucao?: (1 - Sim  2 - Não) %d\n Quantas classes possui?: %d\n", y, vet[i].nome, vet[i].evolucao, vet[i].quantClasses);
    y++;
    }

    printf("Digite o identificador do personagem que deseja modificar:\n");
    scanf("%d", &y);
    getchar();
    
    printf("Digite o novo nome do personagem: \n");
    scanf("%s", vet[i].nome);
    
    printf("Digite se ele evolui: (1 - Sim  2 - Não) \n");
    scanf("%d", &vet[i].evolucao);
    
    printf("Digite quantas classes ele tem: \n");
    scanf("%d", &vet[i].quantClasses);
    
    fseek(trabalho04, y * sizeof(vet[i]), SEEK_SET);
    
    fwrite(&vet[i], sizeof(vet[i]), 1, trabalho04);

	fclose(trabalho04);

///////////////////////////ADICIONAR NOVA ENTRADA////////////////////////////////////////////////////
trabalho04 = fopen("arqBinario.txt", "ab+");

struct perso novoPersonagem;
printf("\n NOVO PERSONAGEM ? (1 - Sim  2 - Não)\n");
scanf("%d", &p);



if (p==1){
printf("\n Digite o nome do novo personagem: \n");
scanf("%s", novoPersonagem.nome);

printf("Digite se ele evolui:(1 - Sim  2 - Não) \n");
scanf("%d", &novoPersonagem.evolucao);

printf("Digite quantas classes ele tem: \n");
scanf("%d", &novoPersonagem.quantClasses);

fseek(trabalho04, 0, SEEK_END);
fwrite(&novoPersonagem, sizeof(novoPersonagem), 1, trabalho04);
}

else {

printf("\n Ok, pedido aceito. "); 
}
fclose(trabalho04);

/////////////////////////////DELETAR ALGO NA ENTRADA /////////////////////////////////////////////////
//    printf("\nDeseja remover algum personagem? (1-Sim / 2-Não)\n");
//    scanf("%d", &opcao3);
//    while(getchar()!='\n');
//
//    if(opcao3==1){
//
//        trabalho04 = fopen("arqBinario.txt", "rb+");
//        fseek(trabalho04, 0L, SEEK_END);
//        int tamanho = ftell(trabalho04);
//        int num_registros = tamanho / sizeof(struct perso);
//        fclose(trabalho04);
//
//        if(num_registros==0){
//            printf("\nNão há personagens registrados\n");
//            return 0;
//        }
//    
//    printf("Digite o número correspondente ao personagem que você deseja remover: ");
//    scanf("%d", &registro);
//    while(getchar()!='\n');
//
//    if(registro<1 || registro>num_registros){
//        printf("\nOpção inválida!\n");
//        return 0;
//    }
//
//    trabalhoPokeBinario = fopen("trabalhoPokeBiAqui.txt", "r+b");
//
//    fseek(trabalhoPokeBinario, (registro-1)*sizeof(struct pokemon), SEEK_SET);
//
//    for(i=registro-1;i<num_registros-1;i++){
//        fseek(trabalhoPokeBinario, (i+1)*sizeof(struct pokemon), SEEK_SET);
//        fread(&vet[i+1], sizeof(struct pokemon), 1, trabalhoPokeBinario);
//        fseek(trabalhoPokeBinario, i*sizeof(struct pokemon), SEEK_SET);
//        fwrite(&vet[i+1], sizeof(struct pokemon), 1, trabalhoPokeBinario);
//    }
//
//    num_registros--;
//    ftruncate(fileno(trabalhoPokeBinario), num_registros*sizeof(struct pokemon));
//    fclose(trabalhoPokeBinario);
//
//    printf("\nPokémon removido com sucesso!\n");
//
//    trabalhoPokeBinario = fopen("trabalhoPokeBiAqui.txt", "rb");
//
//    for(r=0;r<num_registros;r++){
//        fread(&vet[r], sizeof(vet[r]), 1, trabalhoPokeBinario);
//        printf("\nPokémon %d:\n", r+1);
//        printf("Nome:%s, Tipo:%s, Sexo:%s\n", vet[r].nome, vet[r].tipo, vet[r].sexo);
//    }
//
//    fclose(trabalhoPokeBinario);
//
//    }else if(opcao3==2){
//       printf("\nOK, nenhum pokémon será removido.\n");
//    }else{
//    printf("\nOpção inválida!\n");
//    }
}
