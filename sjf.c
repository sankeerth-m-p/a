#include<stdio.h>
int main()
{
	int  p[10],at[10],bt[10],ct[10],tat[10],wt[10],i,j,temp=0,n,min,k=1,z,m=1;
	float awt=0,atat=0;
    	printf("\nEnter the No. of processes :");
    	scanf("%d",&n);
    	for(i=0;i<n;i++)
    	{
    		printf("enter process no, arrival time , burst time:");
    		scanf("%d%d%d",&p[i],&at[i],&bt[i]);
    	}
    	/*Sorting According to Arrival Time*/
    	for(i=0;i<n-1;i++)
    	{
    		for(j=0;j<(n-i-1);j++)
    		{
      			if(at[j]>at[j+1] ||(at[j]==at[j+1] && bt[j]>bt[j+1] ))
     			{
        			temp=p[j+1];
        			p[j+1]=p[j];
        			p[j]=temp;
        			temp=at[j+1];
        			at[j+1]=at[j];
        			at[j]=temp;
        			temp=bt[j+1];
        			bt[j+1]=bt[j];
        			bt[j]=temp;
      			}
     		}
    	} 
    /*able according to Burst time,
    Execution time and Arrival Time
    Arrival time <= Execution time
    */
    	ct[0]=at[0]+bt[0];
        for(i=0,j=1;i<n-1;i++,j++)
       	{
       		for(z=i+1;z<n-1;z++)
        	{
			m=i;
            		if (ct[i]>=at[z] && bt[z]>bt[z+1])
            		{
             	   		m=z;
            		}
            		if(m!=i)
            		{
                		temp=p[z+1];
                		p[z+1]=p[z];
                		p[z]=temp;
                		temp=at[z+1];
                		at[z+1]=at[z];
                		at[z]=temp;
                		temp=bt[z+1];
                		bt[z+1]=bt[z];
                		bt[z]=temp;
            		}
        	}
        	temp=0;
        	if(ct[j-1]<at[j])
       		{	
        		temp=at[j]-ct[j-1];
       		}
    		ct[j]=ct[j-1]+bt[j]+temp;
      	}
    	for(i=0;i<n;i++)
    	{
        	tat[i]=ct[i]-at[i];
        	wt[i]=tat[i]-bt[i];
        	awt=awt+wt[i];
        	atat=atat+tat[i];
    	}
    	atat=atat/n;
    	awt=awt/n;
    	printf("\nProcess\t Arrival\t Burst\t ct\t\t Waiting\t Turn-around" );
    	for(i=0;i<n;i++)
    	{
    	    printf("\n p%d\t %d\t \t  %d\t %d\t\t  %d\t\t  %d",p[i],at[i],bt[i],ct[i],wt[i],tat[i]);
    	} 
    	printf("\n\nAVERAGE WAITING TIME : %f",awt);
    	printf("\nAVERAGE TURN AROUND TIME : %f",atat);
    	return 0;
}
