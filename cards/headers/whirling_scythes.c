#ifndef WHIRLING_SCYTHES_H_INCLUDED
#define WHIRLING_SCYTHES_H_INCLUDED

void whirling_scythes(struct Card *card) {
        card->bmp = al_load_bitmap("cards/whirling_scythes.png");
        card->nome = "Whirling Scythes\0";
        card->elemento = "Earth\0";
        card->colecao = 119;
        card->RARIDADE = 1;
        card->preco = 1770;
        card->tipo = "Tactic\0";
        card->str_concat = "Earth - Tactic - Strategy\0";

        card->tactic = (struct tactic *)malloc(sizeof(struct tactic));
        card->tactic->acao = "Do 30 damage to all opponents monsters and character. Draw a card for each monster destroyed by this tactic.\0";
        card->tactic->level = 70;

        card->boss = NULL;
        card->equip = NULL;
        card->field = NULL;
        card->jrboss = NULL;
        card->monster = NULL;
        card->character = NULL;

        card->lv_acao = (struct char_action *)malloc(sizeof(struct char_action));
        card->lv_acao->acao = "Equip / Rapid Action / Locate 100 - Play an equipment or a tactic of level 100 or less or a field.\0";
        card->lv_acao->nivel = 80;
        card->lv_acao->atrib = 3;

        card->lv_acao->ant = NULL;
        card->lv_acao->prox = NULL;
}

#endif // WHIRLING_SCYTHES_H_INCLUDED
