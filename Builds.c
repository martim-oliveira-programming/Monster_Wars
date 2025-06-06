#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "header.h"
#include <unistd.h> 

void get_attributes(Player *main_character) {
    if (strcmp(main_character->build, "Assassin") == 0) {
        main_character->weapon = "Basic Dagger";
        main_character->weapon_OFF_Hand = "Basic Dagger";
        
        // Initialize armor slots
        strcpy(main_character->armor[0], "");
        strcpy(main_character->armor[1], "");
        strcpy(main_character->armor[2], "");
        strcpy(main_character->armor[3], ""); 
        
        main_character->stats = (Attributes){
            .DEFENCE = 0,
            .DAMAGE = 4,
            .MAGIC_POWER = 1,
            .MAX_HP = 3,
            .MOUNT = NULL,
            .MAX_MANA = 10,
            .SUMMONS_STORAGE = 0,
            .SPEED = 20,
            .STEALTH = 10,
            .WEAPON_DAMAGE = 12,
            .WEAPON_USER = 1,
            .DUAL_WILDING = 1,
            .MAGIC_USER = 1,
        };//Total:60
    }
    else if (strcmp(main_character->build, "Tank") == 0) {
        main_character->weapon = "Basic Sword";
        main_character->weapon_OFF_Hand = "Basic Shield";
        main_character->abilities = (char*[]){"Shield Bash", NULL};
        
        // Initialize armor
        strcpy(main_character->armor[0], "Leather Helmet");
        strcpy(main_character->armor[1], "Leather Chestplate");
        strcpy(main_character->armor[2], "Leather Pants");
        strcpy(main_character->armor[3], "Leather Boots");
        
        main_character->stats = (Attributes){
            .DEFENCE = 10,
            .DAMAGE = 4,
            .MAGIC_POWER = 1,
            .MAX_HP = 20,
            .MOUNT = NULL,
            .MAX_MANA = 4,
            .SUMMONS_STORAGE = 0,
            .SPEED = 5,
            .STEALTH = 4,
            .WEAPON_DAMAGE = 12,
            .WEAPON_USER = 1,
            .DUAL_WILDING = 0,
            .MAGIC_USER = 1,
        };//Total:60
    }
    else if (strcmp(main_character->build, "Monk") == 0) {
        main_character->weapon = "";
        main_character->weapon_OFF_Hand = "";
        main_character->abilities = (char*[]){"Lethal Punch Barrage", NULL};
        
        // Initialize armor
        strcpy(main_character->armor[0], "Headband");
        strcpy(main_character->armor[1], "");
        strcpy(main_character->armor[2], "");
        strcpy(main_character->armor[3], "");
        
        main_character->stats = (Attributes){
            .DEFENCE = 0,
            .DAMAGE = 30,
            .MAGIC_POWER = 0,
            .MAX_HP = 10,
            .MOUNT = NULL,
            .MAX_MANA = 10,
            .SUMMONS_STORAGE = 0,
            .SPEED = 20,
            .STEALTH = 9,
            .WEAPON_DAMAGE = 0,
            //0 = False 1 = True
            .WEAPON_USER = 0,
            .DUAL_WILDING = 0,
            .MAGIC_USER = 0,
        };//Total:80. Higher because the player will never be able to use magic or weapons.
    }
    else if (strcmp(main_character->build, "Ninja") == 0) {
        main_character->weapon = "Basic Katana";
        main_character->weapon_OFF_Hand = "Shuriken";
        main_character->abilities = (char*[]){"Disguise", NULL};
        
        // Initialize armor slots
        strcpy(main_character->armor[0], "Headband");
        strcpy(main_character->armor[1], "Ninja chestplate");
        strcpy(main_character->armor[2], "Ninja pants");
        strcpy(main_character->armor[3], "Soundless sandals");
        
        main_character->stats = (Attributes){
            .DEFENCE = 0,
            .DAMAGE = 2,
            .MAGIC_POWER = 8,
            .MAX_HP = 2,
            .MOUNT = NULL,
            .MAX_MANA = 8,
            .SUMMONS_STORAGE = 0,
            .SPEED = 13,
            .STEALTH = 15,
            .WEAPON_DAMAGE = 12,
            .WEAPON_USER = 1,
            .DUAL_WILDING = 0,
            .MAGIC_USER = 1,
        };//Total:60
    }
    else if (strcmp(main_character->build, "Mage") == 0) {
        main_character->weapon = "Basic Grimoire";
        main_character->weapon_OFF_Hand = "";
        main_character->abilities = (char*[]){"Fire Bolt","Basic Healling", NULL};
        
        // Initialize armor
        //TODO Armors to items transform in ints
        strcpy(main_character->armor[0], "");
        strcpy(main_character->armor[1], "Mage Robe");
        strcpy(main_character->armor[2], "");
        strcpy(main_character->armor[3], "");
        
        main_character->stats = (Attributes){
            .DEFENCE = 0,
            .DAMAGE = 4,
            .MAGIC_POWER = 20,
            .MAX_HP = 4,
            .MOUNT = NULL,
            .MAX_MANA = 13,
            .SUMMONS_STORAGE = 0,
            .SPEED = 5,
            .STEALTH = 4,
            .WEAPON_DAMAGE = 10,
            .WEAPON_USER = 1,
            .DUAL_WILDING = 0,
            .MAGIC_USER = 1,
        };//Total:60
    }
    else if (strcmp(main_character->build, "Healer") == 0) {
        main_character->weapon = "Basic Grimoire";
        main_character->weapon_OFF_Hand = "";
        main_character->abilities = (char*[]){"Group Healing","Basic Healing", NULL};
        
        // Initialize armor
        strcpy(main_character->armor[0], "");
        strcpy(main_character->armor[1], "Healer's Glove");
        strcpy(main_character->armor[2], "");
        strcpy(main_character->armor[3], "");
        
        main_character->stats = (Attributes){
            .DEFENCE = 0,
            .DAMAGE = 0,
            .MAGIC_POWER = 10,
            .MAX_HP = 5,
            .MOUNT = NULL,
            .MAX_MANA = 17,
            .SUMMONS_STORAGE = 0,
            .SPEED = 6,
            .STEALTH = 12,
            .WEAPON_DAMAGE = 10,
            .WEAPON_USER = 1,
            .DUAL_WILDING = 0,
            .MAGIC_USER = 1,
        };//Total:60
    }
    else if (strcmp(main_character->build, "Summoner") == 0) {
        main_character->weapon = "Basic Grimoire";
        main_character->weapon_OFF_Hand = "";
        main_character->abilities = (char*[]){"Shadow Dog Summon","Basic Healing", NULL};
        
        // Initialize armor
        strcpy(main_character->armor[0], "");
        strcpy(main_character->armor[1], "");
        strcpy(main_character->armor[2], "");
        strcpy(main_character->armor[3], "");
        
        main_character->stats = (Attributes){
            .DEFENCE = 0,
            .DAMAGE = 0,
            .MAGIC_POWER = 11,
            .MAX_HP = 7,
            .MOUNT = NULL,
            .MAX_MANA = 18,
            .SUMMONS_STORAGE = 2,
            .SPEED = 6,
            .STEALTH = 12,
            .WEAPON_DAMAGE = 2,
            .WEAPON_USER = 1,
            .DUAL_WILDING = 0,
            .MAGIC_USER = 1,
        };//Total:60
    }

    else if (strcmp(main_character->build, "Balanced") == 0) {
        main_character->weapon = "Basic Sword";
        main_character->weapon_OFF_Hand = "Basic Grimoir";
        main_character->abilities = (char*[]){"Strength Boost","Fire Bolt", NULL};
        
        // Initialize armor
        strcpy(main_character->armor[0], "");
        strcpy(main_character->armor[1], "Leather Chestplate");
        strcpy(main_character->armor[2], "Leather Pants");
        strcpy(main_character->armor[3], "");
        
        main_character->stats = (Attributes){
            .DEFENCE = 6,
            .DAMAGE = 6,
            .MAGIC_POWER = 6,
            .MAX_HP = 6,
            .MOUNT = NULL,
            .MAX_MANA = 6,
            .SUMMONS_STORAGE = 6,
            .SPEED = 6,
            .STEALTH = 6,
            .WEAPON_DAMAGE = 6,
            .WEAPON_USER = 1,
            .DUAL_WILDING = 1,
            .MAGIC_USER = 1,
        };//Total:60
    }
}

void apply_ability_effect(Player *main_character ,Abilities player_ability){
    if (player_ability.EFFECT_TYPE == NONE){
    }
    else if(player_ability.EFFECT_TYPE == BOOST){
        char *effect = player_ability.EFFECTS;
        char *multiplier_str = strtok(effect," ");
        char *Attribute = strtok(NULL,"");
        float multiplier = atof(multiplier_str);
        free(effect);
        free(multiplier_str);

        if (strcmp(Attribute,"DEFENCE")==0){
            main_character->stats.DEFENCE *= multiplier;
        }else if (strcmp(Attribute,"MAX_HP")==0){
            main_character->stats.MAX_HP *= multiplier;
        }else if (strcmp(Attribute,"MAX_MANA")==0){
            main_character->stats.MAX_MANA *= multiplier;
        }else if (strcmp(Attribute,"MAGIC_POWER")==0){
            main_character->stats.MAGIC_POWER *= multiplier;
        }else if (strcmp(Attribute,"WEAPON_DAMAGE")==0){
            main_character->stats.WEAPON_DAMAGE *= multiplier;
        }else if (strcmp(Attribute,"DAMAGE")==0){
            main_character->stats.DAMAGE *= multiplier;
        }else if (strcmp(Attribute,"SPEED")==0){
            main_character->stats.SPEED *= multiplier;
        }else if (strcmp(Attribute,"STEALTH")==0){
            main_character->stats.STEALTH *= multiplier;
        }
        free(Attribute);
    }
    else if(player_ability.EFFECT_TYPE == SUMMON){
        char *effect = player_ability.EFFECTS;
        char *ammount_str = strtok(effect," ");
        char *SUMMON = strtok(NULL,"");
        int ammount = atoi(ammount_str);
        int summon_id = atoi(SUMMON);
        free(effect);
        free(ammount_str);
        free(SUMMON);


    }
    

}

Abilities* get_ability_by_id(int id) {
    for (int i = 0; i < TOTAL_ABILITIES; i++) {
        if (ALL_abilities[i].ID == id) {
            return &ALL_abilities[i];
        }
    }
    return NULL; // Not found
}

NPC* get_npc_by_id(int id){
    for(int i = 0;i<TOTAL_SUMMONS;i++){
        if (ALL_summons[i].ID == id){
            return &ALL_summons[i];
        }
    }
    return NULL;
}

Items* get_items_by_id(int id){
    for(int i = 0;i<TOTAL_ITEMS;i++){
        if (ALL_items[i].ID == id){
            return &ALL_items[i];
        }
    }
    return NULL;
}
