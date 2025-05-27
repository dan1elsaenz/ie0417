import os
import time
import subprocess
import psycopg2
from psycopg2 import OperationalError

def wait_for_db():
    print("Esperando a que la base de datos esté lista...")
    while True:
        try:
            conn = psycopg2.connect(
                dbname=os.environ["POSTGRES_DB"],
                user=os.environ["POSTGRES_USER"],
                password=os.environ["POSTGRES_PASSWORD"],
                host=os.environ["DB_HOST"],
                port=os.environ["DB_PORT"],
            )
            conn.close()
            print("Base de datos lista.")
            break
        except OperationalError:
            print("Base de datos no disponible, esperando 1 segundo...")
            time.sleep(1)

def main():
    wait_for_db()
    print("Ejecutando migraciones...")
    subprocess.run(["python", "manage.py", "makemigrations"], check=True)
    subprocess.run(["python", "manage.py", "migrate"], check=True)
    print("Levantando el servidor...")
    subprocess.run(["python", "manage.py", "runserver", "0.0.0.0:8000"])

if __name__ == "__main__":
    main()
