#ifndef REGISTRO_H
#define REGISTRO_H
#include <iostream>
#include <string>
#include "Fecha.h"

class Registro {
public:
        // Constructores
        Registro();
        Registro(Fecha);
        Registro(Fecha fecha, std::string ip, std::string razon);

        // Getters
        Fecha getFecha();
        std::string getIp();
        std::string getRazon();

        // Setters
        void setFecha(Fecha fecha);
        void setIp(std::string ip);
        void setRazon(std::string razon);

        // Sobrecargas
        // Sobrecarga de de operador de flujo de entrada
        friend std::istream &operator>>(std::istream &, Registro &);
        // Sobrecarga de operador de flujo de salida
        friend std::ostream &operator<<(std::ostream &, const Registro &);
        // Sobrecarga del operador booleano < como funcion de la clase
        bool operator<(const Registro &) const;
        // Sobrecarga del operador booleano <= como funcion de la clase
        bool operator<=(const Registro &) const;

    private:
        Fecha fecha;
        std::string ip;
        std::string razon;
};

#endif // REGISTRO_H
