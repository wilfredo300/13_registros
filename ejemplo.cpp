#include<iostream>
#include<cstring>
using namespace std;
struct EMP{
    int num;
    string nom;
    float ven[12];
    float sal;
    float t_ven;
};
int main(){
    EMP EMPLEADOS[100];
    int n,i,j;
    cout<<"Ingresa el numero de empleados a ingresar: \n";
    cin>>n;
    for (i=0;i<n;i++){
        cout<<"Ingresa el numero de empleado: ";
        cin>>EMPLEADOS[i].num;
        cout<<"Ingresa el nombre de empleado: ";
        cin>>EMPLEADOS[i].nom;
        cout<<"Ingresa el las ventas de empleado: ";
        EMPLEADOS[i].t_ven=0;
        for(j=0;j<12;j++){
            cin>>EMPLEADOS[i].ven[j]; //registra la cantidad de ventas por mes
            EMPLEADOS[i].t_ven += EMPLEADOS[i].ven[j]; //suma el total de ventas al año por cada empleado
        }
        cout<<"Ingresa el salario del empleado\n";
        cin>>EMPLEADOS[i].sal;        
    }
    

    /*
    for (i=0;i<n;i++){
        cout<<"Empleado "<<i;
        cout<<EMPLEADOS[i].num<<" ";
        cout<<EMPLEADOS[i].nom<<" ";
        for(j=0;j<12;j++){
            cout<<EMPLEADOS[i].ven[j]<<" ";
        }
        cout<<EMPLEADOS[i].sal<<endl;
    }
    */
    return 0;
}
