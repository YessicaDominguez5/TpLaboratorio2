#include "Fecha.h"

using namespace std;

void Fecha::EstablecerFechaPorDefecto()
{

   //Fecha Actual

time_t t = time(NULL);


    struct tm *f = localtime(&t); //local time devuelve un struct tm
    //por la documentacion

    //f-> es lo mismo que (*f). (hay que indireccionarlo)
    //ej: _dia = (*f).tm_mday; indirecciona f y accede a tm_mday;

    _dia = f->tm_mday; //vector day of the month[1,31]
    _mes = f->tm_mon+1; //vector month since January[0,11]
    _anio = f->tm_year+1900;//year since 1900 2023-1900 = guarda 123 por eso hay que sumarle 1900


}
bool Fecha::EsBisiesto()
{

    if((_anio % 4 == 0 && _anio % 100 != 0)|| _anio % 400 == 0)
    {

        return true;

    }
    else
    {
        return false;
    }

}

Fecha::Fecha()
{
    EstablecerFechaPorDefecto();
}

Fecha::Fecha(int dia, int mes, int anio)
{
    _dia = dia;
    _mes = mes;
    _anio = anio;

    if(dia <= 0 || mes <= 0 || anio <= 0 || mes > 12 )
    {

        EstablecerFechaPorDefecto();

    }
    else
    {

        int dias[12]= {31,28,31,30,31,30,31,31,30,31,30,31};

        if(EsBisiesto())
        {
            dias[1]++;
        }

        if(dia > dias[_mes - 1])
        {

            EstablecerFechaPorDefecto();

        }

    }
}
void Fecha::SetDia(int d)
{
    _dia = d;

}
void Fecha::SetMes(int m)
{
    _mes = m;

}
void Fecha::SetAnio(int a)
{
    _anio = a;

}

int Fecha::GetDia()
{

    return _dia;

}
int Fecha::GetMes()
{

    return _mes;

}
int Fecha::GetAnio()
{

    return _anio;

}

string Fecha::ToString()
{

    string fechaformateada("");
    string DD = to_string(_dia); // to_string castea el int _dia a un string
    string MM = to_string(_mes);
    string YYYY = to_string(_anio);

    if(_dia < 10)
    {

        DD = "0" + to_string(_dia);


    }
    if(_mes < 10)
    {

        MM = "0" + to_string(_mes);


    }

    fechaformateada = DD + "/" + MM + "/"+ YYYY;

    return fechaformateada;


}
string Fecha::ToStringOtroFormato()
{

    string fechaformateada("");
    string DD = to_string(_dia); // to_string castea el int _dia a un string
    string MM = to_string(_mes);
    string YYYY = to_string(_anio);

    if(_dia < 10)
    {

        DD = "0" + to_string(_dia);


    }
    if(_mes < 10)
    {

        MM = "0" + to_string(_mes);


    }

    fechaformateada = YYYY + "/" + MM + "/"+ DD;

    return fechaformateada;




}

void Fecha::AgregarDia()
{

    int dias[12]= {31,28,31,30,31,30,31,31,30,31,30,31};

    if(EsBisiesto())
    {
        dias[1]++; // si el año es bisiesto cambiar el 28 por 29 en el vector.
    }

    _dia++;
    int d = _dia;
    int m = _mes;

    if(_dia > dias[_mes-1]) //ejemplo: si el día es mayor a 31 en Enero, cambiar a 01/02
    {

        _dia = 1;
        _mes++;

        if(_mes > 12)
        {

            _mes = 1;

            _anio++;

        }
    }


}

void Fecha::AgregarDias(int cantidadDias)
{

    if(cantidadDias > 0)
    {

        for(int i = 0; i < cantidadDias; i++)
        {

            AgregarDia();


        }


    }

}

void Fecha::RestarDia()
{

    int dias[12]= {31,28,31,30,31,30,31,31,30,31,30,31};

    if(EsBisiesto())
    {
        dias[1]++; // si el año es bisiesto cambiar el 28 por 29 en el vector.
    }

    _dia--;

    if(_dia < 1)
    {

        _dia = dias[_mes -2];
        _mes--;

        if(_mes < 1)
        {

            _mes = 12;
            _dia = dias[_mes - 1];

            _anio--;

        }
    }


}

void Fecha::RestarDias(int cantidadDias)
{

    if(cantidadDias > 0)
    {

        for(int i = 0; i < cantidadDias; i++)
        {

            RestarDia();


        }


    }

}

int Fecha::DiferenciaDias(Fecha fechaInicial, Fecha fechaFinal)
{

    int contador = 0;
    bool primerFechaMayor = fechaInicial.ToStringOtroFormato() > fechaFinal.ToStringOtroFormato();

    if(primerFechaMayor)
    {

        Fecha aux = fechaInicial;
        fechaInicial = fechaFinal;
        fechaFinal = aux;
    }

    while(fechaInicial.ToString() != fechaFinal.ToString())
    {

        fechaInicial.AgregarDia();
        contador++;

    }

    if(primerFechaMayor)
    {

        return contador * -1;


    }
    else
    {
        return contador;
    }

}




