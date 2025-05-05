#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <Windows.h>

// TIPO NAVE
typedef struct{
    int id;
    int status; // 0 - Disponivel; 1 - Em missão; 2 - Destruida;
} Nave;

// PILHA PARA GERENCIAMENTO DOS COMANDOS
typedef struct noPilha{
    Nave nave;
    struct noPilha* proximo;
} NoPilha;
typedef NoPilha* PtrNoPilha;

typedef struct{
    PtrNoPilha topo;
    int qtde;
} Pilha;
typedef Pilha* PtrPilha;

// FILA PARA GERENCIAMENTO DE NAVES DISPONIVEIS
typedef struct noFila{
    Nave nave;
    struct noFila* proximo;
} NoFila;
typedef NoFila* PtrNoFila;

typedef struct{
    PtrNoFila inicio;
    PtrNoFila fim;
    int qtde;
} Fila;
typedef Fila* PtrFila;

// LISTA PARA CADASTRO DE NAVES
typedef struct noLista{
    Nave nave;
    struct noLista* proximo;
} NoLista;
typedef NoLista* PtrNoLista;

typedef struct{
    PtrNoLista inicio;
    int qtde;
} Lista;
typedef Lista* PtrLista;

// PROTÓTIPOS DAS FUNÇÕES
void inicializar(PtrPilha p, PtrLista l, PtrFila f);
void adicionarNave(PtrLista naves, PtrFila navesDisponiveis, int idNave);
void enviarNave(PtrPilha comandos, PtrLista naves, PtrFila navesDisponiveis);
void desfazerEnvio(PtrPilha comandos, PtrLista naves, PtrFila navesDisponiveis);
int pesquisarLista(PtrLista l, int key);
void inserirFila(PtrFila navesDisponiveis, Nave novaNave);
void atualizarStatus(PtrLista naves, Nave nave, int status);
void listarDisponiveis(PtrFila navesDisponiveis);
void listarNaves(PtrLista naves);
bool estaVaziaPilha(PtrPilha p);
bool estaVaziaFila(PtrFila f);
bool estaVaziaLista(PtrLista l);

int main(){
    SetConsoleOutputCP(65001);

    PtrPilha comandos = (PtrPilha)malloc(sizeof(Pilha));
    PtrLista naves = (PtrLista)malloc(sizeof(Lista));
    PtrFila navesDisponiveis = (PtrFila)malloc(sizeof(Fila));
    inicializar(comandos, naves, navesDisponiveis);

    int menu, idNave;
    do{
        printf("\n=-=-=-=-=-=-=-=-=-=-=-=-=\n");
        printf("[1] Adicionar nave à frota\n");
        printf("[2] Enviar nave para missão\n");
        printf("[3] Desfazer último envio\n");
        printf("[4] Lista de naves disponíveis\n");
        printf("[5] Lista de todas as naves\n");
        printf("[6] Sair\n\n");
        scanf("%d", &menu);
        printf("\n=-=-=-=-=-=-=-=-=-=-=-=-=\n");

        if(menu == 1){
            printf("\nID da nave: ");
            scanf("%d", &idNave);
        }

        switch (menu)
        {
        case 0:
            break;
        
        case 1:
            adicionarNave(naves, navesDisponiveis, idNave);
            break;
        
        case 2:
            enviarNave(comandos, naves, navesDisponiveis);
            break;
        
        case 3:
            desfazerEnvio(comandos, naves, navesDisponiveis);
            break;
        
        case 4:
            listarDisponiveis(navesDisponiveis);
            break;
        
        case 5:
            listarNaves(naves);
            break;
        
        default:
            printf("\nOpção inválida!\n");
            break;
        }
    }while(menu != 0);
}

void inicializar(PtrPilha p, PtrLista l, PtrFila f){
    // inicializa pilha de comandos
    p->topo= NULL;
    p->qtde = 0;

    // inicializa a lista geral de naves
    l->inicio = NULL;
    l->qtde = 0;

    // inicializa fila de naves disponiveis
    f->inicio = NULL;
    f->fim = NULL;
    f->qtde = 0;
}

void adicionarNave(PtrLista naves, PtrFila navesDisponiveis, int idNave){
    if(pesquisarLista(naves, idNave) == -1){ // Verifica se a nave já está cadastrada
        Nave novaNave;
        novaNave.id = idNave;
        novaNave.status = 0; // Inicia como disponível

        // Adiciona a lista geral de naves
        PtrNoLista naveLista = (PtrNoLista)malloc(sizeof(NoLista));
        naveLista->nave = novaNave;
        if(estaVaziaLista(naves) || naves->inicio->nave.id > idNave ){
            naveLista->proximo = naves->inicio;
            naves->inicio = naveLista;
        }
        else{
            for(PtrNoLista i = naves->inicio; i != NULL; i = i->proximo){
                if(i->proximo == NULL || (i->nave.id <= idNave && i->proximo->nave.id >= idNave)){
                    naveLista->proximo = i->proximo;
                    i->proximo = naveLista;
                    break;
                }
            }
        }
        naves->qtde++;

        inserirFila(navesDisponiveis, novaNave);

        printf("\nNave %d adicionada a frota!\n", novaNave.id);
    } else printf("\nJá existe uma nave com esse ID\n");
}

void enviarNave(PtrPilha comandos, PtrLista naves, PtrFila navesDisponiveis){
    if(!estaVaziaFila(navesDisponiveis)){
        // Coleta a primeira nave disponivel na fila
        PtrNoFila naveFila = navesDisponiveis->inicio;

        // Coleta a nave
        Nave nave = naveFila->nave;
        
        // Atualiza o status para em missão
        atualizarStatus(naves, nave, 1);

        // Exclui ela da fila de naves disponíveis
        navesDisponiveis->inicio = navesDisponiveis->inicio->proximo;
        navesDisponiveis->qtde--;
        free(naveFila);

        // Adicionando na pilha de comandos
        PtrNoPilha comando = (PtrNoPilha)malloc(sizeof(NoPilha));
        comando->nave = nave;
        comando->proximo = comandos->topo;
        comandos->topo = comando;
        comandos->qtde++;

        printf("\nNave %d enviada para missão com sucesso!\n", nave.id);
    } else printf("\nNão tem nenhuma nave disponível para ser enviada!\n");
}

void desfazerEnvio(PtrPilha comandos, PtrLista naves, PtrFila navesDisponiveis){
    if(!estaVaziaPilha(comandos)){
        // Coletar o ultimo comando
        PtrNoPilha navePilha = comandos->topo;

        // Coletar a nave do ultimo comando
        Nave nave = navePilha->nave;

        // Retira o comando da pilha
        comandos->topo = navePilha->proximo;
        comandos->qtde--;
        free(navePilha);

        // Atualizar status da nave na lista geral
        atualizarStatus(naves, nave, 0);

        // Volta a nave na fila de disponíveis
        inserirFila(navesDisponiveis, nave);
        
        printf("\nNave %d voltou para a base!\n", nave.id);
    } else printf("\nNão há nenhum comando a ser desfeito!\n");
}

int pesquisarLista(PtrLista l, int key){
    int pos=0;
    for(PtrNoLista i = l->inicio ; i != NULL; i = i->proximo){
        pos++;
        if(i->nave.id == key){
            return pos;
        }
    }
    return -1;
}

void inserirFila(PtrFila navesDisponiveis, Nave novaNave){
    // Adiciona a fila de naves disponiveis
    PtrNoFila naveFila = (PtrNoFila)malloc(sizeof(NoFila));
    naveFila->nave = novaNave;
    naveFila->proximo = NULL;
    if(estaVaziaFila(navesDisponiveis)){
        navesDisponiveis->inicio = naveFila;
    }
    else{
        navesDisponiveis->fim->proximo = naveFila;
    }
    navesDisponiveis->fim = naveFila;
    navesDisponiveis->qtde++;
}

void atualizarStatus(PtrLista naves, Nave nave, int status){
    for(PtrNoLista i = naves->inicio ; i != NULL; i = i->proximo){
        if(i->nave.id == nave.id){
            i->nave.status = status; // 0 = Disponivel e 1 = Em missão.
            break;
        }
    }
}

void listarDisponiveis(PtrFila navesDisponiveis){
    if(!estaVaziaFila(navesDisponiveis)){
        printf("\n- Naves Disponíveis:\n");
        for(PtrNoFila i = navesDisponiveis->inicio; i != NULL; i= i->proximo) printf("NAVE %d | ", i->nave.id);
        printf("\n");
    } else printf("\nNão tem nenhuma nave disponível!\n");
}

void listarNaves(PtrLista naves){
    if(!estaVaziaLista(naves)){
        printf("\n");
        for(PtrNoLista i = naves->inicio; i != NULL; i = i->proximo){
            printf("Nave %d: %s\n", i->nave.id, i->nave.status == 0 ? "Disponível" : i->nave.status == 1 ? "Em missão" : "Destruída");
        }
    } else printf("\nNão há naves na frota!\n");
}

bool estaVaziaPilha(PtrPilha p){
    return (p->qtde == 0);
}

bool estaVaziaFila(PtrFila f){
    return (f->qtde == 0);
}

bool estaVaziaLista(PtrLista l){
    return (l->qtde == 0);
}