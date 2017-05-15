//栈实现迷宫问题
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
zx[]={-1,-1,0,1,1,1,0,-1},zy[]={0,1,1,1,0,-1,-1,-1};
//起点终点
node start(1,1),end(6,6);
//存储路径坐标的栈
vector<node> stack;
//打印路径
void show(){
	vector<node>::iterator it=stack.begin();
	while(it<stack.end()-1){
		cout<<"("<<it->x<<","<<it->y<<")"<<"->";
		*it++;
	}
	cout<<"("<<it->x<<","<<it->y<<")"<<endl;
}
//深度搜索
void run(node now){
	//记录我现在走到这儿了，同时标记一下这个地方，别下一步走的时候又绕回来
	stack.push_back(now);
	maze[now.x][now.y]=1;
	//找到终点了!cool!马上把我现在记录的迷宫走法打印下来
	if(now.x==end.x && now.y==end.y){
		show();
		//现在马上走离迷宫，如果不加这句的话，我也可以回去然后把所有的方法都找到，不过那样方法有点太多
		return;
	}
	for(int v=0;v<8;v++)
		//如果这里没有墙，而且没有被我以前标记的话，就走走看呗~
		if(maze[now.x+zx[v]][now.y+zy[v]]==0){
			node next(now.x+zx[v],now.y+zy[v]);
			run(next);
		}
	//前面可能的路已经走完了，现在咱们把这个点的标记擦掉，回去看看
	maze[now.x][now.y]=0;
	//回去的话就把前面记的这个记录擦掉了吧
	stack.pop_back();
}
int main(){
	//Ha!开始走迷宫吧!
	run(start);
	return 0;
}
