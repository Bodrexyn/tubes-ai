// create variable
let memberIPKBuruk = 0;
let memberIPKCukup = 0;
let memberIPKBagus = 0;
let memberGajiKecil = 0;
let memberGajiSedang = 0;

function anggotaIPK(inputIPK) {
   if (inputIPK <= 2.75) {
      memberIPKBuruk = 1;
   } else {
      if (inputIPK < 3.0) {
         memberIPKBuruk = (-inputIPK + 3.0) / 0.25;
      } else {
         memberIPKBuruk = 0;
      }
   }

   if (inputIPK <= 2.75 || inputIPK >= 3.25) {
      memberIPKCukup = 0;
   } else {
      if (inputIPK > 2.75 && inputIPK < 3.0) {
         memberIPKCukup = (inputIPK - 2.75) / 0.25;
      } else {
         if (inputIPK > 3.0 && inputIPK < 3.25) {
            memberIPKCukup = (-inputIPK + 3.25) / 0.25;
         } else {
            memberIPKCukup = 1;
         }
      }
   }

   if (inputIPK <= 3.0) {
      memberIPKBagus = 0;
   } else {
      if (inputIPK > 3.0 && inputIPK < 3.25) {
         memberIPKBagus = (inputIPK - 3.0) / 0.25;
      } else {
         memberIPKBagus = 1;
      }
   }
}

function cetakMember() {
   console.log("--------------Proses Fuzzifikasi-----------\n");
   console.log("Nilai fuzzifikasi IPK\n");
   console.log("Buruk\n" + memberIPKBuruk.toFixed(2));
   console.log("Cukup\n" + memberIPKCukup.toFixed(2));
   console.log("Bagus\n" + memberIPKBagus.toFixed(2));
}

// main function
let ipk = 3.2;
anggotaIPK(ipk);
cetakMember();