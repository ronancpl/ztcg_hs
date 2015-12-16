#ifndef BABY_DODONGO_H_INCLUDED
#define BABY_DODONGO_H_INCLUDED

void baby_dodongo(struct Card *card) {
        card->bmp = al_load_bitmap("cards/baby_dodongo.png");
        card->nome = "Baby Dodongo\0";
        card->elemento = "Fire\0";
        card->colecao = 87;
        card->RARIDADE = 7;
        card->preco = 590;
        card->tipo = "Monster\0";
        card->str_concat = "Fire - Monster - Dodongo\0";

        card->monster = (struct monster *)malloc(sizeof(struct monster));
        card->monster->acao = "Hide - Prevent all other damage to Baby Dodongo if it has been damaged already at the turn. Suicide Blast - When Baby Dodongo is destroyed, do 10 damage to all opposing monsters. Then do 20 damage to a character.\0";
        card->monster->level = 28;
        card->monster->attack = 10;
        card->monster->MaxHP = 30;

        card->boss = NULL;
        card->character = NULL;
        card->field = NULL;
        card->jrboss = NULL;
        card->equip = NULL;
        card->tactic = NULL;

        card->lv_acao = (struct char_action *)malloc(sizeof(struct char_action));
        card->lv_acao->acao = "Summon / Equip 40 - Play a monster or an equipment of level 40 or less.\0";
        card->lv_acao->nivel = 30;
        card->lv_acao->atrib = 3;

        card->lv_acao->ant = NULL;
        card->lv_acao->prox = NULL;
}

void baby_dodongo_acao(struct CARD *baby_dodongo,struct Player *adversario) {

}

#endif // BABY_DODONGO_H_INCLUDED
