// @file inventario.cpp
// @brief Implementación de la clase Inventario.

#include "inventario.hpp"
#include <iostream>

void Inventario::agregarProducto(const Producto& producto) {
    productos.push_back(producto);
}

bool Inventario::eliminarProducto(int id) {
    for (auto it = productos.begin(); it != productos.end(); ++it) {
        if (it->getId() == id) {
            productos.erase(it);
            return true;
        }
    }
    return false;
}

void Inventario::mostrarProductos() const {
    if (productos.empty()) {
        std::cout << "El inventario está vacío.\n";
        return;
    }
    for (const auto& producto : productos) {
        std::cout << producto.toString() << std::endl;
    }
}

void Inventario::buscarPorCategoria(const std::string& categoria) const {
    bool encontrado = false;
    for (const auto& producto : productos) {
        if (producto.getCategoria() == categoria) {
            std::cout << producto.toString() << std::endl;
            encontrado = true;
        }
    }
    if (!encontrado) {
        std::cout << "No se encontraron productos en la categoría: " << categoria << std::endl;
    }
}

bool Inventario::actualizarCantidad(int id, int nuevaCantidad) {
    for (auto& producto : productos) {
        if (producto.getId() == id) {
            producto.setCantidad(nuevaCantidad);
            return true;
        }
    }
    return false;
}
