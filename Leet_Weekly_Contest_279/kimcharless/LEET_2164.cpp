vector<int> sortEvenOdd(vector<int> &nums){
    vector<int> odd,even;
    int siz = nums.size();
    for(int i=0;i<siz;i++){
        if(i%2 == 0) even.emplace_back(nums[i]);
        else         odd.emplace_back(nums[i]);
    }
    nums.clear();
    sort(even.begin(),even.end());
    sort(odd.begin(),odd.end(),greater<>());
    auto even_iter = even.begin(),odd_iter = odd.begin();
    for(int i=0;i<siz;i++){
        if(i%2 == 0) nums.emplace_back(*even_iter++);
        else nums.emplace_back(*odd_iter++);
    }
    return nums;
}
