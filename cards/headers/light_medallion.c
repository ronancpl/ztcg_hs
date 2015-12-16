#ifndef LIGHT_MEDALLION_H_INCLUDED
#define LIGHT_MEDALLION_H_INCLUDED

void light_medallion(struct Card *card) {
        card->bmp = al_load_bitmap("cards/light_medallion.png");
        card->nome = "Light Medallion\0";
        card->elemento = "Light\0";
        card->colecao = 113;
        card->RARIDADE = 7;
        card->preco = 840;
        card->tipo = "Tactic\0";
        card->str_concat = "Light - Tactic - Power-UP Item\0";

        card->tactic = (struct tactic *)malloc(sizeof(struct tactic));
        card->tactic->acao = "During the whole turn this card is activated, all LIGHT monsters have its attack enhanced by 20. Draw a card.\0";
        card->tactic->level = 60;

        card->boss = NULL;
        card->equip = NULL;
        card->field = NULL;
        card->jrboss = NULL;
        card->monster = NULL;
        card->character = NULL;

        card->lv_acao = (struct char_action *)malloc(sizeof(struct char_action));
        card->lv_acao->acao = "Bright Strike - Do 20 damage to a monster.\0";
        card->lv_acao->nivel = 50;
        card->lv_acao->atrib = 2;

        card->lv_acao->ant = NULL;
        card->lv_acao->prox = NULL;
}

#endif // LIGHT_MEDALLION_H_INCLUDED
