
import re # Verificación de patrón `- **Palabra**: Definición`
import unicodedata # Ignorar tildes

def removerTildes(texto):
    return ''.join(
        c for c in unicodedata.normalize('NFD', texto)
        if unicodedata.category(c) != 'Mn'
    )

def ordenarDefiniciones(nombre_archivo):
    with open(nombre_archivo, 'r', encoding='utf-8') as archivo:
        lineas = archivo.readlines()

    definiciones = [] # Guardar (palabra, definicion)
    patron = re.compile(r"^- \*\*(.*?)\*\*: (.+)") # Patrón `- **Palabra**: Definición`

    # Separar encabezado (4 primeras líneas) y contenido con definiciones
    encabezado = lineas[:4]
    contenido = lineas[4:]

    for linea in contenido:
        # Buscar coincidencias en las líneas
        coincidencia = patron.match(linea.strip())

        if coincidencia:
            concepto = coincidencia.group(1).strip()
            definicion = coincidencia.group(2).strip()
            definiciones.append((concepto, definicion))

    # Ordenar ignorando tildes y mayúsculas basado en la palabra
    definiciones.sort(key=lambda x: removerTildes(x[0].lower()))

    with open(nombre_archivo, 'w', encoding='utf-8') as archivo:
        archivo.writelines(encabezado) # Escribir encabezado

        # Escribir definiciones
        for concepto, definicion in definiciones:
            archivo.write(f"- **{concepto}**: {definicion}\n\n")

    print(f"Archivo '{nombre_archivo}' ordenado alfabéticamente.")

ordenarDefiniciones("README.md")
