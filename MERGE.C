#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
void mergesort(int[],int,int);
void merge(int[],int,int,int);
void mergesort(int a[100],int l,int h)
{
int mid;
if(l<h)
{
mid=(l+h)/2;
mergesort(a,l,mid);
mergesort(a,mid+1,h);
merge(a,l,mid,h);
}
}
void merge(int a[],int l,int mid,int h)
{
int temp[100];
int i,j,k;
i=l;
j=mid+1;
k=0;
while(i<=mid&&j<=h)
{
if(a[i]<a[j])
temp[k++]=a[i++];
else
temp[k++]=a[j++];
}
while(i<=mid)
temp[k++]=a[i++];
while(j<=h)
temp[k++]=a[j++];
for(i=l,j=0;i<=h;i++,j++)
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
