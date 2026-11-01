#include <iostream>
#include <vector>
#include <utility>
using namespace std;

class ArrayOperations {
public:
    int removeDuplicatesReference(vector<int>& nums) {
        if (nums.empty()) return 0;

        vector<int> result;

        for (int num : nums) {
            bool exists = false;

            for (int resNum : result) {
                if (num == resNum) {
                    exists = true;
                    break;
                }
            }

            if (!exists) {
                result.push_back(num);
            }
        }

        for (int i = 0; i < result.size(); i++) {
            nums[i] = result[i];
        }

        return result.size();
    }

    int removeDuplicatesOptimized(vector<int>& nums) {
        if (nums.empty()) return 0;

        int slow = 0;

        for (int fast = 1; fast < nums.size(); fast++) {
            if (nums[fast] != nums[slow]) {
                slow++;
                nums[slow] = nums[fast];
            }
        }

        return slow + 1;
    }

    pair<int, int> pairSumBruteForce(const vector<int>& nums, int target) {
        int n = nums.size();

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (nums[i] + nums[j] == target) {
                    return {i, j};
                }
            }
        }

        return {-1, -1};
    }

    pair<int, int> pairSumOptimized(const vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;

        while (left < right) {
            int currentSum = nums[left] + nums[right];

            if (currentSum == target) {
                return {left, right};
            } else if (currentSum < target) {
                left++;
            } else {
                right--;
            }
        }

        return {-1, -1};
    }

    void printArray(const vector<int>& nums, int k) {
        cout << "[";

        for (int i = 0; i < k; i++) {
            cout << nums[i];

            if (i < k - 1) {
                cout << ", ";
            }
        }

        cout << "]";
    }
};

int main() {
    ArrayOperations obj;

    vector<vector<int>> dupTests = {
        {1, 1, 2, 2, 2, 3, 4, 4},
        {5},
        {},
        {-3, -3, -1, 0, 0}
    };

    cout << "PART A: REMOVE DUPLICATES\n";

    for (int t = 0; t < dupTests.size(); t++) {
        vector<int> arrRef = dupTests[t];
        vector<int> arrOpt = dupTests[t];

        int kRef = obj.removeDuplicatesReference(arrRef);
        int kOpt = obj.removeDuplicatesOptimized(arrOpt);

        cout << "\nTest Case " << t + 1 << " Input: ";
        obj.printArray(dupTests[t], dupTests[t].size());

        cout << "\nReference k = " << kRef << ", Prefix: ";
        obj.printArray(arrRef, kRef);

        cout << "\nOptimized k = " << kOpt << ", Prefix: ";
        obj.printArray(arrOpt, kOpt);

        cout << "\n";
    }

    vector<pair<vector<int>, int>> pairTests = {
        {{1, 2, 4, 7, 11, 15}, 15},
        {{1, 3, 5, 8}, 7},
        {{2, 4, 6}, 20},
        {{1, 2, 2, 3}, 4}
    };

    cout << "\nPART B: PAIR SUM\n";

    for (int t = 0; t < pairTests.size(); t++) {
        auto arr = pairTests[t].first;
        int target = pairTests[t].second;

        auto resBF = obj.pairSumBruteForce(arr, target);
        auto resOpt = obj.pairSumOptimized(arr, target);

        cout << "\nTest Case " << t + 1 << " Input: ";
        obj.printArray(arr, arr.size());

        cout << ", Target = " << target;

        cout << "\nBrute Force Indices: ("
             << resBF.first << ", " << resBF.second << ")";

        cout << "\nOptimized Indices: ("
             << resOpt.first << ", " << resOpt.second << ")\n";
    }

    return 0;
}
