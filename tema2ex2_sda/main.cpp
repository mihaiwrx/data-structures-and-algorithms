#include <iostream>

using namespace std;

struct nod{
    int valoare;
    nod* next;
};

void adaugare(nod* &primul, int numar){
    nod* nou = new nod;
    nou->valoare = numar;
    if(primul == NULL){
        primul = new nod;
        primul->valoare = numar;
        primul->next = NULL;
    }
    else{
        nod* parcurgere = primul;
        int ok=0;
        while(parcurgere->next != NULL){
            if(parcurgere->next->valoare >= numar){
                ok=1;
                nod* aux = parcurgere->next;
                nou->next = aux;
                parcurgere->next = nou;
                break;
            }
            parcurgere = parcurgere->next;
        }
        if(!ok){
            if(parcurgere->valoare < numar){
                nou->next = NULL;
                parcurgere->next = nou;
            }
            else if(parcurgere->valoare > numar){
                nou->next = primul;
                primul = nou;
            }
        }
    }
}

void afisare_lista(nod* primul){
    if(primul == NULL)
    {
        cout<<"Lista e vida!"<<endl;
    }
    else
    {
        while(primul->next!=NULL)
        {
            cout<<primul->valoare<<' ';
            primul = primul->next;
        }
        cout<<primul->valoare;
        cout<<endl;
    }
}

int main(){
    nod *p=NULL;
    adaugare(p,5);
    afisare_lista(p);
    adaugare(p,1);
    afisare_lista(p);
    adaugare(p,9);
    adaugare(p,1);
    adaugare(p,11);
    adaugare(p,7);
    adaugare(p,7);
    adaugare(p,2);
    adaugare(p,1);
    adaugare(p,9);
    adaugare(p,13);
    afisare_lista(p);
    return 0;
}
