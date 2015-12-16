#ifndef DARK_PATHWAY_H_INCLUDED
#define DARK_PATHWAY_H_INCLUDED

void dark_pathway(struct Card *card) {
        card->bmp = al_load_bitmap("cards/dark_pathway.png");
        card->nome = "Dark Pathway\0";
        card->elemento = "Dark\0";
        card->colecao = 66;
        card->RARIDADE = 7;
        card->preco = 850;
        card->tipo = "Tactic\0";
        card->str_concat = "Dark - Tactic - Pass\0";

        card->tactic = (struct tactic *)malloc(sizeof(struct tactic));
        card->tactic->acao = "Destroy all monsters on the field, excluding DARK monsters. During this turn, DARK monsters has its attack improved by 10.\0";
        card->tactic->level = 50;

        card->boss = NULL;
        card->equip = NULL;
        card->field = NULL;
        card->jrboss = NULL;
        card->monster = NULL;
        card->character = NULL;

        card->lv_acao = (struct char_action *)malloc(sizeof(struct char_action));
        card->lv_acao->acao = "Summon / Equip / Rapid Action 40 - Play a monster, an equipment or a tactic of level 40 or less.\0";
        card->lv_acao->nivel = 50;
        card->lv_acao->atrib = 2;

        card->lv_acao->ant = NULL;
        card->lv_acao->prox = NULL;
}

#endif // DARK_PATHWAY_H_INCLUDED
