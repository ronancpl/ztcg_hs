#ifndef GORON_RUBY_H_INCLUDED
#define GORON_RUBY_H_INCLUDED

void goron_ruby(struct Card *card) {
        card->bmp = al_load_bitmap("cards/goron_ruby.png");
        card->nome = "Goron Ruby\0";
        card->elemento = "Fire\0";
        card->colecao = 26;
        card->RARIDADE = 7;
        card->preco = 970;
        card->tipo = "Equipment\0";
        card->str_concat = "Fire - Equipment - Jewel\0";

        card->equip = (struct equipment *)malloc(sizeof(struct equipment));
        card->equip->acao = "All FIRE monsters get +10 attack and +10 HP. Whenever you play a FIRE monster, peek the top card of your deck; if it is a tactic play it, otherwise put it back.\0";
        card->equip->level = 40;

        card->boss = NULL;
        card->character = NULL;
        card->field = NULL;
        card->jrboss = NULL;
        card->monster = NULL;
        card->tactic = NULL;

        card->lv_acao = (struct char_action *)malloc(sizeof(struct char_action));
        card->lv_acao->acao = "Summon / Rapid Action 60 - Play a monster or a tactic of level 60 or less.\0";
        card->lv_acao->nivel = 60;
        card->lv_acao->atrib = 2;

        card->lv_acao->ant = NULL;
        card->lv_acao->prox = NULL;
}

#endif // GORON_RUBY_H_INCLUDED
