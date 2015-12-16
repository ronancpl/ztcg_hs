#ifndef BASICO_C_INCLUDED
#define BASICO_C_INCLUDED

/*
NOTA:: IMPLEMENTAR TODO O JOGO COM LISTAS(DECKS) ENCADEADAS COM CABEÇA!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

    RARIDADE:
        facil ->   7 em 11
        medio ->   3 em 11
        dificil -> 1 em 11
*/

void LiberaListaColecao(struct ListaCards ***lista) {
    struct ListaCards *aux,*aux2;
    short int i;

    for(i = 0;i < 8;i++) {
        aux = (*lista)[i];

        while(aux->prox != NULL) {
            aux2 = aux;
            aux = aux->prox;
            free(aux2);
        }
        free(aux);
    }

    free(*lista);
}

void Particao(int Esq,int Dir,int *i,int *j,struct ListaCards *A) {
    struct ListaCards x, w;

    *i = Esq;
    *j = Dir;
    x = A[(*i + *j) / 2]; /* obtem o pivo x */
    do {
        while (strcmp(x.card->elemento,A[*i].card->elemento) > 0) (*i)++;
        while (strcmp(x.card->elemento,A[*j].card->elemento) < 0) (*j)--;
        if (*i <= *j) {
            w = A[*i];
            A[*i] = A[*j];
            A[*j] = w;

            (*i)++;
            (*j)--;
        }
    } while (*i <= *j);
}

void Quicksort(int Esq,int Dir,struct ListaCards *A) {
    int i,j;

    Particao(Esq, Dir, &i, &j, A);
    if (Esq < j) Quicksort(Esq, j, A);
    if (i < Dir) Quicksort(i, Dir, A);
}

void OrdenaLista(struct ListaCards ***colecao,int **total) {
    int i,j;
    struct ListaCards **sublista,*aux;

    printf("Ordena lista ");
    sublista = (struct ListaCards **)calloc(8,sizeof(struct ListaCards *));
    for(i = 0;i < 8;i++) sublista[i] = (struct ListaCards *)calloc((*total)[i],sizeof(struct ListaCards));

    for(i = 0;i < 8;i++) {
        if((*total)[i] == 0) continue;

        aux = (*colecao)[i];
        for(j = 0;j < (*total)[i];j++) {
            (sublista[i][j]).card = aux->card;        //armazena o conteudo das listas em vetores, para que possa ser feita a ordenacao.
            aux = aux->prox;                        //ordenacao feita com base no elemento do card.
        }

        Quicksort(0,(*total)[i] - 1,sublista[i]);
    }

    printf("1 ");
    LiberaListaColecao(colecao);
    printf("2 ");
    *colecao = (struct ListaCards **)malloc(8*sizeof(struct ListaCards *));
    for(i = 0;i < 8;i++) {
        j = 0;
        (*colecao)[i] = (struct ListaCards *)malloc(sizeof(struct ListaCards));
        aux = (*colecao)[i];
        aux->prox = NULL;

        while(j < (*total)[i]) {
            aux->card = sublista[i][j].card;
            aux->prox = (struct ListaCards *)malloc(sizeof(struct ListaCards));
            aux = aux->prox;
            aux->prox = NULL;

            j++;
        }
    }
    printf("3 ");

    for(i = 0;i < 8;i++) free(sublista[i]);
    printf("4 ");
    free(sublista);
    printf("OK! ");
}

void ListaCard(struct ListaCards **lista,int **total,struct Card *card) {
    short i;

    if(!strcmp(card->tipo,"Character")) i = 0;
    else if(!strcmp(card->tipo,"Monster")) i = 1;
    else if(!strcmp(card->tipo,"Equipment")) i = 2;
    else if(!strcmp(card->tipo,"Tactic")) i = 3;
    else if(!strcmp(card->tipo,"NPC Monster")) i = 4;  //obsoleto?
    else if(!strcmp(card->tipo,"Field")) i = 5;
    else if(!strcmp(card->tipo,"Jr. Boss")) i = 6;
    else i = 7;

    (*total)[i]++;

    (lista[i])->card = card;
    (lista[i])->prox = (struct ListaCards *)malloc(sizeof(struct ListaCards));
    (lista[i]) = (lista[i])->prox;
}

void ListaColecao(struct ListaCards ***lista,struct COLECAO *colecao,int **total) {
    struct ListaCards **aux;
    short i = 0;

    //0 -> Character
    //1 -> Monster
    //2 -> Equip
    //3 -> Tactic
    //4 -> NPC
    //5 -> Field
    //6 -> Jrboss
    //7 -> Boss

    *lista = (struct ListaCards **)malloc(8*sizeof(struct ListaCards *));
    *total = (int *)malloc(8*sizeof(int));

    aux = (struct ListaCards **)malloc(8*sizeof(struct ListaCards *));

    for(i = 0; i < 8; i++) {
        (*lista)[i] = (struct ListaCards *)malloc(sizeof(struct ListaCards));
        (*total)[i] = 0;
        aux[i] = (*lista)[i];
    }

    ListaCard(aux,total,colecao->link);
    ListaCard(aux,total,colecao->great_dekus_bless);
    ListaCard(aux,total,colecao->gohma);
    ListaCard(aux,total,colecao->goron_tunic);
    ListaCard(aux,total,colecao->dark_link);
    ListaCard(aux,total,colecao->desert_colossus);
    ListaCard(aux,total,colecao->likelike);
    ListaCard(aux,total,colecao->impa);
    ListaCard(aux,total,colecao->twinrova);
    ListaCard(aux,total,colecao->pierre);
    ListaCard(aux,total,colecao->blue_potion);
    ListaCard(aux,total,colecao->flare_dancer);
    printf("1 ");
    ListaCard(aux,total,colecao->adult_wallet);
    ListaCard(aux,total,colecao->goron_bracelet);
    ListaCard(aux,total,colecao->kokiri_forest);
    ListaCard(aux,total,colecao->golden_scale);
    ListaCard(aux,total,colecao->master_sword);
    ListaCard(aux,total,colecao->gerudo_guard);
    ListaCard(aux,total,colecao->bombchu);
    ListaCard(aux,total,colecao->princess_zelda);
    ListaCard(aux,total,colecao->lizalfos);
    ListaCard(aux,total,colecao->hookshot);
    ListaCard(aux,total,colecao->young_link);
    ListaCard(aux,total,colecao->ganon);
    ListaCard(aux,total,colecao->spirit_medallion);
    ListaCard(aux,total,colecao->goron_ruby);
    printf("2 ");
    ListaCard(aux,total,colecao->bongobongo);
    ListaCard(aux,total,colecao->guay);
    ListaCard(aux,total,colecao->moblin);
    ListaCard(aux,total,colecao->bazaar_seller);
    ListaCard(aux,total,colecao->king_zora);
    ListaCard(aux,total,colecao->nabooru);
    ListaCard(aux,total,colecao->anubis);
    ListaCard(aux,total,colecao->dead_hand);
    ListaCard(aux,total,colecao->death_mt_crater);
    ListaCard(aux,total,colecao->hyrule_castle);
    ListaCard(aux,total,colecao->lake_hylia);
    ListaCard(aux,total,colecao->rauru);
    ListaCard(aux,total,colecao->phantom_ganon);
    ListaCard(aux,total,colecao->bigocto);
    ListaCard(aux,total,colecao->tailpasaran);
    ListaCard(aux,total,colecao->gerudo_fortress);
    ListaCard(aux,total,colecao->cursed_villager);
    ListaCard(aux,total,colecao->poe_sisters);
    printf("3 ");
    ListaCard(aux,total,colecao->hylian_shield);
    ListaCard(aux,total,colecao->deku_seeds_bag);
    ListaCard(aux,total,colecao->bless_of_triforce);
    ListaCard(aux,total,colecao->skulltulas_ambush);
    ListaCard(aux,total,colecao->heart_piece);
    ListaCard(aux,total,colecao->milk_bottle);
    ListaCard(aux,total,colecao->stinger);
    ListaCard(aux,total,colecao->zoras_sapphire);
    ListaCard(aux,total,colecao->peahat);
    ListaCard(aux,total,colecao->gold_skulltula);
    ListaCard(aux,total,colecao->larva_gohma);
    ListaCard(aux,total,colecao->magic_beans);
    ListaCard(aux,total,colecao->small_key);
    ListaCard(aux,total,colecao->great_deku_trees_knowledge);
    ListaCard(aux,total,colecao->bomb_rain);
    ListaCard(aux,total,colecao->kakariko_graveyard);
    printf("4 ");
    ListaCard(aux,total,colecao->mido);
    ListaCard(aux,total,colecao->cucco_lady);
    ListaCard(aux,total,colecao->fairys_aid);
    ListaCard(aux,total,colecao->triple_shot);
    ListaCard(aux,total,colecao->deku_nut);
    ListaCard(aux,total,colecao->dark_pathway);
    ListaCard(aux,total,colecao->magic_jar);
    ListaCard(aux,total,colecao->give_away);
    ListaCard(aux,total,colecao->ice_arrow);
    ListaCard(aux,total,colecao->play_ocarina);
    ListaCard(aux,total,colecao->open_chest);
    ListaCard(aux,total,colecao->crystal_switch);
    ListaCard(aux,total,colecao->raze);
    ListaCard(aux,total,colecao->dins_fire);
    ListaCard(aux,total,colecao->mountain_climbing);
    ListaCard(aux,total,colecao->horse_riding);
    ListaCard(aux,total,colecao->_1_ton_rock_lifting);
    ListaCard(aux,total,colecao->octorok);
    ListaCard(aux,total,colecao->joelle);
    ListaCard(aux,total,colecao->torch_slug);
    ListaCard(aux,total,colecao->spike);
    ListaCard(aux,total,colecao->bomb_bag);
    ListaCard(aux,total,colecao->fairy_slingshot);
    printf("5 ");
    ListaCard(aux,total,colecao->compass);
    ListaCard(aux,total,colecao->guillotine);
    ListaCard(aux,total,colecao->skullwalltula);
    ListaCard(aux,total,colecao->baby_dodongo);
    ListaCard(aux,total,colecao->fabulous_five_froggish_tenors);
    ListaCard(aux,total,colecao->leever);
    ListaCard(aux,total,colecao->red_tektite);
    ListaCard(aux,total,colecao->blue_tektite);
    ListaCard(aux,total,colecao->granny);
    ListaCard(aux,total,colecao->wolfos);
    ListaCard(aux,total,colecao->shabom);
    ListaCard(aux,total,colecao->silver_gauntlets);
    ListaCard(aux,total,colecao->worlds_finest_eye_drops);
    ListaCard(aux,total,colecao->ocarina_of_time);
    ListaCard(aux,total,colecao->gossip_stone);
    ListaCard(aux,total,colecao->ganons_castle);
    ListaCard(aux,total,colecao->dungeon_map);
    ListaCard(aux,total,colecao->gerudos_membership_card);
    ListaCard(aux,total,colecao->shadow_merge);
    ListaCard(aux,total,colecao->golden_gauntlets);
    ListaCard(aux,total,colecao->mask_of_truth);
    ListaCard(aux,total,colecao->warp);
    ListaCard(aux,total,colecao->giant_leever);
    ListaCard(aux,total,colecao->big_poe);
    printf("6 ");
    ListaCard(aux,total,colecao->skull_mask);
    ListaCard(aux,total,colecao->ganondorf);
    ListaCard(aux,total,colecao->chest);
    ListaCard(aux,total,colecao->skull_kid);
    ListaCard(aux,total,colecao->princess_ruto);
    ListaCard(aux,total,colecao->light_medallion);
    ListaCard(aux,total,colecao->fire_arrow);
    ListaCard(aux,total,colecao->jump_quest_water);
    ListaCard(aux,total,colecao->iron_boots);
    ListaCard(aux,total,colecao->mirror_shield);
    ListaCard(aux,total,colecao->white_wolfos);
    ListaCard(aux,total,colecao->whirling_scythes);
    ListaCard(aux,total,colecao->darunia);
    ListaCard(aux,total,colecao->sunset);
    ListaCard(aux,total,colecao->channeled_strike);
    ListaCard(aux,total,colecao->purple_rupee);
    ListaCard(aux,total,colecao->redead);
    ListaCard(aux,total,colecao->beamos);
    ListaCard(aux,total,colecao->iron_knuckles);
    ListaCard(aux,total,colecao->dodongo);
    ListaCard(aux,total,colecao->freezard);
    ListaCard(aux,total,colecao->business_scrub);
    ListaCard(aux,total,colecao->jump_quest_wind);
    ListaCard(aux,total,colecao->underground_shelter);
    ListaCard(aux,total,colecao->hover_boots);
    ListaCard(aux,total,colecao->epona);
    ListaCard(aux,total,colecao->claim_check);
    ListaCard(aux,total,colecao->purple_poe_remnant);
    ListaCard(aux,total,colecao->green_poe_remnant);
    ListaCard(aux,total,colecao->fire_temple);
    ListaCard(aux,total,colecao->bigger_bomb_bag);
    ListaCard(aux,total,colecao->bomb);
    ListaCard(aux,total,colecao->malon);
    ListaCard(aux,total,colecao->boomerang);
    ListaCard(aux,total,colecao->tricky_shot);
    ListaCard(aux,total,colecao->kokiri_tunic);
    ListaCard(aux,total,colecao->stalfos);
    ListaCard(aux,total,colecao->big_deku_baba);
    ListaCard(aux,total,colecao->fairy_fountain);
    ListaCard(aux,total,colecao->mystic_spell);
    ListaCard(aux,total,colecao->great_fairys_bless);
    ListaCard(aux,total,colecao->keese);

    for(i = 0;i < 8;i++) (aux[i])->prox = NULL;

    printf("7 ");

    free(aux);
    printf("8 ");
    OrdenaLista(lista,total);
    printf("OK! ");
}

void EmbaralhaDeck(struct Deck *deck,int quantidade) {   //algoritmo de embaralhamento: Fisher-Yates.
    struct Deck *aux;
    struct CARD **vetor,*temp;
    int i,j;

    vetor = (struct CARD **)malloc(quantidade*sizeof(struct CARD *));
    aux = deck;
    for(i = 0;i < quantidade;i++) {
        vetor[i] = aux->card;
        aux = aux->prox;
    }

    for (i = quantidade - 1; i >= 1; i--) {
        j = rand() % (i + 1);

        temp = vetor[i];
        vetor[i] = vetor[j];
        vetor[j] = temp;
    }

    aux = deck;
    for(i = 0;i < quantidade;i++) {
        aux->card = vetor[i];
        aux = aux->prox;
    }

    free(vetor);
}

bool AtingeCards(struct Player *jogador,struct Player *adversario,struct CARD *card,int modo,int origem_ataque,int elemento_ataque) {
    //CARD NO CASO EH O QUE VAI SER ALVEJADO!
    /*
        ORIGEM:
        0-> Monster
        1-> Char. Actions
        2-> Tactic
        3-> Equip(?)
    */

    /*
        MODO (o que vai ser atingido):
        0-> Character
        1-> Monster (comum,jrboss,boss,NPC)

    */

    if(modo == 0) { //INCLUI FUNCOES de cards QUE POSSAM SALVAR O CHARACTER!
        if(adversario->turn_away > 0) return(false);
        else if(adversario->var_tactic->horse_riding_turn_cont > 0 && origem_ataque == 0) return(false);
    }

    else if(modo == 1) {    //SALVAM MONSTROS.
        if((card->origem->colecao == FLARE_DANCER || card->origem->colecao == GUAY || card->origem->colecao == BIGOCTO || card->origem->colecao == OCTOROK || card->origem->colecao == SKULLWALLTULA || card->origem->colecao == BIG_POE || card->origem->colecao == KEESE) && card->turn_silenced == 0 && origem_ataque == 0) return(false);
        else if((card->origem->colecao == MOBLIN || (card->origem->colecao == LARVA_GOHMA) || card->origem->colecao == SHABOM) && card->turn_silenced == 0 && origem_ataque == 1) return(false);
        else if(origem_ataque == 1 && ((adversario->mesa->monstro1 != NULL && adversario->mesa->monstro1->origem->colecao == BONGOBONGO && adversario->mesa->monstro1->turn_silenced == 0) || (adversario->mesa->monstro2 != NULL && adversario->mesa->monstro2->origem->colecao == BONGOBONGO && adversario->mesa->monstro2->turn_silenced == 0) || (adversario->mesa->monstro3 != NULL && adversario->mesa->monstro3->origem->colecao == BONGOBONGO && adversario->mesa->monstro3->turn_silenced == 0) || (adversario->mesa->monstro4 != NULL && adversario->mesa->monstro4->origem->colecao == BONGOBONGO && adversario->mesa->monstro4->turn_silenced == 0) || (adversario->mesa->monstro5 != NULL && adversario->mesa->monstro5->origem->colecao == BONGOBONGO && adversario->mesa->monstro5->turn_silenced == 0) || (adversario->mesa->monstro6 != NULL && adversario->mesa->monstro6->origem->colecao == BONGOBONGO && adversario->mesa->monstro6->turn_silenced == 0) || (adversario->mesa->monstro7 != NULL && adversario->mesa->monstro7->origem->colecao == BONGOBONGO && adversario->mesa->monstro7->turn_silenced == 0))) return(false);
        else if((card->origem->colecao == ANUBIS) && card->turn_silenced == 0 && elemento_ataque != 2) return(false);
        else if(card->var_monster->baby_dodongo_bool == true && card->turn_silenced == 0) return(false);

    }

    return(true);
}

void TextoNaLista(int *indice,char **lista_texto,char *texto,ALLEGRO_FONT *font) {  //o indice sera compartilhado!
    bool final = false;
    int cont = 0,larg,i;
    char *temp,str[30];   //56...

    if(texto == NULL) return;
    temp = (char *)calloc(56,sizeof(char));

    while(final == false) {
        larg = 0;
        temp[0] = 0;

        while(1) {
            i = 0;
            if(texto[cont] == ' ') cont++;

            do {
                str[i] = texto[cont];
                i++; cont++;
            } while(str[i-1] != ' ' && str[i-1] != '\0');
            str[i] = 0;

            larg = larg + al_get_text_width(font,str);
            if(larg >= 220) {
                cont = cont - strlen(str) - 1;
                break;
            }

            temp = strcat(temp,str);
            if(str[i-1] == 0) {
                final = true;
                break;
            }
        }

        //guarda string da temp na lista de textos.
        lista_texto[*indice] = (char *)calloc(strlen(temp) + 1,sizeof(char));
        lista_texto[*indice] = strcpy(lista_texto[*indice],temp);
        (*indice)++;
    }

    lista_texto[*indice] = (char *)calloc(1,sizeof(char));  //saltar um espaco entre definicoes do card.
    lista_texto[*indice][0] = 0;
    (*indice)++;

    free(temp);
}

void EscreveTextoCard(struct Card *card,ALLEGRO_FONT *font) {
    int indice = 0;
    Acao aux;

    card->lista_texto = (char **)calloc(50,sizeof(char *));
    TextoNaLista(&indice,card->lista_texto,card->nome,font);
    TextoNaLista(&indice,card->lista_texto,card->str_concat,font);

    if(card->character != NULL) {
        aux = card->character->inicio;

        while(aux->prox != NULL) {
            TextoNaLista(&indice,card->lista_texto,aux->acao,font);
            aux = aux->prox;
        }
    }

    else if(card->boss != NULL) {
        aux = card->boss->acao;

        while(aux->prox != NULL) {
            TextoNaLista(&indice,card->lista_texto,aux->acao,font);
            aux = aux->prox;
        }
    }

    else if(card->monster != NULL) {
        TextoNaLista(&indice,card->lista_texto,card->monster->acao,font);
    }

    else if(card->equip != NULL) {
        TextoNaLista(&indice,card->lista_texto,card->equip->acao,font);
    }

    else if(card->field != NULL) {
        TextoNaLista(&indice,card->lista_texto,card->field->acao,font);
    }

    else if(card->tactic != NULL) {
        TextoNaLista(&indice,card->lista_texto,card->tactic->acao,font);
    }

    else if(card->jrboss != NULL) {
        aux = card->jrboss->acao;

        while(aux->prox != NULL) {
            TextoNaLista(&indice,card->lista_texto,aux->acao,font);
            aux = aux->prox;
        }
    }

    if(card->character == NULL) TextoNaLista(&indice,card->lista_texto,card->lv_acao->acao,font);
    card->indice_texto = indice;
}

void TextBox(ALLEGRO_FONT *font,ALLEGRO_COLOR color,struct Card *card,int rolagem) {
    int i;

    if(card == NULL) return;
    for(i = 0; i < 12; i++) {
        al_draw_textf(font,color,5,365 + 20*i,0,"%s",card->lista_texto[rolagem + i]);
    }
}

//card_tbox eh o card a ser definido. Esta funcao ocorre a cada LOOP com um INTEIRO definido para ROLL_TBOX E definicoes do mouse!
//UTILIZAR FONTE 8 com esta funcao!
void BarraRolagem(int *roll_tbox,int *mouseX,int *mouseY,int *dltZ,bool *mouse,struct Card *card_tbox,ALLEGRO_BITMAP *roll_bar,ALLEGRO_FONT *font,ALLEGRO_COLOR color) {
    float altura_bloco;
    int max_tbox;

    if(card_tbox == NULL) max_tbox = 0;
    else {
        max_tbox = card_tbox->indice_texto;
        al_draw_bitmap(card_tbox->bmp,0,0,0);
    }

    if(*roll_tbox > 0 && ((*mouseX >= 220 && *mouseX < 240 && *mouseY >= 360 && *mouseY < 380 && *mouse == true) || *dltZ > 0)) (*roll_tbox)--;
    else if(*roll_tbox < max_tbox - 12 && ((*mouseX >= 220 && *mouseX < 240 && *mouseY >= 580 && *mouseY < 600 && *mouse == true) || *dltZ < 0)) (*roll_tbox)++;
    //al_rest(0.05);

    if(max_tbox < 12) al_draw_scaled_bitmap(roll_bar,0,0,20,200,220,380,20,200,0);
    else {
        altura_bloco = 200.0 / max_tbox;
        al_draw_scaled_bitmap(roll_bar,0,0,20,200,220,380 + (*roll_tbox)*altura_bloco,20,12*altura_bloco,0); //12 capacidade maxima do DISPLAY
    }

    TextBox(font,color,card_tbox,*roll_tbox);
}

void DesenhaContador(int valor,int max,bool cor,struct StatusBox_bitmaps *sbox,int refX,int refY) {
    //COR: 0 -> Vermelho; 1 -> Azul
    int HPcontainer, i, cont = 0;

    if(max != -1) {
        if(max % 40 != 0) max += (40 - (max % 40));
        HPcontainer = (max - valor) / 40;

        for(i = 0;i < HPcontainer;i++) {
            al_draw_bitmap(sbox->hp0, 45 + 10*(cont + i) + refX, 135 + refY, 0);
        }
        cont += HPcontainer;

        HPcontainer = valor / 40;
        for(i = 0;i < HPcontainer;i++) {
            al_draw_bitmap(sbox->hp4, 45 + 10*(cont + i) + refX, 135 + refY, 0);
        }
        cont += HPcontainer;

        HPcontainer = valor % 40;
        switch(HPcontainer) {
            case 10:
                al_draw_bitmap(sbox->hp1, 45 + 10*cont + refX, 135 + refY, 0);
                break;

            case 20:
                al_draw_bitmap(sbox->hp2, 45 + 10*cont + refX, 135 + refY, 0);
                break;

            case 30:
                al_draw_bitmap(sbox->hp3, 45 + 10*cont + refX, 135 + refY, 0);
                break;
        }
    }
    else {
        HPcontainer = valor / 40;
        cont = valor % 40;

        if(cor == false) {
            for(i = 0;i < HPcontainer; i++)
                al_draw_bitmap(sbox->hp4, 45 + 10*i + refX, 210 + refY, 0);

            if(cont == 10) al_draw_bitmap(sbox->hp1, 45 + 10*i + refX, 210 + refY, 0);
            else if(cont == 20) al_draw_bitmap(sbox->hp2, 45 + 10*i + refX, 210 + refY, 0);
            else if(cont == 30) al_draw_bitmap(sbox->hp3, 45 + 10*i + refX, 210 + refY, 0);
        }
        else {
            for(i = 0;i < HPcontainer; i++)
                al_draw_bitmap(sbox->dmg4, 45 + 10*i + refX, 170 + refY, 0);

            if(cont == 10) al_draw_bitmap(sbox->dmg1, 45 + 10*i + refX, 170 + refY, 0);
            else if(cont == 20) al_draw_bitmap(sbox->dmg2, 45 + 10*i + refX, 170 + refY, 0);
            else if(cont == 30) al_draw_bitmap(sbox->dmg3, 45 + 10*i + refX, 170 + refY, 0);
        }
    }
}

bool AlvoEmCampo(struct CARD *card,struct Player *adversario) {
    if(adversario->mesa->character->PosicaoX == card->PosicaoX && adversario->mesa->character->PosicaoY == card->PosicaoY && adversario->var_tactic->horse_riding_turn_cont == 0) return(true);
    if(adversario->mesa->monstro1 != NULL && adversario->mesa->monstro1->PosicaoX == card->PosicaoX && adversario->mesa->monstro1->PosicaoY == card->PosicaoY) return(true);
    if(adversario->mesa->monstro2 != NULL && adversario->mesa->monstro2->PosicaoX == card->PosicaoX && adversario->mesa->monstro2->PosicaoY == card->PosicaoY) return(true);
    if(adversario->mesa->monstro3 != NULL && adversario->mesa->monstro3->PosicaoX == card->PosicaoX && adversario->mesa->monstro3->PosicaoY == card->PosicaoY) return(true);
    if(adversario->mesa->monstro4 != NULL && adversario->mesa->monstro4->PosicaoX == card->PosicaoX && adversario->mesa->monstro4->PosicaoY == card->PosicaoY) return(true);
    if(adversario->mesa->monstro5 != NULL && adversario->mesa->monstro5->PosicaoX == card->PosicaoX && adversario->mesa->monstro5->PosicaoY == card->PosicaoY) return(true);
    if(adversario->mesa->monstro6 != NULL && adversario->mesa->monstro6->PosicaoX == card->PosicaoX && adversario->mesa->monstro6->PosicaoY == card->PosicaoY) return(true);
    if(adversario->mesa->monstro7 != NULL && adversario->mesa->monstro7->PosicaoX == card->PosicaoX && adversario->mesa->monstro7->PosicaoY == card->PosicaoY) return(true);

    return(false);
}

bool DHneutralizado(struct Player *adversario) {
    if(adversario->mesa->monstro1 != NULL && adversario->mesa->monstro1->origem->colecao == DEAD_HAND && adversario->mesa->monstro1->turn_silenced > 0) return(true);
    if(adversario->mesa->monstro2 != NULL && adversario->mesa->monstro2->origem->colecao == DEAD_HAND && adversario->mesa->monstro2->turn_silenced > 0) return(true);
    if(adversario->mesa->monstro3 != NULL && adversario->mesa->monstro3->origem->colecao == DEAD_HAND && adversario->mesa->monstro3->turn_silenced > 0) return(true);
    if(adversario->mesa->monstro4 != NULL && adversario->mesa->monstro4->origem->colecao == DEAD_HAND && adversario->mesa->monstro4->turn_silenced > 0) return(true);
    if(adversario->mesa->monstro5 != NULL && adversario->mesa->monstro5->origem->colecao == DEAD_HAND && adversario->mesa->monstro5->turn_silenced > 0) return(true);
    if(adversario->mesa->monstro6 != NULL && adversario->mesa->monstro6->origem->colecao == DEAD_HAND && adversario->mesa->monstro6->turn_silenced > 0) return(true);
    if(adversario->mesa->monstro7 != NULL && adversario->mesa->monstro7->origem->colecao == DEAD_HAND && adversario->mesa->monstro7->turn_silenced > 0) return(true);

    return(false);
}

void StatusBox(bool tipo_card,bool orientacao,struct Coordenadas *lista,struct CARD *card,struct StatusBox_bitmaps *sbox,int posX,int posY,struct Player *jogador,struct Player *adversario,ALLEGRO_FONT *font,ALLEGRO_FONT *font2,ALLEGRO_COLOR color,int ataque_gerado,int defesa_gerada) {
    struct Coordenadas *aux;    //TIPO_CARD: 0 -> Monstro; 1 -> Character
    int refX,refY;
    bool alvo = false;

    if(posX + 350 < 800) refX = posX;   //Busca referencias de forma que StatusBox nao ultrapasse os limites do display.
    else refX = posX - 350;

    if(posY + 250 < 600) refY = posY;
    else refY = posY - 250;

    al_draw_bitmap(sbox->container_bg, refX, refY, 0);

    if(tipo_card == true) {
        al_draw_textf(font,color, 5 + refX, 5 + refY, 0,"%s", jogador->nome_prof);
        al_draw_textf(font,color, 5 + refX,25 + refY, 0,"LVL: %d    EXP: %d / 0", jogador->level_prof, jogador->exp_prof);

        al_draw_scaled_bitmap(sbox->earth_icon, 0, 0, 48, 48, 210 + refX, 5 + refY, 20, 20, 0);
        al_draw_textf(font,color, 235 + refX, 10 + refY, 0,"%d", jogador->earth_ic);

        al_draw_scaled_bitmap(sbox->wind_icon, 0, 0, 48, 48, 210 + refX, 35 + refY, 20, 20, 0);
        al_draw_textf(font,color, 235 + refX, 40 + refY, 0,"%d", jogador->wind_ic);

        al_draw_scaled_bitmap(sbox->light_icon, 0, 0, 48, 48, 255 + refX, 5 + refY, 20, 20, 0);
        al_draw_textf(font,color, 280 + refX, 10 + refY, 0,"%d", jogador->light_ic);

        al_draw_scaled_bitmap(sbox->dark_icon, 0, 0, 48, 48, 255 + refX, 35 + refY, 20, 20, 0);
        al_draw_textf(font,color, 280 + refX, 40 + refY, 0,"%d", jogador->dark_ic);

        al_draw_scaled_bitmap(sbox->fire_icon, 0, 0, 48, 48, 300 + refX, 5 + refY, 20, 20, 0);
        al_draw_textf(font,color, 325 + refX, 10 + refY, 0,"%d", jogador->fire_ic);

        al_draw_scaled_bitmap(sbox->water_icon, 0, 0, 48, 48, 300 + refX, 35 + refY, 20, 20, 0);
        al_draw_textf(font,color, 325 + refX, 40 + refY, 0,"%d", jogador->water_ic);
    }

    al_draw_textf(font,color, 10 + refX, 70 + refY, 0,"%s", card->origem->tipo);
    al_draw_textf(font,color, 10 + refX, 90 + refY, 0,"%s", card->origem->nome);

    if((jogador->mesa->field != NULL && !strcmp(card->origem->elemento,jogador->mesa->field->origem->elemento)) || (jogador->mesa->field == NULL && adversario->mesa->field != NULL && !strcmp(card->origem->elemento,adversario->mesa->field->origem->elemento))) {
        al_draw_bitmap(sbox->map_icon, 265 + refX, 55 + refY, 0);
        if(tipo_card == true) {
            if(card == jogador->mesa->character) al_draw_textf(font,color, 315 + refX, 70 + refY, 0,"%d", jogador->field_cont);
            else if(card == adversario->mesa->character) al_draw_textf(font,color, 315 + refX, 70 + refY, 0,"%d", adversario->field_cont);
        }
    }

    //--- stuns -----------

    if(card->turn_cooldown > 0) {
        al_draw_bitmap(sbox->stun_icon, 265 + refX, 125 + refY, 0);
        al_draw_textf(font2,color, 310 + refX, 140 + refY, 0,"%d", card->turn_cooldown);
    }

    if(card->var_monster != NULL && card->var_monster->dead_hand_bool == true && !DHneutralizado(adversario)) al_draw_bitmap(sbox->stun_icon, 265 + refX, 125 + refY, 0);

    //---------------------

    if(orientacao == false) {
        if(lista != NULL) {
            aux = lista;
            while(aux->prox != NULL) {
                if(aux->x == card->PosicaoX && aux->y == card->PosicaoY) {
                    alvo = true;
                    break;
                }

                aux = aux->prox;
            }

            if(aux->prox == NULL && ataque_gerado >= 0 && AlvoEmCampo(card,jogador)) al_draw_bitmap(sbox->prevent_icon, 265 + refX, 165 + refY, 0);
        }
        if(tipo_card == true) {
            if(jogador->turn_away > 0) {
                al_draw_bitmap(sbox->warp_icon, 265 + refX, 165 + refY, 0);
                al_draw_textf(font2,color, 310 + refX, 180 + refY, 0,"%d", jogador->turn_away);
            }
            else if(alvo == true) {
                if(jogador->prevent_damage > 0) {
                    al_draw_bitmap(sbox->prevent_icon, 265 + refX, 165 + refY, 0);
                    al_draw_textf(font2,color, 310 + refX, 180 + refY, 0,"%d", jogador->prevent_damage);
                }
                else if(jogador->prevent_any_damage > 0) {
                    al_draw_bitmap(sbox->prevent_icon, 265 + refX, 165 + refY, 0);
                    al_draw_textf(font2,color, 310 + refX, 180 + refY, 0,"%d", jogador->prevent_any_damage);
                }
            }
        }
        else if(alvo == true && jogador->prevent_any_damage > 0) {
            al_draw_bitmap(sbox->prevent_icon, 265 + refX, 165 + refY, 0);
            al_draw_textf(font2,color, 310 + refX, 180 + refY, 0,"%d", jogador->prevent_any_damage);
        }
    }
    else if(tipo_card == true && jogador->turn_away > 0) {
        al_draw_bitmap(sbox->warp_icon, 265 + refX, 165 + refY, 0);
        al_draw_textf(font2,color, 310 + refX, 180 + refY, 0,"%d", jogador->turn_away);
    }


    //------ DOT & Silence Effect ---------
    if(card->dot_list->prox != NULL) {
        al_draw_bitmap(sbox->dot_icon, 265 + refX, 205 + refY, 0);
        if(card->turn_silenced > 0) al_draw_bitmap(sbox->silence_icon, 308 + refX, 205 + refY, 0);
    }
    else if(card->turn_silenced > 0) al_draw_bitmap(sbox->silence_icon, 265 + refX, 205 + refY, 0);
    //----------------------------------------

    al_draw_bitmap(sbox->defense_icon, 5 + refX, 205 + refY, 0);
    if(defesa_gerada != -1) DesenhaContador(defesa_gerada,-1,false,sbox,refX,refY);

    al_draw_bitmap(sbox->offense_icon, 5 + refX, 165 + refY, 0);
    if(ataque_gerado != -1 && alvo == true) DesenhaContador(ataque_gerado,-1,true,sbox,refX,refY);

    al_draw_bitmap(sbox->HPpool_icon, 5 + refX, 125 + refY, 0);
    DesenhaContador(card->HP,card->MaxHP,true,sbox,refX,refY);
}

void VerificaEventos(bool *sair,int *posX,int *posY,int *deltaZ,bool *mouseEsq,bool *mouseDir,bool *mouse_lado,int *pressionado,bool *repete_pressionado,ALLEGRO_EVENT_QUEUE *event_queue,ALLEGRO_TIMER *keyb_press_timer,ALLEGRO_TIMER *mouse_press_timer) {
    ALLEGRO_EVENT ev;
    al_wait_for_event_timed(event_queue, &ev,0.05);

    *deltaZ = 0;
    if(ev.type == ALLEGRO_EVENT_MOUSE_AXES) {
        *posX = ev.mouse.x;
        *posY = ev.mouse.y;
        *deltaZ = ev.mouse.dz;
    }

    *repete_pressionado = false;
    *mouseEsq = false;
    *mouseDir = false;

    if(ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE) *sair = true;
    else if(ev.type == ALLEGRO_EVENT_MOUSE_BUTTON_UP) {
        al_stop_timer(mouse_press_timer);
        al_set_timer_count(mouse_press_timer,0);
    }
    else if(ev.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN) {
        if(ev.mouse.button == 1) {
            *mouse_lado = false;
            *mouseEsq = true;
        }
        else if(ev.mouse.button == 2) {
            *mouse_lado = true;
            *mouseDir = true;
        }

        al_start_timer(mouse_press_timer);
    }
    else if(ev.type == ALLEGRO_EVENT_KEY_UP) {
        al_stop_timer(keyb_press_timer);
        al_set_timer_count(keyb_press_timer,0);
    }
    else if(ev.type == ALLEGRO_EVENT_KEY_DOWN) {
        *pressionado = ev.keyboard.keycode; //precisara ser tratado dps de alguma forma...

        if(!al_get_timer_started(keyb_press_timer)) {
            *repete_pressionado = true;

            al_start_timer(keyb_press_timer);
        }
    }

    if(al_get_timer_count(mouse_press_timer) > 1000 * MOUSE_AUTOREP_SEG) {
        if(*mouse_lado == false) *mouseEsq = true;
        else *mouseDir = true;
    }
    else if(al_get_timer_count(keyb_press_timer) > 1000 * KEYB_AUTOREP_SEG) {
        *repete_pressionado = true;
    }
}

bool promptSair(bool *fim_de_jogo,ALLEGRO_BITMAP *prompt,ALLEGRO_COLOR color,ALLEGRO_DISPLAY *display,struct Player *jogador,bool *sair,int *posX,int *posY,int *deltaZ,bool *mouse,bool *mouse2,bool *mouse_lado,int *keychar,bool *repete_keychar,ALLEGRO_EVENT_QUEUE *event_queue,ALLEGRO_TIMER *keyb_press_timer,ALLEGRO_TIMER *mouse_press_timer) {
    ALLEGRO_FONT *texto;
    ALLEGRO_BITMAP *temp;

    temp = al_clone_bitmap(al_get_backbuffer(display));
    texto = al_load_ttf_font("data/triforce.ttf",20,0);

    al_clear_to_color(al_map_rgb_f(0, 0, 0));
    al_draw_tinted_bitmap(temp, al_map_rgba_f(0.3, 0.3, 0.3, 0.3),0, 0, 0);

    al_draw_bitmap(prompt,140,225,0);
    al_draw_text(texto,color,155,235,0,"QUIT current game? EXP gained will be computed as well,");
    al_draw_text(texto,color,155,265,0,"part of it will be deducted from quitting though.");

    al_draw_text(texto,color,245,315,0,"Yes");
    al_draw_text(texto,color,515,315,0,"No");

    while(1) {
        al_flip_display();
        VerificaEventos(sair,posX,posY,deltaZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);

        if(*mouse == true && *posX >= 155 && *posX < 365 && *posY >= 300 && *posY < 345) {
            printf("'%s' DESISTIU DO JOGO!\n",jogador->nome_prof);
            *fim_de_jogo = true;     //Jogador atual desiste.
            *(jogador->HP) = 0;
            //al_rest(0.2);

            al_destroy_font(texto);
            al_draw_bitmap(temp,0,0,0);
            al_destroy_bitmap(temp);
            return(true);
        }

        else if (*mouse == true && *posX >= 425 && *posX < 635 && *posY >= 300 && *posY < 345) {
            //al_rest(0.2);

            al_destroy_font(texto);
            al_draw_bitmap(temp,0,0,0);
            al_destroy_bitmap(temp);
            return(false);
        }
    }
}

struct Deck *MenuCards(char *msg,bool permite_olhar,struct Deck *menu,bool *fim_de_jogo,struct Player *jogador,ALLEGRO_DISPLAY *display,ALLEGRO_BITMAP *prompt,ALLEGRO_BITMAP *selecao,ALLEGRO_BITMAP *roll_bar,ALLEGRO_BITMAP *fundo_card,ALLEGRO_BITMAP *fundo_menu,ALLEGRO_BITMAP *fundo,ALLEGRO_FONT *font,ALLEGRO_FONT *font2,ALLEGRO_COLOR color,bool *sair,int *posX,int *posY,int *dltZ,bool *mouse,bool *mouse2,bool *mouse_lado,int *keychar,bool *repete_keychar,ALLEGRO_EVENT_QUEUE *event_queue,ALLEGRO_TIMER *keyb_press_timer,ALLEGRO_TIMER *mouse_press_timer) {
    int i = 0,pagina = 1,j,cont;
    int valor,rolagem = 0;
    struct Deck **vetor, *imgCard = NULL;
    struct Deck *aux, *retorna_card;
    struct Card *buffer = NULL;
    int nome = -1;
    ALLEGRO_BITMAP *temp;

    //al_rest(0.1);
    if(menu->prox == NULL) {
        printf("RETORNA CARD NULO!\n");
        return(NULL);
    }

    aux = menu;
    while(aux->prox != NULL) {
        aux = aux->prox;
        i++;
    }
    printf("MENU contem %d cards\n", i);

    vetor = (struct Deck **)calloc(i,sizeof(struct Deck *));
    i = 0;

    aux = menu;
    while(aux->prox != NULL) {
        vetor[i] = aux;
        aux = aux->prox;
        i++;
    }

    if(i % 12 > 0) valor = 1;
    else valor = 0;

    temp = al_clone_bitmap(al_get_backbuffer(display));
    while(*sair == false) {
        al_clear_to_color(al_map_rgb_f(0, 0, 0));
        al_draw_tinted_bitmap(temp, al_map_rgba_f(0.3, 0.3, 0.3, 0.3),0, 0, 0);
        al_draw_bitmap_region(fundo,0,0,240,600,0,0,0);

        if(msg != NULL) {
            al_draw_scaled_bitmap(selecao,0,0,240,360,240,550,455,25,0);
            al_draw_text(font,color,250,550,0,msg);
        }

        al_draw_bitmap(fundo_menu,240,70,0);
        al_draw_textf(font2,color,725,205,0,"%d / %d",pagina,i/12 + valor);

        cont = 0;
        for(j = 12*(pagina-1);j < 12*pagina;j++) {
            if(j == i) break;
            if(permite_olhar == true) al_draw_scaled_bitmap(vetor[j]->card->origem->bmp,0,0,240,360,240 + 125*(cont % 4),70 + 160*(cont / 4),100,150,0);
            else al_draw_scaled_bitmap(fundo_card,0,0,240,360,240 + 125*(cont % 4),70 + 160*(cont / 4),100,150,0);
            cont++;
        }

        VerificaEventos(sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);

        if(*sair == true) {
            if(!promptSair(fim_de_jogo,prompt,color,display,jogador,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer)) {
                *sair = false;
            }
        }

        if(*mouse2 == true || (*mouse == true && *posX >= 725 && *posX < 725 + 45 && *posY >= 490 && *posY < 490 + 45)) {
            imgCard = NULL;
            break;
        }
        else if(*mouse == true && pagina+1 <= i/12 + valor && *posX >= 725 && *posX < 770 && *posY >= 85 && *posY < 130) {
            pagina++;
            //al_rest(0.2);
        }
        else if(*mouse == true && pagina > 1 && *posX >= 725 && *posX < 770 && *posY >= 145 && *posY < 190) {
            pagina--;
            //al_rest(0.2);
        }


        if(cont > 0 && *posX >= 240 && *posX < 340 && *posY >= 70 && *posY < 220) {
            if(*mouse == true) {
                imgCard = vetor[12*(pagina-1)];
                break;
            }
            else {
                if(vetor[12*(pagina-1)]->card->origem->colecao != nome) {
                    rolagem = 0;
                    nome = vetor[12*(pagina-1)]->card->origem->colecao;
                }

                if(permite_olhar == true) {
                    al_draw_bitmap(vetor[12*(pagina-1)]->card->origem->bmp,0,0,0);
                    buffer = vetor[12*(pagina-1)]->card->origem;
                }
            }
        }

        else if(cont > 1 && *posX >= 365 && *posX < 465 && *posY >= 70 && *posY < 220) {
            if(*mouse == true) {
                imgCard = vetor[12*(pagina-1) + 1];
                break;
            }
            else {
                if(vetor[12*(pagina-1) + 1]->card->origem->colecao != nome) {
                    rolagem = 0;
                    nome = vetor[12*(pagina-1) + 1]->card->origem->colecao;
                }

                if(permite_olhar == true) {
                    al_draw_bitmap(vetor[12*(pagina-1) + 1]->card->origem->bmp,0,0,0);
                    buffer = vetor[12*(pagina-1) + 1]->card->origem;
                }
            }
        }

        else if(cont > 2 && *posX >= 490 && *posX < 590 && *posY >= 70 && *posY < 220) {
            if(*mouse == true) {
                imgCard = vetor[12*(pagina-1) + 2];
                break;
            }
            else {
                if(vetor[12*(pagina-1) + 2]->card->origem->colecao != nome) {
                    rolagem = 0;
                    nome = vetor[12*(pagina-1) + 2]->card->origem->colecao;
                }

                if(permite_olhar == true) {
                    al_draw_bitmap(vetor[12*(pagina-1) + 2]->card->origem->bmp,0,0,0);
                    buffer = vetor[12*(pagina-1) + 2]->card->origem;
                }
            }
        }

        else if(cont > 3 && *posX >= 615 && *posX < 715 && *posY >= 70 && *posY < 220) {
            if(*mouse == true) {
                imgCard = vetor[12*(pagina-1) + 3];
                break;
            }
            else {
                if(vetor[12*(pagina-1) + 3]->card->origem->colecao != nome) {
                    rolagem = 0;
                    nome = vetor[12*(pagina-1) + 3]->card->origem->colecao;
                }

                if(permite_olhar == true) {
                    al_draw_bitmap(vetor[12*(pagina-1) + 3]->card->origem->bmp,0,0,0);
                    buffer = vetor[12*(pagina-1) + 3]->card->origem;
                }
            }
        }

        else if(cont > 4 && *posX >= 240 && *posX < 340 && *posY >= 230 && *posY < 380) {
            if(*mouse == true) {
                imgCard = vetor[12*(pagina-1) + 4];
                break;
            }
            else {
                if(vetor[12*(pagina-1) + 4]->card->origem->colecao != nome) {
                    rolagem = 0;
                    nome = vetor[12*(pagina-1) + 4]->card->origem->colecao;
                }

                if(permite_olhar == true) {
                    al_draw_bitmap(vetor[12*(pagina-1) + 4]->card->origem->bmp,0,0,0);
                    buffer = vetor[12*(pagina-1) + 4]->card->origem;
                }
            }
        }

        else if(cont > 5 && *posX >= 365 && *posX < 465 && *posY >= 230 && *posY < 380) {
            if(*mouse == true) {
                imgCard = vetor[12*(pagina-1) + 5];
                break;
            }
            else {
                if(vetor[12*(pagina-1) + 5]->card->origem->colecao != nome) {
                    rolagem = 0;
                    nome = vetor[12*(pagina-1) + 5]->card->origem->colecao;
                }

                if(permite_olhar == true) {
                    al_draw_bitmap(vetor[12*(pagina-1) + 5]->card->origem->bmp,0,0,0);
                    buffer = vetor[12*(pagina-1) + 5]->card->origem;
                }
            }
        }

        else if(cont > 6 && *posX >= 490 && *posX < 590 && *posY >= 230 && *posY < 380) {
            if(*mouse == true) {
                imgCard = vetor[12*(pagina-1) + 6];
                break;
            }
            else {
                if(vetor[12*(pagina-1) + 6]->card->origem->colecao != nome) {
                    rolagem = 0;
                    nome = vetor[12*(pagina-1) + 6]->card->origem->colecao;
                }

                if(permite_olhar == true) {
                    al_draw_bitmap(vetor[12*(pagina-1) + 6]->card->origem->bmp,0,0,0);
                    buffer = vetor[12*(pagina-1) + 6]->card->origem;
                }
            }
        }

        else if(cont > 7 && *posX >= 615 && *posX < 715 && *posY >= 230 && *posY < 380) {
            if(*mouse == true) {
                imgCard = vetor[12*(pagina-1) + 7];
                break;
            }
            else {
                if(vetor[12*(pagina-1) + 7]->card->origem->colecao != nome) {
                    rolagem = 0;
                    nome = vetor[12*(pagina-1) + 7]->card->origem->colecao;
                }

                if(permite_olhar == true) {
                    al_draw_bitmap(vetor[12*(pagina-1) + 7]->card->origem->bmp,0,0,0);
                    buffer = vetor[12*(pagina-1) + 7]->card->origem;
                }
            }
        }

        else if(cont > 8 && *posX >= 240 && *posX < 340 && *posY >= 390 && *posY < 540) {
            if(*mouse == true) {
                imgCard = vetor[12*(pagina-1) + 8];
                break;
            }
            else {
                if(vetor[12*(pagina-1) + 8]->card->origem->colecao != nome) {
                    rolagem = 0;
                    nome = vetor[12*(pagina-1) + 8]->card->origem->colecao;
                }

                if(permite_olhar == true) {
                    al_draw_bitmap(vetor[12*(pagina-1) + 8]->card->origem->bmp,0,0,0);
                    buffer = vetor[12*(pagina-1) + 8]->card->origem;
                }
            }
        }

        else if(cont > 9 && *posX >= 365 && *posX < 465 && *posY >= 390 && *posY < 540) {
            if(*mouse == true) {
                imgCard = vetor[12*(pagina-1) + 9];
                break;
            }
            else {
                if(vetor[12*(pagina-1) + 9]->card->origem->colecao != nome) {
                    rolagem = 0;
                    nome = vetor[12*(pagina-1) + 9]->card->origem->colecao;
                }

                if(permite_olhar == true) {
                    al_draw_bitmap(vetor[12*(pagina-1) + 9]->card->origem->bmp,0,0,0);
                    buffer = vetor[12*(pagina-1) + 9]->card->origem;
                }
            }
        }

        else if(cont > 10 && *posX >= 490 && *posX < 590 && *posY >= 390 && *posY < 540) {
            if(*mouse == true) {
                imgCard = vetor[12*(pagina-1) + 10];
                break;
            }
            else {
                if(vetor[12*(pagina-1) + 10]->card->origem->colecao != nome) {
                    rolagem = 0;
                    nome = vetor[12*(pagina-1) + 10]->card->origem->colecao;
                }

                if(permite_olhar == true) {
                    al_draw_bitmap(vetor[12*(pagina-1) + 10]->card->origem->bmp,0,0,0);
                    buffer = vetor[12*(pagina-1) + 10]->card->origem;
                }
            }
        }

        else if(cont > 11 && *posX >= 615 && *posX < 715 && *posY >= 390 && *posY < 540) {
            if(*mouse == true) {
                imgCard = vetor[12*(pagina-1) + 11];
                break;
            }
            else {
                if(vetor[12*(pagina-1) + 11]->card->origem->colecao != nome) {
                    rolagem = 0;
                    nome = vetor[12*(pagina-1) + 11]->card->origem->colecao;
                }

                if(permite_olhar == true) {
                    al_draw_bitmap(vetor[12*(pagina-1) + 11]->card->origem->bmp,0,0,0);
                    buffer = vetor[12*(pagina-1) + 11]->card->origem;
                }
            }
        }

        BarraRolagem(&rolagem,posX,posY,dltZ,mouse,buffer,roll_bar,font2,color);
        al_flip_display();
    }

    al_draw_bitmap(temp,0,0,0);
    if(imgCard == NULL) {
        retorna_card = NULL;
        printf("Busca retorna nula!\n");
    }
    else {
        printf("Busca retorna:");

        aux = menu;
        while(aux->prox != NULL && imgCard->card != aux->card) {
            aux = aux->prox;
        }
        retorna_card = aux;
    }

    al_destroy_bitmap(temp);
    //al_rest(0.2);
    free(vetor);

    if(imgCard != NULL) printf(" %s!\n",retorna_card->card->origem->nome);
    return(retorna_card);
}

void InspecionaGraveyard(struct Player *player,bool lado,bool *fim,struct Player *jogador,ALLEGRO_DISPLAY *display,ALLEGRO_BITMAP *prompt,ALLEGRO_BITMAP *selecao,ALLEGRO_BITMAP *roll_bar,ALLEGRO_BITMAP *fundo_carta,ALLEGRO_BITMAP *fundo_menu,ALLEGRO_BITMAP *fundo,ALLEGRO_FONT *font,ALLEGRO_FONT *font2,ALLEGRO_COLOR color,bool *sair,int *posX,int *posY,int *dltZ,bool *mouse,bool *mouse2,bool *mouse_lado,int *keychar,bool *repete_keychar,ALLEGRO_EVENT_QUEUE *event_queue,ALLEGRO_TIMER *keyb_press_timer,ALLEGRO_TIMER *mouse_press_timer) {
    if(lado == true) MenuCards("Player GRAVEYARD",true,player->graveyard->inicio,fim,jogador,display,prompt,selecao,roll_bar,fundo_carta,fundo_menu,fundo,font2,font,color,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);
    else MenuCards("Adversary GRAVEYARD",true,player->graveyard->inicio,fim,jogador,display,prompt,selecao,roll_bar,fundo_carta,fundo_menu,fundo,font2,font,color,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);
}

//Se x = -1 e y = -1, os atributos do mouse nao serao usados.
void DestacaCard(struct Card **buffer,bool *fim,struct Player *jogador,struct Player *adversario,struct StatusBox_bitmaps *sbox,struct Coordenadas *lista,ALLEGRO_BITMAP *prompt,ALLEGRO_BITMAP *fundo_card,ALLEGRO_BITMAP *fundo_menu,ALLEGRO_BITMAP *fundo,ALLEGRO_BITMAP *selecao,ALLEGRO_BITMAP *roll_bar,ALLEGRO_DISPLAY *display,ALLEGRO_FONT *font,ALLEGRO_FONT *font2,ALLEGRO_COLOR color,bool *sair,int *posX,int *posY,int *dltZ,bool *mouse,bool *mouse2,bool *mouse_lado,int *keychar,bool *repete_keychar,ALLEGRO_EVENT_QUEUE *event_queue,ALLEGRO_TIMER *keyb_press_timer,ALLEGRO_TIMER *mouse_press_timer,int *rolagem,int ataque_gerado,int *defesa_gerada) {
    struct Deck *aux;
    struct CARD *alvo = NULL;
    Acao aux2;
    int defValor;
    bool toggle,ehCharacter,ehJogador;
    char *nome;

    VerificaEventos(sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);
    //al_rest(0.1);

    nome = (char *)calloc(50,sizeof(char));
    if(*buffer != NULL) strcpy(nome,(*buffer)->nome);

    if(jogador->mesa->character != NULL && (*posX)>=jogador->mesa->character->PosicaoX && (*posX)<jogador->mesa->character->PosicaoX + 50 && (*posY)>=jogador->mesa->character->PosicaoY && (*posY)<jogador->mesa->character->PosicaoY + 75) {
        *buffer = jogador->mesa->character->origem;

        if(defesa_gerada == NULL) defValor = -1;
        else defValor = defesa_gerada[8];

        alvo = jogador->mesa->character;
        ehCharacter = true;
        ehJogador = true;
    }
    else if(jogador->mesa->equip1 != NULL && (*posX)>=jogador->mesa->equip1->PosicaoX && (*posX)<jogador->mesa->equip1->PosicaoX + 50 && (*posY)>=jogador->mesa->equip1->PosicaoY && (*posY)<jogador->mesa->equip1->PosicaoY + 75) {
        *buffer = jogador->mesa->equip1->origem;
    }
    else if(jogador->mesa->equip2 != NULL && (*posX)>=jogador->mesa->equip2->PosicaoX && (*posX)<jogador->mesa->equip2->PosicaoX + 50 && (*posY)>=jogador->mesa->equip2->PosicaoY && (*posY)<jogador->mesa->equip2->PosicaoY + 75) {
        *buffer = jogador->mesa->equip2->origem;
    }
    else if(jogador->mesa->equip3 != NULL && (*posX)>=jogador->mesa->equip3->PosicaoX && (*posX)<jogador->mesa->equip3->PosicaoX + 50 && (*posY)>=jogador->mesa->equip3->PosicaoY && (*posY)<jogador->mesa->equip3->PosicaoY + 75) {
        *buffer = jogador->mesa->equip3->origem;
    }
    else if(jogador->mesa->equip4 != NULL && (*posX)>=jogador->mesa->equip4->PosicaoX && (*posX)<jogador->mesa->equip4->PosicaoX + 50 && (*posY)>=jogador->mesa->equip4->PosicaoY && (*posY)<jogador->mesa->equip4->PosicaoY + 75) {
        *buffer = jogador->mesa->equip4->origem;
    }
    else if(jogador->mesa->equip5 != NULL && (*posX)>=jogador->mesa->equip5->PosicaoX && (*posX)<jogador->mesa->equip5->PosicaoX + 50 && (*posY)>=jogador->mesa->equip5->PosicaoY && (*posY)<jogador->mesa->equip5->PosicaoY + 75) {
        *buffer = jogador->mesa->equip5->origem;
    }
    else if(jogador->mesa->equip6 != NULL && (*posX)>=jogador->mesa->equip6->PosicaoX && (*posX)<jogador->mesa->equip6->PosicaoX + 50 && (*posY)>=jogador->mesa->equip6->PosicaoY && (*posY)<jogador->mesa->equip6->PosicaoY + 75) {
        *buffer = jogador->mesa->equip6->origem;
    }
    else if(jogador->mesa->equip7 != NULL && (*posX)>=jogador->mesa->equip7->PosicaoX && (*posX)<jogador->mesa->equip7->PosicaoX + 50 && (*posY)>=jogador->mesa->equip7->PosicaoY && (*posY)<jogador->mesa->equip7->PosicaoY + 75) {
        *buffer = jogador->mesa->equip7->origem;
    }
    else if(jogador->mesa->monstro1 != NULL && (*posX)>=jogador->mesa->monstro1->PosicaoX && (*posX)<jogador->mesa->monstro1->PosicaoX + 50 && (*posY)>=jogador->mesa->monstro1->PosicaoY && (*posY)<jogador->mesa->monstro1->PosicaoY + 75) {
        *buffer = jogador->mesa->monstro1->origem;

        if(defesa_gerada == NULL) defValor = -1;
        else defValor = defesa_gerada[9];

        alvo = jogador->mesa->monstro1;
        ehCharacter = false;
        ehJogador = true;
    }
    else if(jogador->mesa->monstro2 != NULL && (*posX)>=jogador->mesa->monstro2->PosicaoX && (*posX)<jogador->mesa->monstro2->PosicaoX + 50 && (*posY)>=jogador->mesa->monstro2->PosicaoY && (*posY)<jogador->mesa->monstro2->PosicaoY + 75) {
        *buffer = jogador->mesa->monstro2->origem;

        if(defesa_gerada == NULL) defValor = -1;
        else defValor = defesa_gerada[10];

        alvo = jogador->mesa->monstro2;
        ehCharacter = false;
        ehJogador = true;
    }
    else if(jogador->mesa->monstro3 != NULL && (*posX)>=jogador->mesa->monstro3->PosicaoX && (*posX)<jogador->mesa->monstro3->PosicaoX + 50 && (*posY)>=jogador->mesa->monstro3->PosicaoY && (*posY)<jogador->mesa->monstro3->PosicaoY + 75) {
        *buffer = jogador->mesa->monstro3->origem;

        if(defesa_gerada == NULL) defValor = -1;
        else defValor = defesa_gerada[11];

        alvo = jogador->mesa->monstro3;
        ehCharacter = false;
        ehJogador = true;
    }
    else if(jogador->mesa->monstro4 != NULL && (*posX)>=jogador->mesa->monstro4->PosicaoX && (*posX)<jogador->mesa->monstro4->PosicaoX + 50 && (*posY)>=jogador->mesa->monstro4->PosicaoY && (*posY)<jogador->mesa->monstro4->PosicaoY + 75) {
        *buffer = jogador->mesa->monstro4->origem;

        if(defesa_gerada == NULL) defValor = -1;
        else defValor = defesa_gerada[12];

        alvo = jogador->mesa->monstro4;
        ehCharacter = false;
        ehJogador = true;
    }
    else if(jogador->mesa->monstro5 != NULL && (*posX)>=jogador->mesa->monstro5->PosicaoX && (*posX)<jogador->mesa->monstro5->PosicaoX + 50 && (*posY)>=jogador->mesa->monstro5->PosicaoY && (*posY)<jogador->mesa->monstro5->PosicaoY + 75) {
        *buffer = jogador->mesa->monstro5->origem;

        if(defesa_gerada == NULL) defValor = -1;
        else defValor = defesa_gerada[13];

        alvo = jogador->mesa->monstro5;
        ehCharacter = false;
        ehJogador = true;
    }
    else if(jogador->mesa->monstro6 != NULL && (*posX)>=jogador->mesa->monstro6->PosicaoX && (*posX)<jogador->mesa->monstro6->PosicaoX + 50 && (*posY)>=jogador->mesa->monstro6->PosicaoY && (*posY)<jogador->mesa->monstro6->PosicaoY + 75) {
        *buffer = jogador->mesa->monstro6->origem;

        if(defesa_gerada == NULL) defValor = -1;
        else defValor = defesa_gerada[14];

        alvo = jogador->mesa->monstro6;
        ehCharacter = false;
        ehJogador = true;
    }
    else if(jogador->mesa->monstro7 != NULL && (*posX)>=jogador->mesa->monstro7->PosicaoX && (*posX)<jogador->mesa->monstro7->PosicaoX + 50 && (*posY)>=jogador->mesa->monstro7->PosicaoY && (*posY)<jogador->mesa->monstro7->PosicaoY + 75) {
        *buffer = jogador->mesa->monstro7->origem;

        if(defesa_gerada == NULL) defValor = -1;
        else defValor = defesa_gerada[15];

        alvo = jogador->mesa->monstro7;
        ehCharacter = false;
        ehJogador = true;
    }
    else if(jogador->mesa->field != NULL && (*posX)>=jogador->mesa->field->PosicaoX && (*posX)<jogador->mesa->field->PosicaoX + 50 && (*posY)>=jogador->mesa->field->PosicaoY && (*posY)<jogador->mesa->field->PosicaoY + 75) {
        *buffer = jogador->mesa->field->origem;
    }

    else if(adversario->mesa->character != NULL && (*posX)>=adversario->mesa->character->PosicaoX && (*posX)<adversario->mesa->character->PosicaoX + 50 && (*posY)>=adversario->mesa->character->PosicaoY && (*posY)<adversario->mesa->character->PosicaoY + 75) {
        *buffer = adversario->mesa->character->origem;

        if(defesa_gerada == NULL) defValor = -1;
        else defValor = defesa_gerada[0];

        alvo = adversario->mesa->character;

        ehCharacter = true;
        ehJogador = false;
    }
    else if(adversario->mesa->equip1 != NULL && (*posX)>=adversario->mesa->equip1->PosicaoX && (*posX)<adversario->mesa->equip1->PosicaoX + 50 && (*posY)>=adversario->mesa->equip1->PosicaoY && (*posY)<adversario->mesa->equip1->PosicaoY + 75) {
        *buffer = adversario->mesa->equip1->origem;
    }
    else if(adversario->mesa->equip2 != NULL && (*posX)>=adversario->mesa->equip2->PosicaoX && (*posX)<adversario->mesa->equip2->PosicaoX + 50 && (*posY)>=adversario->mesa->equip2->PosicaoY && (*posY)<adversario->mesa->equip2->PosicaoY + 75) {
        *buffer = adversario->mesa->equip2->origem;
    }
    else if(adversario->mesa->equip3 != NULL && (*posX)>=adversario->mesa->equip3->PosicaoX && (*posX)<adversario->mesa->equip3->PosicaoX + 50 && (*posY)>=adversario->mesa->equip3->PosicaoY && (*posY)<adversario->mesa->equip3->PosicaoY + 75) {
        *buffer = adversario->mesa->equip3->origem;
    }
    else if(adversario->mesa->equip4 != NULL && (*posX)>=adversario->mesa->equip4->PosicaoX && (*posX)<adversario->mesa->equip4->PosicaoX + 50 && (*posY)>=adversario->mesa->equip4->PosicaoY && (*posY)<adversario->mesa->equip4->PosicaoY + 75) {
        *buffer = adversario->mesa->equip4->origem;
    }
    else if(adversario->mesa->equip5 != NULL && (*posX)>=adversario->mesa->equip5->PosicaoX && (*posX)<adversario->mesa->equip5->PosicaoX + 50 && (*posY)>=adversario->mesa->equip5->PosicaoY && (*posY)<adversario->mesa->equip5->PosicaoY + 75) {
        *buffer = adversario->mesa->equip5->origem;
    }
    else if(adversario->mesa->equip6 != NULL && (*posX)>=adversario->mesa->equip6->PosicaoX && (*posX)<adversario->mesa->equip6->PosicaoX + 50 && (*posY)>=adversario->mesa->equip6->PosicaoY && (*posY)<adversario->mesa->equip6->PosicaoY + 75) {
        *buffer = adversario->mesa->equip6->origem;
    }
    else if(adversario->mesa->equip7 != NULL && (*posX)>=adversario->mesa->equip7->PosicaoX && (*posX)<adversario->mesa->equip7->PosicaoX + 50 && (*posY)>=adversario->mesa->equip7->PosicaoY && (*posY)<adversario->mesa->equip7->PosicaoY + 75) {
        *buffer = adversario->mesa->equip7->origem;
    }
    else if(adversario->mesa->monstro1 != NULL && (*posX)>=adversario->mesa->monstro1->PosicaoX && (*posX)<adversario->mesa->monstro1->PosicaoX + 50 && (*posY)>=adversario->mesa->monstro1->PosicaoY && (*posY)<adversario->mesa->monstro1->PosicaoY + 75) {
        *buffer = adversario->mesa->monstro1->origem;

        if(defesa_gerada == NULL) defValor = -1;
        else defValor = defesa_gerada[1];

        alvo = adversario->mesa->monstro1;
        ehCharacter = false;
        ehJogador = false;
    }
    else if(adversario->mesa->monstro2 != NULL && (*posX)>=adversario->mesa->monstro2->PosicaoX && (*posX)<adversario->mesa->monstro2->PosicaoX + 50 && (*posY)>=adversario->mesa->monstro2->PosicaoY && (*posY)<adversario->mesa->monstro2->PosicaoY + 75) {
        *buffer = adversario->mesa->monstro2->origem;

        if(defesa_gerada == NULL) defValor = -1;
        else defValor = defesa_gerada[2];

        alvo = adversario->mesa->monstro2;
        ehCharacter = false;
        ehJogador = false;
    }
    else if(adversario->mesa->monstro3 != NULL && (*posX)>=adversario->mesa->monstro3->PosicaoX && (*posX)<adversario->mesa->monstro3->PosicaoX + 50 && (*posY)>=adversario->mesa->monstro3->PosicaoY && (*posY)<adversario->mesa->monstro3->PosicaoY + 75) {
        *buffer = adversario->mesa->monstro3->origem;

        if(defesa_gerada == NULL) defValor = -1;
        else defValor = defesa_gerada[3];

        alvo = adversario->mesa->monstro3;
        ehCharacter = false;
        ehJogador = false;
    }
    else if(adversario->mesa->monstro4 != NULL && (*posX)>=adversario->mesa->monstro4->PosicaoX && (*posX)<adversario->mesa->monstro4->PosicaoX + 50 && (*posY)>=adversario->mesa->monstro4->PosicaoY && (*posY)<adversario->mesa->monstro4->PosicaoY + 75) {
        *buffer = adversario->mesa->monstro4->origem;

        if(defesa_gerada == NULL) defValor = -1;
        else defValor = defesa_gerada[4];

        alvo = adversario->mesa->monstro4;
        ehCharacter = false;
        ehJogador = false;
    }
    else if(adversario->mesa->monstro5 != NULL && (*posX)>=adversario->mesa->monstro5->PosicaoX && (*posX)<adversario->mesa->monstro5->PosicaoX + 50 && (*posY)>=adversario->mesa->monstro5->PosicaoY && (*posY)<adversario->mesa->monstro5->PosicaoY + 75) {
        *buffer = adversario->mesa->monstro5->origem;

        if(defesa_gerada == NULL) defValor = -1;
        else defValor = defesa_gerada[5];

        alvo = adversario->mesa->monstro5;
        ehCharacter = false;
        ehJogador = false;
    }
    else if(adversario->mesa->monstro6 != NULL && (*posX)>=adversario->mesa->monstro6->PosicaoX && (*posX)<adversario->mesa->monstro6->PosicaoX + 50 && (*posY)>=adversario->mesa->monstro6->PosicaoY && (*posY)<adversario->mesa->monstro6->PosicaoY + 75) {
        *buffer = adversario->mesa->monstro6->origem;

        if(defesa_gerada == NULL) defValor = -1;
        else defValor = defesa_gerada[6];

        alvo = adversario->mesa->monstro6;
        ehCharacter = false;
        ehJogador = false;
    }
    else if(adversario->mesa->monstro7 != NULL && (*posX)>=adversario->mesa->monstro7->PosicaoX && (*posX)<adversario->mesa->monstro7->PosicaoX + 50 && (*posY)>=adversario->mesa->monstro7->PosicaoY && (*posY)<adversario->mesa->monstro7->PosicaoY + 75) {
        *buffer = adversario->mesa->monstro7->origem;

        if(defesa_gerada == NULL) defValor = -1;
        else defValor = defesa_gerada[7];

        alvo = adversario->mesa->monstro7;
        ehCharacter = false;
        ehJogador = false;
    }
    else if(adversario->mesa->field != NULL && (*posX)>=adversario->mesa->field->PosicaoX && (*posX)<adversario->mesa->field->PosicaoX + 50 && (*posY)>=adversario->mesa->field->PosicaoY && (*posY)<adversario->mesa->field->PosicaoY + 75) {
        *buffer = adversario->mesa->field->origem;
    }

    else if(jogador->graveyard->quantidade > 0 && (*posX)>=745 && (*posX)<745+50 && (*posY)>=365 && (*posY)<365+75) {
        *buffer = jogador->graveyard->inicio->card->origem;
        if(*mouse == true) InspecionaGraveyard(jogador,true,fim,jogador,display,prompt,selecao,roll_bar,fundo_card,fundo_menu,fundo,font,font2,color,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);
    }

    else if(adversario->graveyard->quantidade > 0 && (*posX)>=745 && (*posX)<745+50 && (*posY)>=115 && (*posY)<115+75) {
        *buffer = adversario->graveyard->inicio->card->origem;
        if(*mouse == true) InspecionaGraveyard(adversario,false,fim,jogador,display,prompt,selecao,roll_bar,fundo_card,fundo_menu,fundo,font,font2,color,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);
    }

    else {
        aux = jogador->hand->inicio;    //cards da mao do jogador
        while(aux->prox != NULL) {
            if(aux->prox->prox == NULL && (*posX)>=aux->card->PosicaoX && (*posX)<aux->card->PosicaoX + 100 && (*posY)>=aux->card->PosicaoY && (*posY)<aux->card->PosicaoY + 150) {
                *buffer = aux->card->origem;
                break;
            }
            else if((*posX)>=aux->card->PosicaoX && (*posX)<aux->card->PosicaoX + 30 && (*posY)>=aux->card->PosicaoY && (*posY)<aux->card->PosicaoY + 150) {
                *buffer = aux->card->origem;
                break;
            }

            aux = aux->prox;
        }

        if(aux->prox == NULL) {
            aux2 = jogador->character_actions->prox->prox->prox;
            toggle = false;
            while(aux2->prox != NULL) {
                if((*posX)>=aux2->card->PosicaoX && (*posX)<aux2->card->PosicaoX + 50 && (*posY)>=aux2->card->PosicaoY + 55 && (*posY)<aux2->card->PosicaoY + 75) {
                    *buffer = aux2->card->origem;
                    toggle = true;
                    break;
                }
                aux2 = aux2->prox;
            }
            if(toggle == false) {
                aux2 = adversario->character_actions->prox->prox->prox;
                while(aux2->prox != NULL) {
                    if((*posX)>=aux2->card->PosicaoX && (*posX)<aux2->card->PosicaoX + 50 && (*posY)>=aux2->card->PosicaoY + 55 && (*posY)<aux2->card->PosicaoY + 75) {
                        *buffer = aux2->card->origem;
                        toggle = true;
                        break;
                    }
                    aux2 = aux2->prox;
                }

                if(toggle == false && adversario->hand->quantidade > 0 && (*posX) >= 240 && (*posX) <= 240 + (30*(adversario->hand->quantidade - 1) + 50) && (*posY) >= 30 && (*posY) < 30 + 75) *buffer = NULL;
            }
        }
    }

    if(*buffer != NULL) {
        if(strcmp(nome,(*buffer)->nome) != 0) *rolagem = 0;
        al_draw_bitmap((*buffer)->bmp,0,0,0);
        BarraRolagem(rolagem,posX,posY,dltZ,mouse,*buffer,roll_bar,font,color);
    }

    if(alvo != NULL) {
        if(ehJogador) StatusBox(ehCharacter,true,lista,alvo,sbox,(*posX),(*posY),jogador,adversario,font2,font,color,ataque_gerado,defValor);
        else StatusBox(ehCharacter,false,lista,alvo,sbox,(*posX),(*posY),adversario,jogador,font2,font,color,ataque_gerado,defValor);
    }

    free(nome);
}

bool MonstroPresente(struct Player *jogador) {
    if(jogador->mesa->monstro1 != NULL) return(true);
    if(jogador->mesa->monstro2 != NULL) return(true);
    if(jogador->mesa->monstro3 != NULL) return(true);
    if(jogador->mesa->monstro4 != NULL) return(true);
    if(jogador->mesa->monstro5 != NULL) return(true);
    if(jogador->mesa->monstro6 != NULL) return(true);
    if(jogador->mesa->monstro7 != NULL) return(true);

    return(false);
}

bool BossPresente(struct Player *jogador) {
    if(jogador->mesa->monstro1 != NULL && (jogador->mesa->monstro1->origem->jrboss != NULL || jogador->mesa->monstro1->origem->boss != NULL)) return(true);
    if(jogador->mesa->monstro2 != NULL && (jogador->mesa->monstro2->origem->jrboss != NULL || jogador->mesa->monstro2->origem->boss != NULL)) return(true);
    if(jogador->mesa->monstro3 != NULL && (jogador->mesa->monstro3->origem->jrboss != NULL || jogador->mesa->monstro3->origem->boss != NULL)) return(true);
    if(jogador->mesa->monstro4 != NULL && (jogador->mesa->monstro4->origem->jrboss != NULL || jogador->mesa->monstro4->origem->boss != NULL)) return(true);
    if(jogador->mesa->monstro5 != NULL && (jogador->mesa->monstro5->origem->jrboss != NULL || jogador->mesa->monstro5->origem->boss != NULL)) return(true);
    if(jogador->mesa->monstro6 != NULL && (jogador->mesa->monstro6->origem->jrboss != NULL || jogador->mesa->monstro6->origem->boss != NULL)) return(true);
    if(jogador->mesa->monstro7 != NULL && (jogador->mesa->monstro7->origem->jrboss != NULL || jogador->mesa->monstro7->origem->boss != NULL)) return(true);

    return(false);
}

bool EhBoss(struct CARD *card) {    //todo card que passa por esta funcao TEM que ter sido testado a sua EXISTENCIA!
    if(card->origem->jrboss != NULL || card->origem->boss != NULL) return(true);
    else return(false);
}

int TotalEquipsEmCampo(struct Player *jogador,struct Player *adversario,int modo) {
    //MODO: 0 -> sem restricoes     1 -> Jogador somente     2 -> Adversario somente
    int cont = 0;

    if(modo != 2) {
        if(jogador->mesa->equip1 != NULL) cont++;
        if(jogador->mesa->equip2 != NULL) cont++;
        if(jogador->mesa->equip3 != NULL) cont++;
        if(jogador->mesa->equip4 != NULL) cont++;
        if(jogador->mesa->equip5 != NULL) cont++;
        if(jogador->mesa->equip6 != NULL) cont++;
        if(jogador->mesa->equip7 != NULL) cont++;
    }

    if(modo != 1) {
        if(adversario->mesa->equip1 != NULL) cont++;
        if(adversario->mesa->equip2 != NULL) cont++;
        if(adversario->mesa->equip3 != NULL) cont++;
        if(adversario->mesa->equip4 != NULL) cont++;
        if(adversario->mesa->equip5 != NULL) cont++;
        if(adversario->mesa->equip6 != NULL) cont++;
        if(adversario->mesa->equip7 != NULL) cont++;
    }

    return(cont);
}

int TotalMobsEmCampo(struct Player *jogador,struct Player *adversario,int modo) {
    //MODO: 0 -> sem restricoes     1 -> Jogador somente     2 -> Adversario somente
    int cont = 0;

    if(modo != 2) {
        if(jogador->mesa->monstro1 != NULL) cont++;
        if(jogador->mesa->monstro2 != NULL) cont++;
        if(jogador->mesa->monstro3 != NULL) cont++;
        if(jogador->mesa->monstro4 != NULL) cont++;
        if(jogador->mesa->monstro5 != NULL) cont++;
        if(jogador->mesa->monstro6 != NULL) cont++;
        if(jogador->mesa->monstro7 != NULL) cont++;
    }

    if(modo != 1) {
        if(adversario->mesa->monstro1 != NULL) cont++;
        if(adversario->mesa->monstro2 != NULL) cont++;
        if(adversario->mesa->monstro3 != NULL) cont++;
        if(adversario->mesa->monstro4 != NULL) cont++;
        if(adversario->mesa->monstro5 != NULL) cont++;
        if(adversario->mesa->monstro6 != NULL) cont++;
        if(adversario->mesa->monstro7 != NULL) cont++;
    }

    return(cont);
}

//Lista todos os possiveis alvos.
void IdentificaCard(struct Card **buffer,bool *fim,ALLEGRO_BITMAP *roll_bar,ALLEGRO_BITMAP *fundo_carta,ALLEGRO_BITMAP *deck_meio,ALLEGRO_BITMAP *deck_cheio,ALLEGRO_BITMAP *fundo,ALLEGRO_FONT *font,ALLEGRO_COLOR color,int *rolagem,bool *sair,int *posX,int *posY,int *dltZ,bool *mouse1,bool *mouse2,bool *mouse_lado,int *keychar,bool *repete_keychar,ALLEGRO_EVENT_QUEUE *event_queue,ALLEGRO_TIMER *keyb_press_timer,ALLEGRO_TIMER *mouse_press_timer,int elemento_ataque,int origem_ataque,int restricoes,struct Player *jogador,struct Player *adversario,int level,ALLEGRO_DISPLAY *display,ALLEGRO_BITMAP *bmp,int modo,struct Coordenadas *lista) {
    int i = 0;
    struct Deck *aux,*aux4 = NULL;
    struct Coordenadas *aux2,*aux3;

    if(lista == NULL) return;

    aux2 = lista;
    if(modo == 0) {         //ATTACK MONSTER & CHARACTER (OK a parte externa, nao a funcao interna!!!!!!)
        printf("Ataque iminente! ORIGEM: %d\t DESTINO: %d\t RESTRICOES: %d\n",origem_ataque,modo,restricoes);

        if(restricoes != 1 && AtingeCards(jogador,adversario,adversario->mesa->character,0,origem_ataque,elemento_ataque)) {  //alveja char
            aux2->prox = (struct Coordenadas *)malloc(sizeof(struct Coordenadas));
            aux2->prox->prox = NULL;

            al_draw_bitmap(bmp,685,110,0);
            aux2->x = 685;
            aux2->y = 110;
            aux2 = aux2->prox;
        }

        if(restricoes != 2 && adversario->mesa->monstro1 != NULL && AtingeCards(jogador,adversario,adversario->mesa->monstro1,1,origem_ataque,elemento_ataque)) {    //alveja monstro
            aux2->prox = (struct Coordenadas *)malloc(sizeof(struct Coordenadas));
            aux2->prox->prox = NULL;

            al_draw_bitmap(bmp,300,190,0);
            aux2->x = 300;
            aux2->y = 190;
            aux2 = aux2->prox;
        }

        if(restricoes != 2 && adversario->mesa->monstro2 != NULL && AtingeCards(jogador,adversario,adversario->mesa->monstro2,1,origem_ataque,elemento_ataque)) {
            aux2->prox = (struct Coordenadas *)malloc(sizeof(struct Coordenadas));
            aux2->prox->prox = NULL;

            al_draw_bitmap(bmp,355,190,0);
            aux2->x = 355;
            aux2->y = 190;
            aux2 = aux2->prox;
        }

        if(restricoes != 2 && adversario->mesa->monstro3 != NULL && AtingeCards(jogador,adversario,adversario->mesa->monstro3,1,origem_ataque,elemento_ataque)) {
            aux2->prox = (struct Coordenadas *)malloc(sizeof(struct Coordenadas));
            aux2->prox->prox = NULL;

            al_draw_bitmap(bmp,410,190,0);
            aux2->x = 410;
            aux2->y = 190;
            aux2 = aux2->prox;
        }

        if(restricoes != 2 && adversario->mesa->monstro4 != NULL && AtingeCards(jogador,adversario,adversario->mesa->monstro4,1,origem_ataque,elemento_ataque)) {
            aux2->prox = (struct Coordenadas *)malloc(sizeof(struct Coordenadas));
            aux2->prox->prox = NULL;

            al_draw_bitmap(bmp,465,190,0);
            aux2->x = 465;
            aux2->y = 190;
            aux2 = aux2->prox;
        }

        if(restricoes != 2 && adversario->mesa->monstro5 != NULL && AtingeCards(jogador,adversario,adversario->mesa->monstro5,1,origem_ataque,elemento_ataque)) {
            aux2->prox = (struct Coordenadas *)malloc(sizeof(struct Coordenadas));
            aux2->prox->prox = NULL;

            al_draw_bitmap(bmp,520,190,0);
            aux2->x = 520;
            aux2->y = 190;
            aux2 = aux2->prox;
        }

        if(restricoes != 2 && adversario->mesa->monstro6 != NULL && AtingeCards(jogador,adversario,adversario->mesa->monstro6,1,origem_ataque,elemento_ataque)) {
            aux2->prox = (struct Coordenadas *)malloc(sizeof(struct Coordenadas));
            aux2->prox->prox = NULL;

            al_draw_bitmap(bmp,575,190,0);
            aux2->x = 575;
            aux2->y = 190;
            aux2 = aux2->prox;
        }

        if(restricoes != 2 && adversario->mesa->monstro7 != NULL && AtingeCards(jogador,adversario,adversario->mesa->monstro7,1,origem_ataque,elemento_ataque)) {
            aux2->prox = (struct Coordenadas *)malloc(sizeof(struct Coordenadas));
            aux2->prox->prox = NULL;

            al_draw_bitmap(bmp,630,190,0);
            aux2->x = 630;
            aux2->y = 190;
            aux2 = aux2->prox;
        }
    }

    else if(modo == 1) {    //ATTACK EQUIPMENT
        if(adversario->mesa->equip1 != NULL) {
            aux3 = aux2;
            aux2->prox = (struct Coordenadas *)malloc(sizeof(struct Coordenadas));
            aux2 = aux2->prox;
            aux2->prox = NULL;

            al_draw_bitmap(bmp,300,110,0);
            aux3->x = 300;
            aux3->y = 110;
        }
        if(adversario->mesa->equip2 != NULL) {
            aux3 = aux2;
            aux2->prox = (struct Coordenadas *)malloc(sizeof(struct Coordenadas));
            aux2 = aux2->prox;
            aux2->prox = NULL;

            al_draw_bitmap(bmp,355,110,0);
            aux3->x = 355;
            aux3->y = 110;
        }
        if(adversario->mesa->equip3 != NULL) {
            aux3 = aux2;
            aux2->prox = (struct Coordenadas *)malloc(sizeof(struct Coordenadas));
            aux2 = aux2->prox;
            aux2->prox = NULL;

            al_draw_bitmap(bmp,410,110,0);
            aux3->x = 410;
            aux3->y = 110;
        }
        if(adversario->mesa->equip4 != NULL) {
            aux3 = aux2;
            aux2->prox = (struct Coordenadas *)malloc(sizeof(struct Coordenadas));
            aux2 = aux2->prox;
            aux2->prox = NULL;

            al_draw_bitmap(bmp,465,110,0);
            aux3->x = 465;
            aux3->y = 110;
        }
        if(adversario->mesa->equip5 != NULL) {
            aux3 = aux2;
            aux2->prox = (struct Coordenadas *)malloc(sizeof(struct Coordenadas));
            aux2 = aux2->prox;
            aux2->prox = NULL;

            al_draw_bitmap(bmp,520,110,0);
            aux3->x = 520;
            aux3->y = 110;
        }
        if(adversario->mesa->equip6 != NULL) {
            aux3 = aux2;
            aux2->prox = (struct Coordenadas *)malloc(sizeof(struct Coordenadas));
            aux2 = aux2->prox;
            aux2->prox = NULL;

            al_draw_bitmap(bmp,575,110,0);
            aux3->x = 575;
            aux3->y = 110;
        }
        if(adversario->mesa->equip7 != NULL) {
            aux3 = aux2;
            aux2->prox = (struct Coordenadas *)malloc(sizeof(struct Coordenadas));
            aux2 = aux2->prox;
            aux2->prox = NULL;

            al_draw_bitmap(bmp,630,110,0);
            aux3->x = 630;
            aux3->y = 110;
        }
    }

    else if(modo == 2) {    //LEVEL-UP CARD(OK!)
        aux = jogador->hand->inicio;

        while(aux->prox != NULL) {
            aux3 = aux2;
            aux2->prox = (struct Coordenadas *)malloc(sizeof(struct Coordenadas));
            aux2 = aux2->prox;
            aux2->prox = NULL;

            aux3->x = 240 + i*30;
            aux3->y = 450;

            al_draw_bitmap(bmp,240 + 30*i,450,0);    //representa o local de cada carta
            i++;

            aux = aux->prox;
        }
    }

    else if(modo == 3) {    //ESCOLHER MONSTRO, JR. BOSS E BOSS
        aux = jogador->hand->inicio;

        while(aux->prox != NULL) {
            if(aux->card->origem->monster != NULL && (aux->card->origem->monster->level - aux->card->level_drop) <= level) {
                if(strcmp(aux->card->origem->elemento,"Earth") == 0 && jogador->earth_ic > 0) {
                    aux3 = aux2;
                    aux2->prox = (struct Coordenadas *)malloc(sizeof(struct Coordenadas));
                    aux2 = aux2->prox;
                    aux2->prox = NULL;

                    aux3->x = 240 + i*30;
                    aux3->y = 450;

                    al_draw_bitmap(bmp,240 + i*30,450,0);
                }
                else if(strcmp(aux->card->origem->elemento,"Wind") == 0 && jogador->wind_ic > 0) {
                    aux3 = aux2;
                    aux2->prox = (struct Coordenadas *)malloc(sizeof(struct Coordenadas));
                    aux2 = aux2->prox;
                    aux2->prox = NULL;

                    aux3->x = 240 + i*30;
                    aux3->y = 450;

                    al_draw_bitmap(bmp,240 + i*30,450,0);
                }
                else if(strcmp(aux->card->origem->elemento,"Light") == 0 && jogador->light_ic > 0) {
                    aux3 = aux2;
                    aux2->prox = (struct Coordenadas *)malloc(sizeof(struct Coordenadas));
                    aux2 = aux2->prox;
                    aux2->prox = NULL;

                    aux3->x = 240 + i*30;
                    aux3->y = 450;

                    al_draw_bitmap(bmp,240 + i*30,450,0);
                }
                else if(strcmp(aux->card->origem->elemento,"Dark") == 0 && jogador->dark_ic > 0) {
                    aux3 = aux2;
                    aux2->prox = (struct Coordenadas *)malloc(sizeof(struct Coordenadas));
                    aux2 = aux2->prox;
                    aux2->prox = NULL;

                    aux3->x = 240 + i*30;
                    aux3->y = 450;

                    al_draw_bitmap(bmp,240 + i*30,450,0);
                }
                else if(strcmp(aux->card->origem->elemento,"Fire") == 0 && jogador->fire_ic > 0) {
                    aux3 = aux2;
                    aux2->prox = (struct Coordenadas *)malloc(sizeof(struct Coordenadas));
                    aux2 = aux2->prox;
                    aux2->prox = NULL;

                    aux3->x = 240 + i*30;
                    aux3->y = 450;

                    al_draw_bitmap(bmp,240 + i*30,450,0);
                }
                else if(strcmp(aux->card->origem->elemento,"Water") == 0 && jogador->water_ic > 0) {
                    aux3 = aux2;
                    aux2->prox = (struct Coordenadas *)malloc(sizeof(struct Coordenadas));
                    aux2 = aux2->prox;
                    aux2->prox = NULL;

                    aux3->x = 240 + i*30;
                    aux3->y = 450;

                    al_draw_bitmap(bmp,240 + i*30,450,0);
                }
            }

            else if(aux->card->origem->jrboss != NULL && (aux->card->origem->jrboss->level - aux->card->level_drop) <= level && !BossPresente(jogador)) {
                if(strcmp(aux->card->origem->elemento,"Earth") == 0 && jogador->earth_ic > 0) {
                    aux3 = aux2;
                    aux2->prox = (struct Coordenadas *)malloc(sizeof(struct Coordenadas));
                    aux2 = aux2->prox;
                    aux2->prox = NULL;

                    aux3->x = 240 + i*30;
                    aux3->y = 450;

                    al_draw_bitmap(bmp,240 + i*30,450,0);
                }
                else if(strcmp(aux->card->origem->elemento,"Wind") == 0 && jogador->wind_ic > 0) {
                    aux3 = aux2;
                    aux2->prox = (struct Coordenadas *)malloc(sizeof(struct Coordenadas));
                    aux2 = aux2->prox;
                    aux2->prox = NULL;

                    aux3->x = 240 + i*30;
                    aux3->y = 450;

                    al_draw_bitmap(bmp,240 + i*30,450,0);
                }
                else if(strcmp(aux->card->origem->elemento,"Light") == 0 && jogador->light_ic > 0) {
                    aux3 = aux2;
                    aux2->prox = (struct Coordenadas *)malloc(sizeof(struct Coordenadas));
                    aux2 = aux2->prox;
                    aux2->prox = NULL;

                    aux3->x = 240 + i*30;
                    aux3->y = 450;

                    al_draw_bitmap(bmp,240 + i*30,450,0);
                }
                else if(strcmp(aux->card->origem->elemento,"Dark") == 0 && jogador->dark_ic > 0) {
                    aux3 = aux2;
                    aux2->prox = (struct Coordenadas *)malloc(sizeof(struct Coordenadas));
                    aux2 = aux2->prox;
                    aux2->prox = NULL;

                    aux3->x = 240 + i*30;
                    aux3->y = 450;

                    al_draw_bitmap(bmp,240 + i*30,450,0);
                }
                else if(strcmp(aux->card->origem->elemento,"Fire") == 0 && jogador->fire_ic > 0) {
                    aux3 = aux2;
                    aux2->prox = (struct Coordenadas *)malloc(sizeof(struct Coordenadas));
                    aux2 = aux2->prox;
                    aux2->prox = NULL;

                    aux3->x = 240 + i*30;
                    aux3->y = 450;

                    al_draw_bitmap(bmp,240 + i*30,450,0);
                }
                else if(strcmp(aux->card->origem->elemento,"Water") == 0 && jogador->water_ic > 0) {
                    aux3 = aux2;
                    aux2->prox = (struct Coordenadas *)malloc(sizeof(struct Coordenadas));
                    aux2 = aux2->prox;
                    aux2->prox = NULL;

                    aux3->x = 240 + i*30;
                    aux3->y = 450;

                    al_draw_bitmap(bmp,240 + i*30,450,0);
                }
            }

            else if(aux->card->origem->boss != NULL && (aux->card->origem->boss->level - aux->card->level_drop) <= level && !BossPresente(jogador)) {
                if(strcmp(aux->card->origem->elemento,"Earth") == 0 && jogador->earth_ic > 0) {
                    aux3 = aux2;
                    aux2->prox = (struct Coordenadas *)malloc(sizeof(struct Coordenadas));
                    aux2 = aux2->prox;
                    aux2->prox = NULL;

                    aux3->x = 240 + i*30;
                    aux3->y = 450;

                    al_draw_bitmap(bmp,240 + i*30,450,0);
                }
                else if(strcmp(aux->card->origem->elemento,"Wind") == 0 && jogador->wind_ic > 0) {
                    aux3 = aux2;
                    aux2->prox = (struct Coordenadas *)malloc(sizeof(struct Coordenadas));
                    aux2 = aux2->prox;
                    aux2->prox = NULL;

                    aux3->x = 240 + i*30;
                    aux3->y = 450;

                    al_draw_bitmap(bmp,240 + i*30,450,0);
                }
                else if(strcmp(aux->card->origem->elemento,"Light") == 0 && jogador->light_ic > 0) {
                    aux3 = aux2;
                    aux2->prox = (struct Coordenadas *)malloc(sizeof(struct Coordenadas));
                    aux2 = aux2->prox;
                    aux2->prox = NULL;

                    aux3->x = 240 + i*30;
                    aux3->y = 450;

                    al_draw_bitmap(bmp,240 + i*30,450,0);
                }
                else if(strcmp(aux->card->origem->elemento,"Dark") == 0 && jogador->dark_ic > 0) {
                    aux3 = aux2;
                    aux2->prox = (struct Coordenadas *)malloc(sizeof(struct Coordenadas));
                    aux2 = aux2->prox;
                    aux2->prox = NULL;

                    aux3->x = 240 + i*30;
                    aux3->y = 450;

                    al_draw_bitmap(bmp,240 + i*30,450,0);
                }
                else if(strcmp(aux->card->origem->elemento,"Fire") == 0 && jogador->fire_ic > 0) {
                    aux3 = aux2;
                    aux2->prox = (struct Coordenadas *)malloc(sizeof(struct Coordenadas));
                    aux2 = aux2->prox;
                    aux2->prox = NULL;

                    aux3->x = 240 + i*30;
                    aux3->y = 450;

                    al_draw_bitmap(bmp,240 + i*30,450,0);
                }
                else if(strcmp(aux->card->origem->elemento,"Water") == 0 && jogador->water_ic > 0) {
                    aux3 = aux2;
                    aux2->prox = (struct Coordenadas *)malloc(sizeof(struct Coordenadas));
                    aux2 = aux2->prox;
                    aux2->prox = NULL;

                    aux3->x = 240 + i*30;
                    aux3->y = 450;

                    al_draw_bitmap(bmp,240 + i*30,450,0);
                }
            }

            i++;
            aux = aux->prox;
        }
    }

    else if(modo == 4) {    //ESCOLHER EQUIP
        aux = jogador->hand->inicio;

        while(aux->prox!=NULL) {
            if(aux->card->origem->equip!=NULL && (aux->card->origem->equip->level - aux->card->level_drop) <= level) {
                if(strcmp(aux->card->origem->elemento,"Earth") == 0 && jogador->earth_ic > 0) {
                    aux3 = aux2;
                    aux2->prox = (struct Coordenadas *)malloc(sizeof(struct Coordenadas));
                    aux2 = aux2->prox;
                    aux2->prox = NULL;

                    aux3->x = 240 + i*30;
                    aux3->y = 450;

                    al_draw_bitmap(bmp,240 + i*30,450,0);
                }
                else if(strcmp(aux->card->origem->elemento,"Wind") == 0 && jogador->wind_ic > 0) {
                    aux3 = aux2;
                    aux2->prox = (struct Coordenadas *)malloc(sizeof(struct Coordenadas));
                    aux2 = aux2->prox;
                    aux2->prox = NULL;

                    aux3->x = 240 + i*30;
                    aux3->y = 450;

                    al_draw_bitmap(bmp,240 + i*30,450,0);
                }
                else if(strcmp(aux->card->origem->elemento,"Light") == 0 && jogador->light_ic > 0) {
                    aux3 = aux2;
                    aux2->prox = (struct Coordenadas *)malloc(sizeof(struct Coordenadas));
                    aux2 = aux2->prox;
                    aux2->prox = NULL;

                    aux3->x = 240 + i*30;
                    aux3->y = 450;

                    al_draw_bitmap(bmp,240 + i*30,450,0);
                }
                else if(strcmp(aux->card->origem->elemento,"Dark") == 0 && jogador->dark_ic > 0) {
                    aux3 = aux2;
                    aux2->prox = (struct Coordenadas *)malloc(sizeof(struct Coordenadas));
                    aux2 = aux2->prox;
                    aux2->prox = NULL;

                    aux3->x = 240 + i*30;
                    aux3->y = 450;

                    al_draw_bitmap(bmp,240 + i*30,450,0);
                }
                else if(strcmp(aux->card->origem->elemento,"Fire") == 0 && jogador->fire_ic > 0) {
                    aux3 = aux2;
                    aux2->prox = (struct Coordenadas *)malloc(sizeof(struct Coordenadas));
                    aux2 = aux2->prox;
                    aux2->prox = NULL;

                    aux3->x = 240 + i*30;
                    aux3->y = 450;

                    al_draw_bitmap(bmp,240 + i*30,450,0);
                }
                else if(strcmp(aux->card->origem->elemento,"Water") == 0 && jogador->water_ic > 0) {
                    aux3 = aux2;
                    aux2->prox = (struct Coordenadas *)malloc(sizeof(struct Coordenadas));
                    aux2 = aux2->prox;
                    aux2->prox = NULL;

                    aux3->x = 240 + i*30;
                    aux3->y = 450;

                    al_draw_bitmap(bmp,240 + i*30,450,0);
                }
            }
            i++;

            aux = aux->prox;
        }
    }

    else if(modo == 5) {    //ESCOLHER FIELD
        aux = jogador->hand->inicio;

        while(aux->prox != NULL) {
            if(aux->card->origem->field != NULL) {
                if(strcmp(aux->card->origem->elemento,"Earth") == 0 && jogador->earth_ic > 0) {
                    aux3 = aux2;
                    aux2->prox = (struct Coordenadas *)malloc(sizeof(struct Coordenadas));
                    aux2 = aux2->prox;
                    aux2->prox = NULL;

                    aux3->x = 240 + i*30;
                    aux3->y = 450;

                    al_draw_bitmap(bmp,240 + i*30,450,0);
                }
                else if(strcmp(aux->card->origem->elemento,"Wind") == 0 && jogador->wind_ic > 0) {
                    aux3 = aux2;
                    aux2->prox = (struct Coordenadas *)malloc(sizeof(struct Coordenadas));
                    aux2 = aux2->prox;
                    aux2->prox = NULL;

                    aux3->x = 240 + i*30;
                    aux3->y = 450;

                    al_draw_bitmap(bmp,240 + i*30,450,0);
                }
                else if(strcmp(aux->card->origem->elemento,"Light") == 0 && jogador->light_ic > 0) {
                    aux3 = aux2;
                    aux2->prox = (struct Coordenadas *)malloc(sizeof(struct Coordenadas));
                    aux2 = aux2->prox;
                    aux2->prox = NULL;

                    aux3->x = 240 + i*30;
                    aux3->y = 450;

                    al_draw_bitmap(bmp,240 + i*30,450,0);
                }
                else if(strcmp(aux->card->origem->elemento,"Dark") == 0 && jogador->dark_ic > 0) {
                    aux3 = aux2;
                    aux2->prox = (struct Coordenadas *)malloc(sizeof(struct Coordenadas));
                    aux2 = aux2->prox;
                    aux2->prox = NULL;

                    aux3->x = 240 + i*30;
                    aux3->y = 450;

                    al_draw_bitmap(bmp,240 + i*30,450,0);
                }
                else if(strcmp(aux->card->origem->elemento,"Fire") == 0 && jogador->fire_ic > 0) {
                    aux3 = aux2;
                    aux2->prox = (struct Coordenadas *)malloc(sizeof(struct Coordenadas));
                    aux2 = aux2->prox;
                    aux2->prox = NULL;

                    aux3->x = 240 + i*30;
                    aux3->y = 450;

                    al_draw_bitmap(bmp,240 + i*30,450,0);
                }
                else if(strcmp(aux->card->origem->elemento,"Water") == 0 && jogador->water_ic > 0) {
                    aux3 = aux2;
                    aux2->prox = (struct Coordenadas *)malloc(sizeof(struct Coordenadas));
                    aux2 = aux2->prox;
                    aux2->prox = NULL;

                    aux3->x = 240 + i*30;
                    aux3->y = 450;

                    al_draw_bitmap(bmp,240 + i*30,450,0);
                }
            }
            i++;

            aux = aux->prox;
        }
    }

    else if(modo == 6) {    //ESCOLHER TACTIC
        aux = jogador->hand->inicio;

        while(aux->prox!=NULL) {
            if(aux->card->origem->tactic!=NULL && (aux->card->origem->tactic->level - aux->card->level_drop) <= level) {
                if(strcmp(aux->card->origem->elemento,"Earth") == 0 && jogador->earth_ic > 0) {
                    aux3 = aux2;
                    aux2->prox = (struct Coordenadas *)malloc(sizeof(struct Coordenadas));
                    aux2 = aux2->prox;
                    aux2->prox = NULL;

                    aux3->x = 240 + i*30;
                    aux3->y = 450;

                    al_draw_bitmap(bmp,240 + i*30,450,0);
                }
                else if(strcmp(aux->card->origem->elemento,"Wind") == 0 && jogador->wind_ic > 0) {
                    aux3 = aux2;
                    aux2->prox = (struct Coordenadas *)malloc(sizeof(struct Coordenadas));
                    aux2 = aux2->prox;
                    aux2->prox = NULL;

                    aux3->x = 240 + i*30;
                    aux3->y = 450;

                    al_draw_bitmap(bmp,240 + i*30,450,0);
                }
                else if(strcmp(aux->card->origem->elemento,"Light") == 0 && jogador->light_ic > 0) {
                    aux3 = aux2;
                    aux2->prox = (struct Coordenadas *)malloc(sizeof(struct Coordenadas));
                    aux2 = aux2->prox;
                    aux2->prox = NULL;

                    aux3->x = 240 + i*30;
                    aux3->y = 450;

                    al_draw_bitmap(bmp,240 + i*30,450,0);
                }
                else if(strcmp(aux->card->origem->elemento,"Dark") == 0 && jogador->dark_ic > 0) {
                    aux3 = aux2;
                    aux2->prox = (struct Coordenadas *)malloc(sizeof(struct Coordenadas));
                    aux2 = aux2->prox;
                    aux2->prox = NULL;

                    aux3->x = 240 + i*30;
                    aux3->y = 450;

                    al_draw_bitmap(bmp,240 + i*30,450,0);
                }
                else if(strcmp(aux->card->origem->elemento,"Fire") == 0 && jogador->fire_ic > 0) {
                    aux3 = aux2;
                    aux2->prox = (struct Coordenadas *)malloc(sizeof(struct Coordenadas));
                    aux2 = aux2->prox;
                    aux2->prox = NULL;

                    aux3->x = 240 + i*30;
                    aux3->y = 450;

                    al_draw_bitmap(bmp,240 + i*30,450,0);
                }
                else if(strcmp(aux->card->origem->elemento,"Water") == 0 && jogador->water_ic > 0) {
                    aux3 = aux2;
                    aux2->prox = (struct Coordenadas *)malloc(sizeof(struct Coordenadas));
                    aux2 = aux2->prox;
                    aux2->prox = NULL;

                    aux3->x = 240 + i*30;
                    aux3->y = 450;

                    al_draw_bitmap(bmp,240 + i*30,450,0);
                }
            }
            i++;

            aux = aux->prox;
        }
    }

    else if(modo == 7) {    //ESCOLHER JR.BOSS
        aux = jogador->hand->inicio;

        while(aux->prox!=NULL) {
            if(aux->card->origem->jrboss!=NULL && (aux->card->origem->jrboss->level - aux->card->level_drop) <= level && !BossPresente(jogador)) {
                if(strcmp(aux->card->origem->elemento,"Earth") == 0 && jogador->earth_ic > 0) {
                    aux3 = aux2;
                    aux2->prox = (struct Coordenadas *)malloc(sizeof(struct Coordenadas));
                    aux2 = aux2->prox;
                    aux2->prox = NULL;

                    aux3->x = 240 + i*30;
                    aux3->y = 450;

                    al_draw_bitmap(bmp,240 + i*30,450,0);
                }
                else if(strcmp(aux->card->origem->elemento,"Wind") == 0 && jogador->wind_ic > 0) {
                    aux3 = aux2;
                    aux2->prox = (struct Coordenadas *)malloc(sizeof(struct Coordenadas));
                    aux2 = aux2->prox;
                    aux2->prox = NULL;

                    aux3->x = 240 + i*30;
                    aux3->y = 450;

                    al_draw_bitmap(bmp,240 + i*30,450,0);
                }
                else if(strcmp(aux->card->origem->elemento,"Light") == 0 && jogador->light_ic > 0) {
                    aux3 = aux2;
                    aux2->prox = (struct Coordenadas *)malloc(sizeof(struct Coordenadas));
                    aux2 = aux2->prox;
                    aux2->prox = NULL;

                    aux3->x = 240 + i*30;
                    aux3->y = 450;

                    al_draw_bitmap(bmp,240 + i*30,450,0);
                }
                else if(strcmp(aux->card->origem->elemento,"Dark") == 0 && jogador->dark_ic > 0) {
                    aux3 = aux2;
                    aux2->prox = (struct Coordenadas *)malloc(sizeof(struct Coordenadas));
                    aux2 = aux2->prox;
                    aux2->prox = NULL;

                    aux3->x = 240 + i*30;
                    aux3->y = 450;

                    al_draw_bitmap(bmp,240 + i*30,450,0);
                }
                else if(strcmp(aux->card->origem->elemento,"Fire") == 0 && jogador->fire_ic > 0) {
                    aux3 = aux2;
                    aux2->prox = (struct Coordenadas *)malloc(sizeof(struct Coordenadas));
                    aux2 = aux2->prox;
                    aux2->prox = NULL;

                    aux3->x = 240 + i*30;
                    aux3->y = 450;

                    al_draw_bitmap(bmp,240 + i*30,450,0);
                }
                else if(strcmp(aux->card->origem->elemento,"Water") == 0 && jogador->water_ic > 0) {
                    aux3 = aux2;
                    aux2->prox = (struct Coordenadas *)malloc(sizeof(struct Coordenadas));
                    aux2 = aux2->prox;
                    aux2->prox = NULL;

                    aux3->x = 240 + i*30;
                    aux3->y = 450;

                    al_draw_bitmap(bmp,240 + i*30,450,0);
                }
            }
            i++;

            aux = aux->prox;
        }
    }

    else if(modo == 8) {    //ESCOLHER BOSS
        aux = jogador->hand->inicio;

        while(aux->prox != NULL) {
            if(aux->card->origem->boss!=NULL && (aux->card->origem->boss->level - aux->card->level_drop) <= level && !BossPresente(jogador)) {
                if(strcmp(aux->card->origem->elemento,"Earth") == 0 && jogador->earth_ic > 0) {
                    aux3 = aux2;
                    aux2->prox = (struct Coordenadas *)malloc(sizeof(struct Coordenadas));
                    aux2 = aux2->prox;
                    aux2->prox = NULL;

                    aux3->x = 240 + i*30;
                    aux3->y = 450;

                    al_draw_bitmap(bmp,240 + i*30,450,0);
                }
                else if(strcmp(aux->card->origem->elemento,"Wind") == 0 && jogador->wind_ic > 0) {
                    aux3 = aux2;
                    aux2->prox = (struct Coordenadas *)malloc(sizeof(struct Coordenadas));
                    aux2 = aux2->prox;
                    aux2->prox = NULL;

                    aux3->x = 240 + i*30;
                    aux3->y = 450;

                    al_draw_bitmap(bmp,240 + i*30,450,0);
                }
                else if(strcmp(aux->card->origem->elemento,"Light") == 0 && jogador->light_ic > 0) {
                    aux3 = aux2;
                    aux2->prox = (struct Coordenadas *)malloc(sizeof(struct Coordenadas));
                    aux2 = aux2->prox;
                    aux2->prox = NULL;

                    aux3->x = 240 + i*30;
                    aux3->y = 450;

                    al_draw_bitmap(bmp,240 + i*30,450,0);
                }
                else if(strcmp(aux->card->origem->elemento,"Dark") == 0 && jogador->dark_ic > 0) {
                    aux3 = aux2;
                    aux2->prox = (struct Coordenadas *)malloc(sizeof(struct Coordenadas));
                    aux2 = aux2->prox;
                    aux2->prox = NULL;

                    aux3->x = 240 + i*30;
                    aux3->y = 450;

                    al_draw_bitmap(bmp,240 + i*30,450,0);
                }
                else if(strcmp(aux->card->origem->elemento,"Fire") == 0 && jogador->fire_ic > 0) {
                    aux3 = aux2;
                    aux2->prox = (struct Coordenadas *)malloc(sizeof(struct Coordenadas));
                    aux2 = aux2->prox;
                    aux2->prox = NULL;

                    aux3->x = 240 + i*30;
                    aux3->y = 450;

                    al_draw_bitmap(bmp,240 + i*30,450,0);
                }
                else if(strcmp(aux->card->origem->elemento,"Water") == 0 && jogador->water_ic > 0) {
                    aux3 = aux2;
                    aux2->prox = (struct Coordenadas *)malloc(sizeof(struct Coordenadas));
                    aux2 = aux2->prox;
                    aux2->prox = NULL;

                    aux3->x = 240 + i*30;
                    aux3->y = 450;

                    al_draw_bitmap(bmp,240 + i*30,450,0);
                }
            }
            i++;

            aux = aux->prox;
        }
    }

    else if(modo == 9) {    //ESCOLHER EQUIP (WEAPON,ARMOR,SHIELD)
        aux = jogador->hand->inicio;

        while(aux->prox != NULL) {
            if(aux->card->origem->equip != NULL && (aux->card->origem->equip->level - aux->card->level_drop) <= level && ((strstr(aux->card->origem->str_concat,"Armor") != NULL) || (strstr(aux->card->origem->str_concat,"Weapon") != NULL) || (strstr(aux->card->origem->str_concat,"Shield") != NULL))) {
                if(strcmp(aux->card->origem->elemento,"Earth") == 0 && jogador->earth_ic > 0) {
                    aux3 = aux2;
                    aux2->prox = (struct Coordenadas *)malloc(sizeof(struct Coordenadas));
                    aux2 = aux2->prox;
                    aux2->prox = NULL;

                    aux3->x = 240 + i*30;
                    aux3->y = 450;

                    al_draw_bitmap(bmp,240 + i*30,450,0);
                }
                else if(strcmp(aux->card->origem->elemento,"Wind") == 0 && jogador->wind_ic > 0) {
                    aux3 = aux2;
                    aux2->prox = (struct Coordenadas *)malloc(sizeof(struct Coordenadas));
                    aux2 = aux2->prox;
                    aux2->prox = NULL;

                    aux3->x = 240 + i*30;
                    aux3->y = 450;

                    al_draw_bitmap(bmp,240 + i*30,450,0);
                }
                else if(strcmp(aux->card->origem->elemento,"Light") == 0 && jogador->light_ic > 0) {
                    aux3 = aux2;
                    aux2->prox = (struct Coordenadas *)malloc(sizeof(struct Coordenadas));
                    aux2 = aux2->prox;
                    aux2->prox = NULL;

                    aux3->x = 240 + i*30;
                    aux3->y = 450;

                    al_draw_bitmap(bmp,240 + i*30,450,0);
                }
                else if(strcmp(aux->card->origem->elemento,"Dark") == 0 && jogador->dark_ic > 0) {
                    aux3 = aux2;
                    aux2->prox = (struct Coordenadas *)malloc(sizeof(struct Coordenadas));
                    aux2 = aux2->prox;
                    aux2->prox = NULL;

                    aux3->x = 240 + i*30;
                    aux3->y = 450;

                    al_draw_bitmap(bmp,240 + i*30,450,0);
                }
                else if(strcmp(aux->card->origem->elemento,"Fire") == 0 && jogador->fire_ic > 0) {
                    aux3 = aux2;
                    aux2->prox = (struct Coordenadas *)malloc(sizeof(struct Coordenadas));
                    aux2 = aux2->prox;
                    aux2->prox = NULL;

                    aux3->x = 240 + i*30;
                    aux3->y = 450;

                    al_draw_bitmap(bmp,240 + i*30,450,0);
                }
                else if(strcmp(aux->card->origem->elemento,"Water") == 0 && jogador->water_ic > 0) {
                    aux3 = aux2;
                    aux2->prox = (struct Coordenadas *)malloc(sizeof(struct Coordenadas));
                    aux2 = aux2->prox;
                    aux2->prox = NULL;

                    aux3->x = 240 + i*30;
                    aux3->y = 450;

                    al_draw_bitmap(bmp,240 + i*30,450,0);
                }
            }
            i++;

            aux = aux->prox;
        }
    }

    else if(modo == 10) {    //ESCOLHER MONSTRO APENAS (NAO USADO AINDA...)
        aux = jogador->hand->inicio;

        while(aux->prox!=NULL) {
            if(aux->card->origem->monster!=NULL && (aux->card->origem->monster->level - aux->card->level_drop) <= level) {
                if(strcmp(aux->card->origem->elemento,"Earth") == 0 && jogador->earth_ic > 0) {
                    aux3 = aux2;
                    aux2->prox = (struct Coordenadas *)malloc(sizeof(struct Coordenadas));
                    aux2 = aux2->prox;
                    aux2->prox = NULL;

                    aux3->x = 240 + i*30;
                    aux3->y = 450;

                    al_draw_bitmap(bmp,240 + i*30,450,0);
                }
                else if(strcmp(aux->card->origem->elemento,"Wind") == 0 && jogador->wind_ic > 0) {
                    aux3 = aux2;
                    aux2->prox = (struct Coordenadas *)malloc(sizeof(struct Coordenadas));
                    aux2 = aux2->prox;
                    aux2->prox = NULL;

                    aux3->x = 240 + i*30;
                    aux3->y = 450;

                    al_draw_bitmap(bmp,240 + i*30,450,0);
                }
                else if(strcmp(aux->card->origem->elemento,"Light") == 0 && jogador->light_ic > 0) {
                    aux3 = aux2;
                    aux2->prox = (struct Coordenadas *)malloc(sizeof(struct Coordenadas));
                    aux2 = aux2->prox;
                    aux2->prox = NULL;

                    aux3->x = 240 + i*30;
                    aux3->y = 450;

                    al_draw_bitmap(bmp,240 + i*30,450,0);
                }
                else if(strcmp(aux->card->origem->elemento,"Dark") == 0 && jogador->dark_ic > 0) {
                    aux3 = aux2;
                    aux2->prox = (struct Coordenadas *)malloc(sizeof(struct Coordenadas));
                    aux2 = aux2->prox;
                    aux2->prox = NULL;

                    aux3->x = 240 + i*30;
                    aux3->y = 450;

                    al_draw_bitmap(bmp,240 + i*30,450,0);
                }
                else if(strcmp(aux->card->origem->elemento,"Fire") == 0 && jogador->fire_ic > 0) {
                    aux3 = aux2;
                    aux2->prox = (struct Coordenadas *)malloc(sizeof(struct Coordenadas));
                    aux2 = aux2->prox;
                    aux2->prox = NULL;

                    aux3->x = 240 + i*30;
                    aux3->y = 450;

                    al_draw_bitmap(bmp,240 + i*30,450,0);
                }
                else if(strcmp(aux->card->origem->elemento,"Water") == 0 && jogador->water_ic > 0) {
                    aux3 = aux2;
                    aux2->prox = (struct Coordenadas *)malloc(sizeof(struct Coordenadas));
                    aux2 = aux2->prox;
                    aux2->prox = NULL;

                    aux3->x = 240 + i*30;
                    aux3->y = 450;

                    al_draw_bitmap(bmp,240 + i*30,450,0);
                }
            }
            i++;

            aux = aux->prox;
        }
    }

    else if(modo == 11) {    //ESCOLHER ULTIMO CARD: SCOUT summon
        aux = NULL;
        aux4 = jogador->hand->inicio;
        printf("SCOUT SUMMON ");

        while(aux4->prox!=NULL) {
            i++;
            aux = aux4;
            aux4 = aux4->prox;
        }
        i--;

        printf("1 ");
        if(aux != NULL) {
            if(aux->card->origem->monster != NULL && (aux->card->origem->monster->level - aux->card->level_drop) <= level) {
                if(strcmp(aux->card->origem->elemento,"Earth") == 0 && jogador->earth_ic > 0) {
                    aux3 = aux2;
                    aux2->prox = (struct Coordenadas *)malloc(sizeof(struct Coordenadas));
                    aux2 = aux2->prox;
                    aux2->prox = NULL;

                    aux3->x = 240 + i*30;
                    aux3->y = 450;

                    al_draw_bitmap(bmp,240 + i*30,450,0);
                }
                else if(strcmp(aux->card->origem->elemento,"Wind") == 0 && jogador->wind_ic > 0) {
                    aux3 = aux2;
                    aux2->prox = (struct Coordenadas *)malloc(sizeof(struct Coordenadas));
                    aux2 = aux2->prox;
                    aux2->prox = NULL;

                    aux3->x = 240 + i*30;
                    aux3->y = 450;

                    al_draw_bitmap(bmp,240 + i*30,450,0);
                }
                else if(strcmp(aux->card->origem->elemento,"Light") == 0 && jogador->light_ic > 0) {
                    aux3 = aux2;
                    aux2->prox = (struct Coordenadas *)malloc(sizeof(struct Coordenadas));
                    aux2 = aux2->prox;
                    aux2->prox = NULL;

                    aux3->x = 240 + i*30;
                    aux3->y = 450;

                    al_draw_bitmap(bmp,240 + i*30,450,0);
                }
                else if(strcmp(aux->card->origem->elemento,"Dark") == 0 && jogador->dark_ic > 0) {
                    aux3 = aux2;
                    aux2->prox = (struct Coordenadas *)malloc(sizeof(struct Coordenadas));
                    aux2 = aux2->prox;
                    aux2->prox = NULL;

                    aux3->x = 240 + i*30;
                    aux3->y = 450;

                    al_draw_bitmap(bmp,240 + i*30,450,0);
                }
                else if(strcmp(aux->card->origem->elemento,"Fire") == 0 && jogador->fire_ic > 0) {
                    aux3 = aux2;
                    aux2->prox = (struct Coordenadas *)malloc(sizeof(struct Coordenadas));
                    aux2 = aux2->prox;
                    aux2->prox = NULL;

                    aux3->x = 240 + i*30;
                    aux3->y = 450;

                    al_draw_bitmap(bmp,240 + i*30,450,0);
                }
                else if(strcmp(aux->card->origem->elemento,"Water") == 0 && jogador->water_ic > 0) {
                    aux3 = aux2;
                    aux2->prox = (struct Coordenadas *)malloc(sizeof(struct Coordenadas));
                    aux2 = aux2->prox;
                    aux2->prox = NULL;

                    aux3->x = 240 + i*30;
                    aux3->y = 450;

                    al_draw_bitmap(bmp,240 + i*30,450,0);
                }
            }

            else if(aux->card->origem->jrboss != NULL && (aux->card->origem->jrboss->level - aux->card->level_drop) <= level && !BossPresente(jogador)) {
                if(strcmp(aux->card->origem->elemento,"Earth") == 0 && jogador->earth_ic > 0) {
                    aux3 = aux2;
                    aux2->prox = (struct Coordenadas *)malloc(sizeof(struct Coordenadas));
                    aux2 = aux2->prox;
                    aux2->prox = NULL;

                    aux3->x = 240 + i*30;
                    aux3->y = 450;

                    al_draw_bitmap(bmp,240 + i*30,450,0);
                }
                else if(strcmp(aux->card->origem->elemento,"Wind") == 0 && jogador->wind_ic > 0) {
                    aux3 = aux2;
                    aux2->prox = (struct Coordenadas *)malloc(sizeof(struct Coordenadas));
                    aux2 = aux2->prox;
                    aux2->prox = NULL;

                    aux3->x = 240 + i*30;
                    aux3->y = 450;

                    al_draw_bitmap(bmp,240 + i*30,450,0);
                }
                else if(strcmp(aux->card->origem->elemento,"Light") == 0 && jogador->light_ic > 0) {
                    aux3 = aux2;
                    aux2->prox = (struct Coordenadas *)malloc(sizeof(struct Coordenadas));
                    aux2 = aux2->prox;
                    aux2->prox = NULL;

                    aux3->x = 240 + i*30;
                    aux3->y = 450;

                    al_draw_bitmap(bmp,240 + i*30,450,0);
                }
                else if(strcmp(aux->card->origem->elemento,"Dark") == 0 && jogador->dark_ic > 0) {
                    aux3 = aux2;
                    aux2->prox = (struct Coordenadas *)malloc(sizeof(struct Coordenadas));
                    aux2 = aux2->prox;
                    aux2->prox = NULL;

                    aux3->x = 240 + i*30;
                    aux3->y = 450;

                    al_draw_bitmap(bmp,240 + i*30,450,0);
                }
                else if(strcmp(aux->card->origem->elemento,"Fire") == 0 && jogador->fire_ic > 0) {
                    aux3 = aux2;
                    aux2->prox = (struct Coordenadas *)malloc(sizeof(struct Coordenadas));
                    aux2 = aux2->prox;
                    aux2->prox = NULL;

                    aux3->x = 240 + i*30;
                    aux3->y = 450;

                    al_draw_bitmap(bmp,240 + i*30,450,0);
                }
                else if(strcmp(aux->card->origem->elemento,"Water") == 0 && jogador->water_ic > 0) {
                    aux3 = aux2;
                    aux2->prox = (struct Coordenadas *)malloc(sizeof(struct Coordenadas));
                    aux2 = aux2->prox;
                    aux2->prox = NULL;

                    aux3->x = 240 + i*30;
                    aux3->y = 450;

                    al_draw_bitmap(bmp,240 + i*30,450,0);
                }
            }

            else if(aux->card->origem->boss != NULL && (aux->card->origem->boss->level - aux->card->level_drop) <= level && !BossPresente(jogador)) {
                if(strcmp(aux->card->origem->elemento,"Earth") == 0 && jogador->earth_ic > 0) {
                    aux3 = aux2;
                    aux2->prox = (struct Coordenadas *)malloc(sizeof(struct Coordenadas));
                    aux2 = aux2->prox;
                    aux2->prox = NULL;

                    aux3->x = 240 + i*30;
                    aux3->y = 450;

                    al_draw_bitmap(bmp,240 + i*30,450,0);
                }
                else if(strcmp(aux->card->origem->elemento,"Wind") == 0 && jogador->wind_ic > 0) {
                    aux3 = aux2;
                    aux2->prox = (struct Coordenadas *)malloc(sizeof(struct Coordenadas));
                    aux2 = aux2->prox;
                    aux2->prox = NULL;

                    aux3->x = 240 + i*30;
                    aux3->y = 450;

                    al_draw_bitmap(bmp,240 + i*30,450,0);
                }
                else if(strcmp(aux->card->origem->elemento,"Light") == 0 && jogador->light_ic > 0) {
                    aux3 = aux2;
                    aux2->prox = (struct Coordenadas *)malloc(sizeof(struct Coordenadas));
                    aux2 = aux2->prox;
                    aux2->prox = NULL;

                    aux3->x = 240 + i*30;
                    aux3->y = 450;

                    al_draw_bitmap(bmp,240 + i*30,450,0);
                }
                else if(strcmp(aux->card->origem->elemento,"Dark") == 0 && jogador->dark_ic > 0) {
                    aux3 = aux2;
                    aux2->prox = (struct Coordenadas *)malloc(sizeof(struct Coordenadas));
                    aux2 = aux2->prox;
                    aux2->prox = NULL;

                    aux3->x = 240 + i*30;
                    aux3->y = 450;

                    al_draw_bitmap(bmp,240 + i*30,450,0);
                }
                else if(strcmp(aux->card->origem->elemento,"Fire") == 0 && jogador->fire_ic > 0) {
                    aux3 = aux2;
                    aux2->prox = (struct Coordenadas *)malloc(sizeof(struct Coordenadas));
                    aux2 = aux2->prox;
                    aux2->prox = NULL;

                    aux3->x = 240 + i*30;
                    aux3->y = 450;

                    al_draw_bitmap(bmp,240 + i*30,450,0);
                }
                else if(strcmp(aux->card->origem->elemento,"Water") == 0 && jogador->water_ic > 0) {
                    aux3 = aux2;
                    aux2->prox = (struct Coordenadas *)malloc(sizeof(struct Coordenadas));
                    aux2 = aux2->prox;
                    aux2->prox = NULL;

                    aux3->x = 240 + i*30;
                    aux3->y = 450;

                    al_draw_bitmap(bmp,240 + i*30,450,0);
                }
            }
        }
        printf("OK\n");
    }

    else if(modo == 12) {    //ESCOLHER PRIMEIRO FIELD CARD
        aux = jogador->hand->inicio;

        if(aux->card->origem->field != NULL) {
            if(strcmp(aux->card->origem->elemento,"Earth") == 0 && jogador->earth_ic > 0) {
                aux3 = aux2;
                aux2->prox = (struct Coordenadas *)malloc(sizeof(struct Coordenadas));
                aux2 = aux2->prox;
                aux2->prox = NULL;

                aux3->x = 240 + i*30;
                aux3->y = 450;

                al_draw_bitmap(bmp,240 + i*30,450,0);
            }
            else if(strcmp(aux->card->origem->elemento,"Wind") == 0 && jogador->wind_ic > 0) {
                aux3 = aux2;
                aux2->prox = (struct Coordenadas *)malloc(sizeof(struct Coordenadas));
                aux2 = aux2->prox;
                aux2->prox = NULL;

                aux3->x = 240 + i*30;
                aux3->y = 450;

                al_draw_bitmap(bmp,240 + i*30,450,0);
            }
            else if(strcmp(aux->card->origem->elemento,"Light") == 0 && jogador->light_ic > 0) {
                aux3 = aux2;
                aux2->prox = (struct Coordenadas *)malloc(sizeof(struct Coordenadas));
                aux2 = aux2->prox;
                aux2->prox = NULL;

                aux3->x = 240 + i*30;
                aux3->y = 450;

                al_draw_bitmap(bmp,240 + i*30,450,0);
            }
            else if(strcmp(aux->card->origem->elemento,"Dark") == 0 && jogador->dark_ic > 0) {
                aux3 = aux2;
                aux2->prox = (struct Coordenadas *)malloc(sizeof(struct Coordenadas));
                aux2 = aux2->prox;
                aux2->prox = NULL;

                aux3->x = 240 + i*30;
                aux3->y = 450;

                al_draw_bitmap(bmp,240 + i*30,450,0);
            }
            else if(strcmp(aux->card->origem->elemento,"Fire") == 0 && jogador->fire_ic > 0) {
                aux3 = aux2;
                aux2->prox = (struct Coordenadas *)malloc(sizeof(struct Coordenadas));
                aux2 = aux2->prox;
                aux2->prox = NULL;

                aux3->x = 240 + i*30;
                aux3->y = 450;

                al_draw_bitmap(bmp,240 + i*30,450,0);
            }
            else if(strcmp(aux->card->origem->elemento,"Water") == 0 && jogador->water_ic > 0) {
                aux3 = aux2;
                aux2->prox = (struct Coordenadas *)malloc(sizeof(struct Coordenadas));
                aux2 = aux2->prox;
                aux2->prox = NULL;

                aux3->x = 240 + i*30;
                aux3->y = 450;

                al_draw_bitmap(bmp,240 + i*30,450,0);
            }
        }
    }

    /*aux2 = lista;
    printf("LISTA:\n");
    while(aux2->prox != NULL) {
        printf("%d %d\n",aux2->x,aux2->y);
        aux2 = aux2->prox;
    }
    printf("--------------------\n");*/
}

void Desenha_MS_contador(struct CARD *mirror_shield,ALLEGRO_FONT *font,int x,int y) {
    if(mirror_shield->var_equip->mirror_shield_cont == 1) al_draw_textf(font,al_map_rgb(30,144,255), x + 22, y + 60, 0,"%d", mirror_shield->var_equip->mirror_shield_dmg);
    else if(mirror_shield->var_equip->mirror_shield_cont == 2) al_draw_textf(font,al_map_rgb(184,134,11), x + 22, y + 60, 0,"%d", mirror_shield->var_equip->mirror_shield_dmg);
    else al_draw_textf(font,al_map_rgb(178,34,34), x + 22, y + 60, 0,"%d", mirror_shield->var_equip->mirror_shield_dmg);
}

//GRAVEYARD deveria atuar como uma PILHA, nao uma LISTA!
void AtualizaMesa(bool refresh,char *texto,int hab_atual,int modo,int level,struct Card **buffer,bool *fim_de_jogo,struct StatusBox_bitmaps *sbox,ALLEGRO_BITMAP *prompt,ALLEGRO_BITMAP *selecao,ALLEGRO_BITMAP *roll_bar,ALLEGRO_BITMAP *fundo_carta,ALLEGRO_BITMAP *fundo_menu,ALLEGRO_BITMAP *deck_meio,ALLEGRO_BITMAP *deck_cheio,ALLEGRO_BITMAP *fundo,ALLEGRO_BITMAP *pont,struct Player *jogador,struct Player *adversario,ALLEGRO_DISPLAY *display,ALLEGRO_FONT *font,ALLEGRO_FONT *font2,ALLEGRO_COLOR color,bool *sair,int *posX,int *posY,int *dltZ,bool *mouse1,bool *mouse2,bool *mouse_lado,int *keychar,bool *repete_keychar,ALLEGRO_EVENT_QUEUE *event_queue,ALLEGRO_TIMER *keyb_press_timer,ALLEGRO_TIMER *mouse_press_timer,int *rolagem,struct Coordenadas *lista,int elemento_ataque,int origem_ataque,int restricoes,int ataque_gerado,int *defesa_gerada, struct CARD *atacante) {
    /*
    ORIGEM ATAQUE:
        0- Monster
        1- Character Action
        2- Tactic
        3- Equip

    RESTRICOES:
        0- Sem limites
        1- Nao atinge characters
        2- Nao atinge monstros
        3- Atinge SLOT FIXO


    MODO (tipos de card a serem listados):
        0- ATTACK MONSTER & CHARACTER (atuando com restricoes)
        1- ATTACK EQUIPMENT
        2- LEVEL-UP CARD
        3- ESCOLHER MONSTRO, JR. BOSS E BOSS
        4- ESCOLHER EQUIP
        5- ESCOLHER FIELD
        6- ESCOLHER TACTIC
        7- ESCOLHER JR.BOSS
        8- ESCOLHER BOSS
        9- ESCOLHER EQUIP (WEAPON,ARMOR,SHIELD)
        10- ESCOLHER MONSTRO APENAS
        11- SCOUT spawn
    */

    struct Deck* aux;
    struct Mesa *player;
    struct Coordenadas *aux2;
    Acao acao1,acao2;
    int i = 0,cont;
    char *tok;

    al_draw_bitmap(fundo,0,0,0);
    //printf("ATUALIZA ");
    i = jogador->deck->quantidade;
    if(i>0 && i<=15) al_draw_scaled_bitmap(deck_meio,0,0,240,360,700,440,100,150,0);
    else if(i>15) al_draw_scaled_bitmap(deck_cheio,0,0,240,360,700,440,100,150,0);
    al_draw_textf(font2,color,740,570,0,"%d",jogador->deck->quantidade);

    i = adversario->deck->quantidade;
    if(i>0 && i<=15) al_draw_scaled_bitmap(deck_meio,0,0,240,360,745,30,50,75,0);
    else if(i>15) al_draw_scaled_bitmap(deck_cheio,0,0,240,360,745,30,50,75,0);
    al_draw_textf(font2,color,760,90,0,"%d",adversario->deck->quantidade);
    //printf("1 ");

    if(jogador->graveyard->inicio->prox != NULL) al_draw_scaled_bitmap(jogador->graveyard->inicio->card->origem->bmp,0,0,240,360,745,365,50,75,0);
    if(adversario->graveyard->inicio->prox != NULL) al_draw_scaled_bitmap(adversario->graveyard->inicio->card->origem->bmp,0,0,240,360,745,115,50,75,0);

    al_draw_textf(font2,color,700,50,0,"%d",adversario->level);
    al_draw_textf(font2,color,700,75,0,"%d / %d",*(adversario->HP),*(adversario->MaxHP));

    al_draw_textf(font,color,600,485,0,"%d",jogador->level);
    al_draw_textf(font,color,600,540,0,"%d / %d",*(jogador->HP),*(jogador->MaxHP));

    al_draw_textf(font2,color,620,35,0,"PLAYER hand: %d",jogador->hand->quantidade);
    al_draw_textf(font2,color,620,65,0,"ADVSRY hand: %d",adversario->hand->quantidade);

    //printf("2 ");
    player = adversario->mesa;
    player->character->PosicaoX = 685;
    player->character->PosicaoY = 110;

    if(player->equip1 != NULL) {
        al_draw_scaled_bitmap(player->equip1->origem->bmp,0,0,240,360,300,110,50,75,0);
        player->equip1->PosicaoX = 300;
        player->equip1->PosicaoY = 110;

        if(player->equip1->qte_associado != 0) al_draw_textf(font2,color, 300 + 22, 110 + 60, 0,"%d", player->equip1->qte_associado);
        else if(player->equip1->var_equip->mirror_shield_cont > 0) Desenha_MS_contador(player->equip1,font2,300,110);
    }
    if(player->equip2 != NULL) {
        al_draw_scaled_bitmap(player->equip2->origem->bmp,0,0,240,360,355,110,50,75,0);
        player->equip2->PosicaoX = 355;
        player->equip2->PosicaoY = 110;

        if(player->equip2->qte_associado != 0) al_draw_textf(font2,color, 355 + 22, 110 + 60, 0,"%d", player->equip2->qte_associado);
        else if(player->equip2->var_equip->mirror_shield_cont > 0) Desenha_MS_contador(player->equip2,font2,355,110);
    }
    if(player->equip3 != NULL) {
        al_draw_scaled_bitmap(player->equip3->origem->bmp,0,0,240,360,410,110,50,75,0);
        player->equip3->PosicaoX = 410;
        player->equip3->PosicaoY = 110;

        if(player->equip3->qte_associado != 0) al_draw_textf(font2,color, 410 + 22, 110 + 60, 0,"%d", player->equip3->qte_associado);
        else if(player->equip3->var_equip->mirror_shield_cont > 0) Desenha_MS_contador(player->equip3,font2,410,110);
    }
    if(player->equip4 != NULL) {
        al_draw_scaled_bitmap(player->equip4->origem->bmp,0,0,240,360,465,110,50,75,0);
        player->equip4->PosicaoX = 465;
        player->equip4->PosicaoY = 110;

        if(player->equip4->qte_associado != 0) al_draw_textf(font2,color, 465 + 22, 110 + 60, 0,"%d", player->equip4->qte_associado);
        else if(player->equip4->var_equip->mirror_shield_cont > 0) Desenha_MS_contador(player->equip4,font2,465,110);
    }
    if(player->equip5 != NULL) {
        al_draw_scaled_bitmap(player->equip5->origem->bmp,0,0,240,360,520,110,50,75,0);
        player->equip5->PosicaoX = 520;
        player->equip5->PosicaoY = 110;

        if(player->equip5->qte_associado != 0) al_draw_textf(font2,color, 520 + 22, 110 + 60, 0,"%d", player->equip5->qte_associado);
        else if(player->equip5->var_equip->mirror_shield_cont > 0) Desenha_MS_contador(player->equip5,font2,520,110);
    }
    if(player->equip6 != NULL) {
        al_draw_scaled_bitmap(player->equip6->origem->bmp,0,0,240,360,575,110,50,75,0);
        player->equip6->PosicaoX = 575;
        player->equip6->PosicaoY = 110;

        if(player->equip6->qte_associado != 0) al_draw_textf(font2,color, 575 + 22, 110 + 60, 0,"%d", player->equip6->qte_associado);
        else if(player->equip6->var_equip->mirror_shield_cont > 0) Desenha_MS_contador(player->equip6,font2,575,110);
    }
    if(player->equip7 != NULL) {
        al_draw_scaled_bitmap(player->equip7->origem->bmp,0,0,240,360,630,110,50,75,0);
        player->equip7->PosicaoX = 630;
        player->equip7->PosicaoY = 110;

        if(player->equip7->qte_associado != 0) al_draw_textf(font2,color, 630 + 22, 110 + 60, 0,"%d", player->equip7->qte_associado);
        else if(player->equip7->var_equip->mirror_shield_cont > 0) Desenha_MS_contador(player->equip7,font2,630,110);
    }
    if(player->monstro1 != NULL) {
        al_draw_scaled_bitmap(player->monstro1->origem->bmp,0,0,240,360,300,190,50,75,0);
        player->monstro1->PosicaoX = 300;
        player->monstro1->PosicaoY = 190;

        //if(player->monstro1->qte_associado != 0) al_draw_textf(font,color, 300 + 20, 190 + 55, 0,"%s", player->monstro1->qte_associado);
    }
    if(player->monstro2 != NULL) {
        al_draw_scaled_bitmap(player->monstro2->origem->bmp,0,0,240,360,355,190,50,75,0);
        player->monstro2->PosicaoX = 355;
        player->monstro2->PosicaoY = 190;

        //if(player->monstro2->qte_associado != 0) al_draw_textf(font,color, 355 + 20, 190 + 55, 0,"%s", player->monstro2->qte_associado);
    }
    if(player->monstro3 != NULL) {
        al_draw_scaled_bitmap(player->monstro3->origem->bmp,0,0,240,360,410,190,50,75,0);
        player->monstro3->PosicaoX = 410;
        player->monstro3->PosicaoY = 190;

        //if(player->monstro3->qte_associado != 0) al_draw_textf(font,color, 410 + 20, 190 + 55, 0,"%s", player->monstro3->qte_associado);
    }
    if(player->monstro4 != NULL) {
        al_draw_scaled_bitmap(player->monstro4->origem->bmp,0,0,240,360,465,190,50,75,0);
        player->monstro4->PosicaoX = 465;
        player->monstro4->PosicaoY = 190;

        //if(player->monstro4->qte_associado != 0) al_draw_textf(font,color, 465 + 20, 190 + 55, 0,"%s", player->monstro4->qte_associado);
    }
    if(player->monstro5 != NULL) {
        al_draw_scaled_bitmap(player->monstro5->origem->bmp,0,0,240,360,520,190,50,75,0);
        player->monstro5->PosicaoX = 520;
        player->monstro5->PosicaoY = 190;

        //if(player->monstro5->qte_associado != 0) al_draw_textf(font,color, 520 + 20, 190 + 55, 0,"%s", player->monstro5->qte_associado);
    }
    if(player->monstro6 != NULL) {
        al_draw_scaled_bitmap(player->monstro6->origem->bmp,0,0,240,360,575,190,50,75,0);
        player->monstro6->PosicaoX = 575;
        player->monstro6->PosicaoY = 190;

        //if(player->monstro6->qte_associado != 0) al_draw_textf(font,color, 575 + 20, 190 + 55, 0,"%s", player->monstro6->qte_associado);
    }
    if(player->monstro7 != NULL) {
        al_draw_scaled_bitmap(player->monstro7->origem->bmp,0,0,240,360,630,190,50,75,0);
        player->monstro7->PosicaoX = 630;
        player->monstro7->PosicaoY = 190;

        //if(player->monstro7->qte_associado != 0) al_draw_textf(font,color, 630 + 20, 190 + 55, 0,"%s", player->monstro7->qte_associado);
    }
    if(player->field != NULL) {
        al_draw_scaled_bitmap(player->field->origem->bmp,0,0,240,360,745,195,50,75,0);
        player->field->PosicaoX = 745;
        player->field->PosicaoY = 195;
    }
    //printf("3 ");

    player = jogador->mesa;
    player->character->PosicaoX = 245;
    player->character->PosicaoY = 110;

    if(player->equip1 != NULL) {
        al_draw_scaled_bitmap(player->equip1->origem->bmp,0,0,240,360,300,350,50,75,0);
        player->equip1->PosicaoX = 300;
        player->equip1->PosicaoY = 350;

        if(player->equip1->qte_associado != 0) al_draw_textf(font2,color, 300 + 22, 350 + 60, 0,"%d", player->equip1->qte_associado);
        else if(player->equip1->origem->colecao == IRON_BOOTS && jogador->var_tactic->iron_boots_cont > 0) al_draw_textf(font2,color, 300 + 22, 350 + 60, 0,"%d", jogador->var_tactic->iron_boots_cont);
        else if(player->equip1->var_equip->mirror_shield_cont > 0) Desenha_MS_contador(player->equip1,font2,300,350);
    }

    if(player->equip2 != NULL) {
        al_draw_scaled_bitmap(player->equip2->origem->bmp,0,0,240,360,355,350,50,75,0);
        player->equip2->PosicaoX = 355;
        player->equip2->PosicaoY = 350;

        if(player->equip2->qte_associado != 0) al_draw_textf(font2,color, 355 + 22, 350 + 60, 0,"%d", player->equip2->qte_associado);
        else if(player->equip2->var_equip->mirror_shield_cont > 0) Desenha_MS_contador(player->equip2,font2,355,350);
    }
    if(player->equip3 != NULL) {
        al_draw_scaled_bitmap(player->equip3->origem->bmp,0,0,240,360,410,350,50,75,0);
        player->equip3->PosicaoX = 410;
        player->equip3->PosicaoY = 350;

        if(player->equip3->qte_associado != 0) al_draw_textf(font2,color, 410 + 22, 350 + 60, 0,"%d", player->equip3->qte_associado);
        else if(player->equip3->var_equip->mirror_shield_cont > 0) Desenha_MS_contador(player->equip3,font2,410,350);
    }
    if(player->equip4 != NULL) {
        al_draw_scaled_bitmap(player->equip4->origem->bmp,0,0,240,360,465,350,50,75,0);
        player->equip4->PosicaoX = 465;
        player->equip4->PosicaoY = 350;

        if(player->equip4->qte_associado != 0) al_draw_textf(font2,color, 465 + 22, 350 + 60, 0,"%d", player->equip4->qte_associado);
        else if(player->equip4->var_equip->mirror_shield_cont > 0) Desenha_MS_contador(player->equip4,font2,465,350);
    }
    if(player->equip5 != NULL) {
        al_draw_scaled_bitmap(player->equip5->origem->bmp,0,0,240,360,520,350,50,75,0);
        player->equip5->PosicaoX = 520;
        player->equip5->PosicaoY = 350;

        if(player->equip5->qte_associado != 0) al_draw_textf(font2,color, 520 + 22, 350 + 60, 0,"%d", player->equip5->qte_associado);
        else if(player->equip5->var_equip->mirror_shield_cont > 0) Desenha_MS_contador(player->equip5,font2,520,350);
    }
    if(player->equip6 != NULL) {
        al_draw_scaled_bitmap(player->equip6->origem->bmp,0,0,240,360,575,350,50,75,0);
        player->equip6->PosicaoX = 575;
        player->equip6->PosicaoY = 350;

        if(player->equip6->qte_associado != 0) al_draw_textf(font2,color, 575 + 22, 350 + 60, 0,"%d", player->equip6->qte_associado);
        else if(player->equip6->var_equip->mirror_shield_cont > 0) Desenha_MS_contador(player->equip6,font2,575,350);
    }
    if(player->equip7 != NULL) {
        al_draw_scaled_bitmap(player->equip7->origem->bmp,0,0,240,360,630,350,50,75,0);
        player->equip7->PosicaoX = 630;
        player->equip7->PosicaoY = 350;

        if(player->equip7->qte_associado != 0) al_draw_textf(font2,color, 630 + 22, 350 + 60, 0,"%d", player->equip7->qte_associado);
        else if(player->equip7->var_equip->mirror_shield_cont > 0) Desenha_MS_contador(player->equip7,font2,630,350);
    }
    if(player->monstro1 != NULL) {
        al_draw_scaled_bitmap(player->monstro1->origem->bmp,0,0,240,360,300,270,50,75,0);
        player->monstro1->PosicaoX = 300;
        player->monstro1->PosicaoY = 270;

        //if(player->monstro1->qte_associado != 0) al_draw_textf(font,color, 300 + 20, 270 + 55, 0,"%s", player->monstro1->qte_associado);
    }
    if(player->monstro2 != NULL) {
        al_draw_scaled_bitmap(player->monstro2->origem->bmp,0,0,240,360,355,270,50,75,0);
        player->monstro2->PosicaoX = 355;
        player->monstro2->PosicaoY = 270;

        //if(player->monstro2->qte_associado != 0) al_draw_textf(font,color, 355 + 20, 270 + 55, 0,"%s", player->monstro2->qte_associado);
    }
    if(player->monstro3 != NULL) {
        al_draw_scaled_bitmap(player->monstro3->origem->bmp,0,0,240,360,410,270,50,75,0);
        player->monstro3->PosicaoX = 410;
        player->monstro3->PosicaoY = 270;

        //if(player->monstro3->qte_associado != 0) al_draw_textf(font,color, 410 + 20, 270 + 55, 0,"%s", player->monstro3->qte_associado);
    }
    if(player->monstro4 != NULL) {
        al_draw_scaled_bitmap(player->monstro4->origem->bmp,0,0,240,360,465,270,50,75,0);
        player->monstro4->PosicaoX = 465;
        player->monstro4->PosicaoY = 270;

        //if(player->monstro4->qte_associado != 0) al_draw_textf(font,color, 465 + 20, 270 + 55, 0,"%s", player->monstro4->qte_associado);
    }
    if(player->monstro5 != NULL) {
        al_draw_scaled_bitmap(player->monstro5->origem->bmp,0,0,240,360,520,270,50,75,0);
        player->monstro5->PosicaoX = 520;
        player->monstro5->PosicaoY = 270;

        //if(player->monstro5->qte_associado != 0) al_draw_textf(font,color, 520 + 20, 270 + 55, 0,"%s", player->monstro5->qte_associado);
    }
    if(player->monstro6 != NULL) {
        al_draw_scaled_bitmap(player->monstro6->origem->bmp,0,0,240,360,575,270,50,75,0);
        player->monstro6->PosicaoX = 575;
        player->monstro6->PosicaoY = 270;

        //if(player->monstro6->qte_associado != 0) al_draw_textf(font,color, 575 + 20, 270 + 55, 0,"%s", player->monstro6->qte_associado);
    }
    if(player->monstro7 != NULL) {
        al_draw_scaled_bitmap(player->monstro7->origem->bmp,0,0,240,360,630,270,50,75,0);
        player->monstro7->PosicaoX = 630;
        player->monstro7->PosicaoY = 270;

        //if(player->monstro7->qte_associado != 0) al_draw_textf(font,color, 630 + 20, 270 + 55, 0,"%s", player->monstro7->qte_associado);
    }
    if(player->field != NULL) {
        al_draw_scaled_bitmap(player->field->origem->bmp,0,0,240,360,745,285,50,75,0);
        player->field->PosicaoX = 745;
        player->field->PosicaoY = 285;
    }
    //printf("4 ");

    i = 0;    //character area
    acao1 = jogador->character_actions->prox->prox;
    while(acao1->prox != NULL && i < 13) {
        acao2 = acao1;
        acao1 = acao1->prox;
        i++;
    }
    i--;

    //printf("5 ");
    while(1) {
        al_draw_scaled_bitmap(acao2->card->origem->bmp,0,0,240,360,245,110 + 20*i,50,75,0);
        acao2->card->PosicaoX = 245;
        acao2->card->PosicaoY = 110 + 20*i;
        i--;
        if(acao2->ant == NULL) break;
        acao2 = acao2->ant;
    }
    //printf("6 ");

    i = 0;
    acao1 = adversario->character_actions->prox->prox;
    while(acao1->prox != NULL && i < 13) {
        acao2 = acao1;
        acao1 = acao1->prox;
        i++;
    }
    i--;

    //printf("7 ");
    while(1) {
        al_draw_scaled_bitmap(acao2->card->origem->bmp,0,0,240,360,685,110 + 20*i,50,75,0);
        acao2->card->PosicaoX = 685;
        acao2->card->PosicaoY = 110 + 20*i;
        i--;
        if(acao2->ant == NULL) break;
        acao2 = acao2->ant;
    }

    //printf("8 ");
    i = 0;
    cont = adversario->hand->quantidade;
    while(i < cont) {
        al_draw_scaled_bitmap(fundo_carta,0,0,240,360,240 + 30*i,30,50,75,0);
        i++;
    }

    i = 0;
    aux = jogador->hand->inicio;
    while(aux->prox!=NULL) {
        al_draw_scaled_bitmap(aux->card->origem->bmp,0,0,240,360,240 + 30*i,450,100,150,0);
        aux->card->PosicaoX = 240 + 30*i;
        aux->card->PosicaoY = 450;
        aux = aux->prox;

        i++;
    }

    //printf("9 ");
    al_draw_scaled_bitmap(selecao,0,0,240,360,240,425,455,25,0);
    if(texto != NULL) {
        if(texto[0] == '#') {
            tok = (char *)malloc(3*sizeof(char));
            tok[0] = texto[1];
            tok[1] = texto[2];
            tok[2] = '\0';

            for(i = 3;i < strlen(texto) + 1;i++)
                texto[i - 3] = texto[i];

            free(tok);
        }

        al_draw_textf(font,color,245,430,0,texto);
    }
    //printf("10 ");

    if(modo != -1 && lista != NULL && lista->prox == NULL) {
        IdentificaCard(buffer,fim_de_jogo,roll_bar,fundo_carta,deck_meio,deck_cheio,fundo,font,color,rolagem,sair,posX,posY,dltZ,mouse1,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer,elemento_ataque,origem_ataque,restricoes,jogador,adversario,level,display,pont,modo,lista);
    }
    else if(lista != NULL) {
        aux2 = lista;
        while(aux2->prox != NULL) {
            al_draw_bitmap(pont,aux2->x,aux2->y,0);
            aux2 = aux2->prox;
        }
    }

    if(hab_atual != -1 && hab_atual < 15) {
        if(hab_atual > 2) al_draw_tinted_bitmap_region(selecao, al_map_rgba_f(0.7, 0.7, 0.7, 0.7), 155, 110, 50, 20, 245, 185 + 20*(hab_atual - 3), 0);
        else al_draw_tinted_bitmap_region(selecao, al_map_rgba_f(0.7, 0.7, 0.7, 0.7), 155, 110, 50, 10, 245, 150 + 10*hab_atual, 0);

        //printf("ACAO BUSCADA! ");
    }
    //printf("11 ");

    if(atacante != NULL && atacante->origem->tactic == NULL) {
        al_draw_tinted_rotated_bitmap(sbox->offense_icon,al_map_rgba_f(0.8,0.8,0.8,0.8), 0, 0, atacante->PosicaoX - 2, atacante->PosicaoY + 40, -ALLEGRO_PI/4, 0);
    }

    DestacaCard(buffer,fim_de_jogo,jogador,adversario,sbox,lista,prompt,fundo_carta,fundo_menu,fundo,selecao,roll_bar,display,font,font2,color,sair,posX,posY,dltZ,mouse1,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer,rolagem,ataque_gerado,defesa_gerada);
    //printf("12 ");

    if(mouse1 != NULL) al_draw_textf(font2,color,640,580,0,"(%d , %d)",*posX,*posY);
    if((*(jogador->HP) == 0 || *(adversario->HP) == 0) || (*mouse1 == true && *posX >= 240 && *posX < 240 + 70 && *posY >= 0 && *posY < 0 + 30 && promptSair(fim_de_jogo,prompt,color,display,jogador,sair,posX,posY,dltZ,mouse1,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer))) *fim_de_jogo = true;

    if(refresh == true) al_flip_display();
    //printf("OK\n");
}

bool RefreshHP(int id_acao,struct Card **buffer,struct CARD *card,int HP,bool *fim_de_jogo,int *rolagem,struct StatusBox_bitmaps *sbox,ALLEGRO_BITMAP *prompt,ALLEGRO_BITMAP *selecao,ALLEGRO_BITMAP *roll_bar,ALLEGRO_BITMAP *fundo_carta,ALLEGRO_BITMAP *fundo_menu,ALLEGRO_BITMAP *deck_meio,ALLEGRO_BITMAP *deck_cheio,ALLEGRO_BITMAP *pont,struct Player *jogador,struct Player *adversario,ALLEGRO_DISPLAY *display,ALLEGRO_BITMAP *fundo,ALLEGRO_FONT *font,ALLEGRO_FONT *font2,ALLEGRO_COLOR color,bool *sair,int *posX,int *posY,int *dltZ,bool *mouse1,bool *mouse2,bool *mouse_lado,int *keychar,bool *repete_keychar,ALLEGRO_EVENT_QUEUE *event_queue,ALLEGRO_TIMER *keyb_press_timer,ALLEGRO_TIMER *mouse_press_timer) {
    card->HP += HP;
    if(card->HP > card->MaxHP) card->HP = card->MaxHP;

    AtualizaMesa(true,"Healing...",id_acao,-1,0,buffer,fim_de_jogo,sbox,prompt,selecao,roll_bar,fundo_carta,fundo_menu,deck_meio,deck_cheio,fundo,pont,jogador,adversario,display,font,font2,color,sair,posX,posY,dltZ,mouse1,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer,rolagem,NULL,-1,-1,0,-1,NULL,NULL);
    printf("Healing '%s' for %d HP.\n",card->origem->nome,HP);
    //al_rest(0.2);
    return(true);
}

void WithdrawCharacter(int id_acao,struct Card **buffer,bool *fim_de_jogo,int *rolagem,struct StatusBox_bitmaps *sbox,ALLEGRO_BITMAP *prompt,ALLEGRO_BITMAP *selecao,ALLEGRO_BITMAP *roll_bar,ALLEGRO_BITMAP *fundo_carta,ALLEGRO_BITMAP *fundo_menu,ALLEGRO_BITMAP *deck_meio,ALLEGRO_BITMAP *deck_cheio,ALLEGRO_BITMAP *pont,struct Player *jogador,struct Player *adversario,ALLEGRO_DISPLAY *display,ALLEGRO_BITMAP *fundo,ALLEGRO_FONT *font,ALLEGRO_FONT *font2,ALLEGRO_COLOR color,bool *sair,int *posX,int *posY,int *dltZ,bool *mouse1,bool *mouse2,bool *mouse_lado,int *keychar,bool *repete_keychar,ALLEGRO_EVENT_QUEUE *event_queue,ALLEGRO_TIMER *keyb_press_timer,ALLEGRO_TIMER *mouse_press_timer) {
    RefreshHP(id_acao,buffer,jogador->mesa->character,60,fim_de_jogo,rolagem,sbox,prompt,selecao,roll_bar,fundo_carta,fundo_menu,deck_meio,deck_cheio,pont,jogador,adversario,display,fundo,font,font2,color,sair,posX,posY,dltZ,mouse1,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);
    jogador->turn_away += 1;
    jogador->var_tactic->char_withdrawal_cont += 1;
}

void ArranjaOrdem_CardInfo(int dist,struct Card **buffer,struct CARD **vetor,bool *clique,int *temp,int pagina) {
    struct CARD *temporario;

    if(*clique == true) {
        //al_rest(0.2);
        if(*temp == -1) {
            *temp = 12*(pagina-1) + dist;
        }
        else {
            temporario = vetor[12*(pagina-1) + dist];
            vetor[12*(pagina-1) + dist] = vetor[*temp];
            vetor[*temp] = temporario;
            *temp = -1;
        }
    }
    else {
        al_draw_bitmap(vetor[12*(pagina-1) + dist]->origem->bmp,0,0,0);
        *buffer = vetor[12*(pagina-1) + dist]->origem;
    }
}

void ArranjaOrdem(int id_acao,struct Deck *menu,struct Card **buffer,bool *fim_de_jogo,struct StatusBox_bitmaps *sbox,ALLEGRO_BITMAP *selecao,ALLEGRO_BITMAP *roll_bar,ALLEGRO_BITMAP *fundo_menu,ALLEGRO_BITMAP *prompt,ALLEGRO_BITMAP *fundo_carta,ALLEGRO_BITMAP *deck_meio,ALLEGRO_BITMAP *deck_cheio,ALLEGRO_BITMAP *fundo,ALLEGRO_BITMAP *pont,struct Player *jogador,struct Player *adversario,ALLEGRO_DISPLAY *display,ALLEGRO_FONT *font,ALLEGRO_FONT *font2,ALLEGRO_COLOR color,int *rolagem,bool *sair,int *posX,int *posY,int *dltZ,bool *mouse1,bool *mouse2,bool *mouse_lado,int *keychar,bool *repete_keychar,ALLEGRO_EVENT_QUEUE *event_queue,ALLEGRO_TIMER *keyb_press_timer,ALLEGRO_TIMER *mouse_press_timer) {
    int i = 0,pagina = 1,j,cont = 0,temp = -1;  //arranja a ORDEM de um conjunto de cards de acordo com a opcao do jogador.
    int valor;
    struct CARD **vetor;
    struct Deck *aux;
    ALLEGRO_FONT *text;
    ALLEGRO_BITMAP *tmp;

    //al_rest(0.1);
    text = al_load_ttf_font("data/triforce.ttf",10,0);
    printf("Arranja ordem ");
    if(menu == NULL || menu->prox == NULL) return;

    aux = menu;
    while(aux->prox != NULL) {
        aux = aux->prox;
        i++;
    }
    printf("de %d cards\n",i);
    vetor = (struct CARD **)malloc(i*sizeof(struct CARD *));

    i = 0;
    aux = menu;
    while(aux->prox != NULL) {
        vetor[i] = aux->card;
        aux = aux->prox;
        i++;
    }

    if(i % 12 > 0) valor = 1;
    else valor = 0;

    *buffer = NULL;
    AtualizaMesa(true,NULL,id_acao,-1,0,buffer,fim_de_jogo,sbox,prompt,selecao,roll_bar,fundo_carta,fundo_menu,deck_meio,deck_cheio,fundo,pont,jogador,adversario,display,font,font2,color,sair,posX,posY,dltZ,mouse1,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer,rolagem,NULL,-1,-1,0,-1,NULL,NULL);
    tmp = al_clone_bitmap(al_get_backbuffer(display));

    //printf("ja vai... ");
    while(1) {
        al_clear_to_color(al_map_rgb_f(0, 0, 0));
        al_draw_tinted_bitmap(tmp, al_map_rgba_f(0.3, 0.3, 0.3, 0.3),0, 0, 0);
        al_draw_bitmap_region(fundo,0,0,240,600,0,0,0);

        al_draw_scaled_bitmap(selecao,0,0,240,360,240,550,455,25,0);
        al_draw_text(text,color,250,550,0,"Define ORDER of cards...");

        al_draw_bitmap(fundo_menu,240,70,0);

        VerificaEventos(sair,posX,posY,dltZ,mouse1,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);
        //printf("1 ");

        if(*mouse2 == true || (*mouse1 == true && *posX >= 725 && *posX < 725 + 45 && *posY >= 490 && *posY < 490 + 45)) break;

        else if(*mouse1 == true && pagina+1 <= i/12 + valor && *posX >= 725 && *posX < 770 && *posY >= 85 && *posY < 130) {
            //al_rest(0.2);
            pagina++;
        }
        else if (*mouse1 == true && pagina > 1 && *posX >= 725 && *posX < 770 && *posY >= 145 && *posY < 190) {
            //al_rest(0.2);
            pagina--;
        }

        else if(*posX >= 240 && *posX < 340 && *posY >= 70 && *posY < 220) {
            ArranjaOrdem_CardInfo(0,buffer,vetor,mouse1,&temp,pagina);
        }

        else if(cont > 1 && *posX >= 365 && *posX < 465 && *posY >= 70 && *posY < 220) {
            ArranjaOrdem_CardInfo(1,buffer,vetor,mouse1,&temp,pagina);
        }

        else if(cont > 2 && *posX >= 490 && *posX < 590 && *posY >= 70 && *posY < 220) {
            ArranjaOrdem_CardInfo(2,buffer,vetor,mouse1,&temp,pagina);
        }

        else if(cont > 3 && *posX >= 615 && *posX < 715 && *posY >= 70 && *posY < 220) {
            ArranjaOrdem_CardInfo(3,buffer,vetor,mouse1,&temp,pagina);
        }

        else if(cont > 4 && *posX >= 240 && *posX < 340 && *posY >= 230 && *posY < 380) {
            ArranjaOrdem_CardInfo(4,buffer,vetor,mouse1,&temp,pagina);
        }

        else if(cont > 5 && *posX >= 365 && *posX < 465 && *posY >= 230 && *posY < 380) {
            ArranjaOrdem_CardInfo(5,buffer,vetor,mouse1,&temp,pagina);
        }

        else if(cont > 6 && *posX >= 490 && *posX < 590 && *posY >= 230 && *posY < 380) {
            ArranjaOrdem_CardInfo(6,buffer,vetor,mouse1,&temp,pagina);
        }

        else if(cont > 7 && *posX >= 615 && *posX < 715 && *posY >= 230 && *posY < 380) {
            ArranjaOrdem_CardInfo(7,buffer,vetor,mouse1,&temp,pagina);
        }

        else if(cont > 8 && *posX >= 240 && *posX < 340 && *posY >= 390 && *posY < 540) {
            ArranjaOrdem_CardInfo(8,buffer,vetor,mouse1,&temp,pagina);
        }

        else if(cont > 9 && *posX >= 365 && *posX < 465 && *posY >= 390 && *posY < 540) {
            ArranjaOrdem_CardInfo(9,buffer,vetor,mouse1,&temp,pagina);
        }

        else if(cont > 10 && *posX >= 490 && *posX < 590 && *posY >= 390 && *posY < 540) {
            ArranjaOrdem_CardInfo(10,buffer,vetor,mouse1,&temp,pagina);
        }

        else if(cont > 11 && *posX >= 615 && *posX < 715 && *posY >= 390 && *posY < 540) {
            ArranjaOrdem_CardInfo(11,buffer,vetor,mouse1,&temp,pagina);
        }
        BarraRolagem(rolagem,posX,posY,dltZ,mouse1,*buffer,roll_bar,font,color);

        cont = 0;
        for(j = 12*(pagina-1);j < 12*pagina;j++) {
            if(j == i) break;
            if(j == temp) al_draw_scaled_bitmap(selecao,0,0,240,360,240 + 125*(cont % 4) - 5,70 + 160*(cont / 4) - 5,100 + 10,150 + 10,0);
            al_draw_scaled_bitmap(vetor[j]->origem->bmp,0,0,240,360,240 + 125*(cont % 4),70 + 160*(cont / 4),100,150,0);

            cont++;
        }

        al_flip_display();
    }

    aux = menu;
    temp = 0;
    while(temp < i) {
        aux->card = vetor[temp];
        aux = aux->prox;
        temp++;
    }

    al_draw_bitmap(tmp,0,0,0);
    al_destroy_bitmap(tmp);
    al_destroy_font(text);
    free(vetor);
    //al_rest(0.2);
}

void InsereAtualizaPosicao(struct Player *jogador,struct Deck *novo_card) {
    //INSERIR novo card PARA uma lista HAND, obrigatoriamente.
    //3 tipos de listas: HAND, DECK e GRAVEYARD.

    struct Deck *aux,*aux2 = NULL;
    int posicao = 0;

    aux = jogador->hand->inicio;
    while(aux->prox != NULL) {
        aux2 = aux;
        aux = aux->prox;
        posicao++;
    }

    if(aux2 != NULL) {
        aux2->prox = novo_card;
        aux2->prox->card->PosicaoX = 240 + 30*posicao;
        aux2->prox->card->PosicaoY = 450;
        aux2->prox->prox = aux;
    }
    else {
        aux2 = novo_card;
        aux2->card->PosicaoX = 240 + 30*posicao;
        aux2->card->PosicaoY = 450;
        aux2->prox = aux;

        jogador->hand->inicio = aux2;
    }

    jogador->hand->quantidade++;
}

bool RecuperaCard(struct Card **buffer,bool *fim_de_jogo,int *rolagem,int tipo_card,bool metodo,int level,ALLEGRO_BITMAP *prompt,ALLEGRO_BITMAP *selecao,ALLEGRO_BITMAP *roll_bar,ALLEGRO_BITMAP *fundo_menu,ALLEGRO_BITMAP *fundo_carta,ALLEGRO_BITMAP *deck_meio,ALLEGRO_BITMAP *deck_cheio,ALLEGRO_BITMAP *pont,struct Player *jogador,struct Player *adversario,ALLEGRO_DISPLAY *display,ALLEGRO_BITMAP *fundo,ALLEGRO_FONT *font,ALLEGRO_FONT *font2,ALLEGRO_COLOR color,bool *sair,int *posX,int *posY,int *dltZ,bool *mouse,bool *mouse2,bool *mouse_lado,int *keychar,bool *repete_keychar,ALLEGRO_EVENT_QUEUE *event_queue,ALLEGRO_TIMER *keyb_press_timer,ALLEGRO_TIMER *mouse_press_timer) {  //INCOMPLETO
    /*
        TIPO CARD:
   -1 -> Qualquer tipo
    0 -> Monster (NAO PERMITE jrboss ou boss CASO JA EXISTA um em campo)
    1 -> Equip
    2 -> Tactic
    3 -> Field

    */
    struct Deck *alvo,*aux,*aux2;
    struct Deck *escolhido = NULL;
    bool boss;

    aux = jogador->graveyard->inicio;
    if(aux == NULL) return(false);

    Menu_Cria(&alvo,&aux2);

    if(tipo_card == 0) {
        boss = BossPresente(jogador);

        while(aux->prox != NULL) {
            if(metodo == true) {
                if((aux->card->origem->monster != NULL && aux->card->origem->monster->level >= level) || (!boss && aux->card->origem->jrboss != NULL && aux->card->origem->jrboss->level >= level) || (!boss && aux->card->origem->boss != NULL && aux->card->origem->boss->level >= level)) {
                    Menu_CopiaDado(&aux2,aux->card);
                }
            }
            else {
                if((aux->card->origem->monster != NULL && aux->card->origem->monster->level <= level) || (aux->card->origem->jrboss != NULL && aux->card->origem->jrboss->level <= level) || (aux->card->origem->boss != NULL && aux->card->origem->boss->level <= level)) {
                    Menu_CopiaDado(&aux2,aux->card);
                }
            }

            aux = aux->prox;
        }
    }
    else if(tipo_card == -1) {
        while(aux->prox != NULL) {
            Menu_CopiaDado(&aux2,aux->card);
            aux = aux->prox;
        }
    }
    Menu_CelulaFinal(&aux2);

    escolhido = MenuCards("Recover a card from the discard pile.",true,alvo,fim_de_jogo,jogador,display,prompt,selecao,roll_bar,fundo_carta,fundo_menu,fundo,font2,font,color,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);
    if(escolhido != NULL) {
        aux = RetiraCardPorCopiaInstancia(escolhido,&(jogador->graveyard));
        InsereAtualizaPosicao(jogador,aux);
    }

    Menu_Finaliza(alvo);

    if(escolhido != NULL) return(true);
    else return(false);
}

void DrawCard_inicial(struct Player *jogador) {
    struct Deck *aux,*aux2 = NULL,*temp;
    int posicao = 0;

    if(jogador->deck->inicio->prox == NULL) return;
    temp = jogador->deck->inicio;
    jogador->deck->inicio = jogador->deck->inicio->prox;
    jogador->hand->quantidade++;
    jogador->deck->quantidade--;

    aux = jogador->hand->inicio;
    while(aux->prox != NULL) {
        aux2 = aux;
        aux = aux->prox;
        posicao++;
    }

    if(aux2 != NULL) {
        aux2->prox = temp;
        aux2->prox->card->PosicaoX = 240 + 30*posicao;
        aux2->prox->card->PosicaoY = 450;
        aux2->prox->prox = aux;
    }
    else {
        aux2 = temp;
        aux2->card->PosicaoX = 240 + 30*posicao;
        aux2->card->PosicaoY = 450;
        aux2->prox = aux;

        jogador->hand->inicio = aux2;
    }
}

bool LancaMoeda(int id_acao,struct Card **buffer,bool *fim,int *rolagem,struct StatusBox_bitmaps *sbox,ALLEGRO_BITMAP *selecao,ALLEGRO_BITMAP *roll_bar,ALLEGRO_BITMAP *prompt,ALLEGRO_BITMAP *fundo_carta,ALLEGRO_BITMAP *fundo_menu,ALLEGRO_BITMAP *deck_meio,ALLEGRO_BITMAP *deck_cheio,ALLEGRO_BITMAP *pont,struct Player *jogador,struct Player *adversario,ALLEGRO_DISPLAY *display,ALLEGRO_BITMAP *fundo,ALLEGRO_FONT *font,ALLEGRO_FONT *font2,ALLEGRO_COLOR color,bool *sair,int *posX,int *posY,int *dltZ,bool *mouse,bool *mouse2,bool *mouse_lado,int *keychar,bool *repete_keychar,ALLEGRO_EVENT_QUEUE *event_queue,ALLEGRO_TIMER *keyb_press_timer,ALLEGRO_TIMER *mouse_press_timer) {
    bool aleatorio,opcao;
    ALLEGRO_COLOR azul,vermelho;
    ALLEGRO_FONT *font3;
    ALLEGRO_BITMAP *temp;

    azul = al_map_rgb(0,0,255);
    vermelho = al_map_rgb(255,0,0);
    font3 = al_load_ttf_font("data/triforce.ttf",16,0);
    temp = al_clone_bitmap(al_get_backbuffer(display));

    al_clear_to_color(al_map_rgb_f(0, 0, 0));
    al_draw_tinted_bitmap(temp, al_map_rgba_f(0.3, 0.3, 0.3, 0.3),0, 0, 0);
    al_draw_bitmap(prompt,140,225,0);
    al_draw_text(font3,color,155,235,0,"FLIP COIN! Choose a side:");
    al_draw_text(font3,color,230,315,0,"Heads");
    al_draw_text(font3,color,505,315,0,"Tails");

    while(1) {
        al_flip_display();

        VerificaEventos(sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);

        if(*mouse == true && *posX >= 155 && *posX < 365 && *posY >= 300 && *posY < 345) {
            opcao = true;
            break;
        }
        else if(*mouse == true && *posX >= 425 && *posX < 635 && *posY >= 300 && *posY < 345) {
            opcao = false;
            break;
        }
    }
    al_destroy_bitmap(temp);

    aleatorio = rand() % 2;
    if(aleatorio == true) al_draw_text(font,color,155,350,0,"Resulted on HEADS.");
    else al_draw_text(font,color,155,350,0,"Resulted on TAILS.");

    if(aleatorio == opcao) {
        al_draw_text(font,azul,425,350,0,"WON!");
        opcao = true;
    }
    else {
        al_draw_text(font,vermelho,425,350,0,"LOST...");
        opcao = false;
    }

    al_flip_display();
    al_rest(2.0);
    AtualizaMesa(true,NULL,id_acao,-1,0,buffer,fim,sbox,prompt,selecao,roll_bar,fundo_carta,fundo_menu,deck_meio,deck_cheio,fundo,pont,jogador,adversario,display,font,font2,color,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer,rolagem,NULL,-1,-1,0,-1,NULL,NULL);

    al_destroy_font(font3);
    return(opcao);
}

bool LancaMoeda2(int id_acao,struct Card **buffer,bool *fim,int *rolagem,struct StatusBox_bitmaps *sbox,ALLEGRO_BITMAP *selecao,ALLEGRO_BITMAP *roll_bar,ALLEGRO_BITMAP *prompt,ALLEGRO_BITMAP *fundo_carta,ALLEGRO_BITMAP *fundo_menu,ALLEGRO_BITMAP *deck_meio,ALLEGRO_BITMAP *deck_cheio,ALLEGRO_BITMAP *pont,struct Player *jogador,struct Player *adversario,ALLEGRO_DISPLAY *display,ALLEGRO_BITMAP *fundo,ALLEGRO_FONT *font,ALLEGRO_FONT *font2,ALLEGRO_COLOR color,bool *sair,int *posX,int *posY,int *dltZ,bool *mouse,bool *mouse2,bool *mouse_lado,int *keychar,bool *repete_keychar,ALLEGRO_EVENT_QUEUE *event_queue,ALLEGRO_TIMER *keyb_press_timer,ALLEGRO_TIMER *mouse_press_timer) {
    bool aleatorio;
    ALLEGRO_COLOR azul,vermelho;
    ALLEGRO_FONT *font3;
    ALLEGRO_BITMAP *temp;

    azul = al_map_rgb(0,0,255);
    vermelho = al_map_rgb(255,0,0);
    font3 = al_load_ttf_font("data/triforce.ttf",16,0);
    temp = al_clone_bitmap(al_get_backbuffer(display));

    al_clear_to_color(al_map_rgb_f(0, 0, 0));
    al_draw_tinted_bitmap(temp, al_map_rgba_f(0.3, 0.3, 0.3, 0.3),0, 0, 0);
    al_destroy_bitmap(temp);

    al_draw_bitmap(prompt,140,225,0);
    al_draw_text(font3,color,155,235,0,"FLIPPED COIN! Result is:");

    aleatorio = rand() % 2;

    if(aleatorio == true) al_draw_text(font3,azul,230,315,0,"HEADS");
    else al_draw_text(font3,vermelho,505,315,0,"TAILS");

    al_flip_display();
    al_rest(2.0);
    AtualizaMesa(true,NULL,id_acao,-1,0,buffer,fim,sbox,prompt,selecao,roll_bar,fundo_carta,fundo_menu,deck_meio,deck_cheio,fundo,pont,jogador,adversario,display,font,font2,color,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer,rolagem,NULL,-1,-1,0,-1,NULL,NULL);

    al_destroy_font(font3);
    return(aleatorio);
}

void IncluiEOTTactic(struct Deck *tactic,struct Player *jogador) {
    struct Deck *aux,*aux2;

    aux = jogador->end_turn_tactics;
    aux2 = NULL;
    while(aux->prox != NULL) {
        aux2 = aux;
        aux = aux->prox;
    }
    if(aux2 != NULL) aux2->prox = tactic;
    else jogador->end_turn_tactics = tactic;
    tactic->prox = aux;
}

void LiberaDotList(struct CARD *card) {
    struct DotInstance *aux,*aux2;

    aux = card->dot_list;
    while(aux->prox != NULL) {
        aux2 = aux;
        aux = aux->prox;
        free(aux2);
    }
    free(aux);
}

void LiberaBuffList(struct CARD *card) {
    struct BuffInstance *aux,*aux2;

    aux = card->buff_list;
    while(aux->prox != NULL) {
        aux2 = aux;
        aux = aux->prox;
        free(aux2);
    }
    free(aux);
}

void LiberaAssociados(struct CARD *card) {
    CardAssociado aux,aux2 = NULL;

    aux = card->cards_associados;
    while(aux->prox != NULL) {
        aux2 = aux;
        aux = aux->prox;

        free(aux2);
    }
    free(aux);
}

void LiberaCARD(struct CARD *card) {
    if(card == NULL) printf("PONTEIRO NULO!\n");

    LiberaAssociados(card);
    LiberaDotList(card);
    LiberaBuffList(card);

    if(!strcmp(card->origem->tipo,"Equipment")) free(card->var_equip);
    if(strstr(card->origem->tipo,"Monster") != NULL || strcmp(card->origem->tipo,"Jr. Boss") == 0 || strcmp(card->origem->tipo,"Boss") == 0) {
        FinalizaListaQteAtaques(card->var_monster);
        free(card->var_monster);
    }
    free(card);
}

void LiberaEOTTactics(struct Deck *lista) {
    struct Deck *aux,*aux2;

    aux = lista;
    while(aux->prox != NULL) {
        aux2 = aux;
        aux = aux->prox;

        LiberaCARD(aux2->card);
        free(aux2);
    }
    free(aux);
}

bool ElaboraPrompt(char *definicao,char *opcional,void *const1,void *const2,char *opcao1,char *opcao2,int posX1,int posX2,int posY_,int id_acao,struct Card **buffer,bool *fim,int *rolagem,struct StatusBox_bitmaps *sbox,ALLEGRO_BITMAP *selecao,ALLEGRO_BITMAP *roll_bar,ALLEGRO_BITMAP *fundo_carta,ALLEGRO_BITMAP *fundo_menu,ALLEGRO_BITMAP *prompt,ALLEGRO_BITMAP *deck_meio,ALLEGRO_BITMAP *deck_cheio,ALLEGRO_BITMAP *pont,struct Player *jogador,struct Player *adversario,ALLEGRO_DISPLAY *display,ALLEGRO_BITMAP *fundo,ALLEGRO_FONT *font,ALLEGRO_FONT *font2,ALLEGRO_COLOR color,bool *sair,int *posX,int *posY,int *dltZ,bool *mouse,bool *mouse2,bool *mouse_lado,int *keychar,bool *repete_keychar,ALLEGRO_EVENT_QUEUE *event_queue,ALLEGRO_TIMER *keyb_press_timer,ALLEGRO_TIMER *mouse_press_timer) {
    //Observe que esta funcao permite como parametros de entrada tipos indefinidos:
    //  INT ou STRING (char *), no parametros cujo tipo esta representado por 'void*'
    //  'opcional' precisa vir com a string com tokens que servirao de mascara para 'const1' (tais como '%s' ou '%d');

    ALLEGRO_FONT *font3;
    ALLEGRO_BITMAP *temp;
    bool resposta;

    if(*fim == true) return(false);

    font3 = al_load_ttf_font("data/triforce.ttf",20,0);
    temp = al_clone_bitmap(al_get_backbuffer(display));
    while(1) {
        al_clear_to_color(al_map_rgb_f(0, 0, 0));
        al_draw_tinted_bitmap(temp, al_map_rgba_f(0.3, 0.3, 0.3, 0.3),0, 0, 0);
        al_draw_bitmap(prompt,140,225,0);
        al_draw_text(font3,color,155,235,0,definicao);
        if(opcional != NULL) al_draw_textf(font,color,155,280,0,opcional,const1,const2);

        al_draw_text(font3,color,posX1,posY_,0,opcao1);
        al_draw_text(font3,color,posX2,posY_,0,opcao2);
        al_flip_display();

        VerificaEventos(sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);

        if(*mouse == true && *posX >= 155 && *posX < 365 && *posY >= 300 && *posY < 345) {
            resposta = true;
            break;
        }
        else if (*mouse == true && *posX >= 425 && *posX < 635 && *posY >= 300 && *posY < 345) {
            resposta = false;
            break;
        }
        //al_rest(0.1);
    }
    //al_rest(0.2);

    AtualizaMesa(false,NULL,id_acao,-1,0,buffer,fim,sbox,prompt,selecao,roll_bar,fundo_carta,fundo_menu,deck_meio,deck_cheio,fundo,pont,jogador,adversario,display,font,font2,color,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer,rolagem,NULL,-1,-1,0,-1,NULL,NULL);
    al_destroy_font(font3);

    return(resposta);
}

void ocarina_of_time_play_tactic(int id_acao,struct Deck *aux,struct Card **buffer,bool *fim,int *rolagem,struct StatusBox_bitmaps *sbox,struct Player *jogador,struct Player *adversario,ALLEGRO_DISPLAY *display,ALLEGRO_BITMAP *prompt,ALLEGRO_BITMAP *selecao,ALLEGRO_BITMAP *roll_bar,ALLEGRO_BITMAP *apontador,ALLEGRO_BITMAP *fundo_carta,ALLEGRO_BITMAP *fundo_menu,ALLEGRO_BITMAP *deck_meio,ALLEGRO_BITMAP *deck_cheio,ALLEGRO_BITMAP *fundo,ALLEGRO_FONT *font,ALLEGRO_FONT *font2,ALLEGRO_COLOR color,bool *sair,int *posX,int *posY,int *dltZ,bool *mouse,bool *mouse2,bool *mouse_lado,int *keychar,bool *repete_keychar,ALLEGRO_EVENT_QUEUE *event_queue,ALLEGRO_TIMER *keyb_press_timer,ALLEGRO_TIMER *mouse_press_timer) {
    if(ElaboraPrompt("SCHEDULE a tactic?","%s",(void *)aux->card->origem->nome,NULL,"Yes","No",240,515,315,id_acao,buffer,fim,rolagem,sbox,selecao,roll_bar,fundo_carta,fundo_menu,prompt,deck_meio,deck_cheio,apontador,jogador,adversario,display,fundo,font,font2,color,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer)) {
        IncluiEOTTactic(aux,jogador);
    }
    else {
        aux->prox = (struct Deck *)malloc(sizeof(struct Deck));
        aux->prox->prox = NULL;
        ColocaListaCardsNaBaseDeck(&(jogador->deck),aux);
    }
}

void ocarina_of_time_acao(struct CARD *equip,int id_acao,struct Card **buffer,bool *fim,int *rolagem,struct StatusBox_bitmaps *sbox,struct Player *jogador,struct Player *adversario,ALLEGRO_DISPLAY *display,ALLEGRO_BITMAP *prompt,ALLEGRO_BITMAP *selecao,ALLEGRO_BITMAP *roll_bar,ALLEGRO_BITMAP *apontador,ALLEGRO_BITMAP *fundo_carta,ALLEGRO_BITMAP *fundo_menu,ALLEGRO_BITMAP *deck_meio,ALLEGRO_BITMAP *deck_cheio,ALLEGRO_BITMAP *fundo,ALLEGRO_FONT *font,ALLEGRO_FONT *font2,ALLEGRO_COLOR color,bool *sair,int *posX,int *posY,int *dltZ,bool *mouse,bool *mouse2,bool *mouse_lado,int *keychar,bool *repete_keychar,ALLEGRO_EVENT_QUEUE *event_queue,ALLEGRO_TIMER *keyb_press_timer,ALLEGRO_TIMER *mouse_press_timer) {
    struct Deck *lista,*aux,*aux2,*escolhido = NULL;
    equip->var_equip->ocarina_of_time_bool = false;

    lista = RetiraPrimeiroCard(&(jogador->deck));
    if(lista == NULL) return;

    aux = lista;
    aux2 = RetiraPrimeiroCard(&(jogador->deck));
    if(aux2 != NULL) {
        aux->prox = aux2;
        aux = aux->prox;
    }

    aux->prox = (struct Deck *)malloc(sizeof(struct Deck));
    aux->prox->prox = NULL;

    while(escolhido == NULL) escolhido = MenuCards("Select a card to DRAW. If the other card is a tactic of your level or less, you may schedule it for later.",true,lista,fim,jogador,display,prompt,selecao,roll_bar,fundo_carta,fundo_menu,fundo,font2,font,color,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);
    RetiraCardPorCopiaMenu(escolhido,&lista);

    ColocaNovoCardNoDeck(&(jogador->deck),escolhido);
    //draw card ainda sera usado...
    if(lista->prox != NULL) {
        if(lista->card->origem->tactic != NULL && lista->card->origem->tactic->level <= jogador->level) {
            aux = lista;
            lista = lista->prox;
            ocarina_of_time_play_tactic(id_acao,aux,buffer,fim,rolagem,sbox,jogador,adversario,display,prompt,selecao,roll_bar,apontador,fundo_carta,fundo_menu,deck_meio,deck_cheio,fundo,font,font2,color,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);

            free(lista);
        }
        else ColocaListaCardsNaBaseDeck(&(jogador->deck),lista);
    }
}

bool DrawCard(int id_acao,struct Card **buffer,bool *fim,int *rolagem,struct StatusBox_bitmaps *sbox,ALLEGRO_BITMAP *prompt,ALLEGRO_BITMAP *selecao,ALLEGRO_BITMAP *roll_bar,ALLEGRO_BITMAP *fundo_carta,ALLEGRO_BITMAP *fundo_menu,ALLEGRO_BITMAP *deck_meio,ALLEGRO_BITMAP *deck_cheio,ALLEGRO_BITMAP *pont,struct Player *jogador,struct Player *adversario,ALLEGRO_DISPLAY *display,ALLEGRO_BITMAP *fundo,ALLEGRO_FONT *font,ALLEGRO_FONT *font2,ALLEGRO_COLOR color,bool *sair,int *posX,int *posY,int *dltZ,bool *mouse,bool *mouse2,bool *mouse_lado,int *keychar,bool *repete_keychar,ALLEGRO_EVENT_QUEUE *event_queue,ALLEGRO_TIMER *keyb_press_timer,ALLEGRO_TIMER *mouse_press_timer) {  //OK!
    struct Deck *temp;

    printf("DRAW CARD... ");
    if(jogador->deck->inicio->prox == NULL) return(false);

    if(jogador->mesa->equip1 != NULL && jogador->mesa->equip1->var_equip->ocarina_of_time_bool == true) ocarina_of_time_acao(jogador->mesa->equip1,id_acao,buffer,fim,rolagem,sbox,jogador,adversario,display,prompt,selecao,roll_bar,pont,fundo_carta,fundo_menu,deck_meio,deck_cheio,fundo,font,font2,color,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);
    else if(jogador->mesa->equip2 != NULL && jogador->mesa->equip2->var_equip->ocarina_of_time_bool == true) ocarina_of_time_acao(jogador->mesa->equip2,id_acao,buffer,fim,rolagem,sbox,jogador,adversario,display,prompt,selecao,roll_bar,pont,fundo_carta,fundo_menu,deck_meio,deck_cheio,fundo,font,font2,color,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);
    else if(jogador->mesa->equip3 != NULL && jogador->mesa->equip3->var_equip->ocarina_of_time_bool == true) ocarina_of_time_acao(jogador->mesa->equip3,id_acao,buffer,fim,rolagem,sbox,jogador,adversario,display,prompt,selecao,roll_bar,pont,fundo_carta,fundo_menu,deck_meio,deck_cheio,fundo,font,font2,color,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);
    else if(jogador->mesa->equip4 != NULL && jogador->mesa->equip4->var_equip->ocarina_of_time_bool == true) ocarina_of_time_acao(jogador->mesa->equip4,id_acao,buffer,fim,rolagem,sbox,jogador,adversario,display,prompt,selecao,roll_bar,pont,fundo_carta,fundo_menu,deck_meio,deck_cheio,fundo,font,font2,color,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);
    else if(jogador->mesa->equip5 != NULL && jogador->mesa->equip5->var_equip->ocarina_of_time_bool == true) ocarina_of_time_acao(jogador->mesa->equip5,id_acao,buffer,fim,rolagem,sbox,jogador,adversario,display,prompt,selecao,roll_bar,pont,fundo_carta,fundo_menu,deck_meio,deck_cheio,fundo,font,font2,color,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);
    else if(jogador->mesa->equip6 != NULL && jogador->mesa->equip6->var_equip->ocarina_of_time_bool == true) ocarina_of_time_acao(jogador->mesa->equip6,id_acao,buffer,fim,rolagem,sbox,jogador,adversario,display,prompt,selecao,roll_bar,pont,fundo_carta,fundo_menu,deck_meio,deck_cheio,fundo,font,font2,color,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);
    else if(jogador->mesa->equip7 != NULL && jogador->mesa->equip7->var_equip->ocarina_of_time_bool == true) ocarina_of_time_acao(jogador->mesa->equip7,id_acao,buffer,fim,rolagem,sbox,jogador,adversario,display,prompt,selecao,roll_bar,pont,fundo_carta,fundo_menu,deck_meio,deck_cheio,fundo,font,font2,color,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);

    printf("1\n");
    temp = RetiraPrimeiroCard(&(jogador->deck));
    InsereAtualizaPosicao(jogador,temp);

    printf("2\n");
    AtualizaMesa(true,"Draw Card...",id_acao,-1,0,buffer,fim,sbox,prompt,selecao,roll_bar,fundo_carta,fundo_menu,deck_meio,deck_cheio,fundo,pont,jogador,adversario,display,font,font2,color,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer,rolagem,NULL,-1,-1,0,-1,NULL,NULL);
    printf("OK\n");

    return(true);
}

void DestroyCard(struct Deck *card,struct Player *jogador,struct Player *adversario) {    //Primeira carta da lista é a última que foi descartada.
    if(card == NULL) return;

    printf("%s (%d) -> (%d)\n",card->card->origem->nome,card->card->id_dono,jogador->id);
    if(card->card->id_dono == jogador->id) {
        card->prox = jogador->graveyard->inicio;
        jogador->graveyard->inicio = card;
        jogador->graveyard->quantidade++;
    }
    else {
        card->prox = adversario->graveyard->inicio;
        adversario->graveyard->inicio = card;
        adversario->graveyard->quantidade++;
    }
}

void DiscardCard(int id_acao,struct Card **buffer,bool *fim,struct StatusBox_bitmaps *sbox,ALLEGRO_BITMAP *prompt,ALLEGRO_BITMAP *selecao,ALLEGRO_BITMAP *roll_bar,ALLEGRO_BITMAP *fundo_carta,ALLEGRO_BITMAP *fundo_menu,ALLEGRO_BITMAP *deck_meio,ALLEGRO_BITMAP *deck_cheio,struct Player *jogador,struct Player *adversario,ALLEGRO_DISPLAY *display,ALLEGRO_BITMAP *fundo,ALLEGRO_FONT *font,ALLEGRO_FONT *font2,ALLEGRO_COLOR color,ALLEGRO_BITMAP *apontador,int *rolagem,bool *sair,int *posX,int *posY,int *dltZ,bool *mouse,bool *mouse2,bool *mouse_lado,int *keychar,bool *repete_keychar,ALLEGRO_EVENT_QUEUE *event_queue,ALLEGRO_TIMER *keyb_press_timer,ALLEGRO_TIMER *mouse_press_timer) {
    bool toggle = false;
    struct Coordenadas *lista,*aux,*aux2 = NULL;
    struct Deck *aux3,*aux4 = NULL;

    if(jogador->hand->quantidade == 0) return;
    lista = (struct Coordenadas *)malloc(sizeof(struct Coordenadas));
    lista->prox = NULL;

    //UTILIZAR menu de cards para escolher card a ser deletado? Nao, pois nao poder haver a opcao de ignorar deletar card!
    while(1) {
        AtualizaMesa(true,"DISCARD a card of your choice.",id_acao,2,0,buffer,fim,sbox,prompt,selecao,roll_bar,fundo_carta,fundo_menu,deck_meio,deck_cheio,fundo,apontador,jogador,adversario,display,font,font2,color,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer,rolagem,lista,-1,-1,0,-1,NULL,NULL);
        if(*fim == true) return;

        if(*mouse == true) {
            aux = lista;
            while(aux->prox != NULL) {
                aux2 = aux;
                aux = aux->prox;

                if(*posX >= aux2->x && *posX < aux2->x + 30 && *posY >= aux2->y && *posY < aux2->y + 150) {
                    toggle = true;
                    break;
                }
            }
            if(toggle == true) break;
            if(aux2 != NULL && *posX >= aux2->x && *posX < aux2->x + 100 && *posY >= aux2->y && *posY < aux2->y + 150) break;
        }
    }

    aux3 = jogador->hand->inicio;
    while(aux3->card->PosicaoX != aux2->x || aux3->card->PosicaoY != aux2->y) {
        aux4 = aux3;
        aux3 = aux3->prox;
    }

    aux = lista;
    while(aux->prox != NULL) {
        aux2 = aux;
        aux = aux->prox;
        free(aux2);
    }
    free(aux);

    if(aux4 != NULL) aux4->prox = aux3->prox;   //aux3: card a descartar.
    else {
        aux4 = aux3->prox;
        jogador->hand->inicio = aux4;
    }

    DestroyCard(aux3,jogador,adversario);
    jogador->hand->quantidade--;

    AtualizaMesa(true,NULL,id_acao,-1,0,buffer,fim,sbox,prompt,selecao,roll_bar,fundo_carta,fundo_menu,deck_meio,deck_cheio,fundo,apontador,jogador,adversario,display,font,font2,color,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer,rolagem,NULL,-1,-1,0,-1,NULL,NULL);
    //al_rest(0.15);
}

void RevelaCarta(char *msg,struct CARD *card,int id_acao,struct Card **buffer,bool *fim,struct StatusBox_bitmaps *sbox,ALLEGRO_BITMAP *prompt,ALLEGRO_BITMAP *select_card,ALLEGRO_BITMAP *roll_bar,ALLEGRO_BITMAP *fundo_carta,ALLEGRO_BITMAP *fundo_menu,ALLEGRO_BITMAP *deck_meio,ALLEGRO_BITMAP *deck_cheio,ALLEGRO_BITMAP *pont,struct Player *jogador,struct Player *adversario,ALLEGRO_DISPLAY *display,ALLEGRO_BITMAP *fundo,ALLEGRO_FONT *font,ALLEGRO_FONT *font2,ALLEGRO_COLOR color,bool *sair,int *posX,int *posY,int *dltZ,bool *mouse,bool *mouse2,bool *mouse_lado,int *keychar,bool *repete_keychar,ALLEGRO_EVENT_QUEUE *event_queue,ALLEGRO_TIMER *keyb_press_timer,ALLEGRO_TIMER *mouse_press_timer,int *rolagem) {    //OK!
    al_draw_scaled_bitmap(select_card,0,0,240,360,270,90,260,400,0);
    al_draw_bitmap(card->origem->bmp,280,120,0);
    al_draw_textf(font,color,280,100,0,msg);
    al_flip_display();

    al_rest(3.0);
    AtualizaMesa(true,NULL,id_acao,-1,0,buffer,fim,sbox,prompt,select_card,roll_bar,fundo_carta,fundo_menu,deck_meio,deck_cheio,fundo,pont,jogador,adversario,display,font,font2,color,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer,rolagem,NULL,-1,-1,0,-1,NULL,NULL);
}

void DiscardRandomCard(int id_acao,struct Card **buffer,bool *fim,struct StatusBox_bitmaps *sbox,ALLEGRO_BITMAP *prompt,ALLEGRO_BITMAP *selecao,ALLEGRO_BITMAP *roll_bar,ALLEGRO_BITMAP *fundo_carta,ALLEGRO_BITMAP *fundo_menu,ALLEGRO_BITMAP *deck_meio,ALLEGRO_BITMAP *deck_cheio,struct Player *jogador,struct Player *adversario,ALLEGRO_DISPLAY *display,ALLEGRO_BITMAP *fundo,ALLEGRO_FONT *font,ALLEGRO_FONT *font2,ALLEGRO_COLOR color,ALLEGRO_BITMAP *apontador,int *rolagem,bool *sair,int *posX,int *posY,int *dltZ,bool *mouse,bool *mouse2,bool *mouse_lado,int *keychar,bool *repete_keychar,ALLEGRO_EVENT_QUEUE *event_queue,ALLEGRO_TIMER *keyb_press_timer,ALLEGRO_TIMER *mouse_press_timer) {
    struct Deck *aux3,*aux4 = NULL;
    int aleatorio;

    if(jogador->hand->quantidade == 0) return;


    //UTILIZAR menu de cards para escolher card a ser deletado? Nao, pois nao poder haver a opcao de ignorar deletar card!

    aleatorio = rand() % jogador->hand->quantidade;

    aux3 = jogador->hand->inicio;
    while(aleatorio > 0) {
        aux4 = aux3;
        aux3 = aux3->prox;
        aleatorio--;
    }

    RevelaCarta("RANDOMLY discarded:",aux3->card,id_acao,buffer,fim,sbox,prompt,selecao,roll_bar,fundo_carta,fundo_menu,deck_meio,deck_cheio,apontador,jogador,adversario,display,fundo,font,font2,color,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer,rolagem);

    if(aux4 != NULL) aux4->prox = aux3->prox;   //aux3: card a descartar.
    else {
        aux4 = aux3->prox;
        jogador->hand->inicio = aux4;
    }

    DestroyCard(aux3,jogador,adversario);
    jogador->hand->quantidade--;

    AtualizaMesa(true,NULL,id_acao,-1,0,buffer,fim,sbox,prompt,selecao,roll_bar,fundo_carta,fundo_menu,deck_meio,deck_cheio,fundo,apontador,jogador,adversario,display,font,font2,color,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer,rolagem,NULL,-1,-1,0,-1,NULL,NULL);
    //al_rest(0.15);
}

void OlhaCarta(int id_acao,struct Card **buffer,bool *fim,struct StatusBox_bitmaps *sbox,ALLEGRO_BITMAP *prompt,ALLEGRO_BITMAP *select_card,ALLEGRO_BITMAP *roll_bar,ALLEGRO_BITMAP *fundo_carta,ALLEGRO_BITMAP *fundo_menu,ALLEGRO_BITMAP *deck_meio,ALLEGRO_BITMAP *deck_cheio,ALLEGRO_BITMAP *pont,struct Player *jogador,struct Player *adversario,ALLEGRO_DISPLAY *display,ALLEGRO_BITMAP *fundo,ALLEGRO_FONT *font,ALLEGRO_FONT *font2,ALLEGRO_COLOR color,bool *sair,int *posX,int *posY,int *dltZ,bool *mouse,bool *mouse2,bool *mouse_lado,int *keychar,bool *repete_keychar,ALLEGRO_EVENT_QUEUE *event_queue,ALLEGRO_TIMER *keyb_press_timer,ALLEGRO_TIMER *mouse_press_timer,int *rolagem) {    //OK!
    al_draw_scaled_bitmap(select_card,0,0,240,360,270,90,260,400,0);
    al_draw_bitmap(jogador->deck->inicio->card->origem->bmp,280,120,0);
    al_draw_textf(font,color,280,100,0,"NEXT CARD...");
    al_flip_display();

    al_rest(3.0);
    AtualizaMesa(true,NULL,id_acao,-1,0,buffer,fim,sbox,prompt,select_card,roll_bar,fundo_carta,fundo_menu,deck_meio,deck_cheio,fundo,pont,jogador,adversario,display,font,font2,color,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer,rolagem,NULL,-1,-1,0,-1,NULL,NULL);
}

//Esta funcao esta implementada SOMENTE para escolher cards da HAND.
bool AvaliaCoordenadas(int *X,int *Y,struct Player *jogador,struct Coordenadas *lista,struct Deck *origem) {
    struct Coordenadas *card,*card2;
    int finalX = 240 + 30*(jogador->hand->quantidade - 1),finalY = 450,posX = *X,posY = *Y;

    card = lista;
    card2 = NULL;
    while(card->prox != NULL) {
        if(posX >= card->x && posX < card->x + 30 && posY >= card->y && posY < card->y + 150) {
            *X = card->x;
            *Y = card->y;
            return(true);

        }
        card2 = card;
        card = card->prox;
    }

    if(card2->prox->prox == NULL && finalX == card2->x && finalY == card2->y && posX >= finalX && posX < finalX + 100 && posY >= finalY && posY < finalY + 150) {
        *X = finalX;
        *Y = finalY;
        return(true);
    }

    return(false);
}

int QuantidadeListaCards(struct Deck *alvo) {
    int qte = 0;
    struct Deck *aux;

    if(alvo == NULL) return(0);

    aux = alvo;
    while(aux->prox != NULL) {
        qte++;
        aux = aux->prox;
    }

    return(qte);
}

int RecuperaCardLevel(struct Card *card) {
    if(card->character != NULL) return(30);
    if(card->monster != NULL) return(card->monster->level);
    if(card->equip != NULL) return(card->equip->level);
    if(card->tactic != NULL) return(card->tactic->level);
    if(card->field != NULL) return(50);
    if(card->jrboss != NULL) return(card->jrboss->level);
    if(card->boss != NULL) return(card->boss->level);

    printf("ERRO: Tipo de card nao identificado: %s!\n",card->nome);
    return(0);
}

bool PossuiWeapon(struct Player *jogador) {
    if(jogador->mesa->equip1 != NULL && strstr(jogador->mesa->equip1->origem->str_concat,"Weapon") != NULL) return(true);
    if(jogador->mesa->equip2 != NULL && strstr(jogador->mesa->equip2->origem->str_concat,"Weapon") != NULL) return(true);
    if(jogador->mesa->equip3 != NULL && strstr(jogador->mesa->equip3->origem->str_concat,"Weapon") != NULL) return(true);
    if(jogador->mesa->equip4 != NULL && strstr(jogador->mesa->equip4->origem->str_concat,"Weapon") != NULL) return(true);
    if(jogador->mesa->equip5 != NULL && strstr(jogador->mesa->equip5->origem->str_concat,"Weapon") != NULL) return(true);
    if(jogador->mesa->equip6 != NULL && strstr(jogador->mesa->equip6->origem->str_concat,"Weapon") != NULL) return(true);
    if(jogador->mesa->equip7 != NULL && strstr(jogador->mesa->equip7->origem->str_concat,"Weapon") != NULL) return(true);

    return(false);
}

bool PossuiIronBoots(struct Player *jogador) {
    if(jogador->mesa->equip1 != NULL && jogador->mesa->equip1->origem->colecao == IRON_BOOTS) return(true);
    if(jogador->mesa->equip2 != NULL && jogador->mesa->equip2->origem->colecao == IRON_BOOTS) return(true);
    if(jogador->mesa->equip3 != NULL && jogador->mesa->equip3->origem->colecao == IRON_BOOTS) return(true);
    if(jogador->mesa->equip4 != NULL && jogador->mesa->equip4->origem->colecao == IRON_BOOTS) return(true);
    if(jogador->mesa->equip5 != NULL && jogador->mesa->equip5->origem->colecao == IRON_BOOTS) return(true);
    if(jogador->mesa->equip6 != NULL && jogador->mesa->equip6->origem->colecao == IRON_BOOTS) return(true);
    if(jogador->mesa->equip7 != NULL && jogador->mesa->equip7->origem->colecao == IRON_BOOTS) return(true);

    return(false);
}

bool VerificaCardPorNome(int nome,struct Lista *deck) {
    struct Deck *aux = deck->inicio;

    while(aux->prox != NULL) {
        if(aux->card->origem->colecao == nome) return(true);
        aux = aux->prox;
    }

    return(false);
}

void IncluiInstancia(struct Player *jogador,char *id,int turns) {
    struct InstanceSchedule *aux;

    aux = jogador->schedule;
    while(aux->prox != NULL) aux = aux->prox;

    aux->instance_id = id;
    aux->turns_left = turns;

    aux->prox = (struct InstanceSchedule *)malloc(sizeof(struct InstanceSchedule));
    aux->prox->prox = NULL;
}

void AtualizaInstancias(struct Player *jogador) {
    struct InstanceSchedule *aux,*aux2;

    aux = jogador->schedule;
    aux2 = NULL;
    while(aux->prox != NULL) {
        aux->turns_left--;

        if(aux->turns_left == 0) {
            if(aux2 != NULL) aux2->prox = aux->prox;
            else jogador->schedule = aux->prox;

            free(aux);
        }

        aux2 = aux;
        aux = aux->prox;
    }
}

void LiberaInstancias(struct Player *jogador) {
    struct InstanceSchedule *aux,*aux2;

    aux = jogador->schedule;
    aux2 = NULL;
    while(aux->prox != NULL) {
        aux2 = aux;
        aux = aux->prox;
        free(aux2);
    }
    free(aux);
}

bool THpresente(struct Player *jogador) {
    if(jogador->mesa->monstro1 != NULL && jogador->mesa->monstro1->origem->colecao == DEAD_HAND && jogador->mesa->monstro1->turn_silenced == 0) return(true);
    if(jogador->mesa->monstro2 != NULL && jogador->mesa->monstro2->origem->colecao == DEAD_HAND && jogador->mesa->monstro2->turn_silenced == 0) return(true);
    if(jogador->mesa->monstro3 != NULL && jogador->mesa->monstro3->origem->colecao == DEAD_HAND && jogador->mesa->monstro3->turn_silenced == 0) return(true);
    if(jogador->mesa->monstro4 != NULL && jogador->mesa->monstro4->origem->colecao == DEAD_HAND && jogador->mesa->monstro4->turn_silenced == 0) return(true);
    if(jogador->mesa->monstro5 != NULL && jogador->mesa->monstro5->origem->colecao == DEAD_HAND && jogador->mesa->monstro5->turn_silenced == 0) return(true);
    if(jogador->mesa->monstro6 != NULL && jogador->mesa->monstro6->origem->colecao == DEAD_HAND && jogador->mesa->monstro6->turn_silenced == 0) return(true);
    if(jogador->mesa->monstro7 != NULL && jogador->mesa->monstro7->origem->colecao == DEAD_HAND && jogador->mesa->monstro7->turn_silenced == 0) return(true);

    return(false);
}

bool GLpresente(struct Player *jogador) {
    if(jogador->mesa->monstro1 != NULL && jogador->mesa->monstro1->origem->colecao == GIANT_LEEVER && jogador->mesa->monstro1->turn_silenced == 0) return(true);
    if(jogador->mesa->monstro2 != NULL && jogador->mesa->monstro2->origem->colecao == GIANT_LEEVER && jogador->mesa->monstro2->turn_silenced == 0) return(true);
    if(jogador->mesa->monstro3 != NULL && jogador->mesa->monstro3->origem->colecao == GIANT_LEEVER && jogador->mesa->monstro3->turn_silenced == 0) return(true);
    if(jogador->mesa->monstro4 != NULL && jogador->mesa->monstro4->origem->colecao == GIANT_LEEVER && jogador->mesa->monstro4->turn_silenced == 0) return(true);
    if(jogador->mesa->monstro5 != NULL && jogador->mesa->monstro5->origem->colecao == GIANT_LEEVER && jogador->mesa->monstro5->turn_silenced == 0) return(true);
    if(jogador->mesa->monstro6 != NULL && jogador->mesa->monstro6->origem->colecao == GIANT_LEEVER && jogador->mesa->monstro6->turn_silenced == 0) return(true);
    if(jogador->mesa->monstro7 != NULL && jogador->mesa->monstro7->origem->colecao == GIANT_LEEVER && jogador->mesa->monstro7->turn_silenced == 0) return(true);

    return(false);
}

/* Inclui todas as cartas */
#include "../cards/headers/link.c"
#include "../cards/headers/great_dekus_bless.c"
#include "../cards/headers/gohma.c"
#include "../cards/headers/goron_tunic.c"
#include "../cards/headers/dark_link.c"
#include "../cards/headers/desert_colossus.c"
#include "../cards/headers/likelike.c"
#include "../cards/headers/impa.c"
#include "../cards/headers/twinrova.c"
#include "../cards/headers/pierre.c"
#include "../cards/headers/blue_potion.c"
#include "../cards/headers/flare_dancer.c"
#include "../cards/headers/adult_wallet.c"
#include "../cards/headers/goron_bracelet.c"
#include "../cards/headers/kokiri_forest.c"
#include "../cards/headers/golden_scale.c"
#include "../cards/headers/master_sword.c"
#include "../cards/headers/gerudo_guard.c"
#include "../cards/headers/bombchu.c"
#include "../cards/headers/princess_zelda.c"
#include "../cards/headers/lizalfos.c"
#include "../cards/headers/hookshot.c"
#include "../cards/headers/young_link.c"
#include "../cards/headers/ganon.c"
#include "../cards/headers/spirit_medallion.c"
#include "../cards/headers/goron_ruby.c"
#include "../cards/headers/bongobongo.c"
#include "../cards/headers/guay.c"
#include "../cards/headers/moblin.c"
#include "../cards/headers/bazaar_seller.c"
#include "../cards/headers/king_zora.c"
#include "../cards/headers/nabooru.c"
#include "../cards/headers/anubis.c"
#include "../cards/headers/dead_hand.c"
#include "../cards/headers/death_mt_crater.c"
#include "../cards/headers/hyrule_castle.c"
#include "../cards/headers/lake_hylia.c"
#include "../cards/headers/rauru.c"
#include "../cards/headers/phantom_ganon.c"
#include "../cards/headers/bigocto.c"
#include "../cards/headers/tailpasaran.c"
#include "../cards/headers/gerudo_fortress.c"
#include "../cards/headers/cursed_villager.c"
#include "../cards/headers/poe_sisters.c"
#include "../cards/headers/hylian_shield.c"
#include "../cards/headers/deku_seeds_bag.c"
#include "../cards/headers/bless_of_triforce.c"
#include "../cards/headers/skulltulas_ambush.c"
#include "../cards/headers/heart_piece.c"
#include "../cards/headers/milk_bottle.c"
#include "../cards/headers/stinger.c"
#include "../cards/headers/zoras_sapphire.c"
#include "../cards/headers/peahat.c"
#include "../cards/headers/gold_skulltula.c"
#include "../cards/headers/larva_gohma.c"
#include "../cards/headers/magic_beans.c"
#include "../cards/headers/small_key.c"
#include "../cards/headers/great_deku_trees_knowledge.c"
#include "../cards/headers/bomb_rain.c"
#include "../cards/headers/kakariko_graveyard.c"
#include "../cards/headers/mido.c"
#include "../cards/headers/cucco_lady.c"
#include "../cards/headers/fairys_aid.c"
#include "../cards/headers/triple_shot.c"
#include "../cards/headers/deku_nut.c"
#include "../cards/headers/dark_pathway.c"
#include "../cards/headers/magic_jar.c"
#include "../cards/headers/give_away.c"
#include "../cards/headers/ice_arrow.c"
#include "../cards/headers/play_ocarina.c"
#include "../cards/headers/open_chest.c"
#include "../cards/headers/crystal_switch.c"
#include "../cards/headers/raze.c"
#include "../cards/headers/dins_fire.c"
#include "../cards/headers/mountain_climbing.c"
#include "../cards/headers/horse_riding.c"
#include "../cards/headers/1_ton_rock_lifting.c"
#include "../cards/headers/octorok.c"
#include "../cards/headers/joelle.c"
#include "../cards/headers/torch_slug.c"
#include "../cards/headers/spike.c"
#include "../cards/headers/bomb_bag.c"
#include "../cards/headers/fairy_slingshot.c"
#include "../cards/headers/compass.c"
#include "../cards/headers/guillotine.c"
#include "../cards/headers/skullwalltula.c"
#include "../cards/headers/baby_dodongo.c"
#include "../cards/headers/fabulous_five_froggish_tenors.c"
#include "../cards/headers/leever.c"
#include "../cards/headers/red_tektite.c"
#include "../cards/headers/blue_tektite.c"
#include "../cards/headers/granny.c"
#include "../cards/headers/wolfos.c"
#include "../cards/headers/shabom.c"
#include "../cards/headers/silver_gauntlets.c"
#include "../cards/headers/worlds_finest_eye_drops.c"
#include "../cards/headers/ocarina_of_time.c"
#include "../cards/headers/gossip_stone.c"
#include "../cards/headers/ganons_castle.c"
#include "../cards/headers/dungeon_map.c"
#include "../cards/headers/gerudos_membership_card.c"
#include "../cards/headers/shadow_merge.c"
#include "../cards/headers/golden_gauntlets.c"
#include "../cards/headers/mask_of_truth.c"
#include "../cards/headers/warp.c"
#include "../cards/headers/giant_leever.c"
#include "../cards/headers/big_poe.c"
#include "../cards/headers/skull_mask.c"
#include "../cards/headers/ganondorf.c"
#include "../cards/headers/chest.c"
#include "../cards/headers/skull_kid.c"
#include "../cards/headers/princess_ruto.c"
#include "../cards/headers/light_medallion.c"
#include "../cards/headers/fire_arrow.c"
#include "../cards/headers/jump_quest_water.c"
#include "../cards/headers/iron_boots.c"
#include "../cards/headers/mirror_shield.c"
#include "../cards/headers/white_wolfos.c"
#include "../cards/headers/whirling_scythes.c"
#include "../cards/headers/darunia.c"
#include "../cards/headers/sunset.c"
#include "../cards/headers/channeled_strike.c"
#include "../cards/headers/purple_rupee.c"
#include "../cards/headers/redead.c"
#include "../cards/headers/beamos.c"
#include "../cards/headers/iron_knuckles.c"
#include "../cards/headers/dodongo.c"
#include "../cards/headers/freezard.c"
#include "../cards/headers/business_scrub.c"
#include "../cards/headers/jump_quest_wind.c"
#include "../cards/headers/underground_shelter.c"
#include "../cards/headers/hover_boots.c"
#include "../cards/headers/epona.c"
#include "../cards/headers/claim_check.c"
#include "../cards/headers/purple_poe_remnant.c"
#include "../cards/headers/green_poe_remnant.c"
#include "../cards/headers/fire_temple.c"
#include "../cards/headers/bigger_bomb_bag.c"
#include "../cards/headers/bomb.c"
#include "../cards/headers/malon.c"
#include "../cards/headers/boomerang.c"
#include "../cards/headers/tricky_shot.c"
#include "../cards/headers/kokiri_tunic.c"
#include "../cards/headers/stalfos.c"
#include "../cards/headers/big_deku_baba.c"
#include "../cards/headers/fairy_fountain.c"
#include "../cards/headers/mystic_spell.c"
#include "../cards/headers/great_fairys_bless.c"
#include "../cards/headers/keese.c"

void RecuperaZeroHP(bool *fim,struct Player *adversario) {
    if(*fim == true) return;
    printf("recuperando 0 HP\n");

    if(adversario->mesa->monstro1 != NULL && adversario->mesa->monstro1->HP <= 0) adversario->mesa->monstro1->HP = 10;
    if(adversario->mesa->monstro2 != NULL && adversario->mesa->monstro2->HP <= 0) adversario->mesa->monstro2->HP = 10;
    if(adversario->mesa->monstro3 != NULL && adversario->mesa->monstro3->HP <= 0) adversario->mesa->monstro3->HP = 10;
    if(adversario->mesa->monstro4 != NULL && adversario->mesa->monstro4->HP <= 0) adversario->mesa->monstro4->HP = 10;
    if(adversario->mesa->monstro5 != NULL && adversario->mesa->monstro5->HP <= 0) adversario->mesa->monstro5->HP = 10;
    if(adversario->mesa->monstro6 != NULL && adversario->mesa->monstro6->HP <= 0) adversario->mesa->monstro6->HP = 10;
    if(adversario->mesa->monstro7 != NULL && adversario->mesa->monstro7->HP <= 0) adversario->mesa->monstro7->HP = 10;

    if(adversario->mesa->character->HP <= 0) adversario->mesa->character->HP = 10;
}

void SilenciaAuras(bool *fim,struct CARD *card,int turns,struct Player *jogador,struct Player *adversario) {   //card deve existir!
    if(card->turn_silenced == 0) {
        if(card->origem->colecao == DEAD_HAND) desfaz_dead_hand_effect(adversario);
        else if(card->origem->colecao == GIANT_LEEVER) desfaz_giant_leever_effect(adversario);
        else if(card->origem->colecao == BLUE_TEKTITE && ((jogador->mesa->field != NULL && !strcmp(jogador->mesa->field->origem->elemento,"Water")) || (adversario->mesa->field != NULL && !strcmp(adversario->mesa->field->origem->elemento,"Water")))) {
            card->HP -= 20;
            card->MaxHP -= 20;
        }

        else if(card->origem->colecao == WOLFOS) RetiraQuantidadeAtaquePorOrigem(&(card->var_monster->lista_qte_ataques),card);
        else if(card->origem->colecao == WHITE_WOLFOS) RetiraQuantidadeAtaquePorOrigem(&(card->var_monster->lista_qte_ataques),card);
    }

    card->turn_silenced += turns;
    RecuperaZeroHP(fim,adversario);
}

//IMPLEMENTAR ENTRADA DE CARD AO CAMPO!
#include "card_acoes2.c"

void RetornaSubcards(struct CARD *card,struct Lista *deck) {
    struct card_associado *aux,*aux2;

    if(card->qte_associado == 0) return;

    aux = card->cards_associados;
    while(aux->prox != NULL) {
        aux->deck->prox = deck->inicio;    //colocando cards debaixo do equipamento pro deck.
        deck->inicio = aux->deck;
        deck->quantidade++;

        aux2 = aux;
        aux = aux->prox;

        free(aux2);
        card->qte_associado--;
    }

    card->cards_associados = aux;
}

#include "field_acoes.c"

void DestroyEquipment(int id_acao,bool *fim,struct Card **buffer,int *rolagem,struct StatusBox_bitmaps *sbox,struct Player *jogador,struct Player *adversario,ALLEGRO_DISPLAY *display,ALLEGRO_BITMAP *prompt,ALLEGRO_BITMAP *selecao,ALLEGRO_BITMAP *roll_bar,ALLEGRO_BITMAP *fundo_carta,ALLEGRO_BITMAP *fundo_menu,ALLEGRO_BITMAP *deck_meio,ALLEGRO_BITMAP *deck_cheio,ALLEGRO_BITMAP *fundo,ALLEGRO_FONT *font,ALLEGRO_FONT *font2,ALLEGRO_COLOR color,bool *sair,int *posX,int *posY,int *dltZ,bool *mouse,bool *mouse2,bool *mouse_lado,int *keychar,bool *repete_keychar,ALLEGRO_EVENT_QUEUE *event_queue,ALLEGRO_TIMER *keyb_press_timer,ALLEGRO_TIMER *mouse_press_timer,ALLEGRO_BITMAP *bmp) {
    struct Coordenadas *lista,*aux,*aux2;
    struct CARD *equip;
    struct Deck *aux3;
    int final;

    lista = (struct Coordenadas *)malloc(sizeof(struct Coordenadas));
    lista->prox = NULL;

    AtualizaMesa(true,"Destroy an equipment.",id_acao,1,0,buffer,fim,sbox,prompt,selecao,roll_bar,fundo_carta,fundo_menu,deck_meio,deck_cheio,fundo,bmp,jogador,adversario,display,font,font2,color,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer,rolagem,lista,-1,-1,0,-1,NULL,NULL);
    if(lista->prox != NULL) {
        while(1) {
            AtualizaMesa(true,"Destroy an equipment.",id_acao,1,0,buffer,fim,sbox,prompt,selecao,roll_bar,fundo_carta,fundo_menu,deck_meio,deck_cheio,fundo,bmp,jogador,adversario,display,font,font2,color,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer,rolagem,lista,-1,-1,0,-1,NULL,NULL);
            if(*fim == true) return;

            if(*mouse == true) {
                printf("%d %d\n",*posX,*posY);
                aux2 = lista;

                while(aux2->prox != NULL) {
                    if(*posX >= aux2->x && *posX < aux2->x + 50 && *posY >= aux2->y && *posY < aux2->y + 75) break;
                    aux2 = aux2->prox;
                }

                if(aux2->prox != NULL) {
                    final = 0;
                    break;
                }
            }
            else if(*mouse2 == true) {
                final = 1;
                break;
            }
        }
    }

    aux = lista;
    while(aux->prox != NULL) {
        aux2 = aux;
        aux = aux->prox;
        free(aux2);
    }
    free(aux);

    if (final == 0) {
        if(*posX >= 300 && *posX < 300 + 50 && *posY >= 110 && *posY < 110 + 75) {
            equip = adversario->mesa->equip1;       //LOCAIS CORRESPONDENTES AOS SLOTS DOS EQUIPS!!!
            if(equip->origem->colecao == DUNGEON_MAP) DesfazAmbosFieldBuffs(jogador,adversario);
            adversario->mesa->equip1 = NULL;
        }
        else if(*posX >= 355 && *posX < 355 + 50 && *posY >= 110 && *posY < 110 + 75) {
            equip = adversario->mesa->equip2;
            if(equip->origem->colecao == DUNGEON_MAP) DesfazAmbosFieldBuffs(jogador,adversario);
            adversario->mesa->equip2 = NULL;
        }
        else if(*posX >= 410 && *posX < 410 + 50 && *posY >= 110 && *posY < 110 + 75) {
            equip = adversario->mesa->equip3;
            if(equip->origem->colecao == DUNGEON_MAP) DesfazAmbosFieldBuffs(jogador,adversario);
            adversario->mesa->equip3 = NULL;
        }
        else if(*posX >= 465 && *posX < 465 + 50 && *posY >= 110 && *posY < 110 + 75) {
            equip = adversario->mesa->equip4;
            if(equip->origem->colecao == DUNGEON_MAP) DesfazAmbosFieldBuffs(jogador,adversario);
            adversario->mesa->equip4 = NULL;
        }
        else if(*posX >= 520 && *posX < 520 + 50 && *posY >= 110 && *posY < 110 + 75) {
            equip = adversario->mesa->equip5;
            if(equip->origem->colecao == DUNGEON_MAP) DesfazAmbosFieldBuffs(jogador,adversario);
            adversario->mesa->equip5 = NULL;
        }
        else if(*posX >= 575 && *posX < 575 + 50 && *posY >= 110 && *posY < 110 + 75) {
            equip = adversario->mesa->equip6;
            if(equip->origem->colecao == DUNGEON_MAP) DesfazAmbosFieldBuffs(jogador,adversario);
            adversario->mesa->equip6 = NULL;
        }
        else if(*posX >= 630 && *posX < 630 + 50 && *posY >= 110 && *posY < 110 + 75) {
            equip = adversario->mesa->equip7;
            if(equip->origem->colecao == DUNGEON_MAP) DesfazAmbosFieldBuffs(jogador,adversario);
            adversario->mesa->equip7 = NULL;
        }

        //---- Efeitos de desativação de equips -----

        if(equip->origem->colecao == GORON_RUBY) {
            desfaz_goron_ruby_acao(jogador,adversario);
        }

        else if(equip->origem->colecao == GORON_TUNIC) {
            desfaz_goron_tunic_acao2(adversario);
        }

        else if(equip->origem->colecao == ZORAS_SAPPHIRE) {
            desfaz_zoras_sapphire_acao(jogador,adversario);
        }

        //-------------------------------------------
        RetornaSubcards(equip,adversario->graveyard);
        if(equip->origem->colecao == DUNGEON_MAP) RefazAmbosFieldBuffs(jogador,adversario);

        RecuperaZeroHP(fim,jogador);
        RecuperaZeroHP(fim,adversario);

        aux3 = (struct Deck *)malloc(sizeof(struct Deck));
        aux3->card = equip;
        DestroyCard(aux3,adversario,jogador);
    }
}

bool PreventDamage(struct CARD *alvo,int id_acao,struct Card **buffer,bool *fim,int *rolagem,struct StatusBox_bitmaps *sbox,ALLEGRO_BITMAP *selecao,ALLEGRO_BITMAP *roll_bar,ALLEGRO_BITMAP *fundo_carta,ALLEGRO_BITMAP *fundo_menu,ALLEGRO_BITMAP *prompt,ALLEGRO_BITMAP *deck_meio,ALLEGRO_BITMAP *deck_cheio,ALLEGRO_BITMAP *pont,struct Player *jogador,struct Player *adversario,ALLEGRO_DISPLAY *display,ALLEGRO_BITMAP *fundo,ALLEGRO_FONT *font,ALLEGRO_FONT *font2,ALLEGRO_COLOR color,bool *sair,int *posX,int *posY,int *dltZ,bool *mouse,bool *mouse2,bool *mouse_lado,int *keychar,bool *repete_keychar,ALLEGRO_EVENT_QUEUE *event_queue,ALLEGRO_TIMER *keyb_press_timer,ALLEGRO_TIMER *mouse_press_timer,int damage) {
    return(ElaboraPrompt("Prevent damage?","'%s' targeted for %d damage.",(void *)alvo->origem->nome,(void *)damage,"Yes","No",240,515,315,id_acao,buffer,fim,rolagem,sbox,selecao,roll_bar,fundo_carta,fundo_menu,prompt,deck_meio,deck_cheio,pont,jogador,adversario,display,fundo,font,font2,color,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer));
}

bool ehMonstro(struct CARD *card) {
    if(card->origem->monster != NULL || card->origem->jrboss != NULL || card->origem->boss != NULL) return(true);
    else return(false);
}

bool Possui_mobslot(struct Player *jogador) {
    if(jogador->mesa->monstro1 == NULL) return(true);
    if(jogador->mesa->monstro2 == NULL) return(true);
    if(jogador->mesa->monstro3 == NULL) return(true);
    if(jogador->mesa->monstro4 == NULL) return(true);
    if(jogador->mesa->monstro5 == NULL) return(true);
    if(jogador->mesa->monstro6 == NULL) return(true);
    if(jogador->mesa->monstro7 == NULL) return(true);

    return(false);
}

bool Possui_eqpslot(struct Player *jogador) {
    if(jogador->mesa->equip1 == NULL) return(true);
    if(jogador->mesa->equip2 == NULL) return(true);
    if(jogador->mesa->equip3 == NULL) return(true);
    if(jogador->mesa->equip4 == NULL) return(true);
    if(jogador->mesa->equip5 == NULL) return(true);
    if(jogador->mesa->equip6 == NULL) return(true);
    if(jogador->mesa->equip7 == NULL) return(true);

    return(false);
}

int BuscaAtacante(struct Player *jogador,struct CARD *atacante) {
    int slot = -1;

    if(jogador->mesa->character == atacante) slot = 0;
    else if(jogador->mesa->monstro1 == atacante) slot = 1;
    else if(jogador->mesa->monstro2 == atacante) slot = 2;
    else if(jogador->mesa->monstro3 == atacante) slot = 3;
    else if(jogador->mesa->monstro4 == atacante) slot = 4;
    else if(jogador->mesa->monstro5 == atacante) slot = 5;
    else if(jogador->mesa->monstro6 == atacante) slot = 6;
    else if(jogador->mesa->monstro7 == atacante) slot = 7;

    if(slot == -1) printf("ERRO: Atacante %s nao encontrado!\n",atacante->origem->nome);
    return(slot);
}

//Efeitos que ocorrem quando monstro possui HP abaixo de determinado limiar!
void MonsterReactor(struct CARD *monstro,struct Card **buffer,bool *fim_de_jogo,int *rolagem,struct Player *jogador,struct Player *adversario,ALLEGRO_DISPLAY *display,ALLEGRO_BITMAP *selecao,ALLEGRO_BITMAP *roll_bar,ALLEGRO_BITMAP *fundo_carta,ALLEGRO_BITMAP *deck_meio,ALLEGRO_BITMAP *deck_cheio,ALLEGRO_BITMAP *fundo,ALLEGRO_FONT *font,ALLEGRO_COLOR color,ALLEGRO_BITMAP *apontador) {
    if(monstro->origem->colecao == BABY_DODONGO) monstro->var_monster->baby_dodongo_bool = true;

    //O efeito somente poderá ser usado se monstro puder realizar efeito ao receber dano.
}

void EquipReactor(bool modo,bool alvoCharacter,int dmg,struct CARD *equip,int id_acao,struct Card **buffer,bool *fim_de_jogo,int *rolagem,struct StatusBox_bitmaps *sbox,ALLEGRO_BITMAP *prompt,ALLEGRO_BITMAP *selecao,ALLEGRO_BITMAP *roll_bar,ALLEGRO_BITMAP *fundo_carta,ALLEGRO_BITMAP *fundo_menu,ALLEGRO_BITMAP *deck_meio,ALLEGRO_BITMAP *deck_cheio,ALLEGRO_BITMAP *pont,struct Player *jogador,struct Player *adversario,ALLEGRO_DISPLAY *display,ALLEGRO_BITMAP *fundo,ALLEGRO_FONT *font,ALLEGRO_FONT *font2,ALLEGRO_COLOR color,bool *sair,int *posX,int *posY,int *dltZ,bool *mouse,bool *mouse2,bool *mouse_lado,int *keychar,bool *repete_keychar,ALLEGRO_EVENT_QUEUE *event_queue,ALLEGRO_TIMER *keyb_press_timer,ALLEGRO_TIMER *mouse_press_timer) {
    if(equip == NULL) return;

    //MODO: 0 -> lado DEFENSIVO
    //      1 -> lado ATACANTE
    if(modo == false) {
        if(equip->origem->colecao == WORLDS_FINEST_EYE_DROPS && alvoCharacter == true && *(jogador->HP) > 0) RefreshHP(id_acao,buffer,jogador->mesa->character,10,fim_de_jogo,rolagem,sbox,prompt,selecao,roll_bar,fundo_carta,fundo_menu,deck_meio,deck_cheio,pont,jogador,adversario,display,fundo,font,font2,color,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);
        else if(equip->origem->colecao == MIRROR_SHIELD && alvoCharacter == true) mirror_shield_absorve_dano(equip,dmg);
    }
    //O efeito somente poderá ser usado se monstro puder realizar efeito ao receber dano.
}

void EquipBuff(bool *usa_weapon,int id_acao,bool aplicavel,struct CARD *atacante,struct Card **buffer,bool *fim_de_jogo,struct CARD *card,int *damage,int *rolagem,struct StatusBox_bitmaps *sbox,ALLEGRO_BITMAP *selecao,ALLEGRO_BITMAP *roll_bar,ALLEGRO_BITMAP *fundo_carta,ALLEGRO_BITMAP *fundo_menu,ALLEGRO_BITMAP *prompt,ALLEGRO_BITMAP *deck_meio,ALLEGRO_BITMAP *deck_cheio,ALLEGRO_BITMAP *bmp,struct Player *jogador,struct Player *adversario,ALLEGRO_DISPLAY *display,ALLEGRO_BITMAP *fundo,ALLEGRO_FONT *font,ALLEGRO_FONT *font2,ALLEGRO_COLOR color,bool *sair,int *posX,int *posY,int *dltZ,bool *mouse,bool *mouse2,bool *mouse_lado,int *keychar,bool *repete_keychar,ALLEGRO_EVENT_QUEUE *event_queue,ALLEGRO_TIMER *keyb_press_timer,ALLEGRO_TIMER *mouse_press_timer) {
    if(*fim_de_jogo == true) return;

    if(card != NULL) {
        if(card->origem->colecao == GOLDEN_SCALE && atacante != NULL && strcmp(atacante->origem->elemento,"Water") == 0 && ehMonstro(atacante)) {
            *damage = *damage + 10;
            printf("BUFF: GOLDEN SCALE\n");
        }
        else if(card->var_equip->master_sword_cont > 0 && atacante->origem->character != NULL && aplicavel == true) master_sword_acao(usa_weapon,id_acao,buffer,fim_de_jogo,card,damage,rolagem,sbox,selecao,roll_bar,fundo_carta,fundo_menu,prompt,deck_meio,deck_cheio,bmp,jogador,adversario,display,fundo,font,font2,color,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);
        else if(card->var_equip->skull_mask_cont > 0 && atacante->origem->character != NULL && aplicavel == true) skull_mask_acao(id_acao,buffer,fim_de_jogo,card,damage,rolagem,sbox,selecao,roll_bar,fundo_carta,fundo_menu,prompt,deck_meio,deck_cheio,bmp,jogador,adversario,display,fundo,font,font2,color,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);
        else if(card->var_equip->fairy_slingshot_cont > 0 && atacante->origem->character != NULL && aplicavel == true) fairy_slingshot_acao(usa_weapon,id_acao,buffer,fim_de_jogo,card,damage,rolagem,sbox,selecao,roll_bar,fundo_carta,fundo_menu,prompt,deck_meio,deck_cheio,bmp,jogador,adversario,display,fundo,font,font2,color,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);
        else if(card->var_equip->silver_gauntlets_cont > 0 && atacante->origem->character != NULL && aplicavel == true && jogador->var_tactic->_1trl_gauntlet_cont == 0) silver_gauntlets_acao(id_acao,buffer,fim_de_jogo,card,damage,rolagem,sbox,selecao,roll_bar,fundo_carta,fundo_menu,prompt,deck_meio,deck_cheio,bmp,jogador,adversario,display,fundo,font,font2,color,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);
        else if(card->var_equip->golden_gauntlets_cont > 0 && atacante->origem->character != NULL && aplicavel == true && jogador->var_tactic->_1trl_gauntlet_cont == 0) golden_gauntlets_acao(id_acao,buffer,fim_de_jogo,card,damage,rolagem,sbox,selecao,roll_bar,fundo_carta,fundo_menu,prompt,deck_meio,deck_cheio,bmp,jogador,adversario,display,fundo,font,font2,color,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);
        else if(card->var_equip->bomb_cont > 0 && atacante->origem->character != NULL && aplicavel == true) bomb_acao(usa_weapon,id_acao,buffer,fim_de_jogo,card,damage,rolagem,sbox,selecao,roll_bar,fundo_carta,fundo_menu,prompt,deck_meio,deck_cheio,bmp,jogador,adversario,display,fundo,font,font2,color,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);
        else if(card->var_equip->boomerang_cont > 0 && atacante->origem->character != NULL && aplicavel == true) boomerang_acao(usa_weapon,id_acao,buffer,fim_de_jogo,card,damage,rolagem,sbox,selecao,roll_bar,fundo_carta,fundo_menu,prompt,deck_meio,deck_cheio,bmp,jogador,adversario,display,fundo,font,font2,color,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);
        else if(card->var_equip->magic_beans_bool == true && atacante->origem->character != NULL) {
            *damage = *damage + 10;
            printf("BUFF: MAGIC BEANS\n");
        }
        else if(card->origem->colecao == GORON_RUBY && atacante != NULL && strcmp(atacante->origem->elemento,"Fire") == 0 && ehMonstro(atacante)) {
            *damage = *damage + 10;
            printf("BUFF: GORON RUBY\n");
        }
    }
}

void VerificaDungeonMap(int *val,struct Player *jogador,struct Player *adversario) {
    if(jogador->mesa->equip1 != NULL && jogador->mesa->equip1->origem->colecao == DUNGEON_MAP) *val += 10;
    if(jogador->mesa->equip2 != NULL && jogador->mesa->equip2->origem->colecao == DUNGEON_MAP) *val += 10;
    if(jogador->mesa->equip3 != NULL && jogador->mesa->equip3->origem->colecao == DUNGEON_MAP) *val += 10;
    if(jogador->mesa->equip4 != NULL && jogador->mesa->equip4->origem->colecao == DUNGEON_MAP) *val += 10;
    if(jogador->mesa->equip5 != NULL && jogador->mesa->equip5->origem->colecao == DUNGEON_MAP) *val += 10;
    if(jogador->mesa->equip6 != NULL && jogador->mesa->equip6->origem->colecao == DUNGEON_MAP) *val += 10;
    if(jogador->mesa->equip7 != NULL && jogador->mesa->equip7->origem->colecao == DUNGEON_MAP) *val += 10;

    if(AplicaMapaAdversario(adversario)) {
        if(adversario->mesa->equip1 != NULL && adversario->mesa->equip1->origem->colecao == DUNGEON_MAP) *val += 10;
        if(adversario->mesa->equip2 != NULL && adversario->mesa->equip2->origem->colecao == DUNGEON_MAP) *val += 10;
        if(adversario->mesa->equip3 != NULL && adversario->mesa->equip3->origem->colecao == DUNGEON_MAP) *val += 10;
        if(adversario->mesa->equip4 != NULL && adversario->mesa->equip4->origem->colecao == DUNGEON_MAP) *val += 10;
        if(adversario->mesa->equip5 != NULL && adversario->mesa->equip5->origem->colecao == DUNGEON_MAP) *val += 10;
        if(adversario->mesa->equip6 != NULL && adversario->mesa->equip6->origem->colecao == DUNGEON_MAP) *val += 10;
        if(adversario->mesa->equip7 != NULL && adversario->mesa->equip7->origem->colecao == DUNGEON_MAP) *val += 10;
    }
}

void EfetuaBuff_atk(struct CARD *card,int *damage) {
    struct BuffInstance *aux = card->buff_list;

    while(aux->prox != NULL) {
        (*damage) += aux->atk;
        aux = aux->prox;
    }
}

void EfetuaBuff_def(struct CARD *card,int *block) {
    if(card == NULL) return;
    struct BuffInstance *aux = card->buff_list;

    while(aux->prox != NULL) {
        (*block) += aux->def;
        aux = aux->prox;
    }
}

void EfetuaBuff_hp(struct CARD *card,int hp) {
    card->MaxHP += hp;
    card->HP += hp;
}

void EfetuaBuff_slot(struct CARD *card) {
    struct BuffInstance *aux,*aux2 = NULL;

    aux = card->buff_list;
    while(aux->prox != NULL) {
        printf("Detectou um (%d,%d,%d)\n",aux->hp,aux->atk,aux->def);
        if(aux->turns_left == 0) {
            if(aux2 == NULL) {
                card->buff_list = aux->prox;
                free(aux);
                aux = card->buff_list;
            }
            else {
                aux2->prox = aux->prox;
                free(aux);
                aux = aux2->prox;
            }

            continue;
        }
        else EfetuaBuff_hp(card,aux->hp);
        aux->turns_left--;

        aux2 = aux;
        aux = aux->prox;
    }
}

void NextAttackBonus(int *damage,struct Player *jogador,int origem_ataque,bool aplicavel) {
    *damage += (jogador->bombchu_cont * 10);
    if(jogador->bombchu_cont > 0) {
        printf("BUFF: BOMBCHU x %d\n",jogador->bombchu_cont);
        if(aplicavel) jogador->bombchu_cont = 0;
    }

    if(jogador->var_tactic->turn_next_attack_bonus > 0) {
            *damage += jogador->var_tactic->turn_next_attack_bonus;
            printf("BUFF: generic NEXT ATTACK BONUS DMG: %d\n",jogador->var_tactic->turn_next_attack_bonus);
            if(aplicavel) {
                jogador->var_tactic->turn_next_attack_bonus = 0;
            }
        }

    if(jogador->var_tactic->great_dekus_bless_cont > 0 && (origem_ataque == 0 || origem_ataque == 2)) great_dekus_bless_tactic(damage,&(jogador->var_tactic->great_dekus_bless_cont),aplicavel);
    if(jogador->var_tactic->great_fairys_bless_cont > 0 && origem_ataque == 0) great_fairys_bless_tactic(damage,&(jogador->var_tactic->great_fairys_bless_cont),aplicavel);
}

int BalanceamentoAtaque(bool *usa_weapon,int id_acao,bool aplicavel,struct Card **buffer,bool *fim_de_jogo,int *rolagem,int origem_ataque,struct Player *jogador,struct Player *adversario,struct CARD *atacante,int dano_inicial,ALLEGRO_DISPLAY *display,struct StatusBox_bitmaps *sbox,ALLEGRO_BITMAP *selecao,ALLEGRO_BITMAP *roll_bar,ALLEGRO_BITMAP *fundo_carta,ALLEGRO_BITMAP *fundo_menu,ALLEGRO_BITMAP *deck_meio,ALLEGRO_BITMAP *deck_cheio,ALLEGRO_BITMAP *fundo,ALLEGRO_BITMAP *prompt,ALLEGRO_FONT *font,ALLEGRO_FONT *font2,ALLEGRO_COLOR color,ALLEGRO_BITMAP *bmp,bool *sair,int *posX,int *posY,int *dltZ,bool *mouse,bool *mouse2,bool *mouse_lado,int *keychar,bool *repete_keychar,ALLEGRO_EVENT_QUEUE *event_queue,ALLEGRO_TIMER *keyb_press_timer,ALLEGRO_TIMER *mouse_press_timer) {
    //funcoes que ajudam ou prejudicam a quantidade de dano...
    //Possui funcoes de field effect, para character!
    int damage = dano_inicial,aux,val,debug;

    debug = damage;
    EfetuaBuff_atk(atacante,&damage);
    if(damage - debug > 0) printf("BUFFS ATK ativos (%d)\n",damage - debug);

    if(origem_ataque == 1) {    //Aumenta damage de character somente.
        if(jogador->mesa->field != NULL && ((jogador->mesa->field->origem->colecao == DESERT_COLOSSUS && !strcmp(jogador->mesa->character->origem->elemento,"Wind")) || (jogador->mesa->field->origem->colecao == HYRULE_CASTLE && !strcmp(jogador->mesa->character->origem->elemento,"Light")) || (jogador->mesa->field->origem->colecao == KAKARIKO_GRAVEYARD && !strcmp(jogador->mesa->character->origem->elemento,"Dark")) || (jogador->mesa->field->origem->colecao == FIRE_TEMPLE && !strcmp(jogador->mesa->character->origem->elemento,"Fire")))) {
            val = 10;
            VerificaDungeonMap(&val,jogador,adversario);
            printf("MAP bonus: %d\n",val);
            damage += val;
        }
        else if(jogador->mesa->field == NULL && adversario->mesa->field != NULL && ((adversario->mesa->field->origem->colecao == DESERT_COLOSSUS && !strcmp(jogador->mesa->character->origem->elemento,"Wind")) || (adversario->mesa->field->origem->colecao == HYRULE_CASTLE && !strcmp(jogador->mesa->character->origem->elemento,"Light")) || (adversario->mesa->field->origem->colecao == KAKARIKO_GRAVEYARD && !strcmp(jogador->mesa->character->origem->elemento,"Dark")) || (adversario->mesa->field->origem->colecao == FIRE_TEMPLE && !strcmp(jogador->mesa->character->origem->elemento,"Fire")))) {
            val = 10;
            VerificaDungeonMap(&val,jogador,adversario);
            printf("MAP bonus: %d\n",val);
            damage += val;
        }
            //outros fields...


        if(jogador->mesa->field != NULL && ((jogador->mesa->field->origem->colecao == GERUDO_FORTRESS && !strcmp(jogador->mesa->character->origem->elemento,"Wind")) || (jogador->mesa->field->origem->colecao == LAKE_HYLIA && !strcmp(jogador->mesa->character->origem->elemento,"Water")) || (jogador->mesa->field->origem->colecao == KOKIRI_FOREST && !strcmp(jogador->mesa->character->origem->elemento,"Earth")) || (jogador->mesa->field->origem->colecao == DEATH_MT_CRATER && !strcmp(jogador->mesa->character->origem->elemento,"Fire")) || (jogador->mesa->field->origem->colecao == GANONS_CASTLE && !strcmp(jogador->mesa->character->origem->elemento,"Dark")))) {
            val = 20;
            VerificaDungeonMap(&val,jogador,adversario);
            printf("MAP bonus: %d\n",val);
            damage += val;
        }
        else if(jogador->mesa->field == NULL && adversario->mesa->field != NULL && ((adversario->mesa->field->origem->colecao == GERUDO_FORTRESS && !strcmp(jogador->mesa->character->origem->elemento,"Wind")) || (adversario->mesa->field->origem->colecao == LAKE_HYLIA && !strcmp(jogador->mesa->character->origem->elemento,"Water")) || (adversario->mesa->field->origem->colecao == KOKIRI_FOREST && !strcmp(jogador->mesa->character->origem->elemento,"Earth")) || (adversario->mesa->field->origem->colecao == DEATH_MT_CRATER && !strcmp(jogador->mesa->character->origem->elemento,"Fire")) || (adversario->mesa->field->origem->colecao == GANONS_CASTLE && !strcmp(jogador->mesa->character->origem->elemento,"Dark")))) {
            val = 20;
            VerificaDungeonMap(&val,jogador,adversario);
            printf("MAP bonus: %d\n",val);
            damage += val;
        }
            //outros fields...

        if(jogador->mesa->field != NULL && !strcmp(jogador->mesa->field->origem->elemento,"Water")) {
            debug = damage;
            golden_scale_acao(jogador,&damage);
            if(damage - debug > 0) printf("BUFF: GOLDEN_SCALE x %d\n",(damage - debug) / 10);
        }
        else if(adversario->mesa->field != NULL && !strcmp(adversario->mesa->field->origem->elemento,"Water")) {
            debug = damage;
            golden_scale_acao(jogador,&damage);
            if(damage - debug > 0) printf("BUFF: GOLDEN_SCALE x %d\n",(damage - debug) / 10);
        }

        if(jogador->var_tactic->flood_buff_bool == true) {
            damage += 10;
            printf("BUFF: FLOOD\n");
        }

        damage += (10 * jogador->var_tactic->fairys_aid_cont);
        if(jogador->var_tactic->fairys_aid_cont > 0) printf("BUFF: FAIRYS_AID x %d\n",jogador->var_tactic->fairys_aid_cont);

        if(jogador->var_tactic->horse_riding_cont > 0 && aplicavel == true) horse_riding_prompt(id_acao,buffer,fim_de_jogo,&damage,rolagem,sbox,selecao,roll_bar,fundo_carta,fundo_menu,prompt,deck_meio,deck_cheio,bmp,jogador,adversario,display,fundo,font,font2,color,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);
        if(jogador->var_tactic->_1trl_gauntlet_cont > 0) {
            if(!PossuiGauntlets(jogador)) {
                if(aplicavel == true) _1_ton_rock_lifting_prompt(&(jogador->var_tactic->_1trl_gauntlet_cont),id_acao,buffer,fim_de_jogo,&damage,rolagem,sbox,selecao,roll_bar,fundo_carta,fundo_menu,prompt,deck_meio,deck_cheio,bmp,jogador,adversario,display,fundo,font,font2,color,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);
            }
            else {
                printf("BUFF: 1TRL x %d\n",jogador->var_tactic->_1trl_gauntlet_cont);
                damage += (10 * jogador->var_tactic->_1trl_gauntlet_cont);
            }
        }
        else if(jogador->var_tactic->_1trl_no_gauntlet_cont > 0 && aplicavel == true) {
            _1_ton_rock_lifting_prompt(&(jogador->var_tactic->_1trl_no_gauntlet_cont),id_acao,buffer,fim_de_jogo,&damage,rolagem,sbox,selecao,roll_bar,fundo_carta,fundo_menu,prompt,deck_meio,deck_cheio,bmp,jogador,adversario,display,fundo,font,font2,color,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);
        }

        if(jogador->var_tactic->channeled_strike_charged_cont > 0) {
            printf("BUFF: channeled strike x%d\n",jogador->var_tactic->channeled_strike_charged_cont);
            damage += (10 * jogador->var_tactic->channeled_strike_charged_cont);
        }

    }

    NextAttackBonus(&damage,jogador,origem_ataque,aplicavel);

    //printf("Parte 2\n");

    if(jogador->level >= 90 && jogador->wind_ic >= 2 && (origem_ataque == 0 || origem_ataque == 1 || origem_ataque == 2)) {
        debug = damage;
        if(jogador->mesa->monstro1 != NULL && jogador->mesa->monstro1->origem->colecao == TWINROVA && jogador->mesa->monstro1->HP <= 80 && jogador->mesa->monstro1->turn_silenced == 0) damage += 20;
        if(jogador->mesa->monstro2 != NULL && jogador->mesa->monstro2->origem->colecao == TWINROVA && jogador->mesa->monstro2->HP <= 80 && jogador->mesa->monstro2->turn_silenced == 0) damage += 20;
        if(jogador->mesa->monstro3 != NULL && jogador->mesa->monstro3->origem->colecao == TWINROVA && jogador->mesa->monstro3->HP <= 80 && jogador->mesa->monstro3->turn_silenced == 0) damage += 20;
        if(jogador->mesa->monstro4 != NULL && jogador->mesa->monstro4->origem->colecao == TWINROVA && jogador->mesa->monstro4->HP <= 80 && jogador->mesa->monstro4->turn_silenced == 0) damage += 20;
        if(jogador->mesa->monstro5 != NULL && jogador->mesa->monstro5->origem->colecao == TWINROVA && jogador->mesa->monstro5->HP <= 80 && jogador->mesa->monstro5->turn_silenced == 0) damage += 20;
        if(jogador->mesa->monstro6 != NULL && jogador->mesa->monstro6->origem->colecao == TWINROVA && jogador->mesa->monstro6->HP <= 80 && jogador->mesa->monstro6->turn_silenced == 0) damage += 20;
        if(jogador->mesa->monstro7 != NULL && jogador->mesa->monstro7->origem->colecao == TWINROVA && jogador->mesa->monstro7->HP <= 80 && jogador->mesa->monstro7->turn_silenced == 0) damage += 20;

        if(damage - debug > 0) printf("BUFF: TWINROVA x %d\n",(damage - debug) / 20);
    }

    //printf("Parte 2.2\n");
    if(origem_ataque == 0 && atacante != NULL) {
        if(jogador->mesa->field != NULL && ((jogador->mesa->field->origem->colecao == DESERT_COLOSSUS && !strcmp(atacante->origem->elemento,"Wind")) || (jogador->mesa->field->origem->colecao == HYRULE_CASTLE && !strcmp(atacante->origem->elemento,"Light")) || (jogador->mesa->field->origem->colecao == KAKARIKO_GRAVEYARD && !strcmp(atacante->origem->elemento,"Dark")) || (jogador->mesa->field->origem->colecao == FIRE_TEMPLE && !strcmp(atacante->origem->elemento,"Fire")))) {
            val = 20;
            VerificaDungeonMap(&val,jogador,adversario);
            printf("MAP bonus: %d\n",val);
            damage += val;
        }
        else if(jogador->mesa->field == NULL && adversario->mesa->field != NULL && ((adversario->mesa->field->origem->colecao == DESERT_COLOSSUS && !strcmp(atacante->origem->elemento,"Wind")) || (adversario->mesa->field->origem->colecao == HYRULE_CASTLE && !strcmp(atacante->origem->elemento,"Light")) || (adversario->mesa->field->origem->colecao == KAKARIKO_GRAVEYARD && !strcmp(atacante->origem->elemento,"Dark")) || (adversario->mesa->field->origem->colecao == FIRE_TEMPLE && !strcmp(atacante->origem->elemento,"Fire")))) {
            val = 20;
            VerificaDungeonMap(&val,jogador,adversario);
            printf("MAP bonus: %d\n",val);
            damage += val;
        }
            //outros fields...


        if(jogador->mesa->field != NULL && ((jogador->mesa->field->origem->colecao == GERUDO_FORTRESS && !strcmp(atacante->origem->elemento,"Wind")) || (jogador->mesa->field->origem->colecao == LAKE_HYLIA && !strcmp(atacante->origem->elemento,"Water")) || (jogador->mesa->field->origem->colecao == KOKIRI_FOREST && !strcmp(atacante->origem->elemento,"Earth")) || (jogador->mesa->field->origem->colecao == DEATH_MT_CRATER && !strcmp(atacante->origem->elemento,"Fire")) || (jogador->mesa->field->origem->colecao == GANONS_CASTLE && !strcmp(atacante->origem->elemento,"Dark")))) {
            val = 10;
            VerificaDungeonMap(&val,jogador,adversario);
            printf("MAP bonus: %d\n",val);
            damage += val;
        }
        else if(jogador->mesa->field == NULL && adversario->mesa->field != NULL && ((adversario->mesa->field->origem->colecao == GERUDO_FORTRESS && !strcmp(atacante->origem->elemento,"Wind")) || (adversario->mesa->field->origem->colecao == LAKE_HYLIA && !strcmp(atacante->origem->elemento,"Water")) || (adversario->mesa->field->origem->colecao == KOKIRI_FOREST && !strcmp(atacante->origem->elemento,"Earth")) || (adversario->mesa->field->origem->colecao == DEATH_MT_CRATER && !strcmp(atacante->origem->elemento,"Fire")) || (adversario->mesa->field->origem->colecao == GANONS_CASTLE && !strcmp(atacante->origem->elemento,"Dark")))) {
            val = 10;
            VerificaDungeonMap(&val,jogador,adversario);
            printf("MAP bonus: %d\n",val);
            damage += val;
        }
            //outros fields...

        damage += (30*atacante->var_monster->giant_leever_bool);
        if(atacante->var_monster->giant_leever_bool > 0) printf("BUFF: GIANT LEEVER CALL\n");

        damage += (20*atacante->var_monster->rage_buff_bool);
        if(atacante->var_monster->rage_buff_bool > 0) printf("BUFF: RAGE BUFF\n");

        damage += (30*atacante->var_monster->milk_bottle_bool);
        if(atacante->var_monster->milk_bottle_bool > 0) printf("BUFF: MILK BOTTLE LVUP\n");

        damage += (30*atacante->var_monster->bless_of_triforce_buff_cont);
        if(atacante->var_monster->bless_of_triforce_buff_cont > 0) printf("BUFF: BLESS OF TRIFORCE x %d\n",atacante->var_monster->bless_of_triforce_buff_cont);

        damage += (20*atacante->var_monster->pierre_cont);
        if(atacante->var_monster->pierre_cont > 0) printf("BUFF: PIERRE x %d\n",atacante->var_monster->pierre_cont);

        damage += atacante->var_monster->bomb_bag_bonus_dmg_cont;
        if(atacante->var_monster->bomb_bag_bonus_dmg_cont > 0) printf("BUFF: BOMB BAG BONUS x %d\n",atacante->var_monster->bomb_bag_bonus_dmg_cont / 10);

        if(jogador->var_tactic->skullwalltula_cont > 0 && strstr(atacante->origem->str_concat,"Spider") != NULL) {
            printf("BUFF: SKULLWALLTULA CONT x %d\n",jogador->var_tactic->skullwalltula_cont);
            damage += (20*jogador->var_tactic->skullwalltula_cont);
        }

        if(jogador->var_tactic->buff_cont > 0) {
            damage += 10 * jogador->var_tactic->buff_cont;
            printf("ACTION BUFF x %d\n",jogador->var_tactic->buff_cont);
        }

        damage += (20 * jogador->var_tactic->fairy_fountain_cont);
        if(jogador->var_tactic->fairy_fountain_cont > 0) printf("BUFF: FAIRY_FOUNTAIN x %d\n",jogador->var_tactic->fairy_fountain_cont);

        damage += (10*jogador->var_tactic->assistance_cont);
        if(jogador->var_tactic->assistance_cont > 0) printf("BUFF: ASSISTANCE x %d\n",jogador->var_tactic->assistance_cont);
        if(aplicavel == true) jogador->var_tactic->assistance_cont = 0;

        if(strcmp(atacante->origem->elemento,"Fire") == 0) {
            debug = damage;
            if(jogador->mesa->monstro1 != NULL && jogador->mesa->monstro1->origem->colecao == FLARE_DANCER && jogador->mesa->monstro1->turn_silenced == 0) damage += 20;
            if(jogador->mesa->monstro2 != NULL && jogador->mesa->monstro2->origem->colecao == FLARE_DANCER && jogador->mesa->monstro2->turn_silenced == 0) damage += 20;
            if(jogador->mesa->monstro3 != NULL && jogador->mesa->monstro3->origem->colecao == FLARE_DANCER && jogador->mesa->monstro3->turn_silenced == 0) damage += 20;
            if(jogador->mesa->monstro4 != NULL && jogador->mesa->monstro4->origem->colecao == FLARE_DANCER && jogador->mesa->monstro4->turn_silenced == 0) damage += 20;
            if(jogador->mesa->monstro5 != NULL && jogador->mesa->monstro5->origem->colecao == FLARE_DANCER && jogador->mesa->monstro5->turn_silenced == 0) damage += 20;
            if(jogador->mesa->monstro6 != NULL && jogador->mesa->monstro6->origem->colecao == FLARE_DANCER && jogador->mesa->monstro6->turn_silenced == 0) damage += 20;
            if(jogador->mesa->monstro7 != NULL && jogador->mesa->monstro7->origem->colecao == FLARE_DANCER && jogador->mesa->monstro7->turn_silenced == 0) damage += 20;
            if(atacante->origem->colecao == FLARE_DANCER && atacante->turn_silenced == 0) damage -= 20;    //flare dancer nao incrementa proprio ataque!
            if(damage - debug > 0) printf("BUFF: FLARE DANCER AURA x %d\n",(damage - debug) / 20);

            debug = damage;
            raze_bonusdmg(&damage,jogador);
            raze_bonusdmg(&damage,adversario);
            if(damage - debug > 0) printf("RAZE x %d\n",(damage - debug) / 20);
        }
        else if(strcmp(atacante->origem->elemento,"Wind") == 0) {
            damage += (10 * jogador->var_tactic->spirit_medallion_cont);
            if(jogador->var_tactic->spirit_medallion_cont > 0) printf("BUFF: jogador SPIRIT MEDALLION x %d\n",jogador->var_tactic->spirit_medallion_cont);
            damage += (10 * adversario->var_tactic->spirit_medallion_cont);
            if(adversario->var_tactic->spirit_medallion_cont > 0) printf("BUFF: adversario SPIRIT MEDALLION x %d\n",adversario->var_tactic->spirit_medallion_cont);

            damage += (10 * jogador->var_tactic->gerudos_membership_card_cont);
            if(jogador->var_tactic->gerudos_membership_card_cont > 0) printf("BUFF: jogador GERUDOS MEMBERSHIP CARD x %d\n",jogador->var_tactic->gerudos_membership_card_cont);
            damage += (10 * adversario->var_tactic->gerudos_membership_card_cont);
            if(jogador->var_tactic->gerudos_membership_card_cont > 0) printf("BUFF: adversario GERUDOS MEMBERSHIP CARD x %d\n",adversario->var_tactic->gerudos_membership_card_cont);
        }
        else if(strcmp(atacante->origem->elemento,"Earth") == 0) {
            if(jogador->var_tactic->mido_bool == true) {
                printf("BUFF: Mido aura\n");
                damage += 20;
            }

            debug = damage;
            if(jogador->mesa->monstro1 != NULL && jogador->mesa->monstro1->origem->colecao == DEAD_HAND && jogador->mesa->monstro1->turn_silenced == 0) damage += 10;
            if(jogador->mesa->monstro2 != NULL && jogador->mesa->monstro2->origem->colecao == DEAD_HAND && jogador->mesa->monstro2->turn_silenced == 0) damage += 10;
            if(jogador->mesa->monstro3 != NULL && jogador->mesa->monstro3->origem->colecao == DEAD_HAND && jogador->mesa->monstro3->turn_silenced == 0) damage += 10;
            if(jogador->mesa->monstro4 != NULL && jogador->mesa->monstro4->origem->colecao == DEAD_HAND && jogador->mesa->monstro4->turn_silenced == 0) damage += 10;
            if(jogador->mesa->monstro5 != NULL && jogador->mesa->monstro5->origem->colecao == DEAD_HAND && jogador->mesa->monstro5->turn_silenced == 0) damage += 10;
            if(jogador->mesa->monstro6 != NULL && jogador->mesa->monstro6->origem->colecao == DEAD_HAND && jogador->mesa->monstro6->turn_silenced == 0) damage += 10;
            if(jogador->mesa->monstro7 != NULL && jogador->mesa->monstro7->origem->colecao == DEAD_HAND && jogador->mesa->monstro7->turn_silenced == 0) damage += 10;
            if(atacante->origem->colecao == DEAD_HAND && atacante->turn_silenced == 0) damage -= 10;    //dead hand nao incrementa proprio ataque!

            if(damage - debug > 0) printf("BUFF: DEAD_HAND AURA x %d\n",(damage - debug) / 10);
        }
        else if(strcmp(atacante->origem->elemento,"Dark") == 0) {
            damage += (10 * jogador->var_tactic->dark_pathway_cont);
            if(jogador->var_tactic->dark_pathway_cont > 0) printf("BUFF: jogador DARK PATHWAY x %d\n",jogador->var_tactic->dark_pathway_cont);
            damage += (10 * adversario->var_tactic->dark_pathway_cont);
            if(jogador->var_tactic->dark_pathway_cont > 0) printf("BUFF: adversario DARK PATHWAY x %d\n",adversario->var_tactic->dark_pathway_cont);

            if(jogador->var_tactic->ganondorf_bool == true) {
                printf("BUFF: Ganondorf aura\n");
                damage += 10;
            }
        }
        else if(strcmp(atacante->origem->elemento,"Water") == 0) {
            if(jogador->var_tactic->tidal_strike_bool == true) {
                damage += (10 * tidal_strike_multiplier(jogador));
                printf("BUFF: TIDAL STRIKE (+%d0 dmg)\n",tidal_strike_multiplier(jogador));
            }
        }
        else if(strcmp(atacante->origem->elemento,"Light") == 0) {
            damage += (20 * jogador->var_tactic->light_medallion_cont);
            if(jogador->var_tactic->light_medallion_cont > 0) printf("BUFF: jogador LIGHT MEDALLION x %d\n",jogador->var_tactic->light_medallion_cont);
            damage += (20 * adversario->var_tactic->light_medallion_cont);
            if(adversario->var_tactic->light_medallion_cont > 0) printf("BUFF: adversario LIGHT MEDALLION x %d\n",adversario->var_tactic->light_medallion_cont);
        }
        else printf("WTF?! Detectou '%s' para '%s'\n",atacante->origem->elemento,atacante->origem->nome);

        if(strstr(atacante->origem->str_concat,"Worm") != NULL) {
            debug = damage;
            if(jogador->mesa->monstro1 != NULL && jogador->mesa->monstro1->origem->colecao == GIANT_LEEVER && jogador->mesa->monstro1->turn_silenced == 0) damage += 20;
            if(jogador->mesa->monstro2 != NULL && jogador->mesa->monstro2->origem->colecao == GIANT_LEEVER && jogador->mesa->monstro2->turn_silenced == 0) damage += 20;
            if(jogador->mesa->monstro3 != NULL && jogador->mesa->monstro3->origem->colecao == GIANT_LEEVER && jogador->mesa->monstro3->turn_silenced == 0) damage += 20;
            if(jogador->mesa->monstro4 != NULL && jogador->mesa->monstro4->origem->colecao == GIANT_LEEVER && jogador->mesa->monstro4->turn_silenced == 0) damage += 20;
            if(jogador->mesa->monstro5 != NULL && jogador->mesa->monstro5->origem->colecao == GIANT_LEEVER && jogador->mesa->monstro5->turn_silenced == 0) damage += 20;
            if(jogador->mesa->monstro6 != NULL && jogador->mesa->monstro6->origem->colecao == GIANT_LEEVER && jogador->mesa->monstro6->turn_silenced == 0) damage += 20;
            if(jogador->mesa->monstro7 != NULL && jogador->mesa->monstro7->origem->colecao == GIANT_LEEVER && jogador->mesa->monstro7->turn_silenced == 0) damage += 20;
            if(damage - debug > 0) printf("BUFF: GIANT LEEVER aura (%d dmg)\n",damage - debug);
        }

        if(atacante->origem->colecao == BLUE_TEKTITE && atacante->turn_silenced == 0 && ((jogador->mesa->field != NULL && !strcmp(jogador->mesa->field->origem->elemento,"Water")) || (adversario->mesa->field != NULL && !strcmp(adversario->mesa->field->origem->elemento,"Water")))) {
            printf("BUFF: Blue Tektite\n");
            damage += 20;
        }

        debug = damage;
        if(jogador->mesa->monstro1 != NULL && jogador->mesa->monstro1->origem->colecao == FABULOUS_FIVE_FROGGISH_TENORS && jogador->mesa->monstro1->turn_silenced == 0) damage += 10;
        if(jogador->mesa->monstro2 != NULL && jogador->mesa->monstro2->origem->colecao == FABULOUS_FIVE_FROGGISH_TENORS && jogador->mesa->monstro2->turn_silenced == 0) damage += 10;
        if(jogador->mesa->monstro3 != NULL && jogador->mesa->monstro3->origem->colecao == FABULOUS_FIVE_FROGGISH_TENORS && jogador->mesa->monstro3->turn_silenced == 0) damage += 10;
        if(jogador->mesa->monstro4 != NULL && jogador->mesa->monstro4->origem->colecao == FABULOUS_FIVE_FROGGISH_TENORS && jogador->mesa->monstro4->turn_silenced == 0) damage += 10;
        if(jogador->mesa->monstro5 != NULL && jogador->mesa->monstro5->origem->colecao == FABULOUS_FIVE_FROGGISH_TENORS && jogador->mesa->monstro5->turn_silenced == 0) damage += 10;
        if(jogador->mesa->monstro6 != NULL && jogador->mesa->monstro6->origem->colecao == FABULOUS_FIVE_FROGGISH_TENORS && jogador->mesa->monstro6->turn_silenced == 0) damage += 10;
        if(jogador->mesa->monstro7 != NULL && jogador->mesa->monstro7->origem->colecao == FABULOUS_FIVE_FROGGISH_TENORS && jogador->mesa->monstro7->turn_silenced == 0) damage += 10;
        if(damage - debug > 0) printf("BUFF: FROG (+%d)\n",damage-debug);

        if(jogador->var_tactic->gerudo_guard_bool == true && GerudoPresente(jogador,&aux)) {
            damage += 20 * aux;
            printf("BUFF: GERUDO GUARD\n");
        }

        if(jogador->var_tactic->blue_potion_cont > 0) {
            damage += (10 * jogador->var_tactic->blue_potion_cont);
            printf("BUFF: BLUE POTION x %d\n",jogador->var_tactic->blue_potion_cont);
        }

        if(jogador->var_tactic->char_withdrawal_cont > 0) {
            damage += (10*jogador->var_tactic->char_withdrawal_cont);
            printf("BUFF: WITHDRAW x %d\n",jogador->var_tactic->char_withdrawal_cont);
        }

        if(atacante->origem->colecao == LIZALFOS && atacante->turn_silenced == 0) {
            damage += (atacante->var_monster->lizalfos_cont * 10);
            printf("BUFF: LIZALFOS x %d\n",atacante->var_monster->lizalfos_cont);
        }

        if(jogador->var_tactic->_1trl_gauntlet_cont > 0 && PossuiGauntlets(jogador)) {
            damage += 10;
            printf("BUFF: 1TRL x %d\n",jogador->var_tactic->_1trl_gauntlet_cont);
        }

        if(atacante->origem->colecao == WHITE_WOLFOS && atacante->turn_silenced == 0 && atacante->var_monster->white_wolfos_dmg_cont > 0) {
            damage += atacante->var_monster->white_wolfos_dmg_cont;
            printf("BUFF: WHITE WOLFOS bonus (%d dmg)\n",atacante->var_monster->white_wolfos_dmg_cont);
        }
    }
    //printf("Parte 2.3\n");

    //por natureza, EquipBuff deve satisfazer ataques efetuados por character e monsters.
    EquipBuff(usa_weapon,id_acao,aplicavel,atacante,buffer,fim_de_jogo,jogador->mesa->equip1,&damage,rolagem,sbox,selecao,roll_bar,fundo_carta,fundo_menu,prompt,deck_meio,deck_cheio,bmp,jogador,adversario,display,fundo,font,font2,color,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);
    EquipBuff(usa_weapon,id_acao,aplicavel,atacante,buffer,fim_de_jogo,jogador->mesa->equip2,&damage,rolagem,sbox,selecao,roll_bar,fundo_carta,fundo_menu,prompt,deck_meio,deck_cheio,bmp,jogador,adversario,display,fundo,font,font2,color,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);
    EquipBuff(usa_weapon,id_acao,aplicavel,atacante,buffer,fim_de_jogo,jogador->mesa->equip3,&damage,rolagem,sbox,selecao,roll_bar,fundo_carta,fundo_menu,prompt,deck_meio,deck_cheio,bmp,jogador,adversario,display,fundo,font,font2,color,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);
    EquipBuff(usa_weapon,id_acao,aplicavel,atacante,buffer,fim_de_jogo,jogador->mesa->equip4,&damage,rolagem,sbox,selecao,roll_bar,fundo_carta,fundo_menu,prompt,deck_meio,deck_cheio,bmp,jogador,adversario,display,fundo,font,font2,color,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);
    EquipBuff(usa_weapon,id_acao,aplicavel,atacante,buffer,fim_de_jogo,jogador->mesa->equip5,&damage,rolagem,sbox,selecao,roll_bar,fundo_carta,fundo_menu,prompt,deck_meio,deck_cheio,bmp,jogador,adversario,display,fundo,font,font2,color,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);
    EquipBuff(usa_weapon,id_acao,aplicavel,atacante,buffer,fim_de_jogo,jogador->mesa->equip6,&damage,rolagem,sbox,selecao,roll_bar,fundo_carta,fundo_menu,prompt,deck_meio,deck_cheio,bmp,jogador,adversario,display,fundo,font,font2,color,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);
    EquipBuff(usa_weapon,id_acao,aplicavel,atacante,buffer,fim_de_jogo,jogador->mesa->equip7,&damage,rolagem,sbox,selecao,roll_bar,fundo_carta,fundo_menu,prompt,deck_meio,deck_cheio,bmp,jogador,adversario,display,fundo,font,font2,color,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);

    //printf("Parte 3\n");
    if(origem_ataque == 1) {
        if(jogador->var_tactic->rauru_cont > 0) {
            debug = damage;
            if(jogador->mesa->monstro1 != NULL && jogador->mesa->monstro1->origem->colecao == RAURU && jogador->mesa->monstro1->turn_silenced == 0) damage += (20 * jogador->var_tactic->rauru_cont);
            if(jogador->mesa->monstro2 != NULL && jogador->mesa->monstro2->origem->colecao == RAURU && jogador->mesa->monstro2->turn_silenced == 0) damage += (20 * jogador->var_tactic->rauru_cont);
            if(jogador->mesa->monstro3 != NULL && jogador->mesa->monstro3->origem->colecao == RAURU && jogador->mesa->monstro3->turn_silenced == 0) damage += (20 * jogador->var_tactic->rauru_cont);
            if(jogador->mesa->monstro4 != NULL && jogador->mesa->monstro4->origem->colecao == RAURU && jogador->mesa->monstro4->turn_silenced == 0) damage += (20 * jogador->var_tactic->rauru_cont);
            if(jogador->mesa->monstro5 != NULL && jogador->mesa->monstro5->origem->colecao == RAURU && jogador->mesa->monstro5->turn_silenced == 0) damage += (20 * jogador->var_tactic->rauru_cont);
            if(jogador->mesa->monstro6 != NULL && jogador->mesa->monstro6->origem->colecao == RAURU && jogador->mesa->monstro6->turn_silenced == 0) damage += (20 * jogador->var_tactic->rauru_cont);
            if(jogador->mesa->monstro7 != NULL && jogador->mesa->monstro7->origem->colecao == RAURU && jogador->mesa->monstro7->turn_silenced == 0) damage += (20 * jogador->var_tactic->rauru_cont);

            if(damage - debug > 0) printf("BUFF: Rauru x %d\n",(damage - debug) / 20);
        }

        damage += (10 * jogador->var_tactic->bless_of_triforce_cont);
        if(jogador->var_tactic->bless_of_triforce_cont > 0) printf("BUFF: jogador BLESS_OF_TRIFORCE x %d\n",jogador->var_tactic->bless_of_triforce_cont);
        damage += (10 * adversario->var_tactic->bless_of_triforce_cont);
        if(adversario->var_tactic->bless_of_triforce_cont > 0) printf("BUFF: adversario BLESS_OF_TRIFORCE x %d\n",adversario->var_tactic->bless_of_triforce_cont);
    }

    if(origem_ataque == 0 && atacante != NULL) {
        damage = RetornaAproximado((atacante->var_monster->damage_multiplier*damage) / 100);

        if(atacante->var_monster->skull_kid_bool == true) {
            damage = 2*damage;
            printf("BUFF: skull kid DOUBLE DAMAGE!\n");
        }
    }
    printf("\t\tBALANCEAMENTO ATAQUE: %d -> %d\n",dano_inicial,damage);

    //Ao final desta funcao, deve-se definir a quantidade alterada de ataque, de forma que o usuário fique ciente do dano a se aplicar.
    return(damage);
}

void EquipBlock(struct CARD *card,int origem_ataque,int *defesa) {
    if(card != NULL) {
        if(card->origem->colecao == GORON_TUNIC && (origem_ataque == 0 || origem_ataque == 1)) {
            *defesa += 10;
            printf("BLOCK: GORON TUNIC\n");
        }
        else if(card->origem->colecao == HYLIAN_SHIELD && origem_ataque == 0) {
            printf("BLOCK: HYLIAN SHIELD\n");
            *defesa += 20;
        }
        else if(card->origem->colecao == SILVER_GAUNTLETS && origem_ataque == 0) {
            printf("BLOCK: SILVER GAUNTLETS\n");
            *defesa += 10;
        }
        else if(card->origem->colecao == GOLDEN_GAUNTLETS && (origem_ataque == 0 || origem_ataque == 1)) {
            printf("BLOCK: GOLDEN GAUNTLETS\n");
            *defesa += 10;
        }
        else if(card->origem->colecao == KOKIRI_TUNIC && origem_ataque == 0) {
            *defesa += 10;
            printf("BLOCK: KOKIRI TUNIC\n");
        }
    }
}

int BalanceamentoDefesa(bool aplicavel,bool hitChar,struct CARD *alvo,int origem_ataque,struct Player *jogador,struct Player *adversario) {
    int defesa = 0,val = 10,debug;

    debug = defesa;
    EfetuaBuff_def(alvo,&defesa);
    if(defesa - debug > 0) printf("BUFFS DEF ativos (%d)\n",defesa - debug);

    if(hitChar == true) {
        if(adversario->field_cont > 0) {  //Block somente para o field tipo 1.
            if(adversario->mesa->field != NULL) {
                if((adversario->mesa->field->origem->colecao == DESERT_COLOSSUS && !strcmp(adversario->mesa->character->origem->elemento,"Wind")) || (adversario->mesa->field->origem->colecao == HYRULE_CASTLE && !strcmp(adversario->mesa->character->origem->elemento,"Light")) || (adversario->mesa->field->origem->colecao == KAKARIKO_GRAVEYARD && !strcmp(adversario->mesa->character->origem->elemento,"Dark")) || (adversario->mesa->field->origem->colecao == FIRE_TEMPLE && !strcmp(adversario->mesa->character->origem->elemento,"Fire"))) {
                    VerificaDungeonMap(&val,adversario,jogador);
                    printf("BLOCK: FIELD (%d)\n",val);
                    defesa += val;

                    if(aplicavel) adversario->field_cont--;
                }
            }
            else if(jogador->mesa->field != NULL) { //Se o joador possui campo e o adv nao, entao adv pode se beneficiar do campo do jogador atual!
                if((jogador->mesa->field->origem->colecao == DESERT_COLOSSUS && !strcmp(adversario->mesa->character->origem->elemento,"Wind")) || (jogador->mesa->field->origem->colecao == HYRULE_CASTLE && !strcmp(adversario->mesa->character->origem->elemento,"Light")) || (jogador->mesa->field->origem->colecao == KAKARIKO_GRAVEYARD && !strcmp(adversario->mesa->character->origem->elemento,"Dark")) || (jogador->mesa->field->origem->colecao == FIRE_TEMPLE && !strcmp(adversario->mesa->character->origem->elemento,"Fire"))) {
                    VerificaDungeonMap(&val,adversario,jogador);
                    printf("BLOCK: FIELD (%d)\n",val);
                    defesa += val;

                    if(aplicavel) adversario->field_cont--;
                }
            }

            //............................
        }

        debug = defesa;
        if(adversario->mesa->monstro1 != NULL) defesa += 10;
        if(adversario->mesa->monstro2 != NULL) defesa += 10;
        if(adversario->mesa->monstro3 != NULL) defesa += 10;
        if(adversario->mesa->monstro4 != NULL) defesa += 10;
        if(adversario->mesa->monstro5 != NULL) defesa += 10;
        if(adversario->mesa->monstro6 != NULL) defesa += 10;
        if(adversario->mesa->monstro7 != NULL) defesa += 10;
        if(defesa - debug > 0) printf("BLOCK: MOBS (%d)\n",defesa - debug);

        EquipBlock(adversario->mesa->equip1,origem_ataque,&defesa);
        EquipBlock(adversario->mesa->equip2,origem_ataque,&defesa);
        EquipBlock(adversario->mesa->equip3,origem_ataque,&defesa);
        EquipBlock(adversario->mesa->equip4,origem_ataque,&defesa);
        EquipBlock(adversario->mesa->equip5,origem_ataque,&defesa);
        EquipBlock(adversario->mesa->equip6,origem_ataque,&defesa);
        EquipBlock(adversario->mesa->equip7,origem_ataque,&defesa);

        defesa += (20 * adversario->var_tactic->bless_of_triforce_cont);
        if(adversario->var_tactic->bless_of_triforce_cont > 0) printf("BLOCK: BLESS_OF_TRIFORCE x %d\n",adversario->var_tactic->bless_of_triforce_cont);
        defesa += (20 * jogador->var_tactic->bless_of_triforce_cont);
        if(jogador->var_tactic->bless_of_triforce_cont > 0) printf("BLOCK: BLESS_OF_TRIFORCE x %d\n",jogador->var_tactic->bless_of_triforce_cont);
    }

    else if(alvo != NULL) {
        if(alvo->origem->colecao == STALFOS && origem_ataque == 0 && alvo->turn_silenced == 0) {
            defesa += 20;
            printf("MOB BLOCK: ANCIENT SHIELD (20)\n");
        }

    }

    if(adversario->var_tactic->underground_shelter_cont > 0) {
        defesa += (20*adversario->var_tactic->underground_shelter_cont);
        printf("BLOCK: UNDERGROUND SHELTER x %d\n",adversario->var_tactic->underground_shelter_cont);
    }

    printf("\t\tBALANCEAMENTO DEFESA: %d\n",defesa);
    return(defesa);
}

bool MonstroAlvejado(struct Coordenadas *aux,int slot_fixo) {
    switch(slot_fixo) {
        case 0:
            if(aux->x == 685 && aux->y == 110) return(true);
            break;

        case 1:
            if(aux->x == 300 && aux->y == 190) return(true);
            break;

        case 2:
            if(aux->x == 355 && aux->y == 190) return(true);
            break;

        case 3:
            if(aux->x == 410 && aux->y == 190) return(true);
            break;

        case 4:
            if(aux->x == 465 && aux->y == 190) return(true);
            break;

        case 5:
            if(aux->x == 520 && aux->y == 190) return(true);
            break;

        case 6:
            if(aux->x == 575 && aux->y == 190) return(true);
            break;

        case 7:
            if(aux->x == 630 && aux->y == 190) return(true);
            break;
    }

    return(false);
}

void IncluiDOT(struct CARD *alvo, struct CARD *source, int dot, short turns) {
    struct DotInstance *aux;

    aux = alvo->dot_list;
    while(aux->prox != NULL) {
        if(source == aux->source) {
            aux->dot = dot;             //talvez eu use para o dano diminuir com tempo?
            aux->turns_left = turns;

            break;
        }
        aux = aux->prox;
    }
    if(aux->prox == NULL) {
        aux->source = source;
        aux->dot = dot;
        aux->turns_left = turns;

        aux->prox = (struct DotInstance *)malloc(sizeof(struct DotInstance));
        aux->prox->prox = NULL;
    }
}

void IncluiBuff(struct CARD *alvo, struct CARD *source, int atk, int hp, int def, short turns) {
    struct BuffInstance *aux;

    printf("Incluindo buff (%d,%d,%d) em '%s'\n",atk,hp,def,alvo->origem->nome);

    aux = alvo->buff_list;
    while(aux->prox != NULL) {
        if(source == aux->source) {
            aux->hp = hp;
            aux->atk = atk;
            aux->def = def;
            aux->turns_left = turns;

            break;
        }
        aux = aux->prox;
    }
    if(aux->prox == NULL) {
        aux->source = source;
        aux->hp = hp;
        aux->atk = atk;
        aux->def = def;
        aux->turns_left = turns;

        aux->prox = (struct BuffInstance *)malloc(sizeof(struct BuffInstance));
        aux->prox->prox = NULL;
    }
}

void EsvaziaBuffs(struct CARD *card) {
    struct BuffInstance *aux = card->buff_list,*aux2;
    while(aux->prox != NULL) {
        aux2 = aux;
        free(aux2);
        aux = aux->prox;
    }

    card->buff_list = aux;
}

bool Attack(int id_acao,bool prevent,bool counter,struct Card **buffer,bool *fim_de_jogo,int *rolagem,bool *ko,int restricoes,int origem_ataque,int monstro_fixo,struct StatusBox_bitmaps *sbox,struct Player *jogador,struct Player *adversario,struct CARD *atacante,int dano_inicial,ALLEGRO_DISPLAY *display,ALLEGRO_BITMAP *prompt,ALLEGRO_BITMAP *selecao,ALLEGRO_BITMAP *roll_bar,ALLEGRO_BITMAP *fundo_carta,ALLEGRO_BITMAP *fundo_menu,ALLEGRO_BITMAP *deck_meio,ALLEGRO_BITMAP *deck_cheio,ALLEGRO_BITMAP *fundo,ALLEGRO_FONT *font,ALLEGRO_FONT *font2,ALLEGRO_COLOR color,ALLEGRO_BITMAP *bmp,bool *sair,int *posX,int *posY,int *dltZ,bool *mouse,bool *mouse2,bool *mouse_lado,int *keychar,bool *repete_keychar,ALLEGRO_EVENT_QUEUE *event_queue,ALLEGRO_TIMER *keyb_press_timer,ALLEGRO_TIMER *mouse_press_timer) {  //INCOMPLETAS funcoes interiores
    //BOOL KO tem funcao unica para char. act HURRICANE!
    //ALTERAR CONFERE ATK E DEF!

    /*
    ORIGEM ATAQUE:
        0- Monster
        1- Character Action
        2- Tactic
        3- Equip
        4- N/A (usado por DestroyMonster)

    RESTRICOES:
        0- Sem limites
        1- Nao atinge characters
        2- Nao atinge monstros
        3- Atinge SLOT FIXO
        4- Damage Over Time (DOT) / Dano Fixo (sem buffs/nerfs)
    */

    bool toggle,usa_weapon = false;
    int final = 0,slot,elemento_ataque,slot_atacante,atkValue,defValue,damage;
    int gridDef[16],gridAtk;
    struct CARD *monstro = NULL;
    struct Deck *aux;
    struct Coordenadas *lista,*aux2,*aux3;

    *ko = false;

    if(origem_ataque == 1 && jogador->turn_away > 0) return(true);

    if(restricoes != 4) {
        if(strcmp(atacante->origem->elemento,"Earth") == 0) elemento_ataque = 0;
        else if(strcmp(atacante->origem->elemento,"Wind") == 0) elemento_ataque = 1;
        else if(strcmp(atacante->origem->elemento,"Fire") == 0) elemento_ataque = 2;
        else if(strcmp(atacante->origem->elemento,"Water") == 0) elemento_ataque = 3;
        else if(strcmp(atacante->origem->elemento,"Light") == 0) elemento_ataque = 4;
        else elemento_ataque = 5;

        for(slot = 0;slot < 16;slot++)
            gridDef[slot] = 0;

        printf("\n---------------------------------------\nATACANTE %s (atk: %d)\n",atacante->origem->nome,dano_inicial);
        if(atacante->turn_cooldown > 0) {
            printf("ATACANTE com STUN! Sem ataque nem efeitos disponiveis!\n");
            return(false);
        }

        lista = (struct Coordenadas *)malloc(sizeof(struct Coordenadas));
        lista->prox = NULL;

        AtualizaMesa(false,"Set the target...",id_acao,0,0,buffer,fim_de_jogo,sbox,prompt,selecao,roll_bar,fundo_carta,fundo_menu,deck_meio,deck_cheio,fundo,bmp,jogador,adversario,display,font,font2,color,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer,rolagem,lista,elemento_ataque,origem_ataque,restricoes,-1,NULL,atacante);
        if(lista->prox == NULL) {
            printf("ERRO: Lista vazia!\n");
            free(lista);
            return(true);
        }

        if(restricoes != 3) {
            //funcao que confere ataque e defesas pra cada configuracao disponivel de ataque! -------------------------------------------------
            //Mas ainda fica faltando casos onde um card não pode ser atingido, ou efeito de um card especifico, que só pode ser determinado no momento do ataque.
            //Balanceamento precisa testar tais ocasioes, e enviar resultados para ATUALIZAMESA!
            gridAtk = BalanceamentoAtaque(&usa_weapon,id_acao,false,buffer,fim_de_jogo,rolagem,origem_ataque,jogador,adversario,atacante,dano_inicial,display,sbox,selecao,roll_bar,fundo_carta,fundo_menu,deck_meio,deck_cheio,fundo,prompt,font,font2,color,bmp,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);
            gridDef[0] = BalanceamentoDefesa(false,true,adversario->mesa->character,origem_ataque,jogador,adversario);
            gridDef[1] = BalanceamentoDefesa(false,false,adversario->mesa->monstro1,origem_ataque,jogador,adversario);
            gridDef[2] = BalanceamentoDefesa(false,false,adversario->mesa->monstro2,origem_ataque,jogador,adversario);
            gridDef[3] = BalanceamentoDefesa(false,false,adversario->mesa->monstro3,origem_ataque,jogador,adversario);
            gridDef[4] = BalanceamentoDefesa(false,false,adversario->mesa->monstro4,origem_ataque,jogador,adversario);
            gridDef[5] = BalanceamentoDefesa(false,false,adversario->mesa->monstro5,origem_ataque,jogador,adversario);
            gridDef[6] = BalanceamentoDefesa(false,false,adversario->mesa->monstro6,origem_ataque,jogador,adversario);
            gridDef[7] = BalanceamentoDefesa(false,false,adversario->mesa->monstro7,origem_ataque,jogador,adversario);

            /* gridDef[8] = BalanceamentoDefesa(false,true,adversario,jogador);   //grid 8~15: simplesmente um chute!
            gridDef[9] = BalanceamentoDefesa(false,false,adversario,jogador);
            gridDef[10] = BalanceamentoDefesa(false,false,adversario,jogador);
            gridDef[11] = BalanceamentoDefesa(false,false,adversario,jogador);
            gridDef[12] = BalanceamentoDefesa(false,false,adversario,jogador);
            gridDef[13] = BalanceamentoDefesa(false,false,adversario,jogador);
            gridDef[14] = BalanceamentoDefesa(false,false,adversario,jogador);
            gridDef[15] = BalanceamentoDefesa(false,false,adversario,jogador);
            */

            //--------------------------------------------------------------------------------

            while(1) {
                AtualizaMesa(true,"Set the target...",id_acao,0,0,buffer,fim_de_jogo,sbox,prompt,selecao,roll_bar,fundo_carta,fundo_menu,deck_meio,deck_cheio,fundo,bmp,jogador,adversario,display,font,font2,color,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer,rolagem,lista,elemento_ataque,origem_ataque,restricoes,gridAtk,gridDef,atacante);

                if(*fim_de_jogo == true) return(true);

                if(*mouse == true) {
                    aux2 = lista;
                    toggle = false;

                    while(aux2->prox != NULL) {
                        if(*posX >= aux2->x && *posX < aux2->x + 50 && *posY >= aux2->y && *posY < aux2->y + 75) {
                            toggle = true;
                            break;
                        }
                        aux2 = aux2->prox;
                    }

                    if(toggle == true) break;
                }
                else if(*mouse2 == true) {
                    printf("Executa limpeza: ataque negado.\n");
                    aux2 = lista;
                    while(aux2->prox != NULL) {
                        aux3 = aux2;
                        aux2 = aux2->prox;
                        free(aux3);
                    }
                    free(aux2);

                    return(false);
                }
            }
        }
        else {
            aux2 = lista;
            while(aux2->prox != NULL) {
                if(MonstroAlvejado(aux2,monstro_fixo)) break;
                aux2 = aux2->prox;
            }
            if(aux2->prox == NULL) {
                free(lista);
                return(true);
            }

            printf("RESTRICOES #3: Atingindo slot FIXO %d\n",monstro_fixo);
        }

        aux2 = lista;
            while(aux2->prox != NULL) {
                aux3 = aux2;
                aux2 = aux2->prox;
                free(aux3);
            }
        free(aux2);

        printf("ATAQUE ");

        toggle = false; //toggle: flag -> character eh alvejado
        //monstro é definido pelo card alvejado, sendo char ou monster.
        if(restricoes == 3) {
            printf("restr %d monstr ",monstro_fixo);

            if(monstro_fixo == 1) {
                monstro = adversario->mesa->monstro1;
                slot = 1;
                printf("FOI 1 ");
                if(monstro == NULL) printf("mas monstro eh nulo...\n");
            }
            else if(monstro_fixo == 2) {
                monstro = adversario->mesa->monstro2;
                slot = 2;
                printf("FOI 2 ");
                if(monstro == NULL) printf("mas monstro eh nulo...\n");
            }
            else if(monstro_fixo == 3) {
                monstro = adversario->mesa->monstro3;
                slot = 3;
                printf("FOI 3 ");
                if(monstro == NULL) printf("mas monstro eh nulo...\n");
            }
            else if(monstro_fixo == 4) {
                monstro = adversario->mesa->monstro4;
                slot = 4;
                printf("FOI 4 ");
                if(monstro == NULL) printf("mas monstro eh nulo...\n");
            }
            else if(monstro_fixo == 5) {
                monstro = adversario->mesa->monstro5;
                slot = 5;
                printf("FOI 5 ");
                if(monstro == NULL) printf("mas monstro eh nulo...\n");
            }
            else if(monstro_fixo == 6) {
                monstro = adversario->mesa->monstro6;
                slot = 6;
                printf("FOI 6 ");
                if(monstro == NULL) printf("mas monstro eh nulo...\n");
            }
            else if(monstro_fixo == 7) {
                monstro = adversario->mesa->monstro7;
                slot = 7;
                printf("FOI 7 ");
                if(monstro == NULL) printf("mas monstro eh nulo...\n");
            }
            else if(monstro_fixo == 0) {
                toggle = true;
                monstro = adversario->mesa->character;
                printf("FOI 0 ");
                if(monstro == NULL) printf("mas monstro eh nulo...\n");
            }
            else printf("WTF?\n");
        }

        else {
            if(*posX >= 300 && *posX < 300 + 50 && *posY >= 190 && *posY < 190 + 75) {
                monstro = adversario->mesa->monstro1;
                slot = 1;
            }
            else if(*posX >= 355 && *posX < 355 + 50 && *posY >= 190 && *posY < 190 + 75) {
                monstro = adversario->mesa->monstro2;
                slot = 2;
            }
            else if(*posX >= 410 && *posX < 410 + 50 && *posY >= 190 && *posY < 190 + 75) {
                monstro = adversario->mesa->monstro3;
                slot = 3;
            }
            else if(*posX >= 465 && *posX < 465 + 50 && *posY >= 190 && *posY < 190 + 75) {
                monstro = adversario->mesa->monstro4;
                slot = 4;
            }
            else if(*posX >= 520 && *posX < 520 + 50 && *posY >= 190 && *posY < 190 + 75) {
                monstro = adversario->mesa->monstro5;
                slot = 5;
            }
            else if(*posX >= 575 && *posX < 575 + 50 && *posY >= 190 && *posY < 190 + 75) {
                monstro = adversario->mesa->monstro6;
                slot = 6;
            }
            else if(*posX >= 630 && *posX < 630 + 50 && *posY >= 190 && *posY < 190 + 75) {
                monstro = adversario->mesa->monstro7;
                slot = 7;
            }
            else if(*posX >= 685 && *posX < 685 + 50 && *posY >= 110 && *posY < 110 + 75) {
                toggle = true;
                monstro = adversario->mesa->character;
            }
        }

        printf("2 ");

        //--------------------------------- Efetiva ataque ---------------------------------------
        atkValue = BalanceamentoAtaque(&usa_weapon,id_acao,true,buffer,fim_de_jogo,rolagem,origem_ataque,jogador,adversario,atacante,dano_inicial,display,sbox,selecao,roll_bar,fundo_carta,fundo_menu,deck_meio,deck_cheio,fundo,prompt,font,font2,color,bmp,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);
        //--------------------------------- Efetiva defesa ---------------------------------------
        printf("3 ");
        defValue = BalanceamentoDefesa(true,toggle,monstro,origem_ataque,jogador,adversario);
        //----------------------------------------------------------------------------------------
        damage = atkValue - defValue;

        if(monstro == adversario->mesa->character && damage > 30 && PossuiIronBoots(adversario)) {
            printf("IRON BOOTS BLOCK (%d) -> 30\n",damage);
            damage = 30;
        }

        if(origem_ataque == 0 && atacante->origem->colecao == BIG_DEKU_BABA && atacante->turn_silenced == 0 && ehMonstro(monstro)) {
            monstro->turn_cooldown += 1;
        }
    }

    else {
        toggle = false;
        if(monstro_fixo == 0) {
            monstro = adversario->mesa->character;
            toggle = true;
        }
        else if(monstro_fixo == 1) monstro = adversario->mesa->monstro1;
        else if(monstro_fixo == 2) monstro = adversario->mesa->monstro2;
        else if(monstro_fixo == 3) monstro = adversario->mesa->monstro3;
        else if(monstro_fixo == 4) monstro = adversario->mesa->monstro4;
        else if(monstro_fixo == 5) monstro = adversario->mesa->monstro5;
        else if(monstro_fixo == 6) monstro = adversario->mesa->monstro6;
        else if(monstro_fixo == 7) monstro = adversario->mesa->monstro7;

        damage = dano_inicial;
        slot = monstro_fixo;
        printf("DAMAGE OVER TIME (%d)!\n", damage);
    }

    printf("DANO : %d ",damage);
    if(monstro == NULL) {
        printf(", mas nenhum ALVO encontrado! (%d,%d,%d, counter: %d)\n",restricoes,origem_ataque,monstro_fixo,counter);
        return(false);
    }

    printf("4: ");
    printf("%d ",toggle);

    if(damage < 0) damage = 0;
    else if(toggle == true) {
        if(prevent == true) {
            if(adversario->prevent_damage > 0) {
                if(damage > 0) {
                    printf("Prevent\n");
                    if(PreventDamage(monstro,id_acao,buffer,fim_de_jogo,rolagem,sbox,selecao,roll_bar,fundo_carta,fundo_menu,prompt,deck_meio,deck_cheio,bmp,jogador,adversario,display,fundo,font,font2,color,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer,damage)) {
                        damage = 0;
                        adversario->prevent_damage--;
                    }
                }
            }
            else if(adversario->prevent_any_damage > 0) {
                if(damage > 0) {
                    printf("Prevent ANY\n");
                    if(PreventDamage(monstro,id_acao,buffer,fim_de_jogo,rolagem,sbox,selecao,roll_bar,fundo_carta,fundo_menu,prompt,deck_meio,deck_cheio,bmp,jogador,adversario,display,fundo,font,font2,color,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer,damage)) {
                        damage = 0;
                        adversario->prevent_any_damage--;
                    }
                }
            }
        }
    }
    else if(adversario->prevent_any_damage > 0 && prevent == true) {
        //PREVENT ANY: para ambos character e monster.
        if(damage > 0) {
            printf("Prevent ANY\n");
            if(PreventDamage(monstro,id_acao,buffer,fim_de_jogo,rolagem,sbox,selecao,roll_bar,fundo_carta,fundo_menu,prompt,deck_meio,deck_cheio,bmp,jogador,adversario,display,fundo,font,font2,color,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer,damage)) {
                damage = 0;
                adversario->prevent_any_damage--;
            }
        }
    }

    printf("hmmm... ");
    printf("HP atual: %d\t\tDano total: %d\n",monstro->HP,damage);
    final = monstro->HP - damage;
    if(final > monstro->HP) final = monstro->HP;
    else if(final < 0) final = 0;

    printf("5 ");

    if(final == 0 && !toggle) { //TOGGLE define q o alvo eh character.
        printf("BRANCH TOMADO\n");
        *ko = true;

        if(origem_ataque == 0) atacante->var_monster->white_wolfos_dmg_cont += 10;

        if (monstro->origem->colecao == PHANTOM_GANON && monstro->turn_silenced == 0 && LancaMoeda(id_acao,buffer,fim_de_jogo,rolagem,sbox,selecao,roll_bar,prompt,fundo_carta,fundo_menu,deck_meio,deck_cheio,bmp,jogador,adversario,display,fundo,font,font2,color,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer)) {
            monstro->HP = 40;
        }
        else if(monstro->origem->colecao == SPIKE && monstro->turn_silenced == 0 && monstro->var_monster->spike_bool == true) {
            monstro->HP = 10;
            monstro->var_monster->spike_bool = false;
        }
        else {
            aux = adversario->graveyard->inicio;
            while(aux->prox!=NULL) aux = aux->prox;

            EsvaziaBuffs(monstro);

            printf("6 ");
            if(monstro->var_monster->dead_hand_bool == true) {
                if(jogador->mesa->monstro1 != NULL && jogador->mesa->monstro1->origem->colecao == DEAD_HAND) jogador->mesa->monstro1->var_monster->dead_hand_cont++;
                else if(jogador->mesa->monstro2 != NULL && jogador->mesa->monstro2->origem->colecao == DEAD_HAND) jogador->mesa->monstro2->var_monster->dead_hand_cont++;
                else if(jogador->mesa->monstro3 != NULL && jogador->mesa->monstro3->origem->colecao == DEAD_HAND) jogador->mesa->monstro3->var_monster->dead_hand_cont++;
                else if(jogador->mesa->monstro4 != NULL && jogador->mesa->monstro4->origem->colecao == DEAD_HAND) jogador->mesa->monstro4->var_monster->dead_hand_cont++;
                else if(jogador->mesa->monstro5 != NULL && jogador->mesa->monstro5->origem->colecao == DEAD_HAND) jogador->mesa->monstro5->var_monster->dead_hand_cont++;
                else if(jogador->mesa->monstro6 != NULL && jogador->mesa->monstro6->origem->colecao == DEAD_HAND) jogador->mesa->monstro6->var_monster->dead_hand_cont++;
                else if(jogador->mesa->monstro7 != NULL && jogador->mesa->monstro7->origem->colecao == DEAD_HAND) jogador->mesa->monstro7->var_monster->dead_hand_cont++;
            }
            printf("7 ");
            if(monstro->origem->colecao == DEAD_HAND) {
                if(jogador->mesa->monstro1 != NULL && jogador->mesa->monstro1->var_monster->dead_hand_bool) jogador->mesa->monstro1->var_monster->dead_hand_bool = false;
                if(jogador->mesa->monstro2 != NULL && jogador->mesa->monstro2->var_monster->dead_hand_bool) jogador->mesa->monstro2->var_monster->dead_hand_bool = false;
                if(jogador->mesa->monstro3 != NULL && jogador->mesa->monstro3->var_monster->dead_hand_bool) jogador->mesa->monstro3->var_monster->dead_hand_bool = false;
                if(jogador->mesa->monstro4 != NULL && jogador->mesa->monstro4->var_monster->dead_hand_bool) jogador->mesa->monstro4->var_monster->dead_hand_bool = false;
                if(jogador->mesa->monstro5 != NULL && jogador->mesa->monstro5->var_monster->dead_hand_bool) jogador->mesa->monstro5->var_monster->dead_hand_bool = false;
                if(jogador->mesa->monstro6 != NULL && jogador->mesa->monstro6->var_monster->dead_hand_bool) jogador->mesa->monstro6->var_monster->dead_hand_bool = false;
                if(jogador->mesa->monstro7 != NULL && jogador->mesa->monstro7->var_monster->dead_hand_bool) jogador->mesa->monstro7->var_monster->dead_hand_bool = false;

                if(monstro->turn_silenced == 0) desfaz_dead_hand_effect(adversario);
            }
            else if(monstro->origem->colecao == GIANT_LEEVER) {
                if(monstro->turn_silenced == 0) desfaz_giant_leever_effect(adversario);
            }

            printf("PARTE 1\n");

            printf("8 ");
            if(monstro->turn_silenced == 0) {
                bool ko2 = false;
                if(monstro->origem->colecao == BABY_DODONGO) {
                    if(jogador->mesa->monstro1 != NULL) Attack(-1,true,true,buffer,fim_de_jogo,rolagem,&ko2,3,0,1,sbox,adversario,jogador,monstro,10,display,prompt,selecao,roll_bar,fundo_carta,fundo_menu,deck_meio,deck_cheio,fundo,font,font2,color,bmp,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);
                    if(jogador->mesa->monstro2 != NULL) Attack(-1,true,true,buffer,fim_de_jogo,rolagem,&ko2,3,0,2,sbox,adversario,jogador,monstro,10,display,prompt,selecao,roll_bar,fundo_carta,fundo_menu,deck_meio,deck_cheio,fundo,font,font2,color,bmp,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);
                    if(jogador->mesa->monstro3 != NULL) Attack(-1,true,true,buffer,fim_de_jogo,rolagem,&ko2,3,0,3,sbox,adversario,jogador,monstro,10,display,prompt,selecao,roll_bar,fundo_carta,fundo_menu,deck_meio,deck_cheio,fundo,font,font2,color,bmp,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);
                    if(jogador->mesa->monstro4 != NULL) Attack(-1,true,true,buffer,fim_de_jogo,rolagem,&ko2,3,0,4,sbox,adversario,jogador,monstro,10,display,prompt,selecao,roll_bar,fundo_carta,fundo_menu,deck_meio,deck_cheio,fundo,font,font2,color,bmp,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);
                    if(jogador->mesa->monstro5 != NULL) Attack(-1,true,true,buffer,fim_de_jogo,rolagem,&ko2,3,0,5,sbox,adversario,jogador,monstro,10,display,prompt,selecao,roll_bar,fundo_carta,fundo_menu,deck_meio,deck_cheio,fundo,font,font2,color,bmp,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);
                    if(jogador->mesa->monstro6 != NULL) Attack(-1,true,true,buffer,fim_de_jogo,rolagem,&ko2,3,0,6,sbox,adversario,jogador,monstro,10,display,prompt,selecao,roll_bar,fundo_carta,fundo_menu,deck_meio,deck_cheio,fundo,font,font2,color,bmp,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);
                    if(jogador->mesa->monstro7 != NULL) Attack(-1,true,true,buffer,fim_de_jogo,rolagem,&ko2,3,0,7,sbox,adversario,jogador,monstro,10,display,prompt,selecao,roll_bar,fundo_carta,fundo_menu,deck_meio,deck_cheio,fundo,font,font2,color,bmp,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);
                    Attack(-1,true,true,buffer,fim_de_jogo,rolagem,&ko2,3,0,0,sbox,adversario,jogador,monstro,20,display,prompt,selecao,roll_bar,fundo_carta,fundo_menu,deck_meio,deck_cheio,fundo,font,font2,color,bmp,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);
                }
                else if(monstro->origem->colecao == SHABOM) Attack(-1,true,true,buffer,fim_de_jogo,rolagem,&ko2,0,0,0,sbox,adversario,jogador,monstro,20,display,prompt,selecao,roll_bar,fundo_carta,fundo_menu,deck_meio,deck_cheio,fundo,font,font2,color,bmp,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);
                else if(monstro->origem->colecao == BUSINESS_SCRUB) business_scrub_acao(id_acao,buffer,fim_de_jogo,rolagem,sbox,adversario,jogador,display,prompt,selecao,roll_bar,bmp,fundo_carta,fundo_menu,deck_meio,deck_cheio,fundo,font,font2,color,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);
            }

            aux = (struct Deck *)malloc(sizeof(struct Deck));
            aux->card = monstro;
            DestroyCard(aux,adversario,jogador);

            printf("9 ");
            switch (slot) {
                case 1:
                    adversario->mesa->monstro1 = NULL;
                    break;
                case 2:
                    adversario->mesa->monstro2 = NULL;
                    break;
                case 3:
                    adversario->mesa->monstro3 = NULL;
                    break;
                case 4:
                    adversario->mesa->monstro4 = NULL;
                    break;
                case 5:
                    adversario->mesa->monstro5 = NULL;
                    break;
                case 6:
                    adversario->mesa->monstro6 = NULL;
                    break;
                case 7:
                    adversario->mesa->monstro7 = NULL;
                    break;
            }

            printf("10 ");
            adversario->var_tactic->rauru_cont++;   //conta qte de monstros destruidos no turno.

            if(aux->card->origem->colecao == LEEVER && aux->card->turn_silenced == 0) adversario->var_tactic->giant_leever_call_bool = true;
            else if(monstro->origem->colecao == BIG_DEKU_BABA && aux->card->turn_silenced == 0) big_deku_baba_acao(buffer,fim_de_jogo,rolagem,sbox,prompt,selecao,roll_bar,fundo_carta,fundo_menu,deck_meio,deck_cheio,bmp,adversario,jogador,display,fundo,font,font2,color,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);

            if(atacante != NULL && atacante->origem->colecao == BEAMOS && atacante->turn_silenced == 0) DrawCard(id_acao,buffer,fim_de_jogo,rolagem,sbox,prompt,selecao,roll_bar,fundo_carta,fundo_menu,deck_meio,deck_cheio,bmp,jogador,adversario,display,fundo,font,font2,color,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);
        }

        bigger_bomb_bag_acao(usa_weapon,id_acao,buffer,fim_de_jogo,rolagem,sbox,prompt,selecao,roll_bar,fundo_carta,fundo_menu,deck_meio,deck_cheio,bmp,jogador,adversario,display,fundo,font,font2,color,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);
        kokiri_tunic_acao(origem_ataque,id_acao,buffer,fim_de_jogo,rolagem,sbox,prompt,selecao,roll_bar,fundo_carta,fundo_menu,deck_meio,deck_cheio,bmp,jogador,adversario,display,fundo,font,font2,color,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);

        RecuperaZeroHP(fim_de_jogo,jogador);
        RecuperaZeroHP(fim_de_jogo,adversario);
    }
    else {
        monstro->HP = final;
        printf("%s -> HP: %d\n",monstro->origem->nome,monstro->HP);
        *ko = false;

        printf("-> 11 ");
        if(counter == false && restricoes != 4) {
            //COUNTER-ATTACKs: ocorrem somente se o ataque original ja nao for counter.

            if(monstro->origem->colecao == BIGOCTO && monstro->turn_silenced == 0 && damage > 0) Attack(-1,true,true,buffer,fim_de_jogo,rolagem,ko,0,0,0,sbox,adversario,jogador,monstro,20,display,prompt,selecao,roll_bar,fundo_carta,fundo_menu,deck_meio,deck_cheio,fundo,font,font2,color,bmp,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);
            else if(monstro->origem->colecao == TAILPASARAN && origem_ataque == 0 && monstro->turn_silenced == 0) {
                slot_atacante = BuscaAtacante(jogador,atacante);
                Attack(-1,true,true,buffer,fim_de_jogo,rolagem,ko,3,0,slot_atacante,sbox,adversario,jogador,monstro,20,display,prompt,selecao,roll_bar,fundo_carta,fundo_menu,deck_meio,deck_cheio,fundo,font,font2,color,bmp,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);
            }
            else if(monstro->origem->colecao == POE_SISTERS && monstro->HP <= 20 && monstro->turn_silenced == 0) {
                slot_atacante = BuscaAtacante(jogador,atacante);
                printf("Detectou slot %d\n",slot_atacante);
                Attack(-1,true,true,buffer,fim_de_jogo,rolagem,ko,3,0,slot_atacante,sbox,adversario,jogador,monstro,30,display,prompt,selecao,roll_bar,fundo_carta,fundo_menu,deck_meio,deck_cheio,fundo,font,font2,color,bmp,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);
            }
        }

        printf("12 ");

        //---- MONSTER REACTORS (ocorre ao tomar dano)----
        MonsterReactor(monstro,buffer,fim_de_jogo,rolagem,jogador,adversario,display,selecao,roll_bar,fundo_carta,deck_meio,deck_cheio,fundo,font,color,bmp);
        //-------------------------

        //---- EQUIPMT REACTORS (ocorre ao tomar dano)----
        EquipReactor(true,toggle,damage,jogador->mesa->equip1,id_acao,buffer,fim_de_jogo,rolagem,sbox,prompt,selecao,roll_bar,fundo_carta,fundo_menu,deck_meio,deck_cheio,bmp,jogador,adversario,display,fundo,font,font2,color,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);
        EquipReactor(true,toggle,damage,jogador->mesa->equip2,id_acao,buffer,fim_de_jogo,rolagem,sbox,prompt,selecao,roll_bar,fundo_carta,fundo_menu,deck_meio,deck_cheio,bmp,jogador,adversario,display,fundo,font,font2,color,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);
        EquipReactor(true,toggle,damage,jogador->mesa->equip3,id_acao,buffer,fim_de_jogo,rolagem,sbox,prompt,selecao,roll_bar,fundo_carta,fundo_menu,deck_meio,deck_cheio,bmp,jogador,adversario,display,fundo,font,font2,color,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);
        EquipReactor(true,toggle,damage,jogador->mesa->equip4,id_acao,buffer,fim_de_jogo,rolagem,sbox,prompt,selecao,roll_bar,fundo_carta,fundo_menu,deck_meio,deck_cheio,bmp,jogador,adversario,display,fundo,font,font2,color,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);
        EquipReactor(true,toggle,damage,jogador->mesa->equip5,id_acao,buffer,fim_de_jogo,rolagem,sbox,prompt,selecao,roll_bar,fundo_carta,fundo_menu,deck_meio,deck_cheio,bmp,jogador,adversario,display,fundo,font,font2,color,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);
        EquipReactor(true,toggle,damage,jogador->mesa->equip6,id_acao,buffer,fim_de_jogo,rolagem,sbox,prompt,selecao,roll_bar,fundo_carta,fundo_menu,deck_meio,deck_cheio,bmp,jogador,adversario,display,fundo,font,font2,color,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);
        EquipReactor(true,toggle,damage,jogador->mesa->equip7,id_acao,buffer,fim_de_jogo,rolagem,sbox,prompt,selecao,roll_bar,fundo_carta,fundo_menu,deck_meio,deck_cheio,bmp,jogador,adversario,display,fundo,font,font2,color,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);

        EquipReactor(false,toggle,damage,adversario->mesa->equip1,id_acao,buffer,fim_de_jogo,rolagem,sbox,prompt,selecao,roll_bar,fundo_carta,fundo_menu,deck_meio,deck_cheio,bmp,adversario,jogador,display,fundo,font,font2,color,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);
        EquipReactor(false,toggle,damage,adversario->mesa->equip2,id_acao,buffer,fim_de_jogo,rolagem,sbox,prompt,selecao,roll_bar,fundo_carta,fundo_menu,deck_meio,deck_cheio,bmp,adversario,jogador,display,fundo,font,font2,color,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);
        EquipReactor(false,toggle,damage,adversario->mesa->equip3,id_acao,buffer,fim_de_jogo,rolagem,sbox,prompt,selecao,roll_bar,fundo_carta,fundo_menu,deck_meio,deck_cheio,bmp,adversario,jogador,display,fundo,font,font2,color,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);
        EquipReactor(false,toggle,damage,adversario->mesa->equip4,id_acao,buffer,fim_de_jogo,rolagem,sbox,prompt,selecao,roll_bar,fundo_carta,fundo_menu,deck_meio,deck_cheio,bmp,adversario,jogador,display,fundo,font,font2,color,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);
        EquipReactor(false,toggle,damage,adversario->mesa->equip5,id_acao,buffer,fim_de_jogo,rolagem,sbox,prompt,selecao,roll_bar,fundo_carta,fundo_menu,deck_meio,deck_cheio,bmp,adversario,jogador,display,fundo,font,font2,color,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);
        EquipReactor(false,toggle,damage,adversario->mesa->equip6,id_acao,buffer,fim_de_jogo,rolagem,sbox,prompt,selecao,roll_bar,fundo_carta,fundo_menu,deck_meio,deck_cheio,bmp,adversario,jogador,display,fundo,font,font2,color,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);
        EquipReactor(false,toggle,damage,adversario->mesa->equip7,id_acao,buffer,fim_de_jogo,rolagem,sbox,prompt,selecao,roll_bar,fundo_carta,fundo_menu,deck_meio,deck_cheio,bmp,adversario,jogador,display,fundo,font,font2,color,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);

        //-------------------------
    }

    printf("13 ");
    if(atacante != NULL) {
        if(atacante->origem->colecao == SPIKE && atacante->turn_silenced == 0) IncluiDOT(monstro,atacante,10,3);
        else if(toggle == true && atacante->origem->colecao == LIKELIKE && damage > 0 && atacante->turn_silenced == 0) {
            printf("Destroy equip...\n");
            DestroyEquipment(id_acao,fim_de_jogo,buffer,rolagem,sbox,jogador,adversario,display,prompt,selecao,roll_bar,fundo_carta,fundo_menu,deck_meio,deck_cheio,fundo,font,font2,color,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer,bmp);
        }

        if(monstro->origem->colecao == GOLD_SKULLTULA && monstro->turn_silenced == 0 && (origem_ataque == 0 || origem_ataque == 1)) {
            IncluiDOT(atacante,monstro,30,2);
            if(ehMonstro(atacante)) atacante->turn_cooldown += 1;
        }
    }

    printf("OK\n");
    AtualizaMesa(true,NULL,id_acao,-1,0,buffer,fim_de_jogo,sbox,prompt,selecao,roll_bar,fundo_carta,fundo_menu,deck_meio,deck_cheio,fundo,bmp,jogador,adversario,display,font,font2,color,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer,rolagem,NULL,-1,-1,0,-1,NULL,NULL);
    return(true);
}

void DestroyMonster(int id_acao,struct Card **buffer,int *rolagem,struct StatusBox_bitmaps *sbox,ALLEGRO_BITMAP *selecao,ALLEGRO_BITMAP *roll_bar,ALLEGRO_BITMAP *prompt,bool *fim_de_jogo,ALLEGRO_BITMAP *fundo_carta,ALLEGRO_BITMAP *fundo_menu,ALLEGRO_BITMAP *deck_meio,ALLEGRO_BITMAP *deck_cheio,struct Player *jogador,struct Player *adversario,ALLEGRO_DISPLAY *display,ALLEGRO_BITMAP *fundo,ALLEGRO_FONT *font,ALLEGRO_FONT *font2,ALLEGRO_COLOR color,ALLEGRO_BITMAP *apontador,bool *sair,int *posX,int *posY,int *dltZ,bool *mouse,bool *mouse2,bool *mouse_lado,int *keychar,bool *repete_keychar,ALLEGRO_EVENT_QUEUE *event_queue,ALLEGRO_TIMER *keyb_press_timer,ALLEGRO_TIMER *mouse_press_timer) {
    struct Deck *menu,*aux,*escolhido;
    bool ko;

    Menu_Cria(&menu,&aux);
    if(adversario->mesa->monstro1 != NULL && !EhBoss(adversario->mesa->monstro1)) Menu_CopiaDado(&aux,adversario->mesa->monstro1);
    if(adversario->mesa->monstro2 != NULL && !EhBoss(adversario->mesa->monstro2)) Menu_CopiaDado(&aux,adversario->mesa->monstro2);
    if(adversario->mesa->monstro3 != NULL && !EhBoss(adversario->mesa->monstro3)) Menu_CopiaDado(&aux,adversario->mesa->monstro3);
    if(adversario->mesa->monstro4 != NULL && !EhBoss(adversario->mesa->monstro4)) Menu_CopiaDado(&aux,adversario->mesa->monstro4);
    if(adversario->mesa->monstro5 != NULL && !EhBoss(adversario->mesa->monstro5)) Menu_CopiaDado(&aux,adversario->mesa->monstro5);
    if(adversario->mesa->monstro6 != NULL && !EhBoss(adversario->mesa->monstro6)) Menu_CopiaDado(&aux,adversario->mesa->monstro6);
    if(adversario->mesa->monstro7 != NULL && !EhBoss(adversario->mesa->monstro7)) Menu_CopiaDado(&aux,adversario->mesa->monstro7);
    Menu_CelulaFinal(&aux);

    escolhido = MenuCards("DESTROY a monster...",true,menu,fim_de_jogo,jogador,display,prompt,selecao,roll_bar,fundo_carta,fundo_menu,fundo,font2,font,color,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);
    if(escolhido != NULL) {
        if(escolhido->card == adversario->mesa->monstro1) Attack(id_acao,false,false,buffer,fim_de_jogo,rolagem,&ko,4,4,1,sbox,jogador,adversario,NULL,999,display,prompt,selecao,roll_bar,fundo_carta,fundo_menu,deck_meio,deck_cheio,fundo,font,font2,color,apontador,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);
        else if(escolhido->card == adversario->mesa->monstro2) Attack(id_acao,false,false,buffer,fim_de_jogo,rolagem,&ko,4,4,2,sbox,jogador,adversario,NULL,999,display,prompt,selecao,roll_bar,fundo_carta,fundo_menu,deck_meio,deck_cheio,fundo,font,font2,color,apontador,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);
        else if(escolhido->card == adversario->mesa->monstro3) Attack(id_acao,false,false,buffer,fim_de_jogo,rolagem,&ko,4,4,3,sbox,jogador,adversario,NULL,999,display,prompt,selecao,roll_bar,fundo_carta,fundo_menu,deck_meio,deck_cheio,fundo,font,font2,color,apontador,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);
        else if(escolhido->card == adversario->mesa->monstro4) Attack(id_acao,false,false,buffer,fim_de_jogo,rolagem,&ko,4,4,4,sbox,jogador,adversario,NULL,999,display,prompt,selecao,roll_bar,fundo_carta,fundo_menu,deck_meio,deck_cheio,fundo,font,font2,color,apontador,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);
        else if(escolhido->card == adversario->mesa->monstro5) Attack(id_acao,false,false,buffer,fim_de_jogo,rolagem,&ko,4,4,5,sbox,jogador,adversario,NULL,999,display,prompt,selecao,roll_bar,fundo_carta,fundo_menu,deck_meio,deck_cheio,fundo,font,font2,color,apontador,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);
        else if(escolhido->card == adversario->mesa->monstro6) Attack(id_acao,false,false,buffer,fim_de_jogo,rolagem,&ko,4,4,6,sbox,jogador,adversario,NULL,999,display,prompt,selecao,roll_bar,fundo_carta,fundo_menu,deck_meio,deck_cheio,fundo,font,font2,color,apontador,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);
        else Attack(id_acao,false,false,buffer,fim_de_jogo,rolagem,&ko,4,4,7,sbox,jogador,adversario,NULL,999,display,prompt,selecao,roll_bar,fundo_carta,fundo_menu,deck_meio,deck_cheio,fundo,font,font2,color,apontador,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);
    }

    Menu_Finaliza(menu);
}

bool MonstroEmSlot(struct Player *jogador, int slot) {
    if(slot == 0) return(true);
    if(slot == 1 && jogador->mesa->monstro1 != NULL) return(true);
    if(slot == 2 && jogador->mesa->monstro2 != NULL) return(true);
    if(slot == 3 && jogador->mesa->monstro3 != NULL) return(true);
    if(slot == 4 && jogador->mesa->monstro4 != NULL) return(true);
    if(slot == 5 && jogador->mesa->monstro5 != NULL) return(true);
    if(slot == 6 && jogador->mesa->monstro6 != NULL) return(true);
    if(slot == 7 && jogador->mesa->monstro7 != NULL) return(true);

    return(false);
}

void EfetuaDOT_slot(struct CARD *card,int slot,struct Card **buffer,bool *fim_de_jogo,int *rolagem,struct StatusBox_bitmaps *sbox,struct Player *jogador,struct Player *adversario,ALLEGRO_DISPLAY *display,ALLEGRO_BITMAP *prompt,ALLEGRO_BITMAP *selecao,ALLEGRO_BITMAP *roll_bar,ALLEGRO_BITMAP *fundo_carta,ALLEGRO_BITMAP *fundo_menu,ALLEGRO_BITMAP *deck_meio,ALLEGRO_BITMAP *deck_cheio,ALLEGRO_BITMAP *fundo,ALLEGRO_FONT *font,ALLEGRO_FONT *font2,ALLEGRO_COLOR color,ALLEGRO_BITMAP *bmp,bool *sair,int *posX,int *posY,int *dltZ,bool *mouse,bool *mouse2,bool *mouse_lado,int *keychar,bool *repete_keychar,ALLEGRO_EVENT_QUEUE *event_queue,ALLEGRO_TIMER *keyb_press_timer,ALLEGRO_TIMER *mouse_press_timer) {
    struct DotInstance *aux,*aux2 = NULL;
    bool ko = false;

    aux = card->dot_list;
    while(aux->prox != NULL && MonstroEmSlot(adversario,slot)) {
        Attack(-1,false,true,buffer,fim_de_jogo,rolagem,&ko,4,0,slot,sbox,jogador,adversario,NULL,aux->dot,display,prompt,selecao,roll_bar,fundo_carta,fundo_menu,deck_meio,deck_cheio,fundo,font,font2,color,bmp,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);
        aux->turns_left--;

        if(aux->turns_left == 0) {
            if(aux2 == NULL) {
                card->dot_list = aux->prox;
                free(aux);
                aux = card->dot_list;
            }
            else {
                aux2->prox = aux->prox;
                free(aux);
                aux = aux2->prox;
            }

            continue;
        }

        aux2 = aux;
        aux = aux->prox;
    }
}

void EfetuaDOT(struct Card **buffer,bool *fim_de_jogo,int *rolagem,struct StatusBox_bitmaps *sbox,struct Player *jogador,struct Player *adversario,ALLEGRO_DISPLAY *display,ALLEGRO_BITMAP *prompt,ALLEGRO_BITMAP *selecao,ALLEGRO_BITMAP *roll_bar,ALLEGRO_BITMAP *fundo_carta,ALLEGRO_BITMAP *fundo_menu,ALLEGRO_BITMAP *deck_meio,ALLEGRO_BITMAP *deck_cheio,ALLEGRO_BITMAP *fundo,ALLEGRO_FONT *font,ALLEGRO_FONT *font2,ALLEGRO_COLOR color,ALLEGRO_BITMAP *bmp,bool *sair,int *posX,int *posY,int *dltZ,bool *mouse,bool *mouse2,bool *mouse_lado,int *keychar,bool *repete_keychar,ALLEGRO_EVENT_QUEUE *event_queue,ALLEGRO_TIMER *keyb_press_timer,ALLEGRO_TIMER *mouse_press_timer) {
    if(adversario->mesa->monstro1 != NULL) EfetuaDOT_slot(adversario->mesa->monstro1,1,buffer,fim_de_jogo,rolagem,sbox,jogador,adversario,display,prompt,selecao,roll_bar,fundo_carta,fundo_menu,deck_meio,deck_cheio,fundo,font,font2,color,bmp,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);
    if(adversario->mesa->monstro2 != NULL) EfetuaDOT_slot(adversario->mesa->monstro2,2,buffer,fim_de_jogo,rolagem,sbox,jogador,adversario,display,prompt,selecao,roll_bar,fundo_carta,fundo_menu,deck_meio,deck_cheio,fundo,font,font2,color,bmp,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);
    if(adversario->mesa->monstro3 != NULL) EfetuaDOT_slot(adversario->mesa->monstro3,3,buffer,fim_de_jogo,rolagem,sbox,jogador,adversario,display,prompt,selecao,roll_bar,fundo_carta,fundo_menu,deck_meio,deck_cheio,fundo,font,font2,color,bmp,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);
    if(adversario->mesa->monstro4 != NULL) EfetuaDOT_slot(adversario->mesa->monstro4,4,buffer,fim_de_jogo,rolagem,sbox,jogador,adversario,display,prompt,selecao,roll_bar,fundo_carta,fundo_menu,deck_meio,deck_cheio,fundo,font,font2,color,bmp,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);
    if(adversario->mesa->monstro5 != NULL) EfetuaDOT_slot(adversario->mesa->monstro5,5,buffer,fim_de_jogo,rolagem,sbox,jogador,adversario,display,prompt,selecao,roll_bar,fundo_carta,fundo_menu,deck_meio,deck_cheio,fundo,font,font2,color,bmp,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);
    if(adversario->mesa->monstro6 != NULL) EfetuaDOT_slot(adversario->mesa->monstro6,6,buffer,fim_de_jogo,rolagem,sbox,jogador,adversario,display,prompt,selecao,roll_bar,fundo_carta,fundo_menu,deck_meio,deck_cheio,fundo,font,font2,color,bmp,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);
    if(adversario->mesa->monstro7 != NULL) EfetuaDOT_slot(adversario->mesa->monstro7,7,buffer,fim_de_jogo,rolagem,sbox,jogador,adversario,display,prompt,selecao,roll_bar,fundo_carta,fundo_menu,deck_meio,deck_cheio,fundo,font,font2,color,bmp,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);

    EfetuaDOT_slot(adversario->mesa->character,0,buffer,fim_de_jogo,rolagem,sbox,jogador,adversario,display,prompt,selecao,roll_bar,fundo_carta,fundo_menu,deck_meio,deck_cheio,fundo,font,font2,color,bmp,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);
}

void EfetuaBuffList(struct Player *jogador) {
    if(jogador->mesa->monstro1 != NULL) EfetuaBuff_slot(jogador->mesa->monstro1);
    if(jogador->mesa->monstro2 != NULL) EfetuaBuff_slot(jogador->mesa->monstro2);
    if(jogador->mesa->monstro3 != NULL) EfetuaBuff_slot(jogador->mesa->monstro3);
    if(jogador->mesa->monstro4 != NULL) EfetuaBuff_slot(jogador->mesa->monstro4);
    if(jogador->mesa->monstro5 != NULL) EfetuaBuff_slot(jogador->mesa->monstro5);
    if(jogador->mesa->monstro6 != NULL) EfetuaBuff_slot(jogador->mesa->monstro6);
    if(jogador->mesa->monstro7 != NULL) EfetuaBuff_slot(jogador->mesa->monstro7);

    EfetuaBuff_slot(jogador->mesa->character);
}

void DesfazBuff_hp(struct CARD *card) {
    struct BuffInstance *aux = card->buff_list;

    while(aux->prox != NULL) {
        card->MaxHP -= aux->hp;
        card->HP -= aux->hp;

        aux = aux->prox;
    }
}

void DesfazBuffList(struct Player *jogador) {
    if(jogador->mesa->monstro1 != NULL) DesfazBuff_hp(jogador->mesa->monstro1);
    if(jogador->mesa->monstro2 != NULL) DesfazBuff_hp(jogador->mesa->monstro2);
    if(jogador->mesa->monstro3 != NULL) DesfazBuff_hp(jogador->mesa->monstro3);
    if(jogador->mesa->monstro4 != NULL) DesfazBuff_hp(jogador->mesa->monstro4);
    if(jogador->mesa->monstro5 != NULL) DesfazBuff_hp(jogador->mesa->monstro5);
    if(jogador->mesa->monstro6 != NULL) DesfazBuff_hp(jogador->mesa->monstro6);
    if(jogador->mesa->monstro7 != NULL) DesfazBuff_hp(jogador->mesa->monstro7);

    DesfazBuff_hp(jogador->mesa->character);
}

#include "card_acoes3.c"

void ChargePass(int id_acao,struct Card **buffer,bool *fim_de_jogo,int *rolagem,struct StatusBox_bitmaps *sbox,struct Player *jogador,struct Player *adversario,ALLEGRO_DISPLAY *display,ALLEGRO_BITMAP *prompt,ALLEGRO_BITMAP *selecao,ALLEGRO_BITMAP *roll_bar,ALLEGRO_BITMAP *fundo_carta,ALLEGRO_BITMAP *fundo_menu,ALLEGRO_BITMAP *deck_meio,ALLEGRO_BITMAP *deck_cheio,ALLEGRO_BITMAP *fundo,ALLEGRO_FONT *font,ALLEGRO_FONT *font2,ALLEGRO_COLOR color,ALLEGRO_BITMAP *bmp,bool *sair,int *posX,int *posY,int *dltZ,bool *mouse,bool *mouse2,bool *mouse_lado,int *keychar,bool *repete_keychar,ALLEGRO_EVENT_QUEUE *event_queue,ALLEGRO_TIMER *keyb_press_timer,ALLEGRO_TIMER *mouse_press_timer,char *elemento,short int *contador) {
    bool ko = false;

    //aplica-se como DOT(4), nao TACTIC(3), pq intencao eh destruir o alvo, e nao danifica-lo.
    if(adversario->mesa->monstro1 != NULL && strcmp(adversario->mesa->monstro1->origem->elemento,elemento) != 0 && !EhBoss(adversario->mesa->monstro1)) Attack(id_acao,false,false,buffer,fim_de_jogo,rolagem,&ko,4,2,1,sbox,jogador,adversario,NULL,999,display,prompt,selecao,roll_bar,fundo_carta,fundo_menu,deck_meio,deck_cheio,fundo,font,font2,color,bmp,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);
    if(adversario->mesa->monstro2 != NULL && strcmp(adversario->mesa->monstro2->origem->elemento,elemento) != 0 && !EhBoss(adversario->mesa->monstro2)) Attack(id_acao,false,false,buffer,fim_de_jogo,rolagem,&ko,4,2,2,sbox,jogador,adversario,NULL,999,display,prompt,selecao,roll_bar,fundo_carta,fundo_menu,deck_meio,deck_cheio,fundo,font,font2,color,bmp,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);
    if(adversario->mesa->monstro3 != NULL && strcmp(adversario->mesa->monstro3->origem->elemento,elemento) != 0 && !EhBoss(adversario->mesa->monstro3)) Attack(id_acao,false,false,buffer,fim_de_jogo,rolagem,&ko,4,2,3,sbox,jogador,adversario,NULL,999,display,prompt,selecao,roll_bar,fundo_carta,fundo_menu,deck_meio,deck_cheio,fundo,font,font2,color,bmp,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);
    if(adversario->mesa->monstro4 != NULL && strcmp(adversario->mesa->monstro4->origem->elemento,elemento) != 0 && !EhBoss(adversario->mesa->monstro4)) Attack(id_acao,false,false,buffer,fim_de_jogo,rolagem,&ko,4,2,4,sbox,jogador,adversario,NULL,999,display,prompt,selecao,roll_bar,fundo_carta,fundo_menu,deck_meio,deck_cheio,fundo,font,font2,color,bmp,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);
    if(adversario->mesa->monstro5 != NULL && strcmp(adversario->mesa->monstro5->origem->elemento,elemento) != 0 && !EhBoss(adversario->mesa->monstro5)) Attack(id_acao,false,false,buffer,fim_de_jogo,rolagem,&ko,4,2,5,sbox,jogador,adversario,NULL,999,display,prompt,selecao,roll_bar,fundo_carta,fundo_menu,deck_meio,deck_cheio,fundo,font,font2,color,bmp,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);
    if(adversario->mesa->monstro6 != NULL && strcmp(adversario->mesa->monstro6->origem->elemento,elemento) != 0 && !EhBoss(adversario->mesa->monstro6)) Attack(id_acao,false,false,buffer,fim_de_jogo,rolagem,&ko,4,2,6,sbox,jogador,adversario,NULL,999,display,prompt,selecao,roll_bar,fundo_carta,fundo_menu,deck_meio,deck_cheio,fundo,font,font2,color,bmp,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);
    if(adversario->mesa->monstro7 != NULL && strcmp(adversario->mesa->monstro7->origem->elemento,elemento) != 0 && !EhBoss(adversario->mesa->monstro7)) Attack(id_acao,false,false,buffer,fim_de_jogo,rolagem,&ko,4,2,7,sbox,jogador,adversario,NULL,999,display,prompt,selecao,roll_bar,fundo_carta,fundo_menu,deck_meio,deck_cheio,fundo,font,font2,color,bmp,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);

    if(jogador->mesa->monstro1 != NULL && strcmp(jogador->mesa->monstro1->origem->elemento,elemento) != 0 && !EhBoss(jogador->mesa->monstro1)) Attack(id_acao,false,false,buffer,fim_de_jogo,rolagem,&ko,4,2,1,sbox,adversario,jogador,NULL,999,display,prompt,selecao,roll_bar,fundo_carta,fundo_menu,deck_meio,deck_cheio,fundo,font,font2,color,bmp,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);
    if(jogador->mesa->monstro2 != NULL && strcmp(jogador->mesa->monstro2->origem->elemento,elemento) != 0 && !EhBoss(jogador->mesa->monstro2)) Attack(id_acao,false,false,buffer,fim_de_jogo,rolagem,&ko,4,2,2,sbox,adversario,jogador,NULL,999,display,prompt,selecao,roll_bar,fundo_carta,fundo_menu,deck_meio,deck_cheio,fundo,font,font2,color,bmp,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);
    if(jogador->mesa->monstro3 != NULL && strcmp(jogador->mesa->monstro3->origem->elemento,elemento) != 0 && !EhBoss(jogador->mesa->monstro3)) Attack(id_acao,false,false,buffer,fim_de_jogo,rolagem,&ko,4,2,3,sbox,adversario,jogador,NULL,999,display,prompt,selecao,roll_bar,fundo_carta,fundo_menu,deck_meio,deck_cheio,fundo,font,font2,color,bmp,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);
    if(jogador->mesa->monstro4 != NULL && strcmp(jogador->mesa->monstro4->origem->elemento,elemento) != 0 && !EhBoss(jogador->mesa->monstro4)) Attack(id_acao,false,false,buffer,fim_de_jogo,rolagem,&ko,4,2,4,sbox,adversario,jogador,NULL,999,display,prompt,selecao,roll_bar,fundo_carta,fundo_menu,deck_meio,deck_cheio,fundo,font,font2,color,bmp,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);
    if(jogador->mesa->monstro5 != NULL && strcmp(jogador->mesa->monstro5->origem->elemento,elemento) != 0 && !EhBoss(jogador->mesa->monstro5)) Attack(id_acao,false,false,buffer,fim_de_jogo,rolagem,&ko,4,2,5,sbox,adversario,jogador,NULL,999,display,prompt,selecao,roll_bar,fundo_carta,fundo_menu,deck_meio,deck_cheio,fundo,font,font2,color,bmp,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);
    if(jogador->mesa->monstro6 != NULL && strcmp(jogador->mesa->monstro6->origem->elemento,elemento) != 0 && !EhBoss(jogador->mesa->monstro6)) Attack(id_acao,false,false,buffer,fim_de_jogo,rolagem,&ko,4,2,6,sbox,adversario,jogador,NULL,999,display,prompt,selecao,roll_bar,fundo_carta,fundo_menu,deck_meio,deck_cheio,fundo,font,font2,color,bmp,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);
    if(jogador->mesa->monstro7 != NULL && strcmp(jogador->mesa->monstro7->origem->elemento,elemento) != 0 && !EhBoss(jogador->mesa->monstro7)) Attack(id_acao,false,false,buffer,fim_de_jogo,rolagem,&ko,4,2,7,sbox,adversario,jogador,NULL,999,display,prompt,selecao,roll_bar,fundo_carta,fundo_menu,deck_meio,deck_cheio,fundo,font,font2,color,bmp,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);

    (*contador)++;
}

void MonsterActions_AposTactic(struct CARD *monstro,int lado,int id_acao,struct Card **buffer,bool *fim_de_jogo,int *rolagem,struct StatusBox_bitmaps *sbox,ALLEGRO_BITMAP *prompt,ALLEGRO_BITMAP *selecao,ALLEGRO_BITMAP *roll_bar,ALLEGRO_BITMAP *fundo_carta,ALLEGRO_BITMAP *fundo_menu,ALLEGRO_BITMAP *deck_meio,ALLEGRO_BITMAP *deck_cheio,ALLEGRO_BITMAP *pont,struct Player *jogador,struct Player *adversario,ALLEGRO_DISPLAY *display,ALLEGRO_BITMAP *fundo,ALLEGRO_FONT *font,ALLEGRO_FONT *font2,ALLEGRO_COLOR color,bool *sair,int *posX,int *posY,int *dltZ,bool *mouse,bool *mouse2,bool *mouse_lado,int *keychar,bool *repete_keychar,ALLEGRO_EVENT_QUEUE *event_queue,ALLEGRO_TIMER *keyb_press_timer,ALLEGRO_TIMER *mouse_press_timer) {
    //lado: 1 -> jogador    2 -> adversario

    if(monstro != NULL) {
        if(monstro->origem->colecao == LIZALFOS) monstro->var_monster->lizalfos_cont++;

        else if(lado == 1) {
            if(monstro->origem->colecao == SKULL_KID && monstro->turn_silenced == 0) skull_kid_acao(id_acao,buffer,fim_de_jogo,rolagem,sbox,prompt,selecao,roll_bar,fundo_carta,fundo_menu,deck_meio,deck_cheio,pont,jogador,adversario,display,fundo,font,font2,color,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);
        }
    }
}

void play_card_slot(struct CARD *card,int id_acao,struct Card **buffer,bool *fim_de_jogo,int *rolagem,bool *ko,struct StatusBox_bitmaps *sbox,struct Player *jogador,struct Player *adversario,ALLEGRO_DISPLAY *display,ALLEGRO_BITMAP *prompt,ALLEGRO_BITMAP *selecao,ALLEGRO_BITMAP *roll_bar,ALLEGRO_BITMAP *fundo_carta,ALLEGRO_BITMAP *fundo_menu,ALLEGRO_BITMAP *deck_meio,ALLEGRO_BITMAP *deck_cheio,ALLEGRO_BITMAP *fundo,ALLEGRO_FONT *font,ALLEGRO_FONT *font2,ALLEGRO_COLOR color,ALLEGRO_BITMAP *bmp,bool *sair,int *posX,int *posY,int *dltZ,bool *mouse,bool *mouse2,bool *mouse_lado,int *keychar,bool *repete_keychar,ALLEGRO_EVENT_QUEUE *event_queue,ALLEGRO_TIMER *keyb_press_timer,ALLEGRO_TIMER *mouse_press_timer) {
    if(card->origem->colecao == IRON_KNUCKLES) Attack(-1,true,false,buffer,fim_de_jogo,rolagem,ko,0,0,0,sbox,adversario,jogador,card,20,display,prompt,selecao,roll_bar,fundo_carta,fundo_menu,deck_meio,deck_cheio,fundo,font,font2,color,bmp,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);

}

void play_card_effects(int id_acao,struct Card **buffer,bool *fim_de_jogo,int *rolagem,struct StatusBox_bitmaps *sbox,struct Player *jogador,struct Player *adversario,ALLEGRO_DISPLAY *display,ALLEGRO_BITMAP *prompt,ALLEGRO_BITMAP *selecao,ALLEGRO_BITMAP *roll_bar,ALLEGRO_BITMAP *fundo_carta,ALLEGRO_BITMAP *fundo_menu,ALLEGRO_BITMAP *deck_meio,ALLEGRO_BITMAP *deck_cheio,ALLEGRO_BITMAP *fundo,ALLEGRO_FONT *font,ALLEGRO_FONT *font2,ALLEGRO_COLOR color,ALLEGRO_BITMAP *bmp,bool *sair,int *posX,int *posY,int *dltZ,bool *mouse,bool *mouse2,bool *mouse_lado,int *keychar,bool *repete_keychar,ALLEGRO_EVENT_QUEUE *event_queue,ALLEGRO_TIMER *keyb_press_timer,ALLEGRO_TIMER *mouse_press_timer) {
    bool ko;

    if(adversario->mesa->monstro1 != NULL && adversario->mesa->monstro1->turn_silenced == 0) play_card_slot(adversario->mesa->monstro1,id_acao,buffer,fim_de_jogo,rolagem,&ko,sbox,jogador,adversario,display,prompt,selecao,roll_bar,fundo_carta,fundo_menu,deck_meio,deck_cheio,fundo,font,font2,color,bmp,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);
    if(adversario->mesa->monstro2 != NULL && adversario->mesa->monstro2->turn_silenced == 0) play_card_slot(adversario->mesa->monstro2,id_acao,buffer,fim_de_jogo,rolagem,&ko,sbox,jogador,adversario,display,prompt,selecao,roll_bar,fundo_carta,fundo_menu,deck_meio,deck_cheio,fundo,font,font2,color,bmp,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);
    if(adversario->mesa->monstro3 != NULL && adversario->mesa->monstro3->turn_silenced == 0) play_card_slot(adversario->mesa->monstro3,id_acao,buffer,fim_de_jogo,rolagem,&ko,sbox,jogador,adversario,display,prompt,selecao,roll_bar,fundo_carta,fundo_menu,deck_meio,deck_cheio,fundo,font,font2,color,bmp,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);
    if(adversario->mesa->monstro4 != NULL && adversario->mesa->monstro4->turn_silenced == 0) play_card_slot(adversario->mesa->monstro4,id_acao,buffer,fim_de_jogo,rolagem,&ko,sbox,jogador,adversario,display,prompt,selecao,roll_bar,fundo_carta,fundo_menu,deck_meio,deck_cheio,fundo,font,font2,color,bmp,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);
    if(adversario->mesa->monstro5 != NULL && adversario->mesa->monstro5->turn_silenced == 0) play_card_slot(adversario->mesa->monstro5,id_acao,buffer,fim_de_jogo,rolagem,&ko,sbox,jogador,adversario,display,prompt,selecao,roll_bar,fundo_carta,fundo_menu,deck_meio,deck_cheio,fundo,font,font2,color,bmp,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);
    if(adversario->mesa->monstro6 != NULL && adversario->mesa->monstro6->turn_silenced == 0) play_card_slot(adversario->mesa->monstro6,id_acao,buffer,fim_de_jogo,rolagem,&ko,sbox,jogador,adversario,display,prompt,selecao,roll_bar,fundo_carta,fundo_menu,deck_meio,deck_cheio,fundo,font,font2,color,bmp,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);
    if(adversario->mesa->monstro7 != NULL && adversario->mesa->monstro7->turn_silenced == 0) play_card_slot(adversario->mesa->monstro7,id_acao,buffer,fim_de_jogo,rolagem,&ko,sbox,jogador,adversario,display,prompt,selecao,roll_bar,fundo_carta,fundo_menu,deck_meio,deck_cheio,fundo,font,font2,color,bmp,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);
}

void PlayTactic(int id_acao,struct Deck *aux,struct Card **buffer,bool *fim,int *rolagem,struct StatusBox_bitmaps *sbox,struct Player *jogador,struct Player *adversario,ALLEGRO_DISPLAY *display,ALLEGRO_BITMAP *prompt,ALLEGRO_BITMAP *selecao,ALLEGRO_BITMAP *roll_bar,ALLEGRO_BITMAP *apontador,ALLEGRO_BITMAP *fundo_carta,ALLEGRO_BITMAP *fundo_menu,ALLEGRO_BITMAP *deck_meio,ALLEGRO_BITMAP *deck_cheio,ALLEGRO_BITMAP *fundo,ALLEGRO_FONT *font,ALLEGRO_FONT *font2,ALLEGRO_COLOR color,bool *sair,int *posX,int *posY,int *dltZ,bool *mouse,bool *mouse2,bool *mouse_lado,int *keychar,bool *repete_keychar,ALLEGRO_EVENT_QUEUE *event_queue,ALLEGRO_TIMER *keyb_press_timer,ALLEGRO_TIMER *mouse_press_timer) {
    /* LISTA DE TACTICS */
    /*::: PONTO DE FUNCAO #13 ::: */
    if(aux->card->origem->colecao == GREAT_DEKUS_BLESS) {  //taticas de aumento de ataque se sobrepoem quando card eh o msm.
        jogador->var_tactic->great_dekus_bless_cont++;
        DrawCard(id_acao,buffer,fim,rolagem,sbox,prompt,selecao,roll_bar,fundo_carta,fundo_menu,deck_meio,deck_cheio,apontador,jogador,adversario,display,fundo,font,font2,color,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);
    }
    else if(aux->card->origem->colecao == SPIRIT_MEDALLION) {
        spirit_medallion_acao(jogador,adversario,1);
        jogador->var_tactic->spirit_medallion_cont++;
    }
    else if(aux->card->origem->colecao == BLESS_OF_TRIFORCE) {
        bless_of_triforce_acao(id_acao,aux->card,buffer,fim,rolagem,sbox,jogador,adversario,display,prompt,selecao,roll_bar,fundo_carta,fundo_menu,deck_meio,deck_cheio,fundo,font,font2,color,apontador,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);
        jogador->var_tactic->bless_of_triforce_cont += 1;
    }
    else if(aux->card->origem->colecao == SKULLTULAS_AMBUSH) {
        skulltulas_ambush_acao(id_acao,buffer,fim,rolagem,sbox,selecao,roll_bar,fundo_carta,fundo_menu,deck_meio,deck_cheio,apontador,jogador,adversario,display,fundo,font,font2,color,prompt,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);
    }
    else if(aux->card->origem->colecao == HEART_PIECE) {
        heart_piece_acao(id_acao,buffer,fim,rolagem,sbox,selecao,roll_bar,fundo_carta,fundo_menu,prompt,deck_meio,deck_cheio,apontador,jogador,adversario,display,fundo,font,font2,color,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);
    }
    else if(aux->card->origem->colecao == MILK_BOTTLE) {
        milk_bottle_acao(id_acao,buffer,fim,rolagem,sbox,prompt,selecao,roll_bar,fundo_carta,fundo_menu,deck_meio,deck_cheio,apontador,jogador,adversario,display,fundo,font,font2,color,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);
    }
    else if(aux->card->origem->colecao == SMALL_KEY) {
        small_key_acao(id_acao,buffer,fim,rolagem,sbox,prompt,selecao,roll_bar,fundo_carta,fundo_menu,deck_meio,deck_cheio,apontador,jogador,adversario,display,fundo,font,font2,color,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);
    }
    else if(aux->card->origem->colecao == GREAT_DEKU_TREES_KNOWLEDGE) {
        EscolheCardDoDeck(id_acao,buffer,fim,rolagem,sbox,prompt,selecao,roll_bar,fundo_carta,fundo_menu,deck_meio,deck_cheio,apontador,jogador,adversario,display,fundo,font,font2,color,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);
    }
    else if(aux->card->origem->colecao == BOMB_RAIN) {
        bomb_rain_acao(id_acao,buffer,fim,rolagem,sbox,jogador,adversario,display,prompt,selecao,roll_bar,fundo_carta,fundo_menu,deck_meio,deck_cheio,fundo,font,font2,color,apontador,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);
    }
    else if(aux->card->origem->colecao == FAIRYS_AID) {
        fairys_aid_acao(id_acao,buffer,fim,rolagem,sbox,prompt,selecao,roll_bar,fundo_carta,fundo_menu,deck_meio,deck_cheio,apontador,jogador,adversario,display,fundo,font,font2,color,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);
    }
    else if(aux->card->origem->colecao == TRIPLE_SHOT) {
        triple_shot_acao(id_acao,buffer,fim,rolagem,sbox,jogador,adversario,display,prompt,selecao,roll_bar,fundo_carta,fundo_menu,deck_meio,deck_cheio,fundo,font,font2,color,apontador,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);
    }
    else if(aux->card->origem->colecao == DEKU_NUT) {
        deku_nut_acao(adversario);
    }
    else if(aux->card->origem->colecao == DARK_PATHWAY) {
        ChargePass(id_acao,buffer,fim,rolagem,sbox,jogador,adversario,display,prompt,selecao,roll_bar,fundo_carta,fundo_menu,deck_meio,deck_cheio,fundo,font,font2,color,apontador,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer,"Dark",&(jogador->var_tactic->dark_pathway_cont));
    }
    else if(aux->card->origem->colecao == MAGIC_JAR) {
        magic_jar_acao(id_acao,buffer,fim,rolagem,sbox,prompt,selecao,roll_bar,fundo_carta,fundo_menu,deck_meio,deck_cheio,apontador,jogador,adversario,display,fundo,font,font2,color,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);
    }
    else if(aux->card->origem->colecao == GIVE_AWAY) {
        DestroyEquipment(id_acao,fim,buffer,rolagem,sbox,jogador,adversario,display,prompt,selecao,roll_bar,fundo_carta,fundo_menu,deck_meio,deck_cheio,fundo,font,font2,color,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer,apontador);
    }
    else if(aux->card->origem->colecao == ICE_ARROW) {
        ice_arrow_acao(aux->card,id_acao,buffer,fim,rolagem,sbox,jogador,adversario,display,prompt,selecao,roll_bar,fundo_carta,fundo_menu,deck_meio,deck_cheio,fundo,font,font2,color,apontador,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);
    }
    else if(aux->card->origem->colecao == PLAY_OCARINA) {
        play_ocarina_acao(id_acao,buffer,fim,sbox,selecao,roll_bar,fundo_menu,fundo_carta,deck_meio,deck_cheio,apontador,jogador,adversario,display,fundo,prompt,font,font2,color,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer,rolagem);
    }
    else if(aux->card->origem->colecao == OPEN_CHEST) {
        open_chest_acao(id_acao,buffer,fim,rolagem,sbox,prompt,selecao,roll_bar,fundo_carta,deck_meio,deck_cheio,apontador,jogador,adversario,display,fundo_menu,fundo,font,font2,color,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);
    }
    else if(aux->card->origem->colecao == CRYSTAL_SWITCH) {
        DrawCard(id_acao,buffer,fim,rolagem,sbox,prompt,selecao,roll_bar,fundo_carta,fundo_menu,deck_meio,deck_cheio,apontador,jogador,adversario,display,fundo,font,font2,color,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);
        DrawCard(id_acao,buffer,fim,rolagem,sbox,prompt,selecao,roll_bar,fundo_carta,fundo_menu,deck_meio,deck_cheio,apontador,jogador,adversario,display,fundo,font,font2,color,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);
    }
    else if(aux->card->origem->colecao == RAZE) {
        raze_acao(id_acao,aux->card,buffer,fim,rolagem,sbox,jogador,adversario,display,prompt,selecao,roll_bar,fundo_carta,fundo_menu,deck_meio,deck_cheio,fundo,font,font2,color,apontador,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);
    }
    else if(aux->card->origem->colecao == DINS_FIRE) {
        dins_fire_acao(id_acao,aux->card,buffer,fim,rolagem,sbox,jogador,adversario,display,prompt,selecao,roll_bar,fundo_carta,fundo_menu,deck_meio,deck_cheio,fundo,font,font2,color,apontador,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);
    }
    else if(aux->card->origem->colecao == MOUNTAIN_CLIMBING) {
        WithdrawCharacter(id_acao,buffer,fim,rolagem,sbox,prompt,selecao,roll_bar,fundo_carta,fundo_menu,deck_meio,deck_cheio,apontador,jogador,adversario,display,fundo,font,font2,color,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);
    }
    else if(aux->card->origem->colecao == HORSE_RIDING) {
        horse_riding_acao(jogador);
    }
    else if(aux->card->origem->colecao == _1_TON_ROCK_LIFTING) {
        if(PossuiGauntlets(jogador)) jogador->var_tactic->_1trl_gauntlet_cont += 1;
        else jogador->var_tactic->_1trl_no_gauntlet_cont += 1;
    }
    else if(aux->card->origem->colecao == GUILLOTINE) {
        guillotine_acao(id_acao,buffer,fim,rolagem,sbox,jogador,adversario,aux->card,display,prompt,selecao,roll_bar,fundo_carta,fundo_menu,deck_meio,deck_cheio,fundo,font,font2,color,apontador,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);
    }
    else if(aux->card->origem->colecao == GERUDOS_MEMBERSHIP_CARD) {
        ChargePass(id_acao,buffer,fim,rolagem,sbox,jogador,adversario,display,prompt,selecao,roll_bar,fundo_carta,fundo_menu,deck_meio,deck_cheio,fundo,font,font2,color,apontador,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer,"Wind",&(jogador->var_tactic->gerudos_membership_card_cont));
    }
    else if(aux->card->origem->colecao == SHADOW_MERGE) {
        shadow_merge_acao(id_acao,buffer,fim,rolagem,sbox,jogador,adversario,display,prompt,selecao,roll_bar,apontador,fundo_carta,fundo_menu,deck_meio,deck_cheio,fundo,font,font2,color,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);
    }
    else if(aux->card->origem->colecao == WARP) {
        WithdrawCharacter(id_acao,buffer,fim,rolagem,sbox,prompt,selecao,roll_bar,fundo_carta,fundo_menu,deck_meio,deck_cheio,apontador,jogador,adversario,display,fundo,font,font2,color,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);
    }
    else if(aux->card->origem->colecao == LIGHT_MEDALLION) {
        jogador->var_tactic->light_medallion_cont++;
        DrawCard(id_acao,buffer,fim,rolagem,sbox,prompt,selecao,roll_bar,fundo_carta,fundo_menu,deck_meio,deck_cheio,apontador,jogador,adversario,display,fundo,font,font2,color,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);
    }
    else if(aux->card->origem->colecao == FIRE_ARROW) {
        fire_arrow_acao(aux->card,id_acao,buffer,fim,rolagem,sbox,jogador,adversario,display,prompt,selecao,roll_bar,apontador,fundo_carta,fundo_menu,deck_meio,deck_cheio,fundo,font,font2,color,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);
    }
    else if(aux->card->origem->colecao == JUMP_QUEST_WATER) {
        jump_quest("Water",id_acao,buffer,fim,rolagem,sbox,prompt,selecao,roll_bar,fundo_carta,fundo_menu,deck_meio,deck_cheio,apontador,jogador,adversario,display,fundo,font,font2,color,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);
    }
    else if(aux->card->origem->colecao == WHIRLING_SCYTHES) {
        whirling_scythes_acao(aux->card,id_acao,buffer,fim,rolagem,sbox,jogador,adversario,display,prompt,selecao,roll_bar,apontador,fundo_carta,fundo_menu,deck_meio,deck_cheio,fundo,font,font2,color,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);
    }
    else if(aux->card->origem->colecao == SUNSET) {
        sunset_acao(id_acao,buffer,fim,rolagem,sbox,jogador,adversario,display,prompt,selecao,roll_bar,apontador,fundo_carta,fundo_menu,deck_meio,deck_cheio,fundo,font,font2,color,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);
    }
    else if(aux->card->origem->colecao == CHANNELED_STRIKE) {  //taticas de aumento de ataque se sobrepoem quando card eh o msm.
        jogador->var_tactic->channeled_strike_cont++;
    }
    else if(aux->card->origem->colecao == JUMP_QUEST_WIND) {
        jump_quest("Wind",id_acao,buffer,fim,rolagem,sbox,prompt,selecao,roll_bar,fundo_carta,fundo_menu,deck_meio,deck_cheio,apontador,jogador,adversario,display,fundo,font,font2,color,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);
    }
    else if(aux->card->origem->colecao == UNDERGROUND_SHELTER) {
        jogador->var_tactic->underground_shelter_cont++;
    }
    else if(aux->card->origem->colecao == TRICKY_SHOT) {
        tricky_shot_acao(id_acao,aux->card,buffer,fim,rolagem,sbox,prompt,selecao,roll_bar,fundo_carta,fundo_menu,deck_meio,deck_cheio,apontador,jogador,adversario,display,fundo,font,font2,color,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);
    }
    else if(aux->card->origem->colecao == FAIRY_FOUNTAIN) {
        fairy_fountain_acao(id_acao,buffer,fim,rolagem,sbox,prompt,selecao,roll_bar,fundo_carta,fundo_menu,deck_meio,deck_cheio,apontador,jogador,adversario,display,fundo,font,font2,color,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);
    }
    else if(aux->card->origem->colecao == MYSTIC_SPELL) {
        RecuperaCard(buffer,fim,rolagem,-1,true,999,prompt,selecao,roll_bar,fundo_menu,fundo_carta,deck_meio,deck_cheio,apontador,jogador,adversario,display,fundo,font,font2,color,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);
    }
    else if(aux->card->origem->colecao == GREAT_FAIRYS_BLESS) {
        RefreshHP(id_acao,buffer,jogador->mesa->character,100,fim,rolagem,sbox,prompt,selecao,roll_bar,fundo_carta,fundo_menu,deck_meio,deck_cheio,apontador,jogador,adversario,display,fundo,font,font2,color,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);
        jogador->var_tactic->great_fairys_bless_cont++;
    }

    printf(" ... ");
    //else if(aux->card->origem->colecao == GORON_RUBY) tactics->goron_ruby_bool = true;

        /*       FIM        */

    MonsterActions_AposTactic(jogador->mesa->monstro1,1,id_acao,buffer,fim,rolagem,sbox,prompt,selecao,roll_bar,fundo_carta,fundo_menu,deck_meio,deck_cheio,apontador,jogador,adversario,display,fundo,font,font2,color,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);
    MonsterActions_AposTactic(jogador->mesa->monstro2,1,id_acao,buffer,fim,rolagem,sbox,prompt,selecao,roll_bar,fundo_carta,fundo_menu,deck_meio,deck_cheio,apontador,jogador,adversario,display,fundo,font,font2,color,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);
    MonsterActions_AposTactic(jogador->mesa->monstro3,1,id_acao,buffer,fim,rolagem,sbox,prompt,selecao,roll_bar,fundo_carta,fundo_menu,deck_meio,deck_cheio,apontador,jogador,adversario,display,fundo,font,font2,color,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);
    MonsterActions_AposTactic(jogador->mesa->monstro4,1,id_acao,buffer,fim,rolagem,sbox,prompt,selecao,roll_bar,fundo_carta,fundo_menu,deck_meio,deck_cheio,apontador,jogador,adversario,display,fundo,font,font2,color,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);
    MonsterActions_AposTactic(jogador->mesa->monstro5,1,id_acao,buffer,fim,rolagem,sbox,prompt,selecao,roll_bar,fundo_carta,fundo_menu,deck_meio,deck_cheio,apontador,jogador,adversario,display,fundo,font,font2,color,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);
    MonsterActions_AposTactic(jogador->mesa->monstro6,1,id_acao,buffer,fim,rolagem,sbox,prompt,selecao,roll_bar,fundo_carta,fundo_menu,deck_meio,deck_cheio,apontador,jogador,adversario,display,fundo,font,font2,color,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);
    MonsterActions_AposTactic(jogador->mesa->monstro7,1,id_acao,buffer,fim,rolagem,sbox,prompt,selecao,roll_bar,fundo_carta,fundo_menu,deck_meio,deck_cheio,apontador,jogador,adversario,display,fundo,font,font2,color,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);

    MonsterActions_AposTactic(adversario->mesa->monstro1,2,id_acao,buffer,fim,rolagem,sbox,prompt,selecao,roll_bar,fundo_carta,fundo_menu,deck_meio,deck_cheio,apontador,jogador,adversario,display,fundo,font,font2,color,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);
    MonsterActions_AposTactic(adversario->mesa->monstro2,2,id_acao,buffer,fim,rolagem,sbox,prompt,selecao,roll_bar,fundo_carta,fundo_menu,deck_meio,deck_cheio,apontador,jogador,adversario,display,fundo,font,font2,color,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);
    MonsterActions_AposTactic(adversario->mesa->monstro3,2,id_acao,buffer,fim,rolagem,sbox,prompt,selecao,roll_bar,fundo_carta,fundo_menu,deck_meio,deck_cheio,apontador,jogador,adversario,display,fundo,font,font2,color,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);
    MonsterActions_AposTactic(adversario->mesa->monstro4,2,id_acao,buffer,fim,rolagem,sbox,prompt,selecao,roll_bar,fundo_carta,fundo_menu,deck_meio,deck_cheio,apontador,jogador,adversario,display,fundo,font,font2,color,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);
    MonsterActions_AposTactic(adversario->mesa->monstro5,2,id_acao,buffer,fim,rolagem,sbox,prompt,selecao,roll_bar,fundo_carta,fundo_menu,deck_meio,deck_cheio,apontador,jogador,adversario,display,fundo,font,font2,color,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);
    MonsterActions_AposTactic(adversario->mesa->monstro6,2,id_acao,buffer,fim,rolagem,sbox,prompt,selecao,roll_bar,fundo_carta,fundo_menu,deck_meio,deck_cheio,apontador,jogador,adversario,display,fundo,font,font2,color,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);
    MonsterActions_AposTactic(adversario->mesa->monstro7,2,id_acao,buffer,fim,rolagem,sbox,prompt,selecao,roll_bar,fundo_carta,fundo_menu,deck_meio,deck_cheio,apontador,jogador,adversario,display,fundo,font,font2,color,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);

    if(jogador->mesa->equip1 != NULL && jogador->mesa->equip1->origem->colecao == GOSSIP_STONE) gossip_stone_acao(id_acao,buffer,fim,rolagem,sbox,selecao,roll_bar,fundo_carta,fundo_menu,prompt,deck_meio,deck_cheio,apontador,jogador,adversario,display,fundo,font,font2,color,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);
    if(jogador->mesa->equip2 != NULL && jogador->mesa->equip2->origem->colecao == GOSSIP_STONE) gossip_stone_acao(id_acao,buffer,fim,rolagem,sbox,selecao,roll_bar,fundo_carta,fundo_menu,prompt,deck_meio,deck_cheio,apontador,jogador,adversario,display,fundo,font,font2,color,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);
    if(jogador->mesa->equip3 != NULL && jogador->mesa->equip3->origem->colecao == GOSSIP_STONE) gossip_stone_acao(id_acao,buffer,fim,rolagem,sbox,selecao,roll_bar,fundo_carta,fundo_menu,prompt,deck_meio,deck_cheio,apontador,jogador,adversario,display,fundo,font,font2,color,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);
    if(jogador->mesa->equip4 != NULL && jogador->mesa->equip4->origem->colecao == GOSSIP_STONE) gossip_stone_acao(id_acao,buffer,fim,rolagem,sbox,selecao,roll_bar,fundo_carta,fundo_menu,prompt,deck_meio,deck_cheio,apontador,jogador,adversario,display,fundo,font,font2,color,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);
    if(jogador->mesa->equip5 != NULL && jogador->mesa->equip5->origem->colecao == GOSSIP_STONE) gossip_stone_acao(id_acao,buffer,fim,rolagem,sbox,selecao,roll_bar,fundo_carta,fundo_menu,prompt,deck_meio,deck_cheio,apontador,jogador,adversario,display,fundo,font,font2,color,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);
    if(jogador->mesa->equip6 != NULL && jogador->mesa->equip6->origem->colecao == GOSSIP_STONE) gossip_stone_acao(id_acao,buffer,fim,rolagem,sbox,selecao,roll_bar,fundo_carta,fundo_menu,prompt,deck_meio,deck_cheio,apontador,jogador,adversario,display,fundo,font,font2,color,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);
    if(jogador->mesa->equip7 != NULL && jogador->mesa->equip7->origem->colecao == GOSSIP_STONE) gossip_stone_acao(id_acao,buffer,fim,rolagem,sbox,selecao,roll_bar,fundo_carta,fundo_menu,prompt,deck_meio,deck_cheio,apontador,jogador,adversario,display,fundo,font,font2,color,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);

    compass_acao(aux->card,id_acao,buffer,fim,sbox,prompt,selecao,roll_bar,fundo_carta,fundo_menu,deck_meio,deck_cheio,apontador,jogador,adversario,display,fundo,font,font2,color,rolagem,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);

    printf("quase la... ");
    DestroyCard(aux,jogador,adversario);
    AtualizaMesa(true,NULL,id_acao,-1,0,buffer,fim,sbox,prompt,selecao,roll_bar,fundo_carta,fundo_menu,deck_meio,deck_cheio,fundo,apontador,jogador,adversario,display,font,font2,color,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer,rolagem,NULL,-1,-1,0,-1,NULL,NULL);
    printf("OK!\n");

    play_card_effects(id_acao,buffer,fim,rolagem,sbox,jogador,adversario,display,prompt,selecao,roll_bar,fundo_carta,fundo_menu,deck_meio,deck_cheio,fundo,font,font2,color,apontador,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);
}

void AplicaEOTTactics(struct Card **buffer,bool *fim,int *rolagem,struct StatusBox_bitmaps *sbox,struct Player *jogador,struct Player *adversario,ALLEGRO_DISPLAY *display,ALLEGRO_BITMAP *prompt,ALLEGRO_BITMAP *selecao,ALLEGRO_BITMAP *roll_bar,ALLEGRO_BITMAP *apontador,ALLEGRO_BITMAP *fundo_carta,ALLEGRO_BITMAP *fundo_menu,ALLEGRO_BITMAP *deck_meio,ALLEGRO_BITMAP *deck_cheio,ALLEGRO_BITMAP *fundo,ALLEGRO_FONT *font,ALLEGRO_FONT *font2,ALLEGRO_COLOR color,bool *sair,int *posX,int *posY,int *dltZ,bool *mouse,bool *mouse2,bool *mouse_lado,int *keychar,bool *repete_keychar,ALLEGRO_EVENT_QUEUE *event_queue,ALLEGRO_TIMER *keyb_press_timer,ALLEGRO_TIMER *mouse_press_timer) {
    struct Deck *aux,*aux2;

    aux = jogador->end_turn_tactics;
    aux2 = NULL;
    printf("---APLICANDO TATICAS DE FIM DE TURNO---\n");
    while(aux->prox != NULL) {
        aux2 = aux;
        aux = aux->prox;
        printf("'%s'\n",aux2->card->origem->nome);
        PlayTactic(-1,aux2,buffer,fim,rolagem,sbox,jogador,adversario,display,prompt,selecao,roll_bar,apontador,fundo_carta,fundo_menu,deck_meio,deck_cheio,fundo,font,font2,color,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);
    }

    jogador->end_turn_tactics = aux;

    printf("-----------FIM DE APLICACAO-----------\n");
}

void goron_ruby_acao2(int id_acao,struct Card **buffer,bool *fim,int *rolagem,struct StatusBox_bitmaps *sbox,ALLEGRO_BITMAP *prompt,ALLEGRO_BITMAP *selecao,ALLEGRO_BITMAP *roll_bar,ALLEGRO_BITMAP *apontador,ALLEGRO_BITMAP *fundo_carta,ALLEGRO_BITMAP *fundo_menu,ALLEGRO_BITMAP *deck_meio,ALLEGRO_BITMAP *deck_cheio,struct Player *jogador,struct Player *adversario,ALLEGRO_DISPLAY *display,ALLEGRO_BITMAP *fundo,ALLEGRO_FONT *font,ALLEGRO_FONT *font2,ALLEGRO_COLOR color,bool *sair,int *posX,int *posY,int *dltZ,bool *mouse,bool *mouse2,bool *mouse_lado,int *keychar,bool *repete_keychar,ALLEGRO_EVENT_QUEUE *event_queue,ALLEGRO_TIMER *keyb_press_timer,ALLEGRO_TIMER *mouse_press_timer) {
    struct Deck *aux;

    if(jogador->deck->quantidade == 0) return;
    OlhaCarta(id_acao,buffer,fim,sbox,prompt,selecao,roll_bar,fundo_carta,fundo_menu,deck_meio,deck_cheio,apontador,jogador,adversario,display,fundo,font,font2,color,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer,rolagem);

    if(strcmp(jogador->deck->inicio->card->origem->tipo,"Tactic") == 0) {
        aux = RetiraPrimeiroCard(&(jogador->deck));
        PlayTactic(id_acao,aux,buffer,fim,rolagem,sbox,jogador,adversario,display,prompt,selecao,roll_bar,apontador,fundo_carta,fundo_menu,deck_meio,deck_cheio,fundo,font,font2,color,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);
    }
}

//USADO PELO GUAY BOSS!!!
void ScoutDrawMonster(int id_acao,struct Card **buffer,bool *fim,int *rolagem,struct StatusBox_bitmaps *sbox,ALLEGRO_BITMAP *prompt,ALLEGRO_BITMAP *selecao,ALLEGRO_BITMAP *roll_bar,ALLEGRO_BITMAP *fundo_carta,ALLEGRO_BITMAP *fundo_menu,ALLEGRO_BITMAP *deck_meio,ALLEGRO_BITMAP *deck_cheio,ALLEGRO_BITMAP *pont,struct Player *jogador,struct Player *adversario,ALLEGRO_DISPLAY *display,ALLEGRO_BITMAP *fundo,ALLEGRO_FONT *font,ALLEGRO_FONT *font2,ALLEGRO_COLOR color,bool *sair,int *posX,int *posY,int *dltZ,bool *mouse,bool *mouse2,bool *mouse_lado,int *keychar,bool *repete_keychar,ALLEGRO_EVENT_QUEUE *event_queue,ALLEGRO_TIMER *keyb_press_timer,ALLEGRO_TIMER *mouse_press_timer) { //OK!
    if(jogador->deck->quantidade == 0) return;

    OlhaCarta(id_acao,buffer,fim,sbox,prompt,selecao,roll_bar,fundo_carta,fundo_menu,deck_meio,deck_cheio,pont,jogador,adversario,display,fundo,font,font2,color,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer,rolagem);
    if(strcmp(jogador->deck->inicio->card->origem->tipo,"Monster") == 0 || strcmp(jogador->deck->inicio->card->origem->tipo,"Jr. Boss") == 0 || strcmp(jogador->deck->inicio->card->origem->tipo,"Boss") == 0) {
        DrawCard(id_acao,buffer,fim,rolagem,sbox,prompt,selecao,roll_bar,fundo_carta,fundo_menu,deck_meio,deck_cheio,pont,jogador,adversario,display,fundo,font,font2,color,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);
    }
}

#include "funcoes_slot.c"

void DestroyField(struct Player *jogador,struct Player *adversario) {  //Field do jogador eh destruido.
    struct Deck *aux1;

    aux1 = (struct Deck *)malloc(sizeof(struct Deck));
    aux1->card = jogador->mesa->field;
    DestroyCard(aux1,jogador,adversario);

    jogador->mesa->field = NULL;
}

bool RapidActionX(int id_acao,struct Card **buffer,bool *fim,int *rolagem,struct StatusBox_bitmaps *sbox,struct CARD *card_fixo,struct Player *jogador,struct Player *adversario,int level,ALLEGRO_DISPLAY *display,ALLEGRO_BITMAP *prompt,ALLEGRO_BITMAP *selecao,ALLEGRO_BITMAP *roll_bar,ALLEGRO_BITMAP *apontador,ALLEGRO_BITMAP *fundo_carta,ALLEGRO_BITMAP *fundo_menu,ALLEGRO_BITMAP *deck_meio,ALLEGRO_BITMAP *deck_cheio,ALLEGRO_BITMAP *fundo,ALLEGRO_FONT *font,ALLEGRO_FONT *font2,ALLEGRO_COLOR color,bool *sair,int *posX,int *posY,int *dltZ,bool *mouse,bool *mouse2,bool *mouse_lado,int *keychar,bool *repete_keychar,ALLEGRO_EVENT_QUEUE *event_queue,ALLEGRO_TIMER *keyb_press_timer,ALLEGRO_TIMER *mouse_press_timer) {   //INCOMPLETO, valendo p/ tactic, equip, field TAMBEM
    struct Deck *aux,*aux1;
    bool ativo = false;
    struct Coordenadas *lista,*aux3,*aux4;

    lista = (struct Coordenadas *)malloc(sizeof(struct Coordenadas));
    lista->prox = NULL;

    if(card_fixo == NULL) {
        AtualizaMesa(false,NULL,id_acao,6,level,buffer,fim,sbox,prompt,selecao,roll_bar,fundo_carta,fundo_menu,deck_meio,deck_cheio,fundo,apontador,jogador,adversario,display,font,font2,color,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer,rolagem,lista,-1,-1,0,-1,NULL,NULL);
        if(lista->prox == NULL) return(false);
    }
    else {
        lista->x = card_fixo->PosicaoX;
        lista->y = card_fixo->PosicaoY;
        lista->prox = (struct Coordenadas *)malloc(sizeof(struct Coordenadas));
        lista->prox->prox = NULL;
    }

    while(1) {
        AtualizaMesa(true,"Play a rapid action... (right click to skip)",id_acao,-1,level,buffer,fim,sbox,prompt,selecao,roll_bar,fundo_carta,fundo_menu,deck_meio,deck_cheio,fundo,apontador,jogador,adversario,display,font,font2,color,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer,rolagem,lista,-1,-1,0,-1,NULL,NULL);
        if(*fim == true) return(false);

        if(*mouse2 == true && card_fixo == NULL) break;
        else if(*mouse == true) {
            if(AvaliaCoordenadas(posX,posY,jogador,lista,jogador->hand->inicio)) {
                aux = jogador->hand->inicio;
                aux1 = NULL;
                while(1){
                    if(aux->card->PosicaoX == *posX && aux->card->PosicaoY == *posY) break;
                    aux1 = aux;
                    aux = aux->prox;
                }
                if(aux->card->origem->tactic == NULL) {
                    aux3 = lista;
                    while(aux3->prox != NULL) {
                        aux4 = aux3;
                        aux3 = aux3->prox;
                        free(aux4);
                    }
                    free(aux3);

                    return(false);
                }

                if(aux1 == NULL) jogador->hand->inicio = aux->prox;
                else aux1->prox = aux->prox;
                jogador->hand->quantidade--;

                printf("Tatica usada: %s\n",aux->card->origem->nome);
                PlayTactic(id_acao,aux,buffer,fim,rolagem,sbox,jogador,adversario,display,prompt,selecao,roll_bar,apontador,fundo_carta,fundo_menu,deck_meio,deck_cheio,fundo,font,font2,color,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);

                ativo = true;
                break;
            }
        }
    }

    aux3 = lista;
    while(aux3->prox != NULL) {
        aux4 = aux3;
        aux3 = aux3->prox;
        free(aux4);
    }
    free(aux3);

    return(ativo);
}

void WearEquipment(struct Deck *aux,struct Card **buffer,bool *fim,int *rolagem,int id_acao,struct StatusBox_bitmaps *sbox,struct Player *jogador,struct Player *adversario,ALLEGRO_DISPLAY *display,ALLEGRO_BITMAP *prompt,ALLEGRO_BITMAP *selecao,ALLEGRO_BITMAP *roll_bar,ALLEGRO_BITMAP *apontador,ALLEGRO_BITMAP *fundo_carta,ALLEGRO_BITMAP *fundo_menu,ALLEGRO_BITMAP *deck_meio,ALLEGRO_BITMAP *deck_cheio,ALLEGRO_BITMAP *fundo,ALLEGRO_FONT *font,ALLEGRO_FONT *font2,ALLEGRO_COLOR color,bool *sair,int *posX,int *posY,int *dltZ,bool *mouse,bool *mouse2,bool *mouse_lado,int *keychar,bool *repete_keychar,ALLEGRO_EVENT_QUEUE *event_queue,ALLEGRO_TIMER *keyb_press_timer,ALLEGRO_TIMER *mouse_press_timer) {
    if(aux->card->origem->colecao == DUNGEON_MAP) DesfazAmbosFieldBuffs(jogador,adversario);

    if(jogador->mesa->equip1 == NULL) jogador->mesa->equip1 = aux->card;
    else if(jogador->mesa->equip2 == NULL) jogador->mesa->equip2 = aux->card;
    else if(jogador->mesa->equip3 == NULL) jogador->mesa->equip3 = aux->card;
    else if(jogador->mesa->equip4 == NULL) jogador->mesa->equip4 = aux->card;
    else if(jogador->mesa->equip5 == NULL) jogador->mesa->equip5 = aux->card;
    else if(jogador->mesa->equip6 == NULL) jogador->mesa->equip6 = aux->card;
    else jogador->mesa->equip7 = aux->card;

    EquipItem(aux,id_acao,buffer,fim,jogador->mesa->equip1,sbox,selecao,roll_bar,fundo_menu,fundo_carta,deck_meio,deck_cheio,apontador,jogador,adversario,display,fundo,prompt,font,font2,color,rolagem,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);
    EquipItem(aux,id_acao,buffer,fim,jogador->mesa->equip2,sbox,selecao,roll_bar,fundo_menu,fundo_carta,deck_meio,deck_cheio,apontador,jogador,adversario,display,fundo,prompt,font,font2,color,rolagem,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);
    EquipItem(aux,id_acao,buffer,fim,jogador->mesa->equip3,sbox,selecao,roll_bar,fundo_menu,fundo_carta,deck_meio,deck_cheio,apontador,jogador,adversario,display,fundo,prompt,font,font2,color,rolagem,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);
    EquipItem(aux,id_acao,buffer,fim,jogador->mesa->equip4,sbox,selecao,roll_bar,fundo_menu,fundo_carta,deck_meio,deck_cheio,apontador,jogador,adversario,display,fundo,prompt,font,font2,color,rolagem,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);
    EquipItem(aux,id_acao,buffer,fim,jogador->mesa->equip5,sbox,selecao,roll_bar,fundo_menu,fundo_carta,deck_meio,deck_cheio,apontador,jogador,adversario,display,fundo,prompt,font,font2,color,rolagem,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);
    EquipItem(aux,id_acao,buffer,fim,jogador->mesa->equip6,sbox,selecao,roll_bar,fundo_menu,fundo_carta,deck_meio,deck_cheio,apontador,jogador,adversario,display,fundo,prompt,font,font2,color,rolagem,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);
    EquipItem(aux,id_acao,buffer,fim,jogador->mesa->equip7,sbox,selecao,roll_bar,fundo_menu,fundo_carta,deck_meio,deck_cheio,apontador,jogador,adversario,display,fundo,prompt,font,font2,color,rolagem,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);

    /*::: PONTO DE FUNCAO #10 ::: */
    if(bazaar_seller_funct(id_acao,buffer,fim,jogador->mesa->monstro1,aux->card,rolagem,sbox,prompt,selecao,roll_bar,fundo_carta,deck_meio,deck_cheio,apontador,jogador,adversario,display,fundo_menu,fundo,font,font2,color,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer));
    else if(bazaar_seller_funct(id_acao,buffer,fim,jogador->mesa->monstro2,aux->card,rolagem,sbox,prompt,selecao,roll_bar,fundo_carta,deck_meio,deck_cheio,apontador,jogador,adversario,display,fundo_menu,fundo,font,font2,color,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer));
    else if(bazaar_seller_funct(id_acao,buffer,fim,jogador->mesa->monstro3,aux->card,rolagem,sbox,prompt,selecao,roll_bar,fundo_carta,deck_meio,deck_cheio,apontador,jogador,adversario,display,fundo_menu,fundo,font,font2,color,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer));
    else if(bazaar_seller_funct(id_acao,buffer,fim,jogador->mesa->monstro4,aux->card,rolagem,sbox,prompt,selecao,roll_bar,fundo_carta,deck_meio,deck_cheio,apontador,jogador,adversario,display,fundo_menu,fundo,font,font2,color,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer));
    else if(bazaar_seller_funct(id_acao,buffer,fim,jogador->mesa->monstro5,aux->card,rolagem,sbox,prompt,selecao,roll_bar,fundo_carta,deck_meio,deck_cheio,apontador,jogador,adversario,display,fundo_menu,fundo,font,font2,color,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer));
    else if(bazaar_seller_funct(id_acao,buffer,fim,jogador->mesa->monstro6,aux->card,rolagem,sbox,prompt,selecao,roll_bar,fundo_carta,deck_meio,deck_cheio,apontador,jogador,adversario,display,fundo_menu,fundo,font,font2,color,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer));
    else bazaar_seller_funct(id_acao,buffer,fim,jogador->mesa->monstro7,aux->card,rolagem,sbox,prompt,selecao,roll_bar,fundo_carta,deck_meio,deck_cheio,apontador,jogador,adversario,display,fundo_menu,fundo,font,font2,color,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);

        //----    LISTA DE EFEITOS-ATIVACOES DE EQUIPS -----------------
    if(aux->card->origem->colecao == GORON_TUNIC) goron_tunic_acao2(jogador);
    else if(aux->card->origem->colecao == GORON_RUBY) goron_ruby_acao(jogador,adversario); //aplica mudanças de stats ASAP!
    else if(aux->card->origem->colecao == GORON_BRACELET) goron_bracelet_acao(id_acao + 1,fim,jogador,display,prompt,selecao,roll_bar,fundo_carta,fundo_menu,fundo,font,font2,color,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);
    else if(aux->card->origem->colecao == MASTER_SWORD) aux->card->var_equip->master_sword_cont = 2;
    else if(aux->card->origem->colecao == FAIRY_SLINGSHOT) aux->card->var_equip->fairy_slingshot_cont = 1;
    else if(aux->card->origem->colecao == SKULL_MASK) aux->card->var_equip->skull_mask_cont = 1;
    else if(aux->card->origem->colecao == BOOMERANG) aux->card->var_equip->boomerang_cont = 1;
    else if(aux->card->origem->colecao == SILVER_GAUNTLETS) aux->card->var_equip->silver_gauntlets_cont = 1;
    else if(aux->card->origem->colecao == GOLDEN_GAUNTLETS) aux->card->var_equip->golden_gauntlets_cont = 1;
    else if(aux->card->origem->colecao == ZORAS_SAPPHIRE) zoras_sapphire_acao(jogador,adversario);
    else if(aux->card->origem->colecao == COMPASS) aux->card->var_equip->compass_bool = true;
    else if(aux->card->origem->colecao == OCARINA_OF_TIME) aux->card->var_equip->ocarina_of_time_bool = true;
    else if(aux->card->origem->colecao == HOVER_BOOTS) jogador->prevent_any_damage += 1;
    else if(aux->card->origem->colecao == EPONA) jogador->prevent_damage += 1;
    else if(aux->card->origem->colecao == CLAIM_CHECK) aux->card->var_equip->claim_check_bool = true;
    else if(aux->card->origem->colecao == BIGGER_BOMB_BAG) {
        aux->card->var_equip->bigger_bomb_bag_bool = true;
        aux->card->var_equip->bigger_bomb_bag_overriding_bool = false;

        bigger_bomb_bag_override_effect_slot(aux->card,jogador);
    }
    else if(aux->card->origem->colecao == BOMB) {
        aux->card->var_equip->bomb_cont = 1;
        aux->card->var_equip->bomb_dmg = 10;

        bigger_bomb_bag_played_bomb(aux->card,jogador);
    }

    aux->card->var_equip->mirror_shield_cont = 0;
    aux->card->var_equip->mirror_shield_dmg = 0;

        //--------------------------------------------------------------
    aux->card->var_equip->magic_beans_bool = false;
    compass_acao(aux->card,id_acao,buffer,fim,sbox,prompt,selecao,roll_bar,fundo_carta,fundo_menu,deck_meio,deck_cheio,apontador,jogador,adversario,display,fundo,font,font2,color,rolagem,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);

    if(aux->card->origem->colecao == DUNGEON_MAP) RefazAmbosFieldBuffs(jogador,adversario);

    jogador->equips_played += 1;
    AtualizaMesa(true,NULL,id_acao,-1,0,buffer,fim,sbox,prompt,selecao,roll_bar,fundo_carta,fundo_menu,deck_meio,deck_cheio,fundo,apontador,jogador,adversario,display,font,font2,color,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer,rolagem,NULL,-1,-1,0,-1,NULL,NULL);

    play_card_effects(id_acao,buffer,fim,rolagem,sbox,jogador,adversario,display,prompt,selecao,roll_bar,fundo_carta,fundo_menu,deck_meio,deck_cheio,fundo,font,font2,color,apontador,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);
}

bool EquipX(struct Card **buffer,bool *fim,int *rolagem,int metodo,int id_acao,struct StatusBox_bitmaps *sbox,struct Player *jogador,struct Player *adversario,int level,ALLEGRO_DISPLAY *display,ALLEGRO_BITMAP *prompt,ALLEGRO_BITMAP *selecao,ALLEGRO_BITMAP *roll_bar,ALLEGRO_BITMAP *apontador,ALLEGRO_BITMAP *fundo_carta,ALLEGRO_BITMAP *fundo_menu,ALLEGRO_BITMAP *deck_meio,ALLEGRO_BITMAP *deck_cheio,ALLEGRO_BITMAP *fundo,ALLEGRO_FONT *font,ALLEGRO_FONT *font2,ALLEGRO_COLOR color,bool *sair,int *posX,int *posY,int *dltZ,bool *mouse,bool *mouse2,bool *mouse_lado,int *keychar,bool *repete_keychar,ALLEGRO_EVENT_QUEUE *event_queue,ALLEGRO_TIMER *keyb_press_timer,ALLEGRO_TIMER *mouse_press_timer) {   //INCOMPLETO, valendo p/ tactic, equip, field TAMBEM
    struct Deck *aux,*aux1;
    bool opcao,ativo = false;
    struct Coordenadas *lista,*aux3,*aux4;

    printf("EQUIP...\n");
    opcao = true;
    if(!Possui_eqpslot(jogador)) {
        opcao = false;
    }

    if(opcao == true) {
        lista = (struct Coordenadas *)malloc(sizeof(struct Coordenadas));
        lista->prox = NULL;

        if(metodo == 1) AtualizaMesa(false,NULL,id_acao,9,level,buffer,fim,sbox,prompt,selecao,roll_bar,fundo_carta,fundo_menu,deck_meio,deck_cheio,fundo,apontador,jogador,adversario,display,font,font2,color,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer,rolagem,lista,-1,-1,0,-1,NULL,NULL);
        else AtualizaMesa(false,NULL,id_acao,4,level,buffer,fim,sbox,prompt,selecao,roll_bar,fundo_carta,fundo_menu,deck_meio,deck_cheio,fundo,apontador,jogador,adversario,display,font,font2,color,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer,rolagem,lista,-1,-1,0,-1,NULL,NULL);

        if(lista->prox == NULL) return(false);
        while(1) {
            AtualizaMesa(true,"Wear an equipment (right click to skip)",id_acao,-1,0,buffer,fim,sbox,prompt,selecao,roll_bar,fundo_carta,fundo_menu,deck_meio,deck_cheio,fundo,apontador,jogador,adversario,display,font,font2,color,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer,rolagem,lista,-1,-1,0,-1,NULL,NULL);
            if(*fim == true) return(false);

            if(*mouse2 == true) break;
            else if(*mouse == true) {
                if(AvaliaCoordenadas(posX,posY,jogador,lista,jogador->hand->inicio)) {
                    aux = jogador->hand->inicio;
                    aux1 = NULL;

                    while(1){
                        if(aux->card->PosicaoX == *posX && aux->card->PosicaoY == *posY) break;
                        aux1 = aux;
                        aux = aux->prox;
                    }

                    if(aux->card->origem->equip == NULL) {
                        aux3 = lista;
                        while(aux3->prox != NULL) {
                            aux4 = aux3;
                            aux3 = aux3->prox;
                            free(aux4);
                        }
                        free(aux3);

                        return(false);
                    }

                    if(aux1 == NULL) jogador->hand->inicio = aux->prox;
                    else aux1->prox = aux->prox;
                    jogador->hand->quantidade--;

                    WearEquipment(aux,buffer,fim,rolagem,id_acao,sbox,jogador,adversario,display,prompt,selecao,roll_bar,apontador,fundo_carta,fundo_menu,deck_meio,deck_cheio,fundo,font,font2,color,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);
                    free(aux);
                    ativo = true;
                    break;
                }
            }
        }

        aux3 = lista;
        while(aux3->prox != NULL) {
            aux4 = aux3;
            aux3 = aux3->prox;
            free(aux4);
        }
        free(aux3);
    }

    return(ativo);
}

bool LocateX(bool locked,int id_acao,struct Card **buffer,bool *fim,int *rolagem,struct StatusBox_bitmaps *sbox,struct Player *jogador,struct Player *adversario,ALLEGRO_DISPLAY *display,ALLEGRO_BITMAP *prompt,ALLEGRO_BITMAP *selecao,ALLEGRO_BITMAP *roll_bar,ALLEGRO_BITMAP *apontador,ALLEGRO_BITMAP *fundo_carta,ALLEGRO_BITMAP *fundo_menu,ALLEGRO_BITMAP *deck_meio,ALLEGRO_BITMAP *deck_cheio,ALLEGRO_BITMAP *fundo,ALLEGRO_FONT *font,ALLEGRO_FONT *font2,ALLEGRO_COLOR color,bool *sair,int *posX,int *posY,int *dltZ,bool *mouse,bool *mouse2,bool *mouse_lado,int *keychar,bool *repete_keychar,ALLEGRO_EVENT_QUEUE *event_queue,ALLEGRO_TIMER *keyb_press_timer,ALLEGRO_TIMER *mouse_press_timer) {
    struct Deck *aux,*aux1;
    bool opcao,ativo = false;
    struct Coordenadas *lista,*aux3,*aux4;

    printf("LOCATE... ");
    opcao = true;

    if(opcao == true) {
        lista = (struct Coordenadas *)malloc(sizeof(struct Coordenadas));
        lista->prox = NULL;

        if(locked == false) AtualizaMesa(false,"Enter a field (right click to skip)",id_acao,5,0,buffer,fim,sbox,prompt,selecao,roll_bar,fundo_carta,fundo_menu,deck_meio,deck_cheio,fundo,apontador,jogador,adversario,display,font,font2,color,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer,rolagem,lista,-1,-1,0,-1,NULL,NULL);
        else AtualizaMesa(false,"Enter a field (right click to skip)",id_acao,12,0,buffer,fim,sbox,prompt,selecao,roll_bar,fundo_carta,fundo_menu,deck_meio,deck_cheio,fundo,apontador,jogador,adversario,display,font,font2,color,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer,rolagem,lista,-1,-1,0,-1,NULL,NULL);
        if(lista->prox == NULL) return(false);

        printf("1 ");
        while(1) {
            AtualizaMesa(true,"Enter a field (right click to skip)",id_acao,-1,0,buffer,fim,sbox,prompt,selecao,roll_bar,fundo_carta,fundo_menu,deck_meio,deck_cheio,fundo,apontador,jogador,adversario,display,font,font2,color,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer,rolagem,lista,-1,-1,0,-1,NULL,NULL);
            if(*fim == true) return(false);

            if(*mouse2 == true) break;
            if(*mouse == true) {
                if(AvaliaCoordenadas(posX,posY,jogador,lista,jogador->hand->inicio)) {
                    aux = jogador->hand->inicio;
                    aux1 = NULL;
                    while(1){
                        if(aux->card->PosicaoX == *posX && aux->card->PosicaoY == *posY) break;
                        aux1 = aux;
                        aux = aux->prox;
                    }

                    if(aux->card->origem->field == NULL) {
                        aux3 = lista;
                        while(aux3->prox != NULL) {
                            aux4 = aux3;
                            aux3 = aux3->prox;
                            free(aux4);
                        }
                        free(aux3);

                        return(false);
                    }

                    if(aux1 == NULL) jogador->hand->inicio = aux->prox;
                    else aux1->prox = aux->prox;
                    jogador->hand->quantidade--;
                    printf("2 ");

                    DesfazAmbosFieldBuffs(jogador,adversario);
                    if(jogador->mesa->field != NULL) {
                        if(!(adversario->mesa->field != NULL && !strcmp(adversario->mesa->field->origem->elemento,"Water")) && !strcmp(jogador->mesa->field->origem->elemento,"Water")) DesfazBlueTektiteBuff(jogador,adversario);
                        DestroyField(jogador,adversario);
                    }
                    jogador->mesa->field = aux->card;
                    RefazAmbosFieldBuffs(jogador,adversario);

                    printf("3 ");

                    if(!(adversario->mesa->field != NULL && !strcmp(adversario->mesa->field->origem->elemento,"Water")) && !strcmp(jogador->mesa->field->origem->elemento,"Water")) AtivaBlueTektiteBuff(jogador,adversario);

                    RecuperaZeroHP(fim,jogador);
                    RecuperaZeroHP(fim,adversario);

                    //AINDA PRECISA COBRIR CASOS DE FINALIZAR BUFFS DE FIELDS.
                    //APLICAR FIELDS
                    if(jogador->mesa->field->origem->colecao == KOKIRI_FOREST || jogador->mesa->field->origem->colecao == DEATH_MT_CRATER || jogador->mesa->field->origem->colecao == LAKE_HYLIA || jogador->mesa->field->origem->colecao == GERUDO_FORTRESS || jogador->mesa->field->origem->colecao == GANONS_CASTLE /* || outros fields*/) {
                        RefreshHP(id_acao,buffer,jogador->mesa->character,50,fim,rolagem,sbox,prompt,selecao,roll_bar,fundo_carta,fundo_menu,deck_meio,deck_cheio,apontador,jogador,adversario,display,fundo,font,font2,color,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);
                    }

                    compass_acao(aux->card,id_acao,buffer,fim,sbox,prompt,selecao,roll_bar,fundo_carta,fundo_menu,deck_meio,deck_cheio,apontador,jogador,adversario,display,fundo,font,font2,color,rolagem,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);

                    AtualizaMesa(true,NULL,id_acao,-1,0,buffer,fim,sbox,prompt,selecao,roll_bar,fundo_carta,fundo_menu,deck_meio,deck_cheio,fundo,apontador,jogador,adversario,display,font,font2,color,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer,rolagem,NULL,-1,-1,0,-1,NULL,NULL);
                    ativo = true;

                    play_card_effects(id_acao,buffer,fim,rolagem,sbox,jogador,adversario,display,prompt,selecao,roll_bar,fundo_carta,fundo_menu,deck_meio,deck_cheio,fundo,font,font2,color,apontador,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);
                    printf("4 ");
                    break;
                }
            }
        }

        aux3 = lista;
        while(aux3->prox != NULL) {
            aux4 = aux3;
            aux3 = aux3->prox;
            free(aux4);
        }
        free(aux3);

        printf("OK!\n");
    }

    return(ativo);
}

void SlotMonsterTurn(int id_acao,struct Card **buffer,struct CARD *card,bool *fim_de_jogo,int *rolagem,bool *ko,struct StatusBox_bitmaps *sbox,struct Player *jogador,struct Player *adversario,ALLEGRO_DISPLAY *display,ALLEGRO_BITMAP *selecao,ALLEGRO_BITMAP *roll_bar,ALLEGRO_BITMAP *fundo_carta,ALLEGRO_BITMAP *fundo_menu,ALLEGRO_BITMAP *deck_meio,ALLEGRO_BITMAP *deck_cheio,ALLEGRO_BITMAP *fundo,ALLEGRO_BITMAP *prompt,ALLEGRO_FONT *font,ALLEGRO_FONT *font2,ALLEGRO_COLOR color,ALLEGRO_BITMAP *apontador,bool *sair,int *posX,int *posY,int *dltZ,bool *mouse,bool *mouse2,bool *mouse_lado,int *keychar,bool *repete_keychar,ALLEGRO_EVENT_QUEUE *event_queue,ALLEGRO_TIMER *keyb_press_timer,ALLEGRO_TIMER *mouse_press_timer) {
    if(*fim_de_jogo == true) return;
    if(Attack(id_acao,true,false,buffer,fim_de_jogo,rolagem,ko,0,0,0,sbox,jogador,adversario,card,card->attack,display,prompt,selecao,roll_bar,fundo_carta,fundo_menu,deck_meio,deck_cheio,fundo,font,font2,color,apontador,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer)) card->var_monster->qte_ataques++;
    //else al_rest(0.15);
}

void SpawnEquipBuff(struct CARD *slot,struct Player *jogador,struct Player *adversario) {
    //modo: 0 -> adv; 1 -> jogador

    EquipSummonBuffs(true,jogador->mesa->equip1,slot);
    EquipSummonBuffs(true,jogador->mesa->equip2,slot);
    EquipSummonBuffs(true,jogador->mesa->equip3,slot);
    EquipSummonBuffs(true,jogador->mesa->equip4,slot);
    EquipSummonBuffs(true,jogador->mesa->equip5,slot);
    EquipSummonBuffs(true,jogador->mesa->equip6,slot);
    EquipSummonBuffs(true,jogador->mesa->equip7,slot);

    EquipSummonBuffs(false,adversario->mesa->equip1,slot);
    EquipSummonBuffs(false,adversario->mesa->equip2,slot);
    EquipSummonBuffs(false,adversario->mesa->equip3,slot);
    EquipSummonBuffs(false,adversario->mesa->equip4,slot);
    EquipSummonBuffs(false,adversario->mesa->equip5,slot);
    EquipSummonBuffs(false,adversario->mesa->equip6,slot);
    EquipSummonBuffs(false,adversario->mesa->equip7,slot);
}

void AplicaSpawnEffects(int id_acao,struct Card **buffer,bool *fim_de_jogo,int *rolagem,struct StatusBox_bitmaps *sbox,struct Player *jogador,struct Player *adversario,ALLEGRO_DISPLAY *display,ALLEGRO_BITMAP *prompt,ALLEGRO_BITMAP *selecao,ALLEGRO_BITMAP *roll_bar,ALLEGRO_BITMAP *apontador,ALLEGRO_BITMAP *fundo_carta,ALLEGRO_BITMAP *fundo_menu,ALLEGRO_BITMAP *deck_meio,ALLEGRO_BITMAP *deck_cheio,ALLEGRO_BITMAP *fundo,ALLEGRO_FONT *font,ALLEGRO_FONT *font2,ALLEGRO_COLOR color,bool *sair,int *posX,int *posY,int *dltZ,bool *mouse,bool *mouse2,bool *mouse_lado,int *keychar,bool *repete_keychar,ALLEGRO_EVENT_QUEUE *event_queue,ALLEGRO_TIMER *keyb_press_timer,ALLEGRO_TIMER *mouse_press_timer) {
    struct Deck *aux,*aux1;
    bool toggle = true,ko;
    struct CARD *slot = NULL;

    printf("aplicando SPAWN effects ");
    aux = jogador->hand->inicio;
    aux1 = NULL;

    while(1){
        if(aux->card->PosicaoX == *posX && aux->card->PosicaoY == *posY) break;
        aux1 = aux;
        aux = aux->prox;
    }
    if(!ehMonstro(aux->card)) return;

    printf("Summon: %s ",aux->card->origem->nome);

    if(aux1 == NULL) jogador->hand->inicio = aux->prox;
    else aux1->prox = aux->prox;
    jogador->hand->quantidade--;

    RecuperaStatsBasicos(aux->card);
    aux->card->var_monster->damage_multiplier = 100;
    aux->card->var_monster->white_wolfos_dmg_cont = 0;

    printf("5 ");
    BombchuEffect(&toggle,jogador,adversario,&(adversario->mesa->equip1),aux);
    if(toggle == true) BombchuEffect(&toggle,jogador,adversario,&(adversario->mesa->equip2),aux);
    if(toggle == true) BombchuEffect(&toggle,jogador,adversario,&(adversario->mesa->equip3),aux);
    if(toggle == true) BombchuEffect(&toggle,jogador,adversario,&(adversario->mesa->equip4),aux);
    if(toggle == true) BombchuEffect(&toggle,jogador,adversario,&(adversario->mesa->equip5),aux);
    if(toggle == true) BombchuEffect(&toggle,jogador,adversario,&(adversario->mesa->equip6),aux);
    if(toggle == true) BombchuEffect(&toggle,jogador,adversario,&(adversario->mesa->equip7),aux);

    printf("6 ");
    if(toggle == true) {
        if(IncluiEmCampo(&(jogador->mesa->monstro1),aux->card,jogador->level,jogador->mesa->field,adversario->mesa->field,jogador,adversario)) slot = jogador->mesa->monstro1;
        else if(IncluiEmCampo(&(jogador->mesa->monstro2),aux->card,jogador->level,jogador->mesa->field,adversario->mesa->field,jogador,adversario)) slot = jogador->mesa->monstro2;
        else if(IncluiEmCampo(&(jogador->mesa->monstro3),aux->card,jogador->level,jogador->mesa->field,adversario->mesa->field,jogador,adversario)) slot = jogador->mesa->monstro3;
        else if(IncluiEmCampo(&(jogador->mesa->monstro4),aux->card,jogador->level,jogador->mesa->field,adversario->mesa->field,jogador,adversario)) slot = jogador->mesa->monstro4;
        else if(IncluiEmCampo(&(jogador->mesa->monstro5),aux->card,jogador->level,jogador->mesa->field,adversario->mesa->field,jogador,adversario)) slot = jogador->mesa->monstro5;
        else if(IncluiEmCampo(&(jogador->mesa->monstro6),aux->card,jogador->level,jogador->mesa->field,adversario->mesa->field,jogador,adversario)) slot = jogador->mesa->monstro6;
        else if(IncluiEmCampo(&(jogador->mesa->monstro7),aux->card,jogador->level,jogador->mesa->field,adversario->mesa->field,jogador,adversario)) slot = jogador->mesa->monstro7;
        else {
            printf("ERRO: ALOCACAO INDEVIDA!\n");
            return;
        }
        printf("8 ");
        if(jogador->global_silence == true && slot->turn_silenced == 0) slot->turn_silenced += 1;

        EfetuaBuff_slot(slot);

        slot->var_monster->qte_ataques = 0;
        EsvaziaListaQuantidadeAtaques(&(slot->var_monster->lista_qte_ataques));
        AdicionaNovaQuantidadeAtaque(&(slot->var_monster->lista_qte_ataques),NULL,1);

        slot->var_monster->baby_dodongo_bool = false;
        slot->var_monster->dead_hand_bool = false;

        /*::: PONTO DE FUNCAO #12 ::: */
        if(strstr(slot->origem->str_concat,"Spider") != NULL && cvEmcampo(jogador)) cursed_villager_acao(fim_de_jogo,jogador,adversario);

        cucco_lady_acao(slot->origem,id_acao,buffer,fim_de_jogo,rolagem,sbox,prompt,selecao,roll_bar,fundo_carta,fundo_menu,deck_meio,deck_cheio,apontador,jogador,adversario,display,fundo,font,font2,color,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);

        if((jogador->var_tactic->spirit_medallion_cont > 0) && !strcmp(slot->origem->elemento,"Wind")) {
            slot->MaxHP += (20 * jogador->var_tactic->spirit_medallion_cont);
            slot->HP += (20 * jogador->var_tactic->spirit_medallion_cont);
        }
        if((adversario->var_tactic->spirit_medallion_cont > 0) && !strcmp(slot->origem->elemento,"Wind")) {
            slot->MaxHP += (20 * jogador->var_tactic->spirit_medallion_cont);
            slot->HP += (20 * jogador->var_tactic->spirit_medallion_cont);
        }

        SpawnEquipBuff(slot,jogador,adversario);

        if(slot->origem->colecao != DEAD_HAND) dead_hand_acao(slot,jogador); //Se monstro nao eh o DH, efeito unico. Se DH, efeito eh para todos os monstros do jogador.
        else dead_hand_effect(jogador);

        if(slot->origem->colecao != GIANT_LEEVER) giant_leever_acao(slot,jogador);
        else giant_leever_effect(jogador);

        ganondorf_acao(slot,jogador);

        printf("8.1 ");
        if(slot->origem->colecao == TWINROVA) slot->var_monster->twinrova_cont = 0;
        else if(slot->origem->colecao == LIZALFOS) slot->var_monster->lizalfos_cont = 0;
        else if(slot->origem->colecao == DEAD_HAND) slot->var_monster->dead_hand_cont = 2;
        else if(slot->origem->colecao == GUAY && slot->turn_silenced == 0) Attack(id_acao,true,true,buffer,fim_de_jogo,rolagem,&ko,0,0,0,sbox,jogador,adversario,slot,20,display,prompt,selecao,roll_bar,fundo_carta,fundo_menu,deck_meio,deck_cheio,fundo,font,font2,color,apontador,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);
        else if(slot->origem->colecao == TAILPASARAN && slot->turn_silenced == 0) Attack(id_acao,true,true,buffer,fim_de_jogo,rolagem,&ko,0,0,0,sbox,jogador,adversario,slot,20,display,prompt,selecao,roll_bar,fundo_carta,fundo_menu,deck_meio,deck_cheio,fundo,font,font2,color,apontador,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);
        else if(slot->origem->colecao == STINGER && slot->turn_silenced == 0) Attack(id_acao,true,true,buffer,fim_de_jogo,rolagem,&ko,0,0,0,sbox,jogador,adversario,slot,20,display,prompt,selecao,roll_bar,fundo_carta,fundo_menu,deck_meio,deck_cheio,fundo,font,font2,color,apontador,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);
        else if(slot->origem->colecao == PEAHAT && slot->turn_silenced == 0) Attack(id_acao,true,true,buffer,fim_de_jogo,rolagem,&ko,0,0,0,sbox,jogador,adversario,slot,30,display,prompt,selecao,roll_bar,fundo_carta,fundo_menu,deck_meio,deck_cheio,fundo,font,font2,color,apontador,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);
        else if(slot->origem->colecao == REDEAD && slot->turn_silenced == 0) redead_acao(slot,id_acao,buffer,fim_de_jogo,rolagem,sbox,jogador,adversario,display,prompt,selecao,roll_bar,apontador,fundo_carta,fundo_menu,deck_meio,deck_cheio,fundo,font,font2,color,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);
        else if(slot->origem->colecao == FREEZARD && slot->turn_silenced == 0) freezard_acao(id_acao,buffer,rolagem,sbox,selecao,roll_bar,prompt,fim_de_jogo,fundo_carta,fundo_menu,deck_meio,deck_cheio,jogador,adversario,display,fundo,font,font2,color,apontador,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);

        else if((jogador->mesa->field != NULL && !strcmp(jogador->mesa->field->origem->elemento,"Water")) || (adversario->mesa->field != NULL && !strcmp(adversario->mesa->field->origem->elemento,"Water"))) AtivaBlueTektiteBuffSlot(slot);

        compass_acao(slot,id_acao,buffer,fim_de_jogo,sbox,prompt,selecao,roll_bar,fundo_carta,fundo_menu,deck_meio,deck_cheio,apontador,jogador,adversario,display,fundo,font,font2,color,rolagem,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);

        printf("9 ");
        free(aux);
    }

    printf("7 ");
    if(slot != NULL) {
        EquipSummonEffects(id_acao,jogador->mesa->equip1,slot,buffer,fim_de_jogo,rolagem,sbox,prompt,selecao,roll_bar,apontador,fundo_carta,fundo_menu,deck_meio,deck_cheio,jogador,adversario,display,fundo,font,font2,color,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);
        EquipSummonEffects(id_acao,jogador->mesa->equip2,slot,buffer,fim_de_jogo,rolagem,sbox,prompt,selecao,roll_bar,apontador,fundo_carta,fundo_menu,deck_meio,deck_cheio,jogador,adversario,display,fundo,font,font2,color,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);
        EquipSummonEffects(id_acao,jogador->mesa->equip3,slot,buffer,fim_de_jogo,rolagem,sbox,prompt,selecao,roll_bar,apontador,fundo_carta,fundo_menu,deck_meio,deck_cheio,jogador,adversario,display,fundo,font,font2,color,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);
        EquipSummonEffects(id_acao,jogador->mesa->equip4,slot,buffer,fim_de_jogo,rolagem,sbox,prompt,selecao,roll_bar,apontador,fundo_carta,fundo_menu,deck_meio,deck_cheio,jogador,adversario,display,fundo,font,font2,color,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);
        EquipSummonEffects(id_acao,jogador->mesa->equip5,slot,buffer,fim_de_jogo,rolagem,sbox,prompt,selecao,roll_bar,apontador,fundo_carta,fundo_menu,deck_meio,deck_cheio,jogador,adversario,display,fundo,font,font2,color,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);
        EquipSummonEffects(id_acao,jogador->mesa->equip6,slot,buffer,fim_de_jogo,rolagem,sbox,prompt,selecao,roll_bar,apontador,fundo_carta,fundo_menu,deck_meio,deck_cheio,jogador,adversario,display,fundo,font,font2,color,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);
        EquipSummonEffects(id_acao,jogador->mesa->equip7,slot,buffer,fim_de_jogo,rolagem,sbox,prompt,selecao,roll_bar,apontador,fundo_carta,fundo_menu,deck_meio,deck_cheio,jogador,adversario,display,fundo,font,font2,color,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);
    }

    jogador->mobs_played += 1;
    AtualizaMesa(true,NULL,id_acao,-1,jogador->level,buffer,fim_de_jogo,sbox,prompt,selecao,roll_bar,fundo_carta,fundo_menu,deck_meio,deck_cheio,fundo,apontador,jogador,adversario,display,font,font2,color,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer,rolagem,NULL,-1,-1,0,-1,NULL,NULL);

    //----------------------

    play_card_effects(id_acao,buffer,fim_de_jogo,rolagem,sbox,jogador,adversario,display,prompt,selecao,roll_bar,fundo_carta,fundo_menu,deck_meio,deck_cheio,fundo,font,font2,color,apontador,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);
}

void mask_of_truth_acao(struct Card **buffer,bool *fim_de_jogo,struct StatusBox_bitmaps *sbox,ALLEGRO_BITMAP *prompt,ALLEGRO_BITMAP *select_card,ALLEGRO_BITMAP *roll_bar,ALLEGRO_BITMAP *fundo_carta,ALLEGRO_BITMAP *fundo_menu,ALLEGRO_BITMAP *deck_meio,ALLEGRO_BITMAP *deck_cheio,ALLEGRO_BITMAP *pont,struct Player *jogador,struct Player *adversario,ALLEGRO_DISPLAY *display,ALLEGRO_BITMAP *fundo,ALLEGRO_FONT *font,ALLEGRO_FONT *font2,ALLEGRO_COLOR color,bool *sair,int *posX,int *posY,int *dltZ,bool *mouse,bool *mouse2,bool *mouse_lado,int *keychar,bool *repete_keychar,ALLEGRO_EVENT_QUEUE *event_queue,ALLEGRO_TIMER *keyb_press_timer,ALLEGRO_TIMER *mouse_press_timer,int *rolagem) {
    struct Deck *escolhido = NULL,*aux;

    escolhido = MenuCards("MASK OF TRUTH: reveal a card from the opponents hand...",false,adversario->hand->inicio,fim_de_jogo,jogador,display,prompt,select_card,roll_bar,fundo_carta,fundo_menu,fundo,font2,font,color,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);
    if(escolhido != NULL) {
        RevelaCarta("REVEALED CARD...",escolhido->card,-1,buffer,fim_de_jogo,sbox,prompt,select_card,roll_bar,fundo_carta,fundo_menu,deck_meio,deck_cheio,pont,jogador,adversario,display,fundo,font,font2,color,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer,rolagem);

        if(ehMonstro(escolhido->card) && RecuperaCardLevel(escolhido->card->origem) <= jogador->level && Possui_mobslot(jogador)) {
            if(!(EhBoss(escolhido->card) && BossPresente(jogador))) {
                RetiraCardPorCopia(escolhido,&(adversario->hand));
                InsereAtualizaPosicao(jogador,escolhido);

                aux = jogador->hand->inicio;
                while(aux->prox->prox != NULL) aux = aux->prox;
                printf("nome eh '%s', pos %d %d\n",aux->card->origem->nome,aux->card->PosicaoX,aux->card->PosicaoY);
                *posX = aux->card->PosicaoX;
                *posY = aux->card->PosicaoY;
                AplicaSpawnEffects(-1,buffer,fim_de_jogo,rolagem,sbox,jogador,adversario,display,prompt,select_card,roll_bar,pont,fundo_carta,fundo_menu,deck_meio,deck_cheio,fundo,font,font2,color,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);

                DrawCard(-1,buffer,fim_de_jogo,rolagem,sbox,prompt,select_card,roll_bar,fundo_carta,fundo_menu,deck_meio,deck_cheio,pont,adversario,jogador,display,fundo,font,font2,color,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);
            }
        }
    }
}

//depende de ATTACK
bool SpawnX(int id_acao,bool ultimoCard,struct Card **buffer,bool *fim_de_jogo,int *rolagem,struct StatusBox_bitmaps *sbox,struct Player *jogador,struct Player *adversario,int level,ALLEGRO_DISPLAY *display,ALLEGRO_BITMAP *prompt,ALLEGRO_BITMAP *selecao,ALLEGRO_BITMAP *roll_bar,ALLEGRO_BITMAP *apontador,ALLEGRO_BITMAP *fundo_carta,ALLEGRO_BITMAP *fundo_menu,ALLEGRO_BITMAP *deck_meio,ALLEGRO_BITMAP *deck_cheio,ALLEGRO_BITMAP *fundo,ALLEGRO_FONT *font,ALLEGRO_FONT *font2,ALLEGRO_COLOR color,bool *sair,int *posX,int *posY,int *dltZ,bool *mouse,bool *mouse2,bool *mouse_lado,int *keychar,bool *repete_keychar,ALLEGRO_EVENT_QUEUE *event_queue,ALLEGRO_TIMER *keyb_press_timer,ALLEGRO_TIMER *mouse_press_timer) {   //INCOMPLETO, valendo p/ tactic, equip, field TAMBEM
    struct Deck *aux;
    char *mensagem = NULL;
    struct Coordenadas *lista,*aux3,*aux4;
    bool ativo = false;

    printf("SUMMON ");

    if(Possui_mobslot(jogador)) {
        lista = (struct Coordenadas *)malloc(sizeof(struct Coordenadas));
        lista->prox = NULL;

        if(ultimoCard == false) {
            mensagem = (char *)malloc(52*sizeof(char));
            strcpy(mensagem,"Choose a monster to summon... (right click to skip)");
            printf("1 ");
            AtualizaMesa(false,NULL,id_acao,3,level,buffer,fim_de_jogo,sbox,prompt,selecao,roll_bar,fundo_carta,fundo_menu,deck_meio,deck_cheio,fundo,apontador,jogador,adversario,display,font,font2,color,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer,rolagem,lista,-1,-1,0,-1,NULL,NULL);
            printf("2 ");
            if(lista->prox == NULL) {
                free(mensagem);
                free(lista);
                return(false);
            }

            while(1) {
                AtualizaMesa(true,mensagem,id_acao,-1,level,buffer,fim_de_jogo,sbox,prompt,selecao,roll_bar,fundo_carta,fundo_menu,deck_meio,deck_cheio,fundo,apontador,jogador,adversario,display,font,font2,color,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer,rolagem,lista,-1,-1,0,-1,NULL,NULL);
                if(*fim_de_jogo == true || *mouse2 == true) break;

                else if(*mouse == true && AvaliaCoordenadas(posX,posY,jogador,lista,jogador->hand->inicio)) break;
            }

            aux3 = lista;
            while(aux3->prox != NULL) {
                aux4 = aux3;
                aux3 = aux3->prox;
                free(aux4);
            }
            free(aux3);

            free(mensagem);

            if(*fim_de_jogo == true || *mouse2 == true) return(false);
        }
        else {
            printf("1 ");
            AtualizaMesa(false,NULL,id_acao,11,level,buffer,fim_de_jogo,sbox,prompt,selecao,roll_bar,fundo_carta,fundo_menu,deck_meio,deck_cheio,fundo,apontador,jogador,adversario,display,font,font2,color,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer,rolagem,lista,-1,-1,0,-1,NULL,NULL);
            printf("2 ");
            if(lista->prox == NULL) {
                free(lista);
                return(false);
            }

            aux = jogador->hand->inicio;
            while(aux->prox->prox != NULL) aux = aux->prox;

            *posX = aux->card->PosicaoX;
            *posY = aux->card->PosicaoY;

            aux3 = lista;
            while(aux3->prox != NULL) {
                aux4 = aux3;
                aux3 = aux3->prox;
                free(aux4);
            }
            free(aux3);
        }

        AplicaSpawnEffects(id_acao,buffer,fim_de_jogo,rolagem,sbox,jogador,adversario,display,prompt,selecao,roll_bar,apontador,fundo_carta,fundo_menu,deck_meio,deck_cheio,fundo,font,font2,color,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);

        if(adversario->mesa->equip1 != NULL && adversario->mesa->equip1->origem->colecao == MASK_OF_TRUTH) mask_of_truth_acao(buffer,fim_de_jogo,sbox,prompt,selecao,roll_bar,fundo_carta,fundo_menu,deck_meio,deck_cheio,apontador,adversario,jogador,display,fundo,font,font2,color,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer,rolagem);
        if(adversario->mesa->equip2 != NULL && adversario->mesa->equip2->origem->colecao == MASK_OF_TRUTH) mask_of_truth_acao(buffer,fim_de_jogo,sbox,prompt,selecao,roll_bar,fundo_carta,fundo_menu,deck_meio,deck_cheio,apontador,adversario,jogador,display,fundo,font,font2,color,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer,rolagem);
        if(adversario->mesa->equip3 != NULL && adversario->mesa->equip3->origem->colecao == MASK_OF_TRUTH) mask_of_truth_acao(buffer,fim_de_jogo,sbox,prompt,selecao,roll_bar,fundo_carta,fundo_menu,deck_meio,deck_cheio,apontador,adversario,jogador,display,fundo,font,font2,color,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer,rolagem);
        if(adversario->mesa->equip4 != NULL && adversario->mesa->equip4->origem->colecao == MASK_OF_TRUTH) mask_of_truth_acao(buffer,fim_de_jogo,sbox,prompt,selecao,roll_bar,fundo_carta,fundo_menu,deck_meio,deck_cheio,apontador,adversario,jogador,display,fundo,font,font2,color,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer,rolagem);
        if(adversario->mesa->equip5 != NULL && adversario->mesa->equip5->origem->colecao == MASK_OF_TRUTH) mask_of_truth_acao(buffer,fim_de_jogo,sbox,prompt,selecao,roll_bar,fundo_carta,fundo_menu,deck_meio,deck_cheio,apontador,adversario,jogador,display,fundo,font,font2,color,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer,rolagem);
        if(adversario->mesa->equip6 != NULL && adversario->mesa->equip6->origem->colecao == MASK_OF_TRUTH) mask_of_truth_acao(buffer,fim_de_jogo,sbox,prompt,selecao,roll_bar,fundo_carta,fundo_menu,deck_meio,deck_cheio,apontador,adversario,jogador,display,fundo,font,font2,color,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer,rolagem);
        if(adversario->mesa->equip7 != NULL && adversario->mesa->equip7->origem->colecao == MASK_OF_TRUTH) mask_of_truth_acao(buffer,fim_de_jogo,sbox,prompt,selecao,roll_bar,fundo_carta,fundo_menu,deck_meio,deck_cheio,apontador,adversario,jogador,display,fundo,font,font2,color,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer,rolagem);

        ativo = true;
        printf("OK\n");
    }

    return(ativo);
}

void RessucitaMaior50(int id_acao,struct Card **buffer,bool *fim,int *rolagem,ALLEGRO_BITMAP *selecao,ALLEGRO_BITMAP *roll_bar,ALLEGRO_BITMAP *fundo_menu,ALLEGRO_BITMAP *fundo_carta,ALLEGRO_BITMAP *deck_meio,ALLEGRO_BITMAP *deck_cheio,ALLEGRO_BITMAP *pont,ALLEGRO_BITMAP *prompt,struct StatusBox_bitmaps *sbox,struct Player *jogador,struct Player *adversario,ALLEGRO_DISPLAY *display,ALLEGRO_BITMAP *fundo,ALLEGRO_FONT *font,ALLEGRO_FONT *font2,ALLEGRO_COLOR color,bool *sair,int *posX,int *posY,int *dltZ,bool *mouse,bool *mouse2,bool *mouse_lado,int *keychar,bool *repete_keychar,ALLEGRO_EVENT_QUEUE *event_queue,ALLEGRO_TIMER *keyb_press_timer,ALLEGRO_TIMER *mouse_press_timer) {
    if(RecuperaCard(buffer,fim,rolagem,0,true,50,prompt,selecao,roll_bar,fundo_menu,fundo_carta,deck_meio,deck_cheio,pont,jogador,adversario,display,fundo,font,font2,color,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer)) {
        SpawnX(id_acao,true,buffer,fim,rolagem,sbox,jogador,adversario,jogador->level,display,prompt,selecao,roll_bar,pont,fundo_carta,fundo_menu,deck_meio,deck_cheio,fundo,font,font2,color,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);
    }
}

void RessucitaMenor50(int id_acao,struct Card **buffer,bool *fim,int *rolagem,ALLEGRO_BITMAP *selecao,ALLEGRO_BITMAP *roll_bar,ALLEGRO_BITMAP *fundo_menu,ALLEGRO_BITMAP *fundo_carta,ALLEGRO_BITMAP *deck_meio,ALLEGRO_BITMAP *deck_cheio,ALLEGRO_BITMAP *pont,ALLEGRO_BITMAP *prompt,struct StatusBox_bitmaps *sbox,struct Player *jogador,struct Player *adversario,ALLEGRO_DISPLAY *display,ALLEGRO_BITMAP *fundo,ALLEGRO_FONT *font,ALLEGRO_FONT *font2,ALLEGRO_COLOR color,bool *sair,int *posX,int *posY,int *dltZ,bool *mouse,bool *mouse2,bool *mouse_lado,int *keychar,bool *repete_keychar,ALLEGRO_EVENT_QUEUE *event_queue,ALLEGRO_TIMER *keyb_press_timer,ALLEGRO_TIMER *mouse_press_timer) {
    if(RecuperaCard(buffer,fim,rolagem,0,false,50,prompt,selecao,roll_bar,fundo_menu,fundo_carta,deck_meio,deck_cheio,pont,jogador,adversario,display,fundo,font,font2,color,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer)) {
        SpawnX(id_acao,true,buffer,fim,rolagem,sbox,jogador,adversario,50,display,prompt,selecao,roll_bar,pont,fundo_carta,fundo_menu,deck_meio,deck_cheio,fundo,font,font2,color,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);
    }
}

bool PossuiElemento(char *elemento,struct Player *jogador) {
    if(!strcmp(elemento,"Earth") && jogador->earth_ic > 0) return(true);
    if(!strcmp(elemento,"Wind") && jogador->wind_ic > 0) return(true);
    if(!strcmp(elemento,"Light") && jogador->light_ic > 0) return(true);
    if(!strcmp(elemento,"Dark") && jogador->dark_ic > 0) return(true);
    if(!strcmp(elemento,"Fire") && jogador->fire_ic > 0) return(true);
    if(!strcmp(elemento,"Water") && jogador->water_ic > 0) return(true);

    return(false);
}

int CardPossivel(struct Player *jogador,int level,int modo) {
    struct Deck *aux;
    int valor = 0;

    aux = jogador->hand->inicio;
    while(aux->prox != NULL) {
        if((valor != 1 && valor != 3 && valor !=  5 && valor !=  7 && valor !=  9 && valor != 11 && valor != 13 && valor != 15) && (modo == 1 || modo == 3 || modo ==  5 || modo ==  7 || modo ==  9 || modo == 11 || modo == 13 || modo == 15) && PossuiElemento(aux->card->origem->elemento,jogador) && ((aux->card->origem->monster != NULL && aux->card->origem->monster->level <= level) || (aux->card->origem->jrboss != NULL && aux->card->origem->jrboss->level <= level && !BossPresente(jogador)) || (aux->card->origem->boss != NULL && aux->card->origem->boss->level <= level && !BossPresente(jogador)))) valor += 1;
        if((valor != 2 && valor != 3 && valor !=  6 && valor !=  7 && valor != 10 && valor != 11 && valor != 14 && valor != 15) && (modo == 2 || modo == 3 || modo ==  6 || modo ==  7 || modo == 10 || modo == 11 || modo == 14 || modo == 15) && PossuiElemento(aux->card->origem->elemento,jogador) && (aux->card->origem->equip != NULL && aux->card->origem->equip->level <= level)) valor += 2;
        if((valor != 4 && valor != 5 && valor !=  6 && valor !=  7 && valor != 12 && valor != 13 && valor != 14 && valor != 15) && (modo == 4 || modo == 5 || modo ==  6 || modo ==  7 || modo == 12 || modo == 13 || modo == 14 || modo == 15) && PossuiElemento(aux->card->origem->elemento,jogador) && (aux->card->origem->tactic != NULL && aux->card->origem->tactic->level <= level)) valor += 4;
        if((valor != 8 && valor != 9 && valor != 10 && valor != 11 && valor != 12 && valor != 13 && valor != 14 && valor != 15) && (modo == 8 || modo == 9 || modo == 10 || modo == 11 || modo == 12 || modo == 13 || modo == 14 || modo == 15) && PossuiElemento(aux->card->origem->elemento,jogador) && aux->card->origem->field != NULL) valor += 8;

        aux = aux->prox;
    }

    return(valor);
}

bool PlayCard(char *texto,struct Card **buffer,int modo,int id_acao,struct StatusBox_bitmaps *sbox,ALLEGRO_BITMAP *prompt,ALLEGRO_BITMAP *selecao,ALLEGRO_BITMAP *lock,ALLEGRO_BITMAP *roll_bar,ALLEGRO_BITMAP *opcao,struct Player *jogador,struct Player *adversario,int level,ALLEGRO_DISPLAY *display,ALLEGRO_BITMAP *apontador,ALLEGRO_BITMAP *fundo_carta,ALLEGRO_BITMAP *fundo_menu,ALLEGRO_BITMAP *deck_meio,ALLEGRO_BITMAP *deck_cheio,ALLEGRO_BITMAP *fundo,ALLEGRO_FONT *font,ALLEGRO_FONT *font2,ALLEGRO_COLOR color,bool *fim_de_jogo,int *rolagem,bool *sair,int *posX,int *posY,int *dltZ,bool *mouse,bool *mouse2,bool *mouse_lado,int *keychar,bool *repete_keychar,ALLEGRO_EVENT_QUEUE *event_queue,ALLEGRO_TIMER *keyb_press_timer,ALLEGRO_TIMER *mouse_press_timer) {
    /*
    MODOS ORIGINAIS:

        1-> SPAWN           1 + 3 + (2 + 1 + 0) + 1 = 8 opcoes em todos os fatores!
        2-> EQUIP
        4-> R. ACTION
        8-> LOCATE

    */

    bool ativo = false;
    int valor;
    ALLEGRO_BITMAP *temp;

    //AtualizaMesa();
    valor = CardPossivel(jogador,level,modo);
    if(valor == 0) return(false);

    VerificaEventos(sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);

    AtualizaMesa(false,NULL,id_acao,-1,level,buffer,fim_de_jogo,sbox,prompt,selecao,roll_bar,fundo_carta,fundo_menu,deck_meio,deck_cheio,fundo,apontador,jogador,adversario,display,font,font2,color,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer,rolagem,NULL,-1,-1,0,-1,NULL,NULL);
    if(*fim_de_jogo == true) return(false);

    temp = al_clone_bitmap(al_get_backbuffer(display));
    while(1) {
        al_clear_to_color(al_map_rgb_f(0, 0, 0));
        al_draw_tinted_bitmap(temp, al_map_rgba_f(0.3, 0.3, 0.3, 0.3),0, 0, 0);

        al_draw_bitmap(opcao,240,110,0);

        if(!((valor >> 0) % 2 == 1)) al_draw_scaled_bitmap(lock,0,0,240,360,245,205,100,150,0);
        if(!((valor >> 1) % 2 == 1)) al_draw_scaled_bitmap(lock,0,0,240,360,375,205,100,150,0);
        if(!((valor >> 2) % 2 == 1)) al_draw_scaled_bitmap(lock,0,0,240,360,505,205,100,150,0);
        if(!((valor >> 3) % 2 == 1)) al_draw_scaled_bitmap(lock,0,0,240,360,635,205,100,150,0);

        if(texto != NULL) {
            al_draw_scaled_bitmap(selecao,0,0,240,360,240,425,455,25,0);
            al_draw_textf(font,color,245,430,0,texto);
        }

        al_flip_display();

        VerificaEventos(sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);

        if(*mouse2 == true) break;

        if(*mouse == true) {
            if(*posX >= 245 && *posX < 245 + 100 && *posY >= 205 && *posY < 205 + 150) {
                //al_rest(0.2);
                if((valor >> 0) % 2 == 1) {
                    ativo = SpawnX(id_acao,false,buffer,fim_de_jogo,rolagem,sbox,jogador,adversario,level,display,prompt,selecao,roll_bar,apontador,fundo_carta,fundo_menu,deck_meio,deck_cheio,fundo,font,font2,color,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);
                    break;
                }
            }
            else if(*mouse == true && *posX >= 375 && *posX < 375 + 100 && *posY >= 205 && *posY < 205 + 150) {
                //al_rest(0.2);
                if((valor >> 1) % 2 == 1) {
                    ativo = EquipX(buffer,fim_de_jogo,rolagem,0,id_acao,sbox,jogador,adversario,level,display,prompt,selecao,roll_bar,apontador,fundo_carta,fundo_menu,deck_meio,deck_cheio,fundo,font,font2,color,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);
                    break;
                }
            }
            else if(*mouse == true && *posX >= 505 && *posX < 505 + 100 && *posY >= 205 && *posY < 205 + 150) {
                //al_rest(0.2);
                if((valor >> 2) % 2 == 1) {
                    ativo = RapidActionX(id_acao,buffer,fim_de_jogo,rolagem,sbox,NULL,jogador,adversario,level,display,prompt,selecao,roll_bar,apontador,fundo_carta,fundo_menu,deck_meio,deck_cheio,fundo,font,font2,color,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);
                    break;
                }
            }
            else if(*mouse == true && *posX >= 635 && *posX < 635 + 100 && *posY >= 205 && *posY < 205 + 150) {
                //al_rest(0.2);
                if((valor >> 3) % 2 == 1) {
                    ativo = LocateX(false,id_acao,buffer,fim_de_jogo,rolagem,sbox,jogador,adversario,display,prompt,selecao,roll_bar,apontador,fundo_carta,fundo_menu,deck_meio,deck_cheio,fundo,font,font2,color,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);
                    break;
                }
            }
        }
    }

    al_destroy_bitmap(temp);
    return(ativo);
}

#include "card_acoes.c" //depende de ATTACK

void RecuperaMonsterHP(struct Player *jogador) {
    if(jogador->mesa->monstro1 != NULL && jogador->mesa->monstro1->origem->monster != NULL) jogador->mesa->monstro1->HP = jogador->mesa->monstro1->MaxHP;
    if(jogador->mesa->monstro2 != NULL && jogador->mesa->monstro2->origem->monster != NULL) jogador->mesa->monstro2->HP = jogador->mesa->monstro2->MaxHP;
    if(jogador->mesa->monstro3 != NULL && jogador->mesa->monstro3->origem->monster != NULL) jogador->mesa->monstro3->HP = jogador->mesa->monstro3->MaxHP;
    if(jogador->mesa->monstro4 != NULL && jogador->mesa->monstro4->origem->monster != NULL) jogador->mesa->monstro4->HP = jogador->mesa->monstro4->MaxHP;
    if(jogador->mesa->monstro5 != NULL && jogador->mesa->monstro5->origem->monster != NULL) jogador->mesa->monstro5->HP = jogador->mesa->monstro5->MaxHP;
    if(jogador->mesa->monstro6 != NULL && jogador->mesa->monstro6->origem->monster != NULL) jogador->mesa->monstro6->HP = jogador->mesa->monstro6->MaxHP;
    if(jogador->mesa->monstro7 != NULL && jogador->mesa->monstro7->origem->monster != NULL) jogador->mesa->monstro7->HP = jogador->mesa->monstro7->MaxHP;
}

void EfeitoInicial_mobslot(struct CARD *card,struct Card **buffer,bool *fim,int *rolagem,ALLEGRO_BITMAP *selecao,ALLEGRO_BITMAP *roll_bar,ALLEGRO_BITMAP *fundo_menu,ALLEGRO_BITMAP *fundo_carta,ALLEGRO_BITMAP *deck_meio,ALLEGRO_BITMAP *deck_cheio,ALLEGRO_BITMAP *pont,ALLEGRO_BITMAP *prompt,struct StatusBox_bitmaps *sbox,struct Player *jogador,struct Player *adversario,ALLEGRO_DISPLAY *display,ALLEGRO_BITMAP *fundo,ALLEGRO_FONT *font,ALLEGRO_FONT *font2,ALLEGRO_COLOR color,bool *sair,int *posX,int *posY,int *dltZ,bool *mouse,bool *mouse2,bool *mouse_lado,int *keychar,bool *repete_keychar,ALLEGRO_EVENT_QUEUE *event_queue,ALLEGRO_TIMER *keyb_press_timer,ALLEGRO_TIMER *mouse_press_timer) {
    if(card == NULL) return;

    card->var_monster->milk_bottle_bool = false;
    card->var_monster->skull_kid_bool = false;
    card->var_monster->rage_buff_bool = false;

    if(card->origem->colecao == GRANNY && card->turn_silenced == 0) granny_acao(-1,buffer,fim,sbox,prompt,selecao,roll_bar,fundo_carta,fundo_menu,deck_meio,deck_cheio,jogador,adversario,display,fundo,font,font2,color,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer,pont,rolagem);
}

void EfeitoInicial_eqpslot(struct CARD *card,struct Card **buffer,bool *fim,int *rolagem,ALLEGRO_BITMAP *selecao,ALLEGRO_BITMAP *roll_bar,ALLEGRO_BITMAP *fundo_menu,ALLEGRO_BITMAP *fundo_carta,ALLEGRO_BITMAP *deck_meio,ALLEGRO_BITMAP *deck_cheio,ALLEGRO_BITMAP *pont,ALLEGRO_BITMAP *prompt,struct StatusBox_bitmaps *sbox,struct Player *jogador,struct Player *adversario,ALLEGRO_DISPLAY *display,ALLEGRO_BITMAP *fundo,ALLEGRO_FONT *font,ALLEGRO_FONT *font2,ALLEGRO_COLOR color,bool *sair,int *posX,int *posY,int *dltZ,bool *mouse,bool *mouse2,bool *mouse_lado,int *keychar,bool *repete_keychar,ALLEGRO_EVENT_QUEUE *event_queue,ALLEGRO_TIMER *keyb_press_timer,ALLEGRO_TIMER *mouse_press_timer) {
    if(card == NULL) return;

    if(card->origem->colecao == OCARINA_OF_TIME) card->var_equip->ocarina_of_time_bool = true;
}

void RecuperaNivelModifier(struct Lista *deck) {    //Reseta 'level_drop' para todos os cards de um deck.
    struct Deck *aux = deck->inicio;

    while(aux->prox != NULL) {
        aux->card->level_drop = 0;
        aux = aux->prox;
    }
}

void EfeitoInicial(struct Card **buffer,bool *fim,int *rolagem,ALLEGRO_BITMAP *selecao,ALLEGRO_BITMAP *roll_bar,ALLEGRO_BITMAP *fundo_menu,ALLEGRO_BITMAP *fundo_carta,ALLEGRO_BITMAP *deck_meio,ALLEGRO_BITMAP *deck_cheio,ALLEGRO_BITMAP *pont,ALLEGRO_BITMAP *prompt,struct StatusBox_bitmaps *sbox,struct Player *jogador,struct Player *adversario,ALLEGRO_DISPLAY *display,ALLEGRO_BITMAP *fundo,ALLEGRO_FONT *font,ALLEGRO_FONT *font2,ALLEGRO_COLOR color,bool *sair,int *posX,int *posY,int *dltZ,bool *mouse,bool *mouse2,bool *mouse_lado,int *keychar,bool *repete_keychar,ALLEGRO_EVENT_QUEUE *event_queue,ALLEGRO_TIMER *keyb_press_timer,ALLEGRO_TIMER *mouse_press_timer) {
    RecuperaNivelModifier(jogador->hand);

    jogador->var_tactic->turn_next_attack_bonus = 0;

    jogador->var_tactic->flood_buff_bool = false;
    jogador->var_tactic->tidal_strike_bool = false;
    jogador->var_tactic->mido_bool = false;
    jogador->var_tactic->princess_ruto_bool = false;
    jogador->var_tactic->blue_potion_cont = 0;

    jogador->var_tactic->channeled_strike_charged_cont = jogador->var_tactic->channeled_strike_cont;
    jogador->var_tactic->channeled_strike_cont = 0;

    jogador->var_tactic->great_dekus_bless_cont = 0;
    jogador->var_tactic->great_fairys_bless_cont = 0;
    jogador->var_tactic->char_withdrawal_cont = 0;
    jogador->var_tactic->_1trl_gauntlet_cont = 0;
    jogador->var_tactic->_1trl_no_gauntlet_cont = 0;
    jogador->var_tactic->horse_riding_cont = 0;
    jogador->var_tactic->skullwalltula_cont = 0;
    jogador->var_tactic->underground_shelter_cont = 0;
    if(jogador->var_tactic->horse_riding_turn_cont > 0) jogador->var_tactic->horse_riding_turn_cont--;

    jogador->var_tactic->dark_pathway_cont = 0;
    jogador->var_tactic->gerudos_membership_card_cont = 0;

    EfeitoInicial_mobslot(jogador->mesa->monstro1,buffer,fim,rolagem,selecao,roll_bar,fundo_menu,fundo_carta,deck_meio,deck_cheio,pont,prompt,sbox,jogador,adversario,display,fundo,font,font2,color,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);
    EfeitoInicial_mobslot(jogador->mesa->monstro2,buffer,fim,rolagem,selecao,roll_bar,fundo_menu,fundo_carta,deck_meio,deck_cheio,pont,prompt,sbox,jogador,adversario,display,fundo,font,font2,color,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);
    EfeitoInicial_mobslot(jogador->mesa->monstro3,buffer,fim,rolagem,selecao,roll_bar,fundo_menu,fundo_carta,deck_meio,deck_cheio,pont,prompt,sbox,jogador,adversario,display,fundo,font,font2,color,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);
    EfeitoInicial_mobslot(jogador->mesa->monstro4,buffer,fim,rolagem,selecao,roll_bar,fundo_menu,fundo_carta,deck_meio,deck_cheio,pont,prompt,sbox,jogador,adversario,display,fundo,font,font2,color,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);
    EfeitoInicial_mobslot(jogador->mesa->monstro5,buffer,fim,rolagem,selecao,roll_bar,fundo_menu,fundo_carta,deck_meio,deck_cheio,pont,prompt,sbox,jogador,adversario,display,fundo,font,font2,color,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);
    EfeitoInicial_mobslot(jogador->mesa->monstro6,buffer,fim,rolagem,selecao,roll_bar,fundo_menu,fundo_carta,deck_meio,deck_cheio,pont,prompt,sbox,jogador,adversario,display,fundo,font,font2,color,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);
    EfeitoInicial_mobslot(jogador->mesa->monstro7,buffer,fim,rolagem,selecao,roll_bar,fundo_menu,fundo_carta,deck_meio,deck_cheio,pont,prompt,sbox,jogador,adversario,display,fundo,font,font2,color,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);

    EfeitoInicial_eqpslot(jogador->mesa->equip1,buffer,fim,rolagem,selecao,roll_bar,fundo_menu,fundo_carta,deck_meio,deck_cheio,pont,prompt,sbox,jogador,adversario,display,fundo,font,font2,color,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);
    EfeitoInicial_eqpslot(jogador->mesa->equip2,buffer,fim,rolagem,selecao,roll_bar,fundo_menu,fundo_carta,deck_meio,deck_cheio,pont,prompt,sbox,jogador,adversario,display,fundo,font,font2,color,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);
    EfeitoInicial_eqpslot(jogador->mesa->equip3,buffer,fim,rolagem,selecao,roll_bar,fundo_menu,fundo_carta,deck_meio,deck_cheio,pont,prompt,sbox,jogador,adversario,display,fundo,font,font2,color,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);
    EfeitoInicial_eqpslot(jogador->mesa->equip4,buffer,fim,rolagem,selecao,roll_bar,fundo_menu,fundo_carta,deck_meio,deck_cheio,pont,prompt,sbox,jogador,adversario,display,fundo,font,font2,color,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);
    EfeitoInicial_eqpslot(jogador->mesa->equip5,buffer,fim,rolagem,selecao,roll_bar,fundo_menu,fundo_carta,deck_meio,deck_cheio,pont,prompt,sbox,jogador,adversario,display,fundo,font,font2,color,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);
    EfeitoInicial_eqpslot(jogador->mesa->equip6,buffer,fim,rolagem,selecao,roll_bar,fundo_menu,fundo_carta,deck_meio,deck_cheio,pont,prompt,sbox,jogador,adversario,display,fundo,font,font2,color,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);
    EfeitoInicial_eqpslot(jogador->mesa->equip7,buffer,fim,rolagem,selecao,roll_bar,fundo_menu,fundo_carta,deck_meio,deck_cheio,pont,prompt,sbox,jogador,adversario,display,fundo,font,font2,color,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);

    jogador->equips_played = 0;
    jogador->mobs_played = 0;

    if(jogador->turn_away > 0) jogador->turn_away--;
    AtualizaInstancias(jogador);
}

void desfaz_zs_global(struct Player *jogador,struct Player *adversario) {
    if(jogador->mesa->equip1 != NULL && jogador->mesa->equip1->origem->colecao == ZORAS_SAPPHIRE) desfaz_zoras_sapphire_acao(jogador,adversario);
    if(jogador->mesa->equip2 != NULL && jogador->mesa->equip2->origem->colecao == ZORAS_SAPPHIRE) desfaz_zoras_sapphire_acao(jogador,adversario);
    if(jogador->mesa->equip3 != NULL && jogador->mesa->equip3->origem->colecao == ZORAS_SAPPHIRE) desfaz_zoras_sapphire_acao(jogador,adversario);
    if(jogador->mesa->equip4 != NULL && jogador->mesa->equip4->origem->colecao == ZORAS_SAPPHIRE) desfaz_zoras_sapphire_acao(jogador,adversario);
    if(jogador->mesa->equip5 != NULL && jogador->mesa->equip5->origem->colecao == ZORAS_SAPPHIRE) desfaz_zoras_sapphire_acao(jogador,adversario);
    if(jogador->mesa->equip6 != NULL && jogador->mesa->equip6->origem->colecao == ZORAS_SAPPHIRE) desfaz_zoras_sapphire_acao(jogador,adversario);
    if(jogador->mesa->equip7 != NULL && jogador->mesa->equip7->origem->colecao == ZORAS_SAPPHIRE) desfaz_zoras_sapphire_acao(jogador,adversario);

    if(adversario->mesa->equip1 != NULL && adversario->mesa->equip1->origem->colecao == ZORAS_SAPPHIRE) desfaz_zoras_sapphire_acao(jogador,adversario);
    if(adversario->mesa->equip2 != NULL && adversario->mesa->equip2->origem->colecao == ZORAS_SAPPHIRE) desfaz_zoras_sapphire_acao(jogador,adversario);
    if(adversario->mesa->equip3 != NULL && adversario->mesa->equip3->origem->colecao == ZORAS_SAPPHIRE) desfaz_zoras_sapphire_acao(jogador,adversario);
    if(adversario->mesa->equip4 != NULL && adversario->mesa->equip4->origem->colecao == ZORAS_SAPPHIRE) desfaz_zoras_sapphire_acao(jogador,adversario);
    if(adversario->mesa->equip5 != NULL && adversario->mesa->equip5->origem->colecao == ZORAS_SAPPHIRE) desfaz_zoras_sapphire_acao(jogador,adversario);
    if(adversario->mesa->equip6 != NULL && adversario->mesa->equip6->origem->colecao == ZORAS_SAPPHIRE) desfaz_zoras_sapphire_acao(jogador,adversario);
    if(adversario->mesa->equip7 != NULL && adversario->mesa->equip7->origem->colecao == ZORAS_SAPPHIRE) desfaz_zoras_sapphire_acao(jogador,adversario);
}

void desfaz_gr_global(struct Player *jogador,struct Player *adversario) {
    if(jogador->mesa->equip1 != NULL && jogador->mesa->equip1->origem->colecao == GORON_RUBY) desfaz_goron_ruby_acao(jogador,adversario);
    if(jogador->mesa->equip2 != NULL && jogador->mesa->equip2->origem->colecao == GORON_RUBY) desfaz_goron_ruby_acao(jogador,adversario);
    if(jogador->mesa->equip3 != NULL && jogador->mesa->equip3->origem->colecao == GORON_RUBY) desfaz_goron_ruby_acao(jogador,adversario);
    if(jogador->mesa->equip4 != NULL && jogador->mesa->equip4->origem->colecao == GORON_RUBY) desfaz_goron_ruby_acao(jogador,adversario);
    if(jogador->mesa->equip5 != NULL && jogador->mesa->equip5->origem->colecao == GORON_RUBY) desfaz_goron_ruby_acao(jogador,adversario);
    if(jogador->mesa->equip6 != NULL && jogador->mesa->equip6->origem->colecao == GORON_RUBY) desfaz_goron_ruby_acao(jogador,adversario);
    if(jogador->mesa->equip7 != NULL && jogador->mesa->equip7->origem->colecao == GORON_RUBY) desfaz_goron_ruby_acao(jogador,adversario);

    if(adversario->mesa->equip1 != NULL && adversario->mesa->equip1->origem->colecao == GORON_RUBY) desfaz_goron_ruby_acao(jogador,adversario);
    if(adversario->mesa->equip2 != NULL && adversario->mesa->equip2->origem->colecao == GORON_RUBY) desfaz_goron_ruby_acao(jogador,adversario);
    if(adversario->mesa->equip3 != NULL && adversario->mesa->equip3->origem->colecao == GORON_RUBY) desfaz_goron_ruby_acao(jogador,adversario);
    if(adversario->mesa->equip4 != NULL && adversario->mesa->equip4->origem->colecao == GORON_RUBY) desfaz_goron_ruby_acao(jogador,adversario);
    if(adversario->mesa->equip5 != NULL && adversario->mesa->equip5->origem->colecao == GORON_RUBY) desfaz_goron_ruby_acao(jogador,adversario);
    if(adversario->mesa->equip6 != NULL && adversario->mesa->equip6->origem->colecao == GORON_RUBY) desfaz_goron_ruby_acao(jogador,adversario);
    if(adversario->mesa->equip7 != NULL && adversario->mesa->equip7->origem->colecao == GORON_RUBY) desfaz_goron_ruby_acao(jogador,adversario);
}

void DesfazBuffs(struct Player *jogador,struct Player *adversario) {
    if(adversario->var_tactic->spirit_medallion_cont > 0) desfaz_spirit_medallion_acao(jogador,adversario,adversario->var_tactic->spirit_medallion_cont);
    if(jogador->var_tactic->spirit_medallion_cont > 0) desfaz_spirit_medallion_acao(jogador,adversario,jogador->var_tactic->spirit_medallion_cont);
    jogador->var_tactic->spirit_medallion_cont = 0;
    jogador->var_tactic->light_medallion_cont = 0;

    if(THpresente(jogador)) desfaz_dead_hand_effect(jogador);
    if(THpresente(adversario)) desfaz_dead_hand_effect(adversario);

    if(GLpresente(jogador)) desfaz_giant_leever_effect(jogador);
    if(GLpresente(adversario)) desfaz_giant_leever_effect(adversario);

    if(jogador->var_tactic->ganondorf_bool == true) desfaz_ganondorf_effect(jogador);
    if(adversario->var_tactic->ganondorf_bool == true) desfaz_ganondorf_effect(adversario);

    desfaz_gr_global(jogador,adversario);
    desfaz_zs_global(jogador,adversario);

    if(jogador->mesa->field != NULL && !strcmp(jogador->mesa->field->origem->elemento,"Water")) DesfazBlueTektiteBuff(jogador,adversario);
    else if(adversario->mesa->field != NULL && !strcmp(adversario->mesa->field->origem->elemento,"Water")) DesfazBlueTektiteBuff(jogador,adversario);

    if(jogador->mesa->field != NULL) DesfazField(jogador,adversario,jogador->mesa->field);
    if(adversario->mesa->field != NULL) DesfazField(adversario,jogador,adversario->mesa->field);

    DesfazBuffList(jogador);
}

void EfeitoInicio(struct Card **buffer,bool *fim,struct StatusBox_bitmaps *sbox,struct Player *jogador,struct Player *adversario,int *rolagem,ALLEGRO_BITMAP *selecao,ALLEGRO_BITMAP *roll_bar,ALLEGRO_BITMAP *prompt,ALLEGRO_BITMAP *fundo_carta,ALLEGRO_BITMAP *fundo_menu,ALLEGRO_BITMAP *deck_meio,ALLEGRO_BITMAP *deck_cheio,ALLEGRO_BITMAP *pont,ALLEGRO_DISPLAY *display,ALLEGRO_BITMAP *fundo,ALLEGRO_FONT *font,ALLEGRO_FONT *font2,ALLEGRO_COLOR color,bool *sair,int *posX,int *posY,int *dltZ,bool *mouse,bool *mouse2,bool *mouse_lado,int *keychar,bool *repete_keychar,ALLEGRO_EVENT_QUEUE *event_queue,ALLEGRO_TIMER *keyb_press_timer,ALLEGRO_TIMER *mouse_press_timer) {
    struct char_action *aux;
    bool ko = true;

    if(*fim == true) return;
    jogador->prevent_damage = 0;
    jogador->prevent_any_damage = 0;

    jogador->var_tactic->iron_boots_cont = 4;
    jogador->var_tactic->assistance_cont = 0;
    jogador->var_tactic->buff_cont = 0;
    jogador->var_tactic->fairys_aid_cont = 0;
    jogador->var_tactic->fairy_fountain_cont = 0;
    jogador->var_tactic->shadow_merge_spawn_cont = 0;
    adversario->var_tactic->buff_cont = 0;
    adversario->var_tactic->rauru_cont = 0;
    adversario->global_silence = false;

    if(jogador->var_tactic->giant_leever_call_bool == true) {
        printf("Detectou CALL\n");
        leever_acao(-1,buffer,fim,rolagem,selecao,roll_bar,fundo_menu,fundo_carta,deck_meio,deck_cheio,pont,prompt,sbox,jogador,adversario,display,fundo,font,font2,color,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);
        jogador->var_tactic->giant_leever_call_bool = false;
    }

    if(gerudo_guard_acao(adversario)) jogador->var_tactic->gerudo_guard_bool = true;
    else jogador->var_tactic->gerudo_guard_bool = false;

    //IMPLEMENTAR PARA JOGADOR E PARA ADVERSARIO!
    printf("Efeito Inicio ");
    aux = jogador->character_actions;
    while(aux->prox != NULL) {
        aux->goron_bracelet_bool = false;
        aux = aux->prox;
    }

    DesfazBuffs(jogador,adversario);

    RecuperaMonsterStats(true,jogador->mesa->monstro1,buffer,fim,sbox,jogador,adversario,rolagem,prompt,selecao,roll_bar,fundo_carta,deck_meio,deck_cheio,pont,display,fundo,font,font2,color,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);
    RecuperaMonsterStats(true,jogador->mesa->monstro2,buffer,fim,sbox,jogador,adversario,rolagem,prompt,selecao,roll_bar,fundo_carta,deck_meio,deck_cheio,pont,display,fundo,font,font2,color,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);
    RecuperaMonsterStats(true,jogador->mesa->monstro3,buffer,fim,sbox,jogador,adversario,rolagem,prompt,selecao,roll_bar,fundo_carta,deck_meio,deck_cheio,pont,display,fundo,font,font2,color,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);
    RecuperaMonsterStats(true,jogador->mesa->monstro4,buffer,fim,sbox,jogador,adversario,rolagem,prompt,selecao,roll_bar,fundo_carta,deck_meio,deck_cheio,pont,display,fundo,font,font2,color,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);
    RecuperaMonsterStats(true,jogador->mesa->monstro5,buffer,fim,sbox,jogador,adversario,rolagem,prompt,selecao,roll_bar,fundo_carta,deck_meio,deck_cheio,pont,display,fundo,font,font2,color,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);
    RecuperaMonsterStats(true,jogador->mesa->monstro6,buffer,fim,sbox,jogador,adversario,rolagem,prompt,selecao,roll_bar,fundo_carta,deck_meio,deck_cheio,pont,display,fundo,font,font2,color,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);
    RecuperaMonsterStats(true,jogador->mesa->monstro7,buffer,fim,sbox,jogador,adversario,rolagem,prompt,selecao,roll_bar,fundo_carta,deck_meio,deck_cheio,pont,display,fundo,font,font2,color,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);

    if(adversario->mesa->character->turn_cooldown > 0) adversario->mesa->character->turn_cooldown--;    //TURN-BASED!
    //if(card->turn_silenced > 0 && modo == false) card->turn_silenced--;  //NUNCA USADO

    RecuperaMonsterStats(false,adversario->mesa->monstro1,buffer,fim,sbox,adversario,jogador,rolagem,prompt,selecao,roll_bar,fundo_carta,deck_meio,deck_cheio,pont,display,fundo,font,font2,color,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);
    RecuperaMonsterStats(false,adversario->mesa->monstro2,buffer,fim,sbox,adversario,jogador,rolagem,prompt,selecao,roll_bar,fundo_carta,deck_meio,deck_cheio,pont,display,fundo,font,font2,color,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);
    RecuperaMonsterStats(false,adversario->mesa->monstro3,buffer,fim,sbox,adversario,jogador,rolagem,prompt,selecao,roll_bar,fundo_carta,deck_meio,deck_cheio,pont,display,fundo,font,font2,color,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);
    RecuperaMonsterStats(false,adversario->mesa->monstro4,buffer,fim,sbox,adversario,jogador,rolagem,prompt,selecao,roll_bar,fundo_carta,deck_meio,deck_cheio,pont,display,fundo,font,font2,color,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);
    RecuperaMonsterStats(false,adversario->mesa->monstro5,buffer,fim,sbox,adversario,jogador,rolagem,prompt,selecao,roll_bar,fundo_carta,deck_meio,deck_cheio,pont,display,fundo,font,font2,color,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);
    RecuperaMonsterStats(false,adversario->mesa->monstro6,buffer,fim,sbox,adversario,jogador,rolagem,prompt,selecao,roll_bar,fundo_carta,deck_meio,deck_cheio,pont,display,fundo,font,font2,color,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);
    RecuperaMonsterStats(false,adversario->mesa->monstro7,buffer,fim,sbox,adversario,jogador,rolagem,prompt,selecao,roll_bar,fundo_carta,deck_meio,deck_cheio,pont,display,fundo,font,font2,color,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);

    jogador->var_tactic->bless_of_triforce_cont = 0;

    printf("1 ");
    if(jogador->mesa->field != NULL) VerificaField(jogador->mesa->field,jogador,adversario);
    else if(adversario->mesa->field != NULL) VerificaField(adversario->mesa->field,jogador,adversario);

    if(adversario->mesa->field != NULL) VerificaField(adversario->mesa->field,adversario,jogador);
    else if(jogador->mesa->field != NULL) VerificaField(jogador->mesa->field,adversario,jogador);

    printf("2 ");
/*
    if(player->mesa->field != NULL) {
        if (!toggle) {
            AtualizaMesa(false,NULL,-1,0,buffer,fim,sbox,prompt,selecao,roll_bar,fundo_carta,deck_meio,deck_cheio,fundo,pont,jogador,adversario,display,font,font2,color,mouse,rolagem,NULL,NULL,&posX,&posY,NULL,-1,-1,0,-1,NULL);
            toggle = true;
        }
    }
*/
    RecuperaEquipStats(&(jogador->mesa->equip1),buffer,fim,&ko,sbox,jogador,adversario,rolagem,prompt,fundo_menu,selecao,roll_bar,fundo_carta,deck_meio,deck_cheio,pont,display,fundo,font,font2,color,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);
    RecuperaEquipStats(&(jogador->mesa->equip2),buffer,fim,&ko,sbox,jogador,adversario,rolagem,prompt,fundo_menu,selecao,roll_bar,fundo_carta,deck_meio,deck_cheio,pont,display,fundo,font,font2,color,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);
    RecuperaEquipStats(&(jogador->mesa->equip3),buffer,fim,&ko,sbox,jogador,adversario,rolagem,prompt,fundo_menu,selecao,roll_bar,fundo_carta,deck_meio,deck_cheio,pont,display,fundo,font,font2,color,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);
    RecuperaEquipStats(&(jogador->mesa->equip4),buffer,fim,&ko,sbox,jogador,adversario,rolagem,prompt,fundo_menu,selecao,roll_bar,fundo_carta,deck_meio,deck_cheio,pont,display,fundo,font,font2,color,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);
    RecuperaEquipStats(&(jogador->mesa->equip5),buffer,fim,&ko,sbox,jogador,adversario,rolagem,prompt,fundo_menu,selecao,roll_bar,fundo_carta,deck_meio,deck_cheio,pont,display,fundo,font,font2,color,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);
    RecuperaEquipStats(&(jogador->mesa->equip6),buffer,fim,&ko,sbox,jogador,adversario,rolagem,prompt,fundo_menu,selecao,roll_bar,fundo_carta,deck_meio,deck_cheio,pont,display,fundo,font,font2,color,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);
    RecuperaEquipStats(&(jogador->mesa->equip7),buffer,fim,&ko,sbox,jogador,adversario,rolagem,prompt,fundo_menu,selecao,roll_bar,fundo_carta,deck_meio,deck_cheio,pont,display,fundo,font,font2,color,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);

    bigger_bomb_bag_override_effect_slot(jogador->mesa->equip1,jogador);
    bigger_bomb_bag_override_effect_slot(jogador->mesa->equip2,jogador);
    bigger_bomb_bag_override_effect_slot(jogador->mesa->equip3,jogador);
    bigger_bomb_bag_override_effect_slot(jogador->mesa->equip4,jogador);
    bigger_bomb_bag_override_effect_slot(jogador->mesa->equip5,jogador);
    bigger_bomb_bag_override_effect_slot(jogador->mesa->equip6,jogador);
    bigger_bomb_bag_override_effect_slot(jogador->mesa->equip7,jogador);

    printf("3 ");

/* Listar todas as funcoes de equipamentos ou outros itens que devem ocorrer no inicio do turno(antes de char. actions). */
/* Parametros mudam de acordo com os cards jogados do P1 E/OU P2*/
    /* Cards do adversario */
    adversario->var_tactic->great_dekus_bless_cont = 0;
    adversario->var_tactic->great_fairys_bless_cont = 0;
    if(adversario->var_tactic->spirit_medallion_cont > 0) spirit_medallion_acao(adversario,jogador,adversario->var_tactic->spirit_medallion_cont);

    printf("4 ");
    EfetuaBuffList(jogador);

    printf("4.1 ");
/*
    if(player->mesa->field != NULL) {
        if (!toggle) {
            AtualizaMesa(false,NULL,-1,0,buffer,fim,sbox,prompt,selecao,roll_bar,fundo_carta,deck_meio,deck_cheio,fundo,pont,jogador,adversario,display,font,font2,color,mouse,rolagem,NULL,NULL,&posX,&posY,NULL,-1,-1,0,-1,NULL);
            toggle = true;
        }
    }
*/
    printf("5 ");

    AtivaAcaoEquip(jogador->mesa->equip1,1,-1,buffer,fim,rolagem,sbox,prompt,selecao,roll_bar,fundo_carta,fundo_menu,deck_meio,deck_cheio,pont,jogador,adversario,display,fundo,font,font2,color,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);
    AtivaAcaoEquip(jogador->mesa->equip2,1,-1,buffer,fim,rolagem,sbox,prompt,selecao,roll_bar,fundo_carta,fundo_menu,deck_meio,deck_cheio,pont,jogador,adversario,display,fundo,font,font2,color,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);
    AtivaAcaoEquip(jogador->mesa->equip3,1,-1,buffer,fim,rolagem,sbox,prompt,selecao,roll_bar,fundo_carta,fundo_menu,deck_meio,deck_cheio,pont,jogador,adversario,display,fundo,font,font2,color,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);
    AtivaAcaoEquip(jogador->mesa->equip4,1,-1,buffer,fim,rolagem,sbox,prompt,selecao,roll_bar,fundo_carta,fundo_menu,deck_meio,deck_cheio,pont,jogador,adversario,display,fundo,font,font2,color,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);
    AtivaAcaoEquip(jogador->mesa->equip5,1,-1,buffer,fim,rolagem,sbox,prompt,selecao,roll_bar,fundo_carta,fundo_menu,deck_meio,deck_cheio,pont,jogador,adversario,display,fundo,font,font2,color,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);
    AtivaAcaoEquip(jogador->mesa->equip6,1,-1,buffer,fim,rolagem,sbox,prompt,selecao,roll_bar,fundo_carta,fundo_menu,deck_meio,deck_cheio,pont,jogador,adversario,display,fundo,font,font2,color,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);
    AtivaAcaoEquip(jogador->mesa->equip7,1,-1,buffer,fim,rolagem,sbox,prompt,selecao,roll_bar,fundo_carta,fundo_menu,deck_meio,deck_cheio,pont,jogador,adversario,display,fundo,font,font2,color,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);

    AtivaAcaoMonstro(jogador->mesa->monstro1,jogador,adversario,1);
    AtivaAcaoMonstro(jogador->mesa->monstro2,jogador,adversario,1);
    AtivaAcaoMonstro(jogador->mesa->monstro3,jogador,adversario,1);
    AtivaAcaoMonstro(jogador->mesa->monstro4,jogador,adversario,1);
    AtivaAcaoMonstro(jogador->mesa->monstro5,jogador,adversario,1);
    AtivaAcaoMonstro(jogador->mesa->monstro6,jogador,adversario,1);
    AtivaAcaoMonstro(jogador->mesa->monstro7,jogador,adversario,1);

    printf("6 ");

    AtivaAcaoEquip(adversario->mesa->equip1,2,-1,buffer,fim,rolagem,sbox,prompt,selecao,roll_bar,fundo_carta,fundo_menu,deck_meio,deck_cheio,pont,adversario,jogador,display,fundo,font,font2,color,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);
    AtivaAcaoEquip(adversario->mesa->equip2,2,-1,buffer,fim,rolagem,sbox,prompt,selecao,roll_bar,fundo_carta,fundo_menu,deck_meio,deck_cheio,pont,adversario,jogador,display,fundo,font,font2,color,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);
    AtivaAcaoEquip(adversario->mesa->equip3,2,-1,buffer,fim,rolagem,sbox,prompt,selecao,roll_bar,fundo_carta,fundo_menu,deck_meio,deck_cheio,pont,adversario,jogador,display,fundo,font,font2,color,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);
    AtivaAcaoEquip(adversario->mesa->equip4,2,-1,buffer,fim,rolagem,sbox,prompt,selecao,roll_bar,fundo_carta,fundo_menu,deck_meio,deck_cheio,pont,adversario,jogador,display,fundo,font,font2,color,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);
    AtivaAcaoEquip(adversario->mesa->equip5,2,-1,buffer,fim,rolagem,sbox,prompt,selecao,roll_bar,fundo_carta,fundo_menu,deck_meio,deck_cheio,pont,adversario,jogador,display,fundo,font,font2,color,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);
    AtivaAcaoEquip(adversario->mesa->equip6,2,-1,buffer,fim,rolagem,sbox,prompt,selecao,roll_bar,fundo_carta,fundo_menu,deck_meio,deck_cheio,pont,adversario,jogador,display,fundo,font,font2,color,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);
    AtivaAcaoEquip(adversario->mesa->equip7,2,-1,buffer,fim,rolagem,sbox,prompt,selecao,roll_bar,fundo_carta,fundo_menu,deck_meio,deck_cheio,pont,adversario,jogador,display,fundo,font,font2,color,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);

    AtivaAcaoMonstro(adversario->mesa->monstro1,adversario,jogador,2);
    AtivaAcaoMonstro(adversario->mesa->monstro2,adversario,jogador,2);
    AtivaAcaoMonstro(adversario->mesa->monstro3,adversario,jogador,2);
    AtivaAcaoMonstro(adversario->mesa->monstro4,adversario,jogador,2);
    AtivaAcaoMonstro(adversario->mesa->monstro5,adversario,jogador,2);
    AtivaAcaoMonstro(adversario->mesa->monstro6,adversario,jogador,2);
    AtivaAcaoMonstro(adversario->mesa->monstro7,adversario,jogador,2);

    /*::: PONTO DE FUNCAO #5 ::: */
    if((jogador->mesa->field != NULL && !strcmp(jogador->mesa->field->origem->elemento,"Water")) || (adversario->mesa->field != NULL && !strcmp(adversario->mesa->field->origem->elemento,"Water"))) AtivaBlueTektiteBuff(jogador,adversario);

    if(THpresente(jogador)) dead_hand_effect(jogador);
    if(THpresente(adversario)) dead_hand_effect(adversario);

    if(GLpresente(jogador)) giant_leever_effect(jogador);
    if(GLpresente(adversario)) giant_leever_effect(adversario);

    if(jogador->var_tactic->ganondorf_bool == true) ganondorf_effect(jogador);
    if(adversario->var_tactic->ganondorf_bool == true) ganondorf_effect(adversario);

    jogador->var_tactic->ganondorf_bool = false;

    RecuperaZeroHP(fim,jogador);
    RecuperaZeroHP(fim,adversario);

    EfetuaDOT(buffer,fim,rolagem,sbox,jogador,adversario,display,prompt,selecao,roll_bar,fundo_carta,fundo_menu,deck_meio,deck_cheio,fundo,font,font2,color,pont,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);

    mirror_shield_counter(jogador->mesa->equip1,buffer,fim,rolagem,&ko,sbox,jogador,adversario,display,prompt,selecao,roll_bar,fundo_carta,fundo_menu,deck_meio,deck_cheio,fundo,font,font2,color,pont,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);
    mirror_shield_counter(jogador->mesa->equip2,buffer,fim,rolagem,&ko,sbox,jogador,adversario,display,prompt,selecao,roll_bar,fundo_carta,fundo_menu,deck_meio,deck_cheio,fundo,font,font2,color,pont,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);
    mirror_shield_counter(jogador->mesa->equip3,buffer,fim,rolagem,&ko,sbox,jogador,adversario,display,prompt,selecao,roll_bar,fundo_carta,fundo_menu,deck_meio,deck_cheio,fundo,font,font2,color,pont,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);
    mirror_shield_counter(jogador->mesa->equip4,buffer,fim,rolagem,&ko,sbox,jogador,adversario,display,prompt,selecao,roll_bar,fundo_carta,fundo_menu,deck_meio,deck_cheio,fundo,font,font2,color,pont,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);
    mirror_shield_counter(jogador->mesa->equip5,buffer,fim,rolagem,&ko,sbox,jogador,adversario,display,prompt,selecao,roll_bar,fundo_carta,fundo_menu,deck_meio,deck_cheio,fundo,font,font2,color,pont,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);
    mirror_shield_counter(jogador->mesa->equip6,buffer,fim,rolagem,&ko,sbox,jogador,adversario,display,prompt,selecao,roll_bar,fundo_carta,fundo_menu,deck_meio,deck_cheio,fundo,font,font2,color,pont,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);
    mirror_shield_counter(jogador->mesa->equip7,buffer,fim,rolagem,&ko,sbox,jogador,adversario,display,prompt,selecao,roll_bar,fundo_carta,fundo_menu,deck_meio,deck_cheio,fundo,font,font2,color,pont,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);

    printf("OK!\n");
}

void mb_acao(struct CARD *equip,struct Card **buffer,bool *fim_de_jogo,int *rolagem,struct StatusBox_bitmaps *sbox,struct ALLEGRO_BITMAP *prompt,struct ALLEGRO_BITMAP *selecao,struct ALLEGRO_BITMAP *roll_bar,struct ALLEGRO_BITMAP *fundo_carta,struct ALLEGRO_BITMAP *fundo_menu,struct ALLEGRO_BITMAP *deck_meio,struct ALLEGRO_BITMAP *deck_cheio,struct ALLEGRO_BITMAP *apontador,struct Player *jogador,struct Player *adversario,ALLEGRO_DISPLAY *display,struct ALLEGRO_BITMAP *fundo,ALLEGRO_FONT *font,ALLEGRO_FONT *font2,ALLEGRO_COLOR color,bool *sair,int *posX,int *posY,int *dltZ,bool *mouse,bool *mouse2,bool *mouse_lado,int *keychar,bool *repete_keychar,ALLEGRO_EVENT_QUEUE *event_queue,ALLEGRO_TIMER *keyb_press_timer,ALLEGRO_TIMER *mouse_press_timer) {
    if(jogador->equips_played == 0 && jogador->mobs_played == 0 && equip->origem->colecao == MAGIC_BEANS) {
        equip->var_equip->magic_beans_bool = true;
        RefreshHP(-1,buffer,jogador->mesa->character,20,fim_de_jogo,rolagem,sbox,prompt,selecao,roll_bar,fundo_carta,fundo_menu,deck_meio,deck_cheio,apontador,jogador,adversario,display,fundo,font,font2,color,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);
    }
    else equip->var_equip->magic_beans_bool = false;
}

void EfeitoFinal(int id_acao,struct Card **buffer,bool *fim_de_jogo,int *rolagem,struct StatusBox_bitmaps *sbox,ALLEGRO_BITMAP *prompt,ALLEGRO_BITMAP *selecao,ALLEGRO_BITMAP *roll_bar,ALLEGRO_BITMAP *fundo_carta,ALLEGRO_BITMAP *fundo_menu,ALLEGRO_BITMAP *deck_meio,ALLEGRO_BITMAP *deck_cheio,ALLEGRO_BITMAP *apontador,struct Player *jogador,struct Player *adversario,ALLEGRO_DISPLAY *display,ALLEGRO_BITMAP *fundo,ALLEGRO_FONT *font,ALLEGRO_FONT *font2,ALLEGRO_COLOR color,bool *sair,int *posX,int *posY,int *dltZ,bool *mouse,bool *mouse2,bool *mouse_lado,int *keychar,bool *repete_keychar,ALLEGRO_EVENT_QUEUE *event_queue,ALLEGRO_TIMER *keyb_press_timer,ALLEGRO_TIMER *mouse_press_timer) {
    AplicaEOTTactics(buffer,fim_de_jogo,rolagem,sbox,jogador,adversario,display,prompt,selecao,roll_bar,apontador,fundo_carta,fundo_menu,deck_meio,deck_cheio,fundo,font,font2,color,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);

    if(jogador->mesa->equip1 != NULL) mb_acao(jogador->mesa->equip1,buffer,fim_de_jogo,rolagem,sbox,prompt,selecao,roll_bar,fundo_carta,fundo_menu,deck_meio,deck_cheio,apontador,jogador,adversario,display,fundo,font,font2,color,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);
    if(jogador->mesa->equip2 != NULL) mb_acao(jogador->mesa->equip2,buffer,fim_de_jogo,rolagem,sbox,prompt,selecao,roll_bar,fundo_carta,fundo_menu,deck_meio,deck_cheio,apontador,jogador,adversario,display,fundo,font,font2,color,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);
    if(jogador->mesa->equip3 != NULL) mb_acao(jogador->mesa->equip3,buffer,fim_de_jogo,rolagem,sbox,prompt,selecao,roll_bar,fundo_carta,fundo_menu,deck_meio,deck_cheio,apontador,jogador,adversario,display,fundo,font,font2,color,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);
    if(jogador->mesa->equip4 != NULL) mb_acao(jogador->mesa->equip4,buffer,fim_de_jogo,rolagem,sbox,prompt,selecao,roll_bar,fundo_carta,fundo_menu,deck_meio,deck_cheio,apontador,jogador,adversario,display,fundo,font,font2,color,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);
    if(jogador->mesa->equip5 != NULL) mb_acao(jogador->mesa->equip5,buffer,fim_de_jogo,rolagem,sbox,prompt,selecao,roll_bar,fundo_carta,fundo_menu,deck_meio,deck_cheio,apontador,jogador,adversario,display,fundo,font,font2,color,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);
    if(jogador->mesa->equip6 != NULL) mb_acao(jogador->mesa->equip6,buffer,fim_de_jogo,rolagem,sbox,prompt,selecao,roll_bar,fundo_carta,fundo_menu,deck_meio,deck_cheio,apontador,jogador,adversario,display,fundo,font,font2,color,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);
    if(jogador->mesa->equip7 != NULL) mb_acao(jogador->mesa->equip7,buffer,fim_de_jogo,rolagem,sbox,prompt,selecao,roll_bar,fundo_carta,fundo_menu,deck_meio,deck_cheio,apontador,jogador,adversario,display,fundo,font,font2,color,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);

    while(jogador->var_tactic->shadow_merge_spawn_cont > 0) {
        shadow_merge_play_monster(buffer,fim_de_jogo,rolagem,sbox,jogador,adversario,display,prompt,selecao,roll_bar,apontador,fundo_carta,fundo_menu,deck_meio,deck_cheio,fundo,font,font2,color,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);
        jogador->var_tactic->shadow_merge_spawn_cont--;
    }

    malon_acao(jogador->mesa->monstro1,id_acao,buffer,fim_de_jogo,rolagem,sbox,prompt,selecao,roll_bar,fundo_carta,fundo_menu,deck_meio,deck_cheio,apontador,jogador,adversario,display,fundo,font,font2,color,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);
    malon_acao(jogador->mesa->monstro2,id_acao,buffer,fim_de_jogo,rolagem,sbox,prompt,selecao,roll_bar,fundo_carta,fundo_menu,deck_meio,deck_cheio,apontador,jogador,adversario,display,fundo,font,font2,color,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);
    malon_acao(jogador->mesa->monstro3,id_acao,buffer,fim_de_jogo,rolagem,sbox,prompt,selecao,roll_bar,fundo_carta,fundo_menu,deck_meio,deck_cheio,apontador,jogador,adversario,display,fundo,font,font2,color,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);
    malon_acao(jogador->mesa->monstro4,id_acao,buffer,fim_de_jogo,rolagem,sbox,prompt,selecao,roll_bar,fundo_carta,fundo_menu,deck_meio,deck_cheio,apontador,jogador,adversario,display,fundo,font,font2,color,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);
    malon_acao(jogador->mesa->monstro5,id_acao,buffer,fim_de_jogo,rolagem,sbox,prompt,selecao,roll_bar,fundo_carta,fundo_menu,deck_meio,deck_cheio,apontador,jogador,adversario,display,fundo,font,font2,color,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);
    malon_acao(jogador->mesa->monstro6,id_acao,buffer,fim_de_jogo,rolagem,sbox,prompt,selecao,roll_bar,fundo_carta,fundo_menu,deck_meio,deck_cheio,apontador,jogador,adversario,display,fundo,font,font2,color,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);
    malon_acao(jogador->mesa->monstro7,id_acao,buffer,fim_de_jogo,rolagem,sbox,prompt,selecao,roll_bar,fundo_carta,fundo_menu,deck_meio,deck_cheio,apontador,jogador,adversario,display,fundo,font,font2,color,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);

    RecuperaMonsterHP(jogador);
}

//NUNCA FOI APLICADA!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
void EfeitoCardSilence(struct CARD *card,struct Player *jogador,struct Player *adversario) {   //FUNCAO APLICADA ANTES de silenciar (card) DURANTE A VEZ DO (jogador).
    if(card != NULL && card->turn_silenced == 0) {
        if(card->origem->colecao == DEAD_HAND) desfaz_dead_hand_effect(adversario);
        else if(card->origem->colecao == GIANT_LEEVER) desfaz_giant_leever_effect(adversario);

        //else if(card->origem->colecao == GANONDORF) desfaz_ganondorf_effect(adversario);

        //outras AURAS de HP/ATK...
    }
}

void ScoutMonster(int id_acao,struct Card **buffer,bool *fim,int *rolagem,struct StatusBox_bitmaps *sbox,ALLEGRO_BITMAP *prompt,ALLEGRO_BITMAP *selecao,ALLEGRO_BITMAP *roll_bar,ALLEGRO_BITMAP *fundo_carta,ALLEGRO_BITMAP *fundo_menu,ALLEGRO_BITMAP *deck_meio,ALLEGRO_BITMAP *deck_cheio,ALLEGRO_BITMAP *pont,struct Player *jogador,struct Player *adversario,ALLEGRO_DISPLAY *display,ALLEGRO_BITMAP *fundo,ALLEGRO_FONT *font,ALLEGRO_FONT *font2,ALLEGRO_COLOR color,bool *sair,int *posX,int *posY,int *dltZ,bool *mouse,bool *mouse2,bool *mouse_lado,int *keychar,bool *repete_keychar,ALLEGRO_EVENT_QUEUE *event_queue,ALLEGRO_TIMER *keyb_press_timer,ALLEGRO_TIMER *mouse_press_timer) { //OK!
    if(jogador->deck->quantidade == 0) return;

    printf("SCOUT ");
    OlhaCarta(id_acao,buffer,fim,sbox,prompt,selecao,roll_bar,fundo_carta,fundo_menu,deck_meio,deck_cheio,pont,jogador,adversario,display,fundo,font,font2,color,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer,rolagem);
    printf("1 ");
    if(strcmp(jogador->deck->inicio->card->origem->tipo,"Monster") == 0 || strcmp(jogador->deck->inicio->card->origem->tipo,"Jr. Boss") == 0 || strcmp(jogador->deck->inicio->card->origem->tipo,"Boss") == 0) {
        DrawCard(id_acao,buffer,fim,rolagem,sbox,prompt,selecao,roll_bar,fundo_carta,fundo_menu,deck_meio,deck_cheio,pont,jogador,adversario,display,fundo,font,font2,color,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);
        printf("2 ");
        SpawnX(id_acao,true,buffer,fim,rolagem,sbox,jogador,adversario,jogador->level,display,prompt,selecao,roll_bar,pont,fundo_carta,fundo_menu,deck_meio,deck_cheio,fundo,font,font2,color,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);
        printf("OK");
    }
}

void DrinkPotion(struct Player *jogador) {
    *(jogador->HP) = *(jogador->HP) + jogador->level;
    if(*(jogador->HP) > *(jogador->MaxHP)) *(jogador->HP) = *(jogador->MaxHP);
}

void GeraObjetivo(char *objetivo,char *texto) { //OK!
    char ch;
    int i=0;

    ch = texto[0];
    while(ch != '-') {
        objetivo[i] = ch;
        i++;
        ch = texto[i];
    }
    objetivo[i] = 0;
}

void ExecutaGatilho(int id_acao,char *texto,struct Card **buffer,bool *fim,int *rolagem,struct StatusBox_bitmaps *sbox,ALLEGRO_BITMAP *prompt,ALLEGRO_BITMAP *selecao,ALLEGRO_BITMAP *roll_bar,ALLEGRO_BITMAP *fundo_menu,ALLEGRO_BITMAP *apontador,ALLEGRO_BITMAP *fundo_carta,ALLEGRO_BITMAP *deck_meio,ALLEGRO_BITMAP *deck_cheio,struct Player *jogador,struct Player *adversario,ALLEGRO_DISPLAY *display,ALLEGRO_BITMAP *fundo,ALLEGRO_FONT *font,ALLEGRO_FONT *font2,ALLEGRO_COLOR color,bool *sair,int *posX,int *posY,int *dltZ,bool *mouse,bool *mouse2,bool *mouse_lado,int *keychar,bool *repete_keychar,ALLEGRO_EVENT_QUEUE *event_queue,ALLEGRO_TIMER *keyb_press_timer,ALLEGRO_TIMER *mouse_press_timer) {
    char *objetivo;
    bool ko = true;

    objetivo = (char *)malloc(32*sizeof(char));
    GeraObjetivo(objetivo,texto);

    printf("(");
    /*::: PONTO DE FUNCAO #14 ::: */
    if(strcmp(objetivo,"Scout ") == 0) ScoutMonster(id_acao,buffer,fim,rolagem,sbox,prompt,selecao,roll_bar,fundo_carta,fundo_menu,deck_meio,deck_cheio,apontador,jogador,adversario,display,fundo,font,font2,color,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);
    else if(strcmp(objetivo,"Monster Resurrection ") == 0) RessucitaMaior50(id_acao,buffer,fim,rolagem,selecao,roll_bar,fundo_menu,fundo_carta,deck_meio,deck_cheio,apontador,prompt,sbox,jogador,adversario,display,fundo,font,font2,color,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);
    else if(strcmp(objetivo,"Lesser Monster Resurrection ") == 0) RessucitaMenor50(id_acao,buffer,fim,rolagem,selecao,roll_bar,fundo_menu,fundo_carta,deck_meio,deck_cheio,apontador,prompt,sbox,jogador,adversario,display,fundo,font,font2,color,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);
    else if(strcmp(objetivo,"Drink Potion ") == 0) DrinkPotion(jogador);
    else if(strcmp(objetivo,"Rage Buff ") == 0) moblin_lvacao(jogador);
    else if(strcmp(objetivo,"Raurus Wisdom ") == 0) rauru_lvacao(id_acao,buffer,fim,rolagem,sbox,prompt,selecao,roll_bar,fundo_carta,fundo_menu,deck_meio,deck_cheio,jogador,adversario,display,fundo,font,font2,color,apontador,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);
    else if(strcmp(objetivo,"Mortal Strike ") == 0) deku_seeds_bag_lvacao(-1,buffer,fim,rolagem,&ko,sbox,jogador,adversario,display,prompt,selecao,roll_bar,fundo_carta,fundo_menu,deck_meio,deck_cheio,fundo,font,font2,color,apontador,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);
    else if(strcmp(objetivo,"Buff ") == 0) milk_bottle_lvacao(fim,jogador,display,prompt,selecao,roll_bar,fundo_carta,fundo_menu,fundo,font,font2,color,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);
    else if(strcmp(objetivo,"Mercy ") == 0) gdtk_lvacao(id_acao,buffer,fim,rolagem,sbox,prompt,selecao,roll_bar,fundo_carta,fundo_menu,deck_meio,deck_cheio,apontador,jogador,adversario,display,fundo,font,font2,color,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);
    //else if(strcmp(objetivo,"Flood Strike ") == 0) jogador->var_tactic->flood_buff_bool = true;
    else if(strcmp(objetivo,"Tidal Strike ") == 0) jogador->var_tactic->tidal_strike_bool = true;
    else if(strcmp(objetivo,"Side Quest ") == 0) DrawCard(id_acao,buffer,fim,rolagem,sbox,prompt,selecao,roll_bar,fundo_carta,fundo_menu,deck_meio,deck_cheio,apontador,jogador,adversario,display,fundo,font,font2,color,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);
    else if(strcmp(objetivo,"Hazardous Winds ") == 0) freezard_lvacao(id_acao,buffer,rolagem,sbox,selecao,roll_bar,prompt,fim,fundo_carta,fundo_menu,deck_meio,deck_cheio,jogador,adversario,display,fundo,font,font2,color,apontador,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);
    else if(strcmp(objetivo,"Ranch Therapy ") == 0) malon_lvacao(id_acao,buffer,fim,rolagem,sbox,prompt,selecao,roll_bar,fundo_carta,fundo_menu,deck_meio,deck_cheio,apontador,jogador,adversario,display,fundo,font,font2,color,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);

    else {
        printf("Unhandled ONE-SHOT action: '%s'\n", objetivo);
    }

    free(objetivo);
    printf(")");
}

bool DetectaAcao(char *acao,int id_acao,struct Card **buffer,struct CARD *card_origem,int *rolagem,struct StatusBox_bitmaps *sbox,ALLEGRO_BITMAP *selecao,ALLEGRO_BITMAP *lock,ALLEGRO_BITMAP *roll_bar,ALLEGRO_BITMAP *prompt,bool *fim_de_jogo,ALLEGRO_BITMAP *fundo_carta,ALLEGRO_BITMAP *fundo_menu,ALLEGRO_BITMAP *deck_meio,ALLEGRO_BITMAP *deck_cheio,struct Player *jogador,struct Player *adversario,ALLEGRO_DISPLAY *display,ALLEGRO_BITMAP *fundo,ALLEGRO_FONT *font,ALLEGRO_FONT *font2,ALLEGRO_COLOR color,ALLEGRO_BITMAP *apontador,ALLEGRO_BITMAP *escolhe_tipo,struct VariaveisTACTIC *tactics,ALLEGRO_TIMER *timer,bool *sair,int *posX,int *posY,int *dltZ,bool *mouse,bool *mouse2,bool *mouse_lado,int *keychar,bool *repete_keychar,ALLEGRO_EVENT_QUEUE *event_queue,ALLEGRO_TIMER *keyb_press_timer,ALLEGRO_TIMER *mouse_press_timer) {
    char *str,ch = '\0';
    int cont;
    bool ko = true;
    bool ativo = true;

    if(jogador->var_tactic->iron_boots_cont == 0) {
        al_set_timer_count(timer, 0);
        al_start_timer(timer);
        while(al_get_timer_count(timer) < 1500) {
            AtualizaMesa(true,"IRON BOOTS: ran out of actions!",id_acao,-1,0,buffer,fim_de_jogo,sbox,prompt,selecao,roll_bar,fundo_carta,fundo_menu,deck_meio,deck_cheio,fundo,apontador,jogador,adversario,display,font,font2,color,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer,rolagem,NULL,-1,-1,0,-1,NULL,NULL);
        }
        al_stop_timer(timer);

        return(false);
    }

    if(acao[0] == 0) {
        printf("Acao NULA!\n");
        return(false);
    }
    str = (char *)malloc(42*sizeof(char));
    sprintf(str,"#%d%d",id_acao/10, id_acao%10);
    cont = 3;

    while(ch != '-') {
        ch = acao[cont - 3];
        str[cont] = ch;
        cont++;
    }
    str[cont - 1] = 0;

    al_set_timer_count(timer, 0);
    al_start_timer(timer);
    while(al_get_timer_count(timer) < 1500) {
        AtualizaMesa(true,str,id_acao,-1,0,buffer,fim_de_jogo,sbox,prompt,selecao,roll_bar,fundo_carta,fundo_menu,deck_meio,deck_cheio,fundo,apontador,jogador,adversario,display,font,font2,color,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer,rolagem,NULL,-1,-1,0,-1,NULL,NULL);
    }
    al_stop_timer(timer);

    /*::: PONTO DE FUNCAO #6 ::: */
    if(strcmp(str,"Mission ") == 0) ativo = DrawCard(id_acao,buffer,fim_de_jogo,rolagem,sbox,prompt,selecao,roll_bar,fundo_carta,fundo_menu,deck_meio,deck_cheio,apontador,jogador,adversario,display,fundo,font,font2,color,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);
    else if(strcmp(str,"Refresh ") == 0) ativo = RefreshHP(id_acao,buffer,jogador->mesa->character,10,fim_de_jogo,rolagem,sbox,prompt,selecao,roll_bar,fundo_carta,fundo_menu,deck_meio,deck_cheio,apontador,jogador,adversario,display,fundo,font,font2,color,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);
    else if(strcmp(str,"Buff ") == 0) jogador->var_tactic->buff_cont += 1;
    else if(strcmp(str,"Assistance ") == 0) jogador->var_tactic->assistance_cont += 1;
    else if(strcmp(str,"Skulltulas Wrath ") == 0) jogador->var_tactic->skullwalltula_cont += 1;

    else if(strcmp(str,"Thrust ") == 0) ativo = Attack(id_acao,true,false,buffer,fim_de_jogo,rolagem,&ko,0,1,0,sbox,jogador,adversario,card_origem,10,display,prompt,selecao,roll_bar,fundo_carta,fundo_menu,deck_meio,deck_cheio,fundo,font,font2,color,apontador,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);  //lista de acoes
    else if(strcmp(str,"Stab ") == 0) ativo = Attack(id_acao,true,false,buffer,fim_de_jogo,rolagem,&ko,0,1,0,sbox,jogador,adversario,card_origem,10,display,prompt,selecao,roll_bar,fundo_carta,fundo_menu,deck_meio,deck_cheio,fundo,font,font2,color,apontador,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);
    else if(strcmp(str,"Silent Stab ") == 0) ativo = Attack(id_acao,true,false,buffer,fim_de_jogo,rolagem,&ko,0,1,0,sbox,jogador,adversario,card_origem,10,display,prompt,selecao,roll_bar,fundo_carta,fundo_menu,deck_meio,deck_cheio,fundo,font,font2,color,apontador,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);
    else if(strcmp(str,"Headbutt ") == 0) ativo = Attack(id_acao,true,false,buffer,fim_de_jogo,rolagem,&ko,0,1,0,sbox,jogador,adversario,card_origem,10,display,prompt,selecao,roll_bar,fundo_carta,fundo_menu,deck_meio,deck_cheio,fundo,font,font2,color,apontador,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);
    else if(strcmp(str,"Shadow Blast ") == 0) ativo = Attack(id_acao,true,false,buffer,fim_de_jogo,rolagem,&ko,0,1,0,sbox,jogador,adversario,card_origem,10,display,prompt,selecao,roll_bar,fundo_carta,fundo_menu,deck_meio,deck_cheio,fundo,font,font2,color,apontador,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);
    else if(strcmp(str,"Bubble Shot ") == 0) ativo = Attack(id_acao,true,false,buffer,fim_de_jogo,rolagem,&ko,0,1,0,sbox,jogador,adversario,card_origem,10,display,prompt,selecao,roll_bar,fundo_carta,fundo_menu,deck_meio,deck_cheio,fundo,font,font2,color,apontador,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);

    else if(strcmp(str,"Flash Stab ") == 0) ativo = Attack(id_acao,true,false,buffer,fim_de_jogo,rolagem,&ko,0,1,0,sbox,jogador,adversario,card_origem,20,display,prompt,selecao,roll_bar,fundo_carta,fundo_menu,deck_meio,deck_cheio,fundo,font,font2,color,apontador,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);
    else if(strcmp(str,"Burning Flames ") == 0) ativo = Attack(id_acao,true,false,buffer,fim_de_jogo,rolagem,&ko,0,1,0,sbox,jogador,adversario,card_origem,20,display,prompt,selecao,roll_bar,fundo_carta,fundo_menu,deck_meio,deck_cheio,fundo,font,font2,color,apontador,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);
    else if(strcmp(str,"Devastating Strike ") == 0) ativo = Attack(id_acao,true,false,buffer,fim_de_jogo,rolagem,&ko,0,1,0,sbox,jogador,adversario,card_origem,30,display,prompt,selecao,roll_bar,fundo_carta,fundo_menu,deck_meio,deck_cheio,fundo,font,font2,color,apontador,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);
    else if(strcmp(str,"Hurricane ") == 0) {
        ativo = Attack(id_acao,true,false,buffer,fim_de_jogo,rolagem,&ko,0,1,0,sbox,jogador,adversario,card_origem,20,display,prompt,selecao,roll_bar,fundo_carta,fundo_menu,deck_meio,deck_cheio,fundo,font,font2,color,apontador,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);
        while(ko == true) Attack(id_acao,true,false,buffer,fim_de_jogo,rolagem,&ko,0,1,0,sbox,jogador,adversario,card_origem,20,display,prompt,selecao,roll_bar,fundo_carta,fundo_menu,deck_meio,deck_cheio,fundo,font,font2,color,apontador,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);
    }
    else if(strcmp(str,"Shadow Rip ") == 0) ativo = bomb_bag_lvacao(id_acao,buffer,fim_de_jogo,rolagem,&ko,sbox,jogador,adversario,card_origem,display,prompt,selecao,roll_bar,fundo_carta,fundo_menu,deck_meio,deck_cheio,fundo,font,font2,color,apontador,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);
    //else if(strcmp(str,"Slash ") == 0) ativo = Attack(id_acao,true,false,buffer,fim_de_jogo,rolagem,&ko,0,1,0,sbox,jogador,adversario,card_origem,20,display,prompt,selecao,roll_bar,fundo_carta,fundo_menu,deck_meio,deck_cheio,fundo,font,font2,color,apontador,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);
    else if(strcmp(str,"Spin Attack ") == 0) ativo = Attack(id_acao,true,false,buffer,fim_de_jogo,rolagem,&ko,0,1,0,sbox,jogador,adversario,card_origem,20,display,prompt,selecao,roll_bar,fundo_carta,fundo_menu,deck_meio,deck_cheio,fundo,font,font2,color,apontador,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);
    else if(strcmp(str,"Goron Barrage ") == 0) ativo = Attack(id_acao,true,false,buffer,fim_de_jogo,rolagem,&ko,0,1,0,sbox,jogador,adversario,card_origem,20,display,prompt,selecao,roll_bar,fundo_carta,fundo_menu,deck_meio,deck_cheio,fundo,font,font2,color,apontador,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);
    else if(strcmp(str,"Concussive Beam ") == 0) ativo = Attack(id_acao,true,false,buffer,fim_de_jogo,rolagem,&ko,0,1,0,sbox,jogador,adversario,card_origem,30,display,prompt,selecao,roll_bar,fundo_carta,fundo_menu,deck_meio,deck_cheio,fundo,font,font2,color,apontador,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);

    else if(strcmp(str,"Airwave ") == 0) ativo = Attack(id_acao,true,false,buffer,fim_de_jogo,rolagem,&ko,1,1,0,sbox,jogador,adversario,card_origem,20,display,prompt,selecao,roll_bar,fundo_carta,fundo_menu,deck_meio,deck_cheio,fundo,font,font2,color,apontador,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);
    else if(strcmp(str,"Bright Strike ") == 0) ativo = Attack(id_acao,true,false,buffer,fim_de_jogo,rolagem,&ko,1,1,0,sbox,jogador,adversario,card_origem,20,display,prompt,selecao,roll_bar,fundo_carta,fundo_menu,deck_meio,deck_cheio,fundo,font,font2,color,apontador,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);

    else if(strcmp(str,"Flash Strike ") == 0) ativo = Attack(id_acao,true,false,buffer,fim_de_jogo,rolagem,&ko,2,1,0,sbox,jogador,adversario,card_origem,30,display,prompt,selecao,roll_bar,fundo_carta,fundo_menu,deck_meio,deck_cheio,fundo,font,font2,color,apontador,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);
    else if(strcmp(str,"Gerudo Assault ") == 0) ativo = Attack(id_acao,true,false,buffer,fim_de_jogo,rolagem,&ko,2,1,0,sbox,jogador,adversario,card_origem,40,display,prompt,selecao,roll_bar,fundo_carta,fundo_menu,deck_meio,deck_cheio,fundo,font,font2,color,apontador,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);
    else if(strcmp(str,"Air Strike ") == 0) ativo = Attack(id_acao,true,false,buffer,fim_de_jogo,rolagem,&ko,0,1,0,sbox,jogador,adversario,card_origem,20,display,prompt,selecao,roll_bar,fundo_carta,fundo_menu,deck_meio,deck_cheio,fundo,font,font2,color,apontador,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);

    else if(strcmp(str,"Summon X ") == 0) ativo = SpawnX(id_acao,false,buffer,fim_de_jogo,rolagem,sbox,jogador,adversario,jogador->level,display,prompt,selecao,roll_bar,apontador,fundo_carta,fundo_menu,deck_meio,deck_cheio,fundo,font,font2,color,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);
    else if(strcmp(str,"Summon 60 ") == 0) ativo = SpawnX(id_acao,false,buffer,fim_de_jogo,rolagem,sbox,jogador,adversario,60,display,prompt,selecao,roll_bar,apontador,fundo_carta,fundo_menu,deck_meio,deck_cheio,fundo,font,font2,color,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);
    else if(strcmp(str,"Summon 80 ") == 0) ativo = SpawnX(id_acao,false,buffer,fim_de_jogo,rolagem,sbox,jogador,adversario,80,display,prompt,selecao,roll_bar,apontador,fundo_carta,fundo_menu,deck_meio,deck_cheio,fundo,font,font2,color,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);
    else if(strcmp(str,"Summon 100 ") == 0) ativo = SpawnX(id_acao,false,buffer,fim_de_jogo,rolagem,sbox,jogador,adversario,100,display,prompt,selecao,roll_bar,apontador,fundo_carta,fundo_menu,deck_meio,deck_cheio,fundo,font,font2,color,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);

    else if(strcmp(str,"Rapid Action 40 ") == 0) ativo = RapidActionX(id_acao,buffer,fim_de_jogo,rolagem,sbox,NULL,jogador,adversario,40,display,prompt,selecao,roll_bar,apontador,fundo_carta,fundo_menu,deck_meio,deck_cheio,fundo,font,font2,color,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);
    else if(strcmp(str,"Rapid Action 50 ") == 0) ativo = RapidActionX(id_acao,buffer,fim_de_jogo,rolagem,sbox,NULL,jogador,adversario,50,display,prompt,selecao,roll_bar,apontador,fundo_carta,fundo_menu,deck_meio,deck_cheio,fundo,font,font2,color,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);
    else if(strcmp(str,"Rapid Action 80 ") == 0) ativo = RapidActionX(id_acao,buffer,fim_de_jogo,rolagem,sbox,NULL,jogador,adversario,80,display,prompt,selecao,roll_bar,apontador,fundo_carta,fundo_menu,deck_meio,deck_cheio,fundo,font,font2,color,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);
    else if(strcmp(str,"Rapid Action X ") == 0) ativo = RapidActionX(id_acao,buffer,fim_de_jogo,rolagem,sbox,NULL,jogador,adversario,jogador->level,display,prompt,selecao,roll_bar,apontador,fundo_carta,fundo_menu,deck_meio,deck_cheio,fundo,font,font2,color,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);

    else if(strcmp(str,"Equip 40 ") == 0) ativo = EquipX(buffer,fim_de_jogo,rolagem,0,id_acao,sbox,jogador,adversario,40,display,prompt,selecao,roll_bar,apontador,fundo_carta,fundo_menu,deck_meio,deck_cheio,fundo,font,font2,color,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);
    else if(strcmp(str,"Equip 70 ") == 0) ativo = EquipX(buffer,fim_de_jogo,rolagem,0,id_acao,sbox,jogador,adversario,70,display,prompt,selecao,roll_bar,apontador,fundo_carta,fundo_menu,deck_meio,deck_cheio,fundo,font,font2,color,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);
    else if(strcmp(str,"Equip X ") == 0) ativo = EquipX(buffer,fim_de_jogo,rolagem,0,id_acao,sbox,jogador,adversario,jogador->level,display,prompt,selecao,roll_bar,apontador,fundo_carta,fundo_menu,deck_meio,deck_cheio,fundo,font,font2,color,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);
    else if(strcmp(str,"Gear Up ") == 0) ativo = EquipX(buffer,fim_de_jogo,rolagem,1,id_acao,sbox,jogador,adversario,jogador->level,display,prompt,selecao,roll_bar,apontador,fundo_carta,fundo_menu,deck_meio,deck_cheio,fundo,font,font2,color,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);

    else if(strcmp(str,"Locate ") == 0) ativo = LocateX(false,id_acao,buffer,fim_de_jogo,rolagem,sbox,jogador,adversario,display,prompt,selecao,roll_bar,apontador,fundo_carta,fundo_menu,deck_meio,deck_cheio,fundo,font,font2,color,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);

    else if(strcmp(str,"Summon / Equip / Rapid Action 30 ") == 0) ativo = PlayCard(str,buffer,7,id_acao,sbox,prompt,selecao,lock,roll_bar,escolhe_tipo,jogador,adversario,30,display,apontador,fundo_carta,fundo_menu,deck_meio,deck_cheio,fundo,font,font2,color,fim_de_jogo,rolagem,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);
    else if(strcmp(str,"Summon / Equip / Rapid Action 40 ") == 0) ativo = PlayCard(str,buffer,7,id_acao,sbox,prompt,selecao,lock,roll_bar,escolhe_tipo,jogador,adversario,40,display,apontador,fundo_carta,fundo_menu,deck_meio,deck_cheio,fundo,font,font2,color,fim_de_jogo,rolagem,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);
    else if(strcmp(str,"Summon / Equip / Rapid Action 80 ") == 0) ativo = PlayCard(str,buffer,7,id_acao,sbox,prompt,selecao,lock,roll_bar,escolhe_tipo,jogador,adversario,80,display,apontador,fundo_carta,fundo_menu,deck_meio,deck_cheio,fundo,font,font2,color,fim_de_jogo,rolagem,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);

    else if(strcmp(str,"Summon / Equip / Locate 50 ") == 0) ativo = PlayCard(str,buffer,11,id_acao,sbox,prompt,selecao,lock,roll_bar,escolhe_tipo,jogador,adversario,50,display,apontador,fundo_carta,fundo_menu,deck_meio,deck_cheio,fundo,font,font2,color,fim_de_jogo,rolagem,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);
    else if(strcmp(str,"Summon / Equip / Locate 70 ") == 0) ativo = PlayCard(str,buffer,11,id_acao,sbox,prompt,selecao,lock,roll_bar,escolhe_tipo,jogador,adversario,70,display,apontador,fundo_carta,fundo_menu,deck_meio,deck_cheio,fundo,font,font2,color,fim_de_jogo,rolagem,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);
    else if(strcmp(str,"Summon / Equip / Locate 90 ") == 0) ativo = PlayCard(str,buffer,11,id_acao,sbox,prompt,selecao,lock,roll_bar,escolhe_tipo,jogador,adversario,90,display,apontador,fundo_carta,fundo_menu,deck_meio,deck_cheio,fundo,font,font2,color,fim_de_jogo,rolagem,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);
    else if(strcmp(str,"Summon / Equip / Locate 100 ") == 0) ativo = PlayCard(str,buffer,11,id_acao,sbox,prompt,selecao,lock,roll_bar,escolhe_tipo,jogador,adversario,100,display,apontador,fundo_carta,fundo_menu,deck_meio,deck_cheio,fundo,font,font2,color,fim_de_jogo,rolagem,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);
    else if(strcmp(str,"Equip / Rapid Action / Locate 50 ") == 0) ativo = PlayCard(str,buffer,14,id_acao,sbox,prompt,selecao,lock,roll_bar,escolhe_tipo,jogador,adversario,50,display,apontador,fundo_carta,fundo_menu,deck_meio,deck_cheio,fundo,font,font2,color,fim_de_jogo,rolagem,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);
    else if(strcmp(str,"Equip / Rapid Action / Locate 60 ") == 0) ativo = PlayCard(str,buffer,14,id_acao,sbox,prompt,selecao,lock,roll_bar,escolhe_tipo,jogador,adversario,60,display,apontador,fundo_carta,fundo_menu,deck_meio,deck_cheio,fundo,font,font2,color,fim_de_jogo,rolagem,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);
    else if(strcmp(str,"Equip / Rapid Action / Locate 80 ") == 0) ativo = PlayCard(str,buffer,14,id_acao,sbox,prompt,selecao,lock,roll_bar,escolhe_tipo,jogador,adversario,80,display,apontador,fundo_carta,fundo_menu,deck_meio,deck_cheio,fundo,font,font2,color,fim_de_jogo,rolagem,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);
    else if(strcmp(str,"Equip / Rapid Action / Locate 100 ") == 0) ativo = PlayCard(str,buffer,14,id_acao,sbox,prompt,selecao,lock,roll_bar,escolhe_tipo,jogador,adversario,100,display,apontador,fundo_carta,fundo_menu,deck_meio,deck_cheio,fundo,font,font2,color,fim_de_jogo,rolagem,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);

    else if(strcmp(str,"Summon / Equip 30 ") == 0) ativo = PlayCard(str,buffer,3,id_acao,sbox,prompt,selecao,lock,roll_bar,escolhe_tipo,jogador,adversario,30,display,apontador,fundo_carta,fundo_menu,deck_meio,deck_cheio,fundo,font,font2,color,fim_de_jogo,rolagem,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);
    else if(strcmp(str,"Summon / Equip 40 ") == 0) ativo = PlayCard(str,buffer,3,id_acao,sbox,prompt,selecao,lock,roll_bar,escolhe_tipo,jogador,adversario,40,display,apontador,fundo_carta,fundo_menu,deck_meio,deck_cheio,fundo,font,font2,color,fim_de_jogo,rolagem,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);
    else if(strcmp(str,"Summon / Equip 50 ") == 0) ativo = PlayCard(str,buffer,3,id_acao,sbox,prompt,selecao,lock,roll_bar,escolhe_tipo,jogador,adversario,50,display,apontador,fundo_carta,fundo_menu,deck_meio,deck_cheio,fundo,font,font2,color,fim_de_jogo,rolagem,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);
    else if(strcmp(str,"Summon / Equip 60 ") == 0) ativo = PlayCard(str,buffer,3,id_acao,sbox,prompt,selecao,lock,roll_bar,escolhe_tipo,jogador,adversario,60,display,apontador,fundo_carta,fundo_menu,deck_meio,deck_cheio,fundo,font,font2,color,fim_de_jogo,rolagem,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);
    else if(strcmp(str,"Summon / Equip 70 ") == 0) ativo = PlayCard(str,buffer,3,id_acao,sbox,prompt,selecao,lock,roll_bar,escolhe_tipo,jogador,adversario,70,display,apontador,fundo_carta,fundo_menu,deck_meio,deck_cheio,fundo,font,font2,color,fim_de_jogo,rolagem,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);
    else if(strcmp(str,"Summon / Equip 80 ") == 0) ativo = PlayCard(str,buffer,3,id_acao,sbox,prompt,selecao,lock,roll_bar,escolhe_tipo,jogador,adversario,80,display,apontador,fundo_carta,fundo_menu,deck_meio,deck_cheio,fundo,font,font2,color,fim_de_jogo,rolagem,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);
    else if(strcmp(str,"Summon / Equip 90 ") == 0) ativo = PlayCard(str,buffer,3,id_acao,sbox,prompt,selecao,lock,roll_bar,escolhe_tipo,jogador,adversario,90,display,apontador,fundo_carta,fundo_menu,deck_meio,deck_cheio,fundo,font,font2,color,fim_de_jogo,rolagem,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);
    else if(strcmp(str,"Summon / Equip 120 ") == 0) ativo = PlayCard(str,buffer,3,id_acao,sbox,prompt,selecao,lock,roll_bar,escolhe_tipo,jogador,adversario,120,display,apontador,fundo_carta,fundo_menu,deck_meio,deck_cheio,fundo,font,font2,color,fim_de_jogo,rolagem,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);
    else if(strcmp(str,"Summon / Locate 50 ") == 0) ativo = PlayCard(str,buffer,9,id_acao,sbox,prompt,selecao,lock,roll_bar,escolhe_tipo,jogador,adversario,50,display,apontador,fundo_carta,fundo_menu,deck_meio,deck_cheio,fundo,font,font2,color,fim_de_jogo,rolagem,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);
    else if(strcmp(str,"Summon / Locate 120 ") == 0) ativo = PlayCard(str,buffer,9,id_acao,sbox,prompt,selecao,lock,roll_bar,escolhe_tipo,jogador,adversario,120,display,apontador,fundo_carta,fundo_menu,deck_meio,deck_cheio,fundo,font,font2,color,fim_de_jogo,rolagem,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);
    else if(strcmp(str,"Summon / Locate X ") == 0) ativo = PlayCard(str,buffer,9,id_acao,sbox,prompt,selecao,lock,roll_bar,escolhe_tipo,jogador,adversario,jogador->level,display,apontador,fundo_carta,fundo_menu,deck_meio,deck_cheio,fundo,font,font2,color,fim_de_jogo,rolagem,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);
    else if(strcmp(str,"Summon / Rapid Action 30 ") == 0) ativo = PlayCard(str,buffer,5,id_acao,sbox,prompt,selecao,lock,roll_bar,escolhe_tipo,jogador,adversario,30,display,apontador,fundo_carta,fundo_menu,deck_meio,deck_cheio,fundo,font,font2,color,fim_de_jogo,rolagem,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);
    else if(strcmp(str,"Summon / Rapid Action 40 ") == 0) ativo = PlayCard(str,buffer,5,id_acao,sbox,prompt,selecao,lock,roll_bar,escolhe_tipo,jogador,adversario,40,display,apontador,fundo_carta,fundo_menu,deck_meio,deck_cheio,fundo,font,font2,color,fim_de_jogo,rolagem,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);
    else if(strcmp(str,"Summon / Rapid Action 50 ") == 0) ativo = PlayCard(str,buffer,5,id_acao,sbox,prompt,selecao,lock,roll_bar,escolhe_tipo,jogador,adversario,50,display,apontador,fundo_carta,fundo_menu,deck_meio,deck_cheio,fundo,font,font2,color,fim_de_jogo,rolagem,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);
    else if(strcmp(str,"Summon / Rapid Action 60 ") == 0) ativo = PlayCard(str,buffer,5,id_acao,sbox,prompt,selecao,lock,roll_bar,escolhe_tipo,jogador,adversario,60,display,apontador,fundo_carta,fundo_menu,deck_meio,deck_cheio,fundo,font,font2,color,fim_de_jogo,rolagem,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);
    else if(strcmp(str,"Summon / Rapid Action 70 ") == 0) ativo = PlayCard(str,buffer,5,id_acao,sbox,prompt,selecao,lock,roll_bar,escolhe_tipo,jogador,adversario,70,display,apontador,fundo_carta,fundo_menu,deck_meio,deck_cheio,fundo,font,font2,color,fim_de_jogo,rolagem,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);
    else if(strcmp(str,"Summon / Locate 60 ") == 0) ativo = PlayCard(str,buffer,9,id_acao,sbox,prompt,selecao,lock,roll_bar,escolhe_tipo,jogador,adversario,60,display,apontador,fundo_carta,fundo_menu,deck_meio,deck_cheio,fundo,font,font2,color,fim_de_jogo,rolagem,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);
    else if(strcmp(str,"Summon / Locate 70 ") == 0) ativo = PlayCard(str,buffer,9,id_acao,sbox,prompt,selecao,lock,roll_bar,escolhe_tipo,jogador,adversario,70,display,apontador,fundo_carta,fundo_menu,deck_meio,deck_cheio,fundo,font,font2,color,fim_de_jogo,rolagem,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);
    else if(strcmp(str,"Summon / Rapid Action / Locate 60 ") == 0) ativo = PlayCard(str,buffer,13,id_acao,sbox,prompt,selecao,lock,roll_bar,escolhe_tipo,jogador,adversario,60,display,apontador,fundo_carta,fundo_menu,deck_meio,deck_cheio,fundo,font,font2,color,fim_de_jogo,rolagem,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);
    else if(strcmp(str,"Equip / Rapid Action 50 ") == 0) ativo = PlayCard(str,buffer,6,id_acao,sbox,prompt,selecao,lock,roll_bar,escolhe_tipo,jogador,adversario,50,display,apontador,fundo_carta,fundo_menu,deck_meio,deck_cheio,fundo,font,font2,color,fim_de_jogo,rolagem,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);
    else if(strcmp(str,"Equip / Rapid Action 60 ") == 0) ativo = PlayCard(str,buffer,6,id_acao,sbox,prompt,selecao,lock,roll_bar,escolhe_tipo,jogador,adversario,60,display,apontador,fundo_carta,fundo_menu,deck_meio,deck_cheio,fundo,font,font2,color,fim_de_jogo,rolagem,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);
    else if(strcmp(str,"Equip / Rapid Action 70 ") == 0) ativo = PlayCard(str,buffer,6,id_acao,sbox,prompt,selecao,lock,roll_bar,escolhe_tipo,jogador,adversario,70,display,apontador,fundo_carta,fundo_menu,deck_meio,deck_cheio,fundo,font,font2,color,fim_de_jogo,rolagem,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);
    else if(strcmp(str,"Equip / Locate 60 ") == 0) ativo = PlayCard(str,buffer,10,id_acao,sbox,prompt,selecao,lock,roll_bar,escolhe_tipo,jogador,adversario,60,display,apontador,fundo_carta,fundo_menu,deck_meio,deck_cheio,fundo,font,font2,color,fim_de_jogo,rolagem,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);
    else if(strcmp(str,"Equip / Locate 80 ") == 0) ativo = PlayCard(str,buffer,10,id_acao,sbox,prompt,selecao,lock,roll_bar,escolhe_tipo,jogador,adversario,80,display,apontador,fundo_carta,fundo_menu,deck_meio,deck_cheio,fundo,font,font2,color,fim_de_jogo,rolagem,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);
    else if(strcmp(str,"Equip / Locate X ") == 0) ativo = PlayCard(str,buffer,10,id_acao,sbox,prompt,selecao,lock,roll_bar,escolhe_tipo,jogador,adversario,jogador->level,display,apontador,fundo_carta,fundo_menu,deck_meio,deck_cheio,fundo,font,font2,color,fim_de_jogo,rolagem,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);

    else if(strcmp(str,"Crafty 50 ") == 0) ativo = PlayCard(str,buffer,15,id_acao,sbox,prompt,selecao,lock,roll_bar,escolhe_tipo,jogador,adversario,50,display,apontador,fundo_carta,fundo_menu,deck_meio,deck_cheio,fundo,font,font2,color,fim_de_jogo,rolagem,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);
    else if(strcmp(str,"Crafty 70 ") == 0) ativo = PlayCard(str,buffer,15,id_acao,sbox,prompt,selecao,lock,roll_bar,escolhe_tipo,jogador,adversario,70,display,apontador,fundo_carta,fundo_menu,deck_meio,deck_cheio,fundo,font,font2,color,fim_de_jogo,rolagem,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);

    else if(strcmp(str,"Wave Blast ") == 0) ativo = king_zora_acao3(id_acao,buffer,fim_de_jogo,rolagem,&ko,sbox,jogador,adversario,display,prompt,selecao,roll_bar,fundo_carta,fundo_menu,deck_meio,deck_cheio,fundo,font,font2,color,apontador,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);
    else if(strcmp(str,"Startle ") == 0) ativo = impa_acao3(id_acao,buffer,fim_de_jogo,rolagem,sbox,prompt,selecao,roll_bar,fundo_carta,fundo_menu,deck_meio,deck_cheio,apontador,jogador,adversario,display,fundo,font,font2,color,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);
    else if(strcmp(str,"Magic Blast ") == 0) ativo = princess_zelda_acao2(id_acao,buffer,fim_de_jogo,rolagem,&ko,sbox,jogador,adversario,display,prompt,selecao,roll_bar,fundo_carta,fundo_menu,deck_meio,deck_cheio,fundo,font,font2,color,apontador,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);
    else if(strcmp(str,"Warlock Punch ") == 0) ativo = ganondorf_acao2(id_acao,buffer,fim_de_jogo,rolagem,&ko,sbox,jogador,adversario,display,prompt,selecao,roll_bar,fundo_carta,fundo_menu,deck_meio,deck_cheio,fundo,font,font2,color,apontador,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);
    else if(strcmp(str,"Combo Hit ") == 0) ativo = channeled_strike_lvacao(id_acao,buffer,fim_de_jogo,rolagem,&ko,sbox,jogador,adversario,display,prompt,selecao,roll_bar,fundo_carta,fundo_menu,deck_meio,deck_cheio,fundo,font,font2,color,apontador,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);

    else if(strcmp(str,"Swim Mastery ") == 0) jogador->var_tactic->princess_ruto_bool = true;
    else if(strcmp(str,"Fairy PowerUP ") == 0) jogador->var_tactic->mido_bool = true;
    else if(strcmp(str,"Shadow Leader ") == 0) jogador->var_tactic->ganondorf_bool = true;
    else if(strcmp(str,"Light Nova ") == 0) golden_gauntlets_lvacao(id_acao,buffer,card_origem,rolagem,sbox,selecao,lock,roll_bar,prompt,fim_de_jogo,fundo_carta,fundo_menu,deck_meio,deck_cheio,jogador,adversario,display,fundo,font,font2,color,apontador,timer,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);
    else if(strcmp(str,"Roar ") == 0) darunia_acao(jogador);

    else {
        printf("UNHANDLED ACTION: '%s'\n", str);
    }

    free(str);
    return(ativo);
}

void princess_ruto_acao(int id_acao,struct Card **buffer,int *rolagem,struct StatusBox_bitmaps *sbox,ALLEGRO_BITMAP *selecao,ALLEGRO_BITMAP *lock,ALLEGRO_BITMAP *roll_bar,ALLEGRO_BITMAP *prompt,bool *fim_de_jogo,ALLEGRO_BITMAP *fundo_carta,ALLEGRO_BITMAP *fundo_menu,ALLEGRO_BITMAP *deck_meio,ALLEGRO_BITMAP *deck_cheio,struct Player *jogador,struct Player *adversario,ALLEGRO_DISPLAY *display,ALLEGRO_BITMAP *fundo,ALLEGRO_FONT *font,ALLEGRO_FONT *font2,ALLEGRO_COLOR color,ALLEGRO_BITMAP *apontador,ALLEGRO_BITMAP *escolhe_tipo,struct VariaveisTACTIC *tactics,ALLEGRO_TIMER *timer,bool *sair,int *posX,int *posY,int *dltZ,bool *mouse,bool *mouse2,bool *mouse_lado,int *keychar,bool *repete_keychar,ALLEGRO_EVENT_QUEUE *event_queue,ALLEGRO_TIMER *keyb_press_timer,ALLEGRO_TIMER *mouse_press_timer) {
    struct Deck *escolhido,*lista,*aux;
    struct char_action *aux2;

    Menu_Cria(&lista,&aux);

    aux2 = jogador->character_actions->prox->prox->prox;
    while(aux2->prox != NULL) {
        if(jogador->level >= aux2->nivel &&
           ((!strcmp(aux2->card->origem->elemento,"Earth") && jogador->earth_ic >= aux2->atrib) ||
            (!strcmp(aux2->card->origem->elemento,"Wind") && jogador->wind_ic >= aux2->atrib) ||
            (!strcmp(aux2->card->origem->elemento,"Fire") && jogador->fire_ic >= aux2->atrib) ||
            (!strcmp(aux2->card->origem->elemento,"Water") && jogador->water_ic >= aux2->atrib) ||
            (!strcmp(aux2->card->origem->elemento,"Dark") && jogador->dark_ic >= aux2->atrib) ||
            (!strcmp(aux2->card->origem->elemento,"Light") && jogador->light_ic >= aux2->atrib)))
            {
                Menu_CopiaDado(&aux,aux2->card);
            }

        aux2 = aux2->prox;
    }
    Menu_CelulaFinal(&aux);

    escolhido = MenuCards("Select a card to use its LEVEL-UP EFFECT.",true,lista,fim_de_jogo,jogador,display,prompt,selecao,roll_bar,fundo_carta,fundo_menu,fundo,font2,font,color,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);
    if(escolhido != NULL) {
        DetectaAcao(escolhido->card->origem->lv_acao->acao,id_acao,buffer,jogador->mesa->character,rolagem,sbox,selecao,lock,roll_bar,prompt,fim_de_jogo,fundo_carta,fundo_menu,deck_meio,deck_cheio,jogador,adversario,display,fundo,font,font2,color,apontador,escolhe_tipo,jogador->var_tactic,timer,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);
    }

    Menu_Finaliza(lista);
}

#endif // BASICO_C_INCLUDED
