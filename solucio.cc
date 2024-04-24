// marcel.mula@estudiantat.upc.edu L12
// paula.quetineau@estudiantat.upc.edu L42

#include "Cjt_estudiants.hh"
#include <iostream>
/* Pre: index is a valid index*/
/* Post: The return value is an iterator to the element pointed by index*/
vector<Estudiant>::const_iterator index_to_iterator(const vector<Estudiant>& vest, int index){
    auto it = vest.begin();
    for(int i = 0; i<index;++i)++it;
    return it;
};

/* Pre: el paràmetre implícit no està ple */
/* Post: b = indica si el p.i. original conté un estudiant amb el dni d'est;
   si b = fals, s'ha afegit l'estudiant est al paràmetre implícit */
void Cjt_estudiants::afegir_estudiant(const Estudiant &est, bool& b){
    int index = Cjt_estudiants::cerca_dicot(this->vest,0, this->mida()-1, est.consultar_DNI());
    if(this->vest[index].consultar_DNI() == est.consultar_DNI()){
        b = true;
    }else{
        this->vest.insert(index_to_iterator(this->vest, index), est);
        ++this->nest;
        if(est.te_nota())this->incrementar_interval(est.consultar_nota());
        b = false;
    }
}

/* Pre: cert */
/* Post: b indica si el paràmetre implícit original tenia un estudiant 
   amb el dni dni; si b, aquest estudiant ha quedat eliminat
   del paràmetre implícit */
void Cjt_estudiants::esborrar_estudiant(int dni, bool& b){
    int index = Cjt_estudiants::cerca_dicot(this->vest,0, this->mida()-1, dni);
    if(this->vest[index].consultar_DNI() != dni){
        b = false;
    }else{
        if(vest[index].te_nota())this->decrementar_interval(vest[index].consultar_nota());
        this->vest.erase(index_to_iterator(this->vest, index));
        --this->nest;
        b = true;
    }
}

/* Pre: x és una nota vàlida */
/* Post: al paràmetre implícit, s'ha incrementat en una unitat el valor de
   la posició d'"intervals" corresponent a x */
void Cjt_estudiants::incrementar_interval(double x){
    int floor = x; 
    if(floor == 10)x = 9; 
    ++this->intervals[floor];
};

/* Pre: x és una nota vàlida */
/* Post: al paràmetre implícit, s'ha decrementat en una unitat el valor de
   la posició d'"intervals" corresponent a x */
void Cjt_estudiants::decrementar_interval(double x){
    int floor = x; 
    if(floor == 10)x = 9; 
    --this->intervals[floor];
};
