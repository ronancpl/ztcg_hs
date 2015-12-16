#ifndef ICE_ARROW_H_INCLUDED
#define ICE_ARROW_H_INCLUDED

void ice_arrow(struct Card *card) {
        card->bmp = al_load_bitmap("cards/ice_arrow.png");
        card->nome = "Ice Arrow\0";
        card->elemento = "Water\0";
        card->colecao = 69;
        card->RARIDADE = 7;
        card->preco = 900;
        card->tipo = "Tactic\0";
        card->str_concat = "Water - Tactic - Skill\0";

        card->tactic = (struct tactic *)malloc(sizeof(struct tactic));
        card->tactic->acao = "Freeze a monster on the field, making it unable to attack or use its skill for a turn. If the target is a FIRE monster, destroy it instead.\0";
        card->tactic->level = 45;

        card->boss = NULL;
        card->equip = NULL;
        card->field = NULL;
        card->jrboss = NULL;
        card->monster = NULL;
        card->character = NULL;

        card->lv_acao = (struct char_action *)malloc(sizeof(struct char_action));
        card->lv_acao->acao = "Equip / Rapid Action 50 - Play a tactic or an equipment of level 50 or less.\0";
        card->lv_acao->nivel = 40;
        card->lv_acao->atrib = 2;

        card->lv_acao->ant = NULL;
        card->lv_acao->prox = NULL;
}

#endif // ICE_ARROW_H_INCLUDED
