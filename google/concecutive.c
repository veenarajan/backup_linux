#include <stdio,h>

void consecutive(int *arr){
    int i,j=0;
    for (i=0;i<;10;i++){
        if (j==0){
            printf("%d",arr[i]);
        }
        if (arr[i+1]-arr[i] == 1){
            j = 1;
        }
        else{
            if (j!=0){
                printf("-%d\t",arr[i]);
            }
            else{
                printf("\t");
            }
            j =0;
        }
        
    }
    printf("\n");
}

int main(){
    int arr[] = {1,2,3,10,25,26,30,31,32,33};
    int i;
    consecutive(arr);
    return 0;
    }