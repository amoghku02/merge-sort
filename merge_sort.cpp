#include<iostream>

using namespace std;

void merge_it(int arr[],int p,int q,int r)
{
    int n1 = q - p + 1;
    int n2 = r - q;
    int l1[n1];
    int l2[n2];
    for(int i=0; i<n1; i++)
    {
        l1[i] = arr[p+i];
    }
    for(int i=0; i<n2; i++)
    {
        l2[i] = arr[q+i+1];
    }
    int i=0, j=0;
    int k = p;
    while(i<n1 && j<n2)
    {
        if(l1[i]<=l2[j])
        {
            arr[k] = l1[i];
            i++;
        }
        else
        {
            arr[k] = l2[j];
            j++;
        }
        k++;
    }
    while(i<n1)
    {
        arr[k] = l1[i];
        i++;
        k++;
    }
    while(j<n2)
    {
        arr[k] = l2[j];
        j++;
        k++;
    }
}

void merge_sort(int arr[], int p, int r)
{
    if(p<r)
    {
        int q = (r+p)/2;
        merge_sort(arr, p, q);
        merge_sort(arr, q+1, r);
        merge_it(arr, p, q, r);
    }
} 

int main(){

    int temp[12] = {1, 2 , 12, 3, 2, 5, 6, 4, 20, 10, 15, 13};
    merge_sort(temp, 0, 12);
    for(int i=0;i<12;i++)
    {
        cout<<temp[i]<<" ";
    }

return 0;
}
