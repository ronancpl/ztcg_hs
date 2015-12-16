#ifndef CHANNELED_STRIKE_H_INCLUDED
#define CHANNELED_STRIKE_H_INCLUDED

void channeled_strike(struct Card *card) {
        card->bmp = al_load_bitmap("cards/channeled_strike.png");
        card->nome = "Channeled Strike\0";
        card->elemento = "Earth\0";
        card->colecao = 122;
        card->RARIDADE = 3;
        card->preco = 945;
        card->tipo = "Tactic\0";
        card->str_concat = "Earth - Tactic - Skill\0";

        card->tactic = (struct tactic *)malloc(sizeof(struct tactic));
        card->tactic->acao = "At your next turn, get +10 damage with all your character actions. If a Weapon is equipped, at the end of your character actions phase get an additional attack instance of 30 damage to a character or monster.\0";
        card->tactic->level = 40;

        card->boss = NULL;
        card->equip = NULL;
        card->field = NULL;
        card->jrboss = NULL;
        card->monster = NULL;
        card->character = NULL;

        card->lv_acao = (struct char_action *)malloc(sizeof(struct char_action));
        card->lv_acao->acao = "Combo Hit - Do 20 damage to a character or monster. Then, do 30 damage to a character.\0";
        card->lv_acao->nivel = 80;
        card->lv_acao->atrib = 2;

        card->lv_acao->ant = NULL;
        card->lv_acao->prox = NULL;
}

#endif // CHANNELED_STRIKE_H_INCLUDED
