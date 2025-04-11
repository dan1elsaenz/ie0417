// @file producto.cpp
// @brief Implementación de la clase Producto.

#include "producto.hpp"
#include <sstream>

Producto::Producto() : id(0), nombre(""), categoria(""), cantidad(0), precio(0.0) {}

Producto::Producto(int id, const std::string& nombre, const std::string& categoria, int cantidad, double precio)
    : id(id), nombre(nombre), categoria(categoria), cantidad(cantidad), precio(precio) {}

int Producto::getId() const {
    return id;
}

std::string Producto::getNombre() const {
    return nombre;
}

std::string Producto::getCategoria() const {
    return categoria;
}

int Producto::getCantidad() const {
    return cantidad;
}

double Producto::getPrecio() const {
    return precio;
}

void Producto::setCantidad(int nuevaCantidad) {
    cantidad = nuevaCantidad;
}

std::string Producto::toString() const {
    std::ostringstream oss;
    oss << "ID: " << id << ", Nombre: " << nombre << ", Categoría: " << categoria
        << ", Cantidad: " << cantidad << ", Precio: ₡" << precio;
    return oss.str();
} 
