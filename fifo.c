#include<stdio.h>
int main()
{
	int f,p;
	int pages[50],frame[10],hit=0,time[50];
	int i,j,flag,b,c;
	printf("Enter no of frames : ");
	scanf("%d",&f);
	printf("Enter no of pages : ");
	scanf("%d",&p);
	for(i=0;i<p;i++)
	{
		frame[i]=-1;
	}
	printf("Enter page no : \n");
	for(i=0;i<p;i++)
	{
		scanf("%d",&pages[i]);
	}
	printf("\n");
	for(i=0;i<p;i++)
	{	
		time[i]=0;
		c=100;
		b=-1;
		flag=1;
		for(j=0;j<f;j++)
		{
			if(frame[j]==-1 || frame[j]==pages[i])
			{
				if(frame[j]!=-1)
				{
					hit++;
				}
				else
				{	
					time[j]=i;
					frame[j]=pages[i];
				}
				flag=0;
				break;
			}
		}
		if(flag==1)
		{
			for(j=0;j<f;j++)
			{
				if(time[j]<c)
				{
					b=j;
					c=time[j];					
				}
			}
			frame[b] = pages[i];
			time[b]=i;	
		}
		for(j=0;j<f;j++)
		{
			printf("%d  ",frame[j]);
		}
		printf("\n");
	}
	printf("Page hit = %d",hit);
	printf("Page fault = %d",p-hit);
	return 0;
}
