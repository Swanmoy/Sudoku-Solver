//@uthor-evilgenius(Swanmoy)
#include<bits/stdc++.h>
using namespace std;
void solve(int**, bool**, int, int);
bool chk(int**);
void solve(int **grid, bool **can_fill, int row, int col)
{
    if(row==10)
    {
        cout<<"Solution"<<endl;
        for(int x=1;x<=9;x++)
        {
            for(int y=1;y<=9;y++)
            {
                cout<<grid[x][y]<<" ";
            }
            cout<<endl;
        }
    }
    else
    {
        if(can_fill[row][col])
        {
            vector<int> arr(10, 0);
            int i, j, k;
            for(i=1;i<=9;i++)
            {
                arr[grid[row][i]]+=1;
            }
            for(i=1;i<=9;i++)
            {
                if(arr[i]==0)
                {
                    grid[row][col]=i;
                    if(chk(grid))
                    {
                        if(col==9)
                        {
                            solve(grid, can_fill, row+1, 1);
                            grid[row][col]=0;
                        }
                        else
                        {
                            solve(grid, can_fill, row, col+1);
                            grid[row][col]=0;
                        }
                    }
                    else
                        grid[row][col]=0;
                }
            }
        }
        else
        {
            if(col==9)
            {
                solve(grid, can_fill, row+1, 1);
            }
            else
            {
                solve(grid, can_fill, row, col+1);
            }
        }
    }
}
bool chk(int **grid)
{
    int flag=0;
    int i, j, k, l;
    for(i=1;i<=9;i++)
    {
        vector<int> arr(10, 0);
        for(j=1;j<=9;j++)
        {
            arr[grid[i][j]]+=1;
        }
        for(k=1;k<=9;k++)
        {
            if(arr[k]>1)
            {
                flag=1;
                break;
            }
        }
    }
    for(i=1;i<=9;i++)
    {
        vector<int> arr(10, 0);
        for(j=1;j<=9;j++)
        {
            arr[grid[j][i]]+=1;
        }
        for(k=1;k<=9;k++)
        {
            if(arr[k]>1)
            {
                flag=1;
                break;
            }
        }
    }
    for(i=1;i<=9;i+=3)
    {
        for(j=1;j<=9;j+=3)
        {
            vector<int> arr(10, 0);
            for(l=i;l<=i+2;l++)
            {
                for(k=j;k<=j+2;k++)
                {
                    arr[grid[l][k]]+=1;
                }
            }
            for(k=1;k<=9;k++)
            {
                if(arr[k]>1)
                {
                    flag=1;
                    break;
                }
            }
        }
    }
    if(flag==1)
        return false;
    else
        return true;
}
int main()
{
	int **grid=new int*[10];
	bool **can_fill=new bool*[10];
	int i, j, k;
	for(i=0;i<=9;i++)
    {
        grid[i]=new int[10];
        can_fill[i]=new bool[10];
    }
    cout<<"Enter the Sudoku"<<endl;
	for(i=1;i<=9;i++)
    {
        for(j=1;j<=9;j++)
        {
            int a;
            cin>>a;
            if(a==0)
            {
                can_fill[i][j]=true;
                grid[i][j]=0;
            }
            else
            {
                can_fill[i][j]=false;
                grid[i][j]=a;
            }
        }

    }
    cout<<"Calculating..."<<endl;
    solve(grid, can_fill, 1, 1);
}
