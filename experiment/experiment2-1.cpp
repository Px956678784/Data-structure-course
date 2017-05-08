//深搜+栈实现迷宫问题
#include<iostream>
#include<vector>
using namespace std;
//初始化迷宫
int maze[8][8]={{1,1,1,1,1,1,1,1},
{1,0,0,0,1,1,0,1},
{1,0,0,1,0,0,0,1},
{1,0,1,0,0,1,1,1},
{1,1,0,1,1,0,1,1},
{1,0,1,0,1,0,1,1},
{1,1,0,1,0,0,0,1},
{1,1,1,1,1,1,1,1}},
//xy坐标增量数组
zx[]={-1,-1,0,1,1,1,0,-1},zy[]={0,1,1,1,0,-1,-1,-1},
//起点终点
starti=1,startj=1,endi=6,endj=6;
//存储路径坐标的两个栈
vector<int> stackx;
vector<int> stacky;
//打印路径
void show(){
	vector<int>::iterator itx=stackx.begin();
	vector<int>::iterator ity=stacky.begin();
	while(itx<stackx.end()-1 && ity<stacky.end()-1){
		cout<<"("<<*itx<<","<<*ity<<")"<<"->";
		*itx++;*ity++;
	}
	cout<<"("<<*itx<<","<<*ity<<")"<<endl;
}
//深度搜索
void run(int i,int j){
	//记录我现在走到这儿了，同时标记一下这个地方，别下一步走的时候又绕回来
	stackx.push_back(i);stacky.push_back(j);
	maze[i][j]=1;
	//找到终点了!cool!马上把我现在记录的迷宫走法打印下来
	if(i==endi && j==endj){
		show();
		//现在马上走离迷宫，如果不加这句的话，我也可以回去然后把所有的方法都找到，不过那样方法有点太多
		return;
	}
	for(int v=0;v<8;v++)
		//如果这里没有墙，而且没有被我以前标记的话，就走走看呗~
		if(maze[i+zx[v]][j+zy[v]]==0)
			run(i+zx[v],j+zy[v]);
	//前面可能的路已经走完了，现在咱们把这个点的标记擦掉，回去看看
	maze[i][j]=0;
	//回去的话就把前面记的这个记录擦掉了吧
	stackx.pop_back();stacky.pop_back();
}
int main(){
	//Ha!开始走迷宫吧!
	run(starti,startj);
	return 0;
}
