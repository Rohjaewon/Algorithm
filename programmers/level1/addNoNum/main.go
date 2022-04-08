package main

func solution(numbers []int) int {
	sum := 0
	for _, num := range numbers {
		sum += num
	}
	return 45 - sum
}
