/*
    @ Personal strings lib.
    @ In fact, I don't think it is really useful.
    @ Contribute or report an issue: github.com/eeevi/ilsic
*/

#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <stdlib.h>

#include "include/pstring.h"


void
p_map(struct basic_string* str, void* (*iter_f)(char))
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
p_slice(struct basic_string* str, _size left, _size right)
{
    if (!str->size || \
        str->size < right || \
        str->size < left || \
        right <= left)
    {
        perror("p_slice failed, invalid indexes.");
        return;
    }

    _size len    = right - left + 1;
    _size temp_i = 0;
    char  temp[len];

    for (int i = left; i < right; i++)
        temp[temp_i++] = str->content[i];

    temp[temp_i] = '\0';

    free(str->content);
    str->size    = len;
    str->content = (char *)malloc(sizeof(char) * len);

    strcpy(str->content, temp);
}


void
p_remove(struct basic_string* str)
{
    free(str->content);
    str->size = 0;
}
