package main

import (
	"fmt"
	"log"
	"strings"
)

type BinaryTree struct {
	Root *Node
}

func (t *BinaryTree) rebalance() {
	if t == nil || t.Root == nil {
		return
	}
	t.Root = t.Root.rebalance()
}

func (t *BinaryTree) Insert(val int) {
	t.Root = t.Root.Insert(val)

	if t.Root.Bal() < -1 || t.Root.Bal() > 1 {
		t.rebalance()
	}
}

func (t *BinaryTree) Delete(val int) {
	t.Root = t.Root.Delete(val)
}

func (t *BinaryTree) Find(val int) (*Node, bool) {
	if t.Root == nil {
		return nil, false
	}
	return t.Root.Find(val)
}

func (t *BinaryTree) Preorder() error {
	if t.Root == nil {
		log.Printf("Tree is empty!\n")
		return nil
	}

	log.Printf("Preorder traversal Root: %d\n", t.Root.Value)

	return t.Root.Preorder()
}

func (t *BinaryTree) Inorder() error {
	if t.Root == nil {
		log.Printf("Tree is empty!\n")
		return nil
	}
	log.Printf("Inorder traversal Root: %d\n", t.Root.Value)
	return t.Root.Inorder()
}

func (t *BinaryTree) Postorder() error {
	if t.Root == nil {
		log.Printf("Tree is empty!\n")
		return nil
	}
	log.Printf("Postorder traversal Root: %d\n", t.Root.Value)

	return t.Root.Postorder()
}

func (t *BinaryTree) Dump() {
	if t == nil {
		return
	}

	t.Root.Dump(0, "")
}

func (t *BinaryTree) PrettyPrint() {

	printNode := func(n *Node, depth int) {
		fmt.Printf("%s%d\n", strings.Repeat("  ", depth), n.Value)
	}

	var walk func(*Node, int)
	walk = func(n *Node, depth int) {
		if n == nil {
			return
		}
		walk(n.Right, depth+1)
		printNode(n, depth)
		walk(n.Left, depth+1)
	}

	walk(t.Root, 0)
}
