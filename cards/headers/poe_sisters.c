#ifndef POE_SISTERS_H_INCLUDED
#define POE_SISTERS_H_INCLUDED

void poe_sisters(struct Card *card) {
        card->bmp = al_load_bitmap("cards/poe_sisters.png");
        card->nome = "Poe Sisters\0";
        card->elemento = "Light\0";
        card->colecao = 44;
        card->RARIDADE = 7;
        card->preco = 900;
        card->tipo = "Monster\0";
        card->str_concat = "Light - Monster - Ghost Monster\0";

        card->monster = (struct monster *)malloc(sizeof(struct monster));
        card->monster->acao = "Team Attack - When its HP drops to 20 or less, do instantly 30 damage to the attacker.\0";
        card->monster->level = 38;
        card->monster->attack = 10;
        card->monster->MaxHP = 30;

        card->boss = NULL;
        card->character = NULL;
        card->field = NULL;
        card->jrboss = NULL;
        card->equip = NULL;
        card->tactic = NULL;

        card->lv_acao = (struct char_action *)malloc(sizeof(struct char_action));
        card->lv_acao->acao = "Buff - Add +10 damage to each monster attack.\0";
        card->lv_acao->nivel = 50;
        card->lv_acao->atrib = 2;

        card->lv_acao->ant = NULL;
        card->lv_acao->prox = NULL;
}

#endif // POE_SISTERS_H_INCLUDED
