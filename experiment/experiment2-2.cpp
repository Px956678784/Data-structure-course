//广搜+队列实现迷宫问题
#include<iostream>
#include<vector>
#include<queue>
using namespace std;
//迷宫结构
int maze[8][8]={{1,1,1,1,1,1,1,1},
{1,0,0,0,1,1,0,1},
{1,0,0,1,0,0,0,1},
{1,0,1,0,0,1,1,1},
{1,1,0,1,1,0,1,1},
{1,0,1,0,1,0,1,1},
{1,1,0,1,0,0,0,1},
{1,1,1,1,1,1,1,1}},
//记录每个点的前一个点
path[8][8][2],
//增量数组
zx[]={-1,-1,0,1,1,1,0,-1},zy[]={0,1,1,1,0,-1,-1,-1},
//起点，终点
starti=1,startj=1,endi=6,endj=6;
//队列记录需要搜索的点
queue<int> searchx;
queue<int> searchy;
//打印路径
void show(int i,int j){
	if(path[i][j][0]!=0 && path[i][j][1]!=0){
		cout<<"("<<i<<","<<j<<")"<<"->";
		show(path[i][j][0],path[i][j][1]);
	}
}
//广搜
void run(int endi,int endj){
	//先把第一个点列为需要查找的点，从这里进去~
	searchx.push(endi);searchy.push(endj);
	//如果队列上还有记录的点没有搜到，我们就去找
	while(!searchx.empty() && !searchy.empty()){
		//把这个点拿出来之后擦掉，表示我们已经找过这儿啦
		int nowx=searchx.front(),nowy=searchy.front();
		searchx.pop();searchy.pop();
		//我们现在已经到达这个点了，标记一下
		maze[nowx][nowy]=1;	
		for(int v=0;v<8;v++)
			//如果这个方向没有墙也没有标记，就把他记录在队列，待会挨个去查
			if(maze[nowx+zx[v]][nowy+zy[v]]==0){
				searchx.push(nowx+zx[v]);
				searchy.push(nowy+zy[v]);
				//这个待查的点是我现在这个点找过去的，待会打印的时候可以从后往前找到路径
				path[nowx+zx[v]][nowy+zy[v]][0]=nowx;
				path[nowx+zx[v]][nowy+zy[v]][1]=nowy;
				//如果这个点是终点的话，那太好了，直接把路径打出来吧
				if(nowx+zx[v]==starti && nowy+zy[v]==startj){
					show(nowx+zx[v],nowy+zy[v]);
					cout<<"("<<endi<<","<<endj<<")"<<endl;
					return;//这肯定是最短的路径了！不用再找其他更长的路了，咱们走
				}
			}
	}
}
int main(){
	//记录的路径是向前打印的，干脆从出口走到入口吧，省事！
	run(endi,endj);
	return 0;
}
