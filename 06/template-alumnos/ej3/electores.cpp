#include "electores.h"

int validarVotante(int a, int m, int d) {

    if(a < YEAR-100 || a > YEAR || m < 0 || m > 12 || d<0){
        return ERROR;
    }

    if(YEAR - a >=16){
        if(YEAR - a == 16 && m >=10 && d>=22)return OPCIONAL_MENOR;
        if(YEAR - a == 18 && m >=10 && d>=22)return OBLIGATORIO;
        if(YEAR - a == 70 && m >=10 && d>=22)return OPCIONAL_MAYOR;

        if(YEAR - a < 18){
            return OPCIONAL_MENOR;
        }else if (YEAR - a > 70){
            return OPCIONAL_MAYOR;
        }else{
            return OBLIGATORIO;
        }

    }else {
        return NO_VOTA;
    }
}
