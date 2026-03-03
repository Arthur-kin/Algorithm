#include <iostream>
#include <vector>

//Insertion_sort function
void insertion_sort(std::vector<int>&A){
    int n = A.size();
    for (int i= 1;i < n;++i){
        int key = A[i];
        int j = i-1;
        while(j >= 0 && A[j] > key){
            A[j+1] = A[j];
            --j;
        }
        A[j+1] = key;
    }
}

int main(){
    std::vector<int> A = {4, 3, 9, 1};
    insertion_sort(A);
    for (int i = 0;i < A.size(); ++i){
        std::cout << A[i] << "";
    }
    std::cout << "\n";
    
    return 0;
}