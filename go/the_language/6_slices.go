package main

import "fmt"

// Slices are like arrays but have a minimum and a maximum size
// A slice is a REFERENCE to an array
// It just holds a pointer, length, and capacity
func main() {
	/* Define an array containing programming languages */
	languages := [9]string{
		"C", "Lisp", "C++", "Java", "Python",
		"JavaScript", "Ruby", "Go", "Rust", // Must include the trailing comma
	}

	/* Define slices */
	classics := languages[0:3]  // alternatively languages[:3]
	modern := make([]string, 4) // len(modern) = 4
	modern = languages[3:7]     // include 3 exclude 7
	new := languages[7:9]       // alternatively languages[7:] (excludes Rust)

	fmt.Printf("classic languagues: %v\n", classics) // classic languagues: [C Lisp C++]
	fmt.Printf("modern languages: %v\n", modern)     // modern languages: [Java Python JavaScript Ruby]
	fmt.Printf("new languages: %v\n", new)           // new languages: [Go Rust]

}

func uniqproperties() {
	/* An example of unique slice properties to unique properties */
	arr := [...]string{"Golang", "seems", "to", "be", "a", "great", "language"}
	fmt.Println("Array: ", arr)
	// Creating a slice
	myslice := arr[1:6]

	// Display slice
	fmt.Println("Slice:", myslice)

	// Display length of the slice
	fmt.Printf("Length of the slice: %d", len(myslice)) // 5

	// Display the capacity of the slice
	fmt.Printf("\nCapacity of the slice: %d", cap(myslice)) // 6
}

func sliceliteral() {
	// Creating a slice literaly
	var my_slice_1 = []string{"Geeks", "for", "Geeks"}

	fmt.Println("My Slice 1:", my_slice_1)

	my_slice_2 := []int{12, 45, 67, 56, 43, 34, 45}
	fmt.Println("My Slice 2:", my_slice_2)
}
