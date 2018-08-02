#include<stdio.h>
#include<malloc.h>

int Maxbit(int arr[], int size)
{
    int p = 1; int count = 0;int i=0;
      for ( i = 0; i < size; i++)
      {
            while (arr[i]>p)
            {
                    p *= 10;
                   count++;            
            }
              
      }
        return count;

}
void bucketsort(int arr[], int num)
{
    int max = Maxbit(arr, num);
      int i = 0;
      int j = 0;
      int k = 0;
      int index = 1;
      int *tmp =(int*)malloc(sizeof(int)*num); 
      int *count =(int*) malloc(sizeof(int)*10);
      for (i = 0; i < max; i++)
     {
         for (j = 0;j < 10; j++)
         {
               count[j] = 0;
                                    
         }
      for (j = 0; j < num; j++)
      {
          k = (arr[j] / index) % 10;
               count[k]++;
                                              
      }
       for (j = 1; j < 10; j++)
      {
        count[j] = count[j - 1] + count[j];
                                            
      }
      for (j = num - 1; j >= 0; j--)
      {
        k = (arr[j] / index) % 10;
       tmp[count[k] - 1] = arr[j];
        count[k]--;
       }
        index *= 10;
      for (j = 0; j < num; j++)
      {
           arr[j] = tmp[j];
                                                        
       }
                                                                                          
    
     }
      free(tmp);
      free(count);
}

int main()
{ 
int arr[13]={300,1,3,6,5,2,4,8,9,7,12,15,36};
bucketsort(arr,13);
int i=0;
for ( i = 0; i < 13; i++)
{
  printf("%d\n",arr[i]);
}
  return 0;
}


