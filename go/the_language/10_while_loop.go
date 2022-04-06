package main

import "fmt"

func main() {
	count := 1

	// While keyword doesn't exist in go
	for count < 5 {
		count += count
	}
	fmt.Println(count) // 8
}
