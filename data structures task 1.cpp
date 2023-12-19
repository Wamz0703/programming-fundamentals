#include<iostream>
#include<vector>
#include<cmath>

bool findPair(const std::vector<int> & nums, int index_diff, int value_diff){
for(size_t i = 0;i < nums.size(); i++){
    for(size_t j = 0; j< nums.size();j++){
        if(i!= j && std::abs(static_cast<int>(i - j))<= index_diff && std::abs(nums[i] - nums[j])<= value_diff){
            return true;
        }
    }
}
return false;
}

int main(){
    std::vector<int> nums = {3,5,8,10,12};
    int index_diff =  2;
    int value_diff = 3;
    bool result = findPair(nums,index_diff,value_diff);
    std::cout<<std::boolalpha << result<<std:: endl;
    return 0;
}