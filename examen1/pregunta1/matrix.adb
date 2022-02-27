with Ada.Text_IO, Ada.Integer_Text_IO, Ada.Float_Text_IO;
use Ada.Text_IO, Ada.Integer_Text_IO, Ada.Float_Text_IO;

procedure jdoodle is

  MAXN : Integer := 100;
  n: Integer;           
  m: Integer;
  p: Integer;
  ans: Integer := 1;
  
  type Matriz is array(1..MAXN,1..MAXN) of integer;--matriz de 5x3 
  A: Matriz;
  B: Matriz;
  C: Matriz;

begin
    -- =========================================
    -- PEDIR MATRICES
    
  Put ("Ingresa N: ");          -- put a string
  Get (n);                      -- get an integer
  new_line;
  Put ("Ingresa M: ");          -- put a string
  Get (m);                      -- get an integer
  new_line;
  
  Put (" === INGRESAR PRIMERA MATRIZ NxM ====");
  new_line;
  --Ejemplo que recorre una matriz escribiendo sus elementos
    for i in 1..n loop
       for j in 1..m loop
          Get(A(i,j));
       end loop;
    end loop;
    
   Put ("Ingresa P: ");          -- put a string
   Get (p);                      -- get an integer
   new_line;
   Put (" === INGRESAR PRIMERA MATRIZ MxP ====");
   new_line;
   for i in 1..m loop
       for j in 1..p loop
          Get(B(i,j));
       end loop;
    end loop;
    
    -- =========================================
    -- MULTIPLICAR MATRICES
    
    for i in 1..n loop
        for j in 1..p loop
            C(i,j) := 0;
            for k in 1..m loop
               C(i,j) := C(i,j) + A(i,k)*B(k,j);
            end loop;
        end loop;
    end loop;
    
    -- =========================================
    -- IMPRIMIR RESULTADOS
    
    Put (" === IMPRIMI NxM ====");
    new_line;
  --Ejemplo que recorre una matriz escribiendo sus elementos
    for i in 1..n loop
       for j in 1..m loop
          put(A(i,j)); put(" ");
       end loop;
       new_line;
    end loop;
    Put (" === IMPRIMI MxP ====");
    new_line;
    --Ejemplo que recorre una matriz escribiendo sus elementos
    for i in 1..n loop
       for j in 1..m loop
          put(B(i,j)); put(" ");
       end loop;
       new_line;
    end loop;
    Put (" === IMPRIMI NxP (resultado) ====");
    new_line;
    --Ejemplo que recorre una matriz escribiendo sus elementos
    for i in 1..n loop
       for j in 1..m loop
          put(C(i,j)); put(" ");
       end loop;
       new_line;
    end loop;
  
end jdoodle;

-- EJEMPLO DE INPUT 
-- 2 2
-- 0 1
-- 2 3
-- 2
-- 3 2
-- 1 0
