"""
proyecto.py
===========

Este módulo define la clase Proyecto, que agrupa un conjunto de tareas personales.
Permite agregar, listar, buscar y filtrar tareas según su estado de finalización o vencimiento.

Este módulo trabaja en conjunto con `tarea.py`, utilizando la clase Tarea como unidad de organización.
"""
from tarea import Tarea

class Proyecto:
    """
    Representa un proyecto personal que contiene múltiples tareas.

    :param nombre: Nombre del proyecto
    :type nombre: str
    """
    def __init__(self, nombre: str) -> None:
        """
        Inicializa un nuevo proyecto con un nombre y una lista vacía de tareas.

        :param nombre: Nombre del proyecto
        :return: None
        """
        self.nombre = nombre
        self.tareas = []

    def agregar_tarea(self, tarea: Tarea) -> None:
        """
        Agrega una nueva tarea al proyecto.

        :param tarea: Objeto Tarea a agregar
        :return: None
        """
        self.tareas.append(tarea)

    def listar_tareas(self) -> list[str]:
        """
        Lista todas las tareas del proyecto como strings.

        :return: Lista de descripciones de tareas
        :rtype: list[str]
        """
        return [str(t) for t in self.tareas]

    def tareas_pendientes(self) -> list[Tarea]:
        """
        Devuelve una lista de tareas que no han sido completadas.

        :return: Lista de tareas pendientes
        :rtype: list[Tarea]
        """
        return [t for t in self.tareas if not t.completada]

    def tareas_vencidas(self) -> list[Tarea]:
        """
        Devuelve una lista de tareas cuya fecha límite ha pasado y no han sido completadas.

        :return: Lista de tareas vencidas
        :rtype: list[Tarea]
        """
        return [t for t in self.tareas if t.esta_vencida()]

    def buscar_tarea(self, titulo: str) -> Tarea | None:
        """
        Busca una tarea por su título exacto.

        :param titulo: Título de la tarea a buscar
        :return: Tarea correspondiente o None si no se encuentra
        :rtype: Tarea | None
        """
        for t in self.tareas:
            if t.titulo == titulo:
                return t
        return None
