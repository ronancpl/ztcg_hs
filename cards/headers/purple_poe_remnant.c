#ifndef PURPLE_POE_REMNANT_H_INCLUDED
#define PURPLE_POE_REMNANT_H_INCLUDED

void purple_poe_remnant(struct Card *card) {
        card->bmp = al_load_bitmap("cards/purple_poe_remnant.png");
        card->nome = "Purple Poe Remnant\0";
        card->elemento = "Dark\0";
        card->colecao = 135;
        card->RARIDADE = 1;
        card->preco = 1730;
        card->tipo = "Equipment\0";
        card->str_concat = "Dark - Equipment - Soul\0";

        card->equip = (struct equipment *)malloc(sizeof(struct equipment));
        card->equip->acao = "Do an extra attack instance at the end of your character action phase with damage equals to 20 x number of monsters you have deployed on the field.\0";
        card->equip->level = 50;

        card->boss = NULL;
        card->character = NULL;
        card->field = NULL;
        card->jrboss = NULL;
        card->monster = NULL;
        card->tactic = NULL;

        card->lv_acao = (struct char_action *)malloc(sizeof(struct char_action));
        card->lv_acao->acao = "Summon / Locate X - Play a monster of your level or less or a field card.\0";
        card->lv_acao->nivel = 50;
        card->lv_acao->atrib = 3;

        card->lv_acao->ant = NULL;
        card->lv_acao->prox = NULL;
}

#endif // PURPLE_POE_REMNANT_H_INCLUDED
