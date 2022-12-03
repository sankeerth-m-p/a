#include<stdio.h>
int main()
{
	int f,p;
	int pages[50],frame[10],hit=0,count[50],time[50];
	int i,j,flag,a,b,c;
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
	        count[i]=1;
		time[i]=0;
		a=100;
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
					count[j]++;
				}			
				else
				{	
					time[j]=i;
				}
				flag=0;
				frame[j]=pages[i];
				break;
			}
		}
		if(flag==1)
		{
			for(j=0;j<f;j++)
			{
				if(count[j]==a)
				{
					if(time[j]<c)
					{
						a=count[j];
						b=j;
						c=time[j];
					}
				}
				else if(count[j]<a)
				{
					a=count[j];
					b=j;
					c=time[j];
				}
			}
			frame[b] = pages[i];
			count[b] = 1;
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
