#include<iostream>
using namespace std;

struct correo{
    string user;
    string domain;
};

struct contactoEmail{
    string nom;
    char sex;
    int edad;
    correo email;
};

void leerCorreo(correo &, string, string);
void leerContacto(contactoEmail &, string, char, int, correo);
void imprimeContacto(contactoEmail &);

int main(){
    int n, op,id;
    string nom, user, domain;
    char sex,val, op3,op5;
    int edad;
    correo email;
    contactoEmail cont, lista[100], busqueda;
    n = 0;
    do{
        system("cls");
        cout<<"Menu de opciones -------------------------"<<endl;
        cout<<"1. Agregar contacto"<<endl;
        cout<<"2. Mostrar contactos"<<endl;
        cout<<"3. Buscar y/o editar contacto"<<endl;
        cout<<"4. Mostrar contactos por dominio"<<endl;
        cout<<"5. Eliminar contacto"<<endl;
        cout<<"0. Salir"<<endl;
        cout<<"Elige una opcion: "; cin>>op;
        switch(op){
            case 1:
                cout<<"Ingrese los datos de un usuario: "<<endl;
                cin.ignore();
                cout<<"Ingrese el nombre del contacto: "; getline(cin,nom);
                cout<<"Ingrese el sexo (M/F): "; cin>>sex;
                cout<<"Ingrese la edad: "; cin>>edad;
                cout<<"Ingrese el correo electronico (usuario@dominio): "<<endl;
                cout<<"\tIngrese el usuario: "; cin>>user;
                cout<<"\tIngrese el dominio: "; cin>>domain;
                
                leerCorreo(email,user,domain);
                leerContacto(cont,nom,sex,edad,email);
                //imprimeContacto(cont);
                //-----------------validación de contacto------------------//
                cout<<"¿Ingresó los datos correctamente? s/n"<<endl;
                cin>>val;
                val=tolower(val);
                if(val=='n'){
                    cout<<"Ingrese los datos nuevamente: ";
                    continue;
                }else{
                    cout<<"Los datos han sido guardados correctamente";
                }
                lista[n] = cont;
                n++;
                system("pause");
                break;
            case 2:
                for(int i = 0; i < n; i++){
                    cout<<"-------------Contacto #--------------"<<i<<endl;
                    imprimeContacto(lista[i]);
                    cout<<endl;
                }
                system("pause");
                break;
            case 3:
            cout<<  "\tb)Ingresa el id# de la persona que quieres editar\n";
                    cout<<"Ingrese el id#: ";cin>>id;
                    cout<<"Contacto #"<<id<<endl;
                    imprimeContacto(lista[id]);
                    cout<<"¿Estas seguro que quieres editar? (s/n)";cin>>op3;
                    op3=tolower(op3);
                    if(op3=='s'){
                        cin.ignore();
                        cout<<"Ingrese el nombre del contacto: "; getline(cin,nom);
                        cout<<"Ingrese el sexo (M/F): "; cin>>sex;
                        cout<<"Ingrese la edad: "; cin>>edad;
                        cout<<"Ingrese el correo electronico (usuario@dominio): "<<endl;
                        cout<<"\tIngrese el usuario: "; cin>>user;
                        cout<<"\tIngrese el dominio: "; cin>>domain;
                        leerCorreo(email,user,domain);
                        leerContacto(cont,nom,sex,edad,email);
                        lista[id]=cont;
                    }
                    system("pause");
                    break;
            case 4: 
            cout<<"------------Contactos con @hotmail.com:------------------ \n";
            for(int i=0; i<n; i++){
                int a=0;
                if(lista[i].email.domain=="hotmail.com"){
                    cout<<"contacto #"<<i<<endl;
                    imprimeContacto(lista[i]);
                    a++;                    
                }
                if(i==n-1&&a==0){
                    cout<<"No hay correos con este dominio"<<endl;
                }
            }
            cout<<"-----------Contactos con @gmail.com:--------------------- \n";
            for(int i=0; i<n; i++){
                int a=0;
                if(lista[i].email.domain=="gmail.com"){
                    cout<<"contacto #"<<i<<endl;
                    imprimeContacto(lista[i]);
                    a++;                    
                }
                if(i==n-1&&a==0){
                    cout<<"No hay correos con este dominio"<<endl;
                }
            }
            cout<<"-----------Contactos con otros dominios:----------------- \n";
            for(int i=0; i<n; i++){
                int a=0;
                if(lista[i].email.domain!="hotmail.com"&&lista[i].email.domain!="gmail.com"){
                    cout<<"contacto #"<<i<<endl;
                    imprimeContacto(lista[i]);
                    a++;                    
                }
                if(i==n-1&&a==0){
                    cout<<"No hay correos con otros dominios"<<endl;
                }
            }
                system("pause");
                break;
            case 5:
                cout<<"Ingrese el id# del contacto que vas a eliminar: "; cin>>id;
                cout<<"Estas seguro que quieres eliminar a "<<lista[id].nom<<" de la lista de contactos? (s/n)"; cin>>op5;
                op5=tolower(op5);
                if(op5=='s'){
                    for(int i=id;i<n;i++){
                        lista[i]=lista[i+1];
                    }
                    n--;
                }
                system("pause");
                break;
            case 0:
                cout<<"Esta seguro de salir? (S/N): ";
                break;
            default:
                cout<<"Opcion no valida!"<<endl;
                system("pause");
                break;
        }
    } while(op != 0);
    return 0;
}

void leerContacto(contactoEmail &c, string n, char s, int e, correo em){
    c.nom = n;
    c.sex = s;
    c.edad = e;
    c.email = em;
}

void leerCorreo(correo &c, string u, string d){
    c.user = u;
    c.domain = d;
}

void imprimeContacto(contactoEmail &c){
    cout<<"Nombre: "<<c.nom<<endl;
    cout<<"Sexo: "<<c.sex<<endl;
    cout<<"Edad: "<<c.edad<<endl;
    cout<<"Email: "<<c.email.user<<"@"<<c.email.domain<<endl;
}