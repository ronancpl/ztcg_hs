#ifndef ZORAS_SAPPHIRE_H_INCLUDED
#define ZORAS_SAPPHIRE_H_INCLUDED

void zoras_sapphire(struct Card *card) {
        card->bmp = al_load_bitmap("cards/zoras_sapphire.png");
        card->nome = "Zoras Sapphire\0";
        card->elemento = "Water\0";
        card->colecao = 52;
        card->RARIDADE = 7;
        card->preco = 1100;
        card->tipo = "Equipment\0";
        card->str_concat = "Water - Equipment - Jewel\0";

        card->equip = (struct equipment *)malloc(sizeof(struct equipment));
        card->equip->acao = "All WATER monsters gets +10 HP. Whenever you play a WATER monster, peek the top card of your deck; if its a monster draw it, otherwise put it back.\0";
        card->equip->level = 35;

        card->boss = NULL;
        card->character = NULL;
        card->field = NULL;
        card->jrboss = NULL;
        card->monster = NULL;
        card->tactic = NULL;

        card->lv_acao = (struct char_action *)malloc(sizeof(struct char_action));
        card->lv_acao->acao = "Summon / Rapid Action 40 - Play a monster or a tactic of level 40 or less.\0";
        card->lv_acao->nivel = 30;
        card->lv_acao->atrib = 2;

        card->lv_acao->ant = NULL;
        card->lv_acao->prox = NULL;
}

#endif // ZORAS_SAPPHIRE_H_INCLUDED
