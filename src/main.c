/*
** EPITECH PROJECT, 2022
** mypaint
** File description:
** reproducing paint
*/

#include <stdio.h>
#include "../include/my.h"

sfBool is_clicked(struct button_s *button, sfMouseButtonEvent *event)
{
    sfVector2f mouse_pos = {event->x, event->y};

    if (event->button == sfMouseLeft) {
        sfFloatRect rect = sfRectangleShape_getGlobalBounds(button->rect);
        if (sfFloatRect_contains(&rect, mouse_pos.x, mouse_pos.y)) {
            button->state = PRESSED;
            sfRectangleShape_setFillColor(button->rect, sfRed);
            printf("Button clicked\n");
            return (sfTrue);
        }
    }
    return (sfFalse);
}

sfBool is_released(struct button_s *button, sfMouseButtonEvent *event)
{
    sfVector2f mouse_pos = {event->x, event->y};

    if (event->button == sfMouseLeft) {
        sfFloatRect rect = sfRectangleShape_getGlobalBounds(button->rect);
        if (sfFloatRect_contains(&rect, mouse_pos.x, mouse_pos.y)) {
            button->state = RELEASED;
            sfRectangleShape_setFillColor(button->rect, sfGreen);
            return (sfTrue);
        }
    }
    return (sfFalse);
}

sfBool is_hover(struct button_s *button, sfMouseMoveEvent *event)
{
    sfVector2f mouse_pos = {event->x, event->y};
    sfFloatRect rect = sfRectangleShape_getGlobalBounds(button->rect);

    if (sfFloatRect_contains(&rect, mouse_pos.x, mouse_pos.y)) {
        button->state = HOVER;
        my_putstr("hover\n");
        return (sfTrue);
    }
    return (sfFalse);
}

struct button_s *init_button(sfVector2f position, sfVector2f size)
{
    struct button_s *button = malloc(sizeof(struct button_s));

    button->rect = sfRectangleShape_create();
    sfRectangleShape_setPosition(button->rect, position);
    sfRectangleShape_setSize(button->rect, size);
    sfRectangleShape_setFillColor(button->rect, sfWhite);
    button->is_clicked = &is_clicked;
    button->is_hover = &is_hover;
    button->is_released = &is_released;
    button->state = NONE;
    button->id = 0;
    return (button);
}

void window_create(sfRenderWindow* window)
{
    sfVector2i wPos = {0, 0};

    if (!window)
        return;
    sfRenderWindow_setPosition(window, wPos);
    sfRenderWindow_setFramerateLimit(window, 30);
    sfRenderWindow_clear(window, sfBlack);
    return;
}

void display_drop_menu(struct s_gui_drop_menu *drop_menu, sfRenderWindow *window)
{
    sfRenderWindow_drawRectangleShape(window, drop_menu->rect, NULL);
    if (drop_menu->options != NULL) {
        struct s_gui_options *last_option = drop_menu->options;
        while (last_option->next != NULL) {
            sfRenderWindow_drawRectangleShape(window, drop_menu->button, NULL);
            last_option = last_option->next;
        }
    }
}

int main(int ac, char **av)
{
    sfVideoMode mode = {1920, 1080, 32};
    sfRenderWindow* window;
    sfEvent event;
    struct button_s *button = init_button((sfVector2f){0, 0}, (sfVector2f){100, 100});

    window = sfRenderWindow_create(mode, "My Paint", sfClose, NULL);
    window_create(window);
    while (sfRenderWindow_isOpen(window)) {
        sfRenderWindow_display(window);
        sfRenderWindow_drawRectangleShape(window, button->rect, NULL);
        while (sfRenderWindow_pollEvent(window, &event)) {

            //struct s_gui_drop_menu *drop_menu = create_drop_menu((sfVector2f){155, 155}, (sfVector2f){100, 100});
            //if (drop_menu == NULL) {
            //         return NULL;
            //}
            //sfRenderWindow_drawRectangleShape(window, drop_menu->rect, NULL);

            if (event.type == sfEvtMouseButtonPressed) {
                if (button->is_clicked(button, &event.mouseButton) && button->id == 0) {}
                    
            }
            if (event.type == sfEvtMouseButtonReleased) {
                button->is_released(button, &event.mouseButton);
            }
            if (event.type == sfEvtMouseMoved) {
                if (button->is_hover(button, &event.mouseMove) && button->state != PRESSED)
                    sfRectangleShape_setFillColor(button->rect, sfGreen);
                else
                    sfRectangleShape_setFillColor(button->rect, sfWhite);
            }
            if (event.type == sfEvtClosed)
                sfRenderWindow_close(window);
        }
    }
    sfRenderWindow_destroy(window);
    return (0);
}
