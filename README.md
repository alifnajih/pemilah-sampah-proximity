# pemilah-sampah-proximity

---

## 🔹 Fungsi Program

Kode ini adalah untuk **alat pemilah sampah otomatis** menggunakan:

1. **Sensor proximity induktif** → mendeteksi sampah logam (anorganik).
2. **Servo** → menggerakkan pintu/katup untuk membuang sampah ke tempat organik atau anorganik.
3. **IR remote (receiver)** → sudah di-setup, tapi di dalam `loop()` belum dipakai (jadi saat ini belum berfungsi).

---

## 🔹 Cara Kerja Program

1. **Setup:**

   * Servo dihubungkan ke pin 9.
   * Sensor proximity di pin 8 sebagai input.
   * IR receiver di pin 11, sudah diaktifkan (`irrecv.enableIRIn()`), tapi belum ada logika kontrol.

2. **Loop utama:**

   * Membaca nilai sensor:

     * Jika **LOW** → berarti sensor mendeteksi logam → dianggap **sampah anorganik**.

       * Servo digerakkan ke **180°** → buang ke tong anorganik.
       * Setelah 1 detik, servo kembali ke **0°** (posisi awal).
     * Jika **HIGH** → berarti tidak ada logam → dianggap **sampah organik**.

       * Servo digerakkan ke **90°** → buang ke tong organik.
       * Setelah 0.5 detik, servo kembali ke **0°**.

---

## 🔹 Kekurangan Program

1. **IR remote** sudah diinisialisasi, tapi belum digunakan. Jadi saat ini, remote tidak berfungsi.
2. **Servo hanya punya 2 posisi** (180° untuk anorganik, 90° untuk organik). Kalau pintunya harus berbeda arah (misalnya kiri-kanan), sebaiknya pakai posisi **misalnya 0° untuk organik dan 180° untuk anorganik**.
3. Delay terlalu pendek bisa bikin servo belum sempat bergerak penuh.

---

## 🔹 Saran Perbaikan

Kalau kamu mau benar-benar menggunakan IR remote, misalnya untuk **mode manual/otomatis**, bisa ditambahkan logika seperti ini:

```cpp
if (irrecv.decode(&results)) {
  Serial.println(results.value, HEX); // Lihat kode tombol di Serial Monitor
  irrecv.resume(); // Siap terima data berikutnya

  if (results.value == 0xFFA25D) { // Contoh kode tombol Power
    Serial.println("Mode Manual Aktif");
    myservo.write(0); // Servo ke posisi default
  }
}
```

---

## 🔹 Kesimpulan

* Saat ini program sudah bisa **membedakan organik/anorganik** menggunakan sensor proximity induktif.
* IR remote masih belum dipakai.
* Servo gerak ke **180° = anorganik**, **90° = organik**, lalu balik ke **0°**.
