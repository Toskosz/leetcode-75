package main

func productExceptSelf(nums []int) []int {
	var prefix, posfix int = 1, 1
	var res = make([]int, len(nums))

	for i, v := range nums {
		res[i] = prefix
		prefix = prefix * v
	}
	for i := len(nums) - 1; i >= 0; i-- {
		res[i] = res[i] * posfix
		posfix = posfix * nums[i]
	}
	return res
}
