func smallestSufficientTeam(reqSkills []string, people [][]string) []int {
    n := len(people)
    m := len(reqSkills)
    skillID := make(map[string]int)
    for i, skill := range reqSkills {
        skillID[skill] = i
    }
    skillsMaskOfPerson := make([]int, n)
    for i := 0; i < n; i++ {
        for _, skill := range people[i] {
            skillsMaskOfPerson[i] |= 1 << skillID[skill]
        }
    }
    dp := make([]int, 1<<m)
    for i := 0; i < len(dp); i++ {
        dp[i] = -1
    }
    dp[0] = 0

    var f func(int) int
    f = func(skillsMask int) int {
        if dp[skillsMask] != -1 {
            return dp[skillsMask]
        }
        for i := 0; i < n; i++ {
            newSkillsMask := skillsMask & ^skillsMaskOfPerson[i]
            if newSkillsMask != skillsMask {
                peopleMask := f(newSkillsMask) | (1 << i)
                if dp[skillsMask] == -1 || bitCount(peopleMask) < bitCount(dp[skillsMask]) {
                    dp[skillsMask] = peopleMask
                }
            }
        }
        return dp[skillsMask]
    }

    answerMask := f((1 << m) - 1)
    var ans []int
    for i := 0; i < n; i++ {
        if (answerMask >> i) & 1 == 1 {
            ans = append(ans, i)
        }
    }
    return ans
}

func bitCount(n int) int {
    count := 0
    for n != 0 {
        n &= n - 1
        count++
    }
    return count
}
