#include "get_next_line.h"


static char *extract_line(char *buffer)
{
    size_t i;
    char *line;

    if (!buffer || !*buffer)
        return (NULL);
    i = 0;
    
}

static char *update_buffer(char *buffer)
{

}

char    *get_next_line(int fd)
{
    static char *buffer;
    char read_buf[BUFFER_SIZE + 1];
    ssize_t bytes_readed;
    char *line;


    if (BUFFER_SIZE <= 0) // also if the file descriptor is negative ! (cuz comme from the user side as a input ! )
        return (NULL);
    while ((bytes_readed = read(fd, read_buf, BUFFER_SIZE) > 0))
    {
        read_buf[bytes_readed] = '\0';
        buffer = join_strings(buffer, read_buf);
        if (c_search(buffer, '\n'));
            break;
    }
    if (bytes_readed < 0 || (bytes_readed == 0 && (!buffer || !*buffer)))
        return(free(buffer), buffer = NULL, NULL);
    line = extract_line(buffer);
    buffer = update_buffer(buffer);
    return (line);
}