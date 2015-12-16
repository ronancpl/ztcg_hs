#ifndef UNDERGROUND_SHELTER_H_INCLUDED
#define UNDERGROUND_SHELTER_H_INCLUDED

void underground_shelter(struct Card *card) {
        card->bmp = al_load_bitmap("cards/underground_shelter.png");
        card->nome = "Underground Shelter\0";
        card->elemento = "Wind\0";
        card->colecao = 131;
        card->RARIDADE = 3;
        card->preco = 1300;
        card->tipo = "Tactic\0";
        card->str_concat = "Wind - Tactic - Strategy\0";

        card->tactic = (struct tactic *)malloc(sizeof(struct tactic));
        card->tactic->acao = "For one turn, all your monsters and character can block 20 damage from each opposing attack.\0";
        card->tactic->level = 35;

        card->boss = NULL;
        card->equip = NULL;
        card->field = NULL;
        card->jrboss = NULL;
        card->monster = NULL;
        card->character = NULL;

        card->lv_acao = (struct char_action *)malloc(sizeof(struct char_action));
        card->lv_acao->acao = "Refresh - Recover +10 HP.\0";
        card->lv_acao->nivel = 40;
        card->lv_acao->atrib = 1;

        card->lv_acao->ant = NULL;
        card->lv_acao->prox = NULL;
}

#endif // UNDERGROUND_SHELTER_H_INCLUDED
