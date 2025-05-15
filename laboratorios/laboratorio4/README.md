# Laboratorio 4: Patrones de diseño en entrevistas técnicas <!-- omit from toc -->

<details> 
  <summary>Tabla de contenidos</summary>

- [Pregunta 1](#pregunta-1)
  - [Descripción del problema](#descripción-del-problema)
  - [Patrón de diseño seleccionado](#patrón-de-diseño-seleccionado)
  - [Justificación del patrón](#justificación-del-patrón)
  - [Pseudocódigo de implementación](#pseudocódigo-de-implementación)
- [Pregunta 2](#pregunta-2)
  - [Descripción del problema](#descripción-del-problema-1)
  - [Patrón de diseño seleccionado](#patrón-de-diseño-seleccionado-1)
  - [Justificación del patrón](#justificación-del-patrón-1)
  - [Pseudocódigo de implementación](#pseudocódigo-de-implementación-1)
- [Pregunta 3](#pregunta-3)
  - [Descripción del problema](#descripción-del-problema-2)
  - [Patrón de diseño seleccionado](#patrón-de-diseño-seleccionado-2)
  - [Justificación del patrón](#justificación-del-patrón-2)
  - [Pseudocódigo de implementación](#pseudocódigo-de-implementación-2)
- [Reflexión final: ¿Qué aprendieron sobre el uso real de patrones de diseño?](#reflexión-final-qué-aprendieron-sobre-el-uso-real-de-patrones-de-diseño)

</details> 

En este laboratorio del curso IE-0417 Diseño de software para Ingeniería, se analizan 3 preguntas de entrevistas técnicas relacionadas a los patrones de diseño de software vistos en el curso.

Para cada una de las preguntas, se cubren los siguientes aspectos:

- Descripción del problema.
- Patrón de diseño más adecuado.
- Justificación de la escogencia del patrón.
- Implementación sencilla del patrón.

## Pregunta 1

La primera pregunta de entrevistas técnicas fue seleccionada de LeetCode Discussion titulada [_Design Amazon Locker system_](https://leetcode.com/discuss/post/233869/design-amazon-locker-system-by-anonymous-lgpn/) y fue publicada el 8 de febrero del 2019.
Es una discusión popular con cerca de 43 000 visualizaciones al momento de la redacción del documento.

### Descripción del problema

El enunciado de la pregunta consiste en la siguiente:

> Se desea implementar un sistema que administre una red de lockers inteligentes utilizados para la entrega de paquetes.
> El sistema debe permitir a los repartidores asignar paquetes al locker más apropiado (por cercanía, tamaño, disponibilidad) y permitir a los usuarios retirar sus paquetes mediante un código.

### Patrón de diseño seleccionado

Por la naturaleza del problema, se decidió seleccionar los patrones de diseño a continuación:

- **Patrón creacional Singleton**: Para garantizar una única instancia del sistema que administre los lockers.
- **Patrón conductual Strategy**: Para utilizar diferentes algoritmos de asignación de lockers.
- **Patrón creacional Factory Method**: Para instanciar distintos tipos de lockers o paquetes.

### Justificación del patrón

Singleton asegura consistencia al tener una única instancia que coordine todo el sistema de asignación de lockers.

Strategy permite cambiar la política de asignación sin modificar el sistema principal, lo cual es importante para el diseño de un sistema escalable y fácil de mantener.

Factory facilita la creación de lockers y paquetes manejados como objetos.

### Pseudocódigo de implementación

```python
class Locker:
    def __init__(self, id, size, location, available=True):
        self.id = id
        self.size = size
        self.location = location
        self.available = available
```

La clase `Locker` representa un locker físico, con sus atributos relevantes.
Se debe verificar si está disponible y si tiene tamaño suficiente para un paquete en la implementación real.

```python
class AllocationStrategy:
    def assign_locker(self, package, lockers):
        raise NotImplementedError
```

`AllocationStrategy` permite tener una interfaz abstracta del patrón Strategy que define cómo asignar lockers.

```python
class NearestLockerStrategy(AllocationStrategy):
    def assign_locker(self, package, lockers):
        return min(
            (l for l in lockers if l.available and l.size >= package.size),
            key=lambda l: l.location.distance_to(package.destination)
        )
```

Ahora, la clase `NearestLockerStrategy` implementa la estrategia concreta de asignación por proximidad.
Utiliza un filtro para lockers disponibles y selecciona el más cercano.

De esta forma, se crean todos los métodos que se deseen para asignar los lockers.

```python
class LockerSystem:
    _instance = None

    @staticmethod
    def get_instance():
        if LockerSystem._instance is None:
            LockerSystem._instance = LockerSystem()
        return LockerSystem._instance

    def __init__(self):
        self.lockers = []
        self.strategy = NearestLockerStrategy()

    def assign_locker(self, package):
        return self.strategy.assign_locker(package, self.lockers)
```

`LockerSystem` aplica el patrón Singleton.
La estrategia de asignación se puede cambiar de forma dinámica si se quiere usar otra lógica.
El método `assign_locker` delega la lógica a la estrategia seleccionada.

## Pregunta 2

La segunda pregunta de entrevistas técnicas fue seleccionada nuevamente de LeetCode Discussion. Esta se titula [_Tekion Corp Software Engineer II Jan 2025_](https://leetcode.com/discuss/post/233869/design-amazon-locker-system-by-anonymous-lgpn/) y fue publicada el 22 de enero del 2025.
En la discusión se explica que esta pregunta apareció en una entrevista de trabajo de diseño de bajo nivel.

### Descripción del problema

Se desea diseñar una máquina expendedora que funcione a través de múltiples estados:

1) Esperando moneda
2) Selección de producto
3) Entrega
4) Reinicio

El comportamiento debe cambiar dependiendo del estado interno sin recurrir a estructuras condicionales complejas.

### Patrón de diseño seleccionado

- **Patrón conductual State**: Para encapsular los comportamientos en objetos separados según el estado actual de la máquina.

### Justificación del patrón

El patrón State evita estructuras `if-else` o `switch`, y permite definir un comportamiento diferente según el estado, lo que hace el sistema mantenible y escalable.

### Pseudocódigo de implementación

```python
class State:
    def insert_coin(self, machine):
        raise NotImplementedError
    def select_product(self, machine):
        raise NotImplementedError
    def dispense(self, machine):
        raise NotImplementedError
```

Primero, la clase `State` define una interfaz común para todos los estados de la máquina.

```python
class WaitingForCoin(State):
    def insert_coin(self, machine):
        print("Moneda insertada.")
        machine.state = WaitingForSelection()
```

Luego, `WaitingForCoin` define el comportamiento en el estado inicial: al insertar moneda, cambia al siguiente estado.

```python
class WaitingForSelection(State):
    def select_product(self, machine):
        print("Producto seleccionado.")
        machine.state = Dispensing()
```

El siguiente estado corresponde a la clase `WaitingForSelection`, el cual permite seleccionar el producto una vez que se insertó moneda.
Al terminar la selección, se cambia al siguiente estado.

```python
class Dispensing(State):
    def dispense(self, machine):
        print("Producto entregado.")
        machine.state = WaitingForCoin()
```

Finalmente, `Dispensing` entrega el producto y reinicia el ciclo.

```python
class VendingMachine:
    def __init__(self):
        self.state = WaitingForCoin()

    def insert_coin(self):
        self.state.insert_coin(self)

    def select_product(self):
        self.state.select_product(self)

    def dispense(self):
        self.state.dispense(self)
```

La clase principal maneja su comportamiento a través del objeto `state`, que encapsula la lógica según el estado actual.

## Pregunta 3

Como tercera pregunta, se seleccionó la pregunta de LeetCode Discussion titulada [_Design push notification_](https://leetcode.com/discuss/post/125121/design-push-notification-by-sabeer6870-o1in/), la cual fue publicada el 4 de agosto del 2017 en la página.

### Descripción del problema

El enunciado del presente problema consiste en:

> Diseñar un sistema de notificaciones que pueda enviar mensajes por múltiples canales (correo, SMS, push), de forma flexible y extensible.
> El sistema debe permitir añadir o quitar canales dinámicamente, sin modificar la lógica de notificación.

### Patrón de diseño seleccionado

- **Patrón conductual Observer**: Para notificar a múltiples observadores registrados (canales).
- **Patrón estructural Bridge**: Para desacoplar la lógica de envío de la lógica de plataforma.

### Justificación del patrón

Por un lado, Observer permite enviar mensajes a múltiples receptores sin saber la cantidad de ellos.
Por otro lado, Bridge desacopla o divide la notificación de la entrega del mensaje.

### Pseudocódigo de implementación

```python
class NotificationChannel:
    def send(self, message):
        raise NotImplementedError
```

La clase `NotificationChannel` corresponde a la interfaz que representa cualquier canal de notificación.

```python
class EmailNotifier(NotificationChannel):
    def send(self, message):
        print("Correo enviado:", message)

class SMSNotifier(NotificationChannel):
    def send(self, message):
        print("SMS enviado:", message)
```

`EmailNotifier` y `SMSNotifier` consisten en implementaciones específicas para distintos canales, a modo de ejemplo.

```python
class NotificationService:
    def __init__(self):
        self.subscribers = []

    def register(self, channel):
        self.subscribers.append(channel)

    def unregister(self, channel):
        self.subscribers.remove(channel)

    def notify_all(self, message):
        for subscriber in self.subscribers:
            subscriber.send(message)
```

Aplica el patrón Observer, puesto que los canales son los observadores.
Asimismo, el método `notify_all` envía los mensajes a los suscriptores por medio de los distintos medios (sin saber cuáles son).

## Reflexión final: ¿Qué aprendieron sobre el uso real de patrones de diseño?

A través del desarrollo del presente laboratorio, se logró una comprensión más profunda y detallada los patrones de diseño en la resolución de problemas comunes en el desarrollo de software.

En el primer caso, el patrón **Strategy** demostró su utilidad al permitir la selección dinámica de algoritmos de asignación en un sistema de lockers inteligentes.
Esta separación de la lógica algorítmica del sistema principal evidenció cómo los patrones pueden mejorar la flexibilidad y facilitar cambios futuros sin necesidad de modificar la estructura central del código.

Por su parte, el patrón **State**, aplicado en el diseño de una máquina expendedora, permitió modelar el comportamiento del sistema en función de su estado interno.
A diferencia de enfoques basados en condicionales extensos, este patrón proporcionó una estructura más clara, escalable y orientada al mantenimiento a largo plazo.

En el tercer escenario, el patrón **Observer** permitió construir un sistema de notificaciones push extensible y desacoplado, donde múltiples canales pueden recibir actualizaciones sin que el emisor conozca sus detalles.
Adicionalmente, el patrón **Bridge** facilitó la separación entre la lógica y los mecanismos de entrega, lo cual favorece un diseño modular.

En conjunto, estos ejercicios evidenciaron que los patrones de diseño no constituyen únicamente soluciones teóricas, sino herramientas prácticas que mejoran la calidad, escalabilidad y mantenibilidad del software.
Sin embargo, es importante considerar que los patrones de diseño tampoco son soluciones definitivas a todos los problemas de software.
Son adecuados en ciertos escenarios, pero tampoco hay que caer en el vacío de buscar el mejor patrón de diseño para todas las implementaciones que se realicen a un programa.

