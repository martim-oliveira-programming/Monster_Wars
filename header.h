#ifndef HEADER_H
#define HEADER_H
 
#define MAX_INPUT 20
#define TOTAL_ABILITIES 10
#define TOTAL_ITEMS 2
#define TOTAL_SUMMONS 1

typedef enum{
    QUIT = -1,
    MENU,
    PLAYING,
    //PAUSE,
    //MISSION_SELECTION
}GameState;

typedef enum{
    NO,
    MAIN_HAND,
    OFF_HAND,
    HEAD,
    CHEST,
    LEGS,
    SHOES,
}Equipable;

typedef enum{
    Chapter_1,
    Chapter_2,
    Chapter_3,
    Chapter_4,
    Chapter_5,
}Chapters;

typedef struct story{
    int Chapter;
    int Path;
}Story;

typedef enum{
    NONE,
    BOOST,
    SUMMON,
    Group,
}EFFECT_TYPE;

typedef enum{
    CONSUMABLE,
    KEY,
}ITEM_TYPE;

typedef struct initial_build_attributes{
    char *MOUNT;
    int DEFENCE;
    int MAX_HP;
    int MAX_MANA;
    int SUMMONS_STORAGE;
    int MAGIC_POWER;
    int WEAPON_DAMAGE;
    int DAMAGE;
    int SPEED;
    int STEALTH;
    int WEAPON_USER;
    int DUAL_WILDING;
    int MAGIC_USER;
}Attributes;

typedef struct player_abilities{
    int ID;
    char *NAME;
    int HEALING;
    int DAMAGE;
    int MANA_COST;
    char *EFFECTS;
    int EFFECT_TYPE
}Abilities;

typedef struct items{
    int ID;
    char *name;
    char *effect;
    int effect_type;
    int item_type;
    int healling;
    int equipable;
}Items;

typedef struct summoning_contracts{
    NPC stats;
}SUMMONS;

typedef struct player {
    // Basic info
    char *name;
    char *hair_colour;
    int age;
    char *gender;
    // Game attributes
    char *build;
    Abilities *abilities;
    Items *items;
    SUMMONS summons;

    int *item_ammount;
    int armor[4];  // Array for armor slots (helm, chest, legs, boots)
    char *weapon;
    char *weapon_OFF_Hand;
    char RANK;
    int HUNGER;
    int Skill_Points;
    int LEVEL;
    int EXP;
    int HP;
    int MANA;
    int GOODNESS;
    Attributes stats;  // Contains all build-specific attributes
} Player;

typedef struct other_characters{
    int ID;
    char *name;
    int Ability_id;
    int EFFECT_TYPE;
    char* RANK;
    int LEVEL;
    int EXP;
    int HP;
    int MAX_HP;
    int DAMAGE;
    int SPEED;
}NPC;



char* get_input(char* input);

//Save Functions
void save_game(Story story,Player player,NPC* chapter_NPCs);
int load_save(Story *story, Player *player, NPC *chapter_NPCs);
void secure_wipe();
int file_exists(const char* filename);

//Menu Functions
int menu_selection();
int NewGame();
int Commands();
int Continue();
int QuitGame();

//Build Character Functions
Player character_creation();
Player add_inventory(Player main_character, char* item, int amount);
Player remove_inventory(Player main_character, char* item, int amount);
void get_attributes(Player *main_character);

//Abilities & Items
Abilities ALL_abilities[TOTAL_ABILITIES];
NPC ALL_summons[TOTAL_SUMMONS];
Items ALL_items[TOTAL_ITEMS];

#endif
