# ilsic
**I** **l**ike **s**trings **i**n **C**. Some personal library for working with strings in C. I don't think it is actually useful. But there is still usage instruction, hehe. ![Usage examples](https://github.com/eeevi/ilsic/blob/main/ilsic/main.c).

## How to use?
I'm glad you're asking! Here we have a struct `basic_string` and it has two fields:
```c
struct basic_string
{
        _size size; /* uint64_t or uint32_t if _X32 defined. */
        char  *content;
};
```
So you basically declaring struct basic_string and working with it. For this there we have some useful functions!
```c
/* Declare. */
struct basic_string p_string;

/* Init empty string with 'count' size. */
void p_set_size(struct basic_string*, _size);

/* Free memory, allocate again and copy some bad c_string to super cool p_string. */
void p_strcpy(struct basic_string*, char*);

/* Can also concatenate strings. */
void p_concat(struct basic_string*, char*);

/* Compare two strings. Same as strcmp. */
int8_t p_compare(struct basic_string*, char*);

/* Apply some function to every char. */
void p_applicate(struct basic_string*, void* (*)(char));

/* Free content and set size to zero. */
void p_remove(struct basic_string*);
```
