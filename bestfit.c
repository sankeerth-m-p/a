#include<stdio.h>
void main()
{
	int bsize[10], psize[10], bno, pno, allocation[10], i, j;
	for(i = 0; i < 10; i++)
	{
		allocation[i] = -1;
	}
	printf("Enter no. of blocks: ");
	scanf("%d", &bno);
	printf("\nEnter size of each block: ");
	for(i = 0; i < bno; i++)
		scanf("%d", &bsize[i]);
	printf("\nEnter no. of processes: ");
	scanf("%d", &pno);
	printf("\nEnter size of each process: ");
	for(i = 0; i < pno; i++)
		scanf("%d", &psize[i]);
	for(i = 0; i < pno; i++)
	{
		int index = -1;
		for(j = 0; j < bno; j++)
		{
			
			if(bsize[j] >= psize[i])
			{
				if (index== -1)
					index= j;
				else if (bsize[j] < bsize[index])
                    			index= j;
			}
		}
		if (index!= -1)
        	{
            		allocation[i] = index;
            		bsize[index] -= psize[i];
        	}
	}
	printf("\nProcess No.\tProcess Size\t\tBlock no.\n");
    for (int i = 0; i < pno; i++)
    {
        printf("%d \t\t\t %d \t\t\t", i+1, psize[i]);
        if (allocation[i] != -1)
            printf("%d\n",allocation[i] + 1);
        else
            printf("Not Allocated\n");
    }
}