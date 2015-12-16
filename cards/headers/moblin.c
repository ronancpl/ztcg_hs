#ifndef MOBLIN_H_INCLUDED
#define MOBLIN_H_INCLUDED

void moblin(struct Card *card) {
        card->bmp = al_load_bitmap("cards/moblin.png");
        card->nome = "Moblin\0";
        card->elemento = "Dark\0";
        card->colecao = 29;
        card->RARIDADE = 7;
        card->preco = 320;
        card->tipo = "Monster\0";
        card->str_concat = "Dark - Monster - Boar Warrior\0";

        card->monster = (struct monster *)malloc(sizeof(struct monster));
        card->monster->acao = "Armored - Character actions dont hurt Moblin.\0";
        card->monster->level = 30;
        card->monster->attack = 20;
        card->monster->MaxHP = 40;

        card->boss = NULL;
        card->character = NULL;
        card->field = NULL;
        card->jrboss = NULL;
        card->equip = NULL;
        card->tactic = NULL;

        card->lv_acao = (struct char_action *)malloc(sizeof(struct char_action));
        card->lv_acao->acao = "Rage Buff - All of your monsters on field at the moment this effect is activated get +20 damage with their attacks for one turn.\0";
        card->lv_acao->nivel = 999;
        card->lv_acao->atrib = 0;

        card->lv_acao->ant = NULL;
        card->lv_acao->prox = NULL;
}

void moblin_lvacao(struct Player *jogador) {
    if(jogador->mesa->monstro1 != NULL) jogador->mesa->monstro1->var_monster->rage_buff_bool = true;
    if(jogador->mesa->monstro2 != NULL) jogador->mesa->monstro2->var_monster->rage_buff_bool = true;
    if(jogador->mesa->monstro3 != NULL) jogador->mesa->monstro3->var_monster->rage_buff_bool = true;
    if(jogador->mesa->monstro4 != NULL) jogador->mesa->monstro4->var_monster->rage_buff_bool = true;
    if(jogador->mesa->monstro5 != NULL) jogador->mesa->monstro5->var_monster->rage_buff_bool = true;
    if(jogador->mesa->monstro6 != NULL) jogador->mesa->monstro6->var_monster->rage_buff_bool = true;
    if(jogador->mesa->monstro7 != NULL) jogador->mesa->monstro7->var_monster->rage_buff_bool = true;
}

#endif // MOBLIN_H_INCLUDED
