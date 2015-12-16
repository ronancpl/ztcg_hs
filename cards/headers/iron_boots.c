#ifndef IRON_BOOTS_H_INCLUDED
#define IRON_BOOTS_H_INCLUDED

void iron_boots(struct Card *card) {
        card->bmp = al_load_bitmap("cards/iron_boots.png");
        card->nome = "Iron Boots\0";
        card->elemento = "Water\0";
        card->colecao = 116;
        card->RARIDADE = 1;
        card->preco = 1740;
        card->tipo = "Equipment\0";
        card->str_concat = "Water - Equipment - Shoes\0";

        card->equip = (struct equipment *)malloc(sizeof(struct equipment));
        card->equip->acao = "Relieve attacks aimed to your character above 30, reducing the damage inflicted to 30. However, your character will be able to perform up to 4 character actions per turn.\0";
        card->equip->level = 55;

        card->boss = NULL;
        card->character = NULL;
        card->field = NULL;
        card->jrboss = NULL;
        card->monster = NULL;
        card->tactic = NULL;

        card->lv_acao = (struct char_action *)malloc(sizeof(struct char_action));
        card->lv_acao->acao = "Equip / Rapid Action / Locate 60 - Play an equipment or a tactic of level 60 or less or a field card.\0";
        card->lv_acao->nivel = 60;
        card->lv_acao->atrib = 3;

        card->lv_acao->ant = NULL;
        card->lv_acao->prox = NULL;
}


#endif // IRON_BOOTS_H_INCLUDED
