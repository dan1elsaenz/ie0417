# Usa una imagen oficial de Python
FROM python:3.11-slim

# Establece el directorio de trabajo
WORKDIR /app

# Copia los archivos
COPY requirements.txt .

# Instala dependencias
RUN pip install --no-cache-dir -r requirements.txt

# Copia el resto del proyecto
COPY . .

# Expone el puerto 8000 (usado con Django)
EXPOSE 8000

# Comando para ejecutar las migraciones automáticamente y levantar el contenedor
CMD ["python", "start.py"]
