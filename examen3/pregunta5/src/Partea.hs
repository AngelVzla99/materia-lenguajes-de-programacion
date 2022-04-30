module Partea where

what :: a -> ([b] -> [(a, b)]) -> [b] -> [(a, b)]
what _ _ [] = []
what x f (y:ys) = (x, y) : f ys

foldr :: (a -> b -> b) -> b -> [a] -> b
foldr _ e [] = e
foldr f e (x:xs) = f x $ foldr f e xs

const :: a -> b -> a
const x _ = x

--misteriosa :: ???
misteriosa str lista = foldr what (const []) str lista

gen :: Int -> [Int]
gen n = n : gen (n + 1)

-- misteriosa "abc" (gen 1)

{-
misteriosa "abc" (gen 1)

=
foldr what (const []) [a,b,c] (gen 1)

=
(foldr what (const []) "abc") (gen 1)

= <usare f = what y e = (const[])>
= <Definicion de foldr (f x $ foldr f e xs)>
(f 'a' $ foldr f e ['b','c']) (gen 1)

= <Definicion de foldr (f x $ foldr f e xs)>
(f 'a' $ f 'b' $ foldr f e ['c']) (gen 1)

= <Definicion de foldr (f x $ foldr f e xs)>
(f 'a' $ f 'b' $ f 'c' $ foldr f e []) (gen 1)

= <Definicion de foldr (foldr _ e [] = e)>
(f 'a' $ f 'b' $ f 'c' $ e ) (gen 1)

= <la situacion actual es que a la izquierda tenemos una funcion>
= <y a la dderecha una lista, asi que podemos aplicar la funcion>
= <por definicion f = what y (gen 1)= 1 : (gen 2)>
what 'a' ($ f 'b' $ f 'c' $ e) 1:(gen 2)

= <aplicamos la def de what (what x f (y:ys) = (x, y) : f ys)>
('a',1) : ($ f 'b' $ f 'c' $ e) (gen 2)

= <aca ocurre lo mismo de antes, sustituimos f = what y (gen 2)=2:(gen 3)>
('a',1) : what 'b' ($ f 'c' $ e) 2:(gen 3) 

= <aplicamos la def de what (what x f (y:ys) = (x, y) : f ys)>
('a',1) : ('b',2) : ($ f 'c' $ e) (gen 3) 

= <sustituimos f = what y (gen 3)=3:(gen 4)>
('a',1) : ('b',2) :  what 'c' ($ e) 3:(gen 4)

= <aplicamos la def de what (what x f (y:ys) = (x, y) : f ys)>
('a',1) : ('b',2) : ('c',3) : ($ e) (gen 4)

= <sustituimos e = (const [])>
('a',1) : ('b',2) : ('c',3) : (const []) (gen 4)

= <por definicion (y pattern matching) tenemos que (const [] loQueSea) = []>
('a',1) : ('b',2) : ('c',3) : []

= <definicion de lista>
[('a',1),('b',2),('c',3)]

-}
