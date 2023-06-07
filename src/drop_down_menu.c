/*
** EPITECH PROJECT, 2022
** mypaint
** File description:
** reproducing paint
*/

#include "../include/my.h"

struct s_gui_drop_menu *create_drop_menu(sfVector2f position, sfVector2f size)
{
    struct s_gui_drop_menu *drop_menu = malloc(sizeof(struct s_gui_drop_menu));

    drop_menu->rect = sfRectangleShape_create();
    sfRectangleShape_setPosition(drop_menu->rect, position);
    sfRectangleShape_setSize(drop_menu->rect, size);
    sfRectangleShape_setFillColor(drop_menu->rect, sfWhite);
    return (drop_menu);
}

struct s_gui_drop_menu *add_option_drop_menu(struct s_gui_drop_menu *drop_menu)
{
    struct s_gui_options *new_button = malloc(sizeof(struct s_gui_options));
    struct s_gui_options *last_option = drop_menu->options;

    new_button->next = NULL;
    new_button->options = init_button((sfVector2f){165.0, 165.0}, (sfVector2f)
                                                                {10.0, 10.0});
    if (new_button->options == NULL) {
        free(new_button);
        return NULL;
    }
    if (drop_menu->options == NULL) {
        drop_menu->options = new_button;
    } else {
        while (last_option->next != NULL) {
            last_option = last_option->next;
        }
        last_option->next = new_button;
    }
    return (drop_menu);
}
