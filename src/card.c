#ifndef CARD_C_INCLUDED
#define CARD_C_INCLUDED

#include "structs.h"
#include "colecao.h"

/* Funcoes basicas */
#include "estrutura_util.c"
#include "basico.c"
#include "estrutura_jogo.c"

void DesenhaRupee(struct Rupee_bitmaps *rbmp,int valor,int posX,int posY) {
    if(valor < 400) al_draw_scaled_bitmap(rbmp->rupee1, 0, 0, 163, 246, posX, posY, 20, 20, 0);
    else if(valor < 800) al_draw_scaled_bitmap(rbmp->rupee2, 0, 0, 163, 246, posX, posY, 20, 20, 0);
    else if(valor < 2000) al_draw_scaled_bitmap(rbmp->rupee3, 0, 0, 163, 246, posX, posY, 20, 20, 0);
    else if(valor < 10000) al_draw_scaled_bitmap(rbmp->rupee4, 0, 0, 163, 246, posX, posY, 20, 20, 0);
    else al_draw_scaled_bitmap(rbmp->rupee5, 0, 0, 163, 246, posX, posY, 20, 20, 0);
}

void LiberaListaShopCards(struct ProfShopCard *inicio) {
    struct ProfShopCard *aux3,*aux4;

    if(inicio->prox == NULL) return;
    aux3 = inicio;
    while(aux3->prox != NULL) {
        aux4 = aux3;
        aux3 = aux3->prox;

        free(aux4);
    }
    free(aux3);
}

void LiberaListaCards(struct ProfCard *inicio) {
    struct ProfCard *aux3,*aux4;

    if(inicio->prox == NULL) return;
    aux3 = inicio;
    while(aux3->prox != NULL) {
        aux4 = aux3;
        aux3 = aux3->prox;

        free(aux4);
    }
    free(aux3);
}

void LiberaProfile(struct PROFILE *prof) {
    struct PROFILE *aux,*aux2;

    if(prof == NULL) return;
    aux = prof;
    while(aux->prox != NULL) {
        aux2 = aux;
        aux = aux->prox;

        LiberaListaCards(aux2->char_deck);
        LiberaListaCards(aux2->deck);
        LiberaListaCards(aux2->side_deck);
        LiberaListaShopCards(aux2->trade_deck);

        free(aux2->nome);
        free(aux2);
    }
    free(aux);
    printf("Libera Profiles OK!\n");
}

bool ehNumero(char *input) {
    int i;

    for (i = 0;i < strlen(input);i++) {
        if(input[i] < '0' || input[i] > '9') {
            return(false);
        }
    }

    return(true);
}

void CarregaProfile(struct PROFILE **prof,struct COLECAO *colecao) {     //este parametro corresponde ao arquivo-lista de profiles.
    char *nome,*nome2,*tok,*profile,*temp;   //vai ler tudo dos profiles, inclusive os NOMES das cartas!
    bool toggle;
    FILE *lista_prof,*arq;
    struct PROFILE *aux;
    struct ProfCard *aux2;
    struct ProfShopCard *aux3;

    lista_prof = fopen("profiles/lista.pfl","r+t");
    if(lista_prof == NULL) lista_prof = fopen("profiles/lista.pfl","w+t");
    if(lista_prof == NULL) {
        printf("Nao foi possivel criar lista.pfl!\n");
        return;
    }

    temp = (char *)calloc(50,sizeof(char));
    nome  = (char *)calloc(30,sizeof(char));
    nome2 = (char *)calloc(50,sizeof(char));
    profile = (char *)calloc(42,sizeof(char));
    *prof = (struct PROFILE *)calloc(1,sizeof(struct PROFILE));
    aux = *prof;
    aux->prox = NULL;

    while(1) {
        fgets(nome,30,lista_prof);
        if(feof(lista_prof)) break;
        nome[strlen(nome) - 1] = 0;

        profile[0] = 0;
        strcat(profile,"profiles/");
        strcat(profile,nome);
        strcat(profile,".prf");

        arq = fopen(profile,"r+t");
        if(arq != NULL) {
            aux->main_character = -1;
            aux->nome = (char *)calloc(30,sizeof(char));
            strcpy(aux->nome,nome);

            fscanf(arq,"%d",&(aux->level));
            fscanf(arq,"%d",&(aux->exp));
            fscanf(arq,"%ld",&(aux->moeda));
            fscanf(arq,"%d",&(aux->qte_deck));
            fscanf(arq,"%d",&(aux->MAX_deck));
            fgets(nome2,50,arq);
            toggle = false;

            while(1) {
                fgets(nome2,50,arq);
                if(feof(arq)) break;
                nome2[strlen(nome2) - 1] = 0;

                if(strcmp(nome2,"CHAR_DECK") == 0) {
                    aux->char_deck = (struct ProfCard *)calloc(1,sizeof(struct ProfCard));
                    aux->char_deck->prox = NULL;
                    aux2 = aux->char_deck;
                }
                else if(strcmp(nome2,"DECK") == 0) {
                    aux->deck = (struct ProfCard *)calloc(1,sizeof(struct ProfCard));
                    aux->deck->prox = NULL;
                    aux2 = aux->deck;
                }
                else if(strcmp(nome2,"SIDE_DECK") == 0) {
                    aux->side_deck = (struct ProfCard *)calloc(1,sizeof(struct ProfCard));
                    aux->side_deck->prox = NULL;
                    aux2 = aux->side_deck;
                }
                else if(strcmp(nome2,"TRADE_DECK") == 0) {
                    aux->trade_deck = (struct ProfShopCard *)calloc(1,sizeof(struct ProfShopCard));
                    aux->trade_deck->prox = NULL;
                    aux3 = aux->trade_deck;
                    toggle = true;
                }
                else if(!toggle) {
                    aux2->card = ConverteNomeParaId(nome2,colecao);

                    aux2->prox = (struct ProfCard *)calloc(1,sizeof(struct ProfCard));
                    aux2 = aux2->prox;
                    aux2->prox = NULL;
                }
                else {
                        //referente ao TRADE DECK
                    tok = strtok(nome2," ");
                    strcpy(temp,tok);

                    tok = strtok(NULL," ");
                    while(!ehNumero(tok)) {
                        temp[strlen(temp) + 1] = '\0';
                        temp[strlen(temp)] = ' ';

                        temp = strcat(temp,tok);
                        tok = strtok(NULL," ");
                    }
                    aux3->card = ConverteNomeParaId(temp,colecao);
                    aux3->preco = atoi(tok);

                    tok = strtok(NULL,"\0");
                    aux3->quantidade = atoi(tok);

                    aux3->prox = (struct ProfShopCard *)calloc(1,sizeof(struct ProfShopCard));
                    aux3 = aux3->prox;
                    aux3->prox = NULL;
                }
            }

            aux->prox = (struct PROFILE *)calloc(1,sizeof(struct PROFILE));
            aux = aux->prox;
            aux->prox = NULL;

            fclose(arq);
        }
    }

    free(temp);
    free(nome);
    free(nome2);
    free(profile);
    fclose(lista_prof);

    printf("Carregando Profiles OK!\n");
}

bool TestaCardNoDeck(struct ListaCards *deck_atual,struct Card *card) {
    struct ListaCards *aux;

    if(card == NULL) return(false);

    aux = deck_atual;
    while(aux->prox != NULL) {
        if(strcmp(aux->card->nome,card->nome) == 0) return(true);
        aux = aux->prox;
    }
    if(aux->prox == NULL) return(true);

    return(false);
}

int GeraPreco(int lvl_profile,struct Card *card) {
    int valor,min,max,diff2;
    float m_rar,m_prof,diff,i;

    switch(card->RARIDADE) {
        case 1:
            m_rar = 3.0;
            i = 5.0;
            break;

        case 3:
            m_rar = 1.7;
            i = 3.0;
            break;

        case 7:
            m_rar = 1.0;
            i = 1.0;
            break;

        default:
            m_rar = 1.0;
            i = 1.0;
            printf("ERRO: raridade nao identificada em '%s'\n",card->nome);
    }

    diff = pow(i * RecuperaCardLevel(card), 0.5035) - lvl_profile;
    if(diff > 0) m_prof = (0.12*diff) + 0.7;
    else m_prof = (-0.08*diff) + 0.7;

    if(m_prof > 1.2) m_prof = 1.2;

    valor = card->preco * m_prof * m_rar;
    min = 0.8 * valor;
    max = 1.2 * valor;

    diff2 = max - min;
    valor = rand() % (diff2 + 1);
    valor += min;

    if(valor < 30) valor = 30;
    else if(valor > 2500) valor = 2500;

    return(valor);
}

void RandomCard(bool gera_preco,int lvl_profile,int **preco_gerado,struct Card **vetor,int max_cards,struct ListaCards *deck) {
    unsigned int i,j,inicio = 0,contador = 0,soma_raridade = 0,x;   //A funcao gera UM card que eh colocado no final da lista DECK.
    struct ListaCards *aux;
    struct Card *card = NULL;
    char **vetor_aleatorio,*nome_card;

    nome_card = (char *)malloc(55*sizeof(char));

    for(i = 0;i < max_cards;i++) {
        soma_raridade = vetor[i]->RARIDADE + soma_raridade;
    }
    vetor_aleatorio = (char **)calloc(soma_raridade,sizeof(char *));

    for(i = 0;i < max_cards;i++) {                   //monta um vetor que representa a aleatoriedade.
        for(j = 0;j < vetor[i]->RARIDADE;j++) {      //no caso, cada carta representa um determinado espaco no vetor aleatorio.
            vetor_aleatorio[contador] = vetor[i]->nome;
            contador++;
        }
    }

    while(1) {
        x = rand() % (soma_raridade);
        strcpy(nome_card,vetor_aleatorio[x]);

        for(j = inicio;j < max_cards; j++) {
            if(strcmp(nome_card,vetor[j]->nome) == 0) {
                card = vetor[j];
                inicio = j + 1;
                break;
            }
        }

        if(TestaCardNoDeck(deck,card) == true || j == max_cards) break;
    }
    if(j == max_cards) {
        free(vetor_aleatorio);
        free(nome_card);

        return;
    }

    aux = deck;
    i = 0;
    while(aux->prox != NULL) {
        if(strcmp(aux->card->nome,card->nome) == 0) {
            aux->contador++;
            if(gera_preco == true) (*preco_gerado)[i] = GeraPreco(lvl_profile,card);
            break;
        }

        i++;
        aux = aux->prox;
    }
    if(aux->prox == NULL) {
        if(gera_preco == true) {
            (*preco_gerado) = (int *)realloc(*preco_gerado,(i+1)*sizeof(int));
            (*preco_gerado)[i] = GeraPreco(lvl_profile,card);
        }

        aux->contador = 1;
        aux->card = card;

        aux->prox = (struct ListaCards *)malloc(sizeof(struct ListaCards));
        aux = aux->prox;
        aux->prox = NULL;
    }

    free(vetor_aleatorio);
    free(nome_card);
}

char* EscreveDeck(struct ListaCards *deck) {
    char *texto;
    unsigned int cont = 0,i;
    struct ListaCards *aux;

    aux = deck;
    while(aux->prox != NULL) {
        cont = cont + aux->contador*(strlen(aux->card->nome) + 1);
        aux = aux->prox;
    }

    texto = (char *)calloc(cont + 1,sizeof(char));
    texto[0] = 0;

    aux = deck;
    while(aux->prox != NULL) {
        for(i = 0;i < aux->contador;i++) {
            strcat(texto,aux->card->nome);
            strcat(texto,"\n");
        }
        aux = aux->prox;
    }

    return(texto);
}

//ATENCAO: CARDS insuficientes para que esta FUNCAO SEJA COMPLETA!!!!!!!! Vai dar erro por falta de cards!
char* SorteiaDeck(struct ListaCards **colecao,int *total,int modo) {
    char *lista,*str1,*str2;
    unsigned int i,j,cont = 0;
    struct ListaCards *aux,*aux2,*deck_atual;
    struct Card **vetor;

    for(i = 0; i < 8;i++) {
        aux = colecao[i];
        while(aux->prox != NULL) {
            cont++;
            aux = aux->prox;
        }
    }

    switch (modo) {
        case 0:
            str1 = "Earth";
            str2 = "Wind";
            break;

        case 1:
            str1 = "Fire";
            str2 = "Water";
            break;

        case 2:
            str1 = "Light";
            str2 = "Dark";
            break;

        case 3:
            str1 = "Earth";
            str2 = "Light";
            break;

        case 4:
            str1 = "Wind";
            str2 = "Fire";
            break;

        case 5:
            str1 = "Dark";
            str2 = "Water";
            break;

        case 6:
            str1 = "Earth";
            str2 = "Water";
            break;

        case 7:
            str1 = "Dark";
            str2 = "Fire";
            break;

        case 8:
            str1 = "Wind";
            str2 = "Light";
            break;

        default: printf("WTF?!");
    }

    //RARIDADE:
    //    facil ->   7 em 11
    //    medio ->   3 em 11
    //    dificil -> 1 em 11

    deck_atual = (struct ListaCards *)malloc(sizeof(struct ListaCards));
    deck_atual->prox = NULL;

    aux = colecao[0];
    while(aux->prox != NULL) {    //character elemento 1.
        if(strcmp(aux->card->elemento,str1) == 0) cont++;
        aux = aux->prox;
    }

    vetor = (struct Card **)calloc(cont,sizeof(struct Card *));
    aux = colecao[0];
    i = 0;
    while(aux->prox != NULL) {
        if(strcmp(aux->card->elemento,str1) == 0) {
            vetor[i] = aux->card;
            i++;
        }
        aux = aux->prox;
    }
    RandomCard(false,-1,NULL,vetor,i,deck_atual);
    free(vetor);

    aux = colecao[0];
    cont = 0;
    while(aux->prox != NULL) {    //character elemento 2.
        if(strcmp(aux->card->elemento,str2) == 0) cont++;
        aux = aux->prox;
    }

    vetor = (struct Card **)calloc(cont,sizeof(struct Card *));
    aux = colecao[0];
    i = 0;
    while(aux->prox != NULL) {
        if(strcmp(aux->card->elemento,str2) == 0) {
            vetor[i] = aux->card;
            i++;
        }
        aux = aux->prox;
    }
    RandomCard(false,-1,NULL,vetor,i,deck_atual);
    free(vetor);

    aux = colecao[1];   //10 monstros
    cont = 0;
    while(aux->prox != NULL) {
        if(strcmp(aux->card->elemento,str1) == 0 || strcmp(aux->card->elemento,str2) == 0) cont++;
        aux = aux->prox;
    }
    aux = colecao[4];
    while(aux->prox != NULL) {
        if(strcmp(aux->card->elemento,str1) == 0 || strcmp(aux->card->elemento,str2) == 0) cont++;
        aux = aux->prox;
    }
    aux = colecao[6];
    while(aux->prox != NULL) {
        if(strcmp(aux->card->elemento,str1) == 0 || strcmp(aux->card->elemento,str2) == 0) cont++;
        aux = aux->prox;
    }
    aux = colecao[7];
    while(aux->prox != NULL) {
        if(strcmp(aux->card->elemento,str1) == 0 || strcmp(aux->card->elemento,str2) == 0) cont++;
        aux = aux->prox;
    }


    vetor = (struct Card **)calloc(cont,sizeof(struct Card *));
    aux = colecao[1];
    i = 0;
    while(aux->prox != NULL) {
        if(strcmp(aux->card->elemento,str1) == 0 || strcmp(aux->card->elemento,str2) == 0) {
            vetor[i] = aux->card;
            i++;
        }
        aux = aux->prox;
    }
    aux = colecao[4];
    while(aux->prox != NULL) {
        if(strcmp(aux->card->elemento,str1) == 0 || strcmp(aux->card->elemento,str2) == 0) {
            vetor[i] = aux->card;
            i++;
        }
        aux = aux->prox;
    }
    aux = colecao[6];
    while(aux->prox != NULL) {
        if(strcmp(aux->card->elemento,str1) == 0 || strcmp(aux->card->elemento,str2) == 0) {
            vetor[i] = aux->card;
            i++;
        }
        aux = aux->prox;
    }
    aux = colecao[7];
    while(aux->prox != NULL) {
        if(strcmp(aux->card->elemento,str1) == 0 || strcmp(aux->card->elemento,str2) == 0) {
            vetor[i] = aux->card;
            i++;
        }
        aux = aux->prox;
    }

    for(j = 0;j < 10;j++) RandomCard(false,-1,NULL,vetor,i,deck_atual);
    free(vetor);

    //5 escolhidos de cada tipo
    if(modo == 0 || modo == 1 || modo == 4 || modo == 5 || modo == 6 || modo == 8) {
        cont = 0;
        aux = colecao[2];
        while(aux->prox != NULL) {
            if(strcmp(aux->card->elemento,str1) == 0 || strcmp(aux->card->elemento,str2) == 0) cont++;
            aux = aux->prox;
        }

        vetor = (struct Card **)calloc(cont,sizeof(struct Card *));
        aux = colecao[2];
        i = 0;
        while(aux->prox != NULL) {
            if(strcmp(aux->card->elemento,str1) == 0 || strcmp(aux->card->elemento,str2) == 0) {
                vetor[i] = aux->card;
                i++;
            }
            aux = aux->prox;
        }

        for(j = 0;j < 5;j++) RandomCard(false,-1,NULL,vetor,i,deck_atual);
        free(vetor);
    }
    if(modo == 1 || modo == 2 || modo == 3 || modo == 4 || modo == 7 || modo == 8) {
        cont = 0;
        aux = colecao[3];
        while(aux->prox != NULL) {
            if(strcmp(aux->card->elemento,str1) == 0 || strcmp(aux->card->elemento,str2) == 0) cont++;
            aux = aux->prox;
        }

        vetor = (struct Card **)calloc(cont,sizeof(struct Card *));
        aux = colecao[3];
        i = 0;
        while(aux->prox != NULL) {
            if(strcmp(aux->card->elemento,str1) == 0 || strcmp(aux->card->elemento,str2) == 0) {
                vetor[i] = aux->card;
                i++;
            }
            aux = aux->prox;
        }

        //for(j = 0;j < cont; j++) printf("%s\n",vetor[j]->nome);
        for(j = 0;j < 5;j++) RandomCard(false,-1,NULL,vetor,i,deck_atual);
        free(vetor);
    }

    if(modo == 0 || modo == 2 || modo == 3 || modo == 5 || modo == 6 || modo == 7) {
        cont = 0;
        aux = colecao[1];
        while(aux->prox != NULL) {
            if(strcmp(aux->card->elemento,str1) == 0 || strcmp(aux->card->elemento,str2) == 0) cont++;
            aux = aux->prox;
        }
        aux = colecao[4];
        while(aux->prox != NULL) {
            if(strcmp(aux->card->elemento,str1) == 0 || strcmp(aux->card->elemento,str2) == 0) cont++;
            aux = aux->prox;
        }
        aux = colecao[6];
        while(aux->prox != NULL) {
            if(strcmp(aux->card->elemento,str1) == 0 || strcmp(aux->card->elemento,str2) == 0) cont++;
            aux = aux->prox;
        }
        aux = colecao[7];
        while(aux->prox != NULL) {
            if(strcmp(aux->card->elemento,str1) == 0 || strcmp(aux->card->elemento,str2) == 0) cont++;
            aux = aux->prox;
        }

        vetor = (struct Card **)calloc(cont,sizeof(struct Card *));
        aux = colecao[1];
        i = 0;
        while(aux->prox != NULL) {
            if(strcmp(aux->card->elemento,str1) == 0 || strcmp(aux->card->elemento,str2) == 0) {
                vetor[i] = aux->card;
                i++;
            }
            aux = aux->prox;
        }
        aux = colecao[4];
        while(aux->prox != NULL) {
            if(strcmp(aux->card->elemento,str1) == 0 || strcmp(aux->card->elemento,str2) == 0) {
                vetor[i] = aux->card;
                i++;
            }
            aux = aux->prox;
        }
        aux = colecao[6];
        while(aux->prox != NULL) {
            if(strcmp(aux->card->elemento,str1) == 0 || strcmp(aux->card->elemento,str2) == 0) {
                vetor[i] = aux->card;
                i++;
            }
            aux = aux->prox;
        }
        aux = colecao[7];
        while(aux->prox != NULL) {
            if(strcmp(aux->card->elemento,str1) == 0 || strcmp(aux->card->elemento,str2) == 0) {
                vetor[i] = aux->card;
                i++;
            }
            aux = aux->prox;
        }

        for(j = 0;j < 5;j++) RandomCard(false,-1,NULL,vetor,i,deck_atual);
        free(vetor);
    }


    aux = colecao[5];
    cont = 0;
    while(aux->prox != NULL) {    //1 campo.
        if(strcmp(aux->card->elemento,str1) == 0 || strcmp(aux->card->elemento,str2) == 0) cont++;
        aux = aux->prox;
    }

    vetor = (struct Card **)calloc(cont,sizeof(struct Card *));
    aux = colecao[5];
    i = 0;
    while(aux->prox != NULL) {
        if(strcmp(aux->card->elemento,str1) == 0 || strcmp(aux->card->elemento,str2) == 0) {
            vetor[i] = aux->card;
            i++;
        }
        aux = aux->prox;
    }
    RandomCard(false,-1,NULL,vetor,i,deck_atual);
    free(vetor);

    aux = colecao[1];   //19 aleatorios
    cont = 0;
    while(aux->prox != NULL) {
        if(strcmp(aux->card->elemento,str1) == 0 || strcmp(aux->card->elemento,str2) == 0) cont++;
        aux = aux->prox;
    }
    aux = colecao[2];
    while(aux->prox != NULL) {
        if(strcmp(aux->card->elemento,str1) == 0 || strcmp(aux->card->elemento,str2) == 0) cont++;
        aux = aux->prox;
    }
    aux = colecao[3];
    while(aux->prox != NULL) {
        if(strcmp(aux->card->elemento,str1) == 0 || strcmp(aux->card->elemento,str2) == 0) cont++;
        aux = aux->prox;
    }
    aux = colecao[4];
    while(aux->prox != NULL) {
        if(strcmp(aux->card->elemento,str1) == 0 || strcmp(aux->card->elemento,str2) == 0) cont++;
        aux = aux->prox;
    }
    aux = colecao[5];
    while(aux->prox != NULL) {
        if(strcmp(aux->card->elemento,str1) == 0 || strcmp(aux->card->elemento,str2) == 0) cont++;
        aux = aux->prox;
    }
    aux = colecao[6];
    while(aux->prox != NULL) {
        if(strcmp(aux->card->elemento,str1) == 0 || strcmp(aux->card->elemento,str2) == 0) cont++;
        aux = aux->prox;
    }
    aux = colecao[7];
    while(aux->prox != NULL) {
        if(strcmp(aux->card->elemento,str1) == 0 || strcmp(aux->card->elemento,str2) == 0) cont++;
        aux = aux->prox;
    }

    vetor = (struct Card **)calloc(cont,sizeof(struct Card *));
    i = 0;
    aux = colecao[1];
    while(aux->prox != NULL) {
        if(strcmp(aux->card->elemento,str1) == 0 || strcmp(aux->card->elemento,str2) == 0) {
            vetor[i] = aux->card;
            i++;
        }
        aux = aux->prox;
    }
    aux = colecao[2];
    while(aux->prox != NULL) {
        if(strcmp(aux->card->elemento,str1) == 0 || strcmp(aux->card->elemento,str2) == 0) {
            vetor[i] = aux->card;
            i++;
        }
        aux = aux->prox;
    }
    aux = colecao[3];
    while(aux->prox != NULL) {
        if(strcmp(aux->card->elemento,str1) == 0 || strcmp(aux->card->elemento,str2) == 0) {
            vetor[i] = aux->card;
            i++;
        }
        aux = aux->prox;
    }
    aux = colecao[4];
    while(aux->prox != NULL) {
        if(strcmp(aux->card->elemento,str1) == 0 || strcmp(aux->card->elemento,str2) == 0) {
            vetor[i] = aux->card;
            i++;
        }
        aux = aux->prox;
    }
    aux = colecao[5];
    while(aux->prox != NULL) {
        if(strcmp(aux->card->elemento,str1) == 0 || strcmp(aux->card->elemento,str2) == 0) {
            vetor[i] = aux->card;
            i++;
        }
        aux = aux->prox;
    }
    aux = colecao[6];
    while(aux->prox != NULL) {
        if(strcmp(aux->card->elemento,str1) == 0 || strcmp(aux->card->elemento,str2) == 0) {
            vetor[i] = aux->card;
            i++;
        }
        aux = aux->prox;
    }
    aux = colecao[7];
    while(aux->prox != NULL) {
        if(strcmp(aux->card->elemento,str1) == 0 || strcmp(aux->card->elemento,str2) == 0) {
            vetor[i] = aux->card;
            i++;
        }
        aux = aux->prox;
    }

    for(j = 0;j < 19;j++) RandomCard(false,-1,NULL,vetor,i,deck_atual);
    free(vetor);

    lista = EscreveDeck(deck_atual);

    aux = deck_atual;
    while(aux->prox != NULL) {
        aux2 = aux;
        aux = aux->prox;
        free(aux2);
    }
    free(aux);

    return(lista);
}

struct PROFILE* EscolheProfile(struct PROFILE *lista_pfl,ALLEGRO_DISPLAY *janela,ALLEGRO_FONT *text,ALLEGRO_FONT *font,ALLEGRO_COLOR color,ALLEGRO_BITMAP *pont,ALLEGRO_BITMAP *entrada,ALLEGRO_BITMAP *selecao,bool *sair,int *posX,int *posY,int *dltZ,bool *mouse,bool *mouse2,bool *mouse_lado,int *keychar,bool *repete_keychar,ALLEGRO_EVENT_QUEUE *event_queue,ALLEGRO_TIMER *keyb_press_timer,ALLEGRO_TIMER *mouse_press_timer) {
    struct PROFILE *aux = NULL,**vetor;
    int i,max_pagina,pagina,opcao = -1,contador = 0;

    if(lista_pfl == NULL) return(NULL);

    font = al_load_ttf_font("data/triforce.ttf",32, 0);

    aux = lista_pfl;
    while(aux->prox != NULL) {
        aux = aux->prox;
        contador++;
    }

    vetor = (struct PROFILE **)calloc(contador,sizeof(struct PROFILE *));
    aux = lista_pfl;
    i = 0;
    while(aux->prox != NULL) {
        vetor[i] = aux;
        aux = aux->prox;
        i++;
    }

    max_pagina = i / 12;    //12 profiles por página.
    pagina = 0;

    while(1) {
        VerificaEventos(sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);

        al_draw_bitmap(entrada,0,0,0);
        for(i = 0;i < 12;i++) {
            if(12*pagina + i < contador) {
                if(opcao == 12*pagina + i) al_draw_scaled_bitmap(selecao,0,0,240,360,5 + 400*(i % 2),315 + 30*(i / 2),390,40,0);
                al_draw_textf(font,color,10 + 400*(i % 2),320 + 30*(i / 2),0,"%s",vetor[12*pagina + i]->nome);
            }
            else break;
        }

        if(opcao != -1) al_draw_textf(text,color,215,230,0,"%s",vetor[opcao]->nome);
        al_draw_textf(font,color,655,245,0,"%d",pagina + 1);
        al_draw_textf(font,color,735,245,0,"%d",max_pagina + 1);

        if(*posX >= 190 && *posX < 610) {
            if(opcao != -1 && *posY >= 205 && *posY < 295) {
                if(*mouse == true) {
                    //al_rest(0.2);
                    break;
                }
                else al_draw_bitmap(pont,130,225,ALLEGRO_FLIP_HORIZONTAL);
            }
            else if(*posY >= 505 && *posY < 595) {
                if(*mouse == true) {
                    //al_rest(0.2);
                    return(NULL);
                }
                else al_draw_bitmap(pont,610,525,0);
            }
        }
        if(*mouse == true) {
            if(pagina < max_pagina && *posX >= 630 && *posX < 680 && *posY >= 175 && *posY < 225) pagina++;
            else if(pagina > 0 && *posX >= 730 && *posX < 780 && *posY >= 175 && *posY < 225) pagina--;

            for(i = 0;i < 12;i++) {
                if(12*pagina + i < contador) {
                    if(*posX >= 5 + 400*(i % 2) && *posX < 375 + 400*(i % 2) && *posY >= 315 + 30*(i / 2) && *posY < 355 + 30*(i / 2)) {
                        opcao = 12*pagina + i;
                        break;
                    }
                }
                else break;
            }
        }

        al_flip_display();
        //al_wait_for_event_timed(event_queue,&ev,0.05);
        if(*sair == true) return(NULL);
    }
    aux = vetor[opcao];

    free(vetor);

    return(aux);
}

void SorteiaTradeDeck(int **preco_gerado,int lvl_profile,struct ListaCards **colecao,int num_cards,struct ListaCards *deck_atual) {
    int i,j,cont;
    struct ListaCards *aux;
    struct Card **vetor;

    for(i = 0; i < 8;i++) {
        aux = colecao[i];
        while(aux->prox != NULL) {
            cont++;
            aux = aux->prox;
        }
    }

    vetor = (struct Card **)calloc(cont,sizeof(struct Card *));     //junta todos os cards da colecao num unico vetor.
    j = 0;
    for(i = 0;i < 8;i++) {
        aux = colecao[i];
        while(aux->prox != NULL) {
            vetor[j] = aux->card;
            j++;

            aux = aux->prox;
        }
    }

    for(i = 0;i < num_cards;i++) RandomCard(true,lvl_profile,preco_gerado,vetor,j,deck_atual);
    free(vetor);
}

void TrataSimbolo(char *buffer,int *indice,char simbolo) {
    printf("entra aq\n");
    buffer[*indice] = simbolo;
    (*indice)++;
}

bool ChatBox(int max_tam,char *buffer,int *indice,int *keychar,bool *repete_keychar) {
    //necessita de uma chamada externa para TRATAR EVENTOS, esta funcao somente coleta dados encontrados de MENSAGENS.
    //retorna se chegou no fim da msg

    if(*repete_keychar == true) {
        printf("%d/%d %s: %d\n",*indice,max_tam,al_keycode_to_name(*keychar),*keychar);

        if(*keychar == ALLEGRO_KEY_ENTER) return(true); //ENTER -> fim de mensagem, obrigatorio
        if(*keychar == ALLEGRO_KEY_BACKSPACE) {
            if(*indice > 0) {
                buffer[*indice] = 0;
                (*indice)--;
            }
        }

        if(*indice < max_tam) {
            if(*keychar == 17) TrataSimbolo(buffer,indice,'q');
            else if(*keychar == ALLEGRO_KEY_W) TrataSimbolo(buffer,indice,'w');
            else if(*keychar == ALLEGRO_KEY_E) TrataSimbolo(buffer,indice,'e');
            else if(*keychar == ALLEGRO_KEY_R) TrataSimbolo(buffer,indice,'r');
            else if(*keychar == ALLEGRO_KEY_T) TrataSimbolo(buffer,indice,'t');
            else if(*keychar == ALLEGRO_KEY_Y) TrataSimbolo(buffer,indice,'y');
            else if(*keychar == ALLEGRO_KEY_U) TrataSimbolo(buffer,indice,'u');
            else if(*keychar == ALLEGRO_KEY_I) TrataSimbolo(buffer,indice,'i');
            else if(*keychar == ALLEGRO_KEY_O) TrataSimbolo(buffer,indice,'o');
            else if(*keychar == ALLEGRO_KEY_P) TrataSimbolo(buffer,indice,'p');
            else if(*keychar == ALLEGRO_KEY_A) TrataSimbolo(buffer,indice,'a');
            else if(*keychar == ALLEGRO_KEY_S) TrataSimbolo(buffer,indice,'s');
            else if(*keychar == ALLEGRO_KEY_D) TrataSimbolo(buffer,indice,'d');
            else if(*keychar == ALLEGRO_KEY_F) TrataSimbolo(buffer,indice,'f');
            else if(*keychar == ALLEGRO_KEY_G) TrataSimbolo(buffer,indice,'g');
            else if(*keychar == ALLEGRO_KEY_H) TrataSimbolo(buffer,indice,'h');
            else if(*keychar == ALLEGRO_KEY_J) TrataSimbolo(buffer,indice,'j');
            else if(*keychar == ALLEGRO_KEY_K) TrataSimbolo(buffer,indice,'k');
            else if(*keychar == ALLEGRO_KEY_L) TrataSimbolo(buffer,indice,'l');
            else if(*keychar == ALLEGRO_KEY_Z) TrataSimbolo(buffer,indice,'z');
            else if(*keychar == ALLEGRO_KEY_X) TrataSimbolo(buffer,indice,'x');
            else if(*keychar == ALLEGRO_KEY_C) TrataSimbolo(buffer,indice,'c');
            else if(*keychar == ALLEGRO_KEY_V) TrataSimbolo(buffer,indice,'v');
            else if(*keychar == ALLEGRO_KEY_B) TrataSimbolo(buffer,indice,'b');
            else if(*keychar == ALLEGRO_KEY_N) TrataSimbolo(buffer,indice,'n');
            else if(*keychar == ALLEGRO_KEY_M) TrataSimbolo(buffer,indice,'m');

            else if(*keychar == ALLEGRO_KEY_0) TrataSimbolo(buffer,indice,'0');
            else if(*keychar == ALLEGRO_KEY_1) TrataSimbolo(buffer,indice,'1');
            else if(*keychar == ALLEGRO_KEY_2) TrataSimbolo(buffer,indice,'2');
            else if(*keychar == ALLEGRO_KEY_3) TrataSimbolo(buffer,indice,'3');
            else if(*keychar == ALLEGRO_KEY_4) TrataSimbolo(buffer,indice,'4');
            else if(*keychar == ALLEGRO_KEY_5) TrataSimbolo(buffer,indice,'5');
            else if(*keychar == ALLEGRO_KEY_6) TrataSimbolo(buffer,indice,'6');
            else if(*keychar == ALLEGRO_KEY_7) TrataSimbolo(buffer,indice,'7');
            else if(*keychar == ALLEGRO_KEY_8) TrataSimbolo(buffer,indice,'8');
            else if(*keychar == ALLEGRO_KEY_9) TrataSimbolo(buffer,indice,'9');

            else if(*keychar == ALLEGRO_KEY_MINUS) TrataSimbolo(buffer,indice,'_');
        }
        //outros simbolos.... OBS.: nao estou tratando o buffer que esta retornando para a funcao CriarProfile,
        //portanto para adicionar outros simbolos sera preciso efetuar certos 'cuidados' para que nao haja demais repercussoes com o S.O.

        buffer[*indice] = 0;
    }

    return(false);  //mensagem ainda nao foi completada pelo usuario
}


void CriarProfile(struct ListaCards **colecao,int *total,struct PROFILE *lista_pfl,ALLEGRO_DISPLAY *janela,ALLEGRO_FONT *font,ALLEGRO_FONT *font2,ALLEGRO_COLOR color,ALLEGRO_BITMAP *fundo,ALLEGRO_BITMAP *selecao,ALLEGRO_BITMAP *botao,ALLEGRO_BITMAP **cor_retangulo,ALLEGRO_BITMAP **estilo_deck,bool *sair,int *posX,int *posY,int *dltZ,bool *mouse,bool *mouse2,bool *mouse_lado,int *keychar,bool *repete_keychar,ALLEGRO_EVENT_QUEUE *event_queue,ALLEGRO_TIMER *keyb_press_timer,ALLEGRO_TIMER *mouse_press_timer) {
    FILE *lista_profiles,*profile;
    struct PROFILE *aux;
    struct ListaCards *deck,*aux2,*aux3;
    char *lista_cards,*prof,*prof2,*prof3,*trecho;
    int modo = -1,indice,i,*preco_gerado = NULL;
    bool valor = false,fim_msg = false;

    lista_profiles = fopen("profiles/lista.pfl","a+t");
    prof = (char *)calloc(20,sizeof(char));
    prof[0] = 0;

    while(1) {
        al_draw_bitmap(fundo,0,0,0);
        if(valor == true) {
            al_draw_bitmap(cor_retangulo[2],745,170,0);
            al_draw_textf(font,color,310,165,0,"%s",prof);
        }

        VerificaEventos(sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);

        if(*sair == true) break;
        if(*posX >= 545 && *posX < 775 && *posY >= 510 && *posY < 580 && *mouse == true && valor == true && modo != -1) break;
        else if(*posX >= 15 && *posX < 285 && *posY >= 145 && *posY < 225 && *mouse == true) {
            indice = 0;
            prof[0] = 0;

            while(1) {
                VerificaEventos(sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);
                al_draw_bitmap(fundo,0,0,0);
                al_draw_bitmap(botao,15,146,0);
                al_draw_textf(font,color,75,170,0,"APLICAR");

                if(*mouse == true && *posX >= 545 && *posX < 775 && *posY >= 415 && *posY < 485) return; //volta sem salvar.

                if(*sair == true) return;
                fim_msg = ChatBox(20,prof,&indice,keychar,repete_keychar);

                al_draw_textf(font,color,300,165,0,"%s_",prof);
                if(prof[0] != 0) {
                    aux = lista_pfl;
                    while(aux->prox != NULL) {
                        if(strcmp(aux->nome,prof) == 0) break;
                        aux = aux->prox;
                    }

                    if(aux->prox != NULL) al_draw_bitmap(cor_retangulo[0],745,170,0);
                    else {
                        al_draw_bitmap(cor_retangulo[1],745,170,0);
                        if(/* *repete_keychar == true && *keychar == ALLEGRO_KEY_ENTER*/fim_msg == true || (*mouse == true && *posX >= 15 && *posX < 285 && *posY >= 145 && *posY < 235)) {
                            valor = true;
                            break;
                        }
                    }

                }
                else al_draw_bitmap(cor_retangulo[0],745,170,0);

                al_flip_display();
            }
        }
        else {
            for(i = 0;i < 9;i++) {
                if(i < 6 && *posX >= 20 + 110*(i % 3) && *posX < 120 + 110*(i % 3) && *posY >= 265 + 160*(i / 3) && *posY < 415 + 160*(i / 3) && *mouse == true) {
                    modo = i;
                    break;
                }
                else if(i >= 6 && *posX >= 350 && *posX < 417 && *posY >= 265 + 105*(i-6) && *posY < 365 + 105*(i-6) && *mouse == true) {
                    modo = i;
                    break;
                }
            }

            if(*posX >= 545 && *posX < 775 && *posY >= 415 && *posY < 485 && *mouse == true) return; //volta sem salvar.
        }

        for(i = 0;i < 9;i++) {
            if(modo == i) {
                if(i < 6) al_draw_scaled_bitmap(selecao,0,0,240,360,15 + 110*(i % 3),260 + 160*(i / 3),110,160,0);
                else if(i >= 6) al_draw_scaled_bitmap(selecao,0,0,240,360,347.5,262.5 + 105*(i-6),70,105,0);
            }
            if(i < 6) al_draw_scaled_bitmap(estilo_deck[i],0,0,240,360,20 + 110*(i % 3),265 + 160*(i / 3),100,150,0);
            else al_draw_scaled_bitmap(estilo_deck[i],0,0,240,360,350,265 + 105*(i-6),65,100,0);
        }

        al_flip_display();
    }

    prof2 = (char *)calloc(33,sizeof(char));
    prof2[0] = 0;
    strcat(prof2,prof);
    strcat(prof2,".prf");

    prof3 = (char *)calloc(42,sizeof(char));
    prof3[0] = 0;
    strcat(prof3,"profiles/");
    strcat(prof3,prof2);

    profile = fopen(prof3,"r+t");
    if(profile == NULL) {
        profile = fopen(prof3,"w+t");
        fprintf(lista_profiles,"%s\n",prof);

        fprintf(profile,"1 ");     //lvl
        fprintf(profile,"0 ");     //exp
        fprintf(profile,"0 ");     //moeda
        fprintf(profile,"40 ");    //qtecards
        fprintf(profile,"40\n");    //max_deck

        lista_cards = SorteiaDeck(colecao,total,modo);

        fprintf(profile,"CHAR_DECK\n");
        trecho = strtok(lista_cards,"\n");

        fprintf(profile,"%s\n",trecho);
        trecho = strtok(NULL,"\n");

        fprintf(profile,"%s\n",trecho);
        trecho = strtok(NULL,"\0");
        fprintf(profile,"DECK\n%sSIDE_DECK\nTRADE_DECK\n",trecho);

        free(lista_cards);

        //---------------------------------------------------------------------------
        deck = (struct ListaCards *)malloc(sizeof(struct ListaCards));
        deck->prox = NULL;

        preco_gerado = NULL;
        SorteiaTradeDeck(&preco_gerado,1,colecao,4,deck);

        aux2 = deck;
        i = 0;
        while(aux2->prox != NULL) {
            fprintf(profile,"%s %d %d\n",aux2->card->nome,preco_gerado[i],aux2->contador);
            i++;
            aux2 = aux2->prox;
        }

        aux2 = deck;
        aux3 = NULL;
        while(aux2->prox != NULL) {
            aux3 = aux2;
            aux2 = aux2->prox;
            free(aux3);
        }
        free(aux2);

        free(preco_gerado);
        //---------------------------------------------------------------------------

    }
    else printf("FATAL ERROR!");

    fclose(lista_profiles);
    fclose(profile);

    free(prof3);
    free(prof2);
    free(prof);
}

void TransfereCard(struct Card ***vetor_origem,struct Card ***vetor_destino,int **origem,int **destino) {
    struct Card *aux;
    int i;

    aux = (*vetor_origem)[(*origem)[2]];  //transfere card escolhido para o final do vetor destino.
    for(i = (*origem)[2]; i < (*origem)[3] - 1; i++) {
        (*vetor_origem)[i] = (*vetor_origem)[i + 1];
    }

    ((*origem)[3])--;
    ((*destino)[3])++;

    *vetor_origem = (struct Card **)realloc(*vetor_origem,((*origem)[3])*sizeof(struct Card *));
    *vetor_destino = (struct Card **)realloc(*vetor_destino,((*destino)[3])*sizeof(struct Card *));

    (*vetor_destino)[(*destino)[3] - 1] = aux;
    (*origem)[2] = -1;  //redefine a escolha para uma posicao inexistente.
}

bool ControlaQteCopias(char *nome,struct Card **vetor,int total,int **sdeck) {
    int i,cont = 0;

    for (i = 0;i < total;i++) {
        if(strcmp(vetor[i]->nome,nome) == 0) {
            cont++;
            if(cont == 4) {
                (*sdeck)[2] = -1;
                return(false);
            }
        }
    }

    return(true);
}

void Particao2(int Esq,int Dir,int *i,int *j,struct Card **A,bool modo) {
    struct Card *x, *w;

    *i = Esq;
    *j = Dir;
    x = A[(*i + *j) / 2]; /* obtem o pivo x */
    do {
        if(modo == true) {
            while (strcmp(x->nome,A[*i]->nome) > 0) (*i)++;
            while (strcmp(x->nome,A[*j]->nome) < 0) (*j)--;
        }
        else {
            while (strcmp(x->tipo,A[*i]->tipo) > 0) (*i)++;
            while (strcmp(x->tipo,A[*j]->tipo) < 0) (*j)--;
        }
        if (*i <= *j) {
            w = A[*i];
            A[*i] = A[*j];
            A[*j] = w;

            (*i)++;
            (*j)--;
        }
    } while (*i <= *j);
}

void Quicksort2(int Esq,int Dir,struct Card **A,bool modo) {
    int i,j;

    if(Esq == Dir) return;

    Particao2(Esq, Dir, &i, &j, A, modo);
    if (Esq < j) Quicksort2(Esq, j, A, modo);
    if (i < Dir) Quicksort2(i, Dir, A, modo);
}

void OrganizaDeck(int total,struct Card **vetor) {
    int intersecao[15],i,j;

    for(i = 0; i < 15;i++) intersecao[i] = 0;
    Quicksort2(0, total - 1, vetor, false);

    j = 0;
    for(i = 0;i < total - 1;i++) {
        if(strcmp(vetor[i]->tipo,vetor[i + 1]->tipo) != 0) {
            intersecao[j + 1] = i + 1;
            j++;
        }
    }
    intersecao[0] = 0;
    intersecao[j + 1] = total;

    for(i = 0;i <= j;i++) Quicksort2(intersecao[i], intersecao[i + 1] - 1, vetor, true);
}

void InicializaVetorCards(struct ProfCard *inicio,struct Card ***vetor,struct COLECAO *colecao,int **valor) {
    struct ProfCard *aux;
    unsigned int cont = 0;

    (*valor)[0] = 0;
    (*valor)[2] = -1;
    if(inicio == NULL || inicio->prox == NULL) {
        (*valor)[3] = 0;
        return;
    }

    aux = inicio;
    while(aux->prox != NULL) {
        cont++;
        aux = aux->prox;
    }

    *vetor = (struct Card **)malloc(cont*sizeof(struct Card *));
    aux = inicio;
    cont = 0;
    while(aux->prox != NULL) {
        CarregaCard(aux->card,&(*vetor)[cont],colecao);

        aux = aux->prox;
        cont++;
    }

    (*valor)[3] = cont;
    OrganizaDeck(cont,*vetor);
}

void InicializaVetorShopCards(struct ProfShopCard *inicio,struct Card ***vetor,int **preco_cards,int **qte_cards,struct COLECAO *colecao,int **valor) {
    struct ProfShopCard *aux;
    unsigned int cont = 0;

    (*valor)[0] = 0;
    (*valor)[2] = -1;
    if(inicio == NULL || inicio->prox == NULL) {
        (*valor)[3] = 0;
        return;
    }

    aux = inicio;
    while(aux->prox != NULL) {
        cont++;
        aux = aux->prox;
    }

    *vetor = (struct Card **)malloc(cont*sizeof(struct Card *));
    *preco_cards = (int *)calloc(cont,sizeof(int));
    *qte_cards = (int *)calloc(cont,sizeof(int));
    aux = inicio;
    cont = 0;
    while(aux->prox != NULL) {
        CarregaCard(aux->card,&(*vetor)[cont],colecao);
        (*preco_cards)[cont] = aux->preco;
        (*qte_cards)[cont] = aux->quantidade;

        aux = aux->prox;
        cont++;
    }

    (*valor)[3] = cont;
    OrganizaDeck(cont,*vetor);
}

void CardRepetido(struct Card **vetor_tdeck,int cont,bool **repete_cards,struct Card **vetor_deck,struct Card **vetor_cdeck,struct Card **vetor_sdeck,int deck,int cdeck,int sdeck) {
    int i,j;

    if(cont == 0) return;

    *repete_cards = (bool *)calloc(cont,sizeof(bool));
    for(i = 0;i < cont;i++) {
        for(j = 0;j < deck;j++) {
            if(!strcmp(vetor_tdeck[i]->nome,vetor_deck[j]->nome)) {
                (*repete_cards)[i] = true;
                break;
            }
        }
        if((*repete_cards)[i] == true) continue;

        for(j = 0;j < cdeck;j++) {
            if(!strcmp(vetor_tdeck[i]->nome,vetor_cdeck[j]->nome)) {
                (*repete_cards)[i] = true;
                break;
            }
        }
        if((*repete_cards)[i] == true) continue;

        for(j = 0;j < sdeck;j++) {
            if(!strcmp(vetor_tdeck[i]->nome,vetor_sdeck[j]->nome)) {
                (*repete_cards)[i] = true;
                break;
            }
        }
    }
}

int ClonaSideDeck(struct Card ***stdeck,int **qte_cards,struct Card **sdeck,int sdeck_tam) {  //inicio de LOJA
    int i,j,k,card_unico = 0;

    if(sdeck_tam == 0) return(0);
    //printf("----------- SIDE DECK -----------\n");
    for(i = 0;i < sdeck_tam;i++) {
        for(j = i+1; j < sdeck_tam;j++) {
            if(!strcmp(sdeck[i]->nome,sdeck[j]->nome)) break;
        }

        if(j == sdeck_tam) {
            //printf("%s\n",sdeck[i]->nome);
            card_unico++;
        }
    }
    //printf("%d cards --------------------------------------\n",card_unico);

    *stdeck = (struct Card **)malloc(card_unico*sizeof(struct Card *));
    *qte_cards = (int *)calloc(card_unico,sizeof(int));

    k = 0;
    for(i = 0;i < sdeck_tam;i++) {
        for(j = 0;j < k;j++) {
            if(!strcmp(sdeck[i]->nome,(*stdeck)[j]->nome)) {
                (*qte_cards)[j] += 1;
                break;
            }
        }

        if(j == k) {
            (*stdeck)[k] = sdeck[i];
            (*qte_cards)[k] = 1;
            k += 1;
        }
    }

    return(card_unico);
}

void FinalizaClone(struct Card **stdeck,int *qte_cards) {   //fim de LOJA
    free(stdeck);
    free(qte_cards);
}

void AquisicaoCard(bool aquisicao,struct Card ***vetor_tdeck,int **tdeck,struct Card ***vetor_sdeck,int **sdeck,struct Card ***vetor_stdeck,int *diferenciados,int **qte_scards,int **qte_cards) {
    int i,selecionado = -1;

    if(aquisicao == true) {
        //INSERE -> side deck

        printf("1 ");
        *vetor_sdeck = (struct Card **)realloc(*vetor_sdeck, ((*sdeck)[3] + 1) * sizeof(struct Card *));    //sdeck nao possui distincao de cards.
        (*vetor_sdeck)[(*sdeck)[3]] = (*vetor_tdeck)[(*tdeck)[2]];                                         //stdeck ja possui essa diferenciacao,
        (*sdeck)[3] += 1;                                                                                  //bem como o tdeck.

        printf("2 ");
        for(i = 0;i < *diferenciados;i++) {     //atualiza o vetor stdeck.
            if(!strcmp((*vetor_tdeck)[(*tdeck)[2]]->nome,(*vetor_stdeck)[i]->nome)) break;
        }
        printf("3 ");
        if(i == *diferenciados) {
            *vetor_stdeck = (struct Card **)realloc(*vetor_stdeck, (i + 1) * sizeof(struct Card *));
            (*vetor_stdeck)[i] = (*vetor_tdeck)[(*tdeck)[2]];
            (*diferenciados)++;

            *qte_scards = (int *)realloc(*qte_scards,(i + 1) * sizeof(int));
            (*qte_scards)[i] = 1;
        }
        else (*qte_scards)[i] += 1;

        //RETIRA <- trade deck
        printf("4 ");
        if((*qte_cards)[(*tdeck)[2]] > 1) (*qte_cards)[(*tdeck)[2]] -= 1;
        else {
            printf("5 ");
            for(i = (*tdeck)[2];i < (*tdeck)[3];i++) {
                (*vetor_tdeck)[i] = (*vetor_tdeck)[i + 1];
                (*qte_cards)[i] = (*qte_cards)[i + 1];
            }
            printf("6 ");
            *vetor_tdeck = (struct Card **)realloc(*vetor_tdeck,((*tdeck)[3] - 1) * sizeof(struct Card *));
            *qte_cards = (int *)realloc(*qte_cards,((*tdeck)[3] - 1) * sizeof(int));

            (*tdeck)[3] -= 1;
            printf("7 ");
        }
    }

    else {
        //RETIRA <- side deck

        for(i = 0;i < *diferenciados; i++) {
            if(!strcmp((*vetor_sdeck)[(*sdeck)[2]]->nome,(*vetor_stdeck)[i]->nome)) {
                selecionado = i;
                break;
            }
        }
        if(selecionado == -1) printf("ERRO: Nenhum card selecionado!\n");

        if((*qte_scards)[selecionado] > 1) (*qte_scards)[selecionado] -= 1;
        else {
            for(i = selecionado;i < *diferenciados;i++) {
                (*vetor_stdeck)[i] = (*vetor_stdeck)[i + 1];
                (*qte_scards)[i] = (*qte_scards)[i + 1];
            }
            *vetor_stdeck = (struct Card **)realloc(*vetor_stdeck,(*diferenciados - 1) * sizeof(struct Card *));
            *qte_scards = (int *)realloc(*qte_scards,(*diferenciados - 1) * sizeof(int));

            *diferenciados -= 1;
        }

        for(i = (*sdeck)[2];i < (*sdeck)[3];i++) {
            (*vetor_sdeck)[i] = (*vetor_sdeck)[i + 1];
        }
        *vetor_sdeck = (struct Card **)realloc(*vetor_sdeck,((*sdeck)[3] - 1) * sizeof(struct Card *));

        (*sdeck)[3] -= 1;
    }
}

bool PromptTransacao(bool aquisicao,char *nome_card,int moeda,int valor,struct Rupee_bitmaps *rbmp,ALLEGRO_DISPLAY *display,ALLEGRO_BITMAP *prompt,ALLEGRO_BITMAP *selecao,ALLEGRO_FONT *font,ALLEGRO_COLOR color,bool *sair,int *posX,int *posY,int *dltZ,bool *mouse,bool *mouse2,bool *mouse_lado,int *keychar,bool *repete_keychar,ALLEGRO_EVENT_QUEUE *event_queue,ALLEGRO_TIMER *keyb_press_timer,ALLEGRO_TIMER *mouse_press_timer) {
    ALLEGRO_BITMAP *temp;

    if(aquisicao == true && moeda < valor) {
        temp = al_clone_bitmap(al_get_backbuffer(display));
        al_clear_to_color(al_map_rgb_f(0, 0, 0));
        al_draw_tinted_bitmap(temp, al_map_rgba_f(0.3, 0.3, 0.3, 0.3),0, 0, 0);

        al_draw_scaled_bitmap(selecao,0,0,240,360,240,275,400,50,0);
        al_draw_textf(font,color,260,285,0,"Valor insuficiente para a COMPRA!");
        al_flip_display();
        al_destroy_bitmap(temp);
        al_rest(1.5);

        return(false);
    }

    temp = al_clone_bitmap(al_get_backbuffer(display));
    while(1) {
        al_clear_to_color(al_map_rgb_f(0, 0, 0));
        al_draw_tinted_bitmap(temp, al_map_rgba_f(0.3, 0.3, 0.3, 0.3),0, 0, 0);
        al_draw_bitmap(prompt,140,225,0);

        if(aquisicao == true) {
            al_draw_textf(font,color,155,235,0,"Efetuar COMPRA do card: %s?",nome_card);
            al_draw_textf(font,color,155,265,0,"     %d",valor);
            DesenhaRupee(rbmp,valor,158,268);
        }
        else {
            al_draw_textf(font,color,155,235,0,"Efetuar VENDA do card: %s?",nome_card);
            al_draw_textf(font,color,155,265,0,"     %d",valor);
            DesenhaRupee(rbmp,valor,158,268);
        }
        al_draw_text(font,color,240,310,0,"Sim");
        al_draw_text(font,color,510,310,0,"Nao");

        al_flip_display();

        VerificaEventos(sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);

        if(*mouse == true && *posX >= 155 && *posX < 365 && *posY >= 300 && *posY < 345) {
            al_destroy_bitmap(temp);
            //al_rest(0.2);

            return(true);
        }
        else if (*mouse2 == true || (*mouse == true && *posX >= 425 && *posX < 635 && *posY >= 300 && *posY < 345)) {
            al_destroy_bitmap(temp);
            //al_rest(0.2);

            return(false);
        }
    }
}

void ImprimeEstadoAtual(struct Card **vetor_sdeck,struct Card **vetor_stdeck,struct Card **vetor_tdeck,int *sdeck,int *tdeck,int *qte_scards,int *qte_cards,int *preco_cards,int qte_diferenciados) {
    int i;

    printf("\n--------- ESTADO ATUAL ---------------\n");
    printf("------- SIDE_DECK (%d - %d - %d - %d) ---------\n",sdeck[0],sdeck[1],sdeck[2],sdeck[3]);
    for(i = 0;i < sdeck[3];i++) {
        printf("%s\n",vetor_sdeck[i]->nome);
    }
    printf("------- TRADE_SIDE_DECK ---------\n");
    printf("CARDS: %d\n",qte_diferenciados);
    for(i = 0;i < qte_diferenciados;i++) {
        printf("%s x%d vendendo a %d\n",vetor_stdeck[i]->nome,qte_scards[i],(int)(0.7*vetor_stdeck[i]->preco));
    }
    printf("------- TRADE_DECK (%d - %d - %d - %d) ---------\n",tdeck[0],tdeck[1],tdeck[2],tdeck[3]);
    for(i = 0;i < tdeck[3];i++) {
        printf("%s x%d custando %d\n",vetor_tdeck[i]->nome,qte_cards[i],preco_cards[i]);
    }

    printf("------------- FIM ---------------\n");
}

void AdministrarProfile(struct Rupee_bitmaps *conj_rupee,struct COLECAO *colecao,struct PROFILE *lista_pfl,ALLEGRO_DISPLAY *janela,ALLEGRO_FONT *texto,ALLEGRO_FONT *texto2,ALLEGRO_FONT *texto3,ALLEGRO_COLOR color,ALLEGRO_BITMAP *prompt,ALLEGRO_BITMAP *fundo,ALLEGRO_BITMAP *pont,ALLEGRO_BITMAP *entrada,ALLEGRO_BITMAP *selecao,ALLEGRO_BITMAP *roll_bar,ALLEGRO_BITMAP **ret,bool *sair,int *posX,int *posY,int *dltZ,bool *mouse,bool *mouse2,bool *mouse_lado,int *keychar,bool *repete_keychar,ALLEGRO_EVENT_QUEUE *event_queue,ALLEGRO_TIMER *keyb_press_timer,ALLEGRO_TIMER *mouse_press_timer) {
    struct PROFILE *profile;
    struct Card **vetor_deck = NULL,**vetor_sdeck = NULL,**vetor_stdeck = NULL,**vetor_cdeck = NULL,**vetor_tdeck = NULL,*card_tbox = NULL;
    ALLEGRO_FONT *font,*font2;
    FILE *arq;
    char *nome_profile;
    int roll_tbox = 0,i,deck_interface = 0,valor,*deck,*sdeck,*cdeck,*tdeck,*preco_cards = NULL,*qte_scards = NULL,*qte_cards = NULL,qte_diferenciados = -1;
    bool *repete_cards = NULL;
    short int toggle;
    /*vetor:
        0 -> pagina atual
        1 -> max pagina
        2 -> card escolhido
        3 -> total cards (o card escolhido vai de 0 a tc-1)
    */
    profile = EscolheProfile(lista_pfl,janela,texto,texto3,color,pont,entrada,selecao,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);
    if(profile == NULL) {
        printf("NULO!\n");
        return;
    }

    font = al_load_ttf_font("data/triforce.ttf",25,0);
    font2 = al_load_ttf_font("data/triforce.ttf",10,0);

    deck = (int *)calloc(4,sizeof(int));
    sdeck = (int *)calloc(4,sizeof(int));
    cdeck = (int *)calloc(4,sizeof(int));
    tdeck = (int *)calloc(4,sizeof(int));

    InicializaVetorCards(profile->deck,&vetor_deck,colecao,&deck);
    InicializaVetorCards(profile->side_deck,&vetor_sdeck,colecao,&sdeck);
    InicializaVetorCards(profile->char_deck,&vetor_cdeck,colecao,&cdeck);

    InicializaVetorShopCards(profile->trade_deck,&vetor_tdeck,&preco_cards,&qte_cards,colecao,&tdeck);
    printf("QTE: %d\n",tdeck[3]);
    CardRepetido(vetor_tdeck,tdeck[3],&repete_cards,vetor_deck,vetor_cdeck,vetor_sdeck,deck[3],cdeck[3],sdeck[3]);

    for(i = 0;i < deck[3];i++) {
        printf("%s\n",vetor_deck[i]->nome);
    }
    printf("-------\n");
    for(i = 0;i < cdeck[3];i++) {
        printf("%s\n",vetor_cdeck[i]->nome);
    }
    printf("-------\n");
    for(i = 0;i < sdeck[3];i++) {
        printf("%s\n",vetor_sdeck[i]->nome);
    }
    printf("-------\n");
    for(i = 0;i < tdeck[3];i++) {   //Repetido: o card no vetor TRADE existe no vetor SIDE.
        printf("%s (%d) x%d (Repetido: %d)\n",vetor_tdeck[i]->nome,preco_cards[i],qte_cards[i],repete_cards[i]);
    }

    while(1) {
        VerificaEventos(sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);

        deck[1]  =  deck[3] / 12;
        if(deck[3] % 12 == 0 && deck[1] > 0 && deck[3] > 0) {
            (deck[1])--;
            if(deck[0] > deck[1]) deck[0] = deck[1];
        }

        cdeck[1] = cdeck[3] / 12;
        if(cdeck[3] % 12 == 0 && cdeck[1] > 0 && cdeck[3] > 0) {
            (cdeck[1])--;
            if(cdeck[0] > cdeck[1]) cdeck[0] = cdeck[1];
        }

        tdeck[1] = tdeck[3] / 4;
        if(tdeck[3] % 4 == 0 && tdeck[1] > 0 && tdeck[3] > 0) {
            (tdeck[1])--;
            if(tdeck[0] > tdeck[1]) tdeck[0] = tdeck[1];
        }

        if(deck_interface == 2) {
            sdeck[1] = sdeck[3] / 6;
            if(sdeck[3] % 6 == 0 && sdeck[1] > 0 && sdeck[3] > 0) {
                (sdeck[1])--;
                if(sdeck[0] > sdeck[1]) sdeck[0] = sdeck[1];
            }
        }
        else {
            sdeck[1] = sdeck[3] / 18;
            if(sdeck[3] % 18 == 0 && sdeck[1] > 0 && sdeck[3] > 0) {
                (sdeck[1])--;
                if(sdeck[0] > sdeck[1]) sdeck[0] = sdeck[1];
            }
        }

        /*printf("\n----------------------------------------\n");
        printf("Deck: %d / %d\n",deck[0],deck[1]);
        printf("cDeck: %d / %d\n",cdeck[0],cdeck[1]);
        printf("sDeck: %d / %d\n",sdeck[0],sdeck[1]);
        printf("tDeck: %d / %d\n",tdeck[0],tdeck[1]);
        printf("\n----------------------------------------\n");*/

        al_draw_bitmap(fundo,0,0,0);

        if(al_get_text_width(texto,profile->nome) > 190) al_draw_textf(texto2,color,605,10,0,"%s",profile->nome);
        else al_draw_textf(texto,color,605,10,0,"%s",profile->nome);

        al_draw_textf(font,color,605,70,0,"Lv. %d",profile->level);
        al_draw_textf(font,color,605,100,0,"Exp.: %d / _",profile->exp);
        al_draw_textf(font,color,605,130,0,"Moeda:     %ld",profile->moeda);
        DesenhaRupee(conj_rupee,profile->moeda,675,133);
        al_draw_textf(font,color,605,200,0,"Side  Deck: %d",sdeck[3]);
        al_draw_textf(font,color,605,170,0,"Main Deck: %d / %d",deck[3],profile->MAX_deck);
        al_draw_textf(font,color,605,230,0,"Char Deck: %d",cdeck[3]);

        switch(deck_interface) {
            case 0:
                if(deck[3] > 0) {
                    for(i = 0;i < 12;i++) {     //main deck
                        if(deck[0] == deck[1] && i >= deck[3] % 12 && deck[3] % 12 > 0) break;
                        if(12*deck[0] + i == deck[2]) al_draw_scaled_bitmap(selecao,0,0,240,360,242 + 60*(i % 6),397 + 80*(i / 6),56,81,0);
                        al_draw_scaled_bitmap(vetor_deck[12*deck[0] + i]->bmp,0,0,240,360,245 + 60*(i % 6),400 + 80*(i / 6),50,75,0);

                        if(*mouse == true && *posX >= 245 + 60*(i % 6) && *posX < 295 + 60*(i % 6) && *posY >= 400 + 80*(i / 6) && *posY < 475 + 80*(i / 6)) {
                            if(deck[2] == 12*deck[0] + i) deck[2] = -1;
                            else deck[2] = 12*deck[0] + i;
                            card_tbox = vetor_deck[12*deck[0] + i];
                            roll_tbox = 0;
                        }
                    }
                }

                if(*mouse == true) {
                    if(*posX >= 245 && *posX < 275 && *posY >= 565 && *posY < 595 && deck[0] > 0) deck[0]--;
                    else if(*posX >= 375 && *posX < 405 && *posY >= 565 && *posY < 595 && deck[0] < deck[1]) deck[0]++;
                }
                al_draw_textf(texto,color,420,365,0,"Main Deck");
                al_draw_textf(font,color,290,568,0,"%d",deck[0] + 1);
                al_draw_textf(font,color,340,568,0,"%d",deck[1] + 1);

                if(deck[3] == 0) al_draw_bitmap(ret[2],245,365,0);
                else if(deck[2] == -1) al_draw_bitmap(ret[0],245,365,0);
                else al_draw_bitmap(ret[1],245,365,0);
                break;

            case 1:
                if(cdeck[3] > 0) {
                    for(i = 0;i < 12;i++) {     //character deck
                        if(cdeck[0] == cdeck[1] && i >= cdeck[3] % 12 && cdeck[3] % 12 > 0) break;
                        if(12*cdeck[0] + i == cdeck[2]) al_draw_scaled_bitmap(selecao,0,0,240,360,242 + 60*(i % 6),397 + 80*(i / 6),56,81,0);
                        al_draw_scaled_bitmap(vetor_cdeck[12*cdeck[0] + i]->bmp,0,0,240,360,245 + 60*(i % 6),400 + 80*(i / 6),50,75,0);

                        if(*mouse == true && *posX >= 245 + 60*(i % 6) && *posX < 295 + 60*(i % 6) && *posY >= 400 + 80*(i / 6) && *posY < 475 + 80*(i / 6)) {
                            if(cdeck[2] == 12*cdeck[0] + i) cdeck[2] = -1;
                            else cdeck[2] = 12*cdeck[0] + i;
                            card_tbox = vetor_cdeck[12*cdeck[0] + i];
                            roll_tbox = 0;
                        }
                    }
                }

                if(*mouse == true) {
                    if(*posX >= 245 && *posX < 275 && *posY >= 565 && *posY < 595 && cdeck[0] > 0) cdeck[0]--;
                    else if(*posX >= 375 && *posX < 405 && *posY >= 565 && *posY < 595 && cdeck[0] < cdeck[1]) cdeck[0]++;
                }
                al_draw_textf(texto,color,337,365,0,"Character Deck");
                al_draw_textf(font,color,290,568,0,"%d",cdeck[0] + 1);
                al_draw_textf(font,color,340,568,0,"%d",cdeck[1] + 1);

                if(cdeck[3] == 0) al_draw_bitmap(ret[2],245,365,0);
                else if(cdeck[2] == -1) al_draw_bitmap(ret[0],245,365,0);
                else al_draw_bitmap(ret[1],245,365,0);
                break;

            case 2:
                if(sdeck[3] > 0) {
                    for(i = 0;i < 6;i++) {     //shop side deck
                        if(sdeck[0] == sdeck[1] && i >= sdeck[3] % 6 && sdeck[3] % 6 > 0) break;
                        if(6*sdeck[0] + i == sdeck[2]) al_draw_scaled_bitmap(selecao,0,0,240,360,242 + 180*(i % 2),72 + 80*(i / 2),56,81,0);
                        al_draw_scaled_bitmap(vetor_sdeck[6*sdeck[0] + i]->bmp,0,0,240,360,245 + 180*(i % 2),75 + 80*(i / 2),50,75,0);

                        al_draw_textf(font2,color,305 + 180*(i % 2),80 + 80*(i / 2),0,"%s",vetor_sdeck[6*sdeck[0] + i]->nome);
                        valor = (vetor_sdeck[6*sdeck[0] + i]->preco) * 0.7;
                        al_draw_textf(font2,color,305 + 180*(i % 2),137 + 80*(i / 2),0,"       %d",valor);
                        DesenhaRupee(conj_rupee,(vetor_sdeck[6*sdeck[0] + i]->preco) * 0.7,300 + 180*(i % 2),130 + 80*(i / 2));

                        if(*mouse == true && *posX >= 245 + 180*(i % 2) && *posX < 295 + 180*(i % 2) && *posY >= 75 + 80*(i / 2) && *posY < 150 + 80*(i / 2)) {
                            if(sdeck[2] == 6*sdeck[0] + i) sdeck[2] = -1;
                            else {
                                sdeck[2] = 6*sdeck[0] + i;
                                tdeck[2] = -1;
                            }
                            card_tbox = vetor_sdeck[6*sdeck[0] + i];
                            roll_tbox = 0;
                        }
                    }
                }

                if(tdeck[3] > 0) {
                    for(i = 0;i < 4;i++) {  //trade deck
                        if(tdeck[0] == tdeck[1] && i >= tdeck[3] % 4 && tdeck[3] % 4 > 0) break;
                        if(4*tdeck[0] + i == tdeck[2]) al_draw_scaled_bitmap(selecao,0,0,240,360,242 + 180*(i % 2),402 + 80*(i / 2),56,81,0);
                        al_draw_scaled_bitmap(vetor_tdeck[4*tdeck[0] + i]->bmp,0,0,240,360,245 + 180*(i % 2),405 + 80*(i / 2),50,75,0);

                        al_draw_textf(font2,color,305 + 180*(i % 2),410 + 80*(i / 2),0,"%s",vetor_tdeck[4*tdeck[0] + i]->nome);
                        if(repete_cards[4*tdeck[0] + i] == false) al_draw_textf(font2,color,305 + 180*(i % 2),428 + 80*(i / 2),0,"NOVO!");
                        al_draw_textf(font2,color,305 + 180*(i % 2),446 + 80*(i / 2),0,"x %d",qte_cards[4*tdeck[0] + i]);
                        al_draw_textf(font2,color,305 + 180*(i % 2),467 + 80*(i / 2),0,"       %d",preco_cards[4*tdeck[0] + i]);
                        DesenhaRupee(conj_rupee,preco_cards[4*tdeck[0] + i],300 + 180*(i % 2),460 + 80*(i / 2));

                        if(*mouse == true && *posX >= 245 + 180*(i % 2) && *posX < 295 + 180*(i % 2) && *posY >= 405 + 80*(i / 2) && *posY < 480 + 80*(i / 2)) {
                            if(tdeck[2] == 4*tdeck[0] + i) tdeck[2] = -1;
                            else {
                                tdeck[2] = 4*tdeck[0] + i;
                                sdeck[2] = -1;
                            }
                            card_tbox = vetor_tdeck[4*tdeck[0] + i];
                            roll_tbox = 0;
                        }
                    }
                }

                //al_draw_textf(texto,color,420,365,0,"Main Deck");
                al_draw_textf(texto,color,520,365,0,"Loja");
                al_draw_textf(font,color,290,568,0,"%d",tdeck[0] + 1);
                al_draw_textf(font,color,340,568,0,"%d",tdeck[1] + 1);
                if(*mouse == true) {
                    if(*posX >= 245 && *posX < 275 && *posY >= 565 && *posY < 595 && tdeck[0] > 0) tdeck[0]--;
                    else if(*posX >= 375 && *posX < 405 && *posY >= 565 && *posY < 595 && tdeck[0] < tdeck[1]) tdeck[0]++;
                }

                if(tdeck[3] == 0) al_draw_bitmap(ret[2],245,365,0);
                else if(tdeck[2] == -1) al_draw_bitmap(ret[0],245,365,0);
                else al_draw_bitmap(ret[1],245,365,0);
                break;
        }

        if(deck_interface != 2) {
            if(sdeck[3] > 0) {
                for(i = 0;i < 18;i++) {     //side deck
                    if(sdeck[0] == sdeck[1] && i >= sdeck[3] % 18 && sdeck[3] % 18 > 0) break;
                    if(18*sdeck[0] + i == sdeck[2]) al_draw_scaled_bitmap(selecao,0,0,240,360,242 + 60*(i % 6),72 + 80*(i / 6),56,81,0);
                    al_draw_scaled_bitmap(vetor_sdeck[18*sdeck[0] + i]->bmp,0,0,240,360,245 + 60*(i % 6),75 + 80*(i / 6),50,75,0);

                    if(*mouse == true && *posX >= 245 + 60*(i % 6) && *posX < 295 + 60*(i % 6) && *posY >= 75 + 80*(i / 6) && *posY < 150 + 80*(i / 6)) {
                        if(sdeck[2] == 18*sdeck[0] + i) sdeck[2] = -1;
                        else sdeck[2] = 18*sdeck[0] + i;
                        card_tbox = vetor_sdeck[18*sdeck[0] + i];
                        roll_tbox = 0;
                    }
                }
            }
        }

        al_draw_textf(texto,color,440,5,0,"Side Deck");
        al_draw_textf(font,color,290,328,0,"%d",sdeck[0] + 1);
        al_draw_textf(font,color,340,328,0,"%d",sdeck[1] + 1);

        if(sdeck[3] == 0) al_draw_bitmap(ret[2],245,5,0);
        else if(sdeck[2] == -1 || (deck_interface == 0 && strcmp(vetor_sdeck[sdeck[2]]->tipo,"Character") == 0) || (deck_interface == 1 && strcmp(vetor_sdeck[sdeck[2]]->tipo,"Character") != 0)) al_draw_bitmap(ret[0],245,5,0);
        else al_draw_bitmap(ret[1],245,5,0);

        BarraRolagem(&roll_tbox,posX,posY,dltZ,mouse,card_tbox,roll_bar,texto2,color);
        if(*mouse == true) {
            if(*posX >= 245 && *posX < 275 && *posY >= 325 && *posY < 355 && sdeck[0] > 0) (sdeck[0])--;
            else if(*posX >= 375 && *posX < 405 && *posY >= 325 && *posY < 355 && sdeck[0] < sdeck[1]) (sdeck[0])++;

            else if(*posX >= 615 && *posX < 785) {
                if(*posY >= 365 && *posY < 395) {
                    if(deck_interface == 2) {
                        sdeck[0] = sdeck[0] / 3;
                        FinalizaClone(vetor_stdeck,qte_scards);
                    }
                    deck_interface = 0;
                }
                else if(*posY >= 405 && *posY < 435) {
                    if(deck_interface == 2) {
                        sdeck[0] = sdeck[0] / 3;
                        FinalizaClone(vetor_stdeck,qte_scards);
                    }
                    deck_interface = 1;
                }
                else if(*posY >= 445 && *posY < 475) {
                    if(deck_interface != 2) {
                        sdeck[0] = sdeck[0] * 3;
                        qte_diferenciados = ClonaSideDeck(&vetor_stdeck,&qte_scards,vetor_sdeck,sdeck[3]);
                    }
                    deck_interface = 2;

                    deck[2] = -1;
                    cdeck[2] = -1;
                    sdeck[2] = -1;
                    tdeck[2] = -1;
                }

                else if(*posY >= 500 && *posY < 540) break;
                else if(*posY >= 550 && *posY < 590) return;
            }
            else if(*posX >= 475 && *posX < 595 && *posY >= 325 && *posY < 355) {   //botao trocar
                if(deck_interface == 2) {
                    //al_rest(0.2);

                    if(tdeck[2] != -1 && PromptTransacao(true,vetor_tdeck[tdeck[2]]->nome,profile->moeda,preco_cards[tdeck[2]],conj_rupee,janela,prompt,selecao,font,color,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer)) {  //efetua COMPRA
                        ImprimeEstadoAtual(vetor_sdeck,vetor_stdeck,vetor_tdeck,sdeck,tdeck,qte_scards,qte_cards,preco_cards,qte_diferenciados);

                        profile->moeda -= preco_cards[tdeck[2]];

                        AquisicaoCard(true,&vetor_tdeck,&tdeck,&vetor_sdeck,&sdeck,&vetor_stdeck,&qte_diferenciados,&qte_scards,&qte_cards);
                        printf("\n");
                        ImprimeEstadoAtual(vetor_sdeck,vetor_stdeck,vetor_tdeck,sdeck,tdeck,qte_scards,qte_cards,preco_cards,qte_diferenciados);

                        free(repete_cards);
                        repete_cards = NULL;
                        CardRepetido(vetor_tdeck,tdeck[3],&repete_cards,vetor_deck,vetor_cdeck,vetor_sdeck,deck[3],cdeck[3],sdeck[3]);
                        FinalizaClone(vetor_stdeck,qte_scards);
                        qte_diferenciados = ClonaSideDeck(&vetor_stdeck,&qte_scards,vetor_sdeck,sdeck[3]);

                        tdeck[2] = -1;
                        //al_rest(0.2);
                    }

                    else if(sdeck[2] != -1 && PromptTransacao(false,vetor_sdeck[sdeck[2]]->nome,0,0.7 * vetor_sdeck[sdeck[2]]->preco,conj_rupee,janela,prompt,selecao,font,color,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer)) { //efetua VENDA
                        ImprimeEstadoAtual(vetor_sdeck,vetor_stdeck,vetor_tdeck,sdeck,tdeck,qte_scards,qte_cards,preco_cards,qte_diferenciados);
                        profile->moeda += (0.7 * vetor_sdeck[sdeck[2]]->preco);
                        AquisicaoCard(false,&vetor_tdeck,&tdeck,&vetor_sdeck,&sdeck,&vetor_stdeck,&qte_diferenciados,&qte_scards,&qte_cards);
                        printf("\n");
                        ImprimeEstadoAtual(vetor_sdeck,vetor_stdeck,vetor_tdeck,sdeck,tdeck,qte_scards,qte_cards,preco_cards,qte_diferenciados);

                        free(repete_cards);
                        repete_cards = NULL;
                        CardRepetido(vetor_tdeck,tdeck[3],&repete_cards,vetor_deck,vetor_cdeck,vetor_sdeck,deck[3],cdeck[3],sdeck[3]);
                        FinalizaClone(vetor_stdeck,qte_scards);
                        qte_diferenciados = ClonaSideDeck(&vetor_stdeck,&qte_scards,vetor_sdeck,sdeck[3]);

                        sdeck[2] = -1;
                        //al_rest(0.2);
                    }
                }
                else {
                    toggle = 0;

                    if(sdeck[2] != -1) {
                        if(deck_interface == 0 && strcmp((vetor_sdeck[sdeck[2]])->tipo,"Character") != 0 && deck[3] < profile->MAX_deck && ControlaQteCopias((vetor_sdeck[sdeck[2]])->nome,vetor_deck,deck[3],&sdeck) == true) {
                            TransfereCard(&vetor_sdeck,&vetor_deck,&sdeck,&deck);
                            toggle = 1;
                        }
                        else if(deck_interface == 1 && strcmp((vetor_sdeck[sdeck[2]])->tipo,"Character") == 0) {
                            TransfereCard(&vetor_sdeck,&vetor_cdeck,&sdeck,&cdeck);
                            toggle = 2;
                        }
                    }
                    if(deck_interface == 0 && deck[2] != -1) {
                        TransfereCard(&vetor_deck,&vetor_sdeck,&deck,&sdeck);
                        OrganizaDeck(sdeck[3],vetor_sdeck);
                    }
                    else if(deck_interface == 1 && cdeck[2] != -1) {
                        TransfereCard(&vetor_cdeck,&vetor_sdeck,&cdeck,&sdeck);
                        OrganizaDeck(sdeck[3],vetor_sdeck);
                    }

                    if(toggle == 1) OrganizaDeck(deck[3],vetor_deck);
                    else if(toggle == 2) OrganizaDeck(cdeck[3],vetor_cdeck);
                }
            }
        }

        al_flip_display();
        //al_wait_for_event_timed(event_queue,&ev,0.1);
        if(*sair == true) return;
    }
    if(deck_interface == 2) FinalizaClone(vetor_stdeck,qte_scards);

    profile->qte_deck = deck[3];

    nome_profile = (char *)malloc(42*sizeof(char));
    nome_profile[0] = 0;
    strcat(nome_profile,"profiles/");
    strcat(nome_profile,profile->nome);
    strcat(nome_profile,".prf");

    arq = fopen(nome_profile,"w+t");

    fprintf(arq,"%d %d %ld %d %d\n",profile->level,profile->exp,profile->moeda,profile->qte_deck,profile->MAX_deck);
    fprintf(arq,"CHAR_DECK\n");
    for(i = 0;i < cdeck[3];i++) fprintf(arq,"%s\n",vetor_cdeck[i]->nome);

    fprintf(arq,"DECK\n");
    for(i = 0;i < deck[3];i++) fprintf(arq,"%s\n",vetor_deck[i]->nome);

    fprintf(arq,"SIDE_DECK\n");
    for(i = 0;i < sdeck[3];i++) {
        printf("%s\n",vetor_sdeck[i]->nome);
        fprintf(arq,"%s\n",vetor_sdeck[i]->nome);
    }
    fprintf(arq,"TRADE_DECK\n");
    for(i = 0;i < tdeck[3];i++) {
        printf("%s %d %d\n",vetor_tdeck[i]->nome,preco_cards[i],qte_cards[i]);
        fprintf(arq,"%s %d %d\n",vetor_tdeck[i]->nome,preco_cards[i],qte_cards[i]);
    }

    fclose(arq);
    if(cdeck[3] > 0) free(vetor_cdeck);
    if(sdeck[3] > 0) free(vetor_sdeck);
    if(deck[3] > 0) free(vetor_deck);


    if(tdeck[3] > 0) {
        free(vetor_tdeck);
        free(preco_cards);
        free(qte_cards);
        free(repete_cards);
    }

    free(nome_profile);
    free(deck);
    free(cdeck);
    free(sdeck);
    free(tdeck);

    al_destroy_font(font2);
    al_destroy_font(font);
}

void DeletarProfile(struct PROFILE *lista_pfl,ALLEGRO_DISPLAY *janela,ALLEGRO_COLOR color,ALLEGRO_BITMAP *fundo,ALLEGRO_BITMAP *selecao,ALLEGRO_BITMAP *prompt,bool *sair,int *posX,int *posY,int *dltZ,bool *mouse,bool *mouse2,bool *mouse_lado,int *keychar,bool *repete_keychar,ALLEGRO_EVENT_QUEUE *event_queue,ALLEGRO_TIMER *keyb_press_timer,ALLEGRO_TIMER *mouse_press_timer) {
    ALLEGRO_FONT *font;
    ALLEGRO_BITMAP *temp;

    struct PROFILE *aux,*aux2,**vetor;
    char *nome_extenso;
    int erro = 1,i,contador = 0,pagina,max_pagina,opcao = -1;
    FILE *arq;

    font = al_load_ttf_font("data/triforce.ttf",25, 0);
    if(lista_pfl->prox == NULL) {
        al_draw_bitmap(fundo,0,0,0);
        al_draw_textf(font,color,150,235,0,"NAO EXISTEM PROFILES SALVOS! Redirecionando...");
        al_flip_display();

        al_rest(2.0);
        al_destroy_font(font);
        return;
    }

    nome_extenso = (char *)calloc(42,sizeof(char));
    nome_extenso[0] = 0;

    aux = lista_pfl;
    while(aux->prox != NULL) {
        aux = aux->prox;
        contador++;
    }

    vetor = (struct PROFILE **)calloc(contador,sizeof(struct PROFILE *));  //armazena os profiles num vetor, de forma que o acesso a
    aux = lista_pfl;                                                       //estes profiles, entre páginas, seja mais simplificado.
    i = 0;
    while(aux->prox != NULL) {
        vetor[i] = aux;
        aux = aux->prox;
        i++;
    }

    max_pagina = i / 10;    //10 profiles por página.
    pagina = 0;

    while(1) {
        al_draw_bitmap(fundo,0,0,0);

        for(i = 0;i < 10;i++) {
            if(10*pagina + i < contador) {
                if(opcao == 10*pagina + i) al_draw_scaled_bitmap(selecao,0,0,240,360,5,140 + 40*i,770,40,0);
                al_draw_textf(font,color, 10,145 + 40*i,0,"%s",vetor[10*pagina + i]->nome);
                al_draw_textf(font,color,710,145 + 40*i,0,"Lv. %d",vetor[10*pagina + i]->level);
            }
            else break;
        }

        al_draw_textf(font,color,375,555,0,"%d",pagina + 1);
        al_draw_textf(font,color,455,555,0,"%d",max_pagina + 1);

        al_flip_display();
        //al_wait_for_event_timed(event_queue,&ev,0.1);
        VerificaEventos(sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);

        if(*sair == true) return;
        if(*mouse == true) {
            if(*posX >= 10 && *posX < 220 && *posY >= 540 && *posY < 590) return;

            if(pagina < max_pagina && *posX >= 500 && *posX < 550 && *posY >= 540 && *posY < 590) pagina++;
            else if(pagina > 0 && *posX >= 300 && *posX < 350 && *posY >= 540 && *posY < 590) pagina--;
            else if(opcao != -1 && *posX >= 580 && *posX < 790 && *posY >= 540 && *posY < 590) {
                temp = al_clone_bitmap(al_get_backbuffer(janela));
                al_clear_to_color(al_map_rgb_f(0, 0, 0));
                al_draw_tinted_bitmap(temp, al_map_rgba_f(0.3, 0.3, 0.3, 0.3),0, 0, 0);

                al_draw_bitmap(prompt,140,225,0);
                al_draw_textf(font,color,150,235,0,"Deseja mesmo deletar %s?",vetor[opcao]->nome);
                al_draw_text(font,color,230,310,0,"Sim");
                al_draw_text(font,color,490,310,0,"Nao");

                while(1) {
                    al_flip_display();

                    //al_wait_for_event_timed(event_queue,&ev,0.1);
                    VerificaEventos(sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);

                    if(*mouse == true) {
                        if(*posX >= 155 && *posX < 365 && *posY >= 300 && *posY < 345) {
                            erro = 0;
                            break;
                        }
                        else if(*posX >= 425 && *posX < 635 && *posY >= 300 && *posY < 345) {
                            break;
                        }
                    }
                }
                al_destroy_bitmap(temp);
                if(erro == 0) break;
            }

            for(i = 0;i < 10;i++) {
                if(10*pagina + i < contador) {
                    if(*posX >= 10 && *posX < 770 && *posY >= 145 + 40*i && *posY < 185 + 40*i) {
                        opcao = 10*pagina + i;
                        break;
                    }
                }
                else break;
            }
        }
    }
    strcat(nome_extenso,"profiles/");
    strcat(nome_extenso,vetor[opcao]->nome);
    strcat(nome_extenso,".prf");

    arq = fopen("profiles/lista.pfl","w+t");    //Atualiza o conjunto de nomes de profile do arquivo-mestre.
    if(arq != NULL) {
        erro = remove(nome_extenso);
        if(erro == 0) {
            aux = lista_pfl;
            aux2 = NULL;

            while(strcmp(aux->nome,vetor[opcao]->nome) != 0) {
                aux2 = aux;
                aux = aux->prox;
            }

            if(aux2 != NULL) aux2->prox = aux->prox;
            else lista_pfl = aux->prox;
            free(aux);
        }
        else printf("ERRO: Profile %s nao pode ser deletado!\n",vetor[opcao]->nome);

        aux = lista_pfl;
        while(aux->prox != NULL) {
            fprintf(arq,"%s\n",aux->nome);
            aux = aux->prox;
        }

        fclose(arq);
    }
    else printf("ERRO: acesso negado ao arquivo da lista de profiles!\n");

    free(nome_extenso);
    free(vetor);

    al_destroy_font(font);
}

bool CardPresente(int nome,struct PROFILE *profile) {
    struct ProfCard *aux;

    aux = profile->side_deck;
    while(aux->prox != NULL) {
        if(aux->card == nome) return(true);
        aux = aux->prox;
    }

    aux = profile->deck;
    while(aux->prox != NULL) {
        if(aux->card == nome) return(true);
        aux = aux->prox;
    }

    aux = profile->char_deck;
    while(aux->prox != NULL) {
        if(aux->card == nome) return(true);
        aux = aux->prox;
    }

    return(false);
}

void CardList(struct PROFILE *lista_pfl,ALLEGRO_DISPLAY *janela,int *total_cards,struct ListaCards **lista,ALLEGRO_FONT *texto3,ALLEGRO_FONT *texto4,ALLEGRO_FONT *texto5,ALLEGRO_COLOR cor_texto,ALLEGRO_BITMAP *lista_cards,ALLEGRO_BITMAP *select_card,ALLEGRO_BITMAP *roll_bar,ALLEGRO_BITMAP *pont,ALLEGRO_BITMAP *entrada,ALLEGRO_BITMAP *fundo_card,bool *sair,int *posX,int *posY,int *dltZ,bool *mouse,bool *mouse2,bool *mouse_lado,int *keychar,bool *repete_keychar,ALLEGRO_EVENT_QUEUE *event_queue,ALLEGRO_TIMER *keyb_press_timer,ALLEGRO_TIMER *mouse_press_timer) {
    int cont,contador,card_atual,roll_tbox,opcao[2],card_tela,ult_pagina;
    struct ListaCards *aux;
    struct Card *card_tbox;
    struct PROFILE *profile;
    ALLEGRO_EVENT ev;

    card_atual = -1;
    roll_tbox = 0;
    card_tbox = NULL;
    opcao[0] = 0;   //0 representa TIPO DO CARD.
    opcao[1] = 0;   //1 representa sub-indice atual.

    profile = EscolheProfile(lista_pfl,janela,texto4,texto5,cor_texto,pont,entrada,select_card,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);
    if(profile == NULL) return;

    while(1) {
        al_draw_bitmap(lista_cards,0,0,0);

        card_tela = total_cards[opcao[0]] % 15;
        ult_pagina = total_cards[opcao[0]] / 15;

        VerificaEventos(sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);

        aux = lista[opcao[0]];
        for(cont = 0;cont < 15*opcao[1];cont++) aux = aux->prox;

        if(card_atual >= 15*opcao[1] && card_atual < 15*(opcao[1] + 1)) al_draw_scaled_bitmap(select_card,0,0,240,360,245 + 110*(card_atual % 5),40 + 160*((card_atual % 15) / 5),110,160,0);

        for(contador = 0; contador < 15; contador++) {
            if(ult_pagina == opcao[1] && contador >= card_tela) break;

            if(aux->card->bmp != NULL && CardPresente(aux->card->colecao,profile) == true) al_draw_scaled_bitmap(aux->card->bmp,0,0,240,360,250 + 110*(contador % 5),45 + 160*(contador / 5),100,150,0);
            else al_draw_scaled_bitmap(fundo_card,0,0,240,360,250 + 110*(contador % 5),45 + 160*(contador / 5),100,150,0);

            if(*posX >= 250 + 110*(contador % 5) && *posX < 250 + 100 + 110*(contador % 5) && *posY >= 45 + 160*(contador / 5) && *posY < 45 + 150 + 160*(contador / 5) && *mouse == true) {
                card_tbox = aux->card;
                card_atual = 15*opcao[1] + contador;
                roll_tbox = 0;

                //al_rest(0.05);
            }

            if(aux->prox != NULL) aux = aux->prox;
        }

        if(card_tbox != NULL && CardPresente(card_tbox->colecao,profile) == true) BarraRolagem(&roll_tbox,posX,posY,dltZ,mouse,card_tbox,roll_bar,texto3,cor_texto);

        if(total_cards[opcao[0]] % 15 == 0 && ult_pagina > 0) ult_pagina -= 1;
        al_draw_textf(texto4,cor_texto,615,545,0,"%d",opcao[1] + 1);
        al_draw_textf(texto4,cor_texto,700,545,0,"%d",ult_pagina + 1);

        if(opcao[1] < ult_pagina && *posX >= 740 && *posX < 790 && *posY >= 540 && *posY < 590 && *mouse == true) (opcao[1])++;
        else if(opcao[1] > 0     && *posX >= 540 && *posX < 590 && *posY >= 540 && *posY < 590 && *mouse == true) (opcao[1])--;

        else if(*posY >= 0 && *posY < 30) {
            if(*posX >= 240 && *posX < 300) {
                if(*mouse == true) {
                    opcao[0] = 0;
                    opcao[1] = 0;
                    card_atual = -1;
                    //al_rest(0.05);
                }
                else al_draw_bitmap(pont,280,-35,0);
            }
            else if(*posX >= 300 && *posX < 360) {
                if(*mouse == true) {
                    opcao[0] = 1;
                    opcao[1] = 0;
                    card_atual = -1;
                    //al_rest(0.05);
                }
                else al_draw_bitmap(pont,340,-35,0);
            }
            else if(*posX >= 360 && *posX < 420) {
                if(*mouse == true) {
                    opcao[0] = 2;
                    opcao[1] = 0;
                    card_atual = -1;
                    //al_rest(0.05);
                }
                else al_draw_bitmap(pont,400,-35,0);
            }
            else if(*posX >= 420 && *posX < 480) {
                if(*mouse == true) {
                    opcao[0] = 3;
                    opcao[1] = 0;
                    card_atual = -1;
                    //al_rest(0.05);
                }
                else al_draw_bitmap(pont,460,-35,0);
            }
            else if(*posX >= 480 && *posX < 540) {
                if(*mouse == true) {
                    opcao[0] = 4;
                    opcao[1] = 0;
                    card_atual = -1;
                    //al_rest(0.05);
                }
                else al_draw_bitmap(pont,520,-35,0);
            }
            else if(*posX >= 540 && *posX < 600) {
                if(*mouse == true) {
                    opcao[0] = 5;
                    opcao[1] = 0;
                    card_atual = -1;
                    //al_rest(0.05);
                }
                else al_draw_bitmap(pont,580,-35,0);
            }
            else if(*posX >= 600 && *posX < 660) {
                if(*mouse == true) {
                    opcao[0] = 6;
                    opcao[1] = 0;
                    card_atual = -1;
                    //al_rest(0.05);
                }
                else al_draw_bitmap(pont,640,-35,0);
            }
            else if(*posX >= 660 && *posX < 720) {
                if(*mouse == true) {
                    opcao[0] = 7;
                    opcao[1] = 0;
                    card_atual = -1;
                    //al_rest(0.05);
                }
                else al_draw_bitmap(pont,700,-35,0);
            }
            else if(*posX >= 720 && *posX < 800) {
                if(*mouse == true) break;
                else al_draw_bitmap(pont,780,-35,0);
            }
        }

        else if(*mouse == true && *posX >= 250 && *posX < 350 && *posY >= 525 && *posY < 600) {
            //al_rest(0.2);
            profile = EscolheProfile(lista_pfl,janela,texto4,texto5,cor_texto,pont,entrada,select_card,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);
            if(profile == NULL) return;
        }

        al_flip_display();
        //al_wait_for_event_timed(event_queue, &ev,0.05);
        if(ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE) break;
    }
    //al_rest(0.2);
}

void EscolheCharacter(struct PROFILE *profile,struct COLECAO *colecao,ALLEGRO_FONT *font,ALLEGRO_COLOR cor,ALLEGRO_DISPLAY *display,ALLEGRO_BITMAP *fundo,ALLEGRO_BITMAP *selecao,bool *sair,int *posX,int *posY,int *dltZ,bool *mouse,bool *mouse2,bool *mouse_lado,int *keychar,bool *repete_keychar,ALLEGRO_EVENT_QUEUE *event_queue,ALLEGRO_TIMER *keyb_press_timer,ALLEGRO_TIMER *mouse_press_timer) {
    struct Card **vetor;
    struct ProfCard *aux3;
    unsigned int cont = 0,i = 0,pagina = 0,max_pagina,ultimo;
    long int opcao = -1;
    ALLEGRO_BITMAP *temp;

    if(profile != NULL) {
        profile->main_character = -1;
        profile->nome_main_char = NULL;
    }
    if(profile == NULL || profile->char_deck == NULL || profile->char_deck->prox == NULL) {
        al_draw_bitmap(fundo,120,60,0);
        al_draw_textf(font,cor,135,400,0,"Sem characters disponiveis! Insira ao menos um character em seu Character Deck.");
        al_flip_display();
        al_rest(2.0);

        return;
    }

    aux3 = profile->char_deck;
    while(aux3->prox != NULL) {
        cont++;
        aux3 = aux3->prox;
    }
    vetor = (struct Card **)malloc(cont*sizeof(struct Card *));

    aux3 = profile->char_deck;
    while(aux3->prox != NULL) {
        CarregaCard(aux3->card,&(vetor[i]),colecao);
        i++;
        aux3 = aux3->prox;
    }
    max_pagina = cont / 12;
    ultimo = cont % 12;

    temp = al_clone_bitmap(al_get_backbuffer(display));
    while(1) {
        VerificaEventos(sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);

        if(*sair == true) {
            free(vetor);
            //al_rest(0.2);
            return;
        }
        al_clear_to_color(al_map_rgb_f(0, 0, 0));
        al_draw_tinted_bitmap(temp, al_map_rgba_f(0.3, 0.3, 0.3, 0.3),0, 0, 0);

        al_draw_bitmap(fundo,120,60,0);
        for(i = 0;i < 12;i++) {
            if(pagina == max_pagina && i >= ultimo) break;

            if(12*pagina + i == opcao) al_draw_scaled_bitmap(selecao,0,0,240,360,125 + 125*(i % 4),60 + 160*(i / 4),110,160,0);
            al_draw_scaled_bitmap(vetor[12*pagina + i]->bmp,0,0,240,360,130 + 125*(i % 4),65 + 160*(i / 4),100,150,0);
            if(*mouse == true && *posX >= 130 + 125*(i % 4) && *posX < 230 + 125*(i % 4) && *posY >= 65 + 160*(i / 4) && *posY < 215 + 160*(i / 4)) opcao = (12*pagina) + i;
        }
        al_draw_textf(font,cor,600,200,0,"%d / %d",pagina + 1,max_pagina + 1);
        al_flip_display();

        if(*mouse == true) {
            if(pagina < max_pagina && *posX >= 607 && *posX < 652 &&  *posY >= 77 && *posY < 122) pagina++;
            else if(pagina > 0     && *posX >= 607 && *posX < 652 && *posY >= 137 && *posY < 182) pagina--;

            else if(*posX >= 607 && *posX < 652 && *posY >= 482 && *posY < 527) break;
        }
    }

    if(opcao != -1) {
        profile->main_character = vetor[opcao]->colecao;
        profile->nome_main_char = vetor[opcao]->nome;
    }
    else {
        profile->main_character = -1;
        profile->nome_main_char = NULL;
    }

    free(vetor);
    al_destroy_bitmap(temp);
    //al_rest(0.2);
}

void DescarregaCartas(struct COLECAO *colecao) {
    free(colecao->link);
    free(colecao->great_dekus_bless);
    free(colecao->gohma);
    free(colecao->goron_tunic);
    free(colecao->dark_link);
    free(colecao->desert_colossus);
    free(colecao->likelike);
    free(colecao->impa);
    free(colecao->twinrova);
    free(colecao->pierre);
    free(colecao->blue_potion);
    free(colecao->flare_dancer);
    free(colecao->adult_wallet);
    free(colecao->goron_bracelet);
    free(colecao->kokiri_forest);
    free(colecao->golden_scale);
    free(colecao->master_sword);
    free(colecao->gerudo_guard);
    free(colecao->bombchu);
    free(colecao->princess_zelda);
    free(colecao->lizalfos);
    free(colecao->hookshot);
    free(colecao->young_link);
    free(colecao->ganon);
    free(colecao->spirit_medallion);
    free(colecao->goron_ruby);
    free(colecao->bongobongo);
    free(colecao->guay);
    free(colecao->moblin);
    free(colecao->bazaar_seller);
    free(colecao->king_zora);
    free(colecao->nabooru);
    free(colecao->anubis);
    free(colecao->dead_hand);
    free(colecao->death_mt_crater);
    free(colecao->hyrule_castle);
    free(colecao->lake_hylia);
    free(colecao->rauru);
    free(colecao->phantom_ganon);
    free(colecao->bigocto);
    free(colecao->tailpasaran);
    free(colecao->gerudo_fortress);
    free(colecao->cursed_villager);
    free(colecao->poe_sisters);
    free(colecao->hylian_shield);
    free(colecao->deku_seeds_bag);
    free(colecao->bless_of_triforce);
    free(colecao->skulltulas_ambush);
    free(colecao->heart_piece);
    free(colecao->milk_bottle);
    free(colecao->stinger);
    free(colecao->zoras_sapphire);
    free(colecao->peahat);
    free(colecao->gold_skulltula);
    free(colecao->larva_gohma);
    free(colecao->magic_beans);
    free(colecao->small_key);
    free(colecao->great_deku_trees_knowledge);
    free(colecao->bomb_rain);
    free(colecao->kakariko_graveyard);
    free(colecao->mido);
    free(colecao->cucco_lady);
    free(colecao->fairys_aid);
    free(colecao->triple_shot);
    free(colecao->deku_nut);
    free(colecao->dark_pathway);
    free(colecao->magic_jar);
    free(colecao->give_away);
    free(colecao->ice_arrow);
    free(colecao->play_ocarina);
    free(colecao->open_chest);
    free(colecao->crystal_switch);
    free(colecao->raze);
    free(colecao->dins_fire);
    free(colecao->mountain_climbing);
    free(colecao->horse_riding);
    free(colecao->_1_ton_rock_lifting);
    free(colecao->octorok);
    free(colecao->joelle);
    free(colecao->torch_slug);
    free(colecao->spike);
    free(colecao->bomb_bag);
    free(colecao->fairy_slingshot);
    free(colecao->compass);
    free(colecao->guillotine);
    free(colecao->skullwalltula);
    free(colecao->baby_dodongo);
    free(colecao->fabulous_five_froggish_tenors);
    free(colecao->leever);
    free(colecao->red_tektite);
    free(colecao->blue_tektite);
    free(colecao->granny);
    free(colecao->wolfos);
    free(colecao->shabom);
    free(colecao->silver_gauntlets);
    free(colecao->worlds_finest_eye_drops);
    free(colecao->ocarina_of_time);
    free(colecao->gossip_stone);
    free(colecao->ganons_castle);
    free(colecao->dungeon_map);
    free(colecao->gerudos_membership_card);
    free(colecao->shadow_merge);
    free(colecao->golden_gauntlets);
    free(colecao->mask_of_truth);
    free(colecao->warp);
    free(colecao->giant_leever);
    free(colecao->big_poe);
    free(colecao->skull_mask);
    free(colecao->ganondorf);
    free(colecao->chest);
    free(colecao->skull_kid);
    free(colecao->princess_ruto);
    free(colecao->light_medallion);
    free(colecao->fire_arrow);
    free(colecao->jump_quest_water);
    free(colecao->white_wolfos);
    free(colecao->sunset);
    free(colecao->channeled_strike);
    free(colecao->purple_rupee);
    free(colecao->redead);
    free(colecao->beamos);
    free(colecao->iron_knuckles);
    free(colecao->dodongo);
    free(colecao->freezard);
    free(colecao->business_scrub);
    free(colecao->jump_quest_wind);
    free(colecao->underground_shelter);
    free(colecao->hover_boots);
    free(colecao->epona);
    free(colecao->claim_check);
    free(colecao->purple_poe_remnant);
    free(colecao->green_poe_remnant);
    free(colecao->fire_temple);
    free(colecao->bigger_bomb_bag);
    free(colecao->bomb);
    free(colecao->malon);
    free(colecao->boomerang);
    free(colecao->tricky_shot);
    free(colecao->kokiri_tunic);
    free(colecao->stalfos);
    free(colecao->big_deku_baba);
    free(colecao->fairy_fountain);
    free(colecao->mystic_spell);
    free(colecao->great_fairys_bless);
    free(colecao->keese);

    free(colecao);
}

void CarregaCartas(struct COLECAO **lista,ALLEGRO_FONT *font) {
    struct COLECAO *colecao;

    *lista = (struct COLECAO *)malloc(sizeof(struct COLECAO));
    colecao = *lista;

    colecao->link = (struct Card *)malloc(sizeof(struct Card));
    colecao->great_dekus_bless = (struct Card *)malloc(sizeof(struct Card));
    colecao->gohma = (struct Card *)malloc(sizeof(struct Card));
    colecao->goron_tunic = (struct Card *)malloc(sizeof(struct Card));
    colecao->dark_link = (struct Card *)malloc(sizeof(struct Card));
    colecao->desert_colossus = (struct Card *)malloc(sizeof(struct Card));
    colecao->likelike = (struct Card *)malloc(sizeof(struct Card));
    colecao->impa = (struct Card *)malloc(sizeof(struct Card));
    colecao->twinrova = (struct Card *)malloc(sizeof(struct Card));
    colecao->pierre = (struct Card *)malloc(sizeof(struct Card));
    colecao->blue_potion = (struct Card *)malloc(sizeof(struct Card));
    colecao->flare_dancer = (struct Card *)malloc(sizeof(struct Card));
    colecao->adult_wallet = (struct Card *)malloc(sizeof(struct Card));
    colecao->goron_bracelet = (struct Card *)malloc(sizeof(struct Card));
    colecao->kokiri_forest = (struct Card *)malloc(sizeof(struct Card));
    colecao->golden_scale = (struct Card *)malloc(sizeof(struct Card));
    colecao->master_sword = (struct Card *)malloc(sizeof(struct Card));
    colecao->gerudo_guard = (struct Card *)malloc(sizeof(struct Card));
    colecao->bombchu = (struct Card *)malloc(sizeof(struct Card));
    colecao->princess_zelda = (struct Card *)malloc(sizeof(struct Card));
    colecao->lizalfos = (struct Card *)malloc(sizeof(struct Card));
    colecao->hookshot = (struct Card *)malloc(sizeof(struct Card));
    colecao->young_link = (struct Card *)malloc(sizeof(struct Card));
    colecao->ganon = (struct Card *)malloc(sizeof(struct Card));
    colecao->spirit_medallion = (struct Card *)malloc(sizeof(struct Card));
    colecao->goron_ruby = (struct Card *)malloc(sizeof(struct Card));
    colecao->bongobongo = (struct Card *)malloc(sizeof(struct Card));
    colecao->guay = (struct Card *)malloc(sizeof(struct Card));
    colecao->moblin = (struct Card *)malloc(sizeof(struct Card));
    colecao->bazaar_seller = (struct Card *)malloc(sizeof(struct Card));
    colecao->king_zora = (struct Card *)malloc(sizeof(struct Card));
    colecao->nabooru = (struct Card *)malloc(sizeof(struct Card));
    colecao->anubis = (struct Card *)malloc(sizeof(struct Card));
    colecao->dead_hand = (struct Card *)malloc(sizeof(struct Card));
    colecao->death_mt_crater = (struct Card *)malloc(sizeof(struct Card));
    colecao->hyrule_castle = (struct Card *)malloc(sizeof(struct Card));
    colecao->lake_hylia = (struct Card *)malloc(sizeof(struct Card));
    colecao->rauru = (struct Card *)malloc(sizeof(struct Card));
    colecao->phantom_ganon = (struct Card *)malloc(sizeof(struct Card));
    colecao->bigocto = (struct Card *)malloc(sizeof(struct Card));
    colecao->tailpasaran = (struct Card *)malloc(sizeof(struct Card));
    colecao->gerudo_fortress = (struct Card *)malloc(sizeof(struct Card));
    colecao->cursed_villager = (struct Card *)malloc(sizeof(struct Card));
    colecao->poe_sisters = (struct Card *)malloc(sizeof(struct Card));
    colecao->hylian_shield = (struct Card *)malloc(sizeof(struct Card));
    colecao->deku_seeds_bag = (struct Card *)malloc(sizeof(struct Card));
    colecao->bless_of_triforce = (struct Card *)malloc(sizeof(struct Card));
    colecao->skulltulas_ambush = (struct Card *)malloc(sizeof(struct Card));
    colecao->heart_piece = (struct Card *)malloc(sizeof(struct Card));
    colecao->milk_bottle = (struct Card *)malloc(sizeof(struct Card));
    colecao->stinger = (struct Card *)malloc(sizeof(struct Card));
    colecao->zoras_sapphire = (struct Card *)malloc(sizeof(struct Card));
    colecao->peahat = (struct Card *)malloc(sizeof(struct Card));
    colecao->gold_skulltula = (struct Card *)malloc(sizeof(struct Card));
    colecao->larva_gohma = (struct Card *)malloc(sizeof(struct Card));
    colecao->magic_beans = (struct Card *)malloc(sizeof(struct Card));
    colecao->small_key = (struct Card *)malloc(sizeof(struct Card));
    colecao->great_deku_trees_knowledge = (struct Card *)malloc(sizeof(struct Card));
    colecao->bomb_rain = (struct Card *)malloc(sizeof(struct Card));
    colecao->kakariko_graveyard = (struct Card *)malloc(sizeof(struct Card));
    colecao->mido = (struct Card *)malloc(sizeof(struct Card));
    colecao->cucco_lady = (struct Card *)malloc(sizeof(struct Card));
    colecao->fairys_aid = (struct Card *)malloc(sizeof(struct Card));
    colecao->triple_shot = (struct Card *)malloc(sizeof(struct Card));
    colecao->deku_nut = (struct Card *)malloc(sizeof(struct Card));
    colecao->dark_pathway = (struct Card *)malloc(sizeof(struct Card));
    colecao->magic_jar = (struct Card *)malloc(sizeof(struct Card));
    colecao->give_away = (struct Card *)malloc(sizeof(struct Card));
    colecao->ice_arrow = (struct Card *)malloc(sizeof(struct Card));
    colecao->play_ocarina = (struct Card *)malloc(sizeof(struct Card));
    colecao->open_chest = (struct Card *)malloc(sizeof(struct Card));
    colecao->crystal_switch = (struct Card *)malloc(sizeof(struct Card));
    colecao->raze = (struct Card *)malloc(sizeof(struct Card));
    colecao->dins_fire = (struct Card *)malloc(sizeof(struct Card));
    colecao->mountain_climbing = (struct Card *)malloc(sizeof(struct Card));
    colecao->horse_riding = (struct Card *)malloc(sizeof(struct Card));
    colecao->_1_ton_rock_lifting = (struct Card *)malloc(sizeof(struct Card));
    colecao->octorok = (struct Card *)malloc(sizeof(struct Card));
    colecao->joelle = (struct Card *)malloc(sizeof(struct Card));
    colecao->torch_slug = (struct Card *)malloc(sizeof(struct Card));
    colecao->spike = (struct Card *)malloc(sizeof(struct Card));
    colecao->bomb_bag = (struct Card *)malloc(sizeof(struct Card));
    colecao->fairy_slingshot = (struct Card *)malloc(sizeof(struct Card));
    colecao->compass = (struct Card *)malloc(sizeof(struct Card));
    colecao->guillotine = (struct Card *)malloc(sizeof(struct Card));
    colecao->skullwalltula = (struct Card *)malloc(sizeof(struct Card));
    colecao->baby_dodongo = (struct Card *)malloc(sizeof(struct Card));
    colecao->fabulous_five_froggish_tenors = (struct Card *)malloc(sizeof(struct Card));
    colecao->leever = (struct Card *)malloc(sizeof(struct Card));
    colecao->red_tektite = (struct Card *)malloc(sizeof(struct Card));
    colecao->blue_tektite = (struct Card *)malloc(sizeof(struct Card));
    colecao->granny = (struct Card *)malloc(sizeof(struct Card));
    colecao->wolfos = (struct Card *)malloc(sizeof(struct Card));
    colecao->shabom = (struct Card *)malloc(sizeof(struct Card));
    colecao->silver_gauntlets = (struct Card *)malloc(sizeof(struct Card));
    colecao->worlds_finest_eye_drops = (struct Card *)malloc(sizeof(struct Card));
    colecao->ocarina_of_time = (struct Card *)malloc(sizeof(struct Card));
    colecao->gossip_stone = (struct Card *)malloc(sizeof(struct Card));
    colecao->ganons_castle = (struct Card *)malloc(sizeof(struct Card));
    colecao->dungeon_map = (struct Card *)malloc(sizeof(struct Card));
    colecao->gerudos_membership_card = (struct Card *)malloc(sizeof(struct Card));
    colecao->shadow_merge = (struct Card *)malloc(sizeof(struct Card));
    colecao->golden_gauntlets = (struct Card *)malloc(sizeof(struct Card));
    colecao->mask_of_truth = (struct Card *)malloc(sizeof(struct Card));
    colecao->warp = (struct Card *)malloc(sizeof(struct Card));
    colecao->giant_leever = (struct Card *)malloc(sizeof(struct Card));
    colecao->big_poe = (struct Card *)malloc(sizeof(struct Card));
    colecao->skull_mask = (struct Card *)malloc(sizeof(struct Card));
    colecao->ganondorf = (struct Card *)malloc(sizeof(struct Card));
    colecao->chest = (struct Card *)malloc(sizeof(struct Card));
    colecao->skull_kid = (struct Card *)malloc(sizeof(struct Card));
    colecao->princess_ruto = (struct Card *)malloc(sizeof(struct Card));
    colecao->light_medallion = (struct Card *)malloc(sizeof(struct Card));
    colecao->fire_arrow = (struct Card *)malloc(sizeof(struct Card));
    colecao->jump_quest_water = (struct Card *)malloc(sizeof(struct Card));
    colecao->iron_boots = (struct Card *)malloc(sizeof(struct Card));
    colecao->mirror_shield = (struct Card *)malloc(sizeof(struct Card));
    colecao->white_wolfos = (struct Card *)malloc(sizeof(struct Card));
    colecao->whirling_scythes = (struct Card *)malloc(sizeof(struct Card));
    colecao->darunia = (struct Card *)malloc(sizeof(struct Card));
    colecao->sunset = (struct Card *)malloc(sizeof(struct Card));
    colecao->channeled_strike = (struct Card *)malloc(sizeof(struct Card));
    colecao->purple_rupee = (struct Card *)malloc(sizeof(struct Card));
    colecao->redead = (struct Card *)malloc(sizeof(struct Card));
    colecao->beamos = (struct Card *)malloc(sizeof(struct Card));
    colecao->iron_knuckles = (struct Card *)malloc(sizeof(struct Card));
    colecao->dodongo = (struct Card *)malloc(sizeof(struct Card));
    colecao->freezard = (struct Card *)malloc(sizeof(struct Card));
    colecao->business_scrub = (struct Card *)malloc(sizeof(struct Card));
    colecao->jump_quest_wind = (struct Card *)malloc(sizeof(struct Card));
    colecao->underground_shelter = (struct Card *)malloc(sizeof(struct Card));
    colecao->hover_boots = (struct Card *)malloc(sizeof(struct Card));
    colecao->epona = (struct Card *)malloc(sizeof(struct Card));
    colecao->claim_check = (struct Card *)malloc(sizeof(struct Card));
    colecao->purple_poe_remnant = (struct Card *)malloc(sizeof(struct Card));
    colecao->green_poe_remnant = (struct Card *)malloc(sizeof(struct Card));
    colecao->fire_temple = (struct Card *)malloc(sizeof(struct Card));
    colecao->bigger_bomb_bag = (struct Card *)malloc(sizeof(struct Card));
    colecao->bomb = (struct Card *)malloc(sizeof(struct Card));
    colecao->malon = (struct Card *)malloc(sizeof(struct Card));
    colecao->boomerang = (struct Card *)malloc(sizeof(struct Card));
    colecao->tricky_shot = (struct Card *)malloc(sizeof(struct Card));
    colecao->kokiri_tunic = (struct Card *)malloc(sizeof(struct Card));
    colecao->stalfos = (struct Card *)malloc(sizeof(struct Card));
    colecao->big_deku_baba = (struct Card *)malloc(sizeof(struct Card));
    colecao->fairy_fountain = (struct Card *)malloc(sizeof(struct Card));
    colecao->mystic_spell = (struct Card *)malloc(sizeof(struct Card));
    colecao->great_fairys_bless = (struct Card *)malloc(sizeof(struct Card));
    colecao->keese = (struct Card *)malloc(sizeof(struct Card));

    link(colecao->link);
    great_dekus_bless(colecao->great_dekus_bless);
    gohma(colecao->gohma);
    goron_tunic(colecao->goron_tunic);
    dark_link(colecao->dark_link);
    desert_colossus(colecao->desert_colossus);
    likelike(colecao->likelike);
    impa(colecao->impa);
    twinrova(colecao->twinrova);
    pierre(colecao->pierre);
    blue_potion(colecao->blue_potion);
    flare_dancer(colecao->flare_dancer);
    adult_wallet(colecao->adult_wallet);
    goron_bracelet(colecao->goron_bracelet);
    kokiri_forest(colecao->kokiri_forest);
    golden_scale(colecao->golden_scale);
    master_sword(colecao->master_sword);
    gerudo_guard(colecao->gerudo_guard);
    bombchu(colecao->bombchu);
    princess_zelda(colecao->princess_zelda);
    lizalfos(colecao->lizalfos);
    hookshot(colecao->hookshot);
    young_link(colecao->young_link);
    ganon(colecao->ganon);
    spirit_medallion(colecao->spirit_medallion);
    goron_ruby(colecao->goron_ruby);
    bongobongo(colecao->bongobongo);
    guay(colecao->guay);
    moblin(colecao->moblin);
    bazaar_seller(colecao->bazaar_seller);
    king_zora(colecao->king_zora);
    nabooru(colecao->nabooru);
    anubis(colecao->anubis);
    dead_hand(colecao->dead_hand);
    death_mt_crater(colecao->death_mt_crater);
    hyrule_castle(colecao->hyrule_castle);
    lake_hylia(colecao->lake_hylia);
    rauru(colecao->rauru);
    phantom_ganon(colecao->phantom_ganon);
    bigocto(colecao->bigocto);
    tailpasaran(colecao->tailpasaran);
    gerudo_fortress(colecao->gerudo_fortress);
    cursed_villager(colecao->cursed_villager);
    poe_sisters(colecao->poe_sisters);
    hylian_shield(colecao->hylian_shield);
    deku_seeds_bag(colecao->deku_seeds_bag);
    bless_of_triforce(colecao->bless_of_triforce);
    skulltulas_ambush(colecao->skulltulas_ambush);
    heart_piece(colecao->heart_piece);
    milk_bottle(colecao->milk_bottle);
    stinger(colecao->stinger);
    zoras_sapphire(colecao->zoras_sapphire);
    peahat(colecao->peahat);
    gold_skulltula(colecao->gold_skulltula);
    larva_gohma(colecao->larva_gohma);
    magic_beans(colecao->magic_beans);
    small_key(colecao->small_key);
    great_deku_trees_knowledge(colecao->great_deku_trees_knowledge);
    bomb_rain(colecao->bomb_rain);
    kakariko_graveyard(colecao->kakariko_graveyard);
    mido(colecao->mido);
    cucco_lady(colecao->cucco_lady);
    fairys_aid(colecao->fairys_aid);
    triple_shot(colecao->triple_shot);
    deku_nut(colecao->deku_nut);
    dark_pathway(colecao->dark_pathway);
    magic_jar(colecao->magic_jar);
    give_away(colecao->give_away);
    ice_arrow(colecao->ice_arrow);
    play_ocarina(colecao->play_ocarina);
    open_chest(colecao->open_chest);
    crystal_switch(colecao->crystal_switch);
    raze(colecao->raze);
    dins_fire(colecao->dins_fire);
    mountain_climbing(colecao->mountain_climbing);
    horse_riding(colecao->horse_riding);
    _1_ton_rock_lifting(colecao->_1_ton_rock_lifting);
    octorok(colecao->octorok);
    joelle(colecao->joelle);
    torch_slug(colecao->torch_slug);
    spike(colecao->spike);
    bomb_bag(colecao->bomb_bag);
    fairy_slingshot(colecao->fairy_slingshot);
    compass(colecao->compass);
    guillotine(colecao->guillotine);
    skullwalltula(colecao->skullwalltula);
    baby_dodongo(colecao->baby_dodongo);
    fabulous_five_froggish_tenors(colecao->fabulous_five_froggish_tenors);
    leever(colecao->leever);
    red_tektite(colecao->red_tektite);
    blue_tektite(colecao->blue_tektite);
    granny(colecao->granny);
    wolfos(colecao->wolfos);
    shabom(colecao->shabom);
    silver_gauntlets(colecao->silver_gauntlets);
    worlds_finest_eye_drops(colecao->worlds_finest_eye_drops);
    ocarina_of_time(colecao->ocarina_of_time);
    gossip_stone(colecao->gossip_stone);
    ganons_castle(colecao->ganons_castle);
    dungeon_map(colecao->dungeon_map);
    gerudos_membership_card(colecao->gerudos_membership_card);
    shadow_merge(colecao->shadow_merge);
    golden_gauntlets(colecao->golden_gauntlets);
    mask_of_truth(colecao->mask_of_truth);
    warp(colecao->warp);
    giant_leever(colecao->giant_leever);
    big_poe(colecao->big_poe);
    skull_mask(colecao->skull_mask);
    ganondorf(colecao->ganondorf);
    chest(colecao->chest);
    skull_kid(colecao->skull_kid);
    princess_ruto(colecao->princess_ruto);
    light_medallion(colecao->light_medallion);
    fire_arrow(colecao->fire_arrow);
    jump_quest_water(colecao->jump_quest_water);
    iron_boots(colecao->iron_boots);
    mirror_shield(colecao->mirror_shield);
    white_wolfos(colecao->white_wolfos);
    whirling_scythes(colecao->whirling_scythes);
    darunia(colecao->darunia);
    sunset(colecao->sunset);
    channeled_strike(colecao->channeled_strike);
    purple_rupee(colecao->purple_rupee);
    redead(colecao->redead);
    beamos(colecao->beamos);
    iron_knuckles(colecao->iron_knuckles);
    dodongo(colecao->dodongo);
    freezard(colecao->freezard);
    business_scrub(colecao->business_scrub);
    jump_quest_wind(colecao->jump_quest_wind);
    underground_shelter(colecao->underground_shelter);
    hover_boots(colecao->hover_boots);
    epona(colecao->epona);
    claim_check(colecao->claim_check);
    purple_poe_remnant(colecao->purple_poe_remnant);
    green_poe_remnant(colecao->green_poe_remnant);
    fire_temple(colecao->fire_temple);
    bigger_bomb_bag(colecao->bigger_bomb_bag);
    bomb(colecao->bomb);
    malon(colecao->malon);
    boomerang(colecao->boomerang);
    tricky_shot(colecao->tricky_shot);
    kokiri_tunic(colecao->kokiri_tunic);
    stalfos(colecao->stalfos);
    big_deku_baba(colecao->big_deku_baba);
    fairy_fountain(colecao->fairy_fountain);
    mystic_spell(colecao->mystic_spell);
    great_fairys_bless(colecao->great_fairys_bless);
    keese(colecao->keese);

    EscreveTextoCard(colecao->link,font);
    EscreveTextoCard(colecao->great_dekus_bless,font);
    EscreveTextoCard(colecao->gohma,font);
    EscreveTextoCard(colecao->goron_tunic,font);
    EscreveTextoCard(colecao->dark_link,font);
    EscreveTextoCard(colecao->desert_colossus,font);
    EscreveTextoCard(colecao->likelike,font);
    EscreveTextoCard(colecao->impa,font);
    EscreveTextoCard(colecao->twinrova,font);
    EscreveTextoCard(colecao->pierre,font);
    EscreveTextoCard(colecao->blue_potion,font);
    EscreveTextoCard(colecao->flare_dancer,font);
    EscreveTextoCard(colecao->adult_wallet,font);
    EscreveTextoCard(colecao->goron_bracelet,font);
    EscreveTextoCard(colecao->kokiri_forest,font);
    EscreveTextoCard(colecao->golden_scale,font);
    EscreveTextoCard(colecao->master_sword,font);
    EscreveTextoCard(colecao->gerudo_guard,font);
    EscreveTextoCard(colecao->bombchu,font);
    EscreveTextoCard(colecao->princess_zelda,font);
    EscreveTextoCard(colecao->lizalfos,font);
    EscreveTextoCard(colecao->hookshot,font);
    EscreveTextoCard(colecao->young_link,font);
    EscreveTextoCard(colecao->ganon,font);
    EscreveTextoCard(colecao->spirit_medallion,font);
    EscreveTextoCard(colecao->goron_ruby,font);
    EscreveTextoCard(colecao->bongobongo,font);
    EscreveTextoCard(colecao->guay,font);
    EscreveTextoCard(colecao->moblin,font);
    EscreveTextoCard(colecao->bazaar_seller,font);
    EscreveTextoCard(colecao->king_zora,font);
    EscreveTextoCard(colecao->nabooru,font);
    EscreveTextoCard(colecao->anubis,font);
    EscreveTextoCard(colecao->dead_hand,font);
    EscreveTextoCard(colecao->death_mt_crater,font);
    EscreveTextoCard(colecao->hyrule_castle,font);
    EscreveTextoCard(colecao->lake_hylia,font);
    EscreveTextoCard(colecao->rauru,font);
    EscreveTextoCard(colecao->phantom_ganon,font);
    EscreveTextoCard(colecao->bigocto,font);
    EscreveTextoCard(colecao->tailpasaran,font);
    EscreveTextoCard(colecao->gerudo_fortress,font);
    EscreveTextoCard(colecao->cursed_villager,font);
    EscreveTextoCard(colecao->poe_sisters,font);
    EscreveTextoCard(colecao->hylian_shield,font);
    EscreveTextoCard(colecao->deku_seeds_bag,font);
    EscreveTextoCard(colecao->bless_of_triforce,font);
    EscreveTextoCard(colecao->skulltulas_ambush,font);
    EscreveTextoCard(colecao->heart_piece,font);
    EscreveTextoCard(colecao->milk_bottle,font);
    EscreveTextoCard(colecao->stinger,font);
    EscreveTextoCard(colecao->zoras_sapphire,font);
    EscreveTextoCard(colecao->peahat,font);
    EscreveTextoCard(colecao->gold_skulltula,font);
    EscreveTextoCard(colecao->larva_gohma,font);
    EscreveTextoCard(colecao->magic_beans,font);
    EscreveTextoCard(colecao->small_key,font);
    EscreveTextoCard(colecao->great_deku_trees_knowledge,font);
    EscreveTextoCard(colecao->bomb_rain,font);
    EscreveTextoCard(colecao->kakariko_graveyard,font);
    EscreveTextoCard(colecao->mido,font);
    EscreveTextoCard(colecao->cucco_lady,font);
    EscreveTextoCard(colecao->fairys_aid,font);
    EscreveTextoCard(colecao->triple_shot,font);
    EscreveTextoCard(colecao->deku_nut,font);
    EscreveTextoCard(colecao->dark_pathway,font);
    EscreveTextoCard(colecao->magic_jar,font);
    EscreveTextoCard(colecao->give_away,font);
    EscreveTextoCard(colecao->ice_arrow,font);
    EscreveTextoCard(colecao->play_ocarina,font);
    EscreveTextoCard(colecao->open_chest,font);
    EscreveTextoCard(colecao->crystal_switch,font);
    EscreveTextoCard(colecao->raze,font);
    EscreveTextoCard(colecao->dins_fire,font);
    EscreveTextoCard(colecao->mountain_climbing,font);
    EscreveTextoCard(colecao->horse_riding,font);
    EscreveTextoCard(colecao->_1_ton_rock_lifting,font);
    EscreveTextoCard(colecao->octorok,font);
    EscreveTextoCard(colecao->joelle,font);
    EscreveTextoCard(colecao->torch_slug,font);
    EscreveTextoCard(colecao->spike,font);
    EscreveTextoCard(colecao->bomb_bag,font);
    EscreveTextoCard(colecao->fairy_slingshot,font);
    EscreveTextoCard(colecao->compass,font);
    EscreveTextoCard(colecao->guillotine,font);
    EscreveTextoCard(colecao->skullwalltula,font);
    EscreveTextoCard(colecao->baby_dodongo,font);
    EscreveTextoCard(colecao->fabulous_five_froggish_tenors,font);
    EscreveTextoCard(colecao->leever,font);
    EscreveTextoCard(colecao->red_tektite,font);
    EscreveTextoCard(colecao->blue_tektite,font);
    EscreveTextoCard(colecao->granny,font);
    EscreveTextoCard(colecao->wolfos,font);
    EscreveTextoCard(colecao->shabom,font);
    EscreveTextoCard(colecao->silver_gauntlets,font);
    EscreveTextoCard(colecao->worlds_finest_eye_drops,font);
    EscreveTextoCard(colecao->ocarina_of_time,font);
    EscreveTextoCard(colecao->gossip_stone,font);
    EscreveTextoCard(colecao->ganons_castle,font);
    EscreveTextoCard(colecao->dungeon_map,font);
    EscreveTextoCard(colecao->gerudos_membership_card,font);
    EscreveTextoCard(colecao->shadow_merge,font);
    EscreveTextoCard(colecao->golden_gauntlets,font);
    EscreveTextoCard(colecao->mask_of_truth,font);
    EscreveTextoCard(colecao->warp,font);
    EscreveTextoCard(colecao->giant_leever,font);
    EscreveTextoCard(colecao->big_poe,font);
    EscreveTextoCard(colecao->skull_mask,font);
    EscreveTextoCard(colecao->ganondorf,font);
    EscreveTextoCard(colecao->chest,font);
    EscreveTextoCard(colecao->skull_kid,font);
    EscreveTextoCard(colecao->princess_ruto,font);
    EscreveTextoCard(colecao->light_medallion,font);
    EscreveTextoCard(colecao->fire_arrow,font);
    EscreveTextoCard(colecao->jump_quest_water,font);
    EscreveTextoCard(colecao->iron_boots,font);
    EscreveTextoCard(colecao->mirror_shield,font);
    EscreveTextoCard(colecao->white_wolfos,font);
    EscreveTextoCard(colecao->whirling_scythes,font);
    EscreveTextoCard(colecao->darunia,font);
    EscreveTextoCard(colecao->sunset,font);
    EscreveTextoCard(colecao->channeled_strike,font);
    EscreveTextoCard(colecao->purple_rupee,font);
    EscreveTextoCard(colecao->redead,font);
    EscreveTextoCard(colecao->beamos,font);
    EscreveTextoCard(colecao->iron_knuckles,font);
    EscreveTextoCard(colecao->dodongo,font);
    EscreveTextoCard(colecao->freezard,font);
    EscreveTextoCard(colecao->business_scrub,font);
    EscreveTextoCard(colecao->jump_quest_wind,font);
    EscreveTextoCard(colecao->underground_shelter,font);
    EscreveTextoCard(colecao->hover_boots,font);
    EscreveTextoCard(colecao->epona,font);
    EscreveTextoCard(colecao->claim_check,font);
    EscreveTextoCard(colecao->purple_poe_remnant,font);
    EscreveTextoCard(colecao->green_poe_remnant,font);
    EscreveTextoCard(colecao->fire_temple,font);
    EscreveTextoCard(colecao->bigger_bomb_bag,font);
    EscreveTextoCard(colecao->bomb,font);
    EscreveTextoCard(colecao->malon,font);
    EscreveTextoCard(colecao->boomerang,font);
    EscreveTextoCard(colecao->tricky_shot,font);
    EscreveTextoCard(colecao->kokiri_tunic,font);
    EscreveTextoCard(colecao->stalfos,font);
    EscreveTextoCard(colecao->big_deku_baba,font);
    EscreveTextoCard(colecao->fairy_fountain,font);
    EscreveTextoCard(colecao->mystic_spell,font);
    EscreveTextoCard(colecao->great_fairys_bless,font);
    EscreveTextoCard(colecao->keese,font);

    printf("Carregando Cards OK!\n");
}

#endif // CARD_C_INCLUDED
