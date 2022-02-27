with Ada.Text_IO, Ada.Integer_Text_IO, Ada.Float_Text_IO;
use Ada.Text_IO, Ada.Integer_Text_IO, Ada.Float_Text_IO;

procedure jdoodle is

  p: Integer;           
  q: Integer;
  ans: Integer := 1;

begin
  Put ("Ingresa a: ");          -- put a string
  Get (p);                      -- get an integer
  Put ("Ingresa b: ");          -- put a string
  Get (q);                      -- get an integer
  for I in 1..q loop    
    ans := ans * p;
  end loop;                          
  New_Line (2);                       
  Put ("Ans =  ");                 
  Put (ans);
  New_Line;                            
  
end jdoodle;
