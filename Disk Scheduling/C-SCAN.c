
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int main()
{
	int queue[20],n,head,i,j,k,seek=0,max,diff,temp,queue1[20],queue2[20],
				temp1=0,temp2=0;
	float avg;
	printf("\n------------------------------------------------------------------------------------------------\n");
    printf("\n\t\t\t\t\tC-SCAN Disk Scheduling Algorithm \n");
    printf("\n------------------------------------------------------------------------------------------------\n");

	printf("\n Enter the maximum range of the disk : ");
	scanf("%d",&max);
	printf("\n------------------------------------------------------------------------------------------------\n");

	printf("\n Enter the number of queue requests : ");
	scanf("%d",&n);
	printf("\n------------------------------------------------------------------------------------------------\n");

	printf("\n Enter the initial head position : ");
	scanf("%d",&head);
	printf("\n------------------------------------------------------------------------------------------------\n");

	printf("\n Enter the queue of disk positions to be read : ");
	for(i=1;i<=n;i++)
	{
		scanf("%d",&temp);
		if(temp>=head)
		{
			queue1[temp1]=temp;
			temp1++;
		}
		else
		{
			queue2[temp2]=temp;
			temp2++;
		}
	}
	printf("\n------------------------------------------------------------------------------------------------\n");

	for(i=0;i<temp1-1;i++)
	{
		for(j=i+1;j<temp1;j++)
		{
			if(queue1[i]>queue1[j])
			{
				temp=queue1[i];
				queue1[i]=queue1[j];
				queue1[j]=temp;
			}
		}
	}
	for(i=0;i<temp2-1;i++)
	{
		for(j=i+1;j<temp2;j++)
		{
			if(queue2[i]>queue2[j])
			{
				temp=queue2[i];
				queue2[i]=queue2[j];
				queue2[j]=temp;
			}
		}
	}
	
	for(i=1,j=0;j<temp1;i++,j++)
		queue[i]=queue1[j];
		
	queue[i]=max;
	queue[i+1]=0;
	
	for(i=temp1+3,j=0;j<temp2;i++,j++)
		queue[i]=queue2[j];
		
	queue[0]=head;
	for(j=0;j<=n+1;j++)
	{
		diff=abs(queue[j+1]-queue[j]);
		seek+=diff;
		printf("\n The Disk Head moves from %d to %d with Seek Time : %d\n",queue[j],queue[j+1],diff);
	}

	printf("\n------------------------------------------------------------------------------------------------\n");

	printf("\n Total Head Movements : %d cylinders\n",seek);
	avg=seek/(float)n;

	printf("\n\n Average Head Movements :%f cylinders\n",avg);
	printf("\n------------------------------------------------------------------------------------------------\n");

	return 0;
}

