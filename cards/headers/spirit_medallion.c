#ifndef SPIRIT_MEDALLION_H_INCLUDED
#define SPIRIT_MEDALLION_H_INCLUDED

void spirit_medallion(struct Card *card) {
        card->bmp = al_load_bitmap("cards/spirit_medallion.png");
        card->nome = "Spirit Medallion\0";
        card->elemento = "Wind\0";
        card->colecao = 25;
        card->RARIDADE = 7;
        card->preco = 770;
        card->tipo = "Tactic\0";
        card->str_concat = "Wind - Tactic - Power-UP Item\0";

        card->tactic = (struct tactic *)malloc(sizeof(struct tactic));
        card->tactic->acao = "During the whole turn this card is activated, all WIND monsters have its attack and HP enhanced by 10 and 20, respectively.\0";
        card->tactic->level = 50;

        card->boss = NULL;
        card->equip = NULL;
        card->field = NULL;
        card->jrboss = NULL;
        card->monster = NULL;
        card->character = NULL;

        card->lv_acao = (struct char_action *)malloc(sizeof(struct char_action));
        card->lv_acao->acao = "Air Strike - Do 20 damage to a character or a monster.\0";
        card->lv_acao->nivel = 70;
        card->lv_acao->atrib = 2;

        card->lv_acao->ant = NULL;
        card->lv_acao->prox = NULL;
}

void efeito_sm_monstro(struct CARD *card,int instancias) {
    if(card != NULL && strcmp(card->origem->elemento,"Wind") == 0) {
        card->HP = card->HP + (20 * instancias);
        card->MaxHP = card->MaxHP + (20 * instancias);
    }
}

void spirit_medallion_acao(struct Player *jogador,struct Player *adversario,int instancias) {
    printf("BUFF: Spirit Medallion x %d",instancias);

    efeito_sm_monstro(jogador->mesa->monstro1,instancias);
    efeito_sm_monstro(jogador->mesa->monstro2,instancias);
    efeito_sm_monstro(jogador->mesa->monstro3,instancias);
    efeito_sm_monstro(jogador->mesa->monstro4,instancias);
    efeito_sm_monstro(jogador->mesa->monstro5,instancias);
    efeito_sm_monstro(jogador->mesa->monstro6,instancias);
    efeito_sm_monstro(jogador->mesa->monstro7,instancias);

    efeito_sm_monstro(adversario->mesa->monstro1,instancias);
    efeito_sm_monstro(adversario->mesa->monstro2,instancias);
    efeito_sm_monstro(adversario->mesa->monstro3,instancias);
    efeito_sm_monstro(adversario->mesa->monstro4,instancias);
    efeito_sm_monstro(adversario->mesa->monstro5,instancias);
    efeito_sm_monstro(adversario->mesa->monstro6,instancias);
    efeito_sm_monstro(adversario->mesa->monstro7,instancias);
}

void desfaz_efeito_sm_monstro(struct CARD *card,int instancias) {
    if(card != NULL && strcmp(card->origem->elemento,"Wind") == 0) {
        card->HP = card->HP - (20 * instancias);
        if(card->HP <= 0) card->HP = 0;
        card->MaxHP = card->MaxHP - (20 * instancias);
    }
}

void desfaz_spirit_medallion_acao(struct Player *jogador,struct Player *adversario,int instancias) {
    desfaz_efeito_sm_monstro(jogador->mesa->monstro1,instancias);
    desfaz_efeito_sm_monstro(jogador->mesa->monstro2,instancias);
    desfaz_efeito_sm_monstro(jogador->mesa->monstro3,instancias);
    desfaz_efeito_sm_monstro(jogador->mesa->monstro4,instancias);
    desfaz_efeito_sm_monstro(jogador->mesa->monstro5,instancias);
    desfaz_efeito_sm_monstro(jogador->mesa->monstro6,instancias);
    desfaz_efeito_sm_monstro(jogador->mesa->monstro7,instancias);

    desfaz_efeito_sm_monstro(adversario->mesa->monstro1,instancias);
    desfaz_efeito_sm_monstro(adversario->mesa->monstro2,instancias);
    desfaz_efeito_sm_monstro(adversario->mesa->monstro3,instancias);
    desfaz_efeito_sm_monstro(adversario->mesa->monstro4,instancias);
    desfaz_efeito_sm_monstro(adversario->mesa->monstro5,instancias);
    desfaz_efeito_sm_monstro(adversario->mesa->monstro6,instancias);
    desfaz_efeito_sm_monstro(adversario->mesa->monstro7,instancias);
}

#endif // SPIRIT_MEDALLION_H_INCLUDED
