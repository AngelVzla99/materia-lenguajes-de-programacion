object MakeAClass{
    def fpoly[A <: {def apply(i: Int): Any } ](x: A, i: Int): Any = {
        x(i)
    }

    def f( x : Int ) : Int={return x;}

    def main(args: Array[String]){ 
        println( fpoly( f(_),2 ) ); 
    }
}