#ifndef MASK_OF_TRUTH_H_INCLUDED
#define MASK_OF_TRUTH_H_INCLUDED

void mask_of_truth(struct Card *card) {
        card->bmp = al_load_bitmap("cards/mask_of_truth.png");
        card->nome = "Mask of Truth\0";
        card->elemento = "Wind\0";
        card->colecao = 104;
        card->RARIDADE = 1;
        card->preco = 1993;
        card->tipo = "Equipment\0";
        card->str_concat = "Wind - Equipment - Mask\0";

        card->equip = (struct equipment *)malloc(sizeof(struct equipment));
        card->equip->acao = "Whenever your opponent plays a monster, reveal one of your opponents cards on the hand. If a monster is revealed this way, it is of your level or less and it would be allowed to play under normal circumstances (you dont need to have its element attribute under your character though), play it at your side and your opponent draws a card.\0";
        card->equip->level = 56;

        card->boss = NULL;
        card->character = NULL;
        card->field = NULL;
        card->jrboss = NULL;
        card->monster = NULL;
        card->tactic = NULL;

        card->lv_acao = (struct char_action *)malloc(sizeof(struct char_action));
        card->lv_acao->acao = "Equip / Rapid Action / Locate 80 - Play an equipment or a tactic of level 80 or less or a field card.\0";
        card->lv_acao->nivel = 60;
        card->lv_acao->atrib = 3;

        card->lv_acao->ant = NULL;
        card->lv_acao->prox = NULL;
}

/*void AlteraAtributos(int *atrib,struct Player *jogador) {
    atrib[0] = jogador->earth_ic;
    if(jogador->earth_ic == 0) (jogador->earth_ic)++;
    atrib[1] = jogador->wind_ic;
    if(jogador->wind_ic == 0) (jogador->wind_ic)++;
    atrib[2] = jogador->light_ic;
    if(jogador->light_ic == 0) (jogador->light_ic)++;
    atrib[3] = jogador->dark_ic;
    if(jogador->dark_ic == 0) (jogador->dark_ic)++;
    atrib[4] = jogador->fire_ic;
    if(jogador->fire_ic == 0) (jogador->fire_ic)++;
    atrib[5] = jogador->water_ic;
    if(jogador->water_ic == 0) (jogador->water_ic)++;
}

void RecuperaAtributos(int *atrib,struct Player *jogador) {
    jogador->earth_ic = atrib[0];
    jogador->wind_ic = atrib[1];
    jogador->light_ic = atrib[2];
    jogador->dark_ic = atrib[3];
    jogador->fire_ic = atrib[4];
    jogador->water_ic = atrib[5];
}*/

#endif // MASK_OF_TRUTH_H_INCLUDED
