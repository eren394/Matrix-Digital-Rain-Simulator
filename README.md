#  Matrix Digital Rain Simulator (C++)

"Unfortunately, no one can be told what the Matrix is. You have to see it for yourself."

Bu proje, Matrix filmlerinin ikonik "Dijital Yağmur" efektini modern C++ kullanarak terminalde canlandıran, düşük seviyeli (low-level) sistem programlama pratikleri içeren bir simülatördür.

##  Özellikler
- **Zero-Dependency:** Harici hiçbir kütüphane (OpenGL, DirectX vb.) gerektirmez. Saf C++ Standart Kütüphanesi ile yazılmıştır.
- **Sleep-Cycle Awareness:** İşletim sisteminin uyku/hazırda bekletme modlarını takip eder ve sistem uyandığında simülasyonu otomatik olarak senkronize eder.
- **ANSI Escape Engine:** Terminal manipülasyonu için ham ANSI kaçış kodlarını kullanır.
- **Object-Oriented Design:** Her bir yağmur sütunu, kendi hızını, uzunluğunu ve karakter değişimini yöneten bağımsız bir nesnedir.

##  Kurulum ve Çalıştırma

### Gereksinimler
- C++17 veya üzeri bir derleyici (GCC, Clang veya MSVC).

### Derleme
```bash
g++ main.cpp -o matrix
