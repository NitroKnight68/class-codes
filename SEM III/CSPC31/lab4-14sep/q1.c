#include <stdio.h>
#include <stdlib.h>

struct Stud {
	int roll;
	char name[30];
	int marks[5];
	int total;
	float avg;
	char grade;
} s[5];

int main() {
	printf("------Student Details Input------\n\n");
	for(int i = 1; i <= 5; i++) {
		int stotal = 0;
		printf("Enter the Roll Number of Student %d:\n", i);
		scanf("%d", &s[i].roll);
		printf("Enter the Name of Student %d:\n", i);
		scanf("%s", s[i].name);
		printf("Enter the Marks of Student %d:\n", i);
		for(int j = 1; j <= 5; j++) {
			printf("Enter Marks in Subject %d:\n", j);
			scanf("%d", &s[i].marks[j]);
		}
		printf("\n");
		for(int j = 1; j <= 5; j++) {
			stotal += s[i].marks[j];
		}	
		s[i].total = stotal;	
		s[i].avg = stotal / 5.0;
		if(s[i].avg > 90.0) 
			s[i].grade = 'S';
		else if(s[i].avg >= 81.0 && s[i].avg <= 90.0)
			s[i].grade = 'A';
		else if(s[i].avg >= 71.0 && s[i].avg <= 80.0)
			s[i].grade = 'B';
		else if(s[i].avg >= 61.0 && s[i].avg <= 70.0)
			s[i].grade = 'C';
		else if(s[i].avg >= 51.0 && s[i].avg <= 60.0)
			s[i].grade = 'D';
		else if(s[i].avg >= 41.0 && s[i].avg <= 50.0)
			s[i].grade = 'E';
		else
			s[i].grade = 'F';
	}
	printf("------Student Records------\n\n");
	printf("Student Name    Roll Number     Total           Average         Grade\n");
	for(int i = 1; i <=5; i++)
		printf("%s           %d             %d             %f       %c\n",s[i].name ,s[i].roll ,s[i].total, s[i].avg, s[i].grade);
	return 0;
}
