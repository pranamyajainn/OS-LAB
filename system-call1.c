#include<stdio.h>
#include<stdlib.h>
#include<dirent.h>
int main(){
    char dirName[100];
    struct dirent *entry;
    DIR *dir;
    
    printf("enter the name of directory: ");
    scanf("%s",  dirName);
    
    if((dir=opendir(dirName)) == NULL){
        printf("directory doesnot exist");
        return 1;
    }
    while((entry = readdir(dir)) != NULL){
        printf("%s\n", entry->d_name);
    }
    closedir(dir);
    return 0;
}
