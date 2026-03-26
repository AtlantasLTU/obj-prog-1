# Programos naudojimas:
  ## Reikalavimai:
    C++ kompiliatorius su C++20 palaikymu.
    Unix OS (Linux arba MacOS) arba WSL (Windows Subsystem for Linux)
    git

  ## Programos paleidimas:
    git clone https://github.com/AtlantasLTU/obj-prog-1.git
    cd ./obj-prog-1
    make
    ./main

# Testavimas:

- Kompiuterio, su kuriuo testuota parametrai:
<img width="1003" height="602" alt="image" src="https://github.com/user-attachments/assets/26ed66b3-804f-405e-9c00-3e046e22d2a3" />


#### Atlikta programos veikimo greičio (spartos) analizė: t.y. išmatuota programos sparta, išskiriant kiek laiko užtruko kiekvienas iš žemiau išvardintų žingsnių:
- duomenų nuskaitymas iš failų į atitinkamą konteinerį (Failai visiems tyrimams tie patys, tyrimo patikimumui); 
- studentų rūšiavimas didėjimo tvarka konteineryje (funkcija sort);
- studentų skirstymo  į dvi grupes/kategorijas (naujų konteinerių su skirtingais studentais kūrimas);

#### Skirstymo strategijos:
- 0 - pradiniame relize naudota strategija;
- 1 strategija: Bendro studentai konteinerio (vector, list ir deque tipų) skaidymas (rūšiavimas) į du naujus to paties tipo konteinerius: "vargšiukų" ir "kietiakų".
- 2 strategija: Bendro studentų konteinerio (vector, list ir deque) skaidymas (rūšiavimas) panaudojant tik vieną naują konteinerį: "vargšiukai".
- 3 strategija: Bendro studentų konteinerio (vector, list ir deque) skaidymas (rūšiavimas) panaudojant greičiausiai veikianti 1 arba 2 strategiją  įtraukiant į ją "efektyvius" darbo su konteineriais metodus.

Programa kompiliuota su -Ofast veliavėle: "g++ --std=c++20 -Ofast *.cpp -o main".
Testuota tik naudojant terminalą, visos kitos pašalinės programos testavimo metu buvo išjungtos bei įrenginys "performance" režime.
Visi testavimo atvejai testuoti 10 kartų, su medianų skaičiavimu.
Į bendrą trukmę taip pat įeina skaičiavimų trukmė.

## 0 strategija:
|Studentų kiekis|Konteineris|Nuskaitymas (s)|Rūšiavimas (s)|Skirstymas (s)|Bendra trukmė (s)|
|---------|------------------|---------------------------|------------------------------|-------------------------------|-------------------------------|
|1000|vector|0.000983345 s|0.000192645 s|3.57552e-05 s|0.0121175 s|
||deque|0.00137017 s|0.000271119 s|2.40431e-05 s|0.0166533 s|
||list|0.00119636 s|0.000107939 s|5.43623e-05 s|0.0135866 s|
|10000|vector|0.00742587 s|0.00159872 s|0.000445567 s|0.0947015 s|
||deque|0.00625149 s|0.00187195 s|0.000177409 s|0.0830085 s|
||list|0.00845551 s|0.00118747 s|0.00046127 s|0.101043 s|
|100000|vector|0.158093 s|0.0447305 s|0.00373089 s|2.06555 s|
||deque|0.086463 s|0.0461548 s|0.00446084 s|1.37079 s|
||list|0.10791 s|0.0456203 s|0.016041 s|1.69571 s|
|1000000|vector|0.752845 s|0.277954 s|0.024425 s|10.5522 s|
||deque|0.671213 s|0.391769 s|0.0530131 s|11.1599 s|
||list|0.659179 s|0.632095 s|0.16078 s|14.5205 s|
|10000000|vector|8.63254 s|4.06191 s|0.24063 s|129.351 s|
||deque|12.9742 s|8.47272 s|1.15956 s|226.065 s|
||list|14.9606 s|14.1323 s|2.62529 s|317.182 s|
