/*
** EPITECH PROJECT, 2022
** mini shell 1
** File description:
** my header
*/

#ifndef MY_H_
    #define MY_H_
    #include <SFML/Graphics.h>
    #include <stdlib.h>
    #include <stddef.h>
    #include <SFML/System.h>
    #include <SFML/Audio.h>
    #include <stdbool.h>
    #include <time.h>

    enum e_gui_state {
        NONE = 0,
        HOVER,
        PRESSED,
        RELEASED
    };

    struct button_s {
        sfRectangleShape *rect;
        sfBool (*is_clicked)(struct button_s*, sfMouseButtonEvent*);
        sfBool (*is_hover)(struct button_s*, sfMouseButtonEvent*);
        sfBool (*is_released)(struct button_s *, sfMouseButtonEvent *);
        enum e_gui_state state;
        int id;
    };

    struct s_gui_options {
        struct s_gui_object *options;
        struct s_gui_options *next;
    };

    struct s_gui_drop_menu {
        sfRectangleShape *rect;
        struct s_gui_object *button;
        struct s_gui_options *options;
    };

    ///////////////////////////LIB/////////////////////////////
    int my_compute_power_rec(int, int);
    int my_compute_square_root(int);
    int my_find_prime_sup(int);
    int my_is_prime_it(int);
    int my_is_prime(int);
    int my_isneg(int);
    int my_put_nbr(int);
    void display(long, char);
    int my_pow(int, int);
    void my_putchar(char);
    int my_putstr(char const *);
    char *my_revstr(char*);
    char rev_char(char, char);
    int my_showmem(char const *, int);
    int my_showstr(char const *);
    void my_sort_int_array(int *, int);
    int my_str_isalpha(char const *);
    int my_str_islower(char const *);
    int my_str_isnum(char const *);
    int my_str_isprintable(char const *);
    int my_str_isupper(char const *);
    char *my_strcapitalize(char *);
    char *my_strcat(char * , char const *);
    char *my_strcpy(char *, char const *);
    int my_strlen(char const *);
    char *my_strlowcase(char *);
    char *my_strncat(char *, char const *, int);
    int my_strncmp(char const   *, char const *, int);
    char *my_strncpy(char *, char const *, int);
    char *my_strstr(char *, char const *);
    char *my_strupcase(char *);
    void my_swap(int *,int *);
    char *my_strdup(char const *);
    int my_strchr(char *str, char c);
    int my_show_word_array(char * const *tab);
    int my_put_float(double nbr , int precision);
    int my_putnbr_base_long(long nbr, char *base, int precision);
    int my_getnbr(char *input);
    int my_strcmp(char const *s1, char const *s2);
    //////////////////////////////////////////////////////////////

    ///////////////////////////MAIN.C/////////////////////////////

    //////////////////////////////////////////////////////////////
#endif /* !MY_H_ */
