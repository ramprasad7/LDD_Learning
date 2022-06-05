#include<stdio.h>
#include<unistd.h>

struct argus
{
	int id;
	int time;
	int period;
}heap[2001];
int total,i;

void swap(int a,int b)
{
	struct argus x;
	
	x = heap[a];
	heap[a] = heap[b];
	heap[b] = x;
}

void heapup(int pos)
{
	int q;
	q = pos/2;
	
	while(q>=1)
	{
		if(heap[pos].time<heap[q].time)
			swap(pos,q);
		else if(heap[pos].time==heap[q].time)
			if(heap[pos].id<heap[q].id)
				swap(pos,q);
		else break;
		pos = q;
		q = q/2;		
	}
}

void initialize()
{
	char a[10];
	int x,y;
	
	int m;
	scanf("%d\n",&m);
	
	for(i=1;i<=m;i++)
	{
	    
		scanf("%s %d %d\n",a,&heap[i].id,&heap[i].period);
		heap[i].time = heap[i].period;
		heapup(i); 
		total++;

	}

}


int heapdown()
{
	int p=1;
	
	while(2*p<=total)
	{
		int left,right;
		left = 2*p;
		right = 2*p+1;
		
		if(right>total)
		{
			swap(p,left);
			p = left;
		}
		else if(heap[left].time<heap[right].time)
		{
			swap(p,left);
			p = left;
		}
		else if(heap[left].time==heap[right].time&&heap[left].id<heap[right].id)
		{
			swap(p,left);
			p = left;
		}
		else
		{
			swap(p,right);
			p = right;
		}		
	}
	heap[p].time += heap[p].period;
	
	return p; 
}

int main()
{
	int j;
	int n;
	
	initialize();
	int k;
    scanf("%d\n",&k);
	
	for(j=0;j<k;j++)
	{
		printf("%d\n",heap[1].id);
		n = heapdown();
		heapup(n);
	}
}