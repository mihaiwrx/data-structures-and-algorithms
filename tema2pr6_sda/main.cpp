#include <iostream>
#include <math.h>

using namespace std;

struct polinom{
    int grad, coef;
    polinom* next;
};

void adaugare_final(polinom* &primul, int gr, int cf){
    if(primul == NULL){
        primul = new polinom;
        primul->grad = gr;
        primul->coef = cf;
        primul->next = NULL;
    }
    else{
        polinom *nou = new polinom;
        nou->grad = gr;
        nou->coef = cf;
        nou->next = NULL;
        polinom* parcurgere = primul;
        while(parcurgere->next != NULL){
            parcurgere = parcurgere->next;
        }
        parcurgere->next = nou;
    }
}

void inmultire_scalar(polinom* &primul, int a){
    if(primul == NULL){
        cout<<"Inmultirea nu este posibila!"<<endl;
    }
    else{
        polinom* parcurgere = primul;
        while(parcurgere != NULL){
            parcurgere->coef *= a;
            parcurgere = parcurgere->next;
        }
    }
}

void rezolvare(polinom* &primul, int x){
    if(primul == NULL)
        cout<<"Nu se poate rezolva polinomul."<<endl;
    else{
        int suma = 0;
        polinom* parcurgere = primul;
        while(parcurgere != NULL){
            suma = suma + parcurgere->coef * pow(x,parcurgere->grad);
            parcurgere = parcurgere->next;
        }
        cout<<"Suma polinomului este: "<<suma<<endl;
    }
}

void afisare_lista(polinom* primul){
    if(primul == NULL)
    {
        cout<<"Lista e vida!"<<endl;
    }
    else
    {
        cout<<"P = ";
        while(primul->next != NULL)
        {
            cout<<primul->coef<<"x^"<<primul->grad<<" + ";
            primul = primul->next;
        }
        cout<<primul->coef<<"x^"<<primul->grad;
        cout<<endl;
    }
}

int main()
{
    polinom* pol = NULL;
    int a, x;
    cin>>x;
    adaugare_final(pol,2,3);
    adaugare_final(pol,1,2);
    adaugare_final(pol,0,3);
    afisare_lista(pol);
    rezolvare(pol,x);
    afisare_lista(pol);
    return 0;
}
