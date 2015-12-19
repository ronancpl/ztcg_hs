#ifndef FUNCOES_SLOT_C_INCLUDED
#define FUNCOES_SLOT_C_INCLUDED

void EquipSummonBuffs(bool modo,struct CARD *equip,struct CARD *slot) {
    if(equip == NULL) return;

    /*::: PONTO DE FUNCAO #15 ::: */
    if(equip->origem->colecao == GORON_RUBY) efeito_gr_monstro(slot);
    if(equip->origem->colecao == ZORAS_SAPPHIRE) efeito_zs_monstro(slot);
}

void EquipSummonEffects(int id_acao,struct CARD *card,struct CARD *aux,struct Card **buffer,bool *fim_de_jogo,int *rolagem,struct StatusBox_bitmaps *sbox,ALLEGRO_BITMAP *prompt,ALLEGRO_BITMAP *selecao,ALLEGRO_BITMAP *roll_bar,ALLEGRO_BITMAP *apontador,ALLEGRO_BITMAP *fundo_carta,ALLEGRO_BITMAP *fundo_menu,ALLEGRO_BITMAP *deck_meio,ALLEGRO_BITMAP *deck_cheio,struct Player *jogador,struct Player *adversario,ALLEGRO_DISPLAY *display,ALLEGRO_BITMAP *fundo,ALLEGRO_FONT *font,ALLEGRO_FONT *font2,ALLEGRO_COLOR color,bool *sair,int *posX,int *posY,int *dltZ,bool *mouse,bool *mouse2,bool *mouse_lado,int *keychar,bool *repete_keychar,ALLEGRO_EVENT_QUEUE *event_queue,ALLEGRO_TIMER *keyb_press_timer,ALLEGRO_TIMER *mouse_press_timer) {
    if(card != NULL) {
        /*::: PONTO DE FUNCAO #8 ::: */
        if(card->origem->colecao == MASTER_SWORD && strcmp(aux->origem->elemento,"Light") == 0) {
            *(jogador->HP) = *(jogador->HP) + 20;
            if(*(jogador->HP) > *(jogador->MaxHP)) *(jogador->HP) = *(jogador->MaxHP);
        }

        else if(card->origem->colecao == GORON_RUBY && strcmp(aux->origem->elemento,"Fire") == 0) goron_ruby_acao2(id_acao,buffer,fim_de_jogo,rolagem,sbox,prompt,selecao,roll_bar,apontador,fundo_carta,fundo_menu,deck_meio,deck_cheio,jogador,adversario,display,fundo,font,font2,color,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);
        else if(card->origem->colecao == ZORAS_SAPPHIRE && strcmp(aux->origem->elemento,"Water") == 0) ScoutDrawMonster(id_acao,buffer,fim_de_jogo,rolagem,sbox,prompt,selecao,roll_bar,fundo_carta,fundo_menu,deck_meio,deck_cheio,apontador,jogador,adversario,display,fundo,font,font2,color,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);
    }
}

//Reatores ao equipar-se um ITEM.
void EquipItem(struct Deck *equipped,int id_acao,struct Card **buffer,bool *fim,struct CARD *equip,struct StatusBox_bitmaps *sbox,ALLEGRO_BITMAP *selecao,ALLEGRO_BITMAP *roll_bar,ALLEGRO_BITMAP *fundo_menu,ALLEGRO_BITMAP *fundo_carta,ALLEGRO_BITMAP *deck_meio,ALLEGRO_BITMAP *deck_cheio,ALLEGRO_BITMAP *pont,struct Player *jogador,struct Player *adversario,ALLEGRO_DISPLAY *display,ALLEGRO_BITMAP *fundo,ALLEGRO_BITMAP *prompt,ALLEGRO_FONT *font,ALLEGRO_FONT *font2,ALLEGRO_COLOR color,int *rolagem,bool *sair,int *posX,int *posY,int *dltZ,bool *mouse,bool *mouse2,bool *mouse_lado,int *keychar,bool *repete_keychar,ALLEGRO_EVENT_QUEUE *event_queue,ALLEGRO_TIMER *keyb_press_timer,ALLEGRO_TIMER *mouse_press_timer) {
    if(equip != NULL) {
        /*::: PONTO DE FUNCAO #9 ::: */
        if(equip->origem->colecao == ADULT_WALLET) adult_wallet_acao(id_acao,buffer,fim,sbox,selecao,roll_bar,fundo_menu,fundo_carta,deck_meio,deck_cheio,pont,jogador,adversario,display,fundo,prompt,font,font2,color,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer,rolagem);
        if(equip->origem->colecao == CLAIM_CHECK && equip->var_equip->claim_check_bool == true && strstr(equipped->card->origem->str_concat,"Weapon") != NULL) {
            DrawCard(id_acao,buffer,fim,rolagem,sbox,prompt,selecao,roll_bar,fundo_carta,fundo_menu,deck_meio,deck_cheio,pont,jogador,adversario,display,fundo,font,font2,color,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);
            equip->var_equip->claim_check_bool = false;
        }
    }
}

bool bazaar_seller_funct(int id_acao,struct Card **buffer,bool *fim,struct CARD *card,struct CARD *aux,int *rolagem,struct StatusBox_bitmaps *sbox,ALLEGRO_BITMAP *prompt,ALLEGRO_BITMAP *selecao,ALLEGRO_BITMAP *roll_bar,ALLEGRO_BITMAP *fundo_carta,ALLEGRO_BITMAP *deck_meio,ALLEGRO_BITMAP *deck_cheio,ALLEGRO_BITMAP *pont,struct Player *jogador,struct Player *adversario,ALLEGRO_DISPLAY *display,ALLEGRO_BITMAP *fundo_menu,ALLEGRO_BITMAP *fundo,ALLEGRO_FONT *font,ALLEGRO_FONT *font2,ALLEGRO_COLOR color,bool *sair,int *posX,int *posY,int *dltZ,bool *mouse,bool *mouse2,bool *mouse_lado,int *keychar,bool *repete_keychar,ALLEGRO_EVENT_QUEUE *event_queue,ALLEGRO_TIMER *keyb_press_timer,ALLEGRO_TIMER *mouse_press_timer) {
    if(card != NULL && card->origem->colecao == BAZAAR_SELLER && card->var_monster->bazaar_seller_bool == true && card->turn_silenced == 0) {
        bazaar_seller_acao(id_acao,buffer,fim,aux,rolagem,sbox,prompt,selecao,roll_bar,fundo_carta,deck_meio,deck_cheio,pont,jogador,adversario,display,fundo_menu,fundo,font,font2,color,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);
        card->var_monster->bazaar_seller_bool = false;
        return(true);
    }
    return(false);
}

void RecuperaStatsBasicos(struct CARD *card) {
    if(card->origem->monster != NULL) {
        card->attack = card->origem->monster->attack;
        card->MaxHP = card->origem->monster->MaxHP;
    }
    else if(card->origem->jrboss != NULL) {
        card->attack = card->origem->jrboss->attack;
        card->MaxHP = card->origem->jrboss->MaxHP;
    }
    else {
        card->attack = card->origem->boss->attack;
        card->MaxHP = card->origem->boss->MaxHP;
    }
}

void RecuperaMonsterStats(bool modo,struct CARD *card,struct Card **buffer,bool *fim,struct StatusBox_bitmaps *sbox,struct Player *jogador,struct Player *adversario,int *rolagem,ALLEGRO_BITMAP *prompt,ALLEGRO_BITMAP *selecao,ALLEGRO_BITMAP *roll_bar,ALLEGRO_BITMAP *fundo_carta,ALLEGRO_BITMAP *deck_meio,ALLEGRO_BITMAP *deck_cheio,ALLEGRO_BITMAP *pont,ALLEGRO_DISPLAY *display,ALLEGRO_BITMAP *fundo,ALLEGRO_FONT *font,ALLEGRO_FONT *font2,ALLEGRO_COLOR color,bool *sair,int *posX,int *posY,int *dltZ,bool *mouse,bool *mouse2,bool *mouse_lado,int *keychar,bool *repete_keychar,ALLEGRO_EVENT_QUEUE *event_queue,ALLEGRO_TIMER *keyb_press_timer,ALLEGRO_TIMER *mouse_press_timer) {
    //faz retornar os valores ORIGINAIS de ATK e HP dos monstros, alem de habilitar algumas variaveis.
    int contador;

    if(card != NULL) {
        if(card->turn_cooldown > 0 && modo == false) card->turn_cooldown--;    //TURN-BASED!
        if(card->turn_silenced > 0 && modo == false) card->turn_silenced--;

        bless_of_triforce_unit_unbuff(card,card->var_monster->bless_of_triforce_buff_cont);

        RecuperaStatsBasicos(card);

        //desfaz field effect
        if(modo == true) card->var_monster->bless_of_triforce_buff_cont -= jogador->var_tactic->bless_of_triforce_cont;
        else card->var_monster->bless_of_triforce_buff_cont -= adversario->var_tactic->bless_of_triforce_cont;

        if(card->var_monster->bless_of_triforce_buff_cont < 0) card->var_monster->bless_of_triforce_buff_cont = 0;

        if(modo == true) {
            EsvaziaListaQuantidadeAtaques(&(card->var_monster->lista_qte_ataques));
            AdicionaNovaQuantidadeAtaque(&(card->var_monster->lista_qte_ataques),NULL,1);
            card->var_monster->qte_ataques = 0;
            card->var_monster->damage_multiplier = 100;

            if(jogador->global_silence == true && card->turn_silenced == 0) card->turn_silenced += 1;

            card->var_monster->giant_leever_bool = false;
            card->var_monster->biri_bool = false;
            card->var_monster->spawn_bool = false;
            card->var_monster->pierre_cont = 0;
            card->var_monster->bomb_bag_bonus_dmg_cont = 0;
            card->var_monster->big_poe_bool = true;
            card->var_monster->bazaar_seller_bool = true;
        }
        else {
            card->var_monster->baby_dodongo_bool = false;
            card->var_monster->lizalfos_cont = 0;
            card->var_monster->spike_bool = true;
        }

        contador = card->var_monster->bless_of_triforce_buff_cont;  //a variavel vai ser atualizada pela funcao de buff.
        card->var_monster->bless_of_triforce_buff_cont = 0;
        bless_of_triforce_unit_buff(card,contador);

        //card->var_monster->twinrova_bool = false;
        //if(card->origem->colecao == TWINROVA && card->HP <= 80) card->var_monster->twinrova_bool = true;

        /* if(!toggle) {
            //AtualizaMesa(NULL,-1,0,buffer,fim,sbox,prompt,selecao,roll_bar,fundo_carta,deck_meio,deck_cheio,fundo,pont,jogador,adversario,display,font,font2,color,mouse,rolagem,&posX,&posY,NULL,NULL,NULL,-1,-1,0,-1,NULL);
            toggle = true;
        } */
    }
}

