// FULLNAME : MARAOUI YASSINE
// CLASS : GLSID-1
#include<iostream>
#include <string>
using namespace std;
// LA LISTE QUI CONTIENT LES CONTACTS
class contact{
public:
    string name;
    string tel;
    string mail;
    contact* next;
    contact* prev;
};
// LA LISTE DES CHIFFRES
class list{
public:
    contact *letters[26];
    list* a_zero();
    void insertContact(string name,string tel,string mail);
    void showList(char letter);
    int size(char letter);
    void sizeT();
    void searchPeson(string name);
    void deletePerson(string name);
    void updatePerson(string name,string newTel,string newMail);
    int isExist(char f_letter,string tel);
};
// L'ALLOCATION DE MEMOIRE POUR LA LISTE CREEE
// LA CREATION D'UNE LISTE CHAINNES POUR CHAQUE LETTRE
// L'INITIALISATION DE CHAQUE LISTE CHAINNEES PAR DES VALEURS PAR DEFAUT 
// L'AFFECTATION DE LA LISTE CHAINNES VERS LE ELEMENT DU TABLEAU
list* list::a_zero(){
    list* L = new list;
    for(int i=0;i<26;i++){
        contact *c = new contact;
        c->next = NULL;
        c->prev = NULL;
        L->letters[i] = c;       
    }
    return L;
};
// pour verifie si le contact exist ou pas
int list::isExist(char f_letter, string tel){
    contact *head;
    int index = toupper(f_letter)-'A';
    head = this->letters[index];
    while (head!=NULL)
    {
        if(tel == head->tel){
            return 1;
        }
        head = head->next;
    }
    return 0;
}
// L'INSERTION A LA FIN DE CHAQUE LIST
void list::insertContact(string name,string tel,string mail){
    // verification si le contact deja existe
    char F_letter = name.at(0);
    if(isExist(F_letter,tel)){
        cout << "Le contact est deja existe";
    }else{

        // convert F_letter to uppercase POUR CALCULER L'INDEX DE LA CASE
    // QUI SERA predre la liste ou bien le contact a ajoutter
    int index = toupper(F_letter)- 'A';
    contact *newContact = new contact;
    newContact->next = NULL; //////////////////////////////////////////////////////
    newContact->name = name; ///       affectation des valeur au contact     /////
    newContact->tel = tel; ///                   cree                       /////
    newContact->mail = mail; ///////////////////////////////////////////////////
    // creation d'une variable head pour prendre la tete de la liste
    contact *head = new contact;
    contact *before_null = new contact; 
    head = this->letters[index];
    if(head->next == NULL){ // si la liste est vide 
        head->next = newContact; 
        newContact->prev = head;
    }else{ // si la liste contient des element 
        while (head != NULL)
        {   before_null = head; // prendre le dernier element avant l'element null 
            head = head->next;
        }
        before_null->next = newContact; 
        newContact->prev = before_null;
    }

    }
    
};
// affichage de la liste 
void list::showList(char letter){
    contact* head;
    int index = toupper(letter) - 'A';
    head = this->letters[index];
    if(this->size(letter) == 0){
        cout << "LA LISTE COTNTIEN AUCUN ELEMENT";
    }
    else{
        while(head != NULL){
        if(head->prev==NULL){head=head->next;continue;}
        cout <<"nom : "<< head->name<< endl;
        cout << "TEL: "<< head->tel<< endl;
        cout <<"E-MAIL :"<< head->mail<< endl;
        cout << "======================="<< endl;
        head = head->next;
    }
    }
};

int list::size(char letter){
    int index = toupper(letter) - 'A';
    contact* head;
    int nbrElement=0;
    head = this->letters[index];
    while(head != NULL){
        nbrElement++;
        head = head->next;
    }
    nbrElement-=1;
    if(nbrElement==0)
        cout << "LA LISTE DE LA LETTRE "<< (char)toupper(letter) << " EST VIDE";
    return nbrElement;
}

 void list::searchPeson(string name){
     char f_letter = name.at(0);
     int index = toupper(f_letter) - 'A';
     contact* head;
     head = this->letters[index];
     while (head!=NULL)
     {
         if(head->name == name){
             cout <<"NOM : "<<head->name <<endl;
             cout <<"TEL : "<< head->tel<<endl;
             cout <<"E-MAIL : "<<head->mail<<endl;
             cout << "==========================="<<endl;
         }
         head = head->next;
     }
     
 };

void list::sizeT(){
    int sizeTotal = 0;
    for (int i = 0; i < 26; i++)
    {   contact *head = this->letters[i];
        while (head!=NULL)
        {   if(head->prev==NULL){head=head->next;continue;}
            sizeTotal++;
            head = head->next;
        }
        
    }
    
    cout << sizeTotal;
}

// modifie le numero et l'email en se basent sur le nom de la personne
void list::updatePerson(string name,string newTel,string newMail){
    int index = toupper(name.at(0)) - 'A';
    contact *head = this->letters[index];
    while (head!=NULL)
    {
        if(head->name == name){
            break;
        }
        else{head=head->next;}
    }
    head->tel = newTel;
    head->mail = newMail;
};

// supprimer un person par leur nom
void list::deletePerson(string name){
    int index = toupper(name.at(0)) - 'A';
    contact *head = this->letters[index];
    while (head!=NULL)
    {
        if(head->name == name){
            head->prev->next = head->next;
            head->next->prev = head->prev;
            delete head;
        }
        else{head = head->next;}
    }
}

int main(){

    list *L1;
    // size total de la list + size;
    L1 = L1->a_zero();
    L1->insertContact("Ahmed","0651571989","ahmed@mail.com");
    L1->insertContact("Anas","0651531989","anas@mail.com");
    L1->insertContact("Ali","0651522989","ali@mail.com");
    L1->updatePerson("Ahmed","0616922230","ahmed@gmail.com");
    L1->deletePerson("Anas");
    L1->showList('A');
}