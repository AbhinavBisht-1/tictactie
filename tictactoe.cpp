#include<stdio.h>
int main()
{
	char a[3][3];
	printf("\t****WELCOME TO THE GAME OF TIC TAC TOE**** \n\n");
	printf("\t\t");
	for(int i=0;i<=2;i++)
	{
		if(i==0)
		printf("1st row  ");
		if(i==1)
		printf("2nd row  ");
		if(i==2)
		printf("3rd row  ");
		for(int j=0;j<=2;j++)
		{
			if(i%2==0)
			printf("X ");
			else
			printf("O ");
		}
		printf("\n\t\t");
	}
	for(int i=0;i<=2;i++)
	{
		for(int j=0;j<=2;j++)
		{
			a[i][j]='*';
		}
	}
	printf("\n");
	char ch1[15];
	char ch2[15]; 
	printf("FIRST PLAYER Enter your name\n");
	scanf("%s",&ch1);
	printf("SECOND PLAYER Enter your name\n");
	scanf("%s",&ch2);	
	int i1=1,i2=1;                              //index of position to be filled
	char x,mood;
	do
	{
		printf("\n");
		for(int i=1;i<=9;i++)
	    {
		    if(x!='t')
		    { 
		    	if(i%2!=0)
	    		{
	    			againx:
    				printf("%s Enter the row and column to be filled like \nr,c  i.e  2,3\n",ch1); 
    				scanf("%d,%d",&i1,&i2);
    				printf("\n");
    				if(i1>=4||i2>=4||i1==0||i2==0)
    		   		{
			    		printf("Wrong input !!!!!\n");
			    		fflush(stdin);
		    			goto againx;
		    		}
		    		if(a[i1-1][i2-1]=='X'||a[i1-1][i2-1]=='O')
			    	{
			    		printf("That index is already filled . Fill another index .\n");
			    		goto againx;
					}
		    		a[i1-1][i2-1]='X';
			    	for(int i=0;i<=2;i++)
			    	{
			    		for(int j=0;j<=2;j++)
			    		printf("%c ",a[i][j]);
		    			printf("\n");
		    		}
				
			    }
		    	else
		    	{
		    		againo:
		    		printf("%s Enter the row and column to be filled like \nr,c  i.e  2,3\n",ch2); 
		    		scanf("%d,%d",&i1,&i2);
		    		printf("\n");
			    	if(i1>=4||i2>=4||i1==0||i2==0)
    				{
	    				printf("Wrong input !!!!!\n");
	    				fflush(stdin);
		    			goto againo;
			    	}
			    	if(a[i1-1][i2-1]=='X'||a[i1-1][i2-1]=='O')
			    	{
			    		printf("That index is already filled . Fill another index .\n");
			    		goto againo;
					}
    				a[i1-1][i2-1]='O';
	    			for(int i=0;i<=2;i++)
		    		{
			    		for(int j=0;j<=2;j++)
				    	printf("%c ",a[i][j]);
				    	printf("\n");
				    }		
	    		}
		    	if((a[0][0]==a[1][1]&&a[1][1]==a[2][2])||(a[2][0]==a[1][1]&&a[1][1]==a[0][2]))
    			{
					if(a[1][1]=='X')
					{
					printf(" %s  WINS.",ch1);
					x='t';
					}
					if(a[1][1]=='O')
		            {
		    		printf(" %s  WINS.",ch2);
    				x='t';
	    			}
		    	}
    			for(int k=0;k<=2;k++)
	    		{
		    		int l=0;
					if(a[k][l]==a[k][l+1]&&a[k][l+1]==a[k][l+2])
					{  
						if(a[k][l+1]=='X'){
						printf(" %s  WINS.",ch1);
						x='t';}
						if(a[k][l+1]=='O'){
						printf(" %s  WINS.",ch2);
						x='t';}
					}
					if(a[l][k]==a[l+1][k]&&a[l+1][k]==a[l+2][k])
					{
						if(a[l+1][k]=='X'){
						printf(" %s  WINS.",ch1);
						x='t';}
						if(a[l+1][k]=='O'){
						printf(" %s  WINS.",ch2);
						x='t';}
					}
				}
				i1=0;
				i2=0;
			}
		}
		if(x!='t')
		printf(" THE GAME DRAWS . WELL PLAYED  :-)");
		x='a';
		printf("Want to play again ??\nPress N or n to challenge once again ... LET'S GO. \n");
	    printf("Enter any other key to terminate.\n");
	    fflush(stdin);
		scanf("%c",&mood);
	}
	while(mood=='n'||mood=='N');
	return 0;
}
