//队列实现迷宫问题
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
//迷宫结构
int maze[8][8]={{1,1,1,1,1,1,1,1},
{1,0,0,0,1,1,0,1},
{1,0,0,1,0,0,0,1},
{1,0,1,0,0,1,1,1},
{1,1,0,1,1,0,1,1},
{1,0,1,0,1,0,1,1},
{1,1,0,1,0,0,0,1},
{1,1,1,1,1,1,1,1}},
//增量数组
zx[]={-1,-1,0,1,1,1,0,-1},zy[]={0,1,1,1,0,-1,-1,-1};
//起点，终点
node start(1,1),end(6,6),path[8][8];//记录每个点的前一个点
//队列记录需要搜索的点
queue<node> searchlist;
//打印路径
void show(node now){

	if(path[now.x][now.y].x){
		cout<<"("<<now.x<<","<<now.y<<")"<<"->";
		show(path[now.x][now.y]);
	}
}
//广搜
void run(node end){
	//先把第一个点列为需要查找的点，从这里进去~
	searchlist.push(end);
	//如果队列上还有记录的点没有搜到，我们就去找
	while(!searchlist.empty()){
		//把这个点拿出来之后擦掉，表示我们已经找过这儿啦
		node now=searchlist.front();
		searchlist.pop();
		//我们现在已经到达这个点了，标记一下
		maze[now.x][now.y]=1;	
		for(int v=0;v<8;v++)
			//如果这个方向没有墙也没有标记，就把他记录在队列，待会挨个去查
			if(maze[now.x+zx[v]][now.y+zy[v]]==0){
				node next(now.x+zx[v],now.y+zy[v]);
				searchlist.push(next);
				//这个待查的点是我现在这个点找过去的，待会打印的时候可以从后往前找到路径
				path[now.x+zx[v]][now.y+zy[v]].x=now.x;
				path[now.x+zx[v]][now.y+zy[v]].y=now.y;
				//如果这个点是终点的话，那太好了，直接把路径打出来吧
				if(next.x==start.x && next.y==start.y){
					show(next);
					cout<<"("<<end.x<<","<<end.y<<")"<<endl;
					return;//这肯定是最短的路径了！不用再找其他更长的路了，咱们走
				}
			}
	}
}
int main(){
	//记录的路径是向前打印的，干脆从出口走到入口吧，省事！
	run(end);
	return 0;
}
