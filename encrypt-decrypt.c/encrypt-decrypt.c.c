#include <stdio.h>

void reverse_line(char line[],int line_length)/*Reverse line*/
{
	int i,hline,j,key;
	char temp;
	
	do
  {
    printf("Enter key: ");
    scanf("%d",&key);
    printf("\n");
  }while(!(key>0 && key<26));/*repeats if the key is not in range*/
    
	if(line_length%2==0)
    hline=(line_length)/2;
  else
    hline=(line_length+1)/2;
 
	for(i=0;i<hline;i++)/*reverse process*/
	{
    temp=line[i];
    line[i]=line[line_length-i-1];
    line[line_length-1-i]=temp; 
  }
        
  for(i=0;i<line_length;i++)
  {
  	if(line[i]==32)
  		line[i]=95;
  	else if(line[i]==46)
  		line[i]=42;
    else
    {
      for(j=1;j<=key;j++)
      {
            if(line[i]=='a')
                 line[i]='z';   
            else
                 line[i]-=1;/*Add one by one to the ascii value, to control the change a to z.*/

      }
    }
  }
}           

int find_size_of_line(char line[])
/*This function calculates number of characters in line[].*/
{
  int i,line_length=-1;
	for(i=0;line[i]!='\n';i++)
	{
		line_length++;
	}   
	return line_length;
}

void b_reverse_line(char line[],int line_length)/*takes back the first reverse process*/
{
	int i,hline,j,key;
	char temp;
do
  {
    printf("Enter key: ");
    scanf("%d",&key);
    printf("\n");
  }while(!(key>0 && key<26));/*repeats if the key is not in range*/
    
	if(line_length%2==0)
        hline=(line_length)/2;
    else
        hline=(line_length-1)/2;
 
	for(i=0;i<hline;i++)
	{
    temp=line[i];
    line[i]=line[line_length-i-1];
    line[line_length-1-i]=temp; 
  }
        
  for(i=0;i<line_length;i++)
  {
    if(line[i]==95)
      line[i]=32;
    else if(line[i]==42)
      line[i]=46;
    else
    { 
      for(j=1;j<=key;j++)
      {
         if(line[i]=='z')
              line[i]='a';   
         else
              line[i]+=1;/*Add one by one to the ascii value, to control the change z to a.*/

      }
    }
  }  
}    

void decrypt_open_message()/*Decryption process*/
{
	
	int line_length,i=0,j;
	char line[1024];

	FILE * open;
	FILE * secret;
	open=fopen("open_msg.txt","ra+");
	secret=fopen("secret_msg.txt","r");

    while(fgets(line, 1024, secret)) /*Keeps goin until it's done.*/
    {
   		line_length=find_size_of_line(line);
      if(line_length==-1 || line_length==0)/*When we write the secret message, there will be empty lines. Then
                                            program tries to decrypt it. With this condition we can control this.*/
      {
        continue;
      }
      else
      {
	      b_reverse_line(line,line_length);
        printf("%s",line);
        fprintf(open, "%s", line);
        line[line_length]='\n';
      }
    }
		   
   	fclose(open);
   	fclose(secret);
	
}

void encrypt_open_message()/*Encryption process*/
{
	int line_length,i,j;
	char line[1024];
  /*open process*/
	FILE * open;
	FILE * secret;
	open=fopen("open_msg.txt","r");
	secret=fopen("secret_msg.txt","ra+");

  while(fgets(line, 1024, open)) /*Keeps goin until it's done.*/
  {
 		line_length=find_size_of_line(line);
    reverse_line(line,line_length);
    printf("%s",line);
    fprintf(secret, "%s\n", line);
  }
	   
 	fclose(open);
 	fclose(secret);

}

int main()
{
	int choice;

	do{/*Menu process*/
		printf("1.Encrypt\n");
		printf("2.Decrypt\n");
		printf("0.Exit\n");
		printf("Choice:\n");
		scanf("%d",&choice);

		switch(choice)
		{
			case 1:
				encrypt_open_message();
				break;
			case 2:
				decrypt_open_message();
				break;
			case 0:
				choice=0;
				break;
			default:
				printf("1.Encrypt\n");
				printf("2.Decrypt\n");
				printf("0.Exit\n");
				printf("Choice:\n");
				scanf("%d",&choice);
				break;
		}
	}while(choice!=0);
}