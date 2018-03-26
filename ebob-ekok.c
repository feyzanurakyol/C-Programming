/*This program finds Least Common Multiplier and also Gratest Common Divisor of two numbers */
#include <stdio.h>

void LCMGCD(int number1, int number2, int *lcm, int *gcd)
{
	/*Fistly we find the Least Common Multiplier and than we can calculate easily rest of them.*/
	int i,j,divisor=1,multiply;

	printf("-----FIND LCM AND GCM-----\n");
	printf("Enter a number: ");
	scanf("%d %d",&number1,&number2);
	printf("LCMGCD(%d,%d)=",number1,number2);

	multiply=number2*number1;
	for(i=2;i<=number1;i++)/*To find all divisors*/
	{
		while(number1%i==0 && number2%i==0)/*I'll find lcm first.
		*/
		{
			divisor*=i;
			number1/=i;
			number2/=i;
		}
	}

	*lcm=divisor;
	*gcd=multiply / *lcm; /*That is a realtion between lcm and gcd.*/
	return;
}

int main()
{
	int number1,number2,lcm,gcd;
	LCMGCD(number1,number2,&lcm,&gcd); /*I called it function.*/
	printf("%d,%d",gcd,lcm );

	return 0;
}
