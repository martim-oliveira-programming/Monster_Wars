#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "header.h"
#include <unistd.h> 

int main() {
    GameState current_state = MENU;
    Story story = {0};
    Player main_character = {0};
    NPC chapter_npcs[1] = {0};

    // Main game loop
    while (current_state != QUIT) {
        switch(current_state) {
            
            case MENU:
                current_state = menu_selection();
                break;
                
            case PLAYING: {
                // Initialize new game if no save exists
                if (!file_exists("save.txt")) {
                    main_character = character_creation();
                    story.Chapter = Character_Creation;
                    save_game(story, main_character, chapter_npcs);
                } else {
                    // Load existing game
                    load_save(&story, &main_character, chapter_npcs);
                }

                // Gameplay loop
                char *next_action = "";
                while(current_state == PLAYING && strcmp(next_action, "Inventory") != 0) {
                    // Here you would add your actual game logic
                    next_action = get_input("What will you do next? (Type 'Inventory' to return to menu or 'Quit' to save and quit to the Main Menu): ");
                    
                    // Example of game logic
                    if (strcmp(next_action, "Quit") == 0) {
                        save_game(story,main_character,chapter_npcs);
                        current_state = MENU;
                    }
                    
                    free(next_action);
                }
                break;
            }
            case QUIT:
                printf("Goodbye!\n");
                break;
        }
    }

    // Cleanup
    if (main_character.name) free(main_character.name);
    if (chapter_npcs[0].name) free(chapter_npcs[0].name);
    return 0;
}
 