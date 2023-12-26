# Advenced-Shell-
I implemented a new shell in the C language in the Linux operating system, the shell will support all the usual commands, in the usual shell. But will expand its capabilities with other additional commands that do not exist in it. The additional commands support the checking system and create a test, at the end of which the system checks the test, and prints the final grade. The remaining commands are in the text file and can be used.
The additional commands are:

CreateExam: This command accepts 3 parameters: the name of the exam file, the subject of the exam, the name of the exam writer.
Asks the user to enter the desired number of questions. Then she lets him take in a question and 4
Possible answers. At the end of receiving all the questions, the command will create a copy of the exam, by name
The exam file (first parameter). At the beginning of the file, the exam subject will appear, in the second line
The number of questions, then the questions in the order they were entered. And the message will appear at the bottom of the page
"Successfully" then there is the exam writer.

SolExam: (creating a file for correct answers)
This command receives parameter 1: the name of the exam file, asking the user to enter the number
The correct answer to each question in order, that is, the first number for the first question
And so on. This command identifies the number of questions in the exam and according to this number allows
for the user to enter answers. When finished, you will save a copy with the name "exam_name_SOL" which contains
Number the correct answer in order from question 1 to last.

StartExam: (taking the exam and saving a solution file for each user)
This command accepts 2 parameters: the name of the exam file, the name of the exam. Presents the test, ID
The number of questions in the test, the user enters the question number and answer number, upon completion
Receiving the data, the command will create a new file named "Exam Name_Operation Name". When
In the file will appear an answer to each question according to the order of the questions (first to last question) without
Connection to the order of entering the answers.

CheckExam: (checking the exam file)
This command receives 2 parameters: the name of the exam, the name of the operation, the command will open the file
The answers according to the name of the exam (name of the exam plus Sol_) will count the number of correct answers
By comparing the student's solution with the answer file. and print into a file named " there
Exam_name of operation_ Grade "the number of correct answers.

CalcGrade: (exam grade calculation)
This command accepts 2 parameters: the name of the exam file, the name of the operation, you will open the test file
created from the previous command. and according to the number of questions you will calculate the final grade of the exam,
Add it to the end of the test file with the message Final Grade: In addition, it will display on the screen
The name of the student, the name of the exam and final grade. Note that this command does not create a new file but updates an existing file.

GoodBye: This command exits the program, closes the advanced_shell and returns to the original shell.
