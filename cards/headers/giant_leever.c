#ifndef GIANT_LEEVER_H_INCLUDED
#define GIANT_LEEVER_H_INCLUDED

void giant_leever(struct Card *card) {
        card->bmp = al_load_bitmap("cards/giant_leever.png");
        card->nome = "Giant Leever\0";
        card->elemento = "Fire\0";
        card->colecao = 106;
        card->RARIDADE = 3;
        card->preco = 1128;
        card->tipo = "Jr. Boss\0";
        card->str_concat = "Fire - Jr. Boss - Desert Worm\0";

        card->jrboss = (struct jrboss *)malloc(sizeof(struct jrboss));
        card->jrboss->level = 52;
        card->jrboss->attack = 10;
        card->jrboss->MaxHP = 40;

        card->jrboss->acao = (struct char_action *)malloc(sizeof(struct char_action));
        card->jrboss->acao->acao = "Leever Commando - All your Worm monsters gets +20 attack and +20 HP while Giant Leever remains on the field.\0";
        card->jrboss->acao->atrib = 0;
        card->jrboss->acao->nivel = 0;
        card->jrboss->acao->prox = (struct char_action *)malloc(sizeof(struct char_action));
        card->jrboss->acao->prox->acao = "\0";
        card->jrboss->acao->prox->atrib = 0;
        card->jrboss->acao->prox->nivel = 0;
        card->jrboss->acao->prox->prox = (struct char_action *)malloc(sizeof(struct char_action));
        card->jrboss->acao->prox->prox->prox = NULL;

        card->tactic = NULL;
        card->equip = NULL;
        card->field = NULL;
        card->boss = NULL;
        card->monster = NULL;
        card->character = NULL;

        card->lv_acao = (struct char_action *)malloc(sizeof(struct char_action));
        card->lv_acao->acao = "Summon / Equip 90 - Play a monster or an equipment of level 90 or less.\0";
        card->lv_acao->nivel = 70;
        card->lv_acao->atrib = 3;

        card->lv_acao->ant = NULL;
        card->lv_acao->prox = NULL;
}

void desfaz_gl_card(struct CARD *card) {
    if(card != NULL && strstr(card->origem->str_concat,"Worm") != NULL) {
        card->MaxHP = card->MaxHP - 20;
        card->HP = card->HP - 20;
        //card->attack = card->attack - 10;
    }
}

void desfaz_giant_leever_effect(struct Player *jogador) {
    desfaz_gl_card(jogador->mesa->monstro1);
    desfaz_gl_card(jogador->mesa->monstro2);
    desfaz_gl_card(jogador->mesa->monstro3);
    desfaz_gl_card(jogador->mesa->monstro4);
    desfaz_gl_card(jogador->mesa->monstro5);
    desfaz_gl_card(jogador->mesa->monstro6);
    desfaz_gl_card(jogador->mesa->monstro7);
}

void gl_card(struct CARD *card) {
    if(card != NULL && strstr(card->origem->str_concat,"Worm") != NULL) {
        printf("proccing ON CARD on '%s'\n",card->origem->nome);
        card->MaxHP = card->MaxHP + 20;
        card->HP = card->HP + 20;
    }
}

void giant_leever_effect(struct Player *jogador) {
    gl_card(jogador->mesa->monstro1);
    gl_card(jogador->mesa->monstro2);
    gl_card(jogador->mesa->monstro3);
    gl_card(jogador->mesa->monstro4);
    gl_card(jogador->mesa->monstro5);
    gl_card(jogador->mesa->monstro6);
    gl_card(jogador->mesa->monstro7);
}

void giant_leever_acao(struct CARD *card,struct Player *player) { //somente ao colocar card em campo.
    if(strstr(card->origem->str_concat,"Worm") != NULL && GLpresente(player)) {
        card->MaxHP = card->MaxHP + 20;
        card->HP = card->HP + 20;
    }
}

#endif // GIANT_LEEVER_H_INCLUDED
