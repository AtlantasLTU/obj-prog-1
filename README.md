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

## 1 strategija:
|Studentų kiekis|Konteineris|Nuskaitymas (s)|Rūšiavimas (s)|Skirstymas (s)|Bendra trukmė (s)|
|---------|------------------|---------------------------|------------------------------|-------------------------------|-------------------------------|
|1000|vector|0.00179815 s|0.000321597 s|7.33831e-05 s|0.0240027 s|
||deque|0.00184705 s|0.000396967 s|8.39387e-05 s|0.0256645 s|
||list|0.00192091 s|0.000163213 s|9.99378e-05 s|0.0239348 s|
|10000|vector|0.00759772 s|0.0020095 s|0.000353466 s|0.10886 s|
||deque|0.00629947 s|0.00179072 s|0.000304026 s|0.0917307 s|
||list|0.012176 s|0.00178096 s|0.000766612 s|0.162318 s|
|100000|vector|0.0644973 s|0.0197933 s|0.0125853 s|1.04408 s|
||deque|0.0681471 s|0.0276978 s|0.0111462 s|1.16254 s|
||list|0.0658169 s|0.0328695 s|0.0133042 s|1.20127 s|
|1000000|vector|0.707928 s|0.252766 s|0.136163 s|11.7275 s|
||deque|0.658616 s|0.406434 s|0.188184 s|13.3113 s|
||list|0.65788 s|0.652715 s|0.181526 s|15.7181 s|
|10000000|vector|10.9459 s|5.24866 s|1.92524 s|195.436 s|
||deque|10.3159 s|6.803 s|2.42005 s|208.372 s|
||list|13.8479 s|14.235 s|2.44039 s|322.286 s|

## 2 strategija:
|Studentų kiekis|Konteineris|Nuskaitymas (s)|Rūšiavimas (s)|Skirstymas (s)|Bendra trukmė (s)|
|---------|------------------|---------------------------|------------------------------|-------------------------------|-------------------------------|
|1000|vector|0.000884075 s|0.000132972 s|3.25692e-05 s|0.0113803 s|
||deque|0.00187458 s|0.000390499 s|2.36846e-05 s|0.0251699 s|
||list|0.00182821 s|0.000170479 s|4.34549e-05 s|0.0225838 s|
|10000|vector|0.00730136 s|0.00175621 s|0.000286039 s|0.102498 s|
||deque|0.0100728 s|0.00358392 s|0.000155572 s|0.154021 s|
||list|0.0175678 s|0.00279408 s|0.000677829 s|0.234293 s|
|100000|vector|0.115666 s|0.0367263 s|0.00415804 s|1.70555 s|
||deque|0.130116 s|0.050305 s|0.00671793 s|2.03399 s|
||list|0.154279 s|0.0642486 s|0.0269414 s|2.7096 s|
|1000000|vector|1.53402 s|0.516987 s|0.0281033 s|22.4944 s|
||deque|1.05553 s|0.582564 s|0.0585986 s|18.0941 s|
||list|1.4284 s|1.0403 s|0.308256 s|30.0664 s|
|10000000|vector|8.80566 s|3.40267 s|0.223391 s|133.342 s|
||deque|11.2 s|7.51763 s|0.640033 s|208.347 s|
||list|12.4593 s|15.4063 s|3.0205 s|330.893 s|
