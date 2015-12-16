#ifndef BLESS_OF_TRIFORCE_H_INCLUDED
#define BLESS_OF_TRIFORCE_H_INCLUDED

void bless_of_triforce(struct Card *card) {
        card->bmp = al_load_bitmap("cards/bless_of_triforce.png");
        card->nome = "Bless of Triforce\0";

        card->elemento = "Light\0";
        card->colecao = 47;
        card->RARIDADE = 1;
        card->preco = 1777;
        card->tipo = "Tactic\0";
        card->str_concat = "Light - Tactic - Strategy\0";

        card->tactic = (struct tactic *)malloc(sizeof(struct tactic));
        card->tactic->acao = "Do 80 damage to a character or monster. Get +80 HP. All monsters that are on field when this tactic is activated gets +30 attack and +20 HP until your next turn starts. Character actions of both characters are increased by 10, and block 20 damage from attacks targeted to both characters during the whole turn.\0";
        card->tactic->level = 70;

        card->boss = NULL;
        card->equip = NULL;
        card->field = NULL;
        card->jrboss = NULL;
        card->monster = NULL;
        card->character = NULL;

        card->lv_acao = (struct char_action *)malloc(sizeof(struct char_action));
        card->lv_acao->acao = "Summon / Equip 120 - Play a monster or an equipment of level 120 or less.\0";
        card->lv_acao->nivel = 80;
        card->lv_acao->atrib = 2;

        card->lv_acao->ant = NULL;
        card->lv_acao->prox = NULL;
}

#endif // BLESS_OF_TRIFORCE_H_INCLUDED
