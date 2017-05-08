//����+����ʵ���Թ�����
#include<iostream>
#include<vector>
#include<queue>
using namespace std;
//�Թ��ṹ
int maze[8][8]={{1,1,1,1,1,1,1,1},
{1,0,0,0,1,1,0,1},
{1,0,0,1,0,0,0,1},
{1,0,1,0,0,1,1,1},
{1,1,0,1,1,0,1,1},
{1,0,1,0,1,0,1,1},
{1,1,0,1,0,0,0,1},
{1,1,1,1,1,1,1,1}},
//��¼ÿ�����ǰһ����
path[8][8][2],
//��������
zx[]={-1,-1,0,1,1,1,0,-1},zy[]={0,1,1,1,0,-1,-1,-1},
//��㣬�յ�
starti=1,startj=1,endi=6,endj=6;
//���м�¼��Ҫ�����ĵ�
queue<int> searchx;
queue<int> searchy;
//��ӡ·��
void show(int i,int j){
	if(path[i][j][0]!=0 && path[i][j][1]!=0){
		cout<<"("<<i<<","<<j<<")"<<"->";
		show(path[i][j][0],path[i][j][1]);
	}
}
//����
void run(int endi,int endj){
	//�Ȱѵ�һ������Ϊ��Ҫ���ҵĵ㣬�������ȥ~
	searchx.push(endi);searchy.push(endj);
	//��������ϻ��м�¼�ĵ�û���ѵ������Ǿ�ȥ��
	while(!searchx.empty() && !searchy.empty()){
		//��������ó���֮���������ʾ�����Ѿ��ҹ������
		int nowx=searchx.front(),nowy=searchy.front();
		searchx.pop();searchy.pop();
		//���������Ѿ�����������ˣ����һ��
		maze[nowx][nowy]=1;	
		for(int v=0;v<8;v++)
			//����������û��ǽҲû�б�ǣ��Ͱ�����¼�ڶ��У����ᰤ��ȥ��
			if(maze[nowx+zx[v]][nowy+zy[v]]==0){
				searchx.push(nowx+zx[v]);
				searchy.push(nowy+zy[v]);
				//�������ĵ���������������ҹ�ȥ�ģ������ӡ��ʱ����ԴӺ���ǰ�ҵ�·��
				path[nowx+zx[v]][nowy+zy[v]][0]=nowx;
				path[nowx+zx[v]][nowy+zy[v]][1]=nowy;
				//�����������յ�Ļ�����̫���ˣ�ֱ�Ӱ�·���������
				if(nowx+zx[v]==starti && nowy+zy[v]==startj){
					show(nowx+zx[v],nowy+zy[v]);
					cout<<"("<<endi<<","<<endj<<")"<<endl;
					return;//��϶�����̵�·���ˣ�������������������·�ˣ�������
				}
			}
	}
}
int main(){
	//��¼��·������ǰ��ӡ�ģ��ɴ�ӳ����ߵ���ڰɣ�ʡ�£�
	run(endi,endj);
	return 0;
}
