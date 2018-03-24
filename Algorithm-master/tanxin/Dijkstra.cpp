/*************************************************************************
	> File Name: Dijkstra.cpp
	> Author: 
	> Mail: 
	> Created Time: 2017年05月07日 星期日 14时40分38秒
 ************************************************************************/

#include<iostream>
#include <fstream>    
#include <string> 
using namespace std;

const int N = 5;
const int M = 1000;
ifstream fin("Dijkstra");

void Dijkstra(int n,int v,int dist[],int prev[],int c[][N + 1]);
void Traceback(int v,int i,int prev[]);//输出最短路径v源点，i终点

int main()
{
    int v = 1;//源点为1
    int dist[N + 1], prev[N + 1], c[N + 1][N + 1];

    cout<<"有向图权的矩阵为;"<<endl;
    for(int i = 1; i <= N; i++)
    {
        for(int j = 1; j <= N; j++)
        {
            fin>>c[i][j];
            cout<<c[i][j]<<"  ";
        }
        cout<<endl;
    }

    Dijkstra(N,v,dist,prev,c);

    for(int i = 2; i<= N; i++)
    {
        cout<<"源点1到点"<<i<<"的最短路径长度"<<dist[i]<<"，其路径为";
        Traceback(1,i,prev);
        cout<<endl;
    }

    return 0;
}

void Dijkstra(int n,int v,int dist[],int prev[],int c[][N + 1])
{
    bool s[N + 1];
    for(int  i = 1; i <= n; i++)
    {
        dist[i] = c[v][i];
        s[i] = false;

        if(dist[i] == M)
        {
            prev[i] = 0;
        }
        else
        {
            prev[i] = v;
        }
    }

    dist[v] = 0;
    s[v] = true;

    for(int i = 1; i < n; i++)
    {
        int temp = M;
        int u = v;

        for(int j = 1; j <= n; j++)
        {
            if((!s[j]) && (dist[j] < temp))
            {
                u = j;
                temp = dist[j];
            }
        }
        s[u] = true;

        for(int j = 1; j <= n; j++)
        {
            if((!s[j]) && (c[u][j] < M))
            {
                int newdist = dist[u] + c[u][j];
                if(newdist < dist[j])
                {
                    dist[j] = newdist;
                    prev[j] = u;
                }
            }
        }
    }
}

void Traceback(int v,int i,int prev[])
{
    if(v == i)
    {
        cout<<i;
        return;
    }
    Traceback(v,prev[i],prev);
    cout<<"->"<<i;
}
