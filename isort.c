#include<stdio.h>


void shift_element(int* arr, int i){

int k;
int *ptr=(arr+1);// starting from here we shift elements !
int temp = *(ptr+i-1);
for (k = i; k>=1; k--)
{
   *(arr+k)=*(arr+(k-1));
}
*(arr+1)=temp;
}

void insertion_sort(int* arr , int len){
int flag=0;
int i,j;
for (i=1; i < len; ++i)
{
   j=i-1;
   flag=0;
   while((j>=0)&&(*(arr+i)<*(arr+j))){
       flag=1;
       --j;
   }
   if(flag){
       shift_element((arr+j),i-j);
   }
}


}

 
void run_isort()
{
    int arr[50];
    size_t i,j;
   int x;
   int length= sizeof(arr)/sizeof(*(arr+1));
    for ( j = 0; j <length ; j++)//filling the array
    {
       // printf("value of %zu element: " ,j);
        scanf("%d",&x);
        arr[j]=x;
    }

    insertion_sort(arr,length);/// sorting the array
    for ( i = 0; i < length; i++)//printing the array
    {
        printf("%d , ",arr[i]);
    }
    
}