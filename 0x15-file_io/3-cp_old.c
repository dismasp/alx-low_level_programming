#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdarg.h>
#include <errno.h>

#define BUFFER_SIZE 1024

/**
 * print_error - Print an error message to the standard error stream.
 *
 * @message: The error message to print.
 * @exit_code: The exit code to return to the operating system.
 *
 * Return: Nothing.
 */

void print_error(char *message, int exit_code, ...)
{
va_list args;
va_start(args, exit_code);
vfprintf(stderr, message, args);
va_end(args);
exit(exit_code);
}

/**
 * copy_file - Copy the contents of one file to another.
 *
 * @file_from: The path of the file to copy from.
 * @file_to: The path of the file to copy to.
 *
 * Return: Nothing.
 */

void copy_file(char *file_from, char *file_to)
{
int fd_from, fd_to;
ssize_t n_read, n_written;
char buffer[BUFFER_SIZE];

fd_from = open(file_from, O_RDONLY);
if (fd_from == -1)
print_error("Error: Can't read from file %s\n", 98, file_from);

fd_to = open(file_to, O_CREAT | O_WRONLY | O_TRUNC, 0644);
if (fd_to == -1)
print_error("Error: Can't write to %s\n", 99, file_to);

while ((n_read = read(fd_from, buffer, BUFFER_SIZE)) > 0)
{
n_written = write(fd_to, buffer, n_read);
if (n_written == -1)
print_error("Error: Can't write to %s\n", 99, file_to);
}

if (n_read == -1)
print_error("Error: Can't read from file %s\n", 98, file_from);

if (close(fd_from) == -1)
print_error("Error: Can't close fd %d\n", 100, fd_from);

if (close(fd_to) == -1)
print_error("Error: Can't close fd %d\n", 100, fd_to);
}

/**
 * main - Entry point of the program.
 *
 * @argc: The number of arguments passed to the program.
 * @argv: An array of pointers to the arguments.
 *
 * Return: 0 on success, 97-100 on failure.
 */

int main(int argc, char *argv[])
{
if (argc != 3)
/* return (print_error("Usage: cp file_from file_to\n", 97));*/
print_error("Usage: cp file_from file_to\n", 97);
copy_file(argv[1], argv[2]);

return (0);
}
