#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<string.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<sys/types.h>


int main(int argc, char* argv[])
{
	int fd, i = 0, rbytes, index, wbytes;
	char buff[256] = { 0 }, name[20] = { 0 }, buff2[256] = { 0 };

	//creat the name of the test

	strcpy(name, argv[1]);
	strcat(name, ".txt");

	//open the test file for reading
	if ((fd = open(name, O_RDONLY)) == -1) {
		perror("open");
		exit(EXIT_FAILURE);
	}
	//reads the test to buffer
	if ((rbytes = read(fd, buff, 100)) == -1) {
		perror("read");
		exit(EXIT_FAILURE);
	}
	close(fd);


	//looking the number of the qustions in the test
	while ('0' > buff[i] || buff[i] > '9')
		i++;

	//make the number to int from char
	buff2[0] = buff[i];
	index = atoi(buff2);


	//clean the buffer
	strncpy(buff, "", sizeof(buff));

	//creating the text file of the solutions of the user
	strcpy(name, "Sol_");
	strcat(name, argv[1]);
	strcat(name, ".txt");

	//open the file for reading
	if ((fd = open(name, O_WRONLY | O_CREAT, 0664)) == -1) {
		perror("open");
		exit(EXIT_FAILURE);
	}
	//loop that runs the times of qustions and read the answear of the user
	for (i = 1; i <= index; i++) {
		printf("Insert True Sol for Question %d:\n", i);
		fgets(buff2, 256, stdin);
		strcat(buff, buff2);
		buff[strlen(buff)] = '\n';
	}

	//write the answears to sol test file
	if ((wbytes = write(fd, buff, strlen(buff)) == -1))
	{
		perror("write");
		exit(EXIT_FAILURE);
	}

	close(fd);

	return 0;
}