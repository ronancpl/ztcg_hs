#ifndef GERUDO_GUARD_H_INCLUDED
#define GERUDO_GUARD_H_INCLUDED

void gerudo_guard(struct Card *card) {
        card->bmp = al_load_bitmap("cards/gerudo_guard.png");
        card->nome = "Gerudo Guard\0";
        card->elemento = "Wind\0";
        card->colecao = 18;
        card->RARIDADE = 3;
        card->preco = 950;
        card->tipo = "Monster\0";
        card->str_concat = "Wind - Monster - NPC Gerudo\0";

        card->monster = (struct monster *)malloc(sizeof(struct monster));
        card->monster->acao = "NPC QUEST - Your opponent has 3 or more monsters on the field at the start of your turn. REWARD - All of your monster attacks gets assisted with +20 attack damage during this turn.\0";
        card->monster->level = 72;
        card->monster->attack = 30;
        card->monster->MaxHP = 60;

        card->boss = NULL;
        card->character = NULL;
        card->field = NULL;
        card->jrboss = NULL;
        card->equip = NULL;
        card->tactic = NULL;

        card->lv_acao = (struct char_action *)malloc(sizeof(struct char_action));
        card->lv_acao->acao = "Summon / Equip 70 - Play a monster or an equipment of level 70 or less.\0";
        card->lv_acao->nivel = 70;
        card->lv_acao->atrib = 2;

        card->lv_acao->ant = NULL;
        card->lv_acao->prox = NULL;
}

bool gerudo_guard_acao(struct Player *adversario) {
    if(TotalMobsEmCampo(NULL,adversario,2) >= 3) return(true);
    else return(false);
}

#endif // GERUDO_GUARD_H_INCLUDED
