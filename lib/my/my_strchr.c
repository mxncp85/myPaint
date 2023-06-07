/*
** EPITECH PROJECT, 2022
** strchr
** File description:
** find a char in a string
*/

int my_strchr(char *str, char c)
{
    int i = 0;

    while (str[i] != '\0') {
        if (str[i] == c)
            return 1;
        i++;
    }
    return 0;
}
