import scala.collection.mutable.ListBuffer

abstract class Coleccion[A]( var estructura:ListBuffer[A] = ListBuffer[A]() ){
    // Funcion para agregar un elemento 
    def agregar( elemento:A );
    // Funcion para remover un elemento de la estructura
    def remover( elemento:A ){
        if( !toBe(elemento) ){
            println("Error: El elemento no pertenece a la estructura");
        }else{
            estructura -= elemento;
        }
    }
    // Funcion para saber si un elemento pertenece a la estructura en O(n)
    def toBe( elemento:A ) : Boolean={
        for( e2 <- estructura ){
            if( e2 == elemento ){
                return true;
            }
        }
        return false;
    }
    // Funcion booleaca para saber si la estructura esta vacia
    def vacio() : Boolean={
        return estructura.length==0;
    }
}

class Conjunto[A] extends Coleccion[A]{
    def agregar( elemento :A ){
        if( !toBe(elemento) ){
            estructura += elemento;
        }
    }
}

class Bolsa[A] extends Coleccion[A]{
    def agregar( elemento :A ){
        estructura += elemento;
    }
}

object ParteA{
    def main(args: Array[String]){ 
        val conj:Conjunto[Int] = new Conjunto[Int];
        val bol:Bolsa[Int] = new Bolsa[Int];
    }
}