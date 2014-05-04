#include "mictype.h"

int is_alpha (int c)
{
    return ((c>='a'&&c<='z')||(c>='A'&&c<='Z'));
}

int is_digit (int c)
{
    return (c>='0'&&c<='9');
}

int to_upper (int c)
{
    return ((c>='a'&&c<='z')?c-32:c);
}

int to_lower (int c)
{
    return ((c>='A'&&c<='Z')?c+32:c);
}
