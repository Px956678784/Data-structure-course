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
 //�󳤶�
 int length() const{ return listsize;}
 //ȡ���е�i�����ֵ
 const E &get(int it) const{
  if(it-1<0 || it-1>=listsize)  {
   cout<<"Element doesn't exist"<<endl;
   system("pause");
  }
  return listarray[it-1];
 }
 //��ֵ����Ԫ�ص�λ��
 int locate(const E &it){
  for(int i=0;i<listsize;i++){
   if(it==listarray[i])
    return i+1;
  }
  cout<<"Element doesn't exist"<<endl;
   system("pause");
 }
 //����ڵ�
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
 //��λ��ɾ�����
 void DeleteByLocation(int it){
  if(it-1<0 || it-1>=listsize)  {
   cout<<"Element doesn't exist"<<endl;
   system("pause");
  }
  for(int i=it-1;i<listsize-1;i++)
   listarray[i]=listarray[i+1];
  listsize--;
 }
 //������˳���ϲ�
 void merg(List &list2){
  for(int i=0;i<list2.listsize;i++)
   listarray[i+listsize]=list2.get(i+1);
  listsize+=list2.length();
 }
 //��ʾ��
 void display(){
  for(int i=0;i<listsize;i++){
   cout<<listarray[i]<<" ";
  }
  cout<<endl;
 }
};


int main(){
 List<char> list1(10),list2(10);
 cout<<"����˳���1��";
 list1.insert('d');list1.insert('c');list1.insert('b');list1.insert('a');
 list1.display();
 cout<<"ֵΪa�ڱ��е�λ��Ϊ��";
 cout<<list1.locate('a')<<endl;
 cout<<"λ��4��ֵΪ��";
 cout<<list1.get(4)<<endl;
 cout<<"ɾ���ڶ�������˳���:";
 list1.DeleteByLocation(2);
 list1.display();
 cout<<"����˳���2��";
 list2.insert('k');list2.insert('j');list2.insert('i');list2.insert('h');
 list2.display();
 cout<<"�ϲ���ı�Ϊ��";
 list1.merg(list2);
 list1.display();
 return 0;
 
}