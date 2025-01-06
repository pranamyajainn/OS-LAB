#include<stdio.h>
void main(){
    int bsize[10], psize[10],bno,pno,flags[10], allocation[10],i,j;
    
    //initilize flags and allocation array
    for(i=0;i<10;i++){
        flags[i]=0;
        allocation[i]=-1;
    }
    
    
    printf("enter no of blocks");
    scanf("%d", &bno);
    printf("enter size of each block");
    for(i=0;i<bno;i++){
        scanf("%d", &bsize[i]);
    }
    
    
    printf("enter no of process");
    scanf("%d", &pno);
    printf("enter size of each process");
    for(i=0;i<pno;i++){
        scanf("%d", &psize[i]);
    }
    
    //algo logic
    for(i=0;i<pno;i++){
        for(j=0;j<bno;j++){
            if(flags[j]==0 && bsize[j] >= psize[i]){
                allocation[j]=i;
                flags[j]=1;
                break;
            }
        }
    }
    
    //display
    printf("blockno\t size\t processno\t size\n");
    for(i=0;i<bno;i++){
        printf("\n%d\t %d\t", i+1,bsize[i]);
        if(flags[i]==1){
            printf("%d\t\t%d", allocation[i]+1, psize[allocation[i]] );
        }
        else{
            printf("not allocated.");
        }
    }
}
