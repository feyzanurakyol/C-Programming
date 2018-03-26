/*This program prints triangle with the numbers in a special sequences.*/

int main()
{
  int number,min=2,max=10,i,j,temp=0,tempy;
	number=numberGeneratorBetweenRange(min,max);/*Randomly generated number*/
	printf("Number: %d\n\n",number );

	for(i=1;i<=number;i++)
	{
	  temp+=1;  /*To find first column we started from 1.*/
		for(j=1;j<i+1;j++)
		{	
			printf("%d ",j*temp);/*Then we multiply.*/
		}
		printf("\n");
	}
	printf("\n");
return 0;
}
