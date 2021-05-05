#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int main()
{
	int queue[20],n,head,i,j,k,seek=0,max,diff;
	float avg;
	printf("\n------------------------------------------------------------------------------------------------\n");
    printf("\n \t\t\t\t\tFCFS Disk Scheduling Algorithm \n");
    printf("\n------------------------------------------------------------------------------------------------\n");

	printf("\n Enter the maximum range of the disk : ");
	scanf("%d",&max);
	printf("\n------------------------------------------------------------------------------------------------\n");

	printf("\n Enter the number of queue requests : ");
	scanf("%d",&n);
	printf("\n------------------------------------------------------------------------------------------------\n");

	printf("\n Enter the queue of disk positions to be read : ");
	for(i=1;i<=n;i++)
		scanf("%d",&queue[i]);
	printf("\n------------------------------------------------------------------------------------------------\n");


	printf("\n Enter the initial head position : ");
	scanf("%d",&head);
	printf("\n------------------------------------------------------------------------------------------------\n");


	queue[0]=head;
	for(j=0;j<=n-1;j++)
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


