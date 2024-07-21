#include <bits/stdc++.h>
using namespace std;

///Class usage functionality

//class Fruit{
//public:
//    string name;
//    string color;
//};
//int main() {
//    Fruit apple;
//    apple.name = "Apple";
//    apple.color =  "red";
//    cout<<apple.name<<" "<<apple.color<<endl;
//}
//Output -> Apple red

///Class usage using pointer varible to an object of class and use of new keyword

//class Fruit{
//public:
//    string name;
//    string color;
//};
//int main() {
//    Fruit * mango = new Fruit();
//    mango->name = "Mango";
////    mango.color  //Not allowed for pointer variable created to point to an object of the class.
//    mango->color = "yellow";
//    cout<<mango->name<<" "<<mango->color<<endl;
//}
//Output -> Mango yellow

///Default Constructor Usage

//class Rectangle{
//public:
//    int l;
//    int b;
//    Rectangle(){
//        l=0;
//        b=0;
//        cout<<"Constructor Called"<<endl;
//    }
//};
//int main() {
//    Rectangle r1;
//    cout<<r1.l<<" "<<r1.b<<endl;
//}
//Output->
//Constructor Called
//0 0

///Paramatrised Constructor Usage

//class Rectangle{
//public:
//    int l;
//    int b;
//    Rectangle(int x, int y){
//        l=x;
//        b=y;
//        cout<<"Paramatrised Constructor Called"<<endl;
//    }
//};
//int main() {
//    Rectangle r2(3,4);
//    cout<<r2.l<<" "<<r2.b<<endl;
//}
//Output->
//Paramatrised Constructor Called
//3 4

///Copy Constructor Usage

//class Rectangle{
//public:
//    int l;
//    int b;
//    Rectangle(int x, int y){
//        l=x;
//        b=y;
//        cout<<"Paramatrised Constructor Called"<<endl;
//    }
//    Rectangle(Rectangle & r){
//        l=r.l;
//        b=r.b;
//        cout<<"Copy Constructor Called"<<endl;
//    }
//    ~Rectangle(){
//        cout<<"Destructor is Called"<<endl;
//    }
//};
//int main() {
//    Rectangle r2(3,4);
//    cout<<r2.l<<" "<<r2.b<<endl;
//    Rectangle r3(r2);
//    cout<<r3.l<<" "<<r3.b<<endl;
//}
//Output->
//Paramatrised Constructor Called
//3 4
//Copy Constructor Called
//3 4

///Destructor Usage

//class Rectangle{
//public:
//    int l;
//    int b;
//    Rectangle(int x, int y){
//        l=x;
//        b=y;
//        cout<<"Paramatrised Constructor Called"<<endl;
//    }
//    Rectangle(Rectangle & r){
//        l=r.l;
//        b=r.b;
//        cout<<"Copy Constructor Called"<<endl;
//    }
//    ~Rectangle(){
//        cout<<"Destructor is Called"<<endl;
//    }
//};
//int main() {
//    auto * r2 = new Rectangle(3,4);
//    cout<<r2->l<<" "<<r2->b<<endl;
//    delete r2;
//}
//Output ->
//Paramatrised Constructor Called
//3 4
//Destructor is Called

///By Default Private Access Specifier is assigned

//class ABC {
//    int x ;  // By Default access specifier is private
//public:
//    void set(int n){
//        x=n;
//    }
//    int get() {
//        return x;
//    }
//};
//int main() {
//    ABC obj1;
////   obj1.x; // This can't be done as x is a private member of the class ABC
//    obj1.set(3);
//    cout<<obj1.get()<<endl;
//}
//Output-> 3

///Access Specifiers

//class Parent{
//public:
//    int x;
//protected:
//    int y;
//private:
//    int z;
//};
//
//class Child1 : public Parent{
//    // x will remain public
//    //y will remain protected
//    //z will not be accessible
//};
//
//class Child2 : private Parent{
//    //x will be private
//    //y will be private
//    //z will not be accessible
//};
//class Child3 : protected Parent{
//    //x will be protected
//    //y will be protected
//    //z will not be accessible
//};

///Inheritance

//class Parent{
//public:
//    Parent(){
//        cout<<"Parent Class is called"<<endl;
//    }
//};
//
//class child: public Parent{
//public:
//    child(){
//        cout<<"Child class is called"<<endl;
//    }
//};
//int main() {
//    child c;
//}
//Output->
//Parent Class is called
//Child class is called

///Multiple Inheritance

//class Parent1{
//public:
//    Parent1(){
//        cout<<"Parent1 Class is called"<<endl;
//    }
//};
//class Parent2{
//public:
//    Parent2(){
//        cout<<"Parent2 Class is called"<<endl;
//    }
//};
//
//class child: public Parent1,public Parent2{
//public:
//    child(){
//        cout<<"Child class is called"<<endl;
//    }
//};
//int main() {
//    child c;
//}
//Output->
//Parent1 Class is called
//Parent2 Class is called
//Child class is called

///Method Overloading(Compile time Polymorphism)

//class Sum{
//public:
//    void add(int x, int y){
//        cout<<x+y<<endl;
//    }
//    void add(int x, int y, int z){
//        cout<<x+y+z<<endl;
//    }
//    void add(float x,float y){
//        cout<<x+y<<endl;
//    }
//};
//int main() {
//    Sum s;
//    s.add(2,3);
//    s.add(2,3,4);
//    s.add(float(2.3),float(3.8));
//}
//Output->
//5
//9
//6.1

///Run Time Polymorphism

//class Parent{
//public:
//    virtual void print(){
//        cout<<"parent class"<<endl;
//    }
//    void show(){
//        cout<<"parent class show"<<endl;
//    }
//};
//class child:public Parent{
//public:
//    void print(){
//        cout<<"child class"<<endl;
//    }
//    void show(){
//        cout<<"child class show"<<endl;
//    }
//};
//
//int main() {
//    Parent *p;
//    child c;
//    p= &c;
//    p->print();
//    p->show();
//}
//Output->
//child class
//parent class show


///Friend Function Usage

//class A{
//    int x;
//    friend void print(A &obj);
//};
//void print(A &obj){
//    cout<<obj.x<<endl;
//}
//int main() {
//    A obj;
//    print(obj);
//}
//Output->
//0

int main() {
  A obj;
  print(obj);
}
