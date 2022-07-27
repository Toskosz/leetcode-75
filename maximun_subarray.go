package main

func maxSubArray(nums []int) int {
	var sumNow, sumMax int = 0, nums[0]

	for _, v := range nums {
		if sumNow < 0 {
			sumNow = 0
		}
		sumNow = sumNow + v
		if sumNow > sumMax {
			sumMax = sumNow
		}
	}
	return sumMax
}
