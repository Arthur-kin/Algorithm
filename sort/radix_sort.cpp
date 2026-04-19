#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;


void counting_sort_for_radix(vector<int>& A, int exp){
    vector<int> B(A.size(),0);
	vector<int> count(10,0); //因為是十進位 0-9 共10個數字

	for (int num : A){
		int digit = (num / exp) % 10;//找到對應位數以上的數字 然後在用%10找餘數
		++count[digit];
	}

	for (int i = 1; i <count.size(); ++i){
		count[i] = count[i] + count[i-1];//也可以寫成 count[i] += count[i-1];
	}

	for (int i = A.size() - 1; i >= 0; --i){
		int digit = (A[i] / exp) % 10;
		B[count[digit] - 1] = A[i];
		--count[digit];
	}
	A = B;
}

void radix_sort(vector<int>& A){
	if (A.empty()) return; 

	int max_number =*max_element(A.begin(),A.end());

	for (int exp = 1; max_number/exp > 0; exp *= 10){
		counting_sort_for_radix(A, exp);
	}
}

int main(){
	vector<int> A = {345 ,846 ,123 ,567, 789 ,523};
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
