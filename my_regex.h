//
// Created by undefinaids on 21/04/2020.
//

#ifndef REGEX_H
#define REGEX_H

#include <regex.h>
#include <stdio.h>
#define REGEX_MAX_ERROR_MSG 0x1000

int compile_regex(regex_t *r, const char *regex_text);
int match_regex(regex_t *r, const char *to_match);

#endif //REGEX_H
