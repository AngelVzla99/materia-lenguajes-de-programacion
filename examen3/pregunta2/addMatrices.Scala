class MyThread( 
    val r:Int, 
    val c:Int,  
    val M1:Array[Array[Int]],
    val M2:Array[Array[Int]],
    val M3:Array[Array[Int]]
    ) extends Thread{

	override def run(  ){
        M3(r)(c) = M1(r)(c) + M2(r)(c);
	}
}

object addMatrices{
    def printM( A:Array[Array[Int]], N:Int, M:Int ){
        for( i<- 0 to N-1 ){
            for(j<- 0 to M-1){
                printf("%d ", A(i)(j));
            }
            println();
        }
    }

    def main(args: Array[String]) {
        var N = 3;
        var M = 3;

        var Matrix1 = Array.ofDim[Int](N, M)
        var Matrix2 = Array.ofDim[Int](N, M)
        var Matrix3 = Array.ofDim[Int](N, M)

        // inicializar las matrices
        for(i<-0 to N-1){ for(j<-0 to M-1){ Matrix1(i)(j) = i+j; } }
        for(i<-0 to N-1){ for(j<-0 to M-1){ Matrix2(i)(j) = 2; } }

        // Sumar las matrices con hilos
        var hilos = Array.ofDim[MyThread](N,M); 
        for( i <- 0 to N-1 ){
            for( j <- 0 to M-1 ){
                hilos(i)(j) = new MyThread(i,j,Matrix1,Matrix2,Matrix3);
                hilos(i)(j).start();
            }
        }
        for(i<-0 to N-1){ for(j<-0 to M-1){ hilos(i)(j).join(); } }
        
        // Imprimir las matrices
        println("MATRIX1:")
        printM( Matrix1, N, M );

        println("MATRIX2:")
        printM( Matrix2, N, M );

        println("Suma de Matrix1 y Matrix2:")
        printM( Matrix3, N, M );
    }
}
