#include<stdio.h>
void main()
 {   int bsize[10],psize[10],b,p,allocation[10],i,j;
        
        for(i=0;i<10;i++)
          { 
            allocation[i]=-1;
          }
 	printf("enter no. of blocks");
 	scanf("%d",&b);
 
 	printf("\n enter size of each block");
 	  for(i=0;i<b;i++)
  	    scanf("%d",&bsize[i]);
  	    
  	 printf("enter the no. of processes");
   	 scanf("%d",&p);
   	 
   	printf("\n enter size of each processes");
  	 for(i=0;i<p;i++)
  	   scanf("%d",&psize[i]);
   
  	 for(int i=0;i<p;i++)
   	 { 
   	    for(int j=0;j<b;j++)
    	     {
    	        if(bsize[j]>=psize[i])
    	          {       
    	           allocation[i]=j;
    	           bsize[j]-=psize[i];
    	           break;
     	          }
            }
        }
   	printf("\nprocess no.\t process size \t block no.\n");
    	for(int i=0;i<p;i++)
    	 { 
    	     printf("%d\t \t%d\t \t",i+1,psize[i]);
              if(allocation[i]!=-1)
       	printf("%d\n",allocation[i]+1);
             else 
               printf("not allocated \n");
        }
    }