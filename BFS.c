#include<stdio.h>
#include<stdlib.h>
int adj[5][5]={{0,1,1,1,0},{1,0,1,0,0},{1,1,0,0,1},{1,0,0,0,0},{0,0,1,0,0}},f=-1,r=-1,n=5,visit[6]={0},queue[5];
void enqueue(int val)
{
        if(f==-1) f=0;
        queue[++r]=val;
}
int dequeue()
{
        if(f==-1) return -1;
        return queue[f++];
}
void bfs(int v)
{
        if(visit[v-1]==0) printf("%d ~~ ",v);
        visit[v-1]=1;
        for(int i=0;i<n;i++)
        {
                if(visit[i]==0 && adj[v-1][i]==1)
                        enqueue(i+1);
        }
        int t=dequeue();
        if(t>0) bfs(t);
}
int main()
{
        int start;
	printf("Data ::->");
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(j==0) printf("\n%d ",adj[i][j]);
			else printf("%d ",adj[i][j]);
		}
	}
        printf("\nEnter Where to start : ");
        scanf("%d",&start);
        bfs(start);
}
