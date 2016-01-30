//http://www.spoj.com/problems/PARTY/
#include<stdio.h>
#include<stdlib.h>
using namespace std;
int max(int a, int b) { return (a > b)? a : b; }
int knapsack(int W,int val[],int wt[],int n)
{
    int i,w;
    int K[n+1][W+1];
    
    for(i=0;i<=n;i++)
    {
        for(w=0;w<=W;w++)
        {
            if(w==0||i==0)
            {
                K[i][w]=0;
                wg[i][w]=0;
            }
            else if(wt[i-1]<=w)
            {
                K[i][w]=max(val[i-1]+K[i-1][w-wt[i-1]],K[i-1][w]);
            }
            else
            {
                K[i][w]=K[i-1][w];
            }
        }
    }
    // checking if there are lower cost (weight) values for same fun value 
    // this can be done by looping i through [1,W] and finding the least w fow which w K[n][w] == K[n][W] 
    int ans=W;
    for(i=W-1;i>=0;i--)
    {
        if(K[n][i] == K[n][W])
            ans = i;
    }
    printf("%d %d\n",ans,K[n][W]);
}
int main()
{
    int W,n,i;
    while(1)
    {
        scanf("%d %d",&W,&n);
        if(W==0 && n==0)
        {
            break;
        }
        int *val=(int *)malloc(n*sizeof(int));
        int *wt=(int *)malloc(n*sizeof(int));
        for(i=0;i<n;i++)
        {
            scanf("%d %d",&wt[i],&val[i]);
        }
        knapsack(W,val,wt,n);
    }
    return 0;
}
