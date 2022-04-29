import scala.collection.mutable.ListBuffer
import scala.collection.mutable.Stack
import scala.collection.mutable.Queue

// Clase grafo implementada como una lista de adyacencias
class Graph( 
    val N:Int, // Numero de nodos del grafo
    var ady:Array[ListBuffer[Int]] // Lista de adyacencias
    ){
    // Sobrecarga del constructor con un solo parametro
    def this( x:Int ){
        this(x,new Array[ListBuffer[Int]](x))
    }
    // inicializar la lista de adyacencias
    def init(){
        for(i<- 0 to N-1){
            ady(i) = new ListBuffer[Int];
        }
    }
    // Agregar edges
    def add_edge( v:Int, u:Int ){
        ady(v) += u;
    }
}

abstract class Busqueda( g:Graph, visit:Array[Boolean] ){
    // Sobrecarga del constructor busqueda con 1 solo parametro
    def this( g:Graph ){
        this(g, new Array[Boolean](g.N)); 
    }
    // Metodo generico para buscar en un grafo (DFS/BFS)
    def buscar( D:Int, H:Int ) :Int = {
        var ans = 0;

        add(D);
        visit(D) = true
        while( !empty() ){
            ans+=1;
            var v = take();
            if(v==H) return ans;

            for(u <- g.ady(v)) if(!visit(u)){
                visit(u) = true;
                add(u);
            }
        }
        return -1;
    }

    // Agregar elemento a una estructura
    def add( elemento:Int );
    // Tomar un elemento de una estructura
    def take():Int;
    // Saber si la estructura no tiene elementos
    def empty():Boolean;
}

// Clase DFS que basicamente extiende de la clase Graph con la estructura Stack
class DFS( g:Graph, s:Stack[Int] = new Stack[Int] ) extends Busqueda(g){
    def add( elemento:Int ) = s.push(elemento);
    def take():Int = s.pop();
    def empty():Boolean = s.isEmpty;
}

// Clase BFS que basicamente extiende de la clase Graph con la estructura Queue
class BFS( g:Graph, s:Queue[Int] = new Queue[Int] ) extends Busqueda(g){
    def add( elemento:Int ) = s.enqueue(elemento);
    def take():Int = s.dequeue();
    def empty():Boolean = s.isEmpty;
}

object ParteB{
    def main(args: Array[String]){ 

        // Ejemplo de como usar las clases
        var g1:Graph = new Graph(10);
        g1.init();
        g1.add_edge(1,6);
        g1.add_edge(1,7);
        g1.add_edge(1,2);
        g1.add_edge(2,3);
        g1.add_edge(3,4);
        g1.add_edge(4,5);
       
        var busqDFS:DFS = new DFS(g1);
        var busqBFS:BFS = new BFS(g1);

        var cnt1:Int = busqDFS.buscar(1,4);
        var cnt2:Int = busqBFS.buscar(1,4);

        println("Busqueda DFS = "+cnt1);
        println("Busqueda BFS = "+cnt2);
    }
}