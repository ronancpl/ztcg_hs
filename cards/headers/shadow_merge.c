#ifndef SHADOW_MERGE_H_INCLUDED
#define SHADOW_MERGE_H_INCLUDED

void shadow_merge(struct Card *card) {
        card->bmp = al_load_bitmap("cards/shadow_merge.png");
        card->nome = "Shadow Merge\0";
        card->elemento = "Dark\0";
        card->colecao = 102;
        card->RARIDADE = 3;
        card->preco = 1111;
        card->tipo = "Tactic\0";
        card->str_concat = "Dark - Tactic - Strategy\0";

        card->tactic = (struct tactic *)malloc(sizeof(struct tactic));
        card->tactic->acao = "Destroy one of your monsters and one of your opponents (except for Jr. Bosses or Bosses), then you may summon a monster of your level or less.\0";
        card->tactic->level = 45;

        card->boss = NULL;
        card->equip = NULL;
        card->field = NULL;
        card->jrboss = NULL;
        card->monster = NULL;
        card->character = NULL;

        card->lv_acao = (struct char_action *)malloc(sizeof(struct char_action));
        card->lv_acao->acao = "Summon / Locate 70 - Play a monster of level 70 or less or a field.\0";
        card->lv_acao->nivel = 60;
        card->lv_acao->atrib = 2;

        card->lv_acao->ant = NULL;
        card->lv_acao->prox = NULL;
}

void shadow_merge_insere_alvo(struct Deck **aux,struct CARD *card) {
    if(card != NULL && !EhBoss(card)) {
        (*aux)->card = card;
        (*aux)->prox = (struct Deck *)malloc(sizeof(struct Deck));
        (*aux) = (*aux)->prox;
    }
}

#endif // SHADOW_MERGE_H_INCLUDED
