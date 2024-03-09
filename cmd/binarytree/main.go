package main

import "fmt"

var tree BinaryTree

func main() {

	tree.Insert(7)
	tree.Insert(6)
	tree.Insert(3)
	tree.Insert(4)
	tree.Insert(5)
	tree.Insert(2)
	tree.Insert(1)
	tree.Insert(8)
	tree.Insert(9)

	tree.Dump()

	tree.Delete(4)
	fmt.Println("------------------------")
	tree.Dump()

	tree.Delete(6)
	fmt.Println("------------------------")
	tree.Dump()

	tree.Delete(8)
	fmt.Println("------------------------")
	tree.Dump()
}
