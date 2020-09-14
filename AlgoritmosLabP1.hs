-- Ejercicio 1. Mi DNI es 43.542.187

estaEnDNI :: Int -> Bool
estaEnDNI n = n == 1 || n == 2 || n == 3 || n == 4 || n == 5 || n == 7 || n == 8 

-- Ejercicio 2. Mi DNI es 43.542.187

cuentaNoDNI :: [Int] -> Int
cuentaNoDNI [] = 0
cuentaNoDNI (x:xs)
    | estaEnDNI x == True = cuentaNoDNI xs
    | otherwise = 1 + cuentaNoDNI xs

-- Ejercicio 3. Mi DNI es 43.542.187

sumatoria' :: [a] -> (a -> Int) -> Int 
sumatoria' [] _ = 0 
sumatoria' (x:xs) t = t (x) + (sumatoria' xs t)

funcionAuxiliar :: Int -> Int
funcionAuxiliar n
    | estaEnDNI n == False = 1
    | otherwise = 0

cuentaNoDNI' :: [Int] -> Int
cuentaNoDNI' xs = sumatoria' xs funcionAuxiliar

-- Ejercicio 4. 

aplicaSegun :: [Int] -> Int -> (Int -> a) -> (Int -> a) -> [a]
aplicaSegun [] _ _ _ = []
aplicaSegun (x:xs) n f g
    |  x >= n = f x : aplicaSegun xs n f g
    |  otherwise = g x : aplicaSegun xs n f g 