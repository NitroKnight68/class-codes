#include <stdio.h>
#include <stdlib.h>

struct Emp {
	int id;
	char name[30];
	long basic;
	double da;
	double hra;
	double salary;
	double yearly;
	double tax;
} s[5];

int main() {
	printf("------Employee Details Input------\n\n");
	for(int i = 1; i <= 5; i++) {
		printf("Enter the ID Number of Employee %d:\n", i);
		scanf("%d", &s[i].id);
		printf("Enter the Name of Employee %d:\n", i);
		scanf("%s", s[i].name);
		printf("Enter the Basic Pay of Employee %d:\n", i);
		scanf("%ld", &s[i].basic);
		printf("\n");
		s[i].da = 0.38 * s[i].basic;
		s[i].hra = 0.18 * s[i].basic;	
		s[i].salary = s[i].basic + s[i].da + s[i].hra;
		s[i].yearly = 12.0 * s[i].salary;
		if(s[i].yearly > 1000000.0) 
			s[i].tax = 0.20 * s[i].yearly;
		else if(s[i].yearly >= 800000.0 && s[i].yearly <= 1000000.0)
			s[i].tax = 0.15 * s[i].yearly;
		else if(s[i].yearly >= 600000.0 && s[i].yearly <= 800000.0)
			s[i].tax = 0.10 * s[i].yearly;
		else if(s[i].yearly >= 400000.0 && s[i].yearly <= 600000.0)
			s[i].tax = 0.07 * s[i].yearly;
		else
			s[i].tax = 0.02 * s[i].yearly;
	}
	printf("------Employee Records------\n\n");
	printf("Employee Name    ID Number    Basic Pay    DA              HRA            Salary          Yearly           Income Tax\n");
	for(int i = 1; i <=5; i++)
		printf("%s             %d           %ld        %lf    %lf    %lf    %lf    %lf\n",s[i].name ,s[i].id ,s[i].basic, s[i].da, s[i].hra, s[i].salary, s[i].yearly, s[i].tax);
	return 0;
}
