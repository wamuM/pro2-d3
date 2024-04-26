// marcel.mula@estudiantat.upc.edu L12
// paula.quetineau@estudiantat.upc.edu L42

#include "Cjt_estudiants.hh"

void insert(vector<Estudiant>& vest, const int& index, const int& nest, const Estudiant& est){
    for(int i = nest; i>index; --i)vest[i] = vest[i-1];
    vest[index] = est;
}

void erase(vector<Estudiant>& vest, const int& index, const int& nest){
    for(int i = index; i<nest-1; ++i)vest[i] = vest[i+1];
    vest[nest-1] = Estudiant();
}
/* Pre: el paràmetre implícit no està ple */
/* Post: b = indica si el p.i. original conté un estudiant amb el dni d'est;
   si b = fals, s'ha afegit l'estudiant est al paràmetre implícit */
void Cjt_estudiants::afegir_estudiant(const Estudiant& est, bool& b){
    //Totes aquestes condicions estan perque la PRE de cerca_dicot no permet que nest sigui 0 o 1
    int index;
    if(this->nest == 0){
        index = 0;
        b = false;
    }else{
        if(this->nest == 1)index = this->vest[0].consultar_DNI() < est.consultar_DNI();
        else               index = Cjt_estudiants::cerca_dicot(this->vest, 0, this->nest-1, est.consultar_DNI());

        b = this->vest[index].consultar_DNI() == est.consultar_DNI();
    }
    if(b)return;

    if(est.te_nota())this->incrementar_interval(est.consultar_nota());
    insert(this->vest, index, this->nest, est);
    ++this->nest;

}

/* Pre: cert */
/* Post: b indica si el paràmetre implícit original tenia un estudiant 
   amb el dni dni; si b, aquest estudiant ha quedat eliminat
   del paràmetre implícit */
void Cjt_estudiants::esborrar_estudiant(int dni, bool& b){
    int index;
    if(this->nest == 0){
        b = false;
    }else{
        if(this->nest == 1)index = 0;
        else index = Cjt_estudiants::cerca_dicot(this->vest,0, this->nest-1, dni);
    
        b = index < this->nest and this->vest[index].consultar_DNI() == dni;
    }
    if(not b)return;

    if(vest[index].te_nota())this->decrementar_interval(vest[index].consultar_nota());
    erase(this->vest, index, this->nest);
    --this->nest;
}

/* Pre: x és una nota vàlida */
/* Post: al paràmetre implícit, s'ha incrementat en una unitat el valor de
   la posició d'"intervals" corresponent a x */
void Cjt_estudiants::incrementar_interval(double x){
    int floor = x; 
    if(floor == 10)floor = 9; 
    ++this->intervals[floor];
};

/* Pre: x és una nota vàlida */
/* Post: al paràmetre implícit, s'ha decrementat en una unitat el valor de
   la posició d'"intervals" corresponent a x */
void Cjt_estudiants::decrementar_interval(double x){
    int floor = x; 
    if(floor == 10)floor = 9; 
    --this->intervals[floor];
};
