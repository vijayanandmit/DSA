func solution(obstacles []int) int {
	maxCoordinate := 0

	// Find the maximum coordinate in the obstacles array
	for _, obstacle := range obstacles {
		if obstacle > maxCoordinate {
			maxCoordinate = obstacle
		}
	}

	// Find the minimal Jump length by checking each possible length
	for j := 1; j <= maxCoordinate+1; j++ {
		jumpSuccessful := true

		// Check if the jump length is enough to avoid all obstacles
		for _, obstacle := range obstacles {
			if obstacle%j == 0 {
				jumpSuccessful = false
				break
			}
		}

		// If the jump length is enough, return it
		if jumpSuccessful {
			return j
		}
	}

	// If no suitable jump length is found, return 0
	return 0

}
