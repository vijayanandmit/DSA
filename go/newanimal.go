package main

import (
    "bufio"
    "fmt"
    "os"
    "strings"
)

type Animal interface {
    Eat()
    Move()
    Speak()
}

type Cow struct{}

func (c Cow) Eat() {
    fmt.Println("grass")
}

func (c Cow) Move() {
    fmt.Println("walk")
}

func (c Cow) Speak() {
    fmt.Println("moo")
}

type Bird struct{}

func (b Bird) Eat() {
    fmt.Println("worms")
}

func (b Bird) Move() {
    fmt.Println("fly")
}

func (b Bird) Speak() {
    fmt.Println("peep")
}

type Snake struct{}

func (s Snake) Eat() {
    fmt.Println("mice")
}

func (s Snake) Move() {
    fmt.Println("slither")
}

func (s Snake) Speak() {
    fmt.Println("hsss")
}

func main() {
    animals := make(map[string]Animal)
    scanner := bufio.NewScanner(os.Stdin)
    for {
        fmt.Print("> ")
        scanner.Scan()
        input := scanner.Text()
        parts := strings.Split(input, " ")
        if len(parts) != 3 {
            fmt.Println("Invalid input")
            continue
        }
        command := parts[0]
        animalName := parts[1]
        animalType := parts[2]
        switch command {
        case "newanimal":
            var animal Animal
            switch animalType {
            case "cow":
                animal = Cow{}
            case "bird":
                animal = Bird{}
            case "snake":
                animal = Snake{}
            default:
                fmt.Println("Invalid animal type")
                continue
            }
            animals[animalName] = animal
            fmt.Println("Created it!")
        case "query":
            animal, ok := animals[animalName]
            if !ok {
                fmt.Println("Animal not found")
                continue
            }
            switch parts[2] {
            case "eat":
                animal.Eat()
            case "move":
                animal.Move()
            case "speak":
                animal.Speak()
            default:
                fmt.Println("Invalid query")
                continue
            }
        default:
            fmt.Println("Invalid command")
            continue
        }
    }
}
