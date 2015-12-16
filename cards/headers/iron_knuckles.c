#ifndef IRON_KNUCKLES_H_INCLUDED
#define IRON_KNUCKLES_H_INCLUDED

void iron_knuckles(struct Card *card) {
        card->bmp = al_load_bitmap("cards/iron_knuckles.png");
        card->nome = "Iron Knuckles\0";
        card->elemento = "Dark\0";
        card->colecao = 126;
        card->RARIDADE = 1;
        card->preco = 830;
        card->tipo = "Monster\0";
        card->str_concat = "Dark - Monster - Armored Warrior\0";

        card->monster = (struct monster *)malloc(sizeof(struct monster));
        card->monster->acao = "Enraged - Whenever your opponent plays a card on the field, do 20 damage to a character or a monster.\0";
        card->monster->level = 68;
        card->monster->attack = 40;
        card->monster->MaxHP = 60;

        card->boss = NULL;
        card->character = NULL;
        card->field = NULL;
        card->jrboss = NULL;
        card->equip = NULL;
        card->tactic = NULL;

        card->lv_acao = (struct char_action *)malloc(sizeof(struct char_action));
        card->lv_acao->acao = "Summon / Equip 70 - Play a monster or an equipment of level 70 or less.\0";
        card->lv_acao->nivel = 70;
        card->lv_acao->atrib = 2;

        card->lv_acao->ant = NULL;
        card->lv_acao->prox = NULL;
}

#endif // IRON_KNUCKLES_H_INCLUDED
