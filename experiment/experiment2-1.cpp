//ջʵ���Թ�����
#include<iostream>
#include<vector>
using namespace std;
class node{
public:
	int x;
	int y;
	node(int i,int j){
		x=i;y=j;
	}
};
//��ʼ���Թ�
int maze[8][8]={{1,1,1,1,1,1,1,1},
{1,0,0,0,1,1,0,1},
{1,0,0,1,0,0,0,1},
{1,0,1,0,0,1,1,1},
{1,1,0,1,1,0,1,1},
{1,0,1,0,1,0,1,1},
{1,1,0,1,0,0,0,1},
{1,1,1,1,1,1,1,1}},
//xy������������
zx[]={-1,-1,0,1,1,1,0,-1},zy[]={0,1,1,1,0,-1,-1,-1};
//����յ�
node start(1,1),end(6,6);
//�洢·�������ջ
vector<node> stack;
//��ӡ·��
void show(){
	vector<node>::iterator it=stack.begin();
	while(it<stack.end()-1){
		cout<<"("<<it->x<<","<<it->y<<")"<<"->";
		*it++;
	}
	cout<<"("<<it->x<<","<<it->y<<")"<<endl;
}
//�������
void run(node now){
	//��¼�������ߵ�����ˣ�ͬʱ���һ������ط�������һ���ߵ�ʱ�����ƻ���
	stack.push_back(now);
	maze[now.x][now.y]=1;
	//�ҵ��յ���!cool!���ϰ������ڼ�¼���Թ��߷���ӡ����
	if(now.x==end.x && now.y==end.y){
		show();
		//�������������Թ�������������Ļ�����Ҳ���Ի�ȥȻ������еķ������ҵ����������������е�̫��
		return;
	}
	for(int v=0;v<8;v++)
		//�������û��ǽ������û�б�����ǰ��ǵĻ��������߿���~
		if(maze[now.x+zx[v]][now.y+zy[v]]==0){
			node next(now.x+zx[v],now.y+zy[v]);
			run(next);
		}
	//ǰ����ܵ�·�Ѿ������ˣ��������ǰ������ı�ǲ�������ȥ����
	maze[now.x][now.y]=0;
	//��ȥ�Ļ��Ͱ�ǰ��ǵ������¼�����˰�
	stack.pop_back();
}
int main(){
	//Ha!��ʼ���Թ���!
	run(start);
	return 0;
}
