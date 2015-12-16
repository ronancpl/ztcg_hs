#ifndef LIZALFOS_H_INCLUDED
#define LIZALFOS_H_INCLUDED

void lizalfos(struct Card *card) {
        card->bmp = al_load_bitmap("cards/lizalfos.png");
        card->nome = "Lizalfos\0";
        card->elemento = "Earth\0";
        card->colecao = 21;
        card->RARIDADE = 7;
        card->preco = 800;
        card->tipo = "Monster\0";
        card->str_concat = "Earth - Monster - Reptile Warrior\0";

        card->monster = (struct monster *)malloc(sizeof(struct monster));
        card->monster->acao = "Crafty - For each tactic used on the turn this card is on the field, add +10 on its attack damage.\0";
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
        card->lv_acao->acao = "Summon / Locate 60 - Play a monster of level 60 or less or a field.\0";
        card->lv_acao->nivel = 60;
        card->lv_acao->atrib = 1;

        card->lv_acao->ant = NULL;
        card->lv_acao->prox = NULL;
}

#endif // LIZALFOS_H_INCLUDED
