#ifndef GUILLOTINE_H_INCLUDED
#define GUILLOTINE_H_INCLUDED

void guillotine(struct Card *card) {
        card->bmp = al_load_bitmap("cards/guillotine.png");
        card->nome = "Guillotine\0";
        card->elemento = "Dark\0";
        card->colecao = 85;
        card->RARIDADE = 7;
        card->preco = 795;
        card->tipo = "Tactic\0";
        card->str_concat = "Dark - Tactic - Strategy\0";

        card->tactic = (struct tactic *)malloc(sizeof(struct tactic));
        card->tactic->acao = "Pick one of these actions: Inflict 40 damage to a character OR destroy up to 2 monsters.\0";
        card->tactic->level = 55;

        card->boss = NULL;
        card->equip = NULL;
        card->field = NULL;
        card->jrboss = NULL;
        card->monster = NULL;
        card->character = NULL;

        card->lv_acao = (struct char_action *)malloc(sizeof(struct char_action));
        card->lv_acao->acao = "Drink Potion - Recover HP equals to your level.\0";
        card->lv_acao->nivel = 999;
        card->lv_acao->atrib = 0;

        card->lv_acao->ant = NULL;
        card->lv_acao->prox = NULL;
}

#endif // GUILLOTINE_H_INCLUDED
