module Parteb where

data Arbol a = Hoja | Rama a (Arbol a) (Arbol a)

foldA :: (a -> b -> b -> b) -> b -> Arbol a -> b
foldA _ b Hoja = b
foldA f b (Rama a nodeL nodeR) =
    f a (foldA f b nodeL) (foldA f b nodeR)
