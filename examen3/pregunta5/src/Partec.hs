module Partec where

data Arbol a = Hoja | Rama a (Arbol a) (Arbol a) deriving(Show)

foldA :: (a -> b -> b -> b) -> b -> Arbol a -> b
foldA _ b Hoja = b
foldA f b (Rama a nodeL nodeR) =
    f a (foldA f b nodeL) (foldA f b nodeR)

whatTF :: a
    -> (Arbol b -> Arbol (a, b))
    -> (Arbol b -> Arbol (a, b))
    -> Arbol b
    -> Arbol (a, b)
whatTF _ _ _ Hoja = Hoja
whatTF x f g (Rama y i d) = Rama (x, y) (f i) (g d)

--sospechosa :: ???
sospechosa a1 a2 = foldA whatTF (const Hoja) a1 a2

genA :: Int -> Arbol Int
genA n = Rama n (genA (n + 1)) (genA (n * 2))

arbolito :: Arbol Char
arbolito = Rama 'a' (Rama 'b' Hoja (Rama 'c' Hoja Hoja)) Hoja

-- sospechosa arbolito (genA 1)

{-

sospechosa arbolito (genA 1)

=
foldA whatTF (const Hoja) arbolito (genA 1)

=
(foldA whatTF (const Hoja) arbolito) (genA 1)

= <substituimos arbolito>
(foldA whatTF (const Hoja) (Rama 'a' (Rama 'b' Hoja (Rama 'c' Hoja Hoja)) Hoja)) (genA 1)

= <Aplicacmos la def de foldA>
= <foldA f b (Rama a nodeL nodeR) = >
= <f a (foldA f b nodeL) (foldA f b nodeR)>
= <usare f = whatTF y b = (Const Hoja) >
f 'a' (foldA f b (Rama 'b' Hoja (Rama 'c' Hoja Hoja)) ) (foldA f b Hoja) (genA 1)

= <Substituimos el caso base de foldA _ b Hoja>
f 'a' (foldA f b (Rama 'b' Hoja (Rama 'c' Hoja Hoja)) ) b (genA 1)

= <Aplicacmos la def de foldA>
f 'a' (f 'b' ((foldA f b Hoja) (foldA f b (Rama 'c' Hoja Hoja)) ) ) b (genA 1)

= <Substituimos el caso base de foldA _ b Hoja>
f 'a' (f 'b' (b (foldA f b (Rama 'c' Hoja Hoja)) ) ) b (genA 1)

= <Aplicacmos la def de foldA>
f 'a' (f 'b' (b (f 'c' (foldA f b Hoja) (foldA f b Hoja)) ) ) b (genA 1)

= <Substituimos el caso base de foldA _ b Hoja>
f 'a' (f 'b' b (f 'c' b b ) ) b (genA 1)

= <Substutuimos en la parte mas externa de la funcion>
= < f = whatTF, b = (const Hoja) y  >
= < (gen 1) = Rama 1 (genA 2) (genA 2) >
whatTF 'a' (f 'b' b (f 'c' b b ) ) (const Hoja) (Rama 1 (genA 2) (genA 2))

= <Aplicando la definicion de la funcion whatTF>
= <whatTF x f g (Rama y i d) = Rama (x, y) (f i) (g d)>
Rama ('a', 1) ((f 'b' b (f 'c' b b ) ) (genA 2)) ((const Hoja) (genA 2))

= <aplicando la defincion de const Hoja _ = Hoja>
Rama ('a', 1) ((f 'b' b (f 'c' b b ) ) (genA 2)) Hoja

= <Substutuimos en la parte mas externa de la funcion>
= < f = whatTF, b = (const Hoja) y  >
= < (gen 2) = Rama 2 (genA 3) (genA 4) >
Rama ('a', 1) (what 'b' (const Hoja) (f 'c' b b ) (Rama 2 (genA 3) (genA 4))) Hoja

= <Aplicando la definicion de la funcion whatTF>
= <whatTF x f g (Rama y i d) = Rama (x, y) (f i) (g d)>
Rama ('a', 1) (Rama ('b',2) ((const Hoja) (genA 3)) ((f 'c' b b ) (genA 4))) Hoja 

= <aplicando la defincion de const Hoja _ = Hoja>
Rama ('a', 1) (Rama ('b',2) Hoja ((f 'c' b b ) (genA 4))) Hoja 

= <Substutuimos en la parte mas externa de la funcion>
= < f = whatTF, b = (const Hoja) y  >
= < (gen 4) = Rama 4 (genA 5) (genA 8) >
Rama ('a', 1) (Rama ('b',2) Hoja (what 'c' (const Hoja) (const Hoja) (Rama 4 (genA 5) (genA 8)) )) Hoja 

= <Aplicando la definicion de la funcion whatTF>
= <whatTF x f g (Rama y i d) = Rama (x, y) (f i) (g d)>
Rama ('a', 1) (Rama ('b',2) Hoja (Rama ('c',4) ((const Hoja) (genA 5)) ((const Hoja) (genA 8))) ) Hoja 

= <aplicando la defincion de const Hoja _ = Hoja>
Rama ('a', 1) (Rama ('b',2) Hoja (Rama ('c',4) Hoja Hoja) ) Hoja 

-}