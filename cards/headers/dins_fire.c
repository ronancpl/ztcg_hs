#ifndef DINS_FIRE_H_INCLUDED
#define DINS_FIRE_H_INCLUDED

void dins_fire(struct Card *card) {
        card->bmp = al_load_bitmap("cards/dins_fire.png");
        card->nome = "Dins Fire\0";
        card->elemento = "Fire\0";
        card->colecao = 74;
        card->RARIDADE = 3;
        card->preco = 1125;
        card->tipo = "Tactic\0";
        card->str_concat = "Fire - Tactic - Skill\0";

        card->tactic = (struct tactic *)malloc(sizeof(struct tactic));
        card->tactic->acao = "Destroy all monsters in the field. Also, inflict 40 as direct damage at a character.\0";
        card->tactic->level = 60;

        card->boss = NULL;
        card->equip = NULL;
        card->field = NULL;
        card->jrboss = NULL;
        card->monster = NULL;
        card->character = NULL;

        card->lv_acao = (struct char_action *)malloc(sizeof(struct char_action));
        card->lv_acao->acao = "Rapid Action X - Play a tactic of your level or less.\0";
        card->lv_acao->nivel = 50;
        card->lv_acao->atrib = 3;

        card->lv_acao->ant = NULL;
        card->lv_acao->prox = NULL;
}

#endif // DINS_FIRE_H_INCLUDED
