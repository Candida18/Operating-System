#include<stdio.h>
int main()
{
	int p,res;
	printf("\n------------------------------------------------------------------------------------------------\n");
    	printf("\n \t\t\t\t\tBanker's Algorithm \n");
    	printf("\n------------------------------------------------------------------------------------------------\n");
	printf("\n Enter the Number of Process : ");
	scanf("%d",&p);
	printf("\n Enter the Number of Resources : ");
	scanf("%d",&res);
	printf("\n------------------------------------------------------------------------------------------------\n");
	
	int allocated[p][res],need[p][res],max[p][res],status[p],seq[p],available[1][res],flag=0;
	printf("\n Enter the Allocated Matrix : \n");
	for(int i=0;i<p;i++)
	{
		for(int j=0;j<res;j++)
		{
			scanf("%d",&allocated[i][j]);
		}
	}
	printf("\n------------------------------------------------------------------------------------------------\n");
	
	printf("\n Enter the Max Matrix : \n");
	for(int i=0;i<p;i++)
	{
		for(int j=0;j<res;j++)
		{
			scanf("%d",&max[i][j]);
		}
	}
	printf("\n------------------------------------------------------------------------------------------------\n");
	for(int i=0;i<p;i++)
	{
		for(int j=0;j<res;j++)
		{
			need[i][j]=max[i][j]-allocated[i][j];
		}
	}
	
	printf("\n Enter the Available Resources : ");
	for(int i=0;i<res;i++)
	{
		scanf("%d",&available[0][i]);
	}
	printf("\n------------------------------------------------------------------------------------------------\n");
	printf("\n Process\t Allocation\t\tMax\t\t Need\t\t Available\t");
    for(int i=0;i<p;i++)
    {
        printf("\n  P%d\t\t ",i);
        for(int j=0;j<res;j++)
        {
            printf(" %d ",allocated[i][j]);
        }
        printf("\t\t");
        for(int j=0;j<res;j++)
        {
            printf("%d ",max[i][j]);
        }
        printf("\t\t");
        for(int j=0;j<res;j++)
        {
            printf(" %d",max[i][j]-allocated[i][j]);
        }
		printf("\t\t");
		

		for(int j=0;j<res;j++)
			printf(" %d ",available[0][j]);
        
		
    }
	printf("\n\n------------------------------------------------------------------------------------------------\n");
	
	for(int i=0;i<p;i++)
	{
		status[i]=0;
	}
	
	int counter=0;
	while(counter<p)
	{
		int st=0;
		int processid=9999;
		for(int i=0;i<p;i++)
		{
			for(int j=0;j<res;j++)
			{ 
				if(available[0][j]>=need[i][j] && status[i]==0)
				{
					st=1;
					processid=i;
				}
				else	
				{
					st=0;
					break;
				}	
			}
			if(st==1){
				break;
			}
			else{
				continue;
			}
		}
		if(processid==9999){
			printf(" The Processess are in Deadlock ");
			printf("\n------------------------------------------------------------------------------------------------\n");
			flag=1;
			break;
		}
		seq[counter]=processid;	
		status[processid]=1;
		counter++;
		for(int j=0;j<res;j++)
		{
			available[0][j]=available[0][j]+allocated[processid][j];	
		}


	}
	if(flag==0)
	{
			printf("\n The Processes are in a Safe State");
			printf("\n\n The Safe Execution Sequence : ");
			for(int i=0;i<p;i++)
			{
				printf("P%d -> ",seq[i]);
			}
			printf("\n\n------------------------------------------------------------------------------------------------\n");
	}
	return 0;
}

