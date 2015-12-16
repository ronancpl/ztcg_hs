#ifndef GORON_TUNIC_H_INCLUDED
#define GORON_TUNIC_H_INCLUDED

void goron_tunic(struct Card *card) {     //ja deve vir alocado!
        card->bmp = al_load_bitmap("cards/goron_tunic.png");
        card->nome = "Goron Tunic\0";
        card->elemento = "Fire\0";
        card->colecao = 4;
        card->RARIDADE = 3;
        card->preco = 1400;
        card->tipo = "Equipment\0";
        card->str_concat = "Fire - Equipment - Armor\0";

        card->equip = (struct equipment *)malloc(sizeof(struct equipment));
        card->equip->acao = "Block 10 damage from monster and character attacks aimed to your character. Get +40 maxHP and heal 50 HP (the heal effect can be used only at the turn Goron Tunic is activated).\0";
        card->equip->level = 65;

        card->boss = NULL;
        card->character = NULL;
        card->field = NULL;
        card->jrboss = NULL;
        card->monster = NULL;
        card->tactic = NULL;

        card->lv_acao = (struct char_action *)malloc(sizeof(struct char_action));
        card->lv_acao->acao = "Equip / Rapid Action / Locate 80 - Play an equipment or a tactic of level 80 or less or a field card.\0";
        card->lv_acao->nivel = 60;
        card->lv_acao->atrib = 3;

        card->lv_acao->ant = NULL;
        card->lv_acao->prox = NULL;
}

#endif // GORON_TUNIC_H_INCLUDED
