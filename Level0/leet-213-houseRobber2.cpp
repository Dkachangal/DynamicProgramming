#include <iostream>
#include<vector>
using namespace std;

int main()
{
    // ṚECURSION & TABULATION-I APPROACH IN LEET CODE

    // THIS IS THE DP APPROACH WITH TABULATION 
    vector<int> nums = {1,2,3,1};
    if (nums.size() == 1)
        return nums[0];
    if (nums.size() == 2)
        return max(nums[0], nums[1]);

    int iM2 = nums[0];
    int iM1 = max(nums[0], nums[1]);

    for (int i = 2; i < nums.size() - 1; i++)
    {
        int pick = nums[i] + iM2;

        int skip = iM1;

        int curr = max(pick, skip);
        iM2 = iM1;
        iM1 = curr;
    }
    int rob0 = iM1;

    iM1 = nums[1];
    iM2 = 0;

    for (int i = 1; i < nums.size(); i++)
    {
        if (i == 1)
        {
            continue;
        }
        int pick = nums[i] + iM2;

        int skip = iM1;

        int curr = max(pick, skip);
        iM2 = iM1;
        iM1 = curr;
    }

    cout << max(rob0, iM1);

    return 0;
}