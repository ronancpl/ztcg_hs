#ifndef ESTRUTURA_UTIL_C_INCLUDED
#define ESTRUTURA_UTIL_C_INCLUDED

void InicializaListaQteAtaques(struct VariaveisMONSTER *var_monster) {
    var_monster->lista_qte_ataques = (struct QteAtaques *)malloc(sizeof(struct QteAtaques));
    var_monster->lista_qte_ataques->prox = NULL;
}

void FinalizaListaQteAtaques(struct VariaveisMONSTER *var_monster) {
    struct QteAtaques *aux = var_monster->lista_qte_ataques,*aux2;

    while(aux->prox != NULL) {
        aux2 = aux;
        aux = aux->prox;
        free(aux2);
    }
    free(aux);
}

short int RetornaMaiorQuantidadeAtaques(struct QteAtaques *lista) {
    struct QteAtaques *aux = lista;
    short int qte = -1;

    while(aux->prox != NULL) {
        if(aux->quantidade > qte) qte = aux->quantidade;
        aux = aux->prox;
    }

    if(qte < 0) printf("ERRO: encontrou -1 em quantidade de ataques!\n");
    return(qte);
}

void AdicionaNovaQuantidadeAtaque(struct QteAtaques **lista,struct CARD *origem,short int qte) {
    struct QteAtaques *aux = *lista;

    while(aux->prox != NULL) {
        if(aux->origem == origem) {
            aux->quantidade = qte;
            return;
        }
        aux = aux->prox;
    }
    aux->origem = origem;
    aux->quantidade = qte;

    aux->prox = (struct QteAtaques *)malloc(sizeof(struct QteAtaques));
    aux->prox->prox = NULL;
}

void RetiraQuantidadeAtaquePorOrigem(struct QteAtaques **lista,struct CARD *origem) {
    struct QteAtaques *aux = *lista,*aux2 = NULL;

    while(aux->prox != NULL) {
        if(aux->origem == origem) break;

        aux2 = aux;
        aux = aux->prox;
    }
    if(aux->prox == NULL) return;

    if(aux2 != NULL) aux2->prox = aux->prox;
    else (*lista) = aux->prox;

    free(aux);
}

void EsvaziaListaQuantidadeAtaques(struct QteAtaques **lista) {
    struct QteAtaques *aux = *lista,*aux2;

    while(aux->prox != NULL) {
        aux2 = aux;
        aux = aux->prox;

        free(aux2);
    }

    *lista = aux;
}

//------------------------------------------------------------

void Menu_Cria(struct Deck **menu,struct Deck **celula_atual) {
    *menu = (struct Deck *)malloc(sizeof(struct Deck));
    *celula_atual = *menu;
}

void Menu_CopiaDado(struct Deck **celula_atual,struct CARD *alvo) {
    (*celula_atual)->card = alvo;
    (*celula_atual)->prox = (struct Deck *)malloc(sizeof(struct Deck));
    (*celula_atual) = (*celula_atual)->prox;
}

void Menu_CelulaFinal(struct Deck **celula_final) {
    (*celula_final)->prox = NULL;
}

void Menu_Finaliza(struct Deck *menu) {
    struct Deck *aux,*aux2;

    aux = menu;
    while(aux->prox != NULL) {
        aux2 = aux;
        aux = aux->prox;
        free(aux2);
    }
    free(aux);
}

int RetornaQuantidadeCardsNaLista(struct Deck *lista) {
    int cont = 0;
    struct Deck *aux = lista;

    while(aux->prox != NULL) {
        aux = aux->prox;
        cont++;
    }

    return(cont);
}

void ColocaNovoCardNoDeck(struct Lista **lista,struct Deck *card) {
    if(card == NULL) return;

    card->prox = (*lista)->inicio;
    (*lista)->inicio = card;
    ((*lista)->quantidade)++;
}

void MoveCardProTopo(struct Lista **lista,struct Deck *card) {   //Dado um card que PERTENCA ao deck, este eh movido para o topo imediatamente.
    struct Deck *aux,*aux2;

    if(card == NULL) return;
    if((*lista)->inicio == card) return;

    aux = (*lista)->inicio;
    while(aux->prox != NULL) {
        aux2 = aux;
        aux = aux->prox;

        if(aux->card == card->card) {
            aux2->prox = aux->prox;
            aux->prox = (*lista)->inicio;
            (*lista)->inicio = aux;

            break;
        }
    }
}

void ColocaListaCardsNoTopoDeck(struct Lista **lista, struct Deck *sublista) {
    struct Deck *aux,*aux2;
    int qte_cards;

    if(sublista == NULL) return;
    if(sublista->prox == NULL) {
        free(sublista);
        return;
    }

    aux = sublista;
    aux2 = NULL;
    qte_cards = 0;
    printf("listagem: ");
    while(aux->prox != NULL) {
        qte_cards++;
        printf("'%s', ", aux->card->origem->nome);
        aux2 = aux;
        aux = aux->prox;
    }
    printf(" ---> %d cards", qte_cards);
    printf("\n");
    free(aux);

    aux2->prox = (*lista)->inicio;
    (*lista)->inicio = sublista;

    (*lista)->quantidade += qte_cards;
}

void ColocaListaCardsNaBaseDeck(struct Lista **lista, struct Deck *sublista) {
    struct Deck *deck,*ant,*aux,*aux2;
    int qte_cards;

    if(sublista == NULL) return;
    if(sublista->prox == NULL) {
        free(sublista);
        return;
    }

    deck = (*lista)->inicio;
    ant = NULL;
    while(deck->prox != NULL) {
        ant = deck;
        deck = deck->prox;
    }

    aux = sublista;
    aux2 = NULL;
    qte_cards = 0;
    printf("listagem: ");
    while(aux->prox != NULL) {
        qte_cards++;
        printf("'%s', ", aux->card->origem->nome);
        aux2 = aux;
        aux = aux->prox;
    }
    printf(" ---> %d cards", qte_cards);
    printf("\n");
    free(aux);

    if(ant != NULL) {
        ant->prox = sublista;
        aux2->prox = deck;
    }
    else {
        aux2->prox = (*lista)->inicio;
        (*lista)->inicio = sublista;
    }

    (*lista)->quantidade += qte_cards;
}

struct Deck *RetiraCardPorCopiaInstancia(struct Deck *card,struct Lista **lista) {
    //retorna a instancia do card na lista que deu origem ao PONTEIRO DADO COMO PARAMETRO em 'card'.

    struct Deck *aux,*aux2;

    aux2 = NULL;
    aux = (*lista)->inicio;
    while(card->card != aux->card) {
        aux2 = aux;
        aux = aux->prox;
    }
    if(aux2 == NULL) (*lista)->inicio = aux->prox;
    else aux2->prox = aux->prox;

    (*lista)->quantidade--;
    return(aux);
}

void RetiraCardPorCopiaSuperMenu(struct Deck *escolhido,struct Deck **menu) {
    //card a ser retirado pertence a um menu QUE EH ORIGEM dos dados do menu do card 'escolhido'.
    struct Deck *aux3,*aux4 = NULL;

    aux3 = *menu;
    while(aux3->card != escolhido->card) {
        aux4 = aux3;
        aux3 = aux3->prox;
    }
    if(aux4 != NULL) aux4->prox = aux3->prox;
    else *menu = aux3->prox;

    free(aux3);
}

void RetiraCardPorCopiaMenu(struct Deck *card, struct Deck **menu) {
    //card a ser retirado do menu PRECISA EXISTIR NELE.
    struct Deck *aux,*aux2;

    aux = *menu;
    aux2 = NULL;
    while(aux->card != card->card) {
        aux2 = aux;
        aux = aux->prox;
    }

    if(aux2 != NULL) aux2->prox = aux->prox;
    else *menu = aux->prox;
}

void RetiraCardPorCopia(struct Deck *card, struct Lista **lista) {
    struct Deck *aux,*aux2;

    aux = (*lista)->inicio;
    aux2 = NULL;
    while(aux != card) {
        aux2 = aux;
        aux = aux->prox;
    }

    if(aux2 != NULL) aux2->prox = aux->prox;
    else (*lista)->inicio = aux->prox;

    ((*lista)->quantidade)--;
}

void MoveCardPraBase(struct Lista **lista,struct Deck *card) {   //Dado um card que PERTENCA ao deck, este eh movido para a base imediatamente.
    if(card == NULL) return;

    RetiraCardPorCopia(card,lista);
    card->prox = (struct Deck *)malloc(sizeof(struct Deck));
    card->prox->prox = NULL;

    ColocaListaCardsNaBaseDeck(lista,card);
}

void ColocaCardNaBaseDeck(struct Lista **lista,struct Deck *card) {
    ColocaNovoCardNoDeck(lista,card);
    MoveCardPraBase(lista,card);
}

struct Deck *RetiraCardPorNome(int nome_card,struct Lista **deck) {
    struct Deck *aux,*aux2;

    aux = (*deck)->inicio;
    //printf("Busca %d EM:\n",nome_card);

    aux2 = NULL;
    while(aux->prox != NULL) {
        //printf("%d\n",aux->card->origem->colecao);
        if(aux->card->origem->colecao == nome_card) {
            if(aux2 != NULL) aux2->prox = aux->prox;
            else (*deck)->inicio = (*deck)->inicio->prox;

            aux->prox = NULL;
            ((*deck)->quantidade)--;

            return(aux);
        }

        aux2 = aux;
        aux = aux->prox;
    }
    printf("AVISO -> sem card: %d\n",nome_card);
    //system("pause");
    return(NULL);
}

struct Deck *RetiraPrimeiroCard(struct Lista **lista) {
    struct Deck *aux;

    aux = (*lista)->inicio;
    if(aux->prox == NULL) return(NULL);

    (*lista)->inicio = aux->prox;
    ((*lista)->quantidade)--;

    return(aux);
}

struct Deck *RetiraVariosCards(struct Lista **lista, int quantidade) {
    //Retorna uma LISTA de ate N cards, podendo ser menor se a quantidade que estiver na lista for MENOR que N.

    struct Deck *conjunto,*aux,*aux2;
    int i = 0;

    conjunto = (*lista)->inicio;
    if(conjunto->prox == NULL || quantidade == 0) {
        conjunto = (struct Deck *)malloc(sizeof(struct Deck));
        conjunto->prox = NULL;

        return(conjunto);
    }

    aux = conjunto;
    while(i < quantidade && aux->prox != NULL) {
        aux2 = aux;
        aux = aux->prox;
        i++;
    }

    (*lista)->inicio = aux;
    aux2->prox = (struct Deck *)malloc(sizeof(struct Deck));
    aux2->prox->prox = NULL;

    ((*lista)->quantidade) -= i;

    return(conjunto);
}

bool TestaContadorLista(struct Lista *lista) {
    int i = 0;
    struct Deck *aux = lista->inicio;

    while(aux->prox != NULL) {
        i++;
        aux = aux->prox;
    }

    if(i != lista->quantidade) printf("ERRO TECNICO -> %d :: %d atual\n",lista->quantidade,i);

    return(i == lista->quantidade);
}

int RetornaAproximado(int valor) {
    int aux = valor / 10;
    if((valor % 10) >= 5) aux += 1;
    aux *= 10;

    return(aux);
}

int RetornaMaiorAproximado(int c1,int c2,int c3) {
    int temp = c1;
    if(c2 > temp) temp = c2;
    if(c3 > temp) temp = c3;

    return(RetornaAproximado(temp));
}

int RetornaMedioAproximado(int c1,int c2,int c3) {
    int min = c1,max = c2,temp;

    if(c2 < min) {
        max = min;
        min = c2;
    }

    if(c3 < min) {
        temp = min;
        min = c3;
    }
    else if(c3 > max) {
        temp = max;
        max = c3;
    }
    else temp = c3;

    return(RetornaAproximado(temp));
}

void InsereCardAssociado(struct CARD **card,struct Deck *novo_card) {
    CardAssociado aux;

    printf("Insere novo card associado ");
    aux = (*card)->cards_associados;
    while(aux->prox != NULL) aux = aux->prox;

    printf("2 ");
    aux->deck = novo_card;
    aux->prox = (struct card_associado *)malloc(sizeof(struct card_associado));
    aux->prox->prox = NULL;

    (*card)->qte_associado++;
    printf("OK\n");
}

struct Deck *LiberaCardAssociadoPorCopia(struct CARD *card,struct Deck *alvo) {
    //obs.: card alvo DEVE EXISTIR na lista de cards associados.
    CardAssociado aux,aux2 = NULL;
    struct Deck *retorno = NULL;

    aux = card->cards_associados;
    while(aux->deck->card != alvo->card) {
        aux2 = aux;
        aux = aux->prox;
    }
    retorno = aux->deck;

    if(aux2 != NULL) aux2->prox = aux->prox;
    else card->cards_associados = aux->prox;
    free(aux);

    card->qte_associado -= 1;
    return(retorno);
}

void LiberaEstruturaCardsAssociados(struct CARD *card) {
    //Esta funcao NAO DESFAZ dos cards ingame apropriadamente, ponteiros dos cards precisam
    //estar apontando para outras listas para nao se perderem.
    int i = 0;
    CardAssociado aux,aux2;

    printf("Libera estruturas cards associados ");
    aux = card->cards_associados;
    aux2 = NULL;
    while(aux->prox != NULL) {
        aux2 = aux;
        aux = aux->prox;
        free(aux2);
        i++;
    }
    free(aux);

    printf("9 ");
    card->cards_associados = (struct card_associado *)malloc(sizeof(struct card_associado));
    card->cards_associados->prox = NULL;
    card->qte_associado -= i;
}

#endif // ESTRUTURA_UTIL_C_INCLUDED
