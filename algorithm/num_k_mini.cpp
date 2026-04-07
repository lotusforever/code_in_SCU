#include <iostream>
#include <vector>
using namespace std;

int huafen(vector<int>& nums, int l, int r) {
	int p = nums[l];
	int i = l, j = r;
	while (i < j) {
		// 从右找比基准小的
		while (i < j && nums[j] >= p) j--;
		nums[i] = nums[j];
		// 从左找比基准大的
		while (i < j && nums[i] <= p) i++;
		nums[j] = nums[i];
	}
	nums[i] = p;
	return i;
}

// 递归找第k小，快排思想
int quickSelect(vector<int>& nums, int l, int r, int k) {
	int pos = huafen(nums, l, r);
	if (k == pos) {
		return nums[pos];
	} else if (k < pos) {
		return quickSelect(nums, l, pos - 1, k);
	} else {
		return quickSelect(nums, pos + 1, r, k);
	}
}

int main() {
	int n, k;
	cin >> n >> k;
	vector<int> nums(n);
	for (int i = 0; i < n; i++) {
		cin >> nums[i];
	}
	cout << quickSelect(nums, 0, n - 1, k) << endl;
	return 0;
}
