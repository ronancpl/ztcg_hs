#ifndef GREAT_FAIRYS_BLESS_H_INCLUDED
#define GREAT_FAIRYS_BLESS_H_INCLUDED

void great_fairys_bless(struct Card *card) {
        card->bmp = al_load_bitmap("cards/great_fairys_bless.png");
        card->nome = "Great_Fairys Bless\0";
        card->elemento = "Light\0";
        card->colecao = 148;
        card->RARIDADE = 3;
        card->preco = 1090;
        card->tipo = "Tactic\0";
        card->str_concat = "Light - Tactic - Recovery\0";

        card->tactic = (struct tactic *)malloc(sizeof(struct tactic));
        card->tactic->acao = "Heal 100 HP, and boost the next monster attack with +20 damage the turn this card is activated.\0";
        card->tactic->level = 57;

        card->boss = NULL;
        card->equip = NULL;
        card->field = NULL;
        card->jrboss = NULL;
        card->monster = NULL;
        card->character = NULL;

        card->lv_acao = (struct char_action *)malloc(sizeof(struct char_action));
        card->lv_acao->acao = "Summon X - Play a monster of your level or less.\0";
        card->lv_acao->nivel = 50;
        card->lv_acao->atrib = 3;

        card->lv_acao->ant = NULL;
        card->lv_acao->prox = NULL;
}

void great_fairys_bless_tactic(int *attack,short int *valor,bool aplicavel) {
    printf("BUFF: GREAT FAIRYS BLESS TACTIC x %d\n",*valor);
    *attack = *attack + (*valor * 20);
    if(aplicavel) *valor = 0;
}

#endif // GREAT_FAIRYS_BLESS_H_INCLUDED
