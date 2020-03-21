/*
 * @Author: haha_giraffe
 * @Date: 2020-02-28 20:46:04
 * @Description: 输入整数数组 arr ，找出其中最小的 k 个数。例如，输入4、5、1、6、2、7、3、8这8个数字，则最小的4个数字是1、2、3、4。
 */

/* 
    解题方法：最小的k个数，一开始想到的就是堆排，用大根堆
*/
class Solution {
public:
    vector<int> getLeastNumbers(vector<int>& arr, int k) {
        if(arr.empty() || k == 0){
            return {};
        }
        priority_queue<int> pq(arr.begin(), arr.begin() + k);
        for(int i = k; i < arr.size(); ++i){
            if(arr[i] < pq.top()){
                pq.push(arr[i]);
                pq.pop();
            }
        }
        vector<int> res;
        while(!pq.empty()){
            int tmp = pq.top();
            pq.pop();
            res.push_back(tmp);
        }
        return res;
    }
};

/* 
    解题方法：partition，快排的思路
*/
class Solution {
public:
    int partition(vector<int>& arr, int left, int right){
        int target = arr[left];
        
        while(left < right){
            while(left < right && arr[right] >= target){
                right--;
            }
            swap(arr[right], arr[left]);
            while(left < right && arr[left] <= target){
                left++;
            }
            swap(arr[right], arr[left]);
        }
        return left;
    }
    
    vector<int> getLeastNumbers(vector<int>& arr, int k) {
        if(arr.empty() || k == 0){
            return {};
        }
        int n = arr.size();
        int l = 0, r = n-1;
        int tmp = partition(arr, l, r);
        while(tmp != k - 1){
            if(tmp > k - 1){
                r = tmp - 1;
                tmp = partition(arr, l, r);
            } else{
                l = tmp + 1;
                tmp = partition(arr, l , r);
            }
        }
        return vector<int> (arr.begin(), arr.begin() + k);
    }
};