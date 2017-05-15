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
	char element; //�ַ�
	int weight; //���ַ����ֵĴ�����Ƶ��
    Node *left;//������
    Node *right;//������
	//Ҷ�ڵ�
    Node(char e, int fre, Node *l=NULL, Node *r=NULL){
		element=e;
		weight=fre;
		left=l;
		right=r;
	}
	//�м̽ڵ�
	Node(int fre, Node *l=NULL, Node *r=NULL){
		weight=fre;
		left=l;
		right=r;
	}
	//���ȶ��������������ʵ����С���ȶ���
    bool operator < (const Node &node) const { 
      return weight > node.weight;
    }
};
//ͳ�������ַ��ĳ���Ƶ��
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

//�����������
void huffmanTree(priority_queue<Node> &forest) {
  while (forest.size() != 1) {
    Node *left = new Node(forest.top()); forest.pop();//ȡ����С�Ľڵ�
    Node *right = new Node(forest.top()); forest.pop();//ȡ���ڶ�С�Ľڵ�
    Node node(left->weight + right->weight, left, right);//������
    forest.push(node);//����ɭ��
  }
}
//����������
void huffmanCode(Node *root, string &coding, map<char, string> &huffman) {
	string code = coding;
	if (root->left == NULL)
		return;
	//����������0
	coding += "0";
	//�����Ҷ�ӽ��д��map,��Ȼ��һֱ��������
	if (root->left->left == NULL)
		huffman[root->left->element] = coding;
	else
		huffmanCode(root->left, coding, huffman);
	//��ԭԭ���ı���
	coding=code;
	//����������1
	coding += "1";
	//�����Ҷ�ӽ��д��map,��Ȼ��һֱ��������
	if (root->right->right == NULL)
		huffman[root->right->element] = coding;
	else
		huffmanCode(root->right,coding,huffman);
}

//����
string decoding(queue<char> &codes,map<char, string> &huffman){
	string temp,words;
	map<char,string>::iterator it;
	//ֻҪ����û�գ���һ��һ��ȡ��
	while(!codes.empty()){
		temp+=codes.front();
		codes.pop();
		for(it=huffman.begin();it!=huffman.end();it++)//���ҵ�ͼ
			if(it->second==temp){
				words+=it->first;
				temp="";//���
			}
	}
	return words;
}
int main() {
	priority_queue<Node> forest;
	//������Ҫ������ļ�
	ifstream in("input.txt");
	string code,words;
	if(!in.is_open()){
		cout<<"���ļ�����"<<endl;
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
  //��ʼ���ַ���Ϣ
	init(forest, words);
  //�����������
	huffmanTree(forest);
  //����������
	Node root = forest.top();
	string coding;
	map<char,string> huffman;
	huffmanCode(&root,coding,huffman);
  //�������Ľ�����ļ�
	for (int i=0; i<words.length(); i++) {
		map<char,string>::iterator it=huffman.find(words[i]);
		if(it!=huffman.end()){
			code+=it->second;
		}
	}
	ofstream out("huffmancode.txt");
	out<<code<<endl;
	out.close();
	//������Ҫ������ļ�
	ifstream decode("huffmancode.txt");
	if(!decode.is_open()){
		cout<<"���ļ�����"<<endl;
		return 0;
	}
	//����������������
	queue<char> codes;
	while(!decode.eof()){
		decode.read(&ch,1);
		codes.push(ch);
	}
	decode.close();
	 //�������Ľ�����ļ�
	ofstream de("decode.txt");
	de<<decoding(codes,huffman)<<endl;
	de.close();
  return 0;
}
