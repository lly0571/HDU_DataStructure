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
    cout<<"������ѡ���ģʽ��1Ϊ��ʾ�����б�2Ϊ��ʾ��ѡ��ž������Ϣ��3Ϊ���������ѡ�����ľ��룬0�˳�";
    cin>>n;
    switch (n)
    {
    case 1:
        ShowSites(mg);
        break;
    case 2:
        cout<<"��������ѡ���㣺";
        cin>>site;
        if(site<=0){
        cout<<"�������";
        break;}
        site-=1;
        ShowNode(mg,site);
        break;
    case 3:
        cout<<"��������ѡ���㣺";
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