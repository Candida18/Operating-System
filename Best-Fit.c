#include<stdio.h>

int main()
{
    int fragment[20],b[20],p[20],i,j,nb,np,temp,lowest=9999;
    int barray[20],parray[20];
    printf("\n------------------------------------------------------------------------------------------------\n");
    printf("\n \t\t\t\tMemory Management Scheme - Best-Fit \n");

    printf("\n------------------------------------------------------------------------------------------------\n");
    printf("\n Enter the number of blocks : ");

    scanf("%d",&nb);
    printf("\n------------------------------------------------------------------------------------------------\n");

    printf("\n Enter the number of processes : ");
    scanf("%d",&np);
    printf("\n------------------------------------------------------------------------------------------------\n");

    printf("\n Enter the size of the blocks : \n");
    for(i=1;i<=nb;i++)
    {
        printf(" Block No. %d : ",i);
        scanf("%d",&b[i]);
    }
    printf("\n------------------------------------------------------------------------------------------------\n");
    printf("\n Enter the size of the processes : \n");
    for(i=1;i<=np;i++)
    {
        printf(" Process No. %d : ",i);
        scanf("%d",&p[i]);
    }
    printf("\n------------------------------------------------------------------------------------------------\n");
    for(i=1;i<=np;i++)
    {
        for(j=1;j<=nb;j++)
        {

            if(barray[j]!=1)
            {
                temp=b[j]-p[i];
                if(temp>=0)
                    if(lowest>temp)
                    {
                        parray[i]=j;
                        lowest=temp;
                    }
            }
        }
        fragment[i]=lowest;
        barray[parray[i]]=1;
        lowest=10000;
    }

    printf("\n Process_no\tProcess_size\tBlock_no\tBlock_size\tFragment\n");
    for(i=1;i<=np && parray[i]!=0;i++)
    printf("\n  %d\t\t%d\t\t%d\t\t%d\t\t%d\n\n",i,p[i],parray[i],b[parray[i]],fragment[i]);

    printf("\n------------------------------------------------------------------------------------------------\n");

    return 0;
}

