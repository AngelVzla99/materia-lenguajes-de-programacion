import java.io.File

class MyThread( 
    var numberOfFiles : Int, // Numero de archivos sumados por el hilo
    val path : String       // Directorio actual
    ) extends Thread{

    // Funcion para obtener la lista de archivos en un directorio
    def getListOfFiles(dir: String):List[File] = {
        val d = new File(dir)
        if (d.exists && d.isDirectory) {
            d.listFiles.filter(_.isFile).toList
        } else {
            List[File]()
        }
    }

	override def run(  ){
        // Numero de archivos 
        val files : List[String] = (new File(path)).
            listFiles.
            filter(_.isFile).
            map(_.getPath).toList;
        numberOfFiles = files.length;

        // Lista de carpetas        
        val folders: List[String] = (new File(path)).
            listFiles.
            filter(_.isDirectory).
            map(_.getPath).toList;

        // Se crea un hilo para cada carpeta
        val numDir:Int = folders.length
        val hilo = new Array[MyThread](numDir);
        for( i <- 0 to numDir-1 ){
            hilo(i) = new MyThread( 0, folders(i) );
            hilo(i).start();
        } 
        for(i <- 0 to numDir-1){
            hilo(i).join();
            numberOfFiles += hilo(i).numberOfFiles;
        }
	}
}

object Archivos {
    
    def main(args: Array[String]){
        // En vez de prueba1 se coloca el directorio 
        // del que se quiere obtener la respuesta
        var th = new MyThread(0,"prueba1");
        th.start(); // Se crea un hilo para el directorio inicial
        th.join();  // Se espera a que el hilo termine
        println( "Numero de archivos " + th.numberOfFiles );
    } 
}