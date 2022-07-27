package main

func twoSum(nums []int, target int) []int {
	// var hash_map map[int]int
	hash_map := make(map[int]int)
	var answer [2]int
	var tmp_bool bool

	for i, v := range nums {
		var diff = target - v
		_, tmp_bool = hash_map[diff]
		if tmp_bool {
			answer[0] = hash_map[diff]
			answer[1] = i
			return answer[:]
		}
		hash_map[v] = i
	}
	return answer[:]
}
