package main

import "fmt"

func findArrayFromPrefix(pref []int) []int {
	n := len(pref)
	arr := make([]int, n)

	for i := 0; i < n; i++ {
		if i == 0 {
			// The first element of arr can be any value, so we set it to pref[0].
			arr[i] = pref[i]
		} else {
			// To find arr[i], we XOR pref[i] with arr[0] ^ arr[1] ^ ... ^ arr[i-1].
			arr[i] = pref[i] ^ arr[i-1]
		}
	}

	return arr
}

func main() {
	pref := []int{1, 3, 2, 6}
	arr := findArrayFromPrefix(pref)
	fmt.Println(arr)
}
