#include "stdio.h"
#include "stdlib.h"

typedef int(*DataCompareFunc)(void *ctc,void *data);

int int_cmp(void *a,void *b)
{
  return (int)a - (int)b;
}

static void merge_sort_impl(void **storage,void **array,size_t low,size_t mid,size_t high,DataCompareFunc cmp)
{
    size_t i = low;
    size_t j = low;
    size_t k = mid;

    if((low+1) < mid)
    {
      size_t x = low + ((mid - low) >> 1);
      merge_sort_impl(storage,array,low,x,mid,cmp);
    }
    if((mid+1) < high)
    {
      size_t x = mid + ((high-mid) >> 1);
      merge_sort_impl(storage,array,mid,x,high,cmp);
    }

    while(j < mid && k < high)
    {
      if(cmp(array[j],array[k]) <= 0)
      {
        storage[i++] = array[j++];
      }
      else
      {
        storage[i++] = array[k++];
      }
    }

    while(j < mid)
    {
      storage[i++] = array[j++];
    }
    while(k < high)
    {
      storage[i++] = array[k++];
    }

    for(i = low; i< high;i++)
    {
      array[i] = storage[i];
    }
    return 0;
}

void merge_sort(void **array,size_t nr,DataCompareFunc cmp)
{
    void **storage = NULL;
    int ret_val  = 0;

    if(nr > 1)
    {
      storage = (void**)malloc(sizeof(void *) * nr);
      if(storage != NULL)
      {
          ret_val = merge_sort_impl(storage,array,0,nr>>1,nr,cmp);
          free(storage);
      }
    }
    return ret_val;
}
