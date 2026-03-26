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
<img width="961" height="602" alt="image" src="https://github.com/user-attachments/assets/02d69d9b-7013-429c-bb14-bf2707342df1" />


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
|1000|vector|0.00109343 s|0.000223843 s|4.73961e-05 s|0.0150629 s|
||deque|0.0011764 s|0.000255723 s|2.33601e-05 s|0.0160936 s|
||list|0.00222662 s|0.00011662 s|5.8369e-05 s|0.0268116 s|
|10000|vector|0.00748536 s|0.0017685 s|0.000418871 s|0.104288 s|
||deque|0.00727007 s|0.0018052 s|0.000176451 s|0.10037 s|
||list|0.00776144 s|0.000899813 s|0.000264103 s|0.0968022 s|
|100000|vector|0.0648436 s|0.0198073 s|0.00263298 s|0.948207 s|
||deque|0.0660978 s|0.0284962 s|0.00438131 s|1.06749 s|
||list|0.0746969 s|0.0320453 s|0.0119148 s|1.26869 s|
|1000000|vector|0.786861 s|0.287081 s|0.0247132 s|11.9246 s|
||deque|1.05579 s|0.588503 s|0.0706132 s|18.4127 s|
||list|1.16024 s|0.869596 s|0.201782 s|23.4797 s|
|10000000|vector|7.38028 s|3.29503 s|0.223495 s|116.854 s|
||deque|6.91557 s|4.58473 s|0.550252 s|128.41 s|
||list|9.83483 s|11.3925 s|1.90237 s|241.494 s|
