"""
tarea.py
========

Este módulo define la clase Tarea para el gestor personal de tareas.
Una tarea contiene un título, una descripción, una fecha límite y un estado de finalización.

Las tareas se pueden marcar como completadas y verificar si están vencidas en relación a la fecha actual.
Este módulo es utilizado por otros componentes del sistema como el módulo `proyecto`.
"""
from datetime import datetime

class Tarea:
    """
    Representa una tarea dentro de un proyecto personal.

    :param titulo: Título de la tarea
    :type titulo: str
    :param descripcion: Descripción de la tarea
    :type descripcion: str
    :param fecha_limite: Fecha límite para la tarea en formato YYYY-MM-DD
    :type fecha_limite: str
    """
    def __init__(self, titulo: str, descripcion: str, fecha_limite: str) -> None:
        """
        Inicializa una nueva instancia de Tarea.

        :param titulo: Título de la tarea
        :param descripcion: Descripción de la tarea
        :param fecha_limite: Fecha límite en formato YYYY-MM-DD
        :return: None
        """
        self.titulo = titulo
        self.descripcion = descripcion
        self.fecha_limite = datetime.strptime(fecha_limite, "%Y-%m-%d")
        self.completada = False

    def marcar_completada(self) -> None:
        """
        Marca la tarea como completada.

        :return: None
        """
        self.completada = True

    def esta_vencida(self) -> bool:
        """
        Verifica si la tarea está vencida.

        :return: True si la tarea está vencida, False en caso contrario
        :rtype: bool
        """
        return not self.completada and datetime.now() > self.fecha_limite

    def __str__(self) -> str:
        """
        Devuelve una representación en string de la tarea.

        :return: Cadena con la información resumida de la tarea
        :rtype: str
        """
        estado = "Completada" if self.completada else "Pendiente"
        return f"{self.titulo} | {self.descripcion} | {estado} | Límite: {self.fecha_limite.date()}"
