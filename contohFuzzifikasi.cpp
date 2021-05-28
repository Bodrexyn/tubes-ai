#include <iostream>
#include <stdio.h>
using namespace std;
class Fuzzy
{
   float memberIPKBuruk = 0;
   float memberIPKCukup = 0;
   float memberIPKBagus = 0;

public:
   //Keanggotaan IPK
   void anggotaIPK(float inputIPK)
   {
      if (inputIPK <= 2.75)
      {
         memberIPKBuruk = 1;
      }
      else
      {
         if (inputIPK < 3.0)
         {
            memberIPKBuruk = (float)((-inputIPK + 3.00) / 0.25);
         }
         else
            memberIPKBuruk = 0;
      }

      if (inputIPK <= 2.75 || (inputIPK >= 3.25))
      {
         memberIPKCukup = 0;
      }
      else
      {
         if (inputIPK > 2.75 && inputIPK < 3.00)
         {
            memberIPKCukup = (float)((inputIPK - 2.75) / 0.25);
         }
         else
         {
            if (inputIPK > 3.00 && inputIPK < 3.25)
            {
               memberIPKCukup = (float)((-inputIPK + 3.25) / 0.25);
            }
            else
               memberIPKCukup = 1;
         }
      }

      if (inputIPK <= 3.00)
      {
         memberIPKBagus = 0;
      }
      else
      {
         if (inputIPK > 3.00 && inputIPK < 3.25)
         {
            memberIPKBagus = (float)((inputIPK - 3.00) / 0.25);
         }
         else
            memberIPKBagus = 1;
      }
   }

   void cetakMember()
   {
      cout << " \n\n----------PROSES FUZZIFIKASI----------\n"
           << endl;
      cout << " Nilai Fuzzy IPK" << endl;
      cout << "Buruk \n"
           << memberIPKBuruk << endl;
      cout << "Cukup \n"
           << memberIPKCukup << endl;
      cout << "Bagus \n"
           << memberIPKBagus << endl;
   }
};
int main()
{
   float ipk;
   Fuzzy test;
   cout << "Masukkan nilai IPK: " << endl;
   cin >> ipk;
   test.anggotaIPK(ipk);
   test.cetakMember();
   return 0;
}