#ifndef FIELD_ACOES_C_INCLUDED
#define FIELD_ACOES_C_INCLUDED

void DesfazFieldEffects(struct CARD *card,struct CARD *field,struct Player *jogador,struct Player *adversario,bool mapa_adversario) {
    if(card != NULL && !strcmp(card->origem->elemento,field->origem->elemento)) {
        int val = 10;

        if(jogador->mesa->equip1 != NULL && jogador->mesa->equip1->origem->colecao == DUNGEON_MAP) val += 10;
        if(jogador->mesa->equip2 != NULL && jogador->mesa->equip2->origem->colecao == DUNGEON_MAP) val += 10;
        if(jogador->mesa->equip3 != NULL && jogador->mesa->equip3->origem->colecao == DUNGEON_MAP) val += 10;
        if(jogador->mesa->equip4 != NULL && jogador->mesa->equip4->origem->colecao == DUNGEON_MAP) val += 10;
        if(jogador->mesa->equip5 != NULL && jogador->mesa->equip5->origem->colecao == DUNGEON_MAP) val += 10;
        if(jogador->mesa->equip6 != NULL && jogador->mesa->equip6->origem->colecao == DUNGEON_MAP) val += 10;
        if(jogador->mesa->equip7 != NULL && jogador->mesa->equip7->origem->colecao == DUNGEON_MAP) val += 10;

        if(mapa_adversario) {
            if(adversario->mesa->equip1 != NULL && adversario->mesa->equip1->origem->colecao == DUNGEON_MAP) val += 10;
            if(adversario->mesa->equip2 != NULL && adversario->mesa->equip2->origem->colecao == DUNGEON_MAP) val += 10;
            if(adversario->mesa->equip3 != NULL && adversario->mesa->equip3->origem->colecao == DUNGEON_MAP) val += 10;
            if(adversario->mesa->equip4 != NULL && adversario->mesa->equip4->origem->colecao == DUNGEON_MAP) val += 10;
            if(adversario->mesa->equip5 != NULL && adversario->mesa->equip5->origem->colecao == DUNGEON_MAP) val += 10;
            if(adversario->mesa->equip6 != NULL && adversario->mesa->equip6->origem->colecao == DUNGEON_MAP) val += 10;
            if(adversario->mesa->equip7 != NULL && adversario->mesa->equip7->origem->colecao == DUNGEON_MAP) val += 10;
        }

        card->HP -= val;
        card->MaxHP -= val;
    }
}

void DesfazFieldEffects2(struct CARD *card,struct CARD *field,struct Player *jogador,struct Player *adversario,bool mapa_adversario) {
    if(card != NULL && !strcmp(card->origem->elemento,field->origem->elemento)) {
        int val = 20;

        if(jogador->mesa->equip1 != NULL && jogador->mesa->equip1->origem->colecao == DUNGEON_MAP) val += 10;
        if(jogador->mesa->equip2 != NULL && jogador->mesa->equip2->origem->colecao == DUNGEON_MAP) val += 10;
        if(jogador->mesa->equip3 != NULL && jogador->mesa->equip3->origem->colecao == DUNGEON_MAP) val += 10;
        if(jogador->mesa->equip4 != NULL && jogador->mesa->equip4->origem->colecao == DUNGEON_MAP) val += 10;
        if(jogador->mesa->equip5 != NULL && jogador->mesa->equip5->origem->colecao == DUNGEON_MAP) val += 10;
        if(jogador->mesa->equip6 != NULL && jogador->mesa->equip6->origem->colecao == DUNGEON_MAP) val += 10;
        if(jogador->mesa->equip7 != NULL && jogador->mesa->equip7->origem->colecao == DUNGEON_MAP) val += 10;

        if(mapa_adversario) {
            if(adversario->mesa->equip1 != NULL && adversario->mesa->equip1->origem->colecao == DUNGEON_MAP) val += 10;
            if(adversario->mesa->equip2 != NULL && adversario->mesa->equip2->origem->colecao == DUNGEON_MAP) val += 10;
            if(adversario->mesa->equip3 != NULL && adversario->mesa->equip3->origem->colecao == DUNGEON_MAP) val += 10;
            if(adversario->mesa->equip4 != NULL && adversario->mesa->equip4->origem->colecao == DUNGEON_MAP) val += 10;
            if(adversario->mesa->equip5 != NULL && adversario->mesa->equip5->origem->colecao == DUNGEON_MAP) val += 10;
            if(adversario->mesa->equip6 != NULL && adversario->mesa->equip6->origem->colecao == DUNGEON_MAP) val += 10;
            if(adversario->mesa->equip7 != NULL && adversario->mesa->equip7->origem->colecao == DUNGEON_MAP) val += 10;
        }

        card->HP -= val;
        card->MaxHP -= val;
    }
}

bool AplicaMapaAdversario(struct Player *adversario) {
    if(adversario->mesa->field == NULL) {
        if(adversario->mesa->equip1 != NULL && adversario->mesa->equip1->origem->colecao == DUNGEON_MAP) return(true);
        if(adversario->mesa->equip2 != NULL && adversario->mesa->equip2->origem->colecao == DUNGEON_MAP) return(true);
        if(adversario->mesa->equip3 != NULL && adversario->mesa->equip3->origem->colecao == DUNGEON_MAP) return(true);
        if(adversario->mesa->equip4 != NULL && adversario->mesa->equip4->origem->colecao == DUNGEON_MAP) return(true);
        if(adversario->mesa->equip5 != NULL && adversario->mesa->equip5->origem->colecao == DUNGEON_MAP) return(true);
        if(adversario->mesa->equip6 != NULL && adversario->mesa->equip6->origem->colecao == DUNGEON_MAP) return(true);
        if(adversario->mesa->equip7 != NULL && adversario->mesa->equip7->origem->colecao == DUNGEON_MAP) return(true);
    }
    return(false);
}

void DesfazField(struct Player *jogador,struct Player *adversario,struct CARD *field) {
    bool toggle = false;

    jogador->field_cont = 0;
    if(AplicaMapaAdversario(adversario)) toggle = true;

    if(field->origem->colecao == DESERT_COLOSSUS || field->origem->colecao == HYRULE_CASTLE || field->origem->colecao == KAKARIKO_GRAVEYARD || field->origem->colecao == FIRE_TEMPLE) {
        DesfazFieldEffects(jogador->mesa->monstro1,field,jogador,adversario,toggle);
        DesfazFieldEffects(jogador->mesa->monstro2,field,jogador,adversario,toggle);
        DesfazFieldEffects(jogador->mesa->monstro3,field,jogador,adversario,toggle);
        DesfazFieldEffects(jogador->mesa->monstro4,field,jogador,adversario,toggle);
        DesfazFieldEffects(jogador->mesa->monstro5,field,jogador,adversario,toggle);
        DesfazFieldEffects(jogador->mesa->monstro6,field,jogador,adversario,toggle);
        DesfazFieldEffects(jogador->mesa->monstro7,field,jogador,adversario,toggle);

        if(adversario->mesa->field == NULL) {
            adversario->field_cont = 0;

            DesfazFieldEffects(adversario->mesa->monstro1,field,jogador,adversario,toggle);
            DesfazFieldEffects(adversario->mesa->monstro2,field,jogador,adversario,toggle);
            DesfazFieldEffects(adversario->mesa->monstro3,field,jogador,adversario,toggle);
            DesfazFieldEffects(adversario->mesa->monstro4,field,jogador,adversario,toggle);
            DesfazFieldEffects(adversario->mesa->monstro5,field,jogador,adversario,toggle);
            DesfazFieldEffects(adversario->mesa->monstro6,field,jogador,adversario,toggle);
            DesfazFieldEffects(adversario->mesa->monstro7,field,jogador,adversario,toggle);
        }
    }

    else if(field->origem->colecao == DEATH_MT_CRATER || field->origem->colecao == KOKIRI_FOREST || field->origem->colecao == LAKE_HYLIA || field->origem->colecao == GERUDO_FORTRESS || field->origem->colecao == GANONS_CASTLE) {
        DesfazFieldEffects2(jogador->mesa->monstro1,field,jogador,adversario,toggle);
        DesfazFieldEffects2(jogador->mesa->monstro2,field,jogador,adversario,toggle);
        DesfazFieldEffects2(jogador->mesa->monstro3,field,jogador,adversario,toggle);
        DesfazFieldEffects2(jogador->mesa->monstro4,field,jogador,adversario,toggle);
        DesfazFieldEffects2(jogador->mesa->monstro5,field,jogador,adversario,toggle);
        DesfazFieldEffects2(jogador->mesa->monstro6,field,jogador,adversario,toggle);
        DesfazFieldEffects2(jogador->mesa->monstro7,field,jogador,adversario,toggle);

        if(adversario->mesa->field == NULL) {
            adversario->field_cont = 0;

            DesfazFieldEffects2(adversario->mesa->monstro1,field,jogador,adversario,toggle);
            DesfazFieldEffects2(adversario->mesa->monstro2,field,jogador,adversario,toggle);
            DesfazFieldEffects2(adversario->mesa->monstro3,field,jogador,adversario,toggle);
            DesfazFieldEffects2(adversario->mesa->monstro4,field,jogador,adversario,toggle);
            DesfazFieldEffects2(adversario->mesa->monstro5,field,jogador,adversario,toggle);
            DesfazFieldEffects2(adversario->mesa->monstro6,field,jogador,adversario,toggle);
            DesfazFieldEffects2(adversario->mesa->monstro7,field,jogador,adversario,toggle);
        }
    }
}

void FieldBoost(struct CARD *card,char *elemento,struct Player *jogador,struct Player *adversario,bool mapa_adversario) {
    if(card != NULL) {
        if(strcmp(card->origem->elemento,elemento) == 0) {
            int val = 10;

            if(jogador->mesa->equip1 != NULL && jogador->mesa->equip1->origem->colecao == DUNGEON_MAP) val += 10;
            if(jogador->mesa->equip2 != NULL && jogador->mesa->equip2->origem->colecao == DUNGEON_MAP) val += 10;
            if(jogador->mesa->equip3 != NULL && jogador->mesa->equip3->origem->colecao == DUNGEON_MAP) val += 10;
            if(jogador->mesa->equip4 != NULL && jogador->mesa->equip4->origem->colecao == DUNGEON_MAP) val += 10;
            if(jogador->mesa->equip5 != NULL && jogador->mesa->equip5->origem->colecao == DUNGEON_MAP) val += 10;
            if(jogador->mesa->equip6 != NULL && jogador->mesa->equip6->origem->colecao == DUNGEON_MAP) val += 10;
            if(jogador->mesa->equip7 != NULL && jogador->mesa->equip7->origem->colecao == DUNGEON_MAP) val += 10;

            if(mapa_adversario) {
                if(adversario->mesa->equip1 != NULL && adversario->mesa->equip1->origem->colecao == DUNGEON_MAP) val += 10;
                if(adversario->mesa->equip2 != NULL && adversario->mesa->equip2->origem->colecao == DUNGEON_MAP) val += 10;
                if(adversario->mesa->equip3 != NULL && adversario->mesa->equip3->origem->colecao == DUNGEON_MAP) val += 10;
                if(adversario->mesa->equip4 != NULL && adversario->mesa->equip4->origem->colecao == DUNGEON_MAP) val += 10;
                if(adversario->mesa->equip5 != NULL && adversario->mesa->equip5->origem->colecao == DUNGEON_MAP) val += 10;
                if(adversario->mesa->equip6 != NULL && adversario->mesa->equip6->origem->colecao == DUNGEON_MAP) val += 10;
                if(adversario->mesa->equip7 != NULL && adversario->mesa->equip7->origem->colecao == DUNGEON_MAP) val += 10;
            }

            printf("---------------> FIELD BOOST PROCD on %s with VAL: %d <------------------\n",card->origem->nome,val);

            if(card->origem->monster != NULL) {
                card->MaxHP = card->MaxHP + val;
                card->HP = card->HP + val;
            }
            else {  //Card ainda pode ser um character.
                if(card->origem->jrboss != NULL || card->origem->boss != NULL) {
                    card->MaxHP = card->MaxHP + val;
                    card->HP = card->HP + val;
                }
            }
        }
    }
}

void FieldBoost2(struct CARD *card,char *elemento,struct Player *jogador,struct Player *adversario,bool mapa_adversario) {
    if(card != NULL) {
        if(strcmp(card->origem->elemento,elemento) == 0) {
            int val = 20;

            if(jogador->mesa->equip1 != NULL && jogador->mesa->equip1->origem->colecao == DUNGEON_MAP) val += 10;
            if(jogador->mesa->equip2 != NULL && jogador->mesa->equip2->origem->colecao == DUNGEON_MAP) val += 10;
            if(jogador->mesa->equip3 != NULL && jogador->mesa->equip3->origem->colecao == DUNGEON_MAP) val += 10;
            if(jogador->mesa->equip4 != NULL && jogador->mesa->equip4->origem->colecao == DUNGEON_MAP) val += 10;
            if(jogador->mesa->equip5 != NULL && jogador->mesa->equip5->origem->colecao == DUNGEON_MAP) val += 10;
            if(jogador->mesa->equip6 != NULL && jogador->mesa->equip6->origem->colecao == DUNGEON_MAP) val += 10;
            if(jogador->mesa->equip7 != NULL && jogador->mesa->equip7->origem->colecao == DUNGEON_MAP) val += 10;

            if(mapa_adversario) {
                if(adversario->mesa->equip1 != NULL && adversario->mesa->equip1->origem->colecao == DUNGEON_MAP) val += 10;
                if(adversario->mesa->equip2 != NULL && adversario->mesa->equip2->origem->colecao == DUNGEON_MAP) val += 10;
                if(adversario->mesa->equip3 != NULL && adversario->mesa->equip3->origem->colecao == DUNGEON_MAP) val += 10;
                if(adversario->mesa->equip4 != NULL && adversario->mesa->equip4->origem->colecao == DUNGEON_MAP) val += 10;
                if(adversario->mesa->equip5 != NULL && adversario->mesa->equip5->origem->colecao == DUNGEON_MAP) val += 10;
                if(adversario->mesa->equip6 != NULL && adversario->mesa->equip6->origem->colecao == DUNGEON_MAP) val += 10;
                if(adversario->mesa->equip7 != NULL && adversario->mesa->equip7->origem->colecao == DUNGEON_MAP) val += 10;
            }

            printf("---------------> FIELD BOOST 2 PROCD on %s with VAL: %d<------------------\n",card->origem->nome,val);

            if(card->origem->monster != NULL) {
                card->MaxHP = card->MaxHP + val;
                card->HP = card->HP + val;
            }
            else {
                if(card->origem->jrboss != NULL || card->origem->boss != NULL) {
                    card->MaxHP = card->MaxHP + val;
                    card->HP = card->HP + val;
                }
            }
        }
    }
}

void Field_effect1(char *tipo,struct Player *jogador,struct Player *adversario) {
    bool toggle = AplicaMapaAdversario(adversario);

    FieldBoost(jogador->mesa->monstro1,tipo,jogador,adversario,toggle);
    FieldBoost(jogador->mesa->monstro2,tipo,jogador,adversario,toggle);
    FieldBoost(jogador->mesa->monstro3,tipo,jogador,adversario,toggle);
    FieldBoost(jogador->mesa->monstro4,tipo,jogador,adversario,toggle);
    FieldBoost(jogador->mesa->monstro5,tipo,jogador,adversario,toggle);
    FieldBoost(jogador->mesa->monstro6,tipo,jogador,adversario,toggle);
    FieldBoost(jogador->mesa->monstro7,tipo,jogador,adversario,toggle);
}

void Field_effect2(char *tipo,struct Player *jogador,struct Player *adversario) {
    bool toggle = AplicaMapaAdversario(adversario);

    FieldBoost2(jogador->mesa->monstro1,tipo,jogador,adversario,toggle);
    FieldBoost2(jogador->mesa->monstro2,tipo,jogador,adversario,toggle);
    FieldBoost2(jogador->mesa->monstro3,tipo,jogador,adversario,toggle);
    FieldBoost2(jogador->mesa->monstro4,tipo,jogador,adversario,toggle);
    FieldBoost2(jogador->mesa->monstro5,tipo,jogador,adversario,toggle);
    FieldBoost2(jogador->mesa->monstro6,tipo,jogador,adversario,toggle);
    FieldBoost2(jogador->mesa->monstro7,tipo,jogador,adversario,toggle);
}

void VerificaField(struct CARD *field,struct Player *jogador,struct Player *adversario) {   //MODO UNICO: VARIA O HP DOS MONSTROS
    /* Lista todos os efeitos dos fields */

    /*::: PONTO DE FUNCAO #1 ::: */
    jogador->field_cont = 0;
    printf("VERIFICA FIELD ");

    if(field->origem->colecao == DESERT_COLOSSUS) {
        Field_effect1(field->origem->elemento,jogador,adversario);
        printf("OK\n");

        jogador->field_cont = jogador->wind_ic;
    }

    else if(field->origem->colecao == HYRULE_CASTLE) {
        Field_effect1(field->origem->elemento,jogador,adversario);
        printf("OK\n");

        jogador->field_cont = jogador->light_ic;
    }

    else if(field->origem->colecao == KAKARIKO_GRAVEYARD) {
        Field_effect1(field->origem->elemento,jogador,adversario);
        printf("OK\n");

        jogador->field_cont = jogador->dark_ic;
    }

    else if(field->origem->colecao == FIRE_TEMPLE) {
        Field_effect1(field->origem->elemento,jogador,adversario);
        printf("OK\n");

        jogador->field_cont = jogador->fire_ic;
    }
     /* ---------- outros fields ----------------- */

     /* ------------------------------------------ */

    else if(field->origem->colecao == DEATH_MT_CRATER) {
        Field_effect2(field->origem->elemento,jogador,adversario);
        printf("OK\n");

        jogador->field_cont = jogador->fire_ic;
    }

    else if(field->origem->colecao == KOKIRI_FOREST) {
        Field_effect2(field->origem->elemento,jogador,adversario);
        printf("OK\n");

        jogador->field_cont = jogador->earth_ic;
    }

    else if(field->origem->colecao == LAKE_HYLIA) {
        Field_effect2(field->origem->elemento,jogador,adversario);
        printf("OK\n");

        jogador->field_cont = jogador->water_ic;
    }

    else if(field->origem->colecao == GERUDO_FORTRESS) {
        Field_effect2(field->origem->elemento,jogador,adversario);
        printf("OK\n");

        jogador->field_cont = jogador->wind_ic;
    }

    else if(field->origem->colecao == GANONS_CASTLE) {
        Field_effect2(field->origem->elemento,jogador,adversario);
        printf("OK\n");

        jogador->field_cont = jogador->dark_ic;
    }

    //outros fields...

}

void DesfazAmbosFieldBuffs(struct Player *jogador,struct Player *adversario) {
    if(jogador->mesa->field != NULL) DesfazField(jogador,adversario,jogador->mesa->field);
    if(adversario->mesa->field != NULL) DesfazField(adversario,jogador,adversario->mesa->field);
}

void RefazAmbosFieldBuffs(struct Player *jogador,struct Player *adversario) {
    if(jogador->mesa->field != NULL) VerificaField(jogador->mesa->field,jogador,adversario);
    else if(adversario->mesa->field != NULL) VerificaField(adversario->mesa->field,jogador,adversario);

    if(adversario->mesa->field != NULL) VerificaField(adversario->mesa->field,adversario,jogador);
    else if(jogador->mesa->field != NULL) VerificaField(jogador->mesa->field,adversario,jogador);
}

#endif // FIELD_ACOES_C_INCLUDED
