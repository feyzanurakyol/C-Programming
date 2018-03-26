/*This program express a number as a sumf of two prime numbers.*/

#include <stdio.h>

int main()
{
	int number,flag,temp=0,count,secondnum,i,j,k;

	printf("-----THE SUM OF TWO PRIME NUMBERS-----\n");
	printf("Enter the number: ");
	scanf("%d",&number);
	printf("\n");

	for(i=2;i<=(number/2);i++)/*Find the numbers that divide given number.*/
	{
			for(j=2;j<i;j++)/*Then i check the number whether prime or not.*/
			{
				if(i==2)
				{
					flag=0;
				}

				else if(i%j==0)/*If it is not prime, flag will be 1.*/
				{
					flag=1;
				}
			}

			secondnum=number-i;


			if(flag==0)/*If first number is prime, so then i check second number.*/
			{			

				for(k=2;k<secondnum;k++)
				{
					if(secondnum==2)
					{
						count=0;
					}
					else if(secondnum%k==0)/*If it is not prime, count will be 1.*/
					{
						count=1;
					}
				}
			}
			
				if(flag==0 && count==0)/*When both are prime, we can display the results.*/
				{
					printf("%d=%d+%d\n",number,i,secondnum);
					temp=1;/*This shows that we found at least one result.*/
				}

				flag=0;
				count=0;

	}
	if(temp==0)/*If we cannot find any combination of sum of prime numbers, we display this result. */
	{
			printf("There is no prime number!\n");
	}

	return 0;
}
