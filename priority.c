#include<stdio.h> 
     
    struct process 
    { 
          int pname; 
          int at, bt, ct, wt, tat, priority; 
          int status; 
    }pq[10]; 
     
    int n; 
     
     
    //function to sort processes by arrival time 
    void at_Sorting() 
    { 
          struct process temp; 
          int i, j; 
          for(i = 0; i < n - 1; i++) 
          { 
                for(j = i + 1; j < n; j++) 
                { 
                      if(pq[i].at > pq[j].at) 
                      { 
                            temp = pq[i]; 
                            pq[i] = pq[j]; 
                            pq[j] = temp; 
                      } 
                } 
          } 
    } 
     
     
    //Driver function 
    void main() 
    { 
          int i, time = 0, bt = 0, large,j;  
          float wait_time = 0, tat = 0, awt=0,atat=0; 
          printf("\nEnter Total Number of Processes:\t"); 
          scanf("%d", &n); 
     
          //taking input process details 
          for(i = 0, j=1; i < n; i++, j++) 
          { 
                pq[i].pname = j; 
                printf("\nEnter Details For Process[%d]:\n", pq[i].pname); 
                printf("Enter Arrival Time, Burst time, Priority:\t"); 
                scanf("%d%d%d", &pq[i].at, &pq[i].bt, &pq[i].priority ); 
                pq[i].status = 0; 
                bt = bt + pq[i].bt; 
          } 
          at_Sorting(); //sorting by arrival time 
          pq[9].priority = -9999; 
          printf("\nProcess Name\tArrival Time\tBurst Time\tPriority\t compile time\tWaiting Time\t turnaround time"); 
          for(time = pq[0].at; time < bt;) 
          { 
                large = 9; 
                for(i = 0; i < n; i++) 
                { 
                      if(pq[i].at <= time && pq[i].status != 1 &&  pq[i].priority > pq[large].priority) 
                      { 
                            large = i; 
                      } 
                } 
                time = time + pq[large].bt; 
                pq[large].ct = time;  
                pq[large].tat = pq[large].ct - pq[large].at; 
                pq[large].wt = pq[large].tat - pq[large].bt;
                pq[large].status = 1; 
                wait_time = wait_time + pq[large].wt; 
                tat = tat + pq[large].tat; 
                printf("\nP%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d", pq[large].pname, pq[large].at, pq[large].bt, pq[large].priority,pq[large].ct, pq[large].wt,pq[large].tat); 
          } 
          awt = wait_time / n;
          atat = tat / n; 
          printf("\n\nAverage waiting time:\t%f\n", awt); 
          printf("Average Turnaround Time:\t%f\n", atat); 
    } 