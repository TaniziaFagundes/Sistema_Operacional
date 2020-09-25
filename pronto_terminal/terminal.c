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
    psRetorno = strtok(sFrase, " "); //pega a primeira palavra antes do espaço


    while (psRetorno != NULL)
    {
        palavra[i++]=psRetorno;
        psRetorno = strtok(NULL," ");  //faz todos os espaços serem nulos
    }palavra[i] = NULL; //insere NULL no ultimo elemento do vetor;


    
    if(palavra[1] == "|"){
        // faz a saída de prog1 ser a entrada de prog2
    }else if(palavra[1] == "&"){
       // roda prog1 e deixa o terminal livre para outros comandos. ?
    }else if(palavra[1] == ">"){
        // saida - roda prog1 e joga o output dele para o arquivo saída
    }else if(palavra[1] == "<"){
       // entrada – roda prog1 e recebe como input o arquivo entrada
    }else{
        //se não for nenhuma desses significa que são comandos do tipo cd nomepasta, ls, pwd, etc..
        
        int rc = fork();  
        if (rc < 0) {      // fork falhou
            fprintf(stderr, "fork falhou\n");
            exit(1);
        }else if (rc == 0) { // filho - todos os recursos do processo filho aqui
            if(strcmp(palavra[0],"ls") == 0){         //ls ok
                execvp(strdup(palavra[0]),palavra);
            }
            if(strcmp(palavra[0],"pwd") == 0){        //pwd ok
                execvp(strdup(palavra[0]),palavra);
            }
            if(strcmp(palavra[0],"cd") == 0){
                
            }

        }else{// Pai vem por aqui
            int wc = wait(NULL);
            printf("\n hello, sou o pai de %d (wc:%d) (pid:%d)\n",
            rc, wc, (int) getpid());
        }
        return 0;
    }
}

/* pedaço do codigo do professor para consulta

        myargs[0] = strdup("ls");   // programa: "wc"
        myargs[1] = strdup("-l");   // argumento: nome do arquivo
        myargs[2] = NULL;           // fim do vetor
        execvp(myargs[0], myargs);  // roda wc

*/