#include<bits/stdc++.h>
using namespace std;

class MaxHeap{
    vector<int> v;
    int parent(int i){
        return i/2;
    }
    int left(int i){
        return 2*i;
    }
    int right(int i){
        return 2*i+1;
    }

    public:
        MaxHeap(){
            v.emplace_back(INT_MIN);
        }

        void insert(int x){
            v.emplace_back(x);
            for(int i=v.size()-1;i>1;i=parent(i)){
                if(parent(i)>0 && v[i]>v[parent(i)])    swap(v[i],v[parent(i)]);
                else break; 
            }
        }

        int pop(){
            if(v.size()<2){
                cout<<"\nUnderflow!";
                return INT_MIN;
            }
            int x=v[1];
            swap(v[1],v[v.size()-1]);
            v.pop_back();

            for(int i=1;i<v.size();){
                int l=left(i),r=right(i),largest=i;
                if(l<v.size() && v[l]>v[largest]) largest=l;
                if(r<v.size() && v[r]>v[largest]) largest=r;
                if(largest==i)  break;
                else{
                    swap(v[largest],v[i]);
                    i=largest;
                }
            }
            return x;
        }

        void print(){
            for(int i=1;i<v.size();i++)
                cout<<v[i]<<" ";
            cout<<"\n";
        }
};

int main(){
    MaxHeap heap;
    heap.insert(5);
    heap.insert(3);
    heap.insert(17);
    heap.insert(10);
    heap.insert(84);
    heap.insert(19);
    heap.insert(6);
    heap.insert(22);
    heap.insert(9);

    heap.print();
    cout<<heap.pop()<<"\n";
    cout<<heap.pop()<<"\n";
    cout<<heap.pop()<<"\n";
    cout<<heap.pop()<<"\n";
    cout<<heap.pop()<<"\n";
    cout<<heap.pop()<<"\n";
    heap.print();
    return 0;
}