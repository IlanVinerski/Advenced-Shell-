#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<sys/types.h>
#include<unistd.h>

int splitString(char* str, char* command[5]);

int main(int argc, char* argv[])
{

	char start1[25] = "/home/braude/";
	char start2[25] = "/bin/";
	char* args[5];
	char buff[256];
	int pid, i = 0;

	printf("AdvShell>");
	fgets(buff, 100, stdin);

	splitString(buff, args);

	//loop until we get GoodBye we run 

	while (strcmp(buff, "GoodBye\n") != 0)

	{

		if ((pid = fork()) == -1)
		{
			perror("Error fork\n");
			exit(1);
		}

		if (pid == 0)
		{
			execvp(args[0], args); //execute the commend from the user
			execv(args[0], args);
			printf("Not Supported\n");
		}

		wait();

		printf("AdvShell>");
		fgets(buff, 100, stdin); //get new commend to execute
		splitString(buff, args);
	}

	if ((pid = fork()) == -1)
	{
		perror("Error fork\n");
		exit(1);
	}

	if (pid == 0)
	{
		execvp(args[0], args);
		execv(args[0], args);
	}

	return 0;
}


int splitString(char* str, char* command[5])
{
	char args[256];
	int j = 0, i, ctr = 0, retVal = 0;
	for (i = 0; i <= (strlen(str)); i++) {
		// if space or NULL found, assign NULL into newString[ctr]
		if (str[i] == ' ' || str[i] == '\n') {
			args[j] = '\0';
			command[ctr] = (char*)malloc(sizeof(char*) * j);

			if (command[ctr] == NULL) {
				printf("allocation failed\n");
				exit(1);
			}
			strcpy(command[ctr], args);
			ctr++;  //for next word
			j = 0;    //for next word, init index to 0
		}
		else {
			if (str[i] != '\n') {
				args[j] = str[i];
				j++;
			}

		}
	}

	retVal = ctr;
	for (ctr; ctr < 5; ctr++)
		command[ctr] = NULL;
	return retVal;
}