void AtivaAcaoEquip(struct CARD *card,int vez,int id_acao,struct Card **buffer,bool *fim,int *rolagem,struct StatusBox_bitmaps *sbox,ALLEGRO_BITMAP *prompt,ALLEGRO_BITMAP *selecao,ALLEGRO_BITMAP *roll_bar,ALLEGRO_BITMAP *fundo_carta,ALLEGRO_BITMAP *fundo_menu,ALLEGRO_BITMAP *deck_meio,ALLEGRO_BITMAP *deck_cheio,ALLEGRO_BITMAP *pont,struct Player *jogador,struct Player *adversario,ALLEGRO_DISPLAY *display,ALLEGRO_BITMAP *fundo,ALLEGRO_FONT *font,ALLEGRO_FONT *font2,ALLEGRO_COLOR color,bool *sair,int *posX,int *posY,int *dltZ,bool *mouse,bool *mouse2,bool *mouse_lado,int *keychar,bool *repete_keychar,ALLEGRO_EVENT_QUEUE *event_queue,ALLEGRO_TIMER *keyb_press_timer,ALLEGRO_TIMER *mouse_press_timer) {   //equipz q ativam tanto no turno do jogador quanto do adversario
    if(card != NULL) {
        /*::: PONTO DE FUNCAO #3 ::: */
        if(card->origem->colecao == GORON_RUBY) goron_ruby_acao(jogador,adversario);
        else if(card->origem->colecao == ZORAS_SAPPHIRE) zoras_sapphire_acao(jogador,adversario);

        else if(vez == 1) {
            if(card->origem->colecao == SKULL_MASK) skull_mask_acao2(id_acao,buffer,fim,rolagem,sbox,prompt,selecao,roll_bar,fundo_carta,fundo_menu,deck_meio,deck_cheio,pont,jogador,adversario,display,fundo,font,font2,color,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);
        }
    }

        //Vez: 1 -> Jogador; 2 -> Adversario
}

void AtivaAcaoMonstro(struct CARD *card,struct Player *jogador,struct Player *adversario,int vez) {    //Vez: 1 -> Jogador; 2 -> Adversario
    /*::: PONTO DE FUNCAO #4 ::: */
}

void BombchuEffect(bool *toggle,struct Player *jogador,struct Player *adversario,struct CARD **card,struct Deck *aux) {
    struct Deck *aux1;

    if(*card != NULL && (*card)->origem->colecao == BOMBCHU) {
        DestroyCard(aux,jogador,adversario);

        aux1 = (struct Deck *)malloc(sizeof(struct Deck));
        aux1->card = *card;
        DestroyCard(aux1,adversario,jogador);

        *card = NULL;
        (adversario->bombchu_cont)++;
        *toggle = false;
    }
}

void SituaMonstro(struct CARD *monstro,struct CARD *field,struct Player *jogador,struct Player *adversario) {    //atua somente ao ser chamado.
    printf("SITUANDO EM %s\n",field->origem->nome);
    bool toggle = AplicaMapaAdversario(adversario);

    /*::: PONTO DE FUNCAO #11 ::: */
    if(field->origem->colecao == DESERT_COLOSSUS || field->origem->colecao == HYRULE_CASTLE || field->origem->colecao == KAKARIKO_GRAVEYARD || field->origem->colecao == FIRE_TEMPLE /*OU outros*/) {
        FieldBoost(monstro,field->origem->elemento,jogador,adversario,toggle);
    }

    else if(field->origem->colecao == DEATH_MT_CRATER || field->origem->colecao == KOKIRI_FOREST || field->origem->colecao == LAKE_HYLIA || field->origem->colecao == GERUDO_FORTRESS || field->origem->colecao == GANONS_CASTLE /*OU outros*/) {
        FieldBoost2(monstro,field->origem->elemento,jogador,adversario,toggle);
    }
}

bool IncluiEmCampo(struct CARD **card,struct CARD *aux,int level_jog,struct CARD *field_jog,struct CARD *field_adv,struct Player *jogador,struct Player *adversario) {
    if(*card == NULL) {
        printf("\n\tCARD incluido: %s ",aux->origem->nome);
        *card = aux;

        if((*card)->origem->monster != NULL) (*card)->MaxHP = (*card)->origem->monster->MaxHP;
        else if((*card)->origem->jrboss != NULL) (*card)->MaxHP = (*card)->origem->jrboss->MaxHP;
        else (*card)->MaxHP = (*card)->origem->boss->MaxHP;

        if((*card)->origem->monster != NULL) (*card)->attack = (*card)->origem->monster->attack;
        else if((*card)->origem->jrboss != NULL) (*card)->attack = (*card)->origem->jrboss->attack;
        else (*card)->attack = (*card)->origem->boss->attack;
        (*card)->turn_cooldown = 0;
        (*card)->turn_silenced = 0;

        if((*card)->origem->monster != NULL && (*card)->origem->monster->level <= level_jog) (*card)->var_monster->spawn_bool = true;
        else if((*card)->origem->jrboss != NULL && (*card)->origem->jrboss->level <= level_jog) (*card)->var_monster->spawn_bool = true;
        else if((*card)->origem->boss != NULL && (*card)->origem->boss->level <= level_jog) (*card)->var_monster->spawn_bool = true;

        if(field_jog != NULL) SituaMonstro(*card,field_jog,jogador,adversario);
        else if(field_adv != NULL) SituaMonstro(*card,field_adv,jogador,adversario);

        return(true);
    }
    else return(false);
}

void DesfazBlueTektiteBuffSlot(struct CARD *card) {
    if(card != NULL && card->origem->colecao == BLUE_TEKTITE && card->turn_silenced == 0) {
        card->HP -= 20;
        card->MaxHP -= 20;
    }
}

void DesfazBlueTektiteBuff(struct Player *jogador,struct Player *adversario) {
    DesfazBlueTektiteBuffSlot(jogador->mesa->monstro1);
    DesfazBlueTektiteBuffSlot(jogador->mesa->monstro2);
    DesfazBlueTektiteBuffSlot(jogador->mesa->monstro3);
    DesfazBlueTektiteBuffSlot(jogador->mesa->monstro4);
    DesfazBlueTektiteBuffSlot(jogador->mesa->monstro5);
    DesfazBlueTektiteBuffSlot(jogador->mesa->monstro6);
    DesfazBlueTektiteBuffSlot(jogador->mesa->monstro7);

    DesfazBlueTektiteBuffSlot(adversario->mesa->monstro1);
    DesfazBlueTektiteBuffSlot(adversario->mesa->monstro2);
    DesfazBlueTektiteBuffSlot(adversario->mesa->monstro3);
    DesfazBlueTektiteBuffSlot(adversario->mesa->monstro4);
    DesfazBlueTektiteBuffSlot(adversario->mesa->monstro5);
    DesfazBlueTektiteBuffSlot(adversario->mesa->monstro6);
    DesfazBlueTektiteBuffSlot(adversario->mesa->monstro7);
}

void AtivaBlueTektiteBuffSlot(struct CARD *card) {
    if(card != NULL && card->origem->colecao == BLUE_TEKTITE && card->turn_silenced == 0) {
        card->MaxHP += 20;
        card->HP += 20;
    }
}

void AtivaBlueTektiteBuff(struct Player *jogador,struct Player *adversario) {
    AtivaBlueTektiteBuffSlot(jogador->mesa->monstro1);
    AtivaBlueTektiteBuffSlot(jogador->mesa->monstro2);
    AtivaBlueTektiteBuffSlot(jogador->mesa->monstro3);
    AtivaBlueTektiteBuffSlot(jogador->mesa->monstro4);
    AtivaBlueTektiteBuffSlot(jogador->mesa->monstro5);
    AtivaBlueTektiteBuffSlot(jogador->mesa->monstro6);
    AtivaBlueTektiteBuffSlot(jogador->mesa->monstro7);

    AtivaBlueTektiteBuffSlot(adversario->mesa->monstro1);
    AtivaBlueTektiteBuffSlot(adversario->mesa->monstro2);
    AtivaBlueTektiteBuffSlot(adversario->mesa->monstro3);
    AtivaBlueTektiteBuffSlot(adversario->mesa->monstro4);
    AtivaBlueTektiteBuffSlot(adversario->mesa->monstro5);
    AtivaBlueTektiteBuffSlot(adversario->mesa->monstro6);
    AtivaBlueTektiteBuffSlot(adversario->mesa->monstro7);
}

#endif // FUNCOES_SLOT_C_INCLUDED
