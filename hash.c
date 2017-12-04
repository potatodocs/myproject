#include<stdio.h>
#include<stdlib.h>

int nextBucket(int v,int i,int m)
{
	return (v+i)%m;
}

void insertItem(int *A,int k,int m)
{
	int v,i,b;

	v=k%m;
	i=0;

	while(i<m)
	{
		b=nextBucket(v,i,m);
		if(A[b]==0)
		{
			A[b]=k;
			printf("%d\n",b);
			break;
		}
		else
		{
			i++;
			printf("C");
		}
	}

}

int findElement(int *A,int k,int m)
{
	int v,i,b;

	v=k%m;
	i=0;

	while(i<m)
	{
		b=nextBucket(v,i,m);
		if(A[b]==0)
		{
			return -1;
		}
		else if(A[b]==k)
		{
			return b;
		}
		else
			i++;
	}
	return -1;
}

int main()
{
	int m,n,i,k,s;
	int *A;
	char adt;

	scanf("%d %d",&m,&n);
	getchar();

	A=(int *)malloc(sizeof(int)*m);

	for(i=0;i<m;i++)
		A[i]=0;

	while(1)
	{	
		scanf("%c",&adt);
		getchar();

		switch(adt)
		{
			case 'i':
				scanf("%d",&k);
				getchar();
				insertItem(A,k,m);
				break;
			case 's':
				scanf("%d",&k);
				getchar();
				s=findElement(A,k,m);
				if(s!=-1)
					printf("%d %d\n",s,k);
				else
					printf("-1\n");
				break;
			case 'e':
				exit(1);
		}
	}


}