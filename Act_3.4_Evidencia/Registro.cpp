#include "Registro.h" 

// Constructores
Registro::Registro()
{
    this->razon = "";
}

Registro::Registro(Ip ip) 
{
    this->ip = ip;
    this->razon = "";
}

Registro::Registro(Fecha fecha, Ip ip, std::string razon) 
{
    this->fecha = fecha;
    this->ip = ip;
    this->razon = razon;
}

// Getters
Fecha Registro::getFecha() 
{
    return this->fecha;
}

Ip Registro::getIp() 
{
    return this->ip;
}

std::string Registro::getRazon() 
{
    return this->razon;
}

// Setters
void Registro::setFecha(Fecha fecha) 
{
    this->fecha = fecha;
}

void Registro::setIp(Ip ip) 
{
    this->ip = ip;
}

void Registro::setRazon(std::string razon) 
{
    this->razon = razon;
}

// Sobrecargas
// Sobrecarga de operador de flujo de entrada
std::istream &operator>>(std::istream &entrada, Registro &registro) 
{
    entrada >> registro.fecha;
    entrada.ignore(1);
    entrada >> registro.ip;
    getline(entrada, registro.razon, '\n');
    return entrada;
}

// Sobrecarga de operador de flujo de salida
std::ostream &operator<<(std::ostream &salida, const Registro &registro) {
    salida << registro.fecha << " " << registro.ip << " " << registro.razon;
    return salida;
}

// Se puede cambiar por ip o fecha

// Sobrecarga del operador booleano < como funcion de la clase (función miembro)
bool Registro::operator<(const Registro &registro) const 
{
    return this->ip < registro.ip;
}

// Sobrecarga del operador booleano <= como funcion de la clase
bool Registro::operator<=(const Registro &registro) const 
{
    return this->ip <= registro.ip;
}

// Sobrecarga del operador booleano == como funcion de la clase
bool Registro::operator==(const Registro &registro) const 
{
    return this->ip == registro.ip;
}
