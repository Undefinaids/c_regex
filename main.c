#include <stdlib.h>
#include "my_regex.h"

int main (int argc, char ** argv)
{
    regex_t r;
    const char * regex_text;
    const char * find_text;
    if (argc != 3) {
        regex_text = "([a-zA-Z]+)\\ ([0-9]+)";
        find_text = "This 1 is nice 2 so 33 for 4254";
    }
    else {
        regex_text = argv[1];
        find_text = argv[2];
    }
    printf ("Trying to find '%s' in '%s'\n", regex_text, find_text);
    compile_regex(&r, regex_text);
    match_regex(&r, find_text);
    regfree(&r);
    return 0;
}