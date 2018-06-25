#include<stdio.h>

void Selectionsort(int arr[], int size)
{
    if (size <= 0)
    {
          return;
            
    }
      int max; int i, j;
        for (i = 0; i < size - 1; i++)
        {
              max = i;
                  for (j = i + 1; j < size; j++)
                  {
                          if (arr[max]>arr[j])

                                    max = j;
                              
                  }


                      if (i != max)
                      {
                              int tmp = arr[i];
                                    arr[i] = arr[max];
                                          arr[max] = tmp;
                                              
                      }
                        
        }

}

int main()
{
int arr[10]={0,3,6,2,5,4,7,8,1,9};
Selectionsort(arr,10);
int i=0;
for (i = 0; i < 10; i++)
{
printf("%d ",arr[i]);  
}
  return 0;
}
