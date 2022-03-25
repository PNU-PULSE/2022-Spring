#include <iostream>

using namespace std;

int main(){
    ios::sync_with_stdio(false);

    int N, K;
    int num_lion, len, a, b, result;

    cin >> N >> K;

    int* arr = new int[N];
    int* pos_lion = new int[N];

    for(int i=0; i<N; i++)
        cin >> arr[i];

    num_lion = 0;
    for(int i=0; i<N; i++){
        if(arr[i] == 1)
            pos_lion[num_lion++] = i;
    }

    a = b = 0;
    result = N + 1;
    len = 0;

    while(b < num_lion){
        if(b-a+1 < K){
                b++;
                continue;
        }

        len = pos_lion[b] - pos_lion[a] + 1;
        if(len < result) result = len;
        a++; b++;

    }

    if(result == N+1) result = -1;

    cout << result << endl;

    delete[] arr;

    return 0;
}
