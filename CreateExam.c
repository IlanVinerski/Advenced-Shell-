#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<string.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<sys/types.h>



int main(int argc, char* argv[])
{
	int fd, q, i, j, rbytes, wbytes;
	char buff[256] = { 0 }, str[30] = { 0 }, index[10] = { 0 }, str2[10] = { 0 }, buff2[256] = { 0 }, fileN[30] = { 0 };


	strcpy(fileN, argv[1]);
	strcat(fileN, ".txt");

	/*opening new file for creating new test file*/

	if ((fd = open(fileN, O_WRONLY | O_CREAT, 0664)) == -1) {
		perror("open");
		exit(EXIT_FAILURE);
	}

	//create the name of the txt file in the name of the test

	strcat(buff, argv[2]);
	buff[strlen(buff)] = '\n';
	buff[strlen(buff)] = '\n';

	printf("Insert Number of Question:\n");

	//geting the number of questions in the test and use it for our question loop

	fgets(buff2, 255, stdin);
	q = atoi(buff2);
	strcat(buff, buff2);
	buff[strlen(buff)] = '\n';

	//loop that asking from the user to enter the question and the answers

	for (i = 0; i < q; i++) {
		strcpy(str, "Question ");
		index[0] = (i + 1) + '0';
		strcat(str, index);
		strcat(str, ":");
		strcat(buff, str);
		buff[strlen(buff)] = '\n';
		buff[strlen(buff)] = '\n';
		printf("Insert Question %d:\n", i + 1);
		fgets(buff2, 255, stdin);
		strcat(buff, buff2);
		printf("Insert 4 Answers:\n");
		buff[strlen(buff)] = '\n';

		for (j = 1; j <= 4; j++)
		{
			printf("%d. ", j);
			str2[0] = '\t';
			index[0] = j + '0';
			strcat(str2, index);
			strcat(str2, ". ");
			strcat(buff, str2);
			fgets(buff2, 255, stdin);
			strcat(buff, buff2);
			strncpy(str2, "", sizeof(str2));
		}
	}

	strcat(buff, "\n");
	strcat(buff, "\n");
	strcat(buff, "Successfully");
	strcat(buff, "\n");
	strcat(buff, argv[3]);

	//writeing the exam to text file 

	if ((wbytes = write(fd, buff, strlen(buff)) == -1))
	{
		perror("write");
		exit(EXIT_FAILURE);
	}
	//close the file

	close(fd);
	return 0;
}