#ifndef SKULLTULAS_AMBUSH_H_INCLUDED
#define SKULLTULAS_AMBUSH_H_INCLUDED

void skulltulas_ambush(struct Card *card) {
        card->bmp = al_load_bitmap("cards/skulltulas_ambush.png");
        card->nome = "Skulltulas Ambush\0";
        card->elemento = "Dark\0";
        card->colecao = 48;
        card->RARIDADE = 1;
        card->preco = 2321;
        card->tipo = "Tactic\0";
        card->str_concat = "Dark - Tactic - Strategy\0";

        card->tactic = (struct tactic *)malloc(sizeof(struct tactic));
        card->tactic->acao = "Flip a coin. If you win, do damage equals your level to each monster and character of your opponent. Draw a card.\0";
        card->tactic->level = 30;

        card->boss = NULL;
        card->equip = NULL;
        card->field = NULL;
        card->jrboss = NULL;
        card->monster = NULL;
        card->character = NULL;

        card->lv_acao = (struct char_action *)malloc(sizeof(struct char_action));
        card->lv_acao->acao = "Shadow Blast - Do 10 damage to a character or a monster.\0";
        card->lv_acao->nivel = 30;
        card->lv_acao->atrib = 1;

        card->lv_acao->ant = NULL;
        card->lv_acao->prox = NULL;
}

#endif // SKULLTULAS_AMBUSH_H_INCLUDED
