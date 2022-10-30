#include "Fecha.h"
#include <map>

// Constructores
Fecha::Fecha() {
    this->mes = "";
    this->dia = "";
    this->hora = "";
}

Fecha::Fecha(std::string mes, std::string dia, std::string hora) {
    this->mes = mes;
    this->dia = dia;
    this->hora = hora;
}

// Getters
std::string Fecha::getMes() {
    return this->mes;
}

std::string Fecha::getDia() {
    return this->dia;
}

std::string Fecha::getHora() {
    return this->hora;
}

// Setters
void Fecha::setMes(std::string mes) {
    this->mes = mes;
}

void Fecha::setDia(std::string dia) {
    this->dia = dia;
}

void Fecha::setHora(std::string hora) {
    this->hora = hora;
}

// Sobrecargas

// Sobrecarga de operador de flujo de entrada
std::istream &operator>>(std::istream &entrada, Fecha &fecha) {
    entrada >> fecha.mes >> fecha.dia >> fecha.hora;
    fecha.setMes(fecha.mes);
    fecha.setDia(fecha.dia);
    fecha.setHora(fecha.hora);
    return entrada;
}

// Sobrecarga de operador de flujo de salida
std::ostream &operator<<(std::ostream &salida, const Fecha &fecha) {
    salida << fecha.mes << " " << fecha.dia << " " << fecha.hora;
    return salida;
}

// Sobrecarga del operador booleano < como funcion de la clase (función miembro)
bool Fecha::operator<(const Fecha &fecha) const {
    std::map<std::string, int> meses {{"Jan", 1}, {"Feb", 2}, {"Mar", 3}, 
            {"Apr", 4}, {"May", 5}, {"Jun", 6}, {"Jul", 7}, {"Aug", 8}, 
            {"Sep", 9}, {"Oct", 10}, {"Nov", 11}, {"Dec", 12}};

    return std::make_tuple(meses[this->mes], stoi(this->dia), this->hora) <
           std::make_tuple(meses[fecha.mes], stoi(fecha.dia), fecha.hora);
}

// Sobrecarga del operador booleano <= como funcion de la clase
bool Fecha::operator<=(const Fecha &fecha) const {
    std::map<std::string, int> meses {{"Jan", 1}, {"Feb", 2}, {"Mar", 3}, 
            {"Apr", 4}, {"May", 5}, {"Jun", 6}, {"Jul", 7}, {"Aug", 8}, 
            {"Sep", 9}, {"Oct", 10}, {"Nov", 11}, {"Dec", 12}};

    return std::make_tuple(meses[this->mes], stoi(this->dia), this->hora) <=
           std::make_tuple(meses[fecha.mes], stoi(fecha.dia), fecha.hora);
}
