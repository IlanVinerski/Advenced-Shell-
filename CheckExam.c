#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<string.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<sys/types.h>



int main(int argc, char* argv[])
{
	int fd1, fd2, fd3, q = 0, cnt = 0, i = 0, j = 0, rbytes, index, wbytes;
	char buff[256] = { 0 }, name[30] = { 0 }, name2[30] = { 0 }, buff2[256] = { 0 }, ch;

	//creating the name of true soultions file of the test
	strcpy(name, "Sol_");
	strcat(name, argv[1]);
	strcat(name, ".txt");


	if ((fd1 = open(name, O_RDONLY)) == -1) {
		perror("open");
		exit(EXIT_FAILURE);
	}

	//read to bufer the right solustions

	if ((rbytes = read(fd1, buff, 255)) == -1) {
		perror("read");
		exit(EXIT_FAILURE);
	}
	//create the name of the user solutions text file
	strcpy(name2, argv[2]);
	strcat(name2, "_");
	strcat(name2, argv[1]);
	strcat(name2, ".txt");

	//open it for reading
	if ((fd2 = open(name2, O_RDONLY)) == -1) {
		perror("open");
		exit(EXIT_FAILURE);
	}

	if ((rbytes = read(fd2, buff2, 255)) == -1) {
		perror("read");
		exit(EXIT_FAILURE);
	}

	//compere the right sol to user's sol
	for (i = 0; i < strlen(buff); i++)
	{
		if (buff[i] != '\n')
		{
			q++;
			if (buff[i] == buff2[i])
				cnt++;
		}
	}

	//create the new file of the number of true answears of the user
	strcpy(name, "Grade_");
	strcat(name, argv[2]);
	strcat(name, "_");
	strcat(name, argv[1]);
	strcat(name, ".txt");

	//open file for write to write the amount of true answears of the user for the test
	if ((fd3 = open(name, O_WRONLY | O_CREAT, 0664)) == -1) {
		perror("open");
		exit(EXIT_FAILURE);
	}
	//clean the buffer
	strncpy(buff, "", sizeof(buff));
	//get to buffer the amount of true answears and qustions
	buff[0] = cnt + '0';
	buff[1] = '/';
	buff[2] = q + '0';

	//write from the buffer to text file the number of sol and qustions
	if ((wbytes = write(fd3, buff, strlen(buff))) == -1)
	{
		perror("write");
		exit(EXIT_FAILURE);
	}

	//close all the text files
	close(fd1);
	close(fd2);
	close(fd3);
	return 0;
}