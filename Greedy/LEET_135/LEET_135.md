# BOJ 9202 Boggle

![예시 이미지](https://github.com/PNU-PULSE/2022-Spring/blob/main/Greedy/LEET_135/1.png)

## 문제 설명
문제는 모든 애들에게 최소 1개 이상의 사탕을 받아야 하며 <br>
모든 애들은 인접한 애들의 rating이 자신보다 <br>
낮은 아이가 있을 경우 무조건 그 아이보다 많이 받는데 이 때 나눠주는 사탕의 개수를 최소화해야하는 문제이다. <br>

## 문제 분석
문제에서 중요한 것은 <b><u>감소하는 부분 수열</u></b>을 찾는 것이다. <br>
인접한 아이의 rating이 자신보다 낮을 경우 무조건 그 아이보다 많은 사탕을 받아야한다. <br>
따라서 rating이 i번째 인덱스부터 j번째 인덱스까지 연속적으로 감소한다면 i번째 아이가 받을 사탕의 값은 i + 1번째부터 j번째 아이들이 받을 사탕 보다 많아야 한다. <br>
이때 나눠주는 사탕의 수는 최소가 되어야 하고, j번째 인덱스에서 감소하는 수열이 종료가 되므로 j번째 아이가 받을 사탕의 수는 j - 1번째 아이가 받을 사탕보다 무조건 작기만 하면 <br>
아무런 제한 사항이 없다. 따라서 감소하는 수열에서는 j번째부터 i + 1번째까지의 아이들은 1부터 1개씩 개수를 증가시키며 사탕을 받으면 되고 <br>
i번째 아이는 i + 1번째 아이가 받는 사탕보다 크고, i - 1번째 아이의 rating만을 고려해서 <br>
i - 1번째 아이의 rating이 자신보다 낮으면 i - 1번째 아이보다 사탕을 많이 받도록만 하면 된다. <br>

## Case별 Greedy
이전 단계에서 문제를 분석한 것을 기반으로 해서 <br>
나올 수 있는 경우를 모델링해서 코드를 짜면 된다. <br>
먼저 이전에 아무런 사람이 없는 0번째 인덱스의 아이와 나머지 아이들의 경우로 문제를 쪼개고 <br>
감소하는 수열인지 아닌지 <br>
이와 같이 케이스를 나누어 각 케이스에서 Greedy한 사탕의 개수를 정해주면 문제를 해결할 수 있다. <br>


### 전체 코드

```C++
class Solution {
public:
    int desending(vector<int>& ratings, int start) {
        int i;
        for(i = start + 1; i < ratings.size() && (i == 0 || ratings[i] < ratings[i - 1]); ++i);
        return i - 1;
    }
    int candy(vector<int>& ratings) {
        int n = 0;
        
        int i = 0;
        int end = 0;
        int pre = 1;
        int gap;
        
        end = desending(ratings, i);
        if (end == i) {
            n += 1;
            i = i + 1;
        }
        else {
            gap = end - i;
            n += (gap + 2) * (gap + 1) / 2;
            i = end + 1;
        }

        while (i < ratings.size()) {
            end = desending(ratings, i);
            if (end == i) {
                if (ratings[i - 1] == ratings[i]) {
                    pre = 1;
                }
                else {
                    pre += 1;
                }
                n += pre;
            }
            else {
                if (ratings[i - 1] == ratings[i]) {
                    pre = 1;
                }
                else {
                    pre += 1;
                }
                gap = end - i + 1;
                if (gap < pre) {
                    n+= pre - gap;
                }
                n += (gap + 1) * gap / 2;
                pre = 1;
                i = end;
            }
            ++i;
        }

        return n;
    }
};