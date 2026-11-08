#include <stdio.h>
#include <unistd.h> /* fork(), execvp() */
#include <string.h> /* strcspn() */
#include <sys/types.h> /* pid_t */
#include <sys/wait.h> /* wait() */

#define TEXT_LENGTH 256

int main(void)
{

	while (1) {
		char command[TEXT_LENGTH];

		printf("> ");
		fflush(stdout);

		if (fgets(command, TEXT_LENGTH, stdin) == NULL)
			return -1;

		command[strcspn(command, "\n")] = '\0';
		if (command[0] == '\0')
			continue;

		if (strcmp(command, "exit") == 0)
			break;

		char *args[] = {command, NULL};
		pid_t cmd = fork();

		switch(cmd) {
			case -1:
				perror("fork");
				_exit(1);

			case 0:
				execvp(command, args);
				perror(command);
				_exit(1);
		}

		int wstatus;
		wait(&wstatus);
	}

	return 0;
}
