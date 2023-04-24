package main

import (
	"fmt"
	"sort"
	"strconv"
	"strings"
	"sync"
	"bufio"
	"os"
)

func main() {
		// Prompt the user to input a series of integers
	fmt.Print("Enter integers separated by spaces: ")
	reader := bufio.NewReader(os.Stdin)
	input, _ := reader.ReadString('\n')

	// Split the input string into an array of integers
	var arr []int
	for _, val := range strings.FieldsFunc(input, func(r rune) bool {
		return r == ' ' || r == '\t' || r == '\n' || 
r == '\r'
	}) {
		num, err := strconv.Atoi(val)
		if err != nil {
			panic("Invalid input")
		}
		arr = append(arr, num)
	}

	// Divide the array into four equal parts
	n := len(arr)
	partSize := n / 4
	if n<5 {
		partSize = 1
	} else if n<10 {
		partSize = 2
	} else if n<15 {
		partSize = 3
	}
	part1 := arr[:partSize]
	part2 := arr[partSize : 2*partSize]
	part3 := arr[2*partSize : 3*partSize]
	part4 := arr[3*partSize:]

	// Print the subarrays that each goroutine will sort
	fmt.Println("Sorting subarrays...")
	fmt.Println("Part 1:", part1)
	fmt.Println("Part 2:", part2)
	fmt.Println("Part 3:", part3)
	fmt.Println("Part 4:", part4)

	// Sort each partition in a separate goroutine
	var wg sync.WaitGroup
	wg.Add(4)

	go func() {
		defer wg.Done()
		sort.Ints(part1)
	}()

	go func() {
		defer wg.Done()
		sort.Ints(part2)
	}()

	go func() {
		defer wg.Done()
		sort.Ints(part3)
	}()

	go func() {
		defer wg.Done()
		sort.Ints(part4)
	}()

	wg.Wait()

	// Merge the four sorted partitions into one large sorted array
	result := make([]int, n)
	copy(result[:partSize], part1)
	copy(result[partSize:2*partSize], part2)
	copy(result[2*partSize:3*partSize], part3)
	copy(result[3*partSize:], part4)
	sort.Ints(result)

	// Print the sorted array
	fmt.Println("Sorted array:", result)
}

