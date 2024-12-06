#include "get_next_line.h"

static char *drs(const char *buff, size_t last)
{
    char *new_buff;
    size_t index;

    index = 0;
    new_buff = malloc((last + 2 ) * sizeof(char));
    if (!new_buff)
        return (NULL);
    while (buff[index] && buff[index] != '\n' && index < last )
    {
        new_buff[index] = buff[index];
        index++;
    }
    if (buff[index] == '\n')
        new_buff[index++] = '\n';
    new_buff[index] = '\0';
    return (new_buff);
}

static char *extract_line(char *buffer)
{
    char *line;
    size_t last;

    last = 0;
    if (!buffer || !*buffer)
        return (NULL);
    while (buffer[last] && buffer[last] != '\n')
        last++;
    line = drs(buffer, last);
    return (line);
}

static char *update_buffer(char *buffer)
{
    char *new_buffer;
    size_t start;

    start = 0;
    while (buffer[start] && buffer[start] != '\n')
        start++;
    if (!buffer[start])
        return (free(buffer), NULL);
    start++;
    new_buffer = duplicate_string(buffer + start);
    if (!new_buffer)
        return (free(buffer), NULL);
    free(buffer);
    return (new_buffer);
}

char    *get_next_line(int fd)
{
    static char *buffer;
    char read_buf[BUFFER_SIZE + 1];
    ssize_t bytes_readed;
    char *line;

    if (fd < 0 || BUFFER_SIZE <= 0)
        return (NULL);
    while (!c_search(buffer, '\n'))
    {
        bytes_readed = read(fd, read_buf, BUFFER_SIZE);
        if (bytes_readed < 0)
        {
            if (buffer)
                free(buffer);
            buffer = NULL;
            return (NULL);
        }
        if (bytes_readed == 0)
            break;
        read_buf[bytes_readed] = '\0';
        buffer = join_strings(buffer, read_buf);
        if (!buffer)
            return (NULL);
    }
    if (!buffer || !*buffer)
		return (free(buffer), buffer = NULL, NULL);
    line = extract_line(buffer);
    buffer = update_buffer(buffer);
    return (line);
}
