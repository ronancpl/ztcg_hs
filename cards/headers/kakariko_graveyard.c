#ifndef KAKARIKO_GRAVEYARD_H_INCLUDED
#define KAKARIKO_GRAVEYARD_H_INCLUDED

void kakariko_graveyard(struct Card *card) {     //ja deve vir alocado!
        card->bmp = al_load_bitmap("cards/kakariko_graveyard.png");
        card->nome = "Kakariko Graveyard\0";
        card->elemento = "Dark\0";
        card->colecao = 60;
        card->RARIDADE = 3;
        card->preco = 1000;
        card->tipo = "Field\0";
        card->str_concat = "Dark - Field - Kakariko Village\0";

        card->field = (struct field *)malloc(sizeof(struct field));
        card->field->acao = "Add +20 attack and +10 HP to each DARK monster in game. If your character is a DARK character, add +10 attack to each character actions, and block 10 damage for each opponent actions, effects limited up to as many DARK cards you have under your character.\0";

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

#endif // KAKARIKO_GRAVEYARD_H_INCLUDED
