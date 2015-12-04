#include<stdio.h>
#define MAX 50

void mergeSort(int arr[], int low, int mid, int high)
{

    int i,m,k,l,temp[MAX];

    l = low;
    i = low;
    m = mid+1;

    while((l<=mid)&&(m<=high))
    {

         if(arr[l]<=arr[m]){
             temp[i]=arr[l];
             l++;
         }
         else{
             temp[i]=arr[m];
             m++;
         }
         i++;
    }

    if(l>mid){
         for(k=m;k<=high;k++){
             temp[i]=arr[k];
             i++;
         }
    }
    else{
         for(k=l;k<=mid;k++){
             temp[i]=arr[k];
             i++;
         }
    }
   
    for(k=low;k<=high;k++){
         arr[k]=temp[k];
    }
}
void partition(int arr[],int low,int high){

    int mid;

    if(low<high)
    {
        mid=(low+high)/2;
        //2
        partition(arr,low,mid);
        //0..1..2
        //0..1
        //0..0
        partition(arr,mid+1,high);
        //3..4..5
        //4..5
        //5..5
        mergeSort(arr,low,mid,high);
    }
}


int main(){
   
    int merge[6] = {9,8,7,6,5,4};
    int i,n;
     n = sizeof(merge)/sizeof(merge[0]);
    
    partition(merge,0,n-1);

    printf("After merge sorting elements are: ");
    for(i=0;i<n;i++){
         printf("%d ",merge[i]);
    }

   return 0;
}






void merge(int arr[], int l, int m, int r)
{
    int i, j, k;
    int n1 = mid - low + 1;
    int n2 =  high - mid;
 
    /* create temp arrays */
    int L[n1], R[n2];
 
    /* Copy data to temp arrays L[] and R[] */
    for(i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for(j = 0; j < n2; j++)
        R[j] = arr[m + 1+ j];
 
    /* Merge the temp arrays back into arr[low ..high]*/
    i = 0;
    j = 0;
    k = low;
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
 
    /* Copy the remaining elements of L[], if there are any */
    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }
 
    /* Copy the remaining elements of R[], if there are any */
    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}
 
