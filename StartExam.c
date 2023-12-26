#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<string.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<sys/types.h>



int main(int argc, char* argv[])
{
	int fd, i = 0, j = 0, rbytes, index, wbytes, * arr, q, s;
	char buff[256] = { 0 }, name[30] = { 0 }, name2[30] = { 0 }, buff2[256] = { 0 };


	//create the name of the test for his txt file
	strcpy(name, argv[1]);
	strcat(name, ".txt");

	//opening text file of the test for reading
	if ((fd = open(name, O_RDONLY)) == -1) {
		perror("open");
		exit(EXIT_FAILURE);
	}
	//reads from the test text file to buff 
	if ((rbytes = read(fd, buff, 255)) == -1) {
		perror("read");
		exit(EXIT_FAILURE);
	}

	close(fd);
	//looking for the number of the qustion in the test
	while ('0' > buff[i] || buff[i] > '9')
		i++;

	//make the number from char to integer for using it in the loop 
	buff2[0] = buff[i];
	index = atoi(buff2);

	//printing to the screen the test for the user
	printf("%s", buff);

	//creating the name for the solution file text
	strcpy(name2, argv[2]);
	strcat(name2, "_");
	strcat(name2, argv[1]);
	strcat(name2, ".txt");

	//clean the buffer
	strncpy(buff, "", sizeof(buff));
	strncpy(buff2, "", sizeof(buff2));

	//open the new file text wchich will contail the answers of the user
	if ((fd = open(name2, O_WRONLY | O_CREAT, 0664)) == -1) {
		perror("open");
		exit(EXIT_FAILURE);
	}

	arr = (int*)malloc(index * sizeof(int));
	if (!arr) {
		printf("Memmory alloctaion failed\n");
		exit(1);
	}

	printf("\nInsert number of Question and sol:\n");

	//loop that gets the solutions of the user to buff
	for (i = 0; i < index; i++) {
		scanf("%d%d", &q, &s);
		arr[q - 1] = s;
	}

	strncpy(buff2, "", sizeof(buff2));

	for (i = 0; i < index; i++) {
		sprintf(buff, "%d", arr[i]);
		strcat(buff2, buff);
		buff2[strlen(buff2)] = '\n';
		buff2[strlen(buff2)] = '\n';
	}

	//write the answers to the text file of name the tset and the name of user

	if ((wbytes = write(fd, buff2, strlen(buff2))) == -1)
	{
		perror("write");
		exit(EXIT_FAILURE);
	}


	close(fd);
	return 0;
}