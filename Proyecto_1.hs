{-
Ejercicio 1 a) esCero :: Int -> Bool, que verifica si un entero 
es igual a 0.
-}

esCero :: Int -> Bool
esCero x = x == 0

{-
Ejercicio 1 b) esPositivo :: Int -> Bool, que verifica si un 
entero es estrictamente mayor a 0.
-}

esPositivo :: Int -> Bool
esPositivo x = x > 0 

{-
Ejercicio 1 c) esVocal :: Char -> Bool, que verifica si un 
carácter es una vocal en minúscula.
-}

esVocal :: Char -> Bool
esVocal x = x == 'a' || x == 'e'  || x == 'i' || x == 'o' || x == 'u'

{-
Ejercicio 2 a) paratodo :: [Bool] -> Bool, que verifica que todos 
los elementos de una lista sean True.
-}

paratodo :: [Bool] -> Bool
paratodo [] = True
paratodo (x:xs) = x && paratodo xs

{-}
Ejercicio 2 b) sumatoria :: [Int] -> Int, que calcula la suma 
de todos los elementos de una lista de enteros.
-}
sumatoria :: [Int] -> Int
sumatoria [] = 0
sumatoria (x:xs) = x + sumatoria xs

{-
Ejercicio 2 c) productoria :: [Int] -> Int, que calcula el 
producto de todos los elementos una la lista de enteros.
-}

productoria :: [Int] -> Int
productoria [] = 0
productoria (x:xs) = x * productoria xs

{-
Ejercicio 2 d) factorial :: Int -> Int, que toma un número n 
y calcula n!.
-}

factorial :: Int -> Int
factorial 0 = 1
factorial n = n * factorial (n - 1)

{-
Ejercicio 2 e) Utilizá la función sumatoria para definir, 
promedio :: [Int] -> Int, que toma una lista de números no vacia 
y calcula el valor promedio (truncado, usando división entera).
-}
promedio :: [Int] -> Int
promedio [] = 0
promedio xs = div (sumatoria xs) (length xs)

{-
Ejercicio 3 Programá la función pertenece :: Int -> [Int] -> Bool, 
que verifica si un número se encuentra en una lista.
-}

pertenece :: Int -> [Int] -> Bool
pertenece _ [] = False
pertenece n (x:xs) = n == x || (pertenece n xs)

{-
Ejercicio 4 a) paratodo’ :: [a] -> (a -> Bool) -> Bool, dada una 
lista xs de tipo [a] y un predicado t :: a -> Bool, determina si 
todos los elementos de xs satisfacen el predicado t.
-}

paratodo' :: [a] -> (a -> Bool) -> Bool
paratodo' [] _ = True
paratodo' (x:xs) t = t (x) && (paratodo' xs t)

{-
b) existe’ :: [a] -> (a -> Bool) -> Bool, dada una lista xs de tipo [a] y un
predicado t :: a -> Bool, determina si algún elemento de xs satisface el predicado
t.
-}

existe' :: [a] -> (a -> Bool) -> Bool
existe' [] _ = False
existe' (x:xs) t = t (x) || (existe' xs t)

{-
c) sumatoria’ :: [a] -> (a -> Int) -> Int, dada una lista xs de tipo [a] y una
función t :: a -> Int (toma elementos de tipo a y devuelve enteros), calcula la
suma de los valores que resultan de la aplicación de t a los elementos de xs.
-}

sumatoria' :: [a] -> (a -> Int) -> Int 
sumatoria' [] _ = 0 
sumatoria' (x:xs) t = t (x) + (sumatoria' xs t)

{-
d) productoria’ :: [a] -> (a -> Int) -> Int, dada una lista de xs de tipo [a]
y una función t :: a -> Int, calcula el producto de los valores que resultan de la
aplicación de t a los elementos de xs.
-}

productoria' :: [a] -> (a -> Int) -> Int 
productoria' [] _ = 1 
productoria' (x:xs) t = t (x) * (productoria' xs t)

{-
5. Definı́ nuevamente la función paratodo, pero esta vez usando la función paratodo’ 
(sin recursión ni análisis por casos!).
-}

paratodo'' :: [Bool] -> Bool
paratodo'' xs = paratodo' xs (==True)