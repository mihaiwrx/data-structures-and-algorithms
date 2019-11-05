#include <iostream>

using namespace std;

struct nod{
    float valoare;
    nod* next;
};

void adaugare_final(nod* &primul, float val){
    if(primul == NULL){
        primul = new nod;
        primul->valoare = val;
        primul->next = NULL;
    }
    else{
        nod *nou = new nod;
        nou->valoare = val;
        nou->next = NULL;
        nod* parcurgere = primul;
    while(parcurgere->next != NULL){
        parcurgere = parcurgere->next;
    }
    parcurgere->next = nou;
    }
}

void inserare(nod* &primul, float numar){
    nod* mijloc = new nod;
    mijloc->valoare = numar;
    nod* aux = primul->next;
    primul->next = mijloc;
    mijloc->next = aux;
}

void modificare_lista(nod* &primul){
    float ma=0;
    if(primul->next == NULL)
        cout<<"Eroare";
    else{
        nod* parcurgere = primul;
        while(parcurgere->next->next != NULL){
            ma=(parcurgere->valoare+parcurgere->next->valoare)/2;
            inserare(parcurgere,ma);
            parcurgere = parcurgere->next->next;
        }
        ma=(parcurgere->valoare+parcurgere->next->valoare)/2;
        inserare(parcurgere,ma);
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

int main()
{
    nod* p=NULL;
    adaugare_final(p,10);
    adaugare_final(p,2);
    adaugare_final(p,7);
    modificare_lista(p);
    afisare_lista(p);
    return 0;
}
