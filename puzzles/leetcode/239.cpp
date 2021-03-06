//sliding window max: https://leetcode.com/problems/sliding-window-maximum/
/*********************************************************************************
Given an array nums, there is a sliding window of size k which is moving from the very left of the array to the very right. You can only see the k numbers in the window. Each time the sliding window moves right by one position.

For example,
Given nums = [1,3,-1,-3,5,3,6,7], and k = 3.
Window position                Max
---------------               -----
[1  3  -1] -3  5  3  6  7       3
1 [3  -1  -3] 5  3  6  7       3
1  3 [-1  -3  5] 3  6  7       5
1  3  -1 [-3  5  3] 6  7       5
1  3  -1  -3 [5  3  6] 7       6
1  3  -1  -3  5 [3  6  7]      7


Therefore, return the max sliding window as [3,3,5,5,6,7].
*********************************************************************************/

//time complexity: O(NK)
//N is the num of input array nums
vector<int> maxSlidingWindow(vector<int>& nums, int k) {
	vector<int> res;
	res.clear();

	if(nums.size() <= 0)
		return res;

	for(int i=0; i<nums.size()-k+1; i++){
		int max=nums[i];
		for(int j=i+1; j<i+k; j++){
			if(nums[j] > max)
				max = nums[j];
		}
		res.push_back(max);
	}

	return res;
}

//time complexity: O(n): every element can inqueue and dequeue one time at most
//space complexity: O(k)
vector<int> maxSlidingWindow(vector<int>& nums, int k) {
	deque<int> q;
        vector<int> ret;
        q.clear();
        ret.clear();
        
        if (nums.size() <= 0) {
            return ret;
        }
        
        for (int i = 0; i < k; i++) {
            while (!q.empty() && nums[q.back()] <= nums[i]) {
                q.pop_back();
            }
            q.push_back(i);
        }
        ret.push_back(nums[q.front()]);
        
        for (int i = k; i < nums.size(); i++) {
            if (q.front() + k == i) {
                q.pop_front();
            }
            while (!q.empty() && nums[q.back()] <= nums[i]) {
                q.pop_back();
            }
            q.push_back(i);

            ret.push_back(nums[q.front()]);
        }
        
        return ret;
}
