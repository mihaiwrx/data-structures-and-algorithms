#include <iostream>

using namespace std;

struct nod{
    int valoare;
    nod *next;
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

void adaugare_inceput(nod* &primul, int val){
    if(primul == NULL){
        primul->valoare = val;
        primul->next = NULL;
    }
    else{
        nod *inceput = new nod;
        inceput->valoare = val;
        inceput->next = primul;
        primul = inceput;
    }
}

void adaugare_pe_poz(nod* &primul, int val, int poz){

    nod *nou = new nod;
    nou->valoare = val;
    nod *parcurgere = primul;
    if(poz == 0){
        nou->next = primul;
        primul = nou;
    }
    else{
        int aux_poz=0;
        while(parcurgere->next != NULL){
            aux_poz++;
            if(poz == aux_poz){
                nou->next = parcurgere->next;
                parcurgere->next = nou;
                break;
            }
            parcurgere = parcurgere->next;
        }
    }
}

void cautare_valoare(nod* primul, int val_cautata){
    int poz = 0;
    if(primul->valoare == val_cautata)
        cout<<"Numarul "<<val_cautata<<" se afla pe pozitia 0."<<endl;
    else{
        nod* parcurgere = primul->next;
        while(parcurgere->next != NULL){
            poz++;
            if(parcurgere->valoare == val_cautata){
                cout<<"Numarul "<<val_cautata<<" se afla de pozitia "<<poz<<"."<<endl;
                break;
            }
            parcurgere = parcurgere->next;
        }
        if(parcurgere->valoare == val_cautata)
            cout<<"Numarul "<<val_cautata<<" se afla de pozitia "<<poz+1<<"."<<endl;
    }
}

void cautare_pozitie(nod* primul, int pozitie){
    nod* parcurgere = primul;
    int poz_aux=0;
    while(parcurgere->next != NULL){
        if(pozitie == poz_aux)
            cout<<"Elementul de pe pozitia "<<pozitie<<" este: "<<parcurgere->valoare<<endl;
        poz_aux++;
        parcurgere = parcurgere->next;
    }
}

void stergere_dupa_valoare(nod* &primul, int val){
    if(primul->valoare == val){
        nod* to_delete = primul;
        primul = primul->next;
        delete to_delete;
    }
    else{
        nod* parcurgere = primul;
        while(parcurgere->next->next != NULL){
            if(parcurgere->next->valoare == val){
                nod* aux = parcurgere->next;
                parcurgere->next = parcurgere->next->next;
                delete aux;
                break;
            }
            parcurgere = parcurgere->next;
        }
        nod* aux= parcurgere->next;
        if(parcurgere->next->valoare == val){
            parcurgere->next = NULL;
            delete aux;
        }
    }
}

void stergere_dupa_pozitie(nod* &primul, int pozitie){
    int poz_aux=1;
    if(pozitie == 0){
        nod* to_delete = primul;
        primul = primul->next;
        delete to_delete;
    }
    else{
        nod* parcurgere = primul;
        while(parcurgere->next != NULL && poz_aux <= pozitie){
            if(poz_aux == pozitie){
                nod* aux = parcurgere->next;
                parcurgere->next = parcurgere->next->next;
                delete aux;
                break;
            }
            poz_aux++;
            parcurgere = parcurgere->next;
        }
        nod* aux= parcurgere->next;
        if(poz_aux+1 == pozitie){
            parcurgere->next = NULL;
            delete aux;
        }
    }
}

void stergere_lista(nod* &primul){
    while(primul != NULL){
        stergere_dupa_pozitie(primul,0);
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
    nod *p = NULL;
    afisare_lista(p);
    adaugare_final(p,2);
    afisare_lista(p);
    adaugare_final(p,12);
    afisare_lista(p);
    adaugare_final(p,5);
    afisare_lista(p);
    adaugare_final(p,88);
    afisare_lista(p);
    adaugare_inceput(p,100);
    afisare_lista(p);
    adaugare_pe_poz(p,555,2);
    afisare_lista(p);
    cout<<"=================="<<endl;
    stergere_dupa_pozitie(p,2);
    afisare_lista(p);
    stergere_lista(p);
    afisare_lista(p);
    return 0;
}

