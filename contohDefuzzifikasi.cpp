#include <iostream>
#include <stdio.h>
using namespace std;
class Fuzzy
{
   float memberIPKBuruk = 0;
   float memberIPKCukup = 0;
   float memberIPKBagus = 0;
   float terbesarX = 0;
   float terbesarY = 0;
   float memberGajiKecil = 0;
   float memberGajiSedang = 0;
   float memberGajiBesar = 0;
   float memberGajiSgtBesar = 0;

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
      cout << " Nilai Fuzzy Gaji" << endl;
      cout << "Kecil \n"
           << memberGajiKecil << endl;
      cout << "Sedang \n"
           << memberGajiSedang << endl;
      cout << "Besar \n"
           << memberGajiBesar << endl;
      cout << "Sangat Besar \n"
           << memberGajiSgtBesar << endl;
   }

   void anggotaGaji(float inputGaji)
   {
      if (inputGaji <= 2)
      {
         memberGajiKecil = 1;
      }
      else
      {
         if (inputGaji >= 2 && inputGaji <= 4)
         {
            memberGajiKecil = (float)((-inputGaji + 4) / 2);
         }
         else
            memberGajiKecil = 0;
      }
      if (inputGaji >= 4 && inputGaji <= 6)
      {
         memberGajiSedang = 1;
      }
      else
      {
         if (inputGaji > 2 && inputGaji < 4)
         {
            memberGajiSedang = (float)((inputGaji - 2) / 2);
         }
         else
         {
            if (inputGaji > 6 && inputGaji < 8)
            {
               memberGajiSedang = (float)((-inputGaji + 8) / 2);
            }
            else
               memberGajiSedang = 0;
         }
      }
      if (inputGaji >= 8 && inputGaji <= 9)
      {
         memberGajiBesar = 1;
      }
      else
      {
         if (inputGaji > 6 && inputGaji < 8)
         {
            memberGajiBesar = (float)((inputGaji - 6) / 2);
         }
         else
         {
            if (inputGaji > 9 && inputGaji < 14)
            {
               memberGajiBesar = (float)((-inputGaji + 14) / 5);
            }
            else
               memberGajiBesar = 0;
         }
      }
      if (inputGaji <= 9)
      {
         memberGajiSgtBesar = 0;
      }
      else
      {
         if (inputGaji > 9 && inputGaji < 14)
         {
            memberGajiSgtBesar = (float)((inputGaji - 9) / 5);
         }
         else
            memberGajiSgtBesar = 1;
      }
   };

   void inferensi()
   {
      int k = 0;
      float nilaiKondisi[4];
      string kondisi[4];
      float nilaiIPK[3] = {memberIPKBuruk,
                           memberIPKCukup, memberIPKBagus};
      float nilaiGaji[4] = {memberGajiKecil,
                            memberGajiSedang, memberGajiBesar, memberGajiSgtBesar};
      //Menentukan rules dan nilai minimum
      for (int i = 0; i < 3; i++)
      {
         for (int j = 0; j < 4; j++)
         {
            if ((nilaiIPK[i] > 0) && (nilaiGaji[j] >
                                      0))
            {
               if (nilaiIPK[i] < nilaiGaji[j])
               {
                  nilaiKondisi[k] = nilaiIPK[i];
               }
               else
               {
                  nilaiKondisi[k] = nilaiGaji[j];
               }
               if ((i == 0) && (j >= 0))
               {
                  kondisi[k] = "RENDAH";
               }
               else if ((i == 1) && (j > 0))
               {
                  kondisi[k] = "RENDAH";
               }
               else if ((i == 2) && (j > 2))
               {
                  kondisi[k] = "RENDAH";
               }
               else
               {
                  kondisi[k] = "TINGGI";
               }
               cout << "Ketika IPK " << nilaiIPK[i] << " dan GAJI " << nilaiGaji[j] << " maka siswa " << kondisi[k] << " dengan nilai = " << nilaiKondisi[k]
                    << endl;
               k = k + 1;
            }
         }
      }
      //menentukan nilai max
      for (int i = 0; i < k; i++)
      {
         if (kondisi[i] == "RENDAH")
         {
            if (i == 0)
            {
               terbesarX = nilaiKondisi[i];
            }
            else
            {
               if (nilaiKondisi[i] > terbesarX)
               {
                  terbesarX = nilaiKondisi[i];
               }
            }
         }
         else
         {
            if (i == 0)
            {
               terbesarY = nilaiKondisi[i];
            }
            else
            {
               if (nilaiKondisi[i] > terbesarY)
               {
                  terbesarY = nilaiKondisi[i];
               }
            }
         }
      }
      if (terbesarX > 0)
      {
         cout << endl
              << "Nilai siswa TIDAK BEASISWA \t= "
              << terbesarX << endl;
      }
      if (terbesarY > 0)
      {
         cout << endl
              << "Nilai DAPAT BEASISWA \t\t= " << terbesarY
              << endl;
      }
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