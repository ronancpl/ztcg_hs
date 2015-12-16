#ifndef CURSED_VILLAGER_H_INCLUDED
#define CURSED_VILLAGER_H_INCLUDED

void cursed_villager(struct Card *card) {
        card->bmp = al_load_bitmap("cards/cursed_villager.png");
        card->nome = "Cursed Villager\0";
        card->elemento = "Dark\0";
        card->colecao = 43;
        card->RARIDADE = 7;
        card->preco = 770;
        card->tipo = "Monster\0";
        card->str_concat = "Dark - Monster - NPC Spider\0";

        card->monster = (struct monster *)malloc(sizeof(struct monster));
        card->monster->acao = "NPC QUEST - Play a Spider monster from your hand. REWARD - All opponent monsters lose their abilities until your next turn starts.\0";
        card->monster->level = 50;
        card->monster->attack = 20;
        card->monster->MaxHP = 40;

        card->boss = NULL;
        card->character = NULL;
        card->field = NULL;
        card->jrboss = NULL;
        card->equip = NULL;
        card->tactic = NULL;

        card->lv_acao = (struct char_action *)malloc(sizeof(struct char_action));
        card->lv_acao->acao = "Summon / Rapid Action 50 - Play a monster or a tactic of level 50 or less.\0";
        card->lv_acao->nivel = 40;
        card->lv_acao->atrib = 2;

        card->lv_acao->ant = NULL;
        card->lv_acao->prox = NULL;
}

bool cvEmcampo(struct Player *jogador) {
    if(jogador->mesa->monstro1 != NULL && jogador->mesa->monstro1->origem->colecao == CURSED_VILLAGER && jogador->mesa->monstro1->turn_silenced == 0) return(true);
    if(jogador->mesa->monstro2 != NULL && jogador->mesa->monstro2->origem->colecao == CURSED_VILLAGER && jogador->mesa->monstro2->turn_silenced == 0) return(true);
    if(jogador->mesa->monstro3 != NULL && jogador->mesa->monstro3->origem->colecao == CURSED_VILLAGER && jogador->mesa->monstro3->turn_silenced == 0) return(true);
    if(jogador->mesa->monstro4 != NULL && jogador->mesa->monstro4->origem->colecao == CURSED_VILLAGER && jogador->mesa->monstro4->turn_silenced == 0) return(true);
    if(jogador->mesa->monstro5 != NULL && jogador->mesa->monstro5->origem->colecao == CURSED_VILLAGER && jogador->mesa->monstro5->turn_silenced == 0) return(true);
    if(jogador->mesa->monstro6 != NULL && jogador->mesa->monstro6->origem->colecao == CURSED_VILLAGER && jogador->mesa->monstro6->turn_silenced == 0) return(true);
    if(jogador->mesa->monstro7 != NULL && jogador->mesa->monstro7->origem->colecao == CURSED_VILLAGER && jogador->mesa->monstro7->turn_silenced == 0) return(true);

    return(false);
}

#endif // CURSED_VILLAGER_H_INCLUDED
