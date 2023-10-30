package main

import (
	"fmt"
	"sync"
	"time"
)

type ChopS struct{ sync.Mutex }

type Philo struct {
	leftCS, rightCS *ChopS
	number          int
	eatCount        int
}

func (p Philo) eat(wg *sync.WaitGroup, host chan int) {
	for p.eatCount < 3 {
		host <- p.number // get permission from host
		p.leftCS.Lock()
		p.rightCS.Lock()

		fmt.Printf("starting to eat %d\n", p.number)
		time.Sleep(time.Second) // simulate eating
		fmt.Printf("finishing eating %d\n", p.number)

		p.rightCS.Unlock()
		p.leftCS.Unlock()

		p.eatCount++
		<-host // release permission from host
	}
	wg.Done()
}

func main() {
	CSticks := make([]*ChopS, 5)
	for i := 0; i < 5; i++ {
		CSticks[i] = new(ChopS)
	}

	philos := make([]*Philo, 5)
	for i := 0; i < 5; i++ {
		philos[i] = &Philo{CSticks[i], CSticks[(i+1)%5], i + 1, 0}
	}

	host := make(chan int, 2) // host allows 2 philosophers to eat concurrently
	var wg sync.WaitGroup
	for i := 0; i < 5; i++ {
		wg.Add(1)
		go philos[i].eat(&wg, host)
	}
	wg.Wait()
}

/*
In this implementation, we have defined two types: ChopS (chopstick) and Philo 
(philosopher). The ChopS type has a mutex that the philosophers use to acquire 
and release the chopsticks. The Philo type has pointers to its left and right 
chopsticks, as well as its number and the number of times it has eaten.

The eat method of the Philo type represents the philosopher's eating behavior. 
It tries to get permission from the host channel, then acquires the left and 
right chopsticks, simulates eating for one second, releases the chopsticks, and 
releases permission from the host channel. The philosopher eats three times 
before finishing.

In the main function, we create five chopsticks and five philosophers. The 
philosophers share the chopsticks in a circular manner, with philosopher i 
holding chopsticks i and (i+1)%5. We also create a host channel with a capacity 
of 2, representing the two philosophers that can eat concurrently. Finally, we 
start the eat method of each philosopher in its own goroutine and wait for them 
to finish using a sync.WaitGroup.
*/
