#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

void bubble_sort(vector<int>&A){
    int n = A.size();
    for (int i = 0;i < n-1;++i){
        for (int j = n-1;j >= i+1;--j){
          if (A[j] < A[j-1]){
            swap(A[j], A[j-1]);//新東西 但要加上面的algorithm
          }
        }      
    }
}

int main(){
    
    vector<int> A = {4, 3, 9, 1};
    cout << "排序前: ";
    for (int num : A) { //新用法
        cout << num << " ";
    }
    bubble_sort(A);
    cout << "\n";
    cout << "排序後: ";
    for (int num : A) {
        cout << num << " ";
    }

}