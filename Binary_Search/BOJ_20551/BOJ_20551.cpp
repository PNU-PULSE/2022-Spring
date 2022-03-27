#include <iostream>
#include <algorithm>

int N, M, A[200000];

int f(int x){
    int low, high, mid;

    low = 0;
    high = N-1;

    while(high-low >= 0){
        mid = (low+high) / 2;

        if(A[mid] == x){
            if(A[mid-1] != A[mid] || mid == 0){
                return mid;
            }
            else{
                high = mid - 1;
            }
        }
        else if(A[mid] > x){
            high = mid - 1;
        }
        else{
            low = mid + 1;
        }

    }

    return -1;
}

int main(){
    int tmp;

    scanf("%d %d", &N, &M);

    for(int i=0; i<N; i++)
        scanf("%d", &A[i]);

    std::sort(A, A+N);

    for(int i=0; i<M; i++){
        scanf("%d", &tmp);
        printf("%d\n", f(tmp));
    }

    return 0;
}
