#ifndef WORLDS_FINEST_EYE_DROPS_H_INCLUDED
#define WORLDS_FINEST_EYE_DROPS_H_INCLUDED

void worlds_finest_eye_drops(struct Card *card) {
        card->bmp = al_load_bitmap("cards/worlds_finest_eye_drops.png");
        card->nome = "Worlds Finest Eye Drops\0";
        card->elemento = "Water\0";
        card->colecao = 96;
        card->RARIDADE = 7;
        card->preco = 640;
        card->tipo = "Equipment\0";
        card->str_concat = "Water - Equipment - Pain Reliever\0";

        card->equip = (struct equipment *)malloc(sizeof(struct equipment));
        card->equip->acao = "Whenever your character is targeted by a attack, recover +10 HP.\0";
        card->equip->level = 33;

        card->boss = NULL;
        card->character = NULL;
        card->field = NULL;
        card->jrboss = NULL;
        card->monster = NULL;
        card->tactic = NULL;

        card->lv_acao = (struct char_action *)malloc(sizeof(struct char_action));
        card->lv_acao->acao = "Monster Resurrection - Retrieve a monster of level 50 or above from your graveyard and play it if its the same level of yours or less.\0";
        card->lv_acao->nivel = 999;
        card->lv_acao->atrib = 0;

        card->lv_acao->ant = NULL;
        card->lv_acao->prox = NULL;
}

#endif // WORLDS_FINEST_EYE_DROPS_H_INCLUDED
