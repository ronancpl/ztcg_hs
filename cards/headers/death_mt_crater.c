#ifndef DEATH_MT_CRATER_H_INCLUDED
#define DEATH_MT_CRATER_H_INCLUDED

void death_mt_crater(struct Card *card) {
        card->bmp = al_load_bitmap("cards/death_mt_crater.png");
        card->nome = "Death Mt. Crater\0";
        card->elemento = "Fire\0";
        card->colecao = 35;
        card->RARIDADE = 1;
        card->preco = 1650;
        card->tipo = "Field\0";
        card->str_concat = "Fire - Field - Death Mountain Crater\0";

        card->field = (struct field *)malloc(sizeof(struct field));
        card->field->acao = "Add +10 attack and +20 HP to each FIRE monster in battle. Add +20 attack to each character action of a FIRE character. Next, get 50 HP for your character.\0";

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

#endif // DEATH_MT_CRATER_H_INCLUDED
