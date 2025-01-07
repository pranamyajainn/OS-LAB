#include<stdio.h>
#include<stdlib.h>
int mutex=1;
int full=0;
int empty=3;
int x=0;

int wait(int s){
    return (--s);
}

int signal(int s){
    return(++s);
}

void producer(){
    mutex=wait(mutex);
    full=signal(full);
    empty=wait(empty);
    x++;
    printf("\n producer produce the item: %d\n", x);
    mutex=signal(mutex);
}
void consumer(){
    mutex=wait(mutex);
    full=wait(full);
    empty=signal(empty);
    x--;
    printf("consumer consumes the item:%d\n", x);
    mutex=signal(mutex);
}

int main(){
    int n;
    printf("\n 1. Producer\n 2. consumer\n 3. exit\n");
    while(1){
        printf("enter chloice");
        scanf("%d", &n);
        switch(n){
            case 1:
            if((mutex==1) && (empty!=0)){
                producer();
            }
            else{
                printf("buffer is full");
            }
            break;
            case 2:
            if((mutex==1) && (full!=0)){
                consumer();
            }
            else{
                printf("buffer is full");
            }
            break;
            case 3:
            printf("exiting");
            exit(0);
            default:
            printf("invali choice");
            break;
        }
    }
}
