#include <iostream>

using namespace std;

struct nod{
    int valoare;
    nod* next;
};

void adaugare_final(nod* &primul, int val){
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

int numere_pozitive(nod* &primul){
    nod* parcurgere = primul;
    int numere=0;
    while(parcurgere != NULL){
        if(parcurgere->valoare > 0)
            numere++;
        parcurgere = parcurgere->next;
    }
    return numere;
}

int ma_negativa(nod* primul){
    nod* parcurgere = primul;
    int ma=0;
    int nr=0;
    while(parcurgere != NULL){
        if(parcurgere->valoare < 0){
            ma+=parcurgere->valoare;
            nr++;
        }
        parcurgere = parcurgere->next;
    }
    if(nr == 0)
        return -1;
    return ma/nr;
}

int main()
{
    nod* p=NULL;
    adaugare_final(p,2);
    adaugare_final(p,11);
    adaugare_final(p,-24);
    adaugare_final(p,-2);
    adaugare_final(p,6);
    cout<<ma_negativa(p);
    return 0;
}
