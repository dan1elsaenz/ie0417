from django.db import models


class Nota(models.Model):
    """Modelo de nota básica"""
    titulo = models.CharField(max_length=100)
    contenido = models.TextField()

    def __str__(self):
        return self.titulo
