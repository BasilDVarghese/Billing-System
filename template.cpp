#include<iostream>
using namespace std;

template <class T>
class vector1{
    public:
    int size;
    T a[20];

    vector1(int s){
        size=s;
    }

    int sum(){
        T s=0;
        for(int i=0;i<size;i++){
            s=s+a[i];
        }
        return s;
    }
};

int main(){
    vector1 <int> v(6);
    v.a[0]=10;
    v.a[1]=10;
    v.a[2]=10;
    v.a[3]=10;
    v.a[4]=10;
    v.a[5]=10;
    cout<<v.sum();
    
    vector1 <float> v2(6);
    v2.a[0]=10.1;
    v2.a[1]=10.2;
    v2.a[2]=10.3;
    v2.a[3]=10.4;
    v2.a[4]=10.5;
    v2.a[5]=10.6;
    cout<<endl<<v2.sum();

}