// marcel.mula@estudiantat.upc.edu L12
// paula.quetineau@estudiantat.upc.edu L42

#include "Cjt_estudiants.hh"

void insert(vector<Estudiant>& vest, int index, int nest, const Estudiant& est){
    for(int i = nest-1; i>=index; --i)vest[i+1] = vest[i];
    vest[index] = est;
}

void erase(vector<Estudiant>& vest, int index, int nest){
    for(int i = index; i<nest-1; ++i)vest[i] = vest[i+1];
    vest[nest-1] = Estudiant();
}
/* Pre: el paràmetre implícit no està ple */
/* Post: b = indica si el p.i. original conté un estudiant amb el dni d'est;
   si b = fals, s'ha afegit l'estudiant est al paràmetre implícit */
void Cjt_estudiants::afegir_estudiant(const Estudiant& est, bool& b){
    int index = 0; //All of this mess because the Pre of cerca_dicot is super strict 
    if(this->nest > 1)index = Cjt_estudiants::cerca_dicot(this->vest, 0, this->nest-1, est.consultar_DNI());
    else if(this->nest == 1)index = this->vest[0].consultar_DNI() > est.consultar_DNI(); 

    if(this->vest[index].consultar_DNI() == est.consultar_DNI()){
        b = true;
    }else{
        insert(this->vest, index, this->nest, est);
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
    int index = 0;
    if(this->nest > 1)index = Cjt_estudiants::cerca_dicot(this->vest,0, this->nest-1, dni);
    else if(this->nest == 1)index = this->vest[0].consultar_DNI() > dni; 

    if(this->vest[index].consultar_DNI() != dni){
        b = false;
    }else{
        if(vest[index].te_nota())this->decrementar_interval(vest[index].consultar_nota());
        erase(this->vest, index, this->nest);
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
