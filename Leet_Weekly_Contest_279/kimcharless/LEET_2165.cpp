long long smallestNumber(long long num) {
    if(num == 0) return 0;
    vector<int> change;
    while(num != 0){
        change.emplace_back(num%10);num/=10;
    }
    sort(change.begin(),change.end());
    if(change[0] == 0){
        int i = 0; while(change[i] == 0) i++;
        swap(change[0] , change[i]);
    }
    for(auto K:change){num = num*10+K;}
    return num;
}
