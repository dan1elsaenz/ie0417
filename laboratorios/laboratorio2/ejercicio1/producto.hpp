// @file producto.hpp
// @brief Definición de la clase Producto para el sistema de inventario.

#ifndef PRODUCTO_HPP
#define PRODUCTO_HPP

#include <string>

/**
 * @class Producto
 * @brief Representa un producto en el inventario.
 */
class Producto {
private:
    int id; ///< ID único del producto
    std::string nombre; ///< Nombre del producto
    std::string categoria; ///< Categoría a la que pertenece el producto
    int cantidad; ///< Cantidad disponible en inventario
    double precio; ///< Precio unitario del producto

public:
    /**
     * @brief Constructor por defecto.
     */
    Producto();

    /**
     * @brief Constructor con parámetros.
     * @param id ID del producto.
     * @param nombre Nombre del producto.
     * @param categoria Categoría del producto.
     * @param cantidad Cantidad en inventario.
     * @param precio Precio por unidad.
     */
    Producto(int id, const std::string& nombre, const std::string& categoria, int cantidad, double precio);

    /// @brief Obtiene el ID del producto.
    int getId() const;

    /// @brief Obtiene el nombre del producto.
    std::string getNombre() const;

    /// @brief Obtiene la categoría del producto.
    std::string getCategoria() const;

    /// @brief Obtiene la cantidad disponible.
    int getCantidad() const;

    /// @brief Obtiene el precio del producto.
    double getPrecio() const;

    /// @brief Modifica la cantidad del producto.
    /// @param nuevaCantidad Nueva cantidad disponible.
    void setCantidad(int nuevaCantidad);

    /// @brief Representación en string del producto.
    /// @return Una cadena que representa al producto.
    std::string toString() const;
};

#endif // PRODUCTO_HPP
