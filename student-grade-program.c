#include <stdio.h>
#include <stdlib.h>

char letter_grade(int grade) /*Decides the letter grade of the grade.*/
{
	char lgrade;
	if(grade>=90)
	{
		lgrade='A';
	}
	else if(grade>=80)
	{
		lgrade='B';
	}
	else if(grade>=60)
	{
		lgrade='C';
	}
	else if(grade>=50)
	{
		lgrade='D';
	}
	else
	{
		lgrade='F';
	}
	return lgrade;
}

void average_grade(int s_count, int sum_grade) /*Calculates the avarage grade.*/
{
	double average;

	average=sum_grade/(double)s_count; /*Avarage formula*/
	printf("The average score of the %d student is %.2lf.\n",s_count,average);

	return;
}

int menu(int s_count) /*Prints the menu*/
{
	int menu_selection;
	printf("\n");
	printf("Student Calculator Menu for %d Student\n",s_count);
	printf("\n");
	printf("1) Most Successful Student \n");
	printf("2) Most Unsuccessful Student \n");
	printf("3) Letter Grade Statistics \n");
	printf("4) Calculate Average \n");
	printf("5) Show All Data \n");
	printf("-- Please enter '-1' to exit the program.\n");
	printf("                        Make Selection: ");
	scanf("%d",&menu_selection);
	printf("\n");

	return menu_selection;
}
void most_successful_s(int most_success, int most_success_num) /*Prints the most successful student.*/
{
	printf("Most Successfully Student: \n");
	printf("Index: %d\n",most_success_num);
	printf("Score: %d\n",most_success);
	printf("Letter grade: %c \n",letter_grade(most_success));
	printf("\n");
	return;	
}
	
void most_unsuccessful_s(int most_unsuccess,int most_unsuccess_num)/*Prints the most unsuccessful student*/
{
	printf("Most Unsuccessfuly Student: \n");
	printf("Index: %d\n",most_unsuccess_num);
	printf("Score: %d\n",most_unsuccess);
	printf("Letter grade: %c \n",letter_grade(most_unsuccess));
	printf("\n");
	return ;
}
	
void total_letter_grade(int acounter,int bcounter,int ccounter,int dcounter,int fcounter) /*Prints expanse of the letter grades.*/
{
	printf("%d student got letter grade 'A'\n", acounter);
	printf("%d student got letter grade 'B'\n", bcounter);
	printf("%d student got letter grade 'C'\n", ccounter);
	printf("%d student got letter grade 'D'\n", dcounter);
	printf("%d student got letter grade 'F'\n", fcounter);
	printf("\n");
	return;
}
int main()
{
	int s_count,
		grades,temp_grade, sum_grade=0,i,
		menu_selection=0,
		most_success, most_unsuccess, most_success_num, most_unsuccess_num,/*Index and success status will be stored*/
		acounter=0,bcounter=0,ccounter=0,dcounter=0,fcounter=0;/*The number of the letter grades will be stored.*/

	srand(40);

	printf("Enter student count:"); /*It controls the number of the students whether they between 3 to 50 or not.*/
	scanf("%d",&s_count);
	printf("\n");

	while(s_count<3 || s_count>50)
	{
		printf("Not in Range!!!\n");
		printf("Enter student count:");
		scanf("%d",&s_count);
		printf("\n");	
	}
	
	most_success=1;
	most_unsuccess=100;
	for(i=0;i<s_count;i++)
	{
		grades=rand()%102;
		printf("%d ",grades);
		sum_grade+=grades;/*Sum of the all numbers will keeps here.*/

		if(grades>most_success) /*It will compare all numbers and find the biggest.*/
		{
			most_success=grades;
			most_success_num=i+1; /*Records the index*/
		}
		
		if(grades<most_unsuccess) /*It will compare all numbers and find the smallest.*/
		{
			most_unsuccess=grades;
			most_unsuccess_num=i+1; /*Records the index*/
		}

		if(letter_grade(grades)=='A') /*To record the number of letter grade 'A'*/ 
		{
			acounter++;
		}
		else if (letter_grade(grades)=='B') /*To record the number of letter grade 'B'*/ 
		{
			bcounter++;
		}
		else if (letter_grade(grades)=='C') /*To record the number of letter grade 'C'*/ 
		{
			ccounter++;
		}
		else if(letter_grade(grades)=='D') /*To record the number of letter grade 'D'*/ 
		{
			dcounter++;
		}
		else /*To record the number of letter grade 'F'*/ 
		{
			fcounter++;
		}
	}

	while(menu_selection!=-1) /*Until the user want, it will continue the process.*/
	{
		menu_selection=menu(s_count); /*Gets the menu selection.*/
	
		switch(menu_selection) 
			{
				case 1:
				most_successful_s(most_success,most_success_num);
				break;
			
				case 2:
				most_unsuccessful_s(most_unsuccess,most_unsuccess_num);
				break;
				
				case 3:
				total_letter_grade(acounter,bcounter,ccounter,dcounter,fcounter);
				break;
				
				case 4:
				average_grade(s_count,sum_grade);
				break;
					
				case 5:
				most_successful_s(most_success,most_success_num);
				most_unsuccessful_s(most_unsuccess,most_unsuccess_num);	
				total_letter_grade(acounter,bcounter,ccounter,dcounter,fcounter);
				average_grade(s_count,sum_grade);
				break;
				
				case -1:
				break;

				default:
				printf("False Selection!\n");
				break;
			}
	}
}
