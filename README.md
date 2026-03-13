# obj-prog-1
Patobulinta išvestis
Pridėtas skirstymas į "galvočius" ir "vargšiukus".
Pridėtas failų generavimas
Pridėtas failų pasirinkimas

Testavimas:

- Kompiuterio, su kuriuo testuota parametrai:
<img width="986" height="671" alt="image" src="https://github.com/user-attachments/assets/3c286ba1-2734-41c3-9942-e271b1e1a4e2" />

Atlikta programos veikimo greičio (spartos) analizė: t.y. išmatuota programos sparta, išskiriant kiek laiko užtruko kiekvienas iš žemiau išvardintų žingsnių:
- 1 tyrimas (failo generavimas):  
failų kūrimas ir jų uždarymas.

- 2 tyrimas (duomenų apdorojimas iš esančių testavimo failų):
        duomenų nuskaitymas iš failo (paprastai matavimo pradžią, kadangi reikia skaityti tuos pačius failus, kad operacijų kiekis išliktų toks pat);
        studentų rūšiavimas į dvi grupes/kategorijas (į atskirus konteinerius);
        surūšiuotų studentų išvedimas į du naujus failus.
        visos programos veikimo laikas

Programa kompiliuota su -O2 veliavėle: "g++ --std=c++20 -O2 *.cpp -o main".
Testuota tik naudojant terminalą, visos kitos pašalinės programos testavimo metu buvo išjungtas bei įrenginys "performance" režime.

- 1 tyrimas atliktas 10 kartų, su 10 atsitiktinių namų darbų generuojamų kiekvienam studentui. (t.y. kiekvienas failas sugeneruotas 10 kartų ir išvestas vidutinis generavimo laikas)

|Laikas|studentai1000.txt|studentai10000.txt|studentai100000.txt|studentai1000000.txt|studentai10000000.txt|
|---------|------------------|---------------------------|------------------------------|-------------------------------|-------------------------------|
|Failo generavimo vidurkis|0.0043508 s|0.0604668 s|0.6221 s|7.15733 s|76.5889 s|

<img width="654" height="1377" alt="image" src="https://github.com/user-attachments/assets/2bddaa1a-1e37-4779-a02c-55997914123c" />


- 2 tyrimas kiekvienam failui atliktas 10 kartų, su medianos skaičiavimais. Lentelėje yra praleistų duomenų, kurie matomi nuotraukose.

|Laikas|studentai1000.txt|studentai10000.txt|studentai100000.txt|studentai1000000.txt|studentai10000000.txt|
|---------|------------------|---------------------------|------------------------------|-------------------------------|-------------------------------|
|Duomenų nuskaitymo vidurkis|0.0013552 s|0.0168587 s|0.123717 s|1.41954 s|13.4566 s|
|Studentų skirstymo į du konteinerius vidurkis|4.31213e-05 s|0.000543653 s|0.00393585 s|0.0308791 s|0.281222 s|
|Studentų išvedimo (vargsiukai.txt+galvociai.txt) vidurkis|6.84614e-04 s|6.71012e-03 s|0.0393036 s|0.553675 s|5.02019 s|
|Bendra trukmė|0.0246013 s|0.302279 s|2.15488 s|27.0308 s|269.872 s|

<img width="958" height="1403" alt="image" src="https://github.com/user-attachments/assets/ec429f43-ca8f-49d4-bd2f-6863fb9a2cf1" />

<img width="959" height="1366" alt="image" src="https://github.com/user-attachments/assets/62b6efa4-184e-4f88-9f60-48d1eff1affd" />

