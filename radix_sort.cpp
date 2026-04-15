#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

void radix_sort(vector<int>& A){
	int n = A[O];
	int digit = 0;
	while(n != 0){
		n /= 10;
		++digit;
	}
	for (int i = 0; i < digit; ++i){}
    
}

void counting_sort(vector<int>& A ){
    int max_number = *max_element(A.begin(),A.end());//找到A裡面最大的數字 因為count陣列的大小要是最大數字+1
    vector<int> count(max_number+1,0);//建立一個count陣列 來記錄0->max_number數字出現的次數
    
    for (int num : A){
        ++count[num];
    }
    
    for(int i = 1; i < count.size();++i){
        count[i] = count[i] + count[i-1];//把count陣列改成前綴和陣列 這樣就可以知道每個數字應該放在output陣列的哪裡
    }
    
    vector<int> B(A.size(),0);//建立一個output陣列 來存放排序後的結果
    
    for (int num : A){
        B[count[num]-1] = num;
        --count[num];//把count陣列裡面對應的數字減一 因為已經放了一個了
    }
    A = B;
}
int main(){
	vector<int> A = {345 ,846 ,123 ,567};
	cout << "排序前: ";
	for (int num : A) {
		cout << num << " ";
	}
	cout << endl;
	radix_sort(A);
	cout << "排序後: ";
	for (int num : A) {
		cout << num << " ";
	}
	cout << endl;

}
