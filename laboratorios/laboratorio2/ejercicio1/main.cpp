// @file main.cpp
// @brief Programa principal para interactuar con el sistema de inventario.

#include "inventario.hpp"
#include <iostream>

/**
 * @brief Muestra el menú principal del programa.
 */
void mostrarMenu() {
    std::cout << "\n--- Sistema de Inventario de Ferretería ---\n";
    std::cout << "1. Agregar producto\n";
    std::cout << "2. Eliminar producto\n";
    std::cout << "3. Mostrar todos los productos\n";
    std::cout << "4. Buscar por categoría\n";
    std::cout << "5. Actualizar cantidad\n";
    std::cout << "6. Salir\n";
    std::cout << "Seleccione una opción: ";
}

int main() {
    Inventario inventario;
    int opcion;

    do {
        mostrarMenu();
        std::cin >> opcion;

        switch (opcion) {
            case 1: {
                int id, cantidad;
                double precio;
                std::string nombre, categoria;
                std::cout << "ID: "; std::cin >> id;
                std::cin.ignore();
                std::cout << "Nombre: "; std::getline(std::cin, nombre);
                std::cout << "Categoría: "; std::getline(std::cin, categoria);
                std::cout << "Cantidad: "; std::cin >> cantidad;
                std::cout << "Precio: "; std::cin >> precio;
                inventario.agregarProducto(Producto(id, nombre, categoria, cantidad, precio));
                break;
            }
            case 2: {
                int id;
                std::cout << "Ingrese el ID del producto a eliminar: ";
                std::cin >> id;
                if (inventario.eliminarProducto(id)) {
                    std::cout << "Producto eliminado correctamente.\n";
                } else {
                    std::cout << "Producto no encontrado.\n";
                }
                break;
            }
            case 3:
                inventario.mostrarProductos();
                break;
            case 4: {
                std::string categoria;
                std::cin.ignore();
                std::cout << "Ingrese la categoría a buscar: ";
                std::getline(std::cin, categoria);
                inventario.buscarPorCategoria(categoria);
                break;
            }
            case 5: {
                int id, cantidad;
                std::cout << "ID del producto: ";
                std::cin >> id;
                std::cout << "Nueva cantidad: ";
                std::cin >> cantidad;
                if (inventario.actualizarCantidad(id, cantidad)) {
                    std::cout << "Cantidad actualizada.\n";
                } else {
                    std::cout << "Producto no encontrado.\n";
                }
                break;
            }
            case 6:
                std::cout << "Saliendo del programa.\n";
                break;
            default:
                std::cout << "Opción inválida. Intente de nuevo.\n";
        }
    } while (opcion != 6);

    return 0;
}
