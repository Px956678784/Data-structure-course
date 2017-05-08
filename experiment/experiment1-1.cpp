#include<iostream>
using namespace std;

template <typename E>
class List {
private:
 int maxsize;
 int listsize;
 int curr;
 E* listarray;
public:
 List(int size){
  maxsize=size;
  listsize=curr=0;
  listarray=new E[maxsize];
 }
 ~List(){ delete[]listarray;}
 void clear(){
  delete[]listarray;
  listsize=curr=0;
  listarray=new E[maxsize];
 }
 //求长度
 int length() const{ return listsize;}
 //取表中第i个结点值
 const E &get(int it) const{
  if(it-1<0 || it-1>=listsize)  {
   cout<<"Element doesn't exist"<<endl;
   system("pause");
  }
  return listarray[it-1];
 }
 //按值查找元素的位置
 int locate(const E &it){
  for(int i=0;i<listsize;i++){
   if(it==listarray[i])
    return i+1;
  }
  cout<<"Element doesn't exist"<<endl;
   system("pause");
 }
 //插入节点
 void insert(const E &it){
  if(listsize>=maxsize){
   cout<<"list capacity exceeded"<<endl;
   return;
  }
  for(int i=listsize;i>curr;i--)
   listarray[i]=listarray[i-1];
  listarray[curr]=it;
  listsize++;
 }
 //按位置删除结点
 void DeleteByLocation(int it){
  if(it-1<0 || it-1>=listsize)  {
   cout<<"Element doesn't exist"<<endl;
   system("pause");
  }
  for(int i=it-1;i<listsize-1;i++)
   listarray[i]=listarray[i+1];
  listsize--;
 }
 //将两个顺序表合并
 void merg(List &list2){
  for(int i=0;i<list2.listsize;i++)
   listarray[i+listsize]=list2.get(i+1);
  listsize+=list2.length();
 }
 //显示表
 void display(){
  for(int i=0;i<listsize;i++){
   cout<<listarray[i]<<" ";
  }
  cout<<endl;
 }
};


int main(){
 List<char> list1(10),list2(10);
 cout<<"创建顺序表1：";
 list1.insert('d');list1.insert('c');list1.insert('b');list1.insert('a');
 list1.display();
 cout<<"值为a在表中的位置为：";
 cout<<list1.locate('a')<<endl;
 cout<<"位置4的值为：";
 cout<<list1.get(4)<<endl;
 cout<<"删除第二个结点后顺序表:";
 list1.DeleteByLocation(2);
 list1.display();
 cout<<"创建顺序表2：";
 list2.insert('k');list2.insert('j');list2.insert('i');list2.insert('h');
 list2.display();
 cout<<"合并后的表为：";
 list1.merg(list2);
 list1.display();
 return 0;
 
}