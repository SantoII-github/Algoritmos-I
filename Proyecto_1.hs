{-
Ejercicio 1 a) esCero :: Int -> Bool, que verifica si un entero es igual a 0.
-}

esCero :: Int -> Bool
esCero x = x == 0

{-
Ejercicio 1 b) esPositivo :: Int -> Bool, que verifica si un entero es estrictamente mayor a 0.
-}

esPositivo :: Int -> Bool
esPositivo x = x > 0 

{-
Ejercicio 1 c) esVocal :: Char -> Bool, que verifica si un carácter es una vocal en minúscula.
-}

esVocal :: Char -> Bool
esVocal x = x == 'a' || x == 'e'  || x == 'i' || x == 'o' || x == 'u'

{-
Ejercicio 2 a) paratodo :: [Bool] -> Bool, que verifica que todos los elementos de una lista sean True.
-}

paratodo :: [Bool] -> Bool
paratodo [] = True
paratodo (x:xs) = x && paratodo xs

{-}
Ejercicio 2 b) sumatoria :: [Int] -> Int, que calcula la suma  de todos los elementos de una lista de enteros.
-}
sumatoria :: [Int] -> Int
sumatoria [] = 0
sumatoria (x:xs) = x + sumatoria xs

{-
Ejercicio 2 c) productoria :: [Int] -> Int, que calcula el producto de todos los elementos de una lista de enteros.
-}

productoria :: [Int] -> Int
productoria [] = 0
productoria (x:xs) = x * productoria xs

{-
Ejercicio 2 d) factorial :: Int -> Int, que toma un número n y calcula n!.
-}

factorial :: Int -> Int
factorial 0 = 1
factorial n = n * factorial (n - 1)

{-
Ejercicio 2 e) Utilizá la función sumatoria para definir, promedio :: [Int] -> Int, que toma una lista de números 
no vacia y calcula el valor promedio (truncado, usando división entera).
-}
promedio :: [Int] -> Int
promedio [] = 0
promedio xs = div (sumatoria xs) (length xs)

{-
Ejercicio 3 Programá la función pertenece :: Int -> [Int] -> Bool, que verifica si un número se encuentra en una lista.
-}

pertenece :: Int -> [Int] -> Bool
pertenece _ [] = False
pertenece n (x:xs) = n == x || (pertenece n xs)

{-
Ejercicio 4 a) paratodo’ :: [a] -> (a -> Bool) -> Bool, dada una lista xs de tipo [a] y un 
predicado t :: a -> Bool, determina si todos los elementos de xs satisfacen el predicado t.
-}

paratodo' :: [a] -> (a -> Bool) -> Bool
paratodo' [] _ = True
paratodo' (x:xs) t = t (x) && (paratodo' xs t)

{-
b) existe’ :: [a] -> (a -> Bool) -> Bool, dada una lista xs de tipo [a] y un predicado t :: a -> Bool, 
determina si algún elemento de xs satisface el predicado t.
-}

existe' :: [a] -> (a -> Bool) -> Bool
existe' [] _ = False
existe' (x:xs) t = t (x) || (existe' xs t)

{-
c) sumatoria’ :: [a] -> (a -> Int) -> Int, dada una lista xs de tipo [a] y una función t :: a -> Int 
(toma elementos de tipo a y devuelve enteros), calcula la suma de los valores que resultan de la aplicación de t 
a los elementos de xs.
-}

sumatoria' :: [a] -> (a -> Int) -> Int 
sumatoria' [] _ = 0 
sumatoria' (x:xs) t = t (x) + (sumatoria' xs t)

{-
d) productoria’ :: [a] -> (a -> Int) -> Int, dada una lista de xs de tipo [a] y una función t :: a -> Int, 
calcula el producto de los valores que resultan de la aplicación de t a los elementos de xs.
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

{-
6. Utilizando las funciones del ejercicio 4, programá las siguientes funciones por composición,
sin usar recursión ni análisis por casos.

a) todosPares :: [Int] -> Bool verifica que todos los números de una lista sean pares.
-}

todosPares :: [Int] -> Bool
todosPares xs = paratodo' xs even

{-
b) hayMultiplo :: Int -> [Int] -> Bool verifica si existe algún número dentro del
segundo parámetro que sea múltiplo del primer parámetro.
-}

--Indica si la variable y es un múltiplo de x
esMultiplo :: Int -> Int -> Bool  
esMultiplo x y = mod y x == 0 

hayMultiplo :: Int -> [Int] -> Bool
hayMultiplo x xs = existe' xs (esMultiplo x) 

--Hace lo mismo que hayMultiplo, pero usa una función lambda en lugar de una auxiliar
hayMultiplo' :: Int -> [Int] -> Bool 
hayMultiplo' x xs = existe' xs (\y -> mod y x == 0)

{-
c) sumaCuadrados :: Int -> Int, dado un número no negativo n, calcula la suma de
los primeros n cuadrados. (Voy a incluir 0^2 y voy a dejar afuera n^2)

Ayuda: En Haskell se puede escribir la lista que contiene el rango de números entre n
y m como [n..m].
-}

--Devuelve el cuadrado de un número
cuadrado :: Int -> Int
cuadrado x = x ^ (2 :: Int)  -- 2 :: Int resuelve un warning que me molestaba. No afecta al resultado y se puede omitir.

sumaCuadrados :: Int -> Int
sumaCuadrados n = sumatoria' [0..n-1] cuadrado

--Hace lo mismo que sumaCuadrados, pero usa una función lambda en lugar de una auxiliar 
sumaCuadrados' :: Int -> Int
sumaCuadrados' n = sumatoria' [0..n-1] (\x -> x ^ (2 ::Int)) -- 2 :: Int resuelve un warning que me molestaba. No afecta al resultado y se puede omitir.

{-
d) ¿Se te ocurre como redefinir factorial (ej. 2d) para evitar usar recursión?
-}

factorial' :: Int -> Int 
factorial' x = productoria' [1..x] id

{-
e) multiplicaPares :: [Int] -> Int que calcula el producto de todos los números pares de una lista.
-}

multiplicaPares :: [Int] -> Int
multiplicaPares xs = productoria' (filter even xs)  id

{-
7. Indagá en Hoogle sobre las funciones map y filter. También podes consultar su tipo en
ghci con el comando :t

-¿Qué hacen estas funciones?
La función map f xs toma dos parámetros, una función f y una lista xs, y devuelve la lista de los resultados
de aplicar f a cada elemento de xs.

La función filter p xs toma dos parámetros, un predicado p y una lista xs, y devuelve la lista de los elementos
de xs que cumplen con ese predicado. ("Filtra" la lista y la devuelve quitándole los elementos que no cumplen p).

-¿A qué equivale la expresión map succ [1,-4, 6, 2,-8], donde succ n = n + 1?
La expresión map succ [1,-4, 6, 2,-8] devuelve la lista de los números enteros que le siguen a cada elemento
de [1,-4, 6, 2, -8]. Es decir, devolvería [2,-3, 7, 3,-7].

-¿Y la expresión filter esPositivo [1,-4, 6, 2,-8]?
La expresión filter esPositivo  [1,-4, 6, 2,-8] devuelve la lista de los números positivos de la lista
[1, -4, 6, 2, -8]. Es decir, devolvería [1, 6, 2].

8. Programá una función que dada una lista de números xs, devuelve la lista que resulta de duplicar cada 
valor de xs.

a) Definila usando recursión.
-}

duplicarLista :: [Int] -> [Int]
duplicarLista [] = []
duplicarLista (x:xs) = (2 * x) : duplicarLista xs  

{-
b) Definila utilizando la función map.
-}

duplicarLista' :: [Int] -> [Int]
duplicarLista' xs = map (*2) xs

{-
9. Programá una función que dada una lista de números xs, calcula una lista que tiene como elementos
aquellos números de xs que son pares.

a) Definila usando recursión.
-}

soloPares :: [Int] -> [Int]
soloPares [] = []
soloPares (x:xs) 
    | mod x 2 == 0 = x : soloPares xs
    | otherwise = soloPares xs 

{-
b) Definila utilizando la función filter
-}

soloPares' :: [Int] -> [Int]
soloPares' xs = filter even xs

{-
c) Revisá tu definición del ejercicio 6e. ¿Cómo podés mejorarla?

Cuando resolví el ejercicio 6e ya conocía la existencia de la función filter. Lo que podría mejorar
es usar la función definida en 9b para que leer la definición de la función multiplicaPares sea
más fácil.
-}

multiplicaPares' :: [Int] -> Int
multiplicaPares' xs = productoria' (soloPares' xs)  id

{-
10. La función primIgualesA toma un valor y una lista, y calcula el tramo inicial
más largo de la lista cuyos elementos son iguales a ese valor. Por ejemplo:

primIgualesA 3 [3, 3, 4, 1] = [3, 3]
primIgualesA 3 [4, 3, 3, 4, 1] = []
primIgualesA 3 [] = []
primIgualesA 'a' "aaadaa" = "aaa"

a) Programá primIgualesA por recursión.
-}

primIgualesA :: Eq a => a -> [a] -> [a]
primIgualesA _ [] = []
primIgualesA y (x:xs)
    | y == x = y : primIgualesA y xs
    | otherwise = []

{-
Programá nuevamente la función utilizando takeWhile
-}

primIgualesA' :: Eq a => a -> [a] -> [a]
primIgualesA' y xs = takeWhile (==y) xs

{-
11. La función primIguales toma una lista y devuelve el mayor tramo inicial de la
lista cuyos elementos son todos iguales entre sí. Por ejemplo:

primIguales [3,3,4,1] = [3,3]
primIguales [4,3,3,4,1] = [4]
primIguales [] = []
primIguales "aaadaa" = "aaa"

a) Programá primIguales por recursión.
-}

primIguales :: Eq a => [a] -> [a]
primIguales [] = []
primIguales [x] = [x]
primIguales (x:xs)
    | x == head xs = x : primIguales xs
    | otherwise = [x]

{-
b) Usá cualquier versión de primIgualesA para programar pimIguales. Está permitido
dividir en casos, pero no usar recursión. 
-}

primIguales' :: Eq a => [a] -> [a]
primIguales' xs
    | xs == [] = []
    | otherwise = primIgualesA (head xs) xs

{-
12. (*) Para cada uno de los siguientes patrones, decidí si están bien tipados, y en tal caso da los
tipos de cada subexpresión. En caso de estar bien tipado, ¿el patrón cubre todos los casos
de definición?

a) 
f :: (a, b) -> ...
f x = ...
Está bien tipado. x :: (a,b). El patrón cubre todos los casos.

b)
f :: (a,b) -> ...
f (x , y) = ...
Está bien tipado. (x, y) :: (a,b). El patrón cubre todos los casos.

c)
f :: [(a,b)] -> ...
f (a,b) = ...
No está bien tipado porque el patrón pide una tupla cuando la función debería
recibir una lista de tuplas.

d)
f :: [(a, b)] -> ...
f (x:xs) = ...
Está bien tipado. x :: (a,b), xs :: [(a,b)]. El patrón no cubre el caso de [].

e)
f :: [(a, b)] -> ...
f ((x, y) : ((a, b) : xs)) = ...
Está bien tipado. x :: a, y :: b, a :: a, b :: b, xs :: [(a,b)]. El patrón
no cubre los casos de [] ni [x] 

f)
f :: [(Int, a)] -> ...
f [(0, a)] = ...
Está bien tipado. 0 :: Int, a :: a. El patrón no cubre los casos [], las listas con más de un elemento
ni los casos en el que el primer elemento de la tupla no sea un 0.

g)
f :: [(Int, a)] -> ...
f ((x, 1) : xs) = ...
Está bien tipado. x :: Int, 1 :: Int, xs:: [(Int, Int)]. El patrón no cubre [] ni las listas en las que
el segundo elemento de la tupla no es 1. 

h)
f :: [(Int, a)] -> ...
f ((1, x) : xs) = ...
Está bien tipado. 1 :: Int, x :: a, x :: [(Int, a)]. El patrón no cubre [] ni las listas en las que el
primer elemento de sus tuplas no es 1.

i)
f :: (Int -> Int) -> Int -> ...
f a b = ...
Está bien tipado. a :: Int -> Int, b :: Int. El patrón cubre todos los casos.

j)
f :: (Int -> Int) -> Int -> ...
f a 3 = ...
Está bien tipado. a :: Int -> Int, 3 :: Int. El patrón no cubre los casos en los que el segundo parámetro
no es 3. 

k)
f :: (Int -> Int) -> Int -> ...
f 0 1 2 = ...
Está mal tipada porque el patrón tiene 3 argumentos mientras que la función debería recibir 2. Además,
ninguno de ellos es una función con tipo Int -> Int.

l)
f :: a -> (a -> a) -> ...
f a g = ...
Está bien tipada. a :: a, g :: a -> a. El patrón cubre todos los casos.

13. (*) Para las siguientes declaraciones de funciones, da al menos una definición cuando sea
posible (que no sea la expresión undefined). ¿Podés dar alguna otra definición alternativa
a la que diste en cada caso?
Por ejemplo, si la declaración es f :: (a, b) -> a, la respuesta es: f (x,y) = x

a) f :: (a, b) -> b
-}

funcionA :: (a,b) -> b
funcionA (_, b) = b

{-
b) f :: (a, b) -> c
Sin especificar el tipo no se puede obtener un tipo que no estemos usando en los parámetros de la función

c) f :: a -> b
Sin especificar el tipo no se puede obtener un tipo que no estemos usando en los parámetros de la función

d) f :: (a -> b) -> a -> b
-}

funcionD :: (a -> b) -> a -> b
funcionD f a = f a 

{-
e) f :: (a -> b) -> [a] -> [b]
-}

funcionE :: (a -> b) -> [a] -> [b]
funcionE _ [] = []
funcionE f (x:_) = (f x) : []

{-
f ) f :: (a -> b) -> a -> c
Sin especificar el tipo no se puede obtener un tipo que no estemos usando en los parámetros de la función

g) f :: (a -> b) -> (b -> c) -> a -> c
-}

funcionF:: (a -> b) -> (b -> c) -> a -> c
funcionF f1 f2 a = f2(f1(a))
