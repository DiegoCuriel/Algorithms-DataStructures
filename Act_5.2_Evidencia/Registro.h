#ifndef REGISTRO_H
#define REGISTRO_H
#include "Fecha.h"
#include "Ip.h"
#include <iostream>
#include <string>

class Registro 
{
    public:
        // Constructores
        Registro();
        Registro(Ip ip);
        Registro(Fecha fecha, Ip ip, std::string razon);

        // Getters
        Fecha getFecha();
        Ip getIp();
        std::string getRazon();

        // Setters
        void setFecha(Fecha fecha);
        void setIp(Ip ip);
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
        // Sobrecarga del operador booleano == como funcion de la clase
        bool operator==(const Registro &) const;
    private:
        Fecha fecha;
        Ip ip;
        std::string razon;
};

#endif // REGISTRO_H
