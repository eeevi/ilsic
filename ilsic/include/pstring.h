#include <stdint.h>

#ifndef _X32
  typedef uint64_t _size;
#else
  typedef uint32_t _size;
#endif

struct basic_string
{
        _size size;
        char  *content;
};

/* Apply some function to every char. */
void
p_map(struct basic_string*, void* (*)(char));

/* Init empty string with 'count' size. */
void
p_set_size(struct basic_string*, _size);

/* Copy some bad c_string to super cool p_string. */
void
p_strcpy(struct basic_string*, char*);

/* Concat strings. */
void
p_concat(struct basic_string*, char*);

/* Compare two string. Will return strcmp() result. */
int8_t
p_compare(struct basic_string*, char*);

/* Slice p_string content from left to right. */
void
p_slice(struct basic_string*, _size, _size);

/* Remove free content and set size to zero. */
void
p_remove(struct basic_string*);
