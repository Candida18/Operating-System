#include <stdio.h>

int available[10];// m number of resource types
int allocation[10][10];// Matrix of n x m, n = #resources m= #resource types
int request[10][10];// max [n][m] n = resource, m = resourcesTypes
int need[10][10];

int numberOfProcesses, numberOfResources;// process, resource


void input();// Asks for all inputs
void show();// Shows all outputs
void compute();// Computing


int main()
{
    printf("\n------------------------------------------------------------------------------------------------\n");
    printf("\n \t\t\t\t\tDeadlock Detection \n");
    printf("\n------------------------------------------------------------------------------------------------\n");
    input();
    show();
    compute();
    return 0;
}

void input()
{
    int i, j;// counters
    printf("\n Enter the number of Processes : ");// single integer, no limits
    scanf("%d", &numberOfProcesses);
    printf("\n Enter the number of Resource Instances : ");// single integer, no limits
    scanf("%d",&numberOfResources);
    printf("\n------------------------------------------------------------------------------------------------\n");

    printf("\n Enter the Request Matrix : \n");
    for( i = 0; i < numberOfProcesses; i++)
    {
        printf("\n");
        printf(" Process %d : ", i);
        for(j = 0; j < numberOfResources; j++)
        {
            scanf("%d", &request[i][j]);
        }
    }
    printf("\n------------------------------------------------------------------------------------------------\n");

    printf("\n Enter the Allocation Matrix : \n");
    for(i = 0; i < numberOfProcesses; i++)
    {
        printf("\n");
        printf(" Process %d : ", i);
        for (j = 0; j < numberOfResources; j++)
        {
            scanf("%d", &allocation[i][j]);
        }
    }
    printf("\n------------------------------------------------------------------------------------------------\n");

    printf("\n Enter the Available Resources : ");
    for(j = 0; j < numberOfResources; j++)
    {
        scanf("%d", &available[j]);
    }
    printf("\n------------------------------------------------------------------------------------------------\n");
}

void show()
{
    int i, j;
    printf("\n Process\t Allocation\t Request\t Available\t ");

    for(i = 0; i < numberOfProcesses; i++)
    {
        printf("\n   P%d\t\t", i);

        for(j = 0; j < numberOfResources; j++)
        {
            printf("%d ", allocation[i][j]);
        }
        printf("\t ");

        for(j = 0; j < numberOfResources; j++)
        {
            printf("%d ", request[i][j]);
        }
        printf("\t");

        if (i == 0) {
            for (j = 0; j < numberOfResources; j++)
            {
                printf("%d ", available[j]);
            }
        }
    }
    printf("\n------------------------------------------------------------------------------------------------\n");
}

void compute()
{
    int finish[10], need[10][10], flag = 1, k;// for the integer arrays, we are declared the maximum space we could take up.
    int dead[10];
    int i, j;
    for( i = 0; i < numberOfProcesses; i ++ )
    {
        finish[i]=0;
    }
    for(i = 0; i < numberOfProcesses; i++)
    {
        for(j = 0; j < numberOfResources; j++)
        {
            need[i][j] = request[i][j] - allocation[i][j];
        }
    }
    while(flag)
    {
        flag = 0;
        for (i = 0; i < numberOfProcesses; i++)
        {
            int c = 0;
            for( j = 0; j < numberOfResources; j++)
            {
                if ( ( finish[i] == 0 ) && ( need[i][j] <= available[j] ) )
                {
                    c++;
                    if ( c == numberOfResources )
                    {
                        for(k = 0; k < numberOfResources; k++)
                        {
                            available[k] += allocation[i][j];
                            finish[i] = 1;
                            flag = 1;
                        }
                        if (finish[i]==1)
                        {
                            i = numberOfProcesses;
                        }
                    }
                }
            }
        }
    }
    // go through and find the deadlocked processes.
    j = 0;
    flag = 0;
    for(i = 0; i < numberOfProcesses; i++)
    {
        if(finish[i] == 0)
        {
            dead[j] = i;
            j++;
            flag = 1;
        }
    }
    if(flag == 1)
    {
        printf("\n System is in Deadlock and the Deadlock process are : \n\n");
        for(i = 0; i < numberOfProcesses; i++)
        {
            printf(" Process %d\t", dead[i]);
        }
        printf("\n------------------------------------------------------------------------------------------------\n");
    }
    else
    {
        printf("\n No Deadlock ");
        printf("\n------------------------------------------------------------------------------------------------\n");
    }
}




allocated
4 0 0 1
1 1 0 0
1 2 5 4
0 6 3 3
0 2 1 2

request
6 0 1 2
1 7 5 0
2 3 5 6
1 6 5 3
1 6 5 6
