#include <iostream>
#include <string>
#include <queue>
#include <vector>
#include <map>
#include <string>
#include <fstream>
using namespace std;
class Node {
public:
	char element; //字符
	int weight; //该字符出现的次数或频率
    Node *left;//左子树
    Node *right;//右子树
	//叶节点
    Node(char e, int fre, Node *l=NULL, Node *r=NULL){
		element=e;
		weight=fre;
		left=l;
		right=r;
	}
	//中继节点
	Node(int fre, Node *l=NULL, Node *r=NULL){
		weight=fre;
		left=l;
		right=r;
	}
	//优先队列重载运算符，实现最小优先队列
    bool operator < (const Node &node) const { 
      return weight > node.weight;
    }
};
//统计输入字符的出现频率
void init(priority_queue<Node> &forest, string words) {
	int weight;
	map<char,int> count;
	for (int i=0; i<words.length(); i++) 
		count[words[i]]++;
	map<char, int>::const_iterator it = count.begin();
	while (it != count.end()) {
    	Node node(it->first, it->second);
		forest.push(node);
		++it;
	}
}

//构造哈夫曼树
void huffmanTree(priority_queue<Node> &forest) {
  while (forest.size() != 1) {
    Node *left = new Node(forest.top()); forest.pop();//取出最小的节点
    Node *right = new Node(forest.top()); forest.pop();//取出第二小的节点
    Node node(left->weight + right->weight, left, right);//生成树
    forest.push(node);//并入森林
  }
}
//哈夫曼编码
void huffmanCode(Node *root, string &coding, map<char, string> &huffman) {
	string code = coding;
	if (root->left == NULL)
		return;
	//左子树编码0
	coding += "0";
	//如果是叶子结点写入map,不然就一直找左子树
	if (root->left->left == NULL)
		huffman[root->left->element] = coding;
	else
		huffmanCode(root->left, coding, huffman);
	//还原原来的编码
	coding=code;
	//右子树编码1
	coding += "1";
	//如果是叶子结点写入map,不然就一直找右子树
	if (root->right->right == NULL)
		huffman[root->right->element] = coding;
	else
		huffmanCode(root->right,coding,huffman);
}

//解码
string decoding(queue<char> &codes,map<char, string> &huffman){
	string temp,words;
	map<char,string>::iterator it;
	//只要队列没空，就一个一个取码
	while(!codes.empty()){
		temp+=codes.front();
		codes.pop();
		for(it=huffman.begin();it!=huffman.end();it++)//查找地图
			if(it->second==temp){
				words+=it->first;
				temp="";//清空
			}
	}
	return words;
}
int main() {
	priority_queue<Node> forest;
	//读入需要编码的文件
	ifstream in("input.txt");
	string code,words;
	if(!in.is_open()){
		cout<<"打开文件出错"<<endl;
		return 0;
	}
	char ch;
	while(!in.eof()){
		in.read(&ch,1);
		if(ch>='a' && ch<='z')
			ch-=32;
		words+=ch;
	}
	in.close();
  //初始化字符信息
	init(forest, words);
  //构造哈夫曼树
	huffmanTree(forest);
  //哈夫曼编码
	Node root = forest.top();
	string coding;
	map<char,string> huffman;
	huffmanCode(&root,coding,huffman);
  //输出编码的结果至文件
	for (int i=0; i<words.length(); i++) {
		map<char,string>::iterator it=huffman.find(words[i]);
		if(it!=huffman.end()){
			code+=it->second;
		}
	}
	ofstream out("huffmancode.txt");
	out<<code<<endl;
	out.close();
	//读入需要解码的文件
	ifstream decode("huffmancode.txt");
	if(!decode.is_open()){
		cout<<"打开文件出错"<<endl;
		return 0;
	}
	//将哈夫曼码读入队列
	queue<char> codes;
	while(!decode.eof()){
		decode.read(&ch,1);
		codes.push(ch);
	}
	decode.close();
	 //输出解码的结果至文件
	ofstream de("decode.txt");
	de<<decoding(codes,huffman)<<endl;
	de.close();
  return 0;
}
