#include<stdio.h>
#include<stdlib.h>
void insertion(int a[100],int n)
{
    int temp,i,j;
    for(i=1;i<n;i++)
    {
        temp = a[i];
        while(j>=0 && temp < a[j])
        {
            a[j+1] = a[j];
            j = j - 1;
        }
        a[j+1] = temp;
    }
    for(i=0;i<n;i++)
    {
        printf("%d ",a[i]);
    }
}
void shellsort(int a[100],int n)
{
    int gap,i,j,temp;
    for(gap = n/2;gap>0;gap = gap/2)
    {
        for(i=gap;i<n;i++)
        {
            for(j=i;j>=gap;j = j - gap)
            {
                if(a[j] < a[j-gap])
                {
                    temp = a[j];
                    a[j] = a[j-gap];
                    a[j-gap] = temp;
                }
            }
        }
    }
    for(i=0;i<n;i++)
    {
        printf("%d ",a[i]);
    }
}
void quicksort(int a[100],int l,int r)
{
    int i,j,pivot,temp;
    if(l<r)
    {
        pivot = l;
        i = 0;
        j = r;
        while(i<j)
        {
            while(a[i]<=a[pivot])
            {
                i++;
            }
            while(a[j]>a[pivot])
            {
                j--;
            }
            if(i<j)
            {
                temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
        temp = a[pivot];
        a[pivot] = a[j];
        a[j] = temp;
        quicksort(a,l,j-1);
        quicksort(a,j+1,r);
    }
}
void merge(int a[100],int left,int right,int mid)
{
    int n1,n2,i,j,k;
    n1 = mid - left + 1;
    n2 = right - mid;
    int L[n1],R[n2];
    for(i=0;i<n1;i++)
    {
        L[i] = a[left + i];
    }
    for(j=0;j<n2;j++)
    {
        R[i] = a[mid + i + j];
    }
    i=0,j=0,k=left;
    while(i<n1 && j<n2)
    {
        if(L[i]<=R[j])
        {
            a[k] = L[i];
            i++;
        }
        else
        {
            a[k] = R[j];
            j++;
        }
        k++;
    }
    while(i<n1)
    {
        a[k]= L[i];
        i++;
        k++;
    }
    while(j<n2)
    {
        a[k] = R[j];
        j++;
        k++;
    }
}
void mergeSort(int a[100],int left,int right)
{
    int mid;
    if(left<right)
    {
        mid = left + (right - left)/2;
        mergeSort(a,left,mid);
        mergeSort(a,mid+1,right);
        merge(a,left,mid,right);
    }
}
int main()
{
    int n;
    printf("Enter the size L");
    scanf("%d",&n);
    int a[n];
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    int left = 0,right=n-1,l=0,r=n-1;
    int ch=0;
    while(ch!=5)
    {
        printf("\n1.Insertion Sort\n");
        printf("2.Shell Sort \n");
        printf("3.Quick Sort\n");
        printf("4.Merge Sort\n");
        printf("\nEnter the choice:\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
                insertion(a,n);
                break;
                case 2:
                shellsort(a,n);
                break;
                case 3:
                quicksort(a,l,r);
                break;
                case 4:
                mergeSort(a,left,right);
                break;
                case 5:
                exit(0);
                break;
                default:
                printf("Invalid Choice\n");
                break;
        }
    }
    for(int j =0;j<n;j++)
    {
        printf("%d ",a[j]);
    }
}