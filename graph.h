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
    string name;//����
    string intro;//���
};
//��
typedef struct ArcCell
{
    int adj;
    //infotype*info;
}ArcCell,adjMatrix[VertexMax][VertexMax];
//����������
struct MatrixGraph
{
    Site vexs[VertexMax];//��������
    adjMatrix arcs;//�ڽӾ���
    int vexnum,arcnum;//�����뻡��
};
typedef struct{
    int prev;   //��ǰ���·���ϸö����ǰ�������λ��
    int lowcost;//��ǰ���·���ĳ���
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
//��λ����
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
    //�����ڽӾ����Ѿ���ʼ��Ϊ0���ʴ˴�ֻ��Ҫ����
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
    //��ʾ�ܵľ�����
    for (int i = 0; i < G.vexnum; i++)
    {
        cout<<G.vexs[i].num<<" "<<G.vexs[i].name<<endl;
    }
    /*//��ʾ�ڽӾ���
    for (int i = 0; i < G.vexnum; i++){
    for (int j = 0; j < G.vexnum; j++)
        cout<<setw(5)<<G.arcs[i][j].adj<<',';
    cout<<endl;
    }*/
}
//��ѯĳ�����
void ShowNode(MatrixGraph&G,int n){
    cout<<G.vexs[n].num<<"�ž��㣺"<<G.vexs[n].name<<endl<<G.vexs[n].intro<<endl;
    cout<<"���ھ���;������£�"<<endl;
    for (int i = 0; i < G.vexnum; i++)
    {
        if(G.arcs[n][i].adj<Inf)
        cout<<G.vexs[i].num<<"�ž��㣬����Ϊ"<<G.arcs[n][i].adj<<endl;
    }
    
}
//��v0��v1
void Floid(MatrixGraph G,int&v0,int&v1,int**path){
    for(int i=0;i<G.vexnum;i++)
    for (int j = 0; j < G.vexnum; j++)
    {
        path[i][j]=j;
    }
    
    //��ͼG�д�i���㵽�������ж�������·��
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
    cout<<"����"<<v0+1<<"������"<<v1+1<<"�����·��Ϊ��"<<endl; 
    while (v0!=v1)
    {
        cout<<G.vexs[v0].name<<"-";
        t=v0;
        v0=path[v0][v1];
        sum+=G.arcs[t][v0].adj;
    }
    cout<<G.vexs[v0].name<<endl;
    cout<<"·������Ϊ��"<<sum<<endl;
}

#endif