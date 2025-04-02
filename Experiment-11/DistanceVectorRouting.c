#include<stdio.h>
int dist[50][50],temp[50][50],n,i,j,k,x; 
void dvr();
int main()
{
printf("\nEnter the number of nodes : "); 
scanf("%d",&n);
printf("\nEnter the distance matrix :\n"); 
for(i=0;i<n;i++)
{
for(j=0;j<n;j++)
{
scanf("%d",&dist[i][j]); 
dist[i][i]=0;
temp[i][j]=j;
}
printf("\n");
}
dvr();
printf("enter value of i &j:"); 
scanf("%d",&i);
scanf("%d",&j); 
printf("enter the new cost"); 
scanf("%d",&x);
dist[i][j]=x;
printf("After update\n\n"); 
dvr();
return 0;
}
void dvr()
{
for (i = 0; i < n; i++) 
for (j = 0; j < n; j++)
for (k = 0; k < n; k++)
if (dist[i][k] + dist[k][j] < dist[i][j])
{
dist[i][j] = dist[i][k] + dist[k][j]; 
temp[i][j] = k;
}
for(i=0;i<n;i++)
{
printf("\n\nState value for router %d is \n",i+1); 
for(j=0;j<n;j++)
printf("\t\nnode %d via %d Distance%d",j+1,temp[i][j]+1,dist[i][j]);
} 
printf("\n\n");
}
