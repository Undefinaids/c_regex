//
// Created by undefinaids on 23/04/2020.
//

#include <string.h>
#include <stdlib.h>

static int how_many_match(char *str, char *to_match)
{
    size_t len = strlen(to_match);
    size_t max_len = strlen(str);
    int count = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        if (i + len > max_len)
            break;
        if (strncmp(str + i, to_match, len) == 0) {
            count += 1;
        }
    }
    return (count);
}

static char *replace_core(char *dest, char *str, char *to_match, char *replace)
{
    int i = 0;
    int nb_match = 0;
    size_t size_r = 0;
    size_t size_m = 0;

    size_r = strlen(replace);
    size_m = strlen(to_match);
    while (str[i] != '\0') {
        if (strncmp(str + i, to_match, size_m) == 0) {
            for (int j = 0; replace[j] != '\0'; j++) {
                dest[i + nb_match * (size_r - size_m) + j] = replace[j];
            }
            i += size_m;
            nb_match += 1;
        }
        else {
            dest[i + nb_match * (size_r - size_m)] = str[i];
            i++;
        }
    }
    dest[i + nb_match * (size_r - size_m)] = '\0';
    return (dest);
}

char *str_replace(char *str, char *match, char *replace)
{
    int nb_match = 0;
    size_t new_size = 0;
    char *dest;

    if (!replace || !match || !str) {
        return (NULL);
    }
    if (!(nb_match = how_many_match(str, match)))
        return (str);
    new_size = strlen(str) + (strlen(replace) - strlen(match)) * nb_match;
    if (!(dest = malloc(sizeof(char) * (new_size + 1)))) {
        return (NULL);
    }
    return (replace_core(dest, str, match, replace));
}