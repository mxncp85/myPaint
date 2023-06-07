/*
** EPITECH PROJECT, 2022
** mypaint
** File description:
** reproducing paint
*/

#include <stdio.h>
#include <SFML/Graphics.h>
#include "../include/my.h"

int main() {
    // Set up window and font
    sfRenderWindow* window;
    sfVideoMode mode = { 800, 600, 32 };
    window = sfRenderWindow_create(mode, "SFML Window", sfResize | sfClose, NULL);
    sfFont* font = sfFont_createFromFile("arial.ttf");
    
    // Create the menu
    char* options[] = {};
    createDropDownMenu(window, font, (sfVector2f){ 50, 50 }, "Menu Title", options, 0);
    
    // Main loop
    while (sfRenderWindow_isOpen(window)) {
                // Process events
        sfEvent event;
        while (sfRenderWindow_pollEvent(window, &event)) {
            if (event.type == sfEvtClosed) {
                sfRenderWindow_close(window);
            }
            // Check if menu is clicked
            /*if (event.type == sfEvtMouseButtonPressed) {
                sfVector2i mousePos = sfMouse_getPositionRenderWindow(window);
                sfFloatRect menuRect = sfRectangleShape_getGlobalBounds(menuBox);
                if (sfFloatRect_contains(&menuRect, mousePos.x, mousePos.y)) {
                    // Toggle the menu's visibility
                    menuVisible = !menuVisible;
                }
            }
            // Check if an option is clicked
            if (event.type == sfEvtMouseButtonPressed && menuVisible) {
                sfVector2i mousePos = sfMouse_getPositionRenderWindow(window);
                for (i = 0; i < numOptions; i++) {
                    sfFloatRect optionRect = sfRectangleShape_getGlobalBounds(optionBoxes[i]);
                    if (sfFloatRect_contains(&optionRect, mousePos.x, mousePos.y)) {
                        // Perform action for selected option
                        printf("Selected option: %s\n", options[i]);
                        menuVisible = false;
                    }
                }
            }*/
        }
        
        // Draw menu if visible
        /*if (menuVisible) {
            for (i = 0; i < numOptions; i++) {
                sfRenderWindow_drawRectangleShape(window, optionBoxes[i], NULL);
                sfRenderWindow_drawText(window, optionTexts[i], NULL);
            }
        }*/
        
        // Display window contents
        sfRenderWindow_display(window);
    }
    
    // Clean up resources
    /*sfRectangleShape_destroy(menuBox);
    sfText_destroy(menuTitle);
    sfRectangleShape_destroy(optionBox);
    sfText_destroy(optionText);
    sfFont_destroy(font);*/
    sfRenderWindow_destroy(window);
    
    return 0;
}

void createDropDownMenu(sfRenderWindow* window, sfFont* font, sfVector2f pos, char* title, char* options[], int numOptions) {
    sfRectangleShape* menuBox = sfRectangleShape_create();
    sfText* menuTitle = sfText_create();
    sfRectangleShape* optionBox = sfRectangleShape_create();
    sfText* optionText = sfText_create();
    sfVector2f menuSize = { 150, 30 };
    sfVector2f optionSize = { 150, 30 };
    int i;
    
    // Set up menu box
    sfRectangleShape_setSize(menuBox, menuSize);
    sfRectangleShape_setPosition(menuBox, pos);
    sfRectangleShape_setFillColor(menuBox, sfWhite);
    sfRectangleShape_setOutlineColor(menuBox, sfBlack);
    sfRectangleShape_setOutlineThickness(menuBox, 2);
    
    // Set up menu title
    sfText_setString(menuTitle, title);
    sfText_setFont(menuTitle, font);
    sfText_setCharacterSize(menuTitle, 20);
    sfText_setFillColor(menuTitle, sfBlack);
    sfText_setPosition(menuTitle, pos);
    
    // Draw menu box and title
    sfRenderWindow_drawRectangleShape(window, menuBox, NULL);
    sfRenderWindow_drawText(window, menuTitle, NULL);
    
    // Loop through options and draw buttons
    for (i = 0; i < numOptions; i++) {
        sfVector2f optionPos = { pos.x, pos.y + menuSize.y + i * optionSize.y };
        sfRectangleShape_setSize(optionBox, optionSize);
        sfRectangleShape_setPosition(optionBox, optionPos);
        sfRectangleShape_setFillColor(optionBox, sfWhite);
        sfRectangleShape_setOutlineColor(optionBox, sfBlack);
        sfRectangleShape_setOutlineThickness(optionBox, 2);
        //sfRenderWindow_drawRectangleShape(window, optionBox, NULL);
        sfText_setString(optionText, options[i]);
        sfText_setFont(optionText, font);
        sfText_setCharacterSize(optionText, 18);
        sfText_setFillColor(optionText, sfBlack);
        sfText_setPosition(optionText, optionPos);
        //sfRenderWindow_drawText(window, optionText, NULL);
    }
}



