#ifndef GOLDEN_SCALE_H_INCLUDED
#define GOLDEN_SCALE_H_INCLUDED

void golden_scale(struct Card *card) {
        card->bmp = al_load_bitmap("cards/golden_scale.png");
        card->nome = "Golden Scale\0";
        card->elemento = "Water\0";
        card->colecao = 16;
        card->RARIDADE = 7;
        card->preco = 1100;
        card->tipo = "Equipment\0";
        card->str_concat = "Water - Equipment - Scale\0";

        card->equip = (struct equipment *)malloc(sizeof(struct equipment));
        card->equip->acao = "Get +10 damage with your WATER monsters. If there is a WATER field on the table, get +10 damage with your character actions.\0";
        card->equip->level = 55;

        card->boss = NULL;
        card->character = NULL;
        card->field = NULL;
        card->jrboss = NULL;
        card->monster = NULL;
        card->tactic = NULL;

        card->lv_acao = (struct char_action *)malloc(sizeof(struct char_action));
        card->lv_acao->acao = "Equip 70 - Play an equipment of level 70 or less.\0";
        card->lv_acao->nivel = 60;
        card->lv_acao->atrib = 2;

        card->lv_acao->ant = NULL;
        card->lv_acao->prox = NULL;
}

void efeito_gs_equip(struct CARD *equip,int *damage) {
    if(equip != NULL && equip->origem->colecao == GOLDEN_SCALE) *damage = *damage + 10;
}

void golden_scale_acao(struct Player *jogador,int *damage) {
    efeito_gs_equip(jogador->mesa->equip1,damage);
    efeito_gs_equip(jogador->mesa->equip2,damage);
    efeito_gs_equip(jogador->mesa->equip3,damage);
    efeito_gs_equip(jogador->mesa->equip4,damage);
    efeito_gs_equip(jogador->mesa->equip5,damage);
    efeito_gs_equip(jogador->mesa->equip6,damage);
    efeito_gs_equip(jogador->mesa->equip7,damage);
}

#endif // GOLDEN_SCALE_H_INCLUDED
