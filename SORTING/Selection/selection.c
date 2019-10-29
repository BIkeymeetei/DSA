#include<stdio.h>
void selectionsort(int data[],int n)
{

int i,j;
int temp;
for(i=0;i<n-1;i++)
{

	for(j=i;j<n;j++)
	{
		if(data[i]>data[j])
		{
			temp=data[i];data[i]=data[j];data[j]=temp;
			
		}
	}

}


for(i=0;i<n;i++)
{
	printf("\n%d",data[i]);

}



}

void main()
{
int n,i;
int data[10];
printf("\nenter the size (<10) :");
scanf("%d",&n);
printf("\nenter the data\n");
for(i=0;i<n;i++)
{
scanf("%d",&data[i]);
}
printf("\nbefore sorting ");
for(i=0;i<n;i++)
{
printf("\n%d",data[i]);

}
printf("\n after sorting");
selectionsort(data,n);

printf("\n");
}
