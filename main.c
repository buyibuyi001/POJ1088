#include<stdio.h>
/*
5 5
1  2  3  4  5
16 17 18 19 6
15 24 25 20 7
14 23 22 21 8
13 12 11 10 9
*/
int row=0,col=0;
int next[4][2]={{0,1},{1,0},{-1,0},{0,-1}};
int hght[110][110]={0},len[110][110]={0};

int get_len(int i,int j)
{
    //len[i][j]+=1;
    if (len[i][j]!=0)
        return len[i][j];
    int curpath=0;int curmaxpath=0;
    for (int k=0;k<4;k++)
    {
        int ni=i+next[k][0];
        int nj=j+next[k][1];
        if ( ni>=0 && ni<row && nj>=0 && nj<col && hght[i][j]>hght[ni][nj] )
        {
            curpath=1+get_len(ni,nj);
            curmaxpath= curmaxpath>curpath? curmaxpath:curpath;
        }
    }
    return curmaxpath;
}

int main (void)
{
    int max_len=0;int curmax=0;
    scanf("%d %d",&row,&col);
    for (int i=0;i<row;i++)
        for (int j=0;j<col;j++)
            scanf("%d",&hght[i][j]);
    for (int i=0;i<row;i++)
        for (int j=0;j<col;j++)
        {
            len[i][j]=get_len(i,j);
            max_len= max_len>len[i][j] ? max_len:len[i][j];
        }
    printf("%d \n", max_len);
    for (int i=0;i<row;i++){
        for (int j=0;j<col;j++)
            printf("%-3d ",len[i][j]);
        printf("\n"); }
    return 0;
}
