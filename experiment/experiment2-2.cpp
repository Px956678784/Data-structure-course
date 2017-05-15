//����ʵ���Թ�����
#include<iostream>
#include<queue>
using namespace std;
class node{
public:
	int x;
	int y;
	node(int i,int j){
		x=i;y=j;
	}
	node(){x=0;y=0;}
};
//�Թ��ṹ
int maze[8][8]={{1,1,1,1,1,1,1,1},
{1,0,0,0,1,1,0,1},
{1,0,0,1,0,0,0,1},
{1,0,1,0,0,1,1,1},
{1,1,0,1,1,0,1,1},
{1,0,1,0,1,0,1,1},
{1,1,0,1,0,0,0,1},
{1,1,1,1,1,1,1,1}},
//��������
zx[]={-1,-1,0,1,1,1,0,-1},zy[]={0,1,1,1,0,-1,-1,-1};
//��㣬�յ�
node start(1,1),end(6,6),path[8][8];//��¼ÿ�����ǰһ����
//���м�¼��Ҫ�����ĵ�
queue<node> searchlist;
//��ӡ·��
void show(node now){

	if(path[now.x][now.y].x){
		cout<<"("<<now.x<<","<<now.y<<")"<<"->";
		show(path[now.x][now.y]);
	}
}
//����
void run(node end){
	//�Ȱѵ�һ������Ϊ��Ҫ���ҵĵ㣬�������ȥ~
	searchlist.push(end);
	//��������ϻ��м�¼�ĵ�û���ѵ������Ǿ�ȥ��
	while(!searchlist.empty()){
		//��������ó���֮���������ʾ�����Ѿ��ҹ������
		node now=searchlist.front();
		searchlist.pop();
		//���������Ѿ�����������ˣ����һ��
		maze[now.x][now.y]=1;	
		for(int v=0;v<8;v++)
			//����������û��ǽҲû�б�ǣ��Ͱ�����¼�ڶ��У����ᰤ��ȥ��
			if(maze[now.x+zx[v]][now.y+zy[v]]==0){
				node next(now.x+zx[v],now.y+zy[v]);
				searchlist.push(next);
				//�������ĵ���������������ҹ�ȥ�ģ������ӡ��ʱ����ԴӺ���ǰ�ҵ�·��
				path[now.x+zx[v]][now.y+zy[v]].x=now.x;
				path[now.x+zx[v]][now.y+zy[v]].y=now.y;
				//�����������յ�Ļ�����̫���ˣ�ֱ�Ӱ�·���������
				if(next.x==start.x && next.y==start.y){
					show(next);
					cout<<"("<<end.x<<","<<end.y<<")"<<endl;
					return;//��϶�����̵�·���ˣ�������������������·�ˣ�������
				}
			}
	}
}
int main(){
	//��¼��·������ǰ��ӡ�ģ��ɴ�ӳ����ߵ���ڰɣ�ʡ�£�
	run(end);
	return 0;
}
