#include<iostream>
#include<vector>

using namespace std;

void max_heaplfy(vector<int>&A ,int i, int A_heap_size){
    
    int l = 2*i+1;
    int r = 2*i+2;

    int largest = i;
    
    if (l < A_heap_size && A[l] > A[largest]){
        largest = l;
    }else{
        largest = i;
    }
    if (r < A_heap_size && A[r] > A[largest]){
        largest = r;
    }
    if (largest != i){
        swap(A[i], A[largest]);
        max_heaplfy(A, largest , A_heap_size);
    }


}

void build_max_heap(vector<int>&A, int A_heap_size){

    for (int i =(A_heap_size)/2;i > -1;--i){
        max_heaplfy(A,i,A_heap_size);
    }

}
void heap_sort(vector<int>&A){
    int A_heap_size = A.size();
    build_max_heap(A, A_heap_size);//先把A調整成max heap
    for (int i = 0; i < A.size(); ++i){
        swap(A[0], A[A.size()-1-i]);//把最大的放到最後面
        A_heap_size = A_heap_size - 1;//把heap size減一
        max_heaplfy(A, 0, A_heap_size);//重新調整成max heap  
    }
    

}

int main(){
    vector<int> A = {4 ,3 ,1 ,9};
    cout<<"排序前:";
    for (int num : A){
        cout<< num << " ";
    }
    heap_sort(A);
    cout << "\n";
    cout<<"排序後:";
    for (int num : A){
        cout<< num << " ";
    }
}