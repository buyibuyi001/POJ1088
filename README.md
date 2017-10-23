# POJ1088
#include<stdio.h>
#define max(a,b) ((a)>(b)?(a):(b)
int path=1,maxpath=1;
int row=0,col=0;
int height[110][110]={0},length[110][110]={0};
int get_ij_length(int,int);
int ijhigher(int i,int j,int x,int y)
{
    if ( x>=0 && x<row && y>=0 && y<col && height[i][j]>height[x][y] )
        {
            //printf("high");
            if(length[x][y]==0)
                get_ij_length(x,y);
            path=1+length[x][y];
            maxpath=max(path,maxpath);
            
        }
    return 0;
}

int get_ij_length(int i,int j)
{
    //printf("h%d%d%-3d ",i,j,height[i][j]);
    ijhigher(i,j,i-1,j);
    ijhigher(i,j,i,j-1);
    ijhigher(i,j,i+1,j);
    ijhigher(i,j,i,j+1);
    length[i][j]=maxpath;
    path=1;
    maxpath=1

    return 0;
}

int main (void)
{
    int i=0,j=0;
    int max_ij_length=1;
    scanf("%d %d",&row,&col);

    for (i=0;i<row;i++)
        for (j=0;j<col;j++)
            scanf("%d",&height[i][j]);

    length[0][0]=1;
    for (i=0;i<row;i++)
        for (j=0;j<col;j++)
        {
            get_ij_length(i,j);
            max_ij_length = max(max_ij_length,length[i][j]);
        }
    printf("%d ", max_ij_length);
    
    return 0;
}


