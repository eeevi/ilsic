/*
    @ Main file.
    @ Some p_string tests and examples here.
*/

#include <stdio.h>
#include <stdint.h>
#include "include/pstring.h"
#include "include/main.h"

int
main(void)
{
    /* Here we declaring basic_string struct, which is defined in pstring.h
       This struct has only two fileds:
                    uint64_t or uint32_t size - current string size;
                    char* content - current string content;

        Functions for work with this stuff is also declared in pstring.h
    */
    struct basic_string p_string;

    /* Set empty string with some size. */
    p_set_size(&p_string, 10);

    /* From now we can set content manually, but this is not cool
       and also it will not increase our size field ;( */

    /* So let's copy some c_string to p_string content and set some size.
       For this we have the p_strcpy function. */
    p_strcpy(&p_string, "Some string, uwu!");

    /* Yes, it's length can be >10, because we will allocate memory one more time. */
    _CONTENT(p_string);
    _SIZE(p_string);

    /* But what about concatenation? 
       Also pretty easy. */
    p_concat(&p_string, " Concating like it's 80's!");

    /* And once again we just reallocating memory. */
    _CONTENT(p_string);
    _SIZE(p_string);

    /* Compare two string. Will return same as strcmp. (-1; 0; 1). */
    // int8_t result = p_compare(&p_string, "Some string.");

    /* switch (result) {
        case -1:
            printf("LOWER\n");
            break;
        case 0:
            printf("EQ\n");
            break;
        case 1:
            printf("HIGHER\n");
            break;
        default:
            break;
    }*/

    /* We also can apply some function to every char of p_string.
       Only need pass a pointer to the function, which gets some char as an argument.
       Also cast function pointer to void to avoid warns. */
    p_map(&p_string, (void *)&something);
    _NEWLINE;

    /* Can also slice p_strings like this. */
    p_strcpy(&p_string, "First part. Second part.");
    _CONTENT(p_string);

    p_slice(&p_string, 0, 11);
    _CONTENT(p_string);        /* First part. */

    /* And again. */
    p_slice(&p_string, 6, 12);
    _CONTENT(p_string);       /* part. */

    /* Remove content and set size to zero. */
    p_remove(&p_string);
    _SIZE(p_string);

    return 0;
}


void
something(char c)
{
    switch (c) {
        case 'o': case 'a': case 'u':
            printf("nii");
            break;
        default:
            printf("%c", c);
            break;
    }
}
