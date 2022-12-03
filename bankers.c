#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{ 
	int n,m,i,j,k,y,alloc[20][20],max[20][20],avail[50],ind=0,safe=1;
	int finish[n],safesequence[n],work[m],need[20][20],allocation[n];
	char ch[1];
  	printf("enter the no. of processes and resources ");
  	scanf("%d%d",&n,&m);
  	printf("enter the claim matrix\n");
  	for(i=0;i<n;i++)
    { 
    	for(j=0;j<m;j++)
       	scanf("%d",&max[i][j]);
 	}
   	printf("enter the allocation matrix\n");
    for(i=0;i<n;i++)
  	{ 
        for(j=0;j<m;j++)
    	scanf("%d",&alloc[i][j]);
  	}
   	printf("enter the resource vector ");
    for(i=0;i<m;i++)
      	scanf("%d",&avail[i]);
		for(i=0;i<n;i++)
    { 
        for(j=0;j<m;j++)
         	need[i][j]=0;;
    }
    for(i=0;i<n;i++)
    { 
        for(j=0;j<m;j++)
		{
         	need[i][j]=max[i][j] - alloc[i][j];
		}
	}
	for(j=0;j<m;j++)
    { 
	allocation[j]=0;
    }
	for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            allocation[j] += alloc[i][j];
        }
    }
	for (i = 0; i < m; i++)
    {
        work[i] = avail[i] - allocation[i];
    }
    for(i=0;i<n;i++)
    { 
	finish[i]=0;
    }
    for(k=0;k<n;k++)
    { 
		for(i=0;i<n;i++)
      	{ 
			if(finish[i]==0)
       		{
				int flag=0;
         		for(j=0;j<m;j++)
          		{
					if(need[i][j]>work[j])
           			{ 
						flag=1;
            	 		break;
           			}
          		}
         		if(flag==0)
         		{ 
					printf("\nall resources can be allocated to Process%d \n", i + 1);
					safesequence[ind++]=safe++;
					finish[i]=1;
            		for(y=0;y<m;y++)
					{
            			work[y]+=alloc[i][y];
					}
					printf("\nAvailable resources:");
            		for(y=0;y<m;y++)
					{
            			printf("\t%d", work[y]);
					}
           			printf("\nProcess is executed?:y/n\n");
					scanf("%s",&ch);
					if((strcmp(ch,"y")==0) || (strcmp(ch,"Y")==0))
						printf(" ");
					else
						{printf("error"); exit(0);}
          		}
        	}
    	}
    }
	safe=1;
	for(i=0;i<n;i++)
    { 
		if(finish[i]==0)
		{
			safe=0;
			break;
		}
    }
	if(safe==0)
    {
        printf("\nThe processes are in unsafe state.\n");
        exit(0);
    }
    else
		printf("system is in safe mode");

    printf("\n following is the Safe sequence \n");
    for(i=1;i<=n;i++)
    	printf("P%d ",safesequence[i]);
}