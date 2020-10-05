-- Ejercicio 1

data Medalla = Bronce | Plata | Oro deriving (Show, Eq, Ord)
type Medallero = [Medalla]

valor_medalla :: Medalla -> Int
valor_medalla Bronce = 1
valor_medalla Plata = 2
valor_medalla Oro = 4

-- Ejercicio 2

data Disciplina = Boxeo | Judo | Vela | Jockey | Tenis
data Resultado = Res Disciplina Medalla 

medallero_vela :: [Resultado] -> Medallero
medallero_vela [] = []
medallero_vela ((Res Vela medalla):xs) = medalla : medallero_vela xs 
medallero_vela ((Res _ _ ):xs) = medallero_vela xs 

-- Ejercicio 3

data ListaAsoc a b = Vacia | Nodo a b (ListaAsoc a b) deriving Show
laPrueba :: ListaAsoc String String
laPrueba = (Nodo "test1" "test2" (Nodo "test3" "test4" (Nodo "test5" "test6" Vacia)))

la_existe :: Eq a => ListaAsoc a b -> a -> Bool
la_existe Vacia _ = False
la_existe (Nodo a _ la) k
    | a == k = True
    | otherwise = la_existe la k

la_busca :: Eq a => ListaAsoc a b -> a -> Maybe b
la_busca Vacia _ = Nothing
la_busca (Nodo a b la) clave
    | a == clave = Just b
    |otherwise = la_busca la clave

esNothing :: Maybe a -> Bool
esNothing Nothing = True
esNothing _ = False

la_existe' :: Eq a => ListaAsoc a b -> a -> Bool
la_existe' la clave = not (esNothing (la_busca la clave))

-- Ejercicio 4

data Arbol a = Hoja | Rama (Arbol a) a (Arbol a) deriving Show

a1,a2,a3,a4,a5,a6,a7 :: Arbol (Int,String)
a7 = Rama a5 (7, "test7") a6
a6 = Rama a3 (6, "test6") a4
a5 = Rama a1 (5, "test5") a2
a4 = Rama Hoja (4, "test4") Hoja
a3 = Rama Hoja (3, "test3") Hoja
a2 = Rama Hoja (2, "test2") Hoja
a1 = Rama Hoja (1, "test1") Hoja

arbol_busca :: Arbol (Int, String) -> Int -> Maybe String
arbol_busca Hoja _ = Nothing
arbol_busca (Rama arbolIzq (a, b) arbolDer) k | k == a = Just b
                                              | otherwise = case arbol_busca arbolIzq k of
                                                            Nothing -> arbol_busca arbolDer k
                                                            Just x -> Just x

