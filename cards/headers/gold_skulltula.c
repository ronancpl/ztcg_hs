#ifndef GOLD_SKULLTULA_H_INCLUDED
#define GOLD_SKULLTULA_H_INCLUDED

void gold_skulltula(struct Card *card) {
        card->bmp = al_load_bitmap("cards/gold_skulltula.png");
        card->nome = "Gold Skulltula\0";
        card->elemento = "Dark\0";
        card->colecao = 54;
        card->RARIDADE = 3;
        card->preco = 670;
        card->tipo = "Monster\0";
        card->str_concat = "Dark - Monster - Spider\0";

        card->monster = (struct monster *)malloc(sizeof(struct monster));
        card->monster->acao = "Cursed - The character or monster that attacks this will take 30 damage (non-preventive) for 2 turns, as the turn of this card owner starts. DOT effects do not stack for the same source. If the attacker is a monster, it will lose the attack ability for 1 turn.\0";
        card->monster->level = 21;
        card->monster->attack = 10;
        card->monster->MaxHP = 30;

        card->boss = NULL;
        card->character = NULL;
        card->field = NULL;
        card->jrboss = NULL;
        card->equip = NULL;
        card->tactic = NULL;

        card->lv_acao = (struct char_action *)malloc(sizeof(struct char_action));
        card->lv_acao->acao = "Silent Stab - Do 10 damage to a character or a monster.\0";
        card->lv_acao->nivel = 30;
        card->lv_acao->atrib = 1;

        card->lv_acao->ant = NULL;
        card->lv_acao->prox = NULL;
}

#endif // GOLD_SKULLTULA_H_INCLUDED
