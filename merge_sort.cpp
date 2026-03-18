#include<iostream>
#include<vector>

using namespace std;

void merge(vector<int>& A, int p, int q, int r){
    
    int n_L = q-p+1;
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
    //兩個merge
    while( i<n_L && j<n_R){
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