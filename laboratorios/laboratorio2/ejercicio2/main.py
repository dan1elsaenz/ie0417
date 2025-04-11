"""
main.py
=======

Este archivo permite la interacción con el usuario para gestionar proyectos y tareas desde la consola.
Utiliza las clases `Proyecto` y `Tarea` para crear una aplicación de línea de comandos que permite:

- Crear tareas nuevas.
- Ver todas las tareas creadas.
- Marcar tareas como completadas.
- Ver tareas vencidas.
- Ver tareas pendientes.
- Salir del sistema.

Este módulo está pensado como el punto de entrada del programa.
"""

from proyecto import Proyecto
from tarea import Tarea

def mostrar_menu() -> None:
    """
    Muestra en consola las opciones disponibles para el usuario.

    Este menú es mostrado en cada iteración del ciclo principal.

    :return: None
    """
    print("\n--- Gestor de Tareas Personales ---")
    print("1. Crear nueva tarea")
    print("2. Ver todas las tareas")
    print("3. Marcar tarea como completada")
    print("4. Ver tareas vencidas")
    print("5. Ver tareas pendientes")
    print("6. Salir")

def main() -> None:
    """
    Función principal que ejecuta el menú interactivo.

    Crea un proyecto vacío, muestra el menú de opciones y permite al usuario
    gestionar las tareas. La interacción se realiza a través de entradas por consola.

    El bucle principal se ejecuta hasta que el usuario selecciona la opción de salir.

    :return: None
    """
    proyecto = Proyecto("Mi Proyecto Personal")

    while True:
        mostrar_menu()
        opcion = input("Seleccione una opción: ")

        if opcion == "1":
            titulo = input("Título: ")
            descripcion = input("Descripción: ")
            fecha_limite = input("Fecha límite (YYYY-MM-DD): ")
            tarea = Tarea(titulo, descripcion, fecha_limite)
            proyecto.agregar_tarea(tarea)
            print("Tarea agregada exitosamente.")

        elif opcion == "2":
            tareas = proyecto.listar_tareas()
            if tareas:
                for t in tareas:
                    print(t)
            else:
                print("No hay tareas registradas.")

        elif opcion == "3":
            titulo = input("Ingrese el título de la tarea a marcar como completada: ")
            tarea = proyecto.buscar_tarea(titulo)
            if tarea:
                tarea.marcar_completada()
                print("Tarea marcada como completada.")
            else:
                print("Tarea no encontrada.")

        elif opcion == "4":
            vencidas = proyecto.tareas_vencidas()
            if vencidas:
                print("Tareas vencidas:")
                for t in vencidas:
                    print(t)
            else:
                print("No hay tareas vencidas.")

        elif opcion == "5":
            pendientes = proyecto.tareas_pendientes()
            if pendientes:
                print("Tareas pendientes:")
                for t in pendientes:
                    print(t)
            else:
                print("No hay tareas pendientes.")

        elif opcion == "6":
            print("Saliendo del programa...")
            break

        else:
            print("Opción inválida. Intente de nuevo.")

if __name__ == "__main__":
    main()
