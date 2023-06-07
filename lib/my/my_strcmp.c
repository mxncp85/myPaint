/*
** EPITECH PROJECT, 2022
** CPOOLDAY08
** File description:
** Write a function that displays the content of an array of words.
*/

int my_strlen(char const *str);

int my_strcmp(char const *s1, char const *s2)
{
    int diff = 0;
    int i = 0;

    if (my_strlen(s1) > my_strlen(s2))
        return 1;
    if (my_strlen(s1) < my_strlen(s2))
        return 1;
    while (s1[i] != '\0' && s2[i] != '\0') {
        if (s1[i] != s2[i])
            return 1;
        i++;
    }
    return 0;
}
