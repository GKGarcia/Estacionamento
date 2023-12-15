#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>
#include <string.h>
#define TAM 50

int opcao, i, j, ok,t,ok1;
char busca[15];
char teste[6];

typedef struct{
	char nome[50];
	char cpf[20];
	char placa[15];
	char modelocar[20];
	char cor[20];
	char horaentrada[6];
	char horasaida[6];
	int ticket;
}cadastro;

cadastro cad[TAM];

void menu();
void cadastrarmotorista();
void estacionado();
int gerarticket();
void saida();
void buscarveiculo();
//void listar veiculos

int main(){
	setlocale(LC_ALL,"portuguese");
	
	while(opcao != 4){
		
		menu();
		 
		switch(opcao){
			case 1:
				cadastrarmotorista();
			   break;
			case 2:
				estacionado();
				break;
			case 3:
				saida();
				break;
			case 4:
				buscarveiculo();
				break;
			case 5:
				printf("SISTEMA EM DESENVOLVIMENTO!\n");
				break;
			default:
				printf("!Opção invalida!\n");
				break;
		}
	}
return 0;
} 

void menu(){
	
	printf("\n\n\n\n\n\n\n\n\n");
	printf("                                  **************************************************            \n");
	printf("                                  *              BEM VINDO AO MENU                 *            \n");
	printf("                                  *           1- Cadastrar Motorista               *            \n");
	printf("                                  *           2- Veiculos Estacionados             *            \n");
	printf("                                  *           3- Registrar Saida de Veiculo        *            \n");
	printf("                                  *           4- Buscar Veiculo                    *            \n");
	printf("                                  *           5- Listar Veiculos                   *            \n");
	printf("                                  *           6- SAIR                              *            \n");
	printf("                                  **************************************************            \n");
	scanf("                                                        %d", &opcao);
	
	system("cls");
}

int gerarticket(void){
	srand(time(NULL));
	int t = rand() % 9000000 + 1000000;
    return t;
}

void cadastrarmotorista(){
	
	strcpy(cad[i].horasaida,"0");
	
	printf("Digite o nome do motorista:\n");
	fflush(stdin);
	scanf("%50[^\n]s", cad[i].nome);
	fflush(stdin);
	
	printf("\nDigite CPF ou CNH do motorista:\n");
	scanf("%20[^\n]s", cad[i].cpf);
	fflush(stdin);
	
	printf("\nDigite o modelo do veiculo:\n");
	scanf("%20[^\n]s", cad[i].modelocar);
	fflush(stdin);
	
	printf("\nDigite a cor do veiculo:\n");
    scanf("%20[^\n]s", cad[i].cor);
    fflush(stdin);
	
	printf("\nDigite o numero da placa do carro:\n");
	scanf("%15[^\n]s", cad[i].placa);
	fflush(stdin);
	
	printf("\nDigite o horario de entrada do veiculo:\n");
	scanf("%6[^\n]s", cad[i].horaentrada);
	
	cad[i].ticket = gerarticket();
	
	printf("\nTICKET:%d\n",cad[i].ticket);
	
	printf("\nAtendimento Cadastrado!\n");
	i=i+1;
	
	system("pause");
	system("cls");
}

void estacionado(){
	
	j=0;
	ok=0;
	
	for(j=0;j<i;j++){
		
		ok = strcmp(cad[j].horasaida,"0");
		
		if(ok == 0){
		
		   printf("\n\nCARRO:%s\n",cad[j].modelocar);
		   printf("COR:%s\n",cad[j].cor);
		   printf("PLACA:%s\n",cad[j].placa);
		   printf("MOTORISTA:%s\n",cad[j].nome);
		   printf("CPF:%s\n",cad[j].cpf);
		   printf("HORARIO DE ENTRADA:%s\n",cad[j].horaentrada);
		   printf("\nTICKET:%d\n",cad[j].ticket);
		   printf("==========================\n");
	   }
	}
	
	system("pause");
	system("cls");
}

void buscarveiculo(){
	
	printf("Digite a placa do carro:\n");
	fflush(stdin);
	scanf("%15[^\n]s", busca);
	fflush(stdin);
	
	system("cls");
	
	for(j=0;j<i;j++){
	
	ok= strcmp(busca,cad[j].placa);
	 
	    if(ok==0){
		
		   printf("\n\nMOTORISTA:%s\n",cad[j].nome);
		   printf("CPF:%s\n",cad[j].cpf);
		   printf("CARRO:%s\n",cad[j].modelocar);
		   printf("COR:%s\n",cad[j].cor);
		   printf("PLACA:%s\n",cad[j].placa);
		   printf("HORARIO DE ENTRADA:%s\n",cad[j].horaentrada);
		   printf("\nTICKET:%d\n",cad[j].ticket);
		   printf("==========================\n");
		
		   system("pause");
		   system("cls");
		}
	}
}

void saida(){
	
	j=0;
	ok=0;
	
	printf("Digite a placa do carro ou o nome do motorista:\n");
	fflush(stdin);
	scanf("%15[^\n]s", busca);
	fflush(stdin);
	
	for(j=0;j<i;j++){
	
		ok= strcmp(busca,cad[j].placa);
		ok1= strcmp(busca,cad[j].nome);
	
        if(ok == 0 || ok1 == 0){
   	
   	        printf("\n\nMOTORISTA:%s\n",cad[j].nome);
	        printf("CPF:%s\n",cad[j].cpf);
	        printf("CARRO:%s\n",cad[j].modelocar);
	        printf("COR:%s\n",cad[j].cor);
	        printf("PLACA:%s\n",cad[j].placa);
	        printf("HORARIO DE ENTRADA:%s\n",cad[j].horaentrada);
	        printf("\nTICKET:%d\n",cad[j].ticket);
	
	        printf("\ndigite o horario de saida:\n");
	        scanf("%6[^/n]s",cad[j].horasaida);
	 
          	printf("\n");
	        printf("Saida Registrada!");
	        
	        system("pause");
	        system("cls");
   	   }
   }
}

