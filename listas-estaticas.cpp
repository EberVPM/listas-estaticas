#include <iostream>

const int TAM = 100;

class Empleado {
private:
    int ClaveEmpleado;
    std::string Nombre, Domicilio, ReportaA;
    float Sueldo;
public:
    Empleado() {
        ClaveEmpleado = 0;
        Nombre = " ";
        Domicilio = " ";
        ReportaA = " ";
        Sueldo = 0;
    }
    Empleado(int clave, std::string nombre, std::string dom, std::string repa, float sueldo) {
        ClaveEmpleado = clave;
        Nombre = nombre;
        Domicilio = dom;
        ReportaA = repa;
        Sueldo = sueldo;
    }
    void Imprime() {
        std::cout << "Clave Empleado: " << ClaveEmpleado << std::endl;
        std::cout << "Nombre: " << Nombre << std::endl;
        std::cout << "Domicilio: " << Domicilio << std::endl;
        std::cout << "Reporta a: " << ReportaA << std::endl;
        std::cout << "Sueldo: " << Sueldo << std::endl;
    }
    void CambiaDomic(std::string domicilio) {
        Domicilio = domicilio;
    }
    void CambiaReporteA(std::string reporte) {
        ReportaA = reporte;
    }
    void ActualSueldo(float sueldo) {
        Sueldo += (Sueldo * sueldo) / 100;
    }

    friend bool operator == (Empleado& empleado1, Empleado& empleado2) {
        return (
                empleado1.ClaveEmpleado == empleado2.ClaveEmpleado &&
                empleado1.Nombre == empleado2.Nombre &&
                empleado1.Domicilio == empleado2.Domicilio &&
                empleado1.ReportaA == empleado2.ReportaA &&
                empleado1.Sueldo == empleado2.Sueldo
            );
    }

     friend bool operator != (Empleado& e1, Empleado& e2){
        return !(e1 == e2);
    }

    friend Empleado operator + (Empleado& e1, Empleado& e2) {
        return Empleado (e1.ClaveEmpleado + e2.ClaveEmpleado, e1.Nombre + e2.Nombre,
                        e1.Domicilio + e2.Domicilio, e1.ReportaA + e2.ReportaA,
                        e1.Sueldo + e2.Sueldo);
    }

    friend bool operator > (Empleado& e1, Empleado& e2) {
        return e1.Sueldo > e2.Sueldo;
    }

    friend bool operator < (Empleado& e1, Empleado& e2) {
        return e1.Sueldo < e2.Sueldo;
    }

    friend std::istream& operator >> (std::istream& i, Empleado& e) {
        std::cout << "Ingresa la clave: ";
        i >> e.ClaveEmpleado;

        std::cout << "Ingresa el nombre: ";
        std::cin.ignore();
        i >> e.Nombre;

        std::cout << "Ingresa el domicilio: ";
        std::cin.ignore();
        i >> e.Domicilio;

        std::cout << "Ingresa el nombre de reporte: ";
        std::cin.ignore();
        i >> e.ReportaA;

        std::cout << "Ingresa el sueldo: ";
        i >> e.Sueldo;

        return i;
    }

    friend std::ostream& operator << (std::ostream& o, Empleado& e) {
        o << "Clave: " << e.ClaveEmpleado << std::endl;
        o << "Nombre: " << e.Nombre << std::endl;
        o << "Domicilio: " << e.Domicilio << std::endl;
        o << "Reporta a: " << e.ReportaA << std::endl;
        o << "Sueldo: " << e.Sueldo << std::endl;

        return o;
    }
};

class Lista {
    private:
        Empleado empleados[TAM];
        int ultimo;
    public:
        Lista(): ultimo (-1) {}

        bool vacia() const {
            if (ultimo == -1) return true;
            return false;
        }

        bool llena() const {
            if (ultimo == TAM - 1) return true;
            return false;
        }

        int agrega(Empleado empleado) {
            if (llena()) {
                std::cout << "No se pudo insertar el empleado" << std::endl;
                return 0;
            }

            empleados[ultimo + 1] = empleado;
            ultimo++;
            return 1;
        }

        int inserta(Empleado empleado, int posicion) {
            if (llena() || posicion < 0 || posicion > ultimo + 1) {
                std::cout << "No se pudo insertar el empleado" << std::endl;
                return 0;
            }

            int i = ultimo + 1;
            while (i > posicion) {
                empleados[i] = empleados[i - 1];
                i--;
            }
            empleados[posicion] = empleado;
            ultimo++;

            return 1;
        }

        int elimina(int posicion) {
            if (vacia() || posicion < 0 || posicion > ultimo) {
                std::cout << "No se pudo eliminar el empleado" << std::endl;
                return 0;
            }

            int i = posicion;
            while(i < ultimo) {
                empleados[i] = empleados[i + 1];
                i++;
            }
            ultimo--;

            return 1;
        }

        void muestra() {
            if (vacia()) {
                std::cout << "La lista esta vacia" << std::endl;
            } else {
                int i;
                for (i = 0; i <= ultimo; i++) {
                    std::cout << empleados[i];
                }
            }
        }
};

int main() {
    int opcion, posicion;
    Empleado empleado;
    Lista lista;

    do {
        std::cout << "--------------------Menu--------------------" << std::endl;
        std::cout << "1. Agregar empleado" << std::endl;
        std::cout << "2. Buscar empleado" << std::endl;
        std::cout << "3. Eliminar empleado" << std::endl;
        std::cout << "4. Inserta un empleado" << std::endl;
        std::cout << "5. Mostrar empleados" << std::endl;
        std::cout << "6. Salir" << std::endl;
        std::cout << "Elija una opcion: ";
        std::cin >> opcion;

        switch (opcion) {
            case 1:
                std::cin >> empleado;
                lista.agrega(empleado);
                break;
            case 2:
                
                break;
            case 3:
                std::cout << "Ingrese la posicon a eliminar: ";
                std::cin >> posicion;
                lista.elimina(posicion);
                break;
            case 4:
                std::cout << "Ingrese la posicon a insertar: ";
                std::cin >> posicion;
                std::cin >> empleado;
                lista.inserta(empleado, posicion);
                break;
            case 5:
                lista.muestra();
                break;
            case 6:
                std::cout << "Saliendo..." << std::endl;
                break;
            default:
                std::cout << "Opcion incorrecta :(" << std::endl;
        }

    } while (opcion != 6);
    return 0;
}
