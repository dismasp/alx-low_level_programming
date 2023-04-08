/**
 * create_file - creates a file and writes text content to it
 *
 * @filename: the name of the file to create
 * @text_content: the text to write to the file
 *
 * Return: 1 on success, -1 on failure
 *
 * Description: This function creates a new file with the specified filename
 * and writes the contents of the text_content string to it. If the file
 * already
 * exists, its contents will be truncated. The file will have permissions o
 * f rw-------
 * and the function will return -1 if the file cannot be created or
 * written to.
 *
 * This code was written by Dismas to meet the requirements of a project.
 */
#include <stdlib.h>
#include "main.h"

/**
 * create_file - creates a file and writes text content to it
 * @filename: the name of the file to create
 * @text_content: the text to write to the file
 *
 * Return: 1 on success, -1 on failure
 */
int create_file(const char *filename, char *text_content)
{
	int fd, len = 0, wrlen;

	if (filename == NULL)
		return (-1);

	if (text_content != NULL)
	{
		while (text_content[len])
			len++;
	}

	fd = open(filename, O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR);
	if (fd == -1)
		return (-1);

	if (len > 0)
	{
		wrlen = write(fd, text_content, len);
		if (wrlen != len)
			return (-1);
	}

	close(fd);
	return (1);
}

