#include<stdio.h>
#include<stdlib.h>

struct process{
    int ID,AT,BT,WT,TT,CT,status;
}P[10],temp;

int q[20],front=-1,rear=-1;

void enqueue(int n){
    if(front==-1 && rear==-1){
        front=0;
    }
    q[++rear]=n;
}

int dequeue(){
    int temp;
    temp=q[front];
    if(front==rear){
        front=rear=-1;
    }
    else
        front++;
    return temp;
}

int search(int item){
    for(int i=front;i<=rear;i++){
        if(q[i]==item)
            return 1;
    }
    return 0;
}

void main(){
    int n,i,j,k,time=0,tq,num,at[10],bt[10],flag;
    float wt=0,tt=0;

    printf("ROUND ROBIN\nEnter number of process: ");
    scanf("%d",&n);
    printf("\nEnter AT and BT\n");
    for(i=0;i<n;i++){
        printf("P%d: ",i+1);
        P[i].ID=i+1;
        scanf("%d %d",&P[i].AT,&P[i].BT);
        bt[i]=P[i].BT;
        at[i]=P[i].AT;

    }
    printf("\nEnter Time Quantum: ");
    scanf("%d",&tq);   
//sort at
    for(i=0;i<n;i++){
        for(j=0;j<n-i-1;j++){
            if(P[j].AT > P[j+1].AT){
                temp=P[j];
                P[j]=P[j+1];
                P[j+1]=temp;
            }
        }
    }

    printf("\nGANTT CHART\n");
    time=0;
    printf("0 ");
    num=n;
    for(i=0;i<n;i++){
        if(P[i].AT<=time && P[i].status==0){
            enqueue(i);
        }
    }
    while(num>0){
        if(front==-1){
            for(i=0;i<n;i++){
                if(P[i].status==0){
                    enqueue(i);
                }
            }
            time=P[i].AT;
            printf("| idle | %d ",time);
        }
        k=dequeue();
        if(bt[k]<=tq){
            P[k].WT+=time-P[k].CT;
            P[k].TT+=P[k].WT+bt[k];
            time=time+bt[k];
            P[k].CT=time;
            P[k].status=1;
            num--;
            for(i=k+1;i<n;i++)
                if(P[i].AT<=time && P[i].status==0){
                    flag=search(i);
                    if(flag==0)
                        enqueue(i);
                }
            printf("| P%d | %d ",P[k].ID,time);
        }
        else{
            P[k].WT+=time-P[k].CT;
            P[k].TT+=P[k].WT+tq;
            time=time+tq;
            P[k].CT=time;
            bt[k]=bt[k]-tq;
            for(i=k+1;i<n;i++)
                if(P[i].AT<=time && P[i].status==0){
                    flag=search(i);
                    if(flag==0)
                        enqueue(i);
                }
            enqueue(k);
            printf("| P%d | %d ",P[k].ID,time);
        }
        
    }
    printf("\n");

    for(i=0;i<n;i++){
        P[i].WT-=P[i].AT;
        P[i].TT-=P[i].AT;
    }

    printf("\nProcess AT BT WT TT\n");
    for(i=0;i<n;i++){
        printf("P%d      %d  %d  %d  %d\n",P[i].ID,P[i].AT,P[i].BT,P[i].WT,P[i].TT);
    }

    for(i=0;i<n;i++){
        wt=wt+P[i].WT;
        tt=tt+P[i].TT;
    }
    printf("\nAverage waiting time = %f",wt/n);
    printf("\nAverage turn around time = %f\n",tt/n);
}