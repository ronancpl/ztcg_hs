#ifndef BOMBCHU_H_INCLUDED
#define BOMBCHU_H_INCLUDED

void bombchu(struct Card *card) {
        card->bmp = al_load_bitmap("cards/bombchu.png");
        card->nome = "Bombchu\0";
        card->elemento = "Dark\0";
        card->colecao = 19;
        card->RARIDADE = 7;
        card->preco = 800;
        card->tipo = "Equipment\0";
        card->str_concat = "Dark - Equipment - Weapon\0";

        card->equip = (struct equipment *)malloc(sizeof(struct equipment));
        card->equip->acao = "The next monster your opponent plays, destroy that monster. Then destroy this equipment and get +10 damage on your next attack.\0";
        card->equip->level = 42;

        card->boss = NULL;
        card->character = NULL;
        card->field = NULL;
        card->jrboss = NULL;
        card->monster = NULL;
        card->tactic = NULL;

        card->lv_acao = (struct char_action *)malloc(sizeof(struct char_action));
        card->lv_acao->acao = "Summon / Locate 50 - Play a monster of level 50 or less or a field card.\0";
        card->lv_acao->nivel = 60;
        card->lv_acao->atrib = 1;

        card->lv_acao->ant = NULL;
        card->lv_acao->prox = NULL;
}

#endif // BOMBCHU_H_INCLUDED
