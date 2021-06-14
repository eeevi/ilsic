/*
    @ Personal strings lib.
    @ In fact, I don't think it is really usefull.
    @ Contribute or report an issue: github.com/eeevi/ilsic
*/

#include <string.h>
#include <stdint.h>
#include <stdlib.h>

#include "include/pstring.h"


void
p_applicate(struct basic_string* str, void* (*iter_f)(char))
{
    for (int i = 0; i < str->size; i++)
        (*iter_f)(str->content[i]);
}


void
p_set_size(struct basic_string* str, _size count)
{
    free(str->content);
    str->size    = 0;
    str->content = (char *)malloc(sizeof(char) * count);
}


void
p_strcpy(struct basic_string* str, char* s_str)
{
    p_set_size(str, strlen(s_str)+1);
    str->size = strlen(s_str);
    strcpy(str->content, s_str);
}


void
p_concat(struct basic_string* str, char* s_str)
{
    str->content = (char *)realloc(str->content, strlen(s_str)+1);
    str->size += strlen(s_str);
    strcat(str->content, s_str);
}


int8_t
p_compare(struct basic_string* str, char* s_str)
{
    return strcmp(str->content, s_str);
}


void
p_remove(struct basic_string* str)
{
    free(str->content);
    str->size = 0;
}
