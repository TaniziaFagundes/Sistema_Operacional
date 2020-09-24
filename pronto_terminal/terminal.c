#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

int main(int argc, char *argv[]){
    printf("hello world (pid:%d)\n", (int) getpid());
    int i=0;
    char sFrase[50];
    char *palavra[5];
    scanf("%[^\n]",sFrase);  

    char *psRetorno;
    

   // Primeiro busca por espaço em branco.
    psRetorno = strtok(sFrase, " "); //pega a primeira palavra antes do espaço

    //printf("\npsRetorno = %s", psRetorno);

    while (psRetorno != NULL)
    {
        palavra[i++]=psRetorno;
        psRetorno = strtok(NULL," ");  //faz todos os espaços serem nulos
    }palavra[i] = NULL; //insere NULL no ultimo elemento do vetor;

    /* TESTE
    printf("\nFrase = %s", sFrase);
    printf("\nPalavra = %s", palavra[0]);
    printf("\nPalavra = %s", palavra[1]);
    printf("\nPalavra = %s", palavra[2]);
    */
    
    int rc = fork();
    if (rc < 0) {// fork falhou
        fprintf(stderr, "fork falhou\n");
        exit(1);
    } else if (rc == 0) { // filho
       
    } else{// Pai vem por aqui
        
    }
    return 0;
}