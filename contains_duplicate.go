package main

func containsDuplicate(nums []int) bool {
	hash_map := make(map[int]int)

	for _, value := range nums {
		_, exists := hash_map[value]
		if exists {
			return true
		} else {
			hash_map[value] = 1
		}
	}
	return false
}
