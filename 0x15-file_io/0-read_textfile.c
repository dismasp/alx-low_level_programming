#include "main.h"
#include <stdlib.h>
/**
 * read_textfile - Reads a text file and prints it to the POSIX standard output
 *                 in reverse order.
 *
 * @filename: Pointer to the name of the file to read.
 * @letters: Number of letters to read and print.
 *
 * Return: Actual number of letters it could read and print in reverse order. 0
 *         if the file cannot be opened or read, filename is NULL, or if write
 *         fails or does not write the expected amount of bytes.
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
    int fd, bytes_read, bytes_written, i;
    char *buffer, temp;

    if (filename == NULL)
        return (0);

    buffer = malloc(sizeof(char) * (letters + 1));
    if (buffer == NULL)
        return (0);

    fd = open(filename, O_RDONLY);
    if (fd == -1)
    {
        free(buffer);
        return (0);
    }

    bytes_read = read(fd, buffer, letters);
    if (bytes_read == -1)
    {
        free(buffer);
        close(fd);
        return (0);
    }

    for (i = 0; i < bytes_read / 2; i++)
    {
        temp = buffer[i];
        buffer[i] = buffer[bytes_read - i - 1];
        buffer[bytes_read - i - 1] = temp;
    }

    buffer[bytes_read] = '\0';

    bytes_written = write(STDOUT_FILENO, buffer, bytes_read);
    if (bytes_written == -1 || bytes_read != bytes_written)
    {
        free(buffer);
        close(fd);
        return (0);
    }

    free(buffer);
    close(fd);

    return (bytes_written);
}
