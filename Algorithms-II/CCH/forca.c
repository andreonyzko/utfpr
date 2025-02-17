// BIBLIOTECAS
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <locale.h>
#include <windows.h>
#include <time.h>

// VALORES FIXOS
#define MAX_PALAVRA 50
#define MIN_PALAVRA 5


// PROTÓTIPOS DAS FUNÇÕES
void novojogo();
void cadastrar();
void atualizar();
void apagar();
void mostrar();
int verificar_existencia(char *palavra);
int verificar_formato(char *palavra);
int contar_palavras(char removidos);
int posicao_palavra(char *palavra);
void maiusculo(char *palavra);
void minusculo(char *palavra);

// ESTRUTURAS JOGO E PALAVRA
typedef struct{
    char resposta[MAX_PALAVRA];
    char letras_usadas[MAX_PALAVRA];
    int chances;
    int pontuacao;
    char display[MAX_PALAVRA];
} Jogo;

typedef struct{
    char palavra[MAX_PALAVRA];
} Palavra;


int main(){
    // VERIFICAÇÃO DO ARQUIVO
    FILE* arquivo = fopen("palavras.bin","a+b");
        if(!arquivo){
            printf("Erro ao acessar o arquivo de palavras");
            return 0;
        }
    fclose(arquivo);

    // CONJUNTO DE CARACTERES
    SetConsoleOutputCP(65001);
    setlocale(LC_ALL, "pt_BR.UTF-8");
    
    // MENU INICIAL
    while(1){
        char opt[100];
        printf("=-=-=-=-=-=-=- MENU -=-=-=-=-=-=-=-=\n");
        printf("> Novo jogo\n");
        printf("> Cadastrar palavra\n");
        printf("> Atualizar palavra\n");
        printf("> Apagar palavra\n");
        printf("> Mostrar palavras\n");
        printf("> Sair\n\n");
        scanf(" %[^\n]s", opt);
        printf("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");

        minusculo(opt);

        if(strcmp(opt, "novo jogo") == 0) novojogo();
        else if(strcmp(opt, "cadastrar palavra") == 0) cadastrar();
        else if(strcmp(opt, "atualizar palavra") == 0) atualizar();
        else if(strcmp(opt, "apagar palavra") == 0) apagar();
        else if(strcmp(opt, "mostrar palavras") == 0) mostrar();
        else if(strcmp(opt, "sair") == 0) break;
        else printf("Opção inválida\n");
    }
}

void novojogo(){
    // BONECO DA FORCA
    char boneco_layout[6] = {'\\','/','\\','|','/','O'};
    char boneco[6] = {' ',' ',' ',' ',' ',' '};

    // VERIFICAR SE HÁ PALAVRA CADASTRADA 
    if(contar_palavras('N') == 0){
        printf("Não há palavras cadastradas.\n");
        return;
    }

    FILE *arquivo = fopen("palavras.bin","rb");
    if(!arquivo){
        printf("Erro ao acessar o arquivo de palavras");
        return;
    }

    // SORTEAR PALAVRA
    Palavra resposta;
    srand(time(NULL));
    while(1){
        int pos_palavra = rand() % contar_palavras('S');
        fseek(arquivo, pos_palavra*sizeof(Palavra), SEEK_SET);
        fread(&resposta, sizeof(Palavra), 1, arquivo);
        if(strcmp(resposta.palavra, " ") == 0) continue;
        break;
    }
    fclose(arquivo);
    
    // DEFINIR PARAMETROS DA PARTIDA
    Jogo partida = {"", " ", 6, 0, " "};
    strcpy(partida.resposta, resposta.palavra);

    // PRIMEIRA RODADA
    int i=0;
    printf("____\n|  |\n|  %c\n| %c%c%c\n| %c %c       ", boneco[5], boneco[4], boneco[3], boneco[2], boneco[1], boneco[0]);
    for(i=0; partida.resposta[i] != '\0'; i++) partida.display[i] = '_';
    partida.resposta[i] = '\0';

    for(int i=0; partida.display[i] != '\0'; i++) printf("%c ", partida.display[i]);
    printf("\n\n");
    printf("Letras usadas: %s\n", partida.letras_usadas);
    printf("Pontuação: %d\n", partida.pontuacao);
    printf("Chances restantes: %d\n", partida.chances);

    // PROXIMAS RODADAS
    int qntd_letras_usadas=0;
    while (1){
        // OBTER LETRA
        char letra;
        printf("Digite uma letra: ");
        scanf(" %c", &letra);
        letra = toupper(letra);

        // VERIFICAR SE A LETRA JÁ FOI USADA
        int ja_foi_usada=0;
        for(int i=0; partida.letras_usadas[i] != '\0'; i++){
            if(partida.letras_usadas[i] == letra){
                printf("\nEssa letra já foi usada!\n");
                ja_foi_usada=1;
                break;
            }
        }
        if(ja_foi_usada) continue;

        // VERIFICAR SE ACERTOU A LETRA
        int acertou=0;
        for(int i=0; partida.resposta[i] !=  '\0'; i++){
            if(partida.resposta[i] == letra){
                partida.display[i] = letra;
                acertou=1;
            }
        }

        // SE ACERTOU = +1 ponto; SE ERROU = -1 chance, -1 ponto, -1 parte do boneco;
        if(acertou){
            partida.pontuacao += 1;
        }
        else{
            partida.chances -= 1;
            if(partida.pontuacao > 0){
                partida.pontuacao -= 1;
            }
            boneco[partida.chances] = boneco_layout[partida.chances];
        }

        // ADICIONA A LETRA AO VETOR DE PALAVRAS USADAS
        partida.letras_usadas[qntd_letras_usadas] = letra;
        partida.letras_usadas[qntd_letras_usadas+1] = '\0';
        qntd_letras_usadas++;

        // VERIFICAR SE O DISPLAY É IGUAL A RESPOSTA = VENCEU
        if(strcmp(partida.display,partida.resposta) == 0){
            printf("\n==================== PARABÉNS ====================\n");
            printf("Você descobriu que a palavra secreta era %s\n\n", partida.resposta);

            printf("____\n|  |\n|  %c\n| %c%c%c\n| %c %c\n\n", boneco[5], boneco[4], boneco[3], boneco[2], boneco[1], boneco[0]);

            printf("--- ESTATISTÍCAS ---\n");
            printf("Pontuação: %d\n", partida.pontuacao);
            printf("Tentativas: %d\n", qntd_letras_usadas);
            printf("Letras usadas: %s\n", partida.letras_usadas);
            printf("Chances restantes: %d\n", partida.chances);
            printf("\n=================================================\n");
            return;
        }

        // VERIFICA SE AINDA HÁ CHANCES, SE NÃO, PERDEU
        if(partida.chances == 0){
            printf("\n==================== GAME OVER ====================\n");
            printf("Você não conseguiu adivinhar. A palavra secreta era %s\n\n", partida.resposta);

            printf("____\n|  |\n|  %c\n| %c%c%c\n| %c %c\n\n", boneco[5], boneco[4], boneco[3], boneco[2], boneco[1], boneco[0]);

            printf("--- ESTATISTÍCAS ---\n");
            printf("Pontuação: %d\n", partida.pontuacao);
            printf("Tentativas: %d\n", qntd_letras_usadas);
            printf("Letras usadas: %s\n", partida.letras_usadas);
            printf("Chances restantes: %d\n", partida.chances);
            printf("\n=================================================\n");
            return;
        }

        // NOVA RODADA
        printf("\n=============================================\n");
        printf("____\n|  |\n|  %c\n| %c%c%c\n| %c %c       ", boneco[5], boneco[4], boneco[3], boneco[2], boneco[1], boneco[0]);
        for(int i=0; partida.display[i] != '\0'; i++) printf("%c ", partida.display[i]);
        printf("\n\n");
        printf("Letras usadas: %s\n", partida.letras_usadas);
        printf("Pontuação: %d\n", partida.pontuacao);
        printf("Chances restantes: %d\n", partida.chances);
    }
}

void cadastrar(){
    // VERIFICA SE HÁ ESPAÇO PARA CADASTRAR MAIS PALAVRAS
    if(contar_palavras('N') >= 10){
        printf("Já tem o máximo de 10 palavras cadastradas\n");
        return;
    }

    // COLETAR PALAVRA NOVA
    Palavra novaPalavra;
    printf("Digite a palavra para cadastrar: ");
    scanf(" %[^\n]s", novaPalavra.palavra);

    // VERIFICAR O FORMATO E SE JÁ ESTA CADASTRADA
    if(verificar_formato(novaPalavra.palavra)) return;
    if(verificar_existencia(novaPalavra.palavra)) return;

    // CADASTRAR PALAVRA
    FILE *arquivo = fopen("palavras.bin","ab");
    if(!arquivo){
        printf("Erro ao acessar o arquivo de palavras");
        return;
    }
    fwrite(&novaPalavra, sizeof(Palavra), 1, arquivo);
    printf("Palavra cadastrada com sucesso!\n");
    fclose(arquivo);
}

void atualizar(){
    // VERIFICA SE HÁ ALGUMA PALAVRA CADASTRADA
    if(contar_palavras('N') == 0){
        printf("Não há palavras cadastradas.\n");
        return;
    }

    // COLETAR A PALAVRA ANTIGA
    Palavra antigaPalavra;
    printf("Digite a palavra que quer alterar: ");
    scanf(" %[^\n]s", antigaPalavra.palavra);
    maiusculo(antigaPalavra.palavra);

    // PEGAR A POSIÇÃO DA PALAVRA ANTIGA, SE NÃO EXISTIR, ABORTA
    int posicao = posicao_palavra(antigaPalavra.palavra);
    if(!posicao) return;
    
    // COLETAR A PALAVRA NOVA
    Palavra novaPalavra;
    printf("Digite a nova palavra: ");
    scanf(" %[^\n]s", novaPalavra.palavra);

    // VERIFICAR FORMATO E SE JÁ ESTA CADASTRADA
    if(verificar_formato(novaPalavra.palavra)) return;
    if(verificar_existencia(novaPalavra.palavra)) return;

    // ATUALIZA A PALAVRA
    FILE *arquivo = fopen("palavras.bin","r+b");
    if(!arquivo){
        printf("Erro ao acessar o arquivo de palavras");
        return;
    }
    fseek(arquivo, (posicao-1)*sizeof(Palavra), SEEK_SET);
    fwrite(&novaPalavra, sizeof(Palavra), 1, arquivo);
    fclose(arquivo);
    printf("Palavra atualizada com sucesso\n");
}

void apagar(){
    // VERIFICAR SE HÁ ALGUMA PALAVRA CADASTRADA
    if(contar_palavras('N') == 0){
        printf("Não há palavras cadastradas.\n");
        return;
    }
    
    // COLETAR A PALAVRA ANTIGA
    Palavra antigaPalavra;
    printf("Digite a palavra que quer excluir: ");
    scanf(" %[^\n]s", antigaPalavra.palavra);
    maiusculo(antigaPalavra.palavra);

    // PEGAR A POSIÇÃO DA PALAVRA ANTIGA, SE NÃO EXISTIR, ABORTA
    int posicao = posicao_palavra(antigaPalavra.palavra);
    if(!posicao) return;

    // EXCLUIR A PALAVRA
    FILE *arquivo = fopen("palavras.bin","r+b");
    if(!arquivo){
        printf("Erro ao acessar o arquivo de palavras");
        return;
    }
    fseek(arquivo, (posicao-1)*sizeof(Palavra), SEEK_SET);
    fwrite(" ", sizeof(Palavra), 1, arquivo);
    fclose(arquivo);
    printf("Palavra excluida com sucesso\n");
}

void mostrar(){
    FILE *arquivo = fopen("palavras.bin","rb");
    if(!arquivo){
        printf("Erro ao acessar o arquivo de palavras");
        return;
    }
    printf("        %d PALAVRAS CADASTRADAS         \n", contar_palavras('N'));
    Palavra palavra_buffer;
    while(fread(palavra_buffer.palavra, sizeof(Palavra), 1, arquivo)){
        if(strcmp(palavra_buffer.palavra," ") != 0){
            printf("%s\n", palavra_buffer.palavra);
        }
    }
    fclose(arquivo);
}

int verificar_formato(char *palavra){
    // PASSAR PARA MAISCULO
    maiusculo(palavra);

    // VERIFICA SE A PALAVRA TEM ENTRE 5 E 50 LETRAS
    if(strlen(palavra) < 5 || strlen(palavra) > MAX_PALAVRA){
        printf("A palavra deve conter entre 5 e 50 letras\n");
        return 1;
    }
    
    // VERIFICA SE É ALFABÉTICO
    for(int i=0; palavra[i] != '\0'; i++){
        if(!isalpha(palavra[i])){
            printf("A palavra só pode conter letras de A-Z\n");
            return 1;
        }
    }

    return 0;
}

int posicao_palavra(char *palavra){
    FILE *arquivo = fopen("palavras.bin","rb");
    if(!arquivo){
        printf("Erro ao acessar o arquivo de palavras");
        return 0;
    }
    Palavra palavra_buffer;
    int contador=0, existencia=0;

    // VARRE O ARQUIVO ATÉ ACHAR A PALAVRA
    while(fread(&palavra_buffer, sizeof(Palavra), 1, arquivo)){
        contador++;
        if(strcmp(palavra_buffer.palavra, palavra) == 0){
            existencia = 1;
            break;
        }
    }

    fclose(arquivo);

    // VERIFICA SE EXISTE, SE SIM, RETORNA A POSIÇÃO, SE NÃO, RETORNA ZERO
    if(existencia) return contador;
    else{
        printf("Essa palavra não está cadastrada.\n");
        return 0;
    }
}

int verificar_existencia(char *palavra){
    FILE *arquivo = fopen("palavras.bin","rb");
    if(!arquivo){
        printf("Erro ao acessar o arquivo de palavras");
        return 1;
    }
    Palavra palavra_buffer;

    // VARRE O ARQUIVO TENTANDO ACHAR A PALAVRA
    while(fread(&palavra_buffer, sizeof(Palavra), 1, arquivo)){
        if(strcmp(palavra, palavra_buffer.palavra) == 0){
            printf("Essa palavra já está cadastrada.\n");
            fclose(arquivo);
            return 1;
        }
    }
    fclose(arquivo);
    return 0;
}

int contar_palavras(char removidos){
    FILE *arquivo = fopen("palavras.bin","rb");
    Palavra palavra_buffer;
    int contador=0;

    // CONTA AS PALAVRAS INCLUINDO AS EXCLUIDAS
    if(removidos == 'S'){
        while(fread(&palavra_buffer, sizeof(Palavra), 1, arquivo)) contador++;
    }

    // CONTA AS PALAVRAS SEM CONTAR AS EXCLUIDAS
    else{
        while(fread(&palavra_buffer, sizeof(Palavra), 1, arquivo)){
            if(strcmp(palavra_buffer.palavra," ") != 0){
                contador++;
            }
        }
    }

    fclose(arquivo);
    return contador;
}

void maiusculo(char *palavra){
    for(int i=0; palavra[i] != '\0'; i++) palavra[i] = toupper(palavra[i]);
}

void minusculo(char *palavra){
    for(int i=0; palavra[i] != '\0'; i++) palavra[i] = tolower(palavra[i]);
}