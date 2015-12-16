#ifndef TORCH_SLUG_H_INCLUDED
#define TORCH_SLUG_H_INCLUDED

void torch_slug(struct Card *card) {
        card->bmp = al_load_bitmap("cards/torch_slug.png");
        card->nome = "Torch Slug\0";
        card->elemento = "Fire\0";
        card->colecao = 80;
        card->RARIDADE = 7;
        card->preco = 400;
        card->tipo = "Monster\0";
        card->str_concat = "Fire - Monster - Snail\0";

        card->monster = (struct monster *)malloc(sizeof(struct monster));
        card->monster->acao = "\0";
        card->monster->level = 18;
        card->monster->attack = 10;
        card->monster->MaxHP = 30;

        card->boss = NULL;
        card->character = NULL;
        card->field = NULL;
        card->jrboss = NULL;
        card->equip = NULL;
        card->tactic = NULL;

        card->lv_acao = (struct char_action *)malloc(sizeof(struct char_action));
        card->lv_acao->acao = "Summon / Rapid Action 30 - Play a monster or a tactic of level 30 or less.\0";
        card->lv_acao->nivel = 20;
        card->lv_acao->atrib = 2;

        card->lv_acao->ant = NULL;
        card->lv_acao->prox = NULL;
}

#endif // JOELLE_H_INCLUDED
