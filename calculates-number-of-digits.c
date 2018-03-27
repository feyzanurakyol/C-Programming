#include <stdio.h>

int number_of_digits(int number) /*Calculates the number of the digits.*/
{
	int digits=1,temp; /*I started from one because our numbers have at least two digits.*/
	
	temp=number;

	while(number>10) /*Divison with ten, we can calculate digits.*/
	{	
		number=number/10;
		if(number>=1)
		{
			digits++; 	
		}
	}

	if(temp==100 || temp==1000 || temp==10000) /*For this numbers, digits will calculate less than they are.*/
	{
		digits+=1;
	}
	
	return digits;
}

int is_it_in_range(int number) /*Checks the value is between the numbers that we want.*/
{
	while(number<23 || number>98760)
	{
		printf("Not in Range!!!\n");
		printf("Enter student number:");
		scanf("%d",&number);	
		printf("\n");
	}
	
	return number;
}


void main()
{
	int number,digits, /*I gave simple names to understand easily.*/
	    fifth_digit,third_digit,fourth_digit,second_digit,first_digit;
       	    /*My program keeps five variables because of the range we want. 
	    It will use when it needs.*/
	
	printf("Enter the number: ");
	scanf("%d",&number);  /*I get the value from the user.*/
	printf("\n");
	
	number=is_it_in_range(number);
	
	digits=number_of_digits(number);

	
	fifth_digit=number%10; /*If we calculate the mod of a number with ten, 
	we find the last digit of the it.*/

	fourth_digit=(((number%100)-fifth_digit)/10); /*Mod of a number with hundred will gave us the last two numbers. 
	Then we can calculate the digit before the last digit with a simple difference and division.*/

	first_digit=number/10000;/*Division with 10000 will give the fist digit of the number 
	who has a 5 digit.*/

	second_digit=(number/1000)-(first_digit*10);/*Division 1000 will give the first two digits, 
	then we can calculate the second digit of the number. If there are just four digits 
	it gave the first digit. */

	third_digit=(number/100)-(second_digit*10)-(first_digit*100);/*This statement  countinues the what we did before this.*/

	switch(digits) /*I will use this statement to display results according to the number of digits. */
	{
		case 2:
		printf("First digit: %d\n",fourth_digit);
		printf("Second digit: %d\n",fifth_digit);
		break;
		
		case 3:
		printf("First digit: %d\n",third_digit);
		printf("Second digit: %d\n",fourth_digit);
		printf("Third digit: %d\n",fifth_digit);
		break;
		
		case 4:
		printf("First digit: %d\n",second_digit);
		printf("Second digit: %d\n",third_digit);
		printf("Third digit: %d\n",fourth_digit);
		printf("Fourth digit: %d\n",fifth_digit);
		break;
		
		case 5:
		printf("First digit: %d\n",first_digit);
		printf("Second digit: %d\n",second_digit);
		printf("Third digit: %d\n",third_digit);
		printf("Fouth digit: %d\n",fourth_digit);
		printf("Fifth digit: %d\n",fifth_digit);
		break;
	}
	
	return;
}
