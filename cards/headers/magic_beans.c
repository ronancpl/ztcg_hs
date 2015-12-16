#ifndef MAGIC_BEANS_H_INCLUDED
#define MAGIC_BEANS_H_INCLUDED

void magic_beans(struct Card *card) {
        card->bmp = al_load_bitmap("cards/magic_beans.png");
        card->nome = "Magic Beans\0";
        card->elemento = "Light\0";
        card->colecao = 56;
        card->RARIDADE = 7;
        card->preco = 530;
        card->tipo = "Equipment\0";
        card->str_concat = "Light - Equipment - Bean\0";

        card->equip = (struct equipment *)malloc(sizeof(struct equipment));
        card->equip->acao = "Get +20 HP at the end of a turn and +10 damage with your character actions next turn if your didnt play a monster or equipment in a turn.\0";
        card->equip->level = 10;

        card->boss = NULL;
        card->character = NULL;
        card->field = NULL;
        card->jrboss = NULL;
        card->monster = NULL;
        card->tactic = NULL;

        card->lv_acao = (struct char_action *)malloc(sizeof(struct char_action));
        card->lv_acao->acao = "Flash Strike - Do 30 damage to a character.\0";
        card->lv_acao->nivel = 60;
        card->lv_acao->atrib = 3;

        card->lv_acao->ant = NULL;
        card->lv_acao->prox = NULL;
}

#endif // MAGIC_BEANS_H_INCLUDED
