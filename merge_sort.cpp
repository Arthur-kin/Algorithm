#include<iostream>
#include<vector>

using namespace std;

void merge(vector<int>& A, int p, int q, int r){
    
    int n_L = q-p+1;//中間點的左邊有幾個元素，包含中間點q
    int n_R = r-q;
    vector<int> L(n_L);
    vector<int> R(n_R);
    for(int i=0; i< n_L;++i){
        L[i] = A[p+i];
    }
    for(int j=0; j< n_R;++j){
        R[j] = A[q+1+j];
    }

    int i = 0;
    int j = 0;
    int k = p;
    //兩個merge,條件因C++的vector是從0開始的 所以設<n_L和<n_R
    while( i<n_L && j<n_R){
        //這邊用<=的話 就會穩定排序 因為如果兩個元素相同 就會先把左邊的放進去
        if(L[i] <= R[j]){
            A[k] = L[i];
            ++i;        
        } else{
            A[k] = R[j];
            ++j;
        }
        ++k; 
    } 
    //只剩一邊
    while (i < n_L) {
        A[k] = L[i];
        ++i;
        ++k;
    }
    while (j < n_R) {
        A[k] = R[j];
        ++j;
        ++k;
    }

}

void merge_sort(vector<int>& A, int p, int r){
    //如果p>=r的話 就代表只有一個元素了 就不需要排序了 其實在C++裡面 這個條件也可以寫成p==r 因為不會有p>r的情況 但是寫成p>=r的話 就比較保險一點
    if( p >= r){
        return;
    }

    int q = p + (r-p)/2;

    merge_sort(A, p, q);
    merge_sort(A, q + 1, r);
    
    merge(A, p, q, r);
}

int main(){
    vector<int> A = {4,3,9,1,5};
    int n = A.size();
    
    //輸出
    cout << "排序前: ";
    for (int num : A) { //新用法
        cout << num << " ";
    }
    merge_sort(A, 0, n-1);

    cout << "\n";
    cout << "排序後: ";
    for (int num : A) {
        cout << num << " ";
    }
    return 0;

}