#include <bits/stdc++.h>
using namespace std;

int minDigits(long long N, int K){
    int digits_num = floor(log10(N) + 1);
    int temp_sum = 0;
    int temp = digits_num;
    int result;
    int X, var;
    int sum = 0;
    int num2 = N;
    while (num2 != 0) {
        sum += num2 % 10;
        num2 /= 10;
    }
    if (sum <= K) {
        X = 0;
    }
    else {
        while (temp > 0) {
            var = (N / (pow(10, temp - 1)));
            temp_sum += var % 10;
            if (temp_sum >= K) {
                var /= 10;
                var++;
                result = var * pow(10, temp);
                break;
            }
            temp--;
        }
        X = result - N;
        return X;
    }
}

int main(){
    long long N,K; cin >> N >> K;
    cout << minDigits(N, K);
    return 0;
}