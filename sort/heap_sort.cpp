#include<iostream>
#include<vector>

using namespace std;

void max_heaplfy(vector<int>&A ,int i, int A_heap_size){
    
    //因為C++的vector是從0開始的 所以左子節點是2*i+1 右子節點是2*i+2
    int l = 2*i+1;
    int r = 2*i+2;

    int largest = i;
    
    if (l < A_heap_size && A[l] > A[largest]){
        largest = l;//如果左邊比自己大 就把largest換成左邊
    }else{
        largest = i;
    }
    if (r < A_heap_size && A[r] > A[largest]){
        largest = r;//如果右邊比自己大 就把largest換成右邊
    }
    if (largest != i){
        swap(A[i], A[largest]);//如果largest不是自己 就把largest跟自己交換
        max_heaplfy(A, largest , A_heap_size);//交換完之後 可能會破壞largest下面的max heap 所以要繼續調整
    }


}

void build_max_heap(vector<int>&A, int A_heap_size){

    //從最後一個非葉子節點開始調整成max heap
    for (int i =(A_heap_size)/2;i > -1;--i){
        max_heaplfy(A,i,A_heap_size);
    }

}
void heap_sort(vector<int>&A){
    int A_heap_size = A.size();
    build_max_heap(A, A_heap_size);//先把A->max heap
    for (int i = 0; i < A.size(); ++i){
        swap(A[0], A[A.size()-1-i]);//把頂部最大的放到已排列前的節點
        A_heap_size = A_heap_size - 1;//把heap size減一 因為最後面已經放好最大值了
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