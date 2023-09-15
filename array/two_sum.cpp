#include<bits/stdc++.h>
using namespace std;
int max(vector<int> &v ){
            int m=v[0];
            for (auto i = v.begin(); i!=v.end(); i++)
            {
                if (m<*i)m=*i;
            }
            return m;
            
        }
class Solution {
public:
// {2,7,11,15};


        
    int []  twoSum(vector<int>& nums, int target) {
        int length=max(nums);
        int resultno[2];
        vector<int> v1(length,0);
        for (int i =0; i<length; i++)
            {
                if(v1[target-nums[i]]==1){
                    cout << nums[i]<<"+"<<target-nums[i]<<"="<<target << endl;
                    resultno[0]=nums[i];
                    return new int[]{nums[i],target-nums[i]};
                }
                else
                v1[nums[i]]++;
            }
            
            }

};
        
int main(){
    vector<int> v1 = {2,7,11,15};
    Solution s1;
    s1.twoSum(v1,9);
    int maximum=max(v1);

    return 0;
}