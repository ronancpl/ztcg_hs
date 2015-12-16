#ifndef TAILPASARAN_H_INCLUDED
#define TAILPASARAN_H_INCLUDED

void tailpasaran(struct Card *card) {
        card->bmp = al_load_bitmap("cards/tailpasaran.png");
        card->nome = "Tailpasaran\0";
        card->elemento = "Light\0";
        card->colecao = 41;
        card->RARIDADE = 7;
        card->preco = 740;
        card->tipo = "Monster\0";
        card->str_concat = "Light - Monster - Worm\0";

        card->monster = (struct monster *)malloc(sizeof(struct monster));
        card->monster->acao = "Motion-Sense Bioequipped - When you play Tailpasaran do 20 damage to a character or monster. Eletric Body - Do 20 damage to any monsters that attacks Tailpasaran.\0";
        card->monster->level = 35;
        card->monster->attack = 10;
        card->monster->MaxHP = 40;

        card->boss = NULL;
        card->character = NULL;
        card->field = NULL;
        card->jrboss = NULL;
        card->equip = NULL;
        card->tactic = NULL;

        card->lv_acao = (struct char_action *)malloc(sizeof(struct char_action));
        card->lv_acao->acao = "Summon / Rapid Action 40 - Play a monster or a tactic of level 40 or less.\0";
        card->lv_acao->nivel = 30;
        card->lv_acao->atrib = 2;

        card->lv_acao->ant = NULL;
        card->lv_acao->prox = NULL;
}

#endif // TAILPASARAN_H_INCLUDED
