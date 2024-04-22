#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
void mergesort(int[],int,int);
void merge(int[],int,int,int,int);
void mergesort(int a[100],int i,int j)
{
int mid;
if(i<j)
{
mid=(i+j)/2;
mergesort(a,i,mid);
mergesort(a,mid+1,j);
merge(a,i,mid,mid+1,j);
}
}
void merge(int a[100],int i1,int j1,int i2,int j2)
{
int temp[100];
int i,j,k;
i=i1;
j=i2;
k=0;
while(i<=j1&&j<=j2)
{
if(a[i]<a[j])
temp[k++]=a[i++];
else
temp[k++]=a[j++];
}
while(i<=j1)
temp[k++]=a[i++];
while(j<=j2)
temp[k++]=a[j++];
for(i=i1,j=0;i<=j2;i++,j++)
a[i]=temp[j];
}
void main()
{
int a[100],n,i,op;
clrscr();
printf("Merge sort\n");
printf("Enter no of elements \n");
scanf("%d",&n);
printf("enter the elements\n");
for(i=0;i<=n-1;i++)
{
scanf("%d",&a[i]);
}
mergesort(a,0,n-1);
printf("sorted array is \n");
for(i=0;i<=n-1;i++)
{
printf("%d\n",a[i]);
}
getch();
}