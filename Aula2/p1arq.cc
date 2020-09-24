#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include<fstream>

using namespace std;
int
main(int argc, char *argv[])
{
	ofstream arq("saida.txt");
	printf("hello world (pid:%d)\n", (int) getpid());
	int rc = fork(); 
	if (rc < 0) {
	// fork falhou; saia do programa
		fprintf(stderr, "Erro no fork\n");
	exit(1);
	} else if (rc == 0) {
		for(int i=0;i<100000;i++)
			arq<<"Processo Filho!"<<endl;
	// o filho entra aqui (novo processo)
		printf("Ola, Sou o filho (pid:%d)\n", (int) getpid());
	} else {
		for(int i=0;i<100000;i++)
			arq<<"Processo Pai!"<<endl;
	// O pai entra aqui (processo original)
		printf("Ola, sou o pai de %d (pid:%d)\n",
		rc, (int) getpid());
	}
	return 0;
}
