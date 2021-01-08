#include"graph.h"
int main(){
    int n,site,s1,s2;
    MatrixGraph mg;
    Init(mg);CreateGraph(mg);
    int**path=new int*[mg.vexnum];
    for(int i=0;i<mg.vexnum;i++){
        path[i]=new int[mg.vexnum];
    }
    
    do{
    cout<<"请输入选择的模式：1为显示景点列表，2为显示所选编号景点的信息，3为输出两个所选景点间的距离，0退出";
    cin>>n;
    switch (n)
    {
    case 1:
        ShowSites(mg);
        break;
    case 2:
        cout<<"请输入所选景点：";
        cin>>site;
        if(site<=0){
        cout<<"输入错误";
        break;}
        site-=1;
        ShowNode(mg,site);
        break;
    case 3:
        cout<<"请输入所选景点：";
        cin>>s1>>s2;
        s1-=1;s2-=1;
        Floid(mg,s1,s2,path);
        break;
    default:
        break;
    }    
    }while(n!=0);
    return 0;
}