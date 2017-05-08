//����+ջʵ���Թ�����
#include<iostream>
#include<vector>
using namespace std;
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
zx[]={-1,-1,0,1,1,1,0,-1},zy[]={0,1,1,1,0,-1,-1,-1},
//����յ�
starti=1,startj=1,endi=6,endj=6;
//�洢·�����������ջ
vector<int> stackx;
vector<int> stacky;
//��ӡ·��
void show(){
	vector<int>::iterator itx=stackx.begin();
	vector<int>::iterator ity=stacky.begin();
	while(itx<stackx.end()-1 && ity<stacky.end()-1){
		cout<<"("<<*itx<<","<<*ity<<")"<<"->";
		*itx++;*ity++;
	}
	cout<<"("<<*itx<<","<<*ity<<")"<<endl;
}
//�������
void run(int i,int j){
	//��¼�������ߵ�����ˣ�ͬʱ���һ������ط�������һ���ߵ�ʱ�����ƻ���
	stackx.push_back(i);stacky.push_back(j);
	maze[i][j]=1;
	//�ҵ��յ���!cool!���ϰ������ڼ�¼���Թ��߷���ӡ����
	if(i==endi && j==endj){
		show();
		//�������������Թ�������������Ļ�����Ҳ���Ի�ȥȻ������еķ������ҵ����������������е�̫��
		return;
	}
	for(int v=0;v<8;v++)
		//�������û��ǽ������û�б�����ǰ��ǵĻ��������߿���~
		if(maze[i+zx[v]][j+zy[v]]==0)
			run(i+zx[v],j+zy[v]);
	//ǰ����ܵ�·�Ѿ������ˣ��������ǰ������ı�ǲ�������ȥ����
	maze[i][j]=0;
	//��ȥ�Ļ��Ͱ�ǰ��ǵ������¼�����˰�
	stackx.pop_back();stacky.pop_back();
}
int main(){
	//Ha!��ʼ���Թ���!
	run(starti,startj);
	return 0;
}
