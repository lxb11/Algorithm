/*************************************************************************
	> File Name: travel.cpp
	> Author: 
	> Mail: 
	> Created Time: 2017年05月11日 星期四 21时04分56秒
 ************************************************************************/

#include<iostream>
#include<fstream>
using namespace std;

ifstream fin("travel");
const int N = 4;// 图的顶点数

template<class Type>
class travel
{
    template<Type>
    friend Type TSP(Type **a, int n);
    public:
    void Backtrace(int i);
    int n,//图G的顶点数
    *x,//当前解
    *bestx;//当前最优解
    Type **a,//图G的邻接矩阵
    cc,//当前费用
    bestc;//当前最优值
    int NoEdge;//无边标记 
};

template<class Type>
inline void Swap(Type &a, Type &b);

template<class Type>
Type TSP(Type * *a, int n);

int main()
{
    cout<<"图的顶点个数 n = "<<N<<endl;

    int * *a = new int*[N + 1];
    for(int i = 0; i <= N; i++)
    {
        a[i] = new int[N + 1];
    }

    cout<<"图的邻接矩阵为："<<endl;

    for(int i = 1; i <= N; i++)
    {
        for(int j = 1; j <= N; j++)
        {
            fin>>a[i][j];
            cout<<a[i][j]<<"  ";
        }
        cout<<endl;
    }
    cout<<"最短回路长为："<<TSP(a,N)<<endl;

    for(int i = 0; i <= N; i++)
    {
        delete [] a[i];
    }
    delete [] a;

    a = 0;
    return 0;
}

template<class Type>
void travel<Type> :: Backtrace(int i)
{
    if(i == n)
    {
        if(a[x[n - 1]][x[n]] != 0 && a[x[n]][1] != 0 && (cc + a[x[n - 1]][x[n]] + a[x[n]][1] <bestc || bestc == 0))
        {
            for(int j = 1; j <= n; j++)
            {
                bestx[j] = x[j];
            }
            bestc = cc + a[x[n - 1]][x[n]] + a[x[n]][1];
        }
    }
    else
    {
        for(int j = i; j <= n; j++)
        {
            //是否可进入x[j]子树
            if(a[x[i - 1]][x[j]] != 0 && (cc + a[x[i - 1]][x[i]] < bestc || bestc == 0))
            {
                //搜索子树 
                Swap(x[i],x[j]);
                cc += a[x[i - 1]][x[i]];//当前费用累加
                Backtrace(i + 1);//排列向右扩展，排列树向下一层扩展
                cc -= a[x[i - 1]][x[i]];
                Swap(x[i],x[j]);
            }
        }
    }
}

template<class Type>
Type TSP(Type **a,int n)
{
    travel<Type> Y;
    Y.n = n;
    Y.x = new int[n + 1];
    Y.bestx = new int[n + 1];

    for(int i = 1; i <= n; i++)
    {
        Y.x[i] = i;
    }

    Y.a = a;
    Y.cc = 0;
    Y.bestc = 0;

    Y.NoEdge = 0;
    Y.Backtrace(2);

    cout<<"最短回路为："<<endl;
    for(int i = 1; i <= n; i++)
    {
        cout<<Y.bestx[i]<<"  -->";
    }
    cout<<Y.bestx[1]<<endl;

    delete [] Y.x;
    Y.x = 0;
    delete [] Y.bestx;
    return Y.bestc;
}

template<class Type>
inline void Swap(Type &a,Type &b)
{
    Type temp = a;
    a = b;
    b = temp;
}
