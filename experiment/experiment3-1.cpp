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
	for (int i = 0; i < words.length(); i++) {
		if(words[i]>='a' && words[i]<='z')
			words[i]-=32;
		count[words[i]]++;
	}		
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
//输出编码结果
void print(map<char, string> huffman) {
  map<char, string>::const_iterator it = huffman.begin();
  while (it != huffman.end()) {
    cout << it->first << ": " << it->second << endl;
    ++it;
  }
}
int main() {
  priority_queue<Node> forest;
  string words;
  //初始化字符信息
  cout << "请输入字符串 ";
  cin >> words;
  init(forest, words);
  //构造哈夫曼树
  huffmanTree(forest);
  //哈夫曼编码
  Node root = forest.top();
  string coding;
  map<char, string> huffman;
  huffmanCode(&root, coding, huffman);
  //输出编码结果
  print(huffman);
  return 0;
}
