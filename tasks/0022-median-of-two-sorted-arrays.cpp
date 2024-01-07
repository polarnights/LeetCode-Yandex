#include <iostream>
#include <vector>

using namespace std;

const int IMPOSSIBLE = 1e6 + 1;

class Solution {
  public:
    int binarySearch(vector<int> &nums, int start, int end, int target) {
        if (end - start <= 1) {
            cout << "BINSEARCH | ENDED with end = " << end
                 << " | start = " << start << "(<--- returning this)\n";
            if (start == 0 && nums[0] > target) {
                return -1;
            }
            /*
            if (start != nums.size() - 1 && nums[end] == target) {
                cout << "ISSUE HERE: " << nums[start]
                     << " start_value <- (?) -> end_value " << nums[end]
                     << "\n";
                cout << "ISSUE HERE: " << start << " start <- (?) -> end "
                     << end << "\n";
                // return end;
            }
            */

            return start;
        }
        int mid = (start + end) / 2;
        if (nums[mid] >= target) {
            cout << "BINSEARCH | current = [" << start << ";" << mid << ")\n";
            return binarySearch(nums, start, mid, target);
        } else {
            // could have issues with multiple elements == mid
            cout << "BINSEARCH | current = [" << mid << ";" << end << ")\n";
            return binarySearch(nums, mid, end, target);
        }
    }

    int binarySearch2(vector<int> &nums, int start, int end, int target) {
        if (end - start <= 1) {
            cout << "BINSEARCH2 | ENDED with end = " << end
                 << " | start = " << start << "(<--- returning this)\n";
            if (start == 0 && nums[0] > target) {
                return -1;
            }
            return start;
        }
        int mid = (start + end) / 2;
        if (nums[mid] > target) {
            cout << "BINSEARCH2 | current = [" << start << ";" << mid << ")\n";
            return binarySearch2(nums, start, mid, target);
        } else {
            // could have issues with multiple elements == mid
            cout << "BINSEARCH2 | current = [" << mid << ";" << end << ")\n";
            return binarySearch2(nums, mid, end, target);
        }
    }

    // for cases when sum(sizes) % 2 == 0 and two elements are in the same array
    // OR when one array is empty
    double helper_solo(vector<int> &nums) {
        auto mid = nums.size() / 2;
        if (nums.size() % 2 == 0) {
            return (double(nums[mid - 1]) + double(nums[mid])) / 2;
        } else {
            return nums[mid];
        }
    }

    double helper(vector<int> &nums1, vector<int> &nums2) {
        cout << "DEBUG| helper STARTED\n";
        // Max possible elem is 10^6
        int start1 = 0;
        int end1 = nums1.size();
        int start2 = 0;
        int end2 = nums2.size();
        int goal = (end1 + end2) / 2 + 1;       // second elem OR single elem
        bool flag = ((end1 + end2) % 2 == 1);   // one number or pair flag
        int mid = -1;

        // The median is an element of one of the arrays
        while (mid != start2) {
            cout << "CONDITION | end2 = " << end2 << ", start2 = " << start2
                 << "\n";
            mid = (end2 + start2) / 2;
            cout << "CONDITION | MID = " << mid << "\n";
            auto target = nums2[mid];
            cout << "CHECK TARGET: " << target << "\n";
            auto idx_first = binarySearch(nums1, start1, end1, target);
            auto idx_first2 = binarySearch2(nums1, start1, end1, target);
            if (idx_first == -1) {
                cout << "LOOK HERE!\n";
                cout << "mid + 1 =(?) goal " << mid + 1 << " =?= " << goal
                     << "\n";
                if (mid + 1 == goal) {
                    if (flag) {
                        return nums2[mid];
                    } else {
                        return (double(nums2[mid - 1]) + double(nums2[mid])) /
                               2;
                    }
                } else if (mid + 1 > goal) {
                    end2 = mid;
                    // mid = (start2 + end2) / 2;
                    continue;
                } else {
                    start2 = mid;
                    mid = (start2 + end2) / 2;
                    continue;
                }
            }
            cout << "DEBUG | for element nums2[" << mid << "] = " << nums2[mid]
                 << " binary search found nums1[" << idx_first
                 << "] = " << nums1[idx_first]
                 << " OTHER binary search found nums1[" << idx_first2
                 << "] = " << nums1[idx_first2] << "\n";
            cout << "DEBUG | idx_first =" << idx_first << " + mid = " << mid
                 << "+ 2 =(?)= goal = " << goal << "\n";
            /*
            if (nums1[idx_first] > target) {
                cout << "DEBUG | (IF!) idx_first =" << idx_first
                     << " and value = " << nums1[idx_first]
                     << "while target = " << target << "\n";
                start2 = mid;

                // continue;
                cout << "ENDING THIS BS\n";
                return IMPOSSIBLE;
            }
            */
            if (idx_first != idx_first2) {
                cout << "ATTENTION! idx1, idx2 = " << idx_first << ", "
                     << idx_first2 << "\n";
                if ((idx_first + mid) + 2 <= goal &&
                    (idx_first2 + mid) + 2 >= goal) {
                    auto FINAL_IDX = goal - mid - 2;
                    if (flag) {
                        cout << "DEBUG | flag = True!\n";
                        // The median is an element of one of the arrays
                        return double(nums2[mid]);
                    } else {
                        cout << "DEBUG | flag = False!\n";
                        if (mid == 0 || nums2[mid - 1] <= nums1[FINAL_IDX]) {
                            return (double(nums2[mid]) +
                                    double(nums1[FINAL_IDX])) /
                                   2;
                        } else {
                            return (double(nums2[mid]) +
                                    double(nums2[mid - 1])) /
                                   2;
                        }
                        // The median is the half of the sum of two array
                        // elements
                    }
                } else if ((idx_first2 + mid) + 2 > goal) {
                    end2 = mid;
                } else {
                    start2 = mid;
                }
            }
            if ((idx_first + mid) + 2 == goal) {
                if (flag) {
                    cout << "DEBUG | flag = True!\n";
                    // The median is an element of one of the arrays
                    return double(nums2[mid]);
                } else {
                    cout << "DEBUG | flag = False!\n";
                    if (mid == 0 || nums2[mid - 1] < nums1[idx_first]) {
                        return (double(nums2[mid]) + double(nums1[idx_first])) /
                               2;
                    } else {
                        return (double(nums2[mid]) + double(nums2[mid - 1])) /
                               2;
                    }
                    // The median is the half of the sum of two array elements
                }
            } else if ((idx_first + mid) + 2 > goal) {
                end2 = mid;
            } else {
                start2 = mid;
                mid = (start2 + end2) / 2;
            }
            cout << "-------------------\n";
        }
        cout << "DEBUG| helper ENDED!\n";
        return IMPOSSIBLE;
    }
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2) {
        // according to the task vectors can't be empty simultaneously
        if (nums1.size() == 0) {
            return helper_solo(nums2);
        }
        if (nums2.size() == 0) {
            return helper_solo(nums1);
        }
        // [start; end)
        auto result = helper(nums1, nums2);
        if (result == IMPOSSIBLE) {
            cout << "First result nums1 -> nums2 == IMPOSSIBLE\n";
            return helper(nums2, nums1);
        } else {
            return result;
        }
    }
};

int
main() {
    vector<int> nums1 = {1, 3, 4};
    vector<int> nums2 = {2, 5, 6};
    Solution solution;
    cout << solution.findMedianSortedArrays(nums1, nums2) << "\n";
}

// Worst solution ever :)
// Memory O(1)
// Runtime O(log(n) * log(m))