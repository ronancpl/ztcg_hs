#ifndef GERUDO_FORTRESS_H_INCLUDED
#define GERUDO_FORTRESS_H_INCLUDED

void gerudo_fortress(struct Card *card) {
        card->bmp = al_load_bitmap("cards/gerudo_fortress.png");
        card->nome = "Gerudos Fortress\0";
        card->elemento = "Wind\0";
        card->colecao = 42;
        card->RARIDADE = 1;
        card->preco = 1650;
        card->tipo = "Field\0";
        card->str_concat = "Wind - Field - Gerudo Valley\0";

        card->field = (struct field *)malloc(sizeof(struct field));
        card->field->acao = "Add +10 attack and +20 HP to each WIND monster in battle. Add +20 attack to each character action of a WIND character. Next, get 50 HP for your character.\0";

        card->boss = NULL;
        card->character = NULL;
        card->equip = NULL;
        card->jrboss = NULL;
        card->monster = NULL;
        card->tactic = NULL;

        card->lv_acao = (struct char_action *)malloc(sizeof(struct char_action));
        card->lv_acao->acao = "Locate - Play a field card.\0";
        card->lv_acao->nivel = 50;
        card->lv_acao->atrib = 3;

        card->lv_acao->ant = NULL;
        card->lv_acao->prox = NULL;
}

#endif // GERUDO_FORTRESS_H_INCLUDED
