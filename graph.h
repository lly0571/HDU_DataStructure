#ifndef _graph_
#define _graph_
#include<string>
#include<iostream>
#include<fstream>
#include<iomanip>
using namespace std;
#define Inf 9999
#define VertexMax 20
struct Site
{
    int num;
    string name;//名称
    string intro;//简介
};
//弧
typedef struct ArcCell
{
    int adj;
    //infotype*info;
}ArcCell,adjMatrix[VertexMax][VertexMax];
//定义无向网
struct MatrixGraph
{
    Site vexs[VertexMax];//顶点向量
    adjMatrix arcs;//邻接矩阵
    int vexnum,arcnum;//顶点与弧数
};
typedef struct{
    int prev;   //当前最短路径上该顶点的前驱顶点的位序
    int lowcost;//当前最短路径的长度
}DistInfo;
void Init(MatrixGraph&G){
    G.vexnum=0;G.arcnum=0;
    for (int i = 0; i < VertexMax; i++)
    for(int j=0;j<VertexMax;j++)
    {
        G.arcs[i][j].adj=Inf;   
    }
    for (int i = 0; i < VertexMax; i++)
    {
        G.vexs[i].name=G.vexs[i].intro="";
        G.vexs[i].num=i+1;
    }
}
//定位顶点
int LocateVex(MatrixGraph G,Site a)
{
    for (int i = 0; i < G.vexnum; i++)
    {
        if (G.vexs[i].name==a.name&&G.vexs[i].intro==a.intro&&G.vexs[i].num==a.num)
        {
            return i;
        }
    }
    return -1;
}
void CreateGraph(MatrixGraph&G){
    ifstream inVA("data.txt",ios::in);
    G.arcnum=20;G.vexnum=13;
    int a,b,wt;
    for (int i = 0; i < G.vexnum; i++)
    {
        inVA>>G.vexs[i].num>>G.vexs[i].name>>G.vexs[i].intro;
    }
    //由于邻接矩阵已经初始化为0，故此处只需要置数
    for (int i = 0; i < G.vexnum; i++)
    for (int j = 0; j < G.vexnum; j++)
    {
        inVA>>a>>b>>wt;
        G.arcs[a-1][b-1].adj=wt;
        G.arcs[b-1][a-1].adj=wt;
    }
    inVA.close();
}
void ShowSites(MatrixGraph&G){
    //显示总的景点编号
    for (int i = 0; i < G.vexnum; i++)
    {
        cout<<G.vexs[i].num<<" "<<G.vexs[i].name<<endl;
    }
    /*//显示邻接矩阵
    for (int i = 0; i < G.vexnum; i++){
    for (int j = 0; j < G.vexnum; j++)
        cout<<setw(5)<<G.arcs[i][j].adj<<',';
    cout<<endl;
    }*/
}
//查询某个结点
void ShowNode(MatrixGraph&G,int n){
    cout<<G.vexs[n].num<<"号景点："<<G.vexs[n].name<<endl<<G.vexs[n].intro<<endl;
    cout<<"相邻景点和距离如下："<<endl;
    for (int i = 0; i < G.vexnum; i++)
    {
        if(G.arcs[n][i].adj<Inf)
        cout<<G.vexs[i].num<<"号景点，距离为"<<G.arcs[n][i].adj<<endl;
    }
    
}
//从v0到v1
void Floid(MatrixGraph G,int&v0,int&v1,int**path){
    for(int i=0;i<G.vexnum;i++)
    for (int j = 0; j < G.vexnum; j++)
    {
        path[i][j]=j;
    }
    
    //求图G中从i顶点到其他所有顶点的最短路径
    for(int k=0;k<=G.vexnum;k++)
    for (int i = 0; i < G.vexnum; i++)
        for (int j =0; j < G.vexnum; j++)
        {
            if (G.arcs[i][k].adj+G.arcs[j][k].adj<G.arcs[i][j].adj)
            {
                G.arcs[i][j].adj=G.arcs[i][k].adj+G.arcs[j][k].adj;
                path[i][j]=path[i][k];
            }
            
        }
    int sum=0,t;
    cout<<"景点"<<v0+1<<"到景点"<<v1+1<<"的最短路径为："<<endl; 
    while (v0!=v1)
    {
        cout<<G.vexs[v0].name<<"-";
        t=v0;
        v0=path[v0][v1];
        sum+=G.arcs[t][v0].adj;
    }
    cout<<G.vexs[v0].name<<endl;
    cout<<"路径长度为："<<sum<<endl;
}

#endif