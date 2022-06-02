#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// 파라미터로 주어지는 문자열은 const로 주어집니다. 변경하려면 문자열을 복사해서 사용하세요.
int solution(const char* s) {
    int answer = 0;

    for (int i=0; i<strlen(s); i++) {
        answer *= 10;

        if (s[i] >= '0' && s[i] <= '9') {
            answer += s[i] - '0';
        }
        else if (s[i] == 'z') {
            i += 3;
        }
        else if (s[i] == 'o') {
            answer += 1;
            i += 2;
        }
        else if (s[i] == 't') {
            if (s[i+1] == 'w') {
                answer += 2;
                i += 2;
            }
            else {
                answer += 3;
                i += 4;
            }
        }
        else if (s[i] == 'f') {
            if (s[i+1] == 'o') {
                answer += 4;
                i += 3;
            }
            else {
                answer += 5;
                i += 3;
            }
        }
        else if (s[i] == 's') {
            if (s[i+1] == 'i') {
                answer += 6;
                i += 2;
            }
            else {
                answer += 7;
                i += 4;
            }
        }
        else if (s[i] == 'e') {
            answer += 8;
            i += 4;
        }
        else if (s[i] == 'n') {
            answer += 9;
            i += 3;
        }
    }

    return answer;
}
