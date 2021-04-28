#include<stdio.h>
int main()
{
    int block_arr[10], file_arr[10];
    int fragments[10], blocks[10], files[10];
    int m, n, number_of_blocks, number_of_files, temp;

    printf("\n------------------------------------------------------------------------------------------------\n");
    printf("\n \t\t\t\tMemory Management Scheme - First-Fit\n");
    printf("\n------------------------------------------------------------------------------------------------\n");

    printf("\n Enter the Total Number of Blocks : ");
    scanf("%d", &number_of_blocks);
    printf("\n------------------------------------------------------------------------------------------------\n");

    printf("\n Enter the Total Number of Process : ");
    scanf("%d", &number_of_files);
    printf("\n------------------------------------------------------------------------------------------------\n");

    printf("\n Enter the Size of the Blocks : \n");
    for(m = 0; m < number_of_blocks; m++)
    {
        printf(" Block No. [%d] : ", m + 1);
        scanf("%d", &blocks[m]);
    }
    printf("\n------------------------------------------------------------------------------------------------\n");

    printf("\n Enter the Size of the Process : \n");
    for(m = 0; m < number_of_files; m++)
    {
        printf(" Process No. [%d] : ", m + 1);
        scanf("%d", &files[m]);
    }
    printf("\n------------------------------------------------------------------------------------------------\n");

    for(m = 0; m < number_of_files; m++)
    {
        for(n = 0; n < number_of_blocks; n++)
        {
            if(block_arr[n] != 1)
            {
                temp = blocks[n] - files[m];
                if(temp >= 0)
                {
                    file_arr[m] = n;
                    break;
                }
            }
        }
        fragments[m] = temp;
        block_arr[file_arr[m]] = 1;
    }

    printf("\n Process_no.\tProcess Size\tBlock Number\tBlock Size\tFragment\n");
    for(m = 0; m < number_of_files; m++)
    {
        printf("\n  %d\t\t%d\t\t%d\t\t%d\t\t%d\n\n", m+1, files[m], file_arr[m]+1,blocks[file_arr[m]],fragments[m]);
    }
    printf("\n------------------------------------------------------------------------------------------------\n");

    return 0;
}





