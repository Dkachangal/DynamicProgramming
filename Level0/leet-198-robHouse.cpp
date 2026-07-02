#include<iostream>
#include<vector>
#include<climits>
using namespace std;

int robHouseRecc(vector<int> nums, int idx) {
    if (idx >= nums.size()) return 0;

    int cost = max(nums[idx] + robHouseRecc(nums, idx+2), robHouseRecc(nums, idx+1));
    return cost;
}

int robHouseMemo(vector<int> nums, int idx, vector<int> &dp) {
    if (idx >= nums.size()) return 0;
    if (dp[idx] != -1) return dp[idx];
    dp[idx] = max(nums[idx] + robHouseMemo(nums, idx+2, dp), robHouseMemo(nums, idx+1, dp));
    return dp[idx];
}

int robHouseTabu(vector<int> nums) {
    vector<int> dp(nums.size());

    dp[0] = nums[0];
    dp[1] = max(nums[0], nums[1]);

    for (int i=2; i<nums.size(); i++) {
        int choose = nums[i] + dp[i-2];
        int skip = nums[i+1];

        dp[i] = max(choose, skip);
    }
    return dp[nums.size()-1];
}
int main() {
    vector<int> nums = {2,7,9,3,1};
    vector<int> dp(nums.size()+1);

    int money = robHouseRecc(nums, -1);
    int dpMoney = robHouseMemo(nums, 0, dp);
    int tabMoney = robHouseTabu(nums);
    cout<< money << endl << dpMoney << endl << tabMoney;

    return 0;
}