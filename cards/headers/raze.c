#ifndef RAZE_H_INCLUDED
#define RAZE_H_INCLUDED

void raze(struct Card *card) {
        card->bmp = al_load_bitmap("cards/raze.png");
        card->nome = "Raze\0";
        card->elemento = "Fire\0";
        card->colecao = 73;
        card->RARIDADE = 1;
        card->preco = 1790;
        card->tipo = "Tactic\0";
        card->str_concat = "Fire - Tactic - Strategy\0";

        card->tactic = (struct tactic *)malloc(sizeof(struct tactic));
        card->tactic->acao = "Inflict 50 damage at all opponents monsters and character. Boost 20 attack damage with all FIRE monsters on the field for 2 turns.\0";
        card->tactic->level = 70;

        card->boss = NULL;
        card->equip = NULL;
        card->field = NULL;
        card->jrboss = NULL;
        card->monster = NULL;
        card->character = NULL;

        card->lv_acao = (struct char_action *)malloc(sizeof(struct char_action));
        card->lv_acao->acao = "Crafty 70 - Play a card of level 70 or less.\0";
        card->lv_acao->nivel = 80;
        card->lv_acao->atrib = 3;

        card->lv_acao->ant = NULL;
        card->lv_acao->prox = NULL;
}

void raze_bonusdmg(int *damage, struct Player *jogador) {
    struct InstanceSchedule *aux;

    aux = jogador->schedule;
    while(aux->prox != NULL) {
        if(!strcmp(aux->instance_id,"Raze")) (*damage) += 20;
        aux = aux->prox;
    }
}

#endif // RAZE_H_INCLUDED
