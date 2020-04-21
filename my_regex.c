//
// Created by undefinaids on 21/04/2020.
//

#include "my_regex.h"

// Maybe allow to pass comp flags in argument
int compile_regex(regex_t *r, const char *regex_text)
{
    char error_message[REGEX_MAX_ERROR_MSG];
    int status;

    status = regcomp(r, regex_text, REG_EXTENDED|REG_NEWLINE);
    if (status != 0) {
        regerror (status, r, error_message, REGEX_MAX_ERROR_MSG);
        printf("Regex error compiling '%s': %s\n", regex_text, error_message);
        return (0);
    }
    return (1);
}

int match_regex(regex_t *r, const char *to_match)
{
    const char *p = to_match;
    const int n_matches = 10;

    //TODO Change n_matches by the value in regex_t ?
    regmatch_t m[n_matches];

    while (1) {
        int nomatch = regexec(r, p, n_matches, m, 0);
        if (nomatch) {
            printf ("No more matches.\n");
            return nomatch;
        }
        for (int i = 0; i < n_matches; i++) {
            int start;
            int finish;
            if (m[i].rm_so == -1) {
                break;
            }
            start = m[i].rm_so + (p - to_match);
            finish = m[i].rm_eo + (p - to_match);
            if (i == 0) {
                printf ("$& is ");
            }
            else {
                printf ("$%d is ", i);
            }
            printf ("'%.*s' (bytes %d:%d)\n", (finish - start),
                    to_match + start, start, finish);
        }
        p += m[0].rm_eo;
    }
    return 0;
}