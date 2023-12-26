#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<string.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<sys/types.h>



int main(int argc, char* argv[])
{
	int fd1, fd2, fd3, q = 0, cnt = 0, i = 0, j = 0, rbytes, index, wbytes, mark;
	char buff[256] = { 0 }, buff3[256] = { 0 }, name[30] = { 0 }, name2[30] = { 0 }, buff2[256] = { 0 };
	char* tok;


	strcpy(name, "Grade_");
	strcat(name, argv[2]);
	strcat(name, "_");
	strcat(name, argv[1]);
	strcat(name, ".txt");

	if ((fd1 = open(name, O_RDONLY)) == -1) {
		printf("%s Not Found!\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	if ((rbytes = read(fd1, buff, 255)) == -1) {
		perror("read");
		exit(EXIT_FAILURE);
	}
	close(fd1);

	strcpy(buff3, buff);
	strcat(buff3, "\n");
	strcat(buff3, "\n");

	tok = strtok(buff, "/");
	cnt = atoi(tok); //the amount of true answears of the user

	tok = strtok(NULL, "/");
	q = atoi(tok); //get the amount of the qustion in the test


	mark = (cnt * 100) / q;
	sprintf(buff2, "%d", mark);
	strcpy(buff, "Final Grade: ");
	strcat(buff, buff2);

	printf("%s\n", argv[2]);
	printf("%s\n", argv[1]);
	printf("%s\n", buff);

	strcat(buff, "/100\n");
	strcat(buff3, buff);

	if ((fd1 = open(name, O_WRONLY | O_CREAT, 0664)) == -1) {
		perror("open");
		exit(EXIT_FAILURE);
	}

	//write from the buffer to text file the number of sol and qustions
	if ((wbytes = write(fd1, buff3, strlen(buff3))) == -1)
	{
		perror("write");
		exit(EXIT_FAILURE);
	}

	close(fd1);
	return 0;
}