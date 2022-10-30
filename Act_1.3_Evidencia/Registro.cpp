#include "Registro.h"
#include <map>

// Constructores
Registro::Registro() {
    this->ip = "";
    this->razon = "";
}

Registro::Registro(Fecha fecha) {
    this->fecha = fecha;
    this->ip = "";
    this->razon = "";
}

Registro::Registro(Fecha fecha, std::string ip, std::string razon) {
    this->fecha = fecha;
    this->ip = ip;
    this->razon = razon;
}

// Getters
Fecha Registro::getFecha() {
    return this->fecha;
}

std::string Registro::getIp() {
    return this->ip;
}

std::string Registro::getRazon() {
    return this->razon;
}

// Setters
void Registro::setFecha(Fecha fecha) {
    this->fecha = fecha;
}

void Registro::setIp(std::string ip) {
    this->ip = ip;
}

void Registro::setRazon(std::string razon) {
    this->razon = razon;
}

// Sobrecargas

// Sobrecarga de operador de flujo de entrada
std::istream &operator>>(std::istream &entrada, Registro &registro) {
    entrada >> registro.fecha >> registro.ip;
    entrada.ignore(1);
    getline(entrada, registro.razon);
    registro.setFecha(registro.fecha);
    registro.setIp(registro.ip);
    registro.setRazon(registro.razon);
    return entrada;
}

// Sobrecarga de operador de flujo de salida
std::ostream &operator<<(std::ostream &salida, const Registro &registro) {
    salida << registro.fecha << " " << registro.ip << " " << registro.razon;
    return salida;
}

// Sobrecarga del operador booleano < como funcion de la clase (función miembro)
bool Registro::operator<(const Registro &registro) const {
    return this->fecha < registro.fecha;
}

// Sobrecarga del operador booleano <= como funcion de la clase
bool Registro::operator<=(const Registro &registro) const {
    return this->fecha <= registro.fecha;
}
