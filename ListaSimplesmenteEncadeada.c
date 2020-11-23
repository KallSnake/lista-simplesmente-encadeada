#include <stdio.h> // stdio.h: Biblioteca padrão de Entrada/Saida - Standard Input-Output Header - Cabeçalho Padrão de Entrada/Saída
#include <stdlib.h> // stclib.h: Biblioteca de Propósito Geral -  Ela possui funções envolvendo alocação de memória, controle de processos, conversões e outras
#include <locale.h>



// Declaracao da Estrutura Nodo 
typedef struct sNodo {
	
	int info;
	struct sNodo *prox;

} Nodo;



// Declaracao da Estrutura Lista Simplesmente Encadeada
typedef struct sListaSimplesEnc {
	
	Nodo *prim;
	
}ListaSimplesEnc;



// Criando Lista Vazia
void criarLista(ListaSimplesEnc *pList) {
	
	pList->prim = NULL;
	
}



// Mostrar Elementos da Lista
void mostrarLista(ListaSimplesEnc *pList) {
	
	
	Nodo *p;
	
	printf("Lista: ");
	
	for (p = pList->prim; p != NULL; p = p->prox) {
		
		printf("%d -> ", p->info);
		
	}
	
	printf("NULL\n\n");
	

}



// Inserir no Inicio da Lista
void inserirIni(ListaSimplesEnc *pList, int v) {
	

	Nodo *novo;
	
	novo = (Nodo*)malloc(sizeof(Nodo));
	
	if (novo != NULL) {
		
		novo->info = v;
		
		novo->prox = pList->prim;
		
		pList->prim = novo;
		
		
		printf("\nValor Inserido com Sucesso!\n\n");
	
	} else {
		
		printf("Memória Insuficiente\n\n");
	
	}


}



// Inserir Elemento em Ordem na Lista
void inserirOrd(ListaSimplesEnc *pList, int v) {
	
	
	Nodo *novo;
	
	novo = (Nodo*)malloc(sizeof(Nodo));
	
	if (novo != NULL) {
		
		novo->info = v;
		
		Nodo *pAtu, *pAnt;
		
		pAnt = NULL;
		
		pAtu = pList->prim;
		
		
		while (pAtu != NULL && pAtu->info < v) {
			
			pAnt = pAtu;
			
			pAtu = pAtu->prox;
			
		}
			
		novo->prox = pAtu;
			
		if (pAnt != NULL) {
			
			pAnt->prox = novo;
			
		} else {
			
			pList->prim = novo;
			
		}
		
		
		printf("\nValor Inserido com Sucesso!\n\n");
		
		
	} else {
		
		printf("Memória Insuficiente\n");
		
	}


}




// Remover um Elemento Especifico da Lista
void removerEle(ListaSimplesEnc *pList, int v) {
	
	
	Nodo *pAtu, *pAnt;
	
	pAnt = NULL;
	
	pAtu = pList->prim;
	
	
	while (pAtu != NULL && pAtu->info != v) {
		
		pAnt = pAtu;
		
		pAtu = pAtu->prox;
	
	}
	
	
	if (pAnt != NULL) {
		
		
		if (pAtu != NULL) {
			
			pAnt->prox = pAtu->prox;
			
			free(pAtu);
			
			printf("Valor Removido\n\n");
		
		} else {
			
	    	printf("Valor não Encontrado\n\n");
	
		}
		
	
	} else {
		
	    printf("Lista Está Vazia\n\n");
	
	}


}




// Remover no Inicio da Lista
void removerIni(ListaSimplesEnc *pList) {
	
	
	Nodo *pAux = pList->prim;
	
	if (pAux != NULL) {
		
		pList->prim = pList->prim->prox;
		
		free(pAux);
		
		printf("Valor Removido\n\n");
		
	} else {
		
		printf("Lista Está Vazia\n\n");
		
	}


}




// Remover Todos os Elementos da Lista
void removerTudo(ListaSimplesEnc *pList) {
	
	
	Nodo *pAux = pList->prim;
	
	if (pAux != NULL) {
		
		
		while (pAux != NULL) {
			
			
			pList->prim = pAux->prox;
			
			free(pAux);
			
			pAux = pList->prim;
			
		
		}
		
	
		printf("Todos os Elementos Foram Removidos!\n\n");
	
	} else {
		
		printf("\nLista Está Vazia\n\n");
	
	}


}




// Alterar Elemento da Lista
void alterarEle(ListaSimplesEnc *pList, int v1, int v2) {
	
	
	Nodo *pAtu, *pAnt;
	pAnt = NULL;
	pAtu = pList->prim;
	
	while (pAtu != NULL && pAtu->info != v1) {
		
		pAnt = pAtu;
		pAtu = pAtu->prox;
	
	}
	
	if (pAnt != NULL) {
		
		
		if (pAtu != NULL) {
			
			pAtu->info = v2;
			
			printf("\nValor Alterado\n\n");
		
		} else {
			
			printf("\nValor não Encontrado\n\n");
		
		}
		
		
	} else {
		
		printf("\nLista Está Vazia\n\n");
		
	}


}



// Lista Vazia
int estaVazia(ListaSimplesEnc *pList) {
	
	return(pList->prim == NULL);

}





int main(){

    setlocale (LC_ALL, "Portuguese");

    // Inicio Variáveis
	ListaSimplesEnc minhaLista;
	
	int valor, op, valorAlt;
	
	criarLista(&minhaLista);
	
	
	
	
	
	do{
		
		
		printf("\nEscolha uma Opção:\n");
		
		
		printf("\n(1) Inserir Elemento no Início da Lista\n");
		printf("(2) Inserir Elemento em Ordem na Lista\n");
		printf("(3) Remover Elemento no Início da Lista\n");
		printf("(4) Remover Elemento Específico da Lista\n");
		printf("(5) Mostrar Lista\n");
		printf("(6) Apagar Todos os Elementos da Lista\n");
		printf("(7) Alterar Elemento da Lista\n");
		printf("(0) Sair (Encerrar o Programa)\n\n");
		printf(" ? ");
		scanf("%d", &op);
	
	
		system("cls");
		
		
		switch (op) {
			
			
			case 1: // Inserir Elemento no Inicio
			
				printf("Valor: ");
				scanf("%d", &valor);
				inserirIni(&minhaLista, valor);
				
			break;
			
			
			case 2: // Inserir Elemento Ordenado
			
				printf("Valor: ");
				scanf("%d", &valor);
				inserirOrd(&minhaLista, valor);
				
			break;
			
			
			case 3: // Remover o Primeiro Elemento da Lista
			
			 	removerIni(&minhaLista);
			 	
			break;
			
			
			case 4: // Remover Determinado Elemento da Lista
			
				printf("Valor a ser removido: ");
				scanf("%d", &valor);
				removerEle(&minhaLista, valor);
			
			break;
			
			
			case 5: // Mostrar Lista
			
				if (estaVazia(&minhaLista)) {
					
					printf("Lista Está Vazia\n\n");
				
				} else {
					
					mostrarLista(&minhaLista);
				
				}
				
			break;
			
			
			case 6: // Apagar Todos os Elementos da Lista
			
				removerTudo(&minhaLista);
			
			break;
			
			
			case 7: // Alterar um Elemento da Lista
			
				printf("Valor a ser alterado: ");
				scanf("%d", &valor);
				printf("Novo valor: ");
				scanf("%d", &valorAlt);
				alterarEle(&minhaLista, valor, valorAlt);
			
			break;
			
			
			case 0: // Encerrar o Programa
			
				removerTudo(&minhaLista);
				
				system("cls");
			    printf("\n\nPrograma Executado com Sucesso!!\n\n");
	    		system("pause"); // Pausa o Programa Após Executar
			
				// op = 0;
			
				exit(0);
			
			
			default:
				
				printf("\nERRO: Opção Inexistente! \n\n");
		
		
		}
		
		
	} while ( op != 0 );



    return 0;

}
