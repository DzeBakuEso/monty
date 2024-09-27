#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>  /* Include this header for perror */

/* Redirects standard error to a specified file */
void redirect_stderr(const char *filename)
{
	int fd;

	/* Open the file for writing */
	fd = open(filename, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd == -1)
	{
		perror("Failed to open file for stderr redirection");
		exit(EXIT_FAILURE);
	}

	/* Redirect standard error to the file */
	if (dup2(fd, STDERR_FILENO) == -1)
	{
		perror("Failed to redirect stderr");
		close(fd);
		exit(EXIT_FAILURE);
	}

	/* Close the file descriptor, as it's no longer needed */
	close(fd);
}

