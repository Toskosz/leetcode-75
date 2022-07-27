package main

func maxProfit(prices []int) int {
	var p1, p2, max int = 0, 1, 0

	for p2 < len(prices) {
		// New low
		if p2 < p1 {
			p1 = p2
		} else {
			// Checks if new profitable operation is the most profitable one
			actualProfit := prices[p2] - prices[p1]
			if actualProfit > max {
				max = actualProfit
			}
		}
		// next day
		p2 = p2 + 1
	}
	return max
}
