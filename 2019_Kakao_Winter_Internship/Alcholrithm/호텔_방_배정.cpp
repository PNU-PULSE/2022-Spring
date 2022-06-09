#include <string>
#include <vector>
#include <map>

using namespace std;

map<unsigned long long,unsigned long long> rooms;

long long occupy(long long r){
    if(rooms.find(r) == rooms.end()) return rooms[r] = r;
    return rooms[r] = occupy(rooms[r] + 1); 
}
vector<long long> solution(long long k, vector<long long> room_number) {
    vector<long long> answer(room_number.size());
    for(size_t i=0;i<room_number.size();++i){
        answer[i] = occupy(room_number[i]);
    }

    return answer;
}