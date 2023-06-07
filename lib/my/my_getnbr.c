/*
** EPITECH PROJECT, 2022
** my_getnbr
** File description:
** Reverses the string
*/

int my_getnbr(char *input)
{
    int i = 0;
    int output = 0;
    int negative = 0;

    if (input[0] == '-') {
        i++;
        negative = 1;
    }
    while (input[i] != '\0') {
        output = ((output * 10) + (input[i] - 48));
        i++;
    }
    if (negative == 1)
        output = -output;
    return (output);
}
