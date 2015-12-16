#ifndef MYSTIC_SPELL_H_INCLUDED
#define MYSTIC_SPELL_H_INCLUDED

void mystic_spell(struct Card *card) {
        card->bmp = al_load_bitmap("cards/mystic_spell.png");
        card->nome = "Mystic Spell\0";

        card->elemento = "Light\0";
        card->colecao = 147;
        card->RARIDADE = 7;
        card->preco = 720;
        card->tipo = "Tactic\0";
        card->str_concat = "Light - Tactic - Strategy\0";

        card->tactic = (struct tactic *)malloc(sizeof(struct tactic));
        card->tactic->acao = "Recover one card from your graveyard to your hand.\0";
        card->tactic->level = 38;

        card->boss = NULL;
        card->equip = NULL;
        card->field = NULL;
        card->jrboss = NULL;
        card->monster = NULL;
        card->character = NULL;

        card->lv_acao = (struct char_action *)malloc(sizeof(struct char_action));
        card->lv_acao->acao = "Rapid Action 50 - Play a tactic of level 50 or less.\0";
        card->lv_acao->nivel = 40;
        card->lv_acao->atrib = 2;

        card->lv_acao->ant = NULL;
        card->lv_acao->prox = NULL;
}

#endif // MYSTIC_SPELL_H_INCLUDED
