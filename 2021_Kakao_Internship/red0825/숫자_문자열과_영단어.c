#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// 파라미터로 주어지는 문자열은 const로 주어집니다. 변경하려면 문자열을 복사해서 사용하세요.
int solution(const char* s) {
    int answer = 0;
    int ss = 0;
    while(s[ss] != 0) ss++;
    for(int i = 0; i < ss; i++){
        answer *= 10;
        if('0' <= s[i] && s[i] <= '9'){
            answer += s[i] - '0';
        }
        else{
            if(s[i] == 'z'){
                i += 3;
                answer += 0;
            }
            else if(s[i] == 'o'){
                i += 2;
                answer += 1;
            }
            else if(s[i] == 't'){
                if(s[i+1] == 'w'){
                    i += 2;
                    answer += 2;
                }
                else{
                    i += 4;
                    answer += 3;
                }
            }
            else if(s[i] == 'f'){
                if(s[i+1] == 'o'){
                    i += 3;
                    answer += 4;
                }
                else{
                    i += 3;
                    answer += 5;
                }
            }
            else if(s[i] == 's'){
                if(s[i+1] == 'i'){
                    i += 2;
                    answer += 6;
                }
                else{
                    i += 4;
                    answer += 7;
                }
            }
            else if(s[i] == 'e'){
                i += 4;
                answer += 8;
            }
            else if(s[i] == 'n'){
                i += 3;
                answer += 9;
            }
        }
    }
    return answer;
}
