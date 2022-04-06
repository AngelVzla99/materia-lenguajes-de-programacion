package main

import "fmt"

type Church struct {
	next   *Church
}

func getZero() *Church {
	return &Church{
		next: nil,
	}
}

func sucesor( n1 *Church ) *Church{
	return &Church{
		next : n1,
	}
}

func valor( n3 *Church ) int{
	var ans int = 0
	for n3.next != nil {
		n3 = n3.next
		ans += 1
	}
	return ans
}

func suma( n1 *Church, n2 *Church ) *Church{
	for n2.next != nil {
		n2 = n2.next
		n1 = &Church{ next : n1, }
	}
	return n1
}

func multiplicar( n1 *Church, n2 *Church ) *Church{
	var ans *Church = getZero()
	for n2.next != nil {
		n2 = n2.next
		ans = suma( ans, n1 )
	}
	return ans
}

func main() {
	// n1  equivalente a numero 2
	var n1 *Church = getZero()
	n1 = sucesor(n1)
	n1 = sucesor(n1)
	
	// n1  equivalente a numero 3
	var n2 *Church = getZero()
	n2 = sucesor(n2)
	n2 = sucesor(n2)
	n2 = sucesor(n2)
	
	// =======  Prueba funcion SUMA =======
	// n3 equivalente a la suma de n1 y n2 (3)
	var n3 *Church = suma(n1,n2)
	fmt.Println( valor(n3) )
	
	// =======  Prueba funcion MULTIPLICACION =======
	var n4 *Church = multiplicar(n1,n2)
	fmt.Println( valor(n4) )
}
