// marcel.mula@estudiantat.upc.edu
// paula.quetineau@estudiantat.upc.edu
#include "Cjt_estudiants.hh"

/* Pre: el paràmetre implícit no està ple */
/* Post: b = indica si el p.i. original conté un estudiant amb el dni d'est;
   si b = fals, s'ha afegit l'estudiant est al paràmetre implícit */
void Cjt_estudiants::afegir_estudiant(const Estudiant &est, bool& b){
    int index = Cjt_estudiants::cerca_dicot(this->vest,0, this->mida(), est.consultar_DNI());
    if(this->vest[index].consultar_DNI() == est.consultar_DNI()){
        b = true;
    }else{
      this->vest.insert(index, est);
      if(est.te_nota())this->incrementar_interval(est.consultar_nota());
    }
}

/* Pre: cert */
/* Post: b indica si el paràmetre implícit original tenia un estudiant 
   amb el dni dni; si b, aquest estudiant ha quedat eliminat
   del paràmetre implícit */
void Cjt_estudiants::esborrar_estudiant(int dni, bool& b){

}

/* Pre: x és una nota vàlida */
/* Post: al paràmetre implícit, s'ha incrementat en una unitat el valor de
   la posició d'"intervals" corresponent a x */
void Cjt_estudiants::incrementar_interval(double x){
    int floor = x; 
    if(floor == 10)x = 9; 
    ++this->intervals[floor];
};

/* Pre: x és una nota vàlida 
/* Post: al paràmetre implícit, s'ha decrementat en una unitat el valor de
   la posició d'"intervals" corresponent a x */
void Cjt_estudiants::decrementar_interval(double x){
    int floor = x; 
    if(floor == 10)x = 9; 
    --this->intervals[floor];
};
