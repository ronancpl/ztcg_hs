#ifndef DESERT_COLOSSUS_H_INCLUDED
#define DESERT_COLOSSUS_H_INCLUDED

void desert_colossus(struct Card *card) {     //ja deve vir alocado!
        card->bmp = al_load_bitmap("cards/desert_colossus.png");
        card->nome = "Desert Colossus\0";
        card->elemento = "Wind\0";
        card->colecao = 6;
        card->RARIDADE = 3;
        card->preco = 1000;
        card->tipo = "Field\0";
        card->str_concat = "Wind - Field - Haunted Lands\0";

        card->field = (struct field *)malloc(sizeof(struct field));
        card->field->acao = "Add +20 attack and +10 HP to each WIND monster in game. If your character is a WIND character, add +10 attack to each character actions, and block 10 damage for each opponent actions, effects limited up to as many WIND cards you have under your character.\0";

        card->boss = NULL;
        card->character = NULL;
        card->equip = NULL;
        card->jrboss = NULL;
        card->monster = NULL;
        card->tactic = NULL;

        card->lv_acao = (struct char_action *)malloc(sizeof(struct char_action));
        card->lv_acao->acao = "Locate - Play a field card.\0";
        card->lv_acao->nivel = 50;
        card->lv_acao->atrib = 3;

        card->lv_acao->ant = NULL;
        card->lv_acao->prox = NULL;
}

#endif // DESERT_COLOSSUS_H_INCLUDED
