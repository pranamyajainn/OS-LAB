#include<stdio.h>
int main(){
    int p[10], pri[10],bt[10],wt[10],tat[10],i,j,n, total=0,totalT=0,pos,temp;
    float avg_wt, avg_tat;
    
    printf("enter the no of processes:");
    scanf("%d", &n);
    
    printf("enter burst time and priority:");
    for(i=0;i<n;i++){
        printf("enter burst time for p%d", i+1);
        scanf("%d", &bt[i]);
        printf("enter priority for p%d",i+1);
        scanf("%d", &pri[i]);
        p[i]=i+1;
    }
    //sort on based of priority
    for(i=0;i<n;i++){
        pos=i;
        for(j=i+1;j<n;j++){
            if(pri[j]<pri[pos]){
                pos=j;
            }
        }
    }
    //swap temp 
    temp=pri[i]; pri[i] =pri[pos]; pri[pos]=temp;
    temp=bt[i]; bt[i]=bt[pos]; bt[pos]=temp;
    temp=p[i]; p[i]=p[pos]; p[pos]=temp;
    
    //cal waiting time
    wt[0]=0;
    for(i=1;i<n;i++){
        wt[i]=0;
        for(j=0;j<i;j++){
            wt[i] += bt[j];
        }
        total += wt[i];
    }
    avg_wt=(float)total/n; 
    
    //cal tat
    printf("\n Process\t burst time\t, priority\t, waiting time\t TAT\n");
    for(i=0;i<n;i++){
        tat[i]=bt[i]+wt[i];
        totalT += tat[i];
        printf("p%d\t %d\t%d\t%d\t%d\n",p[i],bt[i],pri[i],wt[i],tat[i]);
    }
    avg_tat=(float)totalT/n;
    
    //print avg
    printf("avg waiting time: %.2f", avg_wt);
    printf("avg turn around time: %.2f", avg_tat);
    return 0; 
}
