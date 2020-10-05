-- 1. a)  Implementá el tipo Carrera como está definido arriba.

--Queda definido como Carrera' para evitar conflictos con la definición más completa del ejercicio 2
data Carrera' =  Matematica' | Fisica' | Computacion' | Astronomia'

{- 
1. b) Definí la siguiente función, usando pattern matching: titulo :: Carrera -> String
que devuelve el nombre completo de la carrera en forma de string. Por ejemplo, para el
constructor Matematica, debe devolver ”Licenciatura en Matemática”.
-}

titulo :: Carrera -> String
titulo Matematica = "Licenciatura en Matemática"
titulo Fisica =  "Licenciatura en Física"
titulo Computacion = "Licenciatura en Ciencias de la Computación"
titulo Astronomia = "Licenciatura en Astronomía"

{-
2. a) Completar la definición del tipo Carrera para que las expresiones

$> Matematica <= Computacion
$> Matematica ‘min‘ Computacion

sean válidas y no generen error. Ayuda: usar deriving con múltiples clases.
-}

data Carrera =  Matematica | Fisica | Computacion | Astronomia 
    deriving (Eq, Ord, Bounded, Show)

{-
3. a) Implementá los tipos Ingreso, Cargo, Area y Persona como están definidos arriba.
-}

type Ingreso = Int
data Cargo = Titular | Asociado | Adjunto | Asistente | Auxiliar deriving Show
data Area = Administrativa | Ensenanza | Economica | Postgrado deriving Show
data Persona = Decane
            | Docente Cargo
            | NoDocente Area
            | Estudiante Carrera Ingreso
            deriving Show

{-
3. b) ¿Cuál es el tipo del constructor Docente?

Docente :: Cargo -> Persona
-}

{-
3. c) Programá la función cuantos_doc :: [Persona] -> Cargo -> Int que dada una
lista de personas xs, y un cargo c, devuelve la cantidad de docentes incluidos en xs
que poseen el cargo c
-}

es_doc :: Cargo -> Persona -> Bool
es_doc Titular (Docente Titular) = True
es_doc Asociado (Docente Asociado) = True
es_doc Adjunto (Docente Adjunto) = True
es_doc Asistente (Docente Asistente) = True
es_doc Auxiliar (Docente Auxiliar) = True
es_doc _ _ = False

cuantos_doc :: [Persona] -> Cargo -> Int
cuantos_doc [] _ = 0 
cuantos_doc (x:xs) c
    | es_doc c x = 1 + cuantos_doc xs c
    | otherwise = cuantos_doc xs c 

{-
3. d) ¿La función anterior usa filter? Si no es así, reprogramala para usarla.
-}

cuantos_doc' :: [Persona] -> Cargo -> Int
cuantos_doc' xs c = length (filter (es_doc c) xs)

{-
4. a) Definir la función primerElemento que devuelve el primer elemento de una lista no
vacía, o Nothing si la lista es vacía.
-}

primerElemento :: [a] -> Maybe a
primerElemento [] = Nothing
primerElemento (x:_) = Just x

{-
5.a.1) atender :: Cola -> Maybe Cola, que elimina de la cola a la persona que está
en la primer posición de una cola, por haber sido atendida. Si la cola está vacía,
devuelve Nothing.
-}

data Cola = VaciaC | Encolada Persona Cola deriving Show

testCola :: Cola -- Cola para probar funciones
testCola = Encolada Decane (Encolada (Estudiante Computacion 2020)(Encolada (NoDocente Postgrado) (Encolada (Docente Titular) VaciaC)))

atender :: Cola -> Maybe Cola
atender VaciaC = Nothing
atender (Encolada _ cola) = Just cola

{-
5.a.2) encolar :: Persona -> Cola -> Cola, que agrega una persona a una cola de
personas, en la última posici´on.
-}

encolar :: Persona -> Cola -> Cola
encolar persona VaciaC = Encolada persona VaciaC 
encolar persona (Encolada persona2 cola) = Encolada persona2 (encolar persona cola)

{-
5.a.3) busca :: Cola -> Cargo -> Maybe Persona, que devuelve el primer docente
dentro de la cola que tiene un cargo que se corresponde con el segundo parámetro.
Si esa persona no existe, devuelve Nothing.
-}

sonIgualesCargo :: Cargo -> Cargo -> Bool
sonIgualesCargo Titular Titular = True
sonIgualesCargo Asociado Asociado = True
sonIgualesCargo Adjunto Adjunto = True 
sonIgualesCargo Asistente Asistente = True
sonIgualesCargo Auxiliar Auxiliar = True
sonIgualesCargo _ _ = False

busca :: Cola -> Cargo -> Maybe Persona
busca VaciaC _ = Nothing
busca (Encolada (Docente c) cola) cargo
    | sonIgualesCargo c cargo = Just (Docente c)
    | otherwise = busca cola cargo
busca (Encolada _ cola) cargo = busca cola cargo


{-
5.b) A qué otro tipo se parece Cola?.
Cola se parece al tipo lista, pero está más limitado en lo que puede formar parte de ella.
-}

data ListaAsoc a b = Vacia | Nodo a b (ListaAsoc a b) deriving Show

type Diccionario = ListaAsoc String String
type Padron = ListaAsoc Int String

{-
6. a) ¿Como se debe instanciar el tipo ListaAsoc para representar la información almacenada
en una guía telefónica?
-}

-- String = Nombre de la persona, Int = Numero de telefono de la persona
type GuiaTelefonica = ListaAsoc String Int

{-
6.b.1) Programar la función la_long :: ListaAsoc a b -> Int que devuelve la cantidad de datos en una lista.
-}

-- Padrones para probar funciones
testPadron :: Padron
testPadron = Nodo 42351432 "Esc 34" (Nodo 34764504 "Esc 27" (Nodo 43542187 "Esc 66" Vacia))

testPadron' :: Padron
testPadron' = Nodo 29324967 "Esc 88" (Nodo 38876093 "Esc 28" (Nodo 43554298 "Esc 66" Vacia))

la_long :: ListaAsoc a b -> Int
la_long Vacia = 0
la_long (Nodo _ _ lista) = 1 + la_long lista

{-
6.b.2) la_concat :: ListaAsoc a b -> ListaAsoc a b -> ListaAsoc a b que devuelve la concatenación de dos listas de asociación.
-}

la_concat :: ListaAsoc a b -> ListaAsoc a b -> ListaAsoc a b
la_concat la1 Vacia = la1
la_concat Vacia la2 = la2
la_concat (Nodo a b (la1)) la2 = Nodo a b (la_concat la1 la2)

{-
6.b.3) la_pares :: ListaAsoc a b -> [(a, b)] que transforma una lista de asociación en una lista de pares clave-dato.
-}

la_pares :: ListaAsoc a b -> [(a,b)]
la_pares Vacia = []
la_pares (Nodo a b la) = (a,b) : la_pares la

{-
6.b.4) la_busca :: Eq a => ListaAsoc a b -> a -> Maybe b que dada una lista
y una clave devuelve el dato asociado, si es que existe. En caso contrario devuelve Nothing.
-}

la_busca :: Eq a => ListaAsoc a b -> a -> Maybe b
la_busca Vacia _ = Nothing
la_busca (Nodo a b la) clave
    | a == clave = Just b
    |otherwise = la_busca la clave

{-
5) la_borrar :: Eq a => a -> ListaAsoc a b -> ListaAsoc a b que dada una clave a elimina la entrada en la lista.
-}

la_borrar :: Eq a => a -> ListaAsoc a b -> ListaAsoc a b
la_borrar _ Vacia = Vacia
la_borrar clave (Nodo a b la)
    | clave == a = la_borrar clave la
    | otherwise = Nodo a b (la_borrar clave la)

{-
7.a) a_long :: Arbol a -> Int que dado un arbol devuelve la cantidad de datos almacenados.
-}

data Arbol a = Hoja | Rama (Arbol a ) a (Arbol a) deriving Show
type Prefijos = Arbol String

can, cana, canario, canas, cant, cantar, canto :: Prefijos
can = Rama cana "can" cant
cana = Rama canario "a" canas
canario = Rama Hoja "rio" Hoja
canas = Rama Hoja "s" Hoja
cant = Rama cantar "t" canto
cantar = Rama Hoja "ar" Hoja
canto = Rama Hoja "o" Hoja

-- Arbol para probar funciones
r1, r2, r3, r4, r5, r6, r7 :: Arbol Int 
r7 = Rama r5 10 r6
r6 = Rama r3 7 r4
r5 = Rama r1 3 r2
r4 = Rama Hoja 4 Hoja
r3 = Rama Hoja 3 Hoja
r2 = Rama Hoja 2 Hoja
r1 = Rama Hoja 1 Hoja

a_long :: Arbol a -> Int
a_long Hoja = 0
a_long (Rama arbolIzq _ arbolDer) = 1 + a_long arbolIzq + a_long arbolDer

{-
7.b) a_hojas :: Arbol a -> Int que dado un árbol devuelve la cantidad de hojas.
-}

a_hojas :: Arbol a -> Int
a_hojas Hoja = 1
a_hojas (Rama arbolIzq _ arbolDer) = a_hojas arbolIzq + a_hojas arbolDer

{-
a_inc :: Num a => Arbol a -> Arbol a que dado un árbol que contiene números, los incrementa en uno.
-}

a_inc :: Num a => Arbol a -> Arbol a
a_inc Hoja = Hoja
a_inc (Rama arbolIzq x arbolDer) = Rama (a_inc arbolIzq) (x + 1) (a_inc arbolDer)

{-
a_map :: (a -> b) -> Arbol a -> Arbol b que dada una función y un árbol,
devuelve el árbol con la misma estructura, que resulta de aplicar la función a cada uno
de los elementos del árbol. Revisa la definición de la función anterior y reprogramala
usando a_map.
-}

a_map :: (a -> b) -> Arbol a -> Arbol b
a_map _ Hoja = Hoja
a_map f (Rama arbolIzq x arbolDer) = Rama (a_map f arbolIzq) (f x) (a_map f arbolDer)

a_inc' :: Num a => Arbol a -> Arbol a
a_inc' arbol = a_map (+1) arbol
