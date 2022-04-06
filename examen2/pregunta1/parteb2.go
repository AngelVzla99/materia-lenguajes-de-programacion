package main

import "fmt"

func max(x int, y int) int {
 if x > y {
   return x
 }
 return y
}

func min(x int, y int) int {
 if x < y {
   return x
 }
 return y
}

type Node struct {
	val int
	L *Node
	R *Node
}

func getLeaf(a int) *Node{
	return &Node{
		val: a,
		L : nil,
		R : nil,
	}
}

func isLeaf( n *Node ) bool{
	return n.L==nil && n.R==nil
}

type checkNode struct {
	valid bool
	maxVal int
	maxDeph int
	minDeph int
}

func check(n *Node) checkNode{
	var ans checkNode = checkNode{
		valid : true,
		maxVal : n.val,
	}
	
	if isLeaf(n){
		ans.maxDeph = 0
		ans.minDeph = 0
	}else if (n.L==nil && n.R!=nil) || (n.L!=nil && n.R==nil){
		var temp checkNode 
		if n.R!=nil{
			temp = check(n.R) 
		}else{
			temp = check(n.L) 
		}
		
		ans.valid = temp.valid
		ans.maxDeph = 1 + temp.maxDeph
		ans.minDeph = 1 + temp.minDeph
		ans.valid = ans.valid && (ans.maxVal <= temp.maxVal)
		ans.valid = ans.valid && (ans.maxDeph-ans.minDeph<=1)
		ans.maxVal = max( ans.maxVal, temp.maxVal )
	}else{
		var tempL checkNode = check(n.L)
		var tempR checkNode = check(n.R)
		
		ans.valid = tempL.valid && tempR.valid
		ans.maxDeph = 1 + max( tempL.maxDeph, tempR.maxDeph )
		ans.minDeph = 1 + min( tempL.minDeph, tempR.minDeph )
		ans.valid = ans.valid && (ans.maxVal <= max(tempL.maxVal,tempR.maxVal) )
		ans.valid = ans.valid && (ans.maxDeph-ans.minDeph<=1)
		ans.maxVal = max( ans.maxVal, max( tempL.maxVal, tempR.maxVal ) )
	}
	return ans
}

func esMinHeapBalanceado( raiz *Node ) bool{
	return check(raiz).valid
}

func main() {

	// arboles validos
	var n1 *Node = getLeaf(100);
	fmt.Println( esMinHeapBalanceado(n1) )
	
	var n2 *Node = &Node{
		val : 90,
		L : n1, 
		R : n1,
	}
	fmt.Println( esMinHeapBalanceado(n2) )
	
	var n3 *Node = &Node{
		val : 80,
		L : n1,
		R : nil,
	}
	fmt.Println( esMinHeapBalanceado(n3) )
	
	var n4 *Node = &Node{
		val : 70,
		L : n2,
		R :  n3,
	}
	fmt.Println( esMinHeapBalanceado(n4) )
	
	// arboles NO validos
	var n5 *Node = &Node{
		val : 200,
		L : n1,
		R :  n1,
	}
	fmt.Println( esMinHeapBalanceado(n5) )
	
	var n6 *Node = &Node{
		val : 80,
		L : n1,
		R :  nil,
	}
	n6 = &Node{
		val : 70,
		L : n6,
		R : nil,
	}
	n6 = &Node{
		val : 60,
		L : n6,
		R : n1,
	}
	fmt.Println( esMinHeapBalanceado(n6) )
}
