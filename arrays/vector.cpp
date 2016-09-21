#include<stdio.h>
#include<vector>
using namespace std;
vector<int> maxset(vector<int> A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    int index;
    int length=0;
    long long int max_sum = 0, max_length = 0, max_index = -1;
    long long int sum=0;
    int len = A.size();
    int flag = 1, flag2 = 0;
    for(int i = 0; i < len; i++){
        if(A[i] >= 0){
            sum += A[i];
            length++;
            if(flag){index=i; flag=0;}
            flag2 = 1;
        }
        else if(flag2){
            if(sum>max_sum){max_sum = sum; max_length = length; max_index = index;}
            else if(sum == max_sum){
                if(length>max_length){max_length = length; max_index = index;}
            }
            sum = 0;
            length = 0;
            flag = 1;
            flag2 = 0;
        }
    }
    if(flag2){
        if(sum>max_sum){max_sum = sum; max_length = length; max_index = index;}
        else if(sum == max_sum){
            if(length>max_length){max_length = length; max_index = index;}
        }
        sum = 0;
        length = 0;
        flag = 1;
        flag2 = 0;
    }
    // printf("%d\n", max_index);
    int i = 0;
    if(max_index != -1){
        while(i < max_index){
            A.erase(A.begin());
            i++;
        }
        i = 0;
        while(A[i]>=0 && i < A.size())i++;
        A.erase(A.begin()+i, A.end());
    }
    else{
        A.erase(A.begin(), A.end());
    }
    return A;
}

int main(){
    int arr[] = {1967513926, 1540383426, -1303455736, -521595368};
    vector<int> A (arr, arr + 4);
    A = maxset(A);
    int len = A.size();
    for(int i = 0; i < len; i++)
        printf("%d ", A[i]);
    return 0;
}
