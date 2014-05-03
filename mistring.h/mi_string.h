#ifndef MI_STRING_H_INCLUDED
#define MI_STRING_H_INCLUDED
#include <stdlib.h>
#include <stdio.h>
char * str_chr (const char* ,int );
int str_cmp (const char* ,const char* );
int str_cmpi (const char* ,const char* );
int str_ncmp (const char* ,const char* ,int );
char * str_str (const char* ,const char* );
char * str_cat (char* ,const char* );
char * str_cpy (char* ,const char* );
int str_len (const char* );
char * str_upr (char* );
char * str_lwr (char* );
#endif // MI_STRING_H_INCLUDED
