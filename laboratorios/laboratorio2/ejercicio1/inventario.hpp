// @file inventario.hpp
// @brief Definición de la clase Inventario que gestiona múltiples productos.

#ifndef INVENTARIO_HPP
#define INVENTARIO_HPP

#include "producto.hpp"
#include <vector>
#include <string>

/**
 * @class Inventario
 * @brief Administra una colección de productos en memoria.
 */
class Inventario {
private:
    std::vector<Producto> productos; ///< Lista de productos disponibles

public:
    /**
     * @brief Agrega un producto al inventario.
     * @param producto Objeto Producto a agregar.
     */
    void agregarProducto(const Producto& producto);

    /**
     * @brief Elimina un producto por ID.
     * @param id ID del producto a eliminar.
     * @return true si se eliminó correctamente, false si no se encontró.
     */
    bool eliminarProducto(int id);

    /**
     * @brief Muestra todos los productos del inventario.
     */
    void mostrarProductos() const;

    /**
     * @brief Busca productos por categoría.
     * @param categoria Categoría a buscar.
     */
    void buscarPorCategoria(const std::string& categoria) const;

    /**
     * @brief Actualiza la cantidad de un producto.
     * @param id ID del producto.
     * @param nuevaCantidad Nueva cantidad disponible.
     * @return true si se actualizó correctamente, false si no se encontró el producto.
     */
    bool actualizarCantidad(int id, int nuevaCantidad);
};

#endif // INVENTARIO_HPP
