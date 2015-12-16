#ifndef DEKU_NUT_H_INCLUDED
#define DEKU_NUT_H_INCLUDED

void deku_nut(struct Card *card) {
        card->bmp = al_load_bitmap("cards/deku_nut.png");
        card->nome = "Deku Nut\0";

        card->elemento = "Light\0";
        card->colecao = 65;
        card->RARIDADE = 3;
        card->preco = 990;
        card->tipo = "Tactic\0";
        card->str_concat = "Light - Tactic - Skill\0";

        card->tactic = (struct tactic *)malloc(sizeof(struct tactic));
        card->tactic->acao = "All opponent monsters become unable to attack for 3 turns, except these which are summoned after the activation of this card.\0";
        card->tactic->level = 35;

        card->boss = NULL;
        card->equip = NULL;
        card->field = NULL;
        card->jrboss = NULL;
        card->monster = NULL;
        card->character = NULL;

        card->lv_acao = (struct char_action *)malloc(sizeof(struct char_action));
        card->lv_acao->acao = "Summon / Equip 50 - Play a monster or an equipment of level 50 or less.\0";
        card->lv_acao->nivel = 50;
        card->lv_acao->atrib = 3;

        card->lv_acao->ant = NULL;
        card->lv_acao->prox = NULL;
}

void deku_nut_acao(struct Player *adversario) {
    if(adversario->mesa->monstro1 != NULL) adversario->mesa->monstro1->turn_cooldown += 3;
    if(adversario->mesa->monstro2 != NULL) adversario->mesa->monstro2->turn_cooldown += 3;
    if(adversario->mesa->monstro3 != NULL) adversario->mesa->monstro3->turn_cooldown += 3;
    if(adversario->mesa->monstro4 != NULL) adversario->mesa->monstro4->turn_cooldown += 3;
    if(adversario->mesa->monstro5 != NULL) adversario->mesa->monstro5->turn_cooldown += 3;
    if(adversario->mesa->monstro6 != NULL) adversario->mesa->monstro6->turn_cooldown += 3;
    if(adversario->mesa->monstro7 != NULL) adversario->mesa->monstro7->turn_cooldown += 3;
}

#endif // DEKU_NUT_H_INCLUDED
