#include <iostream>

int promedioExamenes(int &aprobados,int &desaprobados){
  int alumnos;
  
  std :: cout << "Ingrese cantidad de alumnos "<< std :: endl;
  std :: cin >> alumnos;
  if (alumnos < 6){
    throw std::invalid_argument("Debe haber mas de 5 alumnos");
  } 

  for(int i=1; i <= alumnos;i++){
	int nota;
	std :: cout << "Ingrese la calificacion del alumno " << i << std :: endl;
	std :: cin >> nota;
    if(nota > 10 || nota < 0){
      throw std::invalid_argument("La nota debe estar entre 0 y 10 ");
    }
    if(nota >= 6){
      aprobados += 1;
    }else{
      desaprobados += 1;
    }
    
  }
  return alumnos;
}


int main(){
  int aprobados = 0;
  int desaprobados = 0;
  int total = promedioExamenes(aprobados,desaprobados);
  std :: cout << aprobados << " Alumnos Aprobados" << std :: endl;
  std :: cout << desaprobados << " Alumnos Desaprobados"<< std :: endl; 
  if ((total * 2)/3 <= aprobados){
    std :: cout << "Se pueden incrementar las plazas " << std :: endl;
  
  }
  return 0;
}
