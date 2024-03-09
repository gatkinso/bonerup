package main

import (
	"fmt"
	"log"
	"strings"
)

type Node struct {
	Left   *Node
	Value  int
	Right  *Node
	height int
}

func createNode(val int) *Node {
	n := new(Node)
	n.Left = nil
	n.Right = nil
	n.Value = val
	n.height = 1

	return n
}

func (n *Node) Height() int {
	if nil == n {
		return 0
	}

	return n.height
}

func (n *Node) Bal() int {
	return n.Right.Height() - n.Left.Height()
}

func (n *Node) Insert(val int) *Node {
	if n == nil {
		n = createNode(val)
		return n
	}

	if val < n.Value {
		n.Left = n.Left.Insert(val)
	} else if val > n.Value {
		n.Right = n.Right.Insert(val)
	} else {
		return n
	}

	n.height = max(n.Left.Height(), n.Right.Height()) + 1

	return n.rebalance()
}

func (n *Node) Preorder() error {
	if n != nil {
		n.Left.Preorder()
		n.Right.Preorder()
		log.Printf("preNode value: %d\n", n.Value)
	}
	return nil
}

func (n *Node) Inorder() error {
	if n != nil {
		n.Left.Inorder()
		log.Printf("inNode value: %d\n", n.Value)
		n.Right.Inorder()
	}
	return nil
}

func (n *Node) Postorder() error {
	if n != nil {
		log.Printf("postNode value: %d\n", n.Value)
		n.Left.Postorder()
		n.Right.Postorder()
	}
	return nil
}

func (n *Node) Find(val int) (*Node, bool) {
	if n == nil {
		return nil, false
	}

	switch {
	case val < n.Value:
		return n.Left.Find(val)
	case val > n.Value:
		return n.Right.Find(val)
	default:
		return n, true
	}
}

func (n *Node) ioSuccessor() int {
	min := n.Value
	for n.Left != nil {
		min = n.Left.Value
		n = n.Left
	}
	return min
}

func (n *Node) Delete(val int) *Node {
	if val < n.Value {
		n.Left = n.Left.Delete(val)
	} else if val > n.Value {
		n.Right = n.Right.Delete(val)
	} else {
		if n.Left == nil {
			return n.Right
		} else if n.Right == nil {
			return n.Left
		}

		n.Value = n.Right.ioSuccessor()
		n.Right = n.Right.Delete(n.Value)
	}

	return n
}

func (n *Node) rotateL() *Node {
	r := n.Right

	n.Right = r.Left
	r.Left = n

	n.height = max(n.Left.Height(), n.Right.Height()) + 1
	r.height = max(r.Left.Height(), r.Right.Height()) + 1

	return r
}

func (n *Node) rotateR() *Node {
	l := n.Left

	n.Left = l.Right
	l.Right = n

	n.height = max(n.Left.Height(), n.Right.Height()) + 1
	l.height = max(l.Left.Height(), l.Right.Height()) + 1

	return l
}

func (n *Node) rotateRL() *Node {
	n.Right = n.Right.rotateR()
	n = n.rotateL()
	n.height = max(n.Left.Height(), n.Right.Height()) + 1

	return n
}

func (n *Node) rotateLR() *Node {
	n.Left = n.Left.rotateL()
	n = n.rotateR()
	n.height = max(n.Left.Height(), n.Right.Height()) + 1

	return n
}

func (n *Node) rebalance() *Node {
	switch {
	case n.Bal() < -1 && n.Left.Bal() == -1:
		return n.rotateR()
	case n.Bal() > 1 && n.Right.Bal() == 1:
		return n.rotateL()
	case n.Bal() < -1 && n.Left.Bal() == 1:
		return n.rotateLR()
	case n.Bal() > 1 && n.Right.Bal() == -1:
		return n.rotateRL()
	}

	return n
}

func (n *Node) Dump(i int, lr string) {
	if n == nil {
		return
	}
	indent := ""
	if i > 0 {
		indent = strings.Repeat(" ", (i-1)*4) + "+" + lr + "--"
	}

	fmt.Printf("%s%d[%d,%d]\n", indent, n.Value, n.Bal(), n.Height())
	n.Left.Dump(i+1, "L")
	n.Right.Dump(i+1, "R")
}
