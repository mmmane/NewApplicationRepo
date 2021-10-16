#include<stdio.h>
#include<stdlib.h>

void sender()
{
	int data[100],div[4]={1,0,0,1},temp[100];
	int i,k,j=0,n;
	printf("\nEnter length of dataword:");
	scanf("%d",&n);
	printf("\nEnter data word: ");
	for(i=0;i<n;i++)
		scanf("%d",&data[i]);

	for(i=0;i<n;i++)
		temp[i]=data[i];

	for(i=n;i<n+3;i++)
		data[i]=0;
	for(i=0;i<n+3;i++)
		printf("%d",data[i]);
	k=0;
	printf("\n");
	for(i=0;i<n;i++)
	{
		if(data[i]==1)
		{
			for(j=i;j<n+3;j++)
			{
				data[j]=data[j]^div[k];
				k++;
			}
		}
		k=0;
	}
	for(j=n;j<n+3;j++)
		temp[j]=data[j];

	for(i=0;i<n+3;i++)
		printf("%d",temp[i]);
}
void receiver()
{
	int data[100],div[4]={1,0,0,1};
	int i,k,j=0,n,cnt=0;
	printf("\nEnter length of codeword:");
	scanf("%d",&n);
	printf("\nEnter codeword");
	for(i=0;i<n;i++)
		scanf("%d",&data[i]);
	k=0;
	n=n-4;
	for(i=0;i<=n;i++)
	{
		if(data[i]==1)
		{
			for(j=i;j<=n+3;j++)
			{
				data[j]=data[j]^div[k];
				k++;
			}
		}
		k=0;
	}

	//for(j=n+1;j<=n+3;j++)
	//{
		//printf("\nposition=%d value=%d",j,data[j]);
	//}

	for(j=n;j<n+3;j++)
	{
		if(data[j]!=0)
			break;
		else
			cnt++;
	}
	if(cnt==3)
		printf("\nNo error present");
	else
		printf("\nError is present");
	return;
}
void main()
{
	int choice;
	printf("\nEnter the choice\n1.Sender\n2.Receiver\n3.Exit \n");
	scanf("%d",&choice);
	switch(choice)
	{
		case 1:
			sender();
			break;
		case 2:
			receiver();
			break;
		default:
			exit(0);
	}
	return;
}







