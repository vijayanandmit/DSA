package main

import (
	"fmt"
	"time"
)

var counter int
func increment() {
	for i := 0; i < 1000; i++ {
		counter++
	}
}

func main() {
	go increment()
	go increment()
	time.Sleep(time.Second)
	fmt.Println(counter)
}
/*
This program has two goroutines (increment) which increment 
the counter variable by 1,000 times each. The main function 
starts these goroutines and then waits for a second before 
printing the value of the counter variable.

The race condition in this program occurs because both 
goroutines access and modify the counter variable 
concurrently without any synchronization. As a result, the 
order in which the two goroutines access the counter 
variable is undefined and can lead to unexpected results.

For example, when running this program, the output value of 
counter may vary between different executions. This is 
because the increment goroutines may overwrite each other's 
changes to the counter variable, leading to lost updates and 
a final counter value that is less than expected.

To avoid the race condition, we can use synchronization 
mechanisms like mutexes or channels to ensure that only one 
goroutine modifies the counter variable at a time.
 */

