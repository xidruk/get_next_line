# Get Next Line

The Get Next Line project is a part of the 42 Network curriculum. It involves creating a function that reads one line at a time from a file descriptor.

## Features

- Reads a line from a file descriptor until a newline or EOF.
- Handles multiple file descriptors simultaneously.
- Efficient memory management.

## How to Use

1. Include `get_next_line.h` in your project.
2. Call `get_next_line(int fd)` to read lines from a file descriptor.

## Files

- `get_next_line.c`: Main implementation.
- `get_next_line_utils.c`: Helper functions.
- `get_next_line.h`: Header file with function prototypes.
- `Makefile`: For compiling the project (YOU DON'T NEED IT).

## Compilation

```bash
make
```

## Example Usage

```c
#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int main(void) {
    int fd = open("test.txt", O_RDONLY);
    char *line;

    while ((line = get_next_line(fd)) != NULL) {
        printf("%s", line);
        free(line);
    }
    close(fd);
    return 0;
}
```

## Notes

- Define `BUFFER_SIZE` for custom buffer sizes.
- Allowed functions: `read`, `malloc`, `free`.
- Ensure proper memory management to avoid leaks.

Enjoy coding with Get Next Line!

