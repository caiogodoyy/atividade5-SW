#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>

int resultado = 0;
int tam = 0;
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

void *somar(void *arg);

int main()
{
	scanf("%d", &tam);
	int matriz[tam][tam];
	for(int i = 0; i < tam; i++) {
		for(int x = 0; x < tam; x++)
			scanf("%d", &matriz[i][x]);
	}
	
	pthread_t threads[tam];
	for(int i = 0; i < tam; i++) {
		int *linha = malloc(tam * sizeof(int));
		for(int x = 0; x < tam; x++)
			linha[x] = matriz[i][x];
		if(pthread_create(&(threads[i]), NULL, somar, (void *)linha))
			printf("ERRO");
	}
	
	for(int i = 0; i < tam; i++)
		pthread_join(threads[i], NULL);
	
	printf("%d", resultado);
	return 0;
}

void *somar(void *arg)
{
	pthread_mutex_lock(&mutex);
	int *linha = (int *)arg;
	for(int i = 0; i < tam; i++)
		resultado = resultado + linha[i];
	pthread_mutex_unlock(&mutex);
}
