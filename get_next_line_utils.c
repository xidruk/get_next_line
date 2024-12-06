#include "get_next_line.h"

size_t get_length(const char *string)
{
    size_t length;

    if (!string)
        return (0);
    length = 0;
    while (string[length])
        length++;
    return (length);
}

static void copy(char *s1, char *s2, char *dest)
{
    int i;
    int j;

    i = 0;
    j = 0;
    if (s1)
    {
        while (s1[i])
        {
            dest[i] = s1[i];
            i++;
        }
    }
    if (s2)
    {
        while (s2[j])
        {
            dest[i] = s2[j];
            i++;
            j++;
        }
    }
    dest[i] = '\0';
}

char *join_strings(char *s1, char *s2)
{
    size_t s1_len;
    size_t s2_len;
    size_t new_len;
    char *joined_string;

    s1_len = 0;
    s2_len = 0;
    s1_len = get_length(s1);
    s2_len = get_length(s2);
    new_len = s1_len + s2_len + 1;
    joined_string = malloc(new_len * sizeof(char));
    if (!joined_string)
        return (NULL);
    copy(s1, s2, joined_string);
    free(s1);
    return(joined_string);
}

char *c_search(const char *s_in_str, int c)
{
    if (!s_in_str)
        return (NULL);
    while (*s_in_str)
    {
        if (*s_in_str == c)
        {
            return ((char *)s_in_str);
        }
        s_in_str++;
    }
    if (c == '\0')
        return ((char *)s_in_str);
    return (NULL);
}

char *duplicate_string(const char *or_str)
{
    char *dpc_string;
    size_t index;

    index = 0;
    dpc_string = malloc((get_length(or_str) + 1) * sizeof(char));
    if (!dpc_string)
        return (NULL);
    while (or_str[index])
    {
        dpc_string[index] = or_str[index];
        index++;
    }
    dpc_string[index] = '\0';
    return (dpc_string);
}
