#ifndef MIRROR_SHIELD_H_INCLUDED
#define MIRROR_SHIELD_H_INCLUDED

void mirror_shield(struct Card *card) {
        card->bmp = al_load_bitmap("cards/mirror_shield.png");
        card->nome = "Mirror Shield\0";
        card->elemento = "Light\0";
        card->colecao = 117;
        card->RARIDADE = 3;
        card->preco = 1375;
        card->tipo = "Equipment\0";
        card->str_concat = "Light - Equipment - Shield\0";

        card->equip = (struct equipment *)malloc(sizeof(struct equipment));
        card->equip->acao = "For each attack instance aimed to your character, absorb (yet taking full damage) 1/3 of the damage inflicted. At the start of your turn, if 3 or more attacks have been absorbed, release and deal damage equals to all the damage absorbed to a character or monster.\0";
        card->equip->level = 65;

        card->boss = NULL;
        card->character = NULL;
        card->field = NULL;
        card->jrboss = NULL;
        card->monster = NULL;
        card->tactic = NULL;

        card->lv_acao = (struct char_action *)malloc(sizeof(struct char_action));
        card->lv_acao->acao = "Summon 80 - Play a monster of level 80 or less.\0";
        card->lv_acao->nivel = 70;
        card->lv_acao->atrib = 2;

        card->lv_acao->ant = NULL;
        card->lv_acao->prox = NULL;
}

#endif // MIRROR_SHIELD_H_INCLUDED
