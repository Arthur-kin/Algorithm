#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

void counting_sort(vector<int>& A ){
    int max_number = *max_element(A.begin(),A.end());//找到A裡面最大的數字 使用＃include<algorithm>裡面的max_element函數 因為count陣列的大小要是最大數字+1
    vector<int> count(max_number+1,0);//建立一個count陣列 來記錄0->max_number數字出現的次數
    
    for (int num : A){
        ++count[num];
    }
    
    for(int i = 1; i < count.size();++i){
        count[i] = count[i] + count[i-1];
    }
    
    vector<int> B(A.size(),0);//建立一個output陣列 
    
    //這裡很重要的是要從後往前面走 才是stable 不然會變成unstable 所以這裡不能用for (int num : A) 因為這樣是從前往後走
    for (int i = A.size()-1; i >= 0; --i){ //
        B[count[A[i]]-1] = A[i];
        --count[A[i]];//把count陣列裡面對應的數字減一 因為已經放了一個了
    }
    A = B;
}

int main(){
    vector<int> A = {4, 3, 9, 1, 11};
    cout << "排序前: ";
    for (int num : A) {
        cout << num << " ";
    }
    cout << endl;

    counting_sort(A);

    cout << "排序後: ";
    for (int num : A) {
        cout << num << " ";
    }
    cout << endl;

    return 0;

}