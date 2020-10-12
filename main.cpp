#include <iostream>

using namespace std;

int *  CrearArreglo(size_t n);
void LlenarArreglo(int *pA,size_t n);
void   Imprimir(int *pA, size_t num);
void  Conteo(const int *pA,size_t num, size_t *m5,size_t *m7);
void LlenarMultiplos(const int *pA, size_t num, int *pAMul,size_t multiplo);
void LiberarMemoria(int * &pA);

int main()
{
  size_t num=0;
  int * pA= nullptr;
  size_t m5=0,m7=0;
  int *pA5= nullptr;
  int *pA7= nullptr;

  srand(time(nullptr));
  cout << "Numero de elementos: ";
  cin >> num;
  pA = CrearArreglo(num);
  LlenarArreglo(pA, num);
  Imprimir(pA, num);
  Conteo(pA,num, &m5,&m7);
  pA5 = CrearArreglo(m5);
  pA7 = CrearArreglo(m7);
  LlenarMultiplos(pA,num,pA5,5);
  LlenarMultiplos(pA,num,pA7,7);
  cout << "\nMultiplos de 5, hay " << m5 << " \n";
  Imprimir(pA5,m5);
  cout << "\nMultiplos de 7, hay " << m7 << "\n";
  Imprimir(pA7,m7);
  LiberarMemoria(pA);
  LiberarMemoria(pA5);
  LiberarMemoria(pA7);
  return 0;
}

int *  CrearArreglo(size_t n)
//---------------------------
{
  return (new int[n]());
}

void LlenarArreglo(int *pA,size_t n)
//----------------------------------
{
  for(int i=0; i<n; i++)
    pA[i] = rand()%999+1;
}

void   Imprimir(int *pA, size_t num)
//-----------------------------------
{
  cout << "\n";
  for(int i=0; i<num; i++)
    cout << "pA[" << i << "] = " << pA[i]<<"\n";
}

void  Conteo(const int *pA,size_t num, size_t *m5,size_t *m7)
{//-----------------------------------------------------
  *m5=*m7=0;
  for(size_t i=0; i<num; i++) {
    if (pA[i] % 5 == 0)
      *m5 = *m5 + 1;
    if (pA[i] % 7 == 0)
      *m7 = *m7 +1;
  }
}

void LlenarMultiplos(const int *pA, size_t num, int *pAMul,size_t multiplo)
{//-----------------------------------------------------------------
 size_t iMul=0;
 for(size_t i=0; i<num; i++)
   if(pA[i]%multiplo==0)
     pAMul[iMul++]=pA[i];
}

void LiberarMemoria(int * &pA)
{
  delete[]pA;
  pA = nullptr;
}
