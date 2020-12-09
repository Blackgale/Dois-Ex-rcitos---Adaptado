/*
	Situacao adaptada do problema dos dois generais
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*Declaração de funções*/
void mensageiro();
void mudar_horario();
void start();
void timestamp();


/*Declaracao de variaveis globais*/
int vermelho, azul, captura, tempo_total;

main()
{
	srand(time(NULL));
	
	/*Inicializacao das variaveis*/
	vermelho = 5;
	azul = 10;
	
	mensageiro();
	
	printf("\nTimestamp - inicio: ");
	start();
	printf("\nTimestamp - final: ");
	timestamp();
	printf("\nTempo: %ds", tempo_total);
	printf("\nVermelhos: %d \nAzuis: %d", vermelho, azul);
	
	if(vermelho == 0 || azul == 0)
		printf("\nSituacao: perdeu");
	else
		printf("\nSituacao: ganhou");
	
	return 0;
}

void mensageiro()
{
	int horario;
	
	while(vermelho > 0) // ciclo do exercito vermelho
	{
		captura = rand() % 100;
		tempo_total += 3600 + (rand() % 600);
		
		if(captura < 45)
		{
			vermelho--;
			tempo_total += 12601;
			continue;
		}
		else
		{
			while(azul > 0) // ciclo do exercito azul
			{
				horario = rand() % 100;
				if(horario == 1) // 1% de chance de mudar o horario
					mudar_horario();
				else
				{
					captura = rand() % 100;
					tempo_total += 3600 + (rand() % 600);
	
					if(captura < 45)
					{
						azul--;
						tempo_total += 4201;
						continue;
					}
					else
						break;	
				}
			}
			break;
		}
	}
}

void mudar_horario()
{
	while(azul > 0) // ciclo do exercito azul
	{
		captura = rand() % 100;
		tempo_total += 3600 + (rand() % 600);

		if(captura < 45)
		{
			azul--;
			tempo_total += 4201;
			continue;
		}
		else
		{
			printf("\nNovo horario recebido pelo exercito vermelho");
			mensageiro();
		}
	}
}

void start()
{
	time_t rawtime = time(NULL);
    struct tm *ptm = localtime(&rawtime);
    
    printf("%02dh:%02dm:%02ds", ptm->tm_hour, 
           ptm->tm_min, ptm->tm_sec);
}

void timestamp()
{
	time_t rawtime = time(NULL);
	int d, h, m, s, tempo;
	struct tm *ptm = localtime(&rawtime);

	tempo = (ptm->tm_hour * 3600) + (ptm->tm_min * 60) + ptm->tm_sec + tempo_total;
	d = tempo / 86400;
	h = (tempo - (86400*d)) / 3600;
	m = (tempo - (86400*d) - (3600*h)) / 60;
    s = (tempo - (86400*d) - (3600*h) - (m*60));

    printf("%02dd:%02dh:%02dm:%02ds", d, h, m, s);
}
