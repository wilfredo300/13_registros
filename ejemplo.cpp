#include<iostream>
#include<cstring>
using namespace std;
struct EMP{
    int num;
    string nom;
    float ven[12];
    float sal;
    float t_ven; //venta total anual
    float bono;
};
int main(){
    EMP EMPLEADOS[100];
    int n,i,j;
    int max(0);//indicador de mayor ventas 
    const float bono=1.1;
    cout<<"Ingresa el numero de empleados a ingresar: \n";
    cin>>n;
    for (i=0;i<n;i++){
        cout<<"Ingresa el numero de empleado: ";
        cin>>EMPLEADOS[i].num;
        cout<<"Ingresa el nombre de empleado: ";
        cin>>EMPLEADOS[i].nom;
        cout<<"Ingresa las ventas de empleado: ";
        EMPLEADOS[i].t_ven=0;
        for(j=0;j<3;j++){
            cin>>EMPLEADOS[i].ven[j]; //registra la cantidad de ventas por mes
            EMPLEADOS[i].t_ven += EMPLEADOS[i].ven[j]; //suma el total de ventas al año por cada empleado
        }
        cout<<"Ingresa el salario del empleado\n";
        cin>>EMPLEADOS[i].sal;        
    }
    //el empleado con mas ventas
    for(i=0;i<n-1;i++){
        if(EMPLEADOS[i].t_ven<EMPLEADOS[i+1].t_ven){
            max=i+1;
        }
    }
        
    /*//  Esta seccion es solo para pruebas
    for (i=0;i<n;i++){
        cout<<"Empleado "<<i;
        cout<<EMPLEADOS[i].num<<" ";
        cout<<EMPLEADOS[i].nom<<" \nVentas totales:";
        cout<<EMPLEADOS[i].t_ven<<" ";
        cout<<EMPLEADOS[i].sal<<endl;
    }
    */
    cout<<"El empleado con mas ventas es: "<<EMPLEADOS[max].nom<<" \n";
    cout<<"Ventas totales: "<<EMPLEADOS[max].t_ven<<" \n";
    //bono para los que tuvieron mas de 100 ventas durante el año
    for(i=0;i<n;i++){        

        if(EMPLEADOS[i].t_ven>100){
            EMPLEADOS[i].sal *= bono;
        }
    }

    cout<<"Vendedores con menos de 30 ventas:\n";
    for(i=0;i<n;i++){
        if(EMPLEADOS[i].t_ven<30){
            cout<<EMPLEADOS[i].nom<<endl;
        }
    }
    
    return 0;
}
