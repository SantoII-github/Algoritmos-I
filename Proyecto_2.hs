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
