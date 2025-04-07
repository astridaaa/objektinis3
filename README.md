# OOP

Programa skirta failų, turinčių skirtingą studentų skaičių, testavimui su STL konteineriais: vektoriumi, dvipuse eile bei sąrašu.

# Kompiuterio specifikacijos
- AMD Ryzen 5 5500U CPU
- 32 GB RAM
- 256GB SSD storage

 # Naudojimosi instrukcija:
- <a href="https://gnuwin32.sourceforge.net/packages/make.htm">Susiinstaliuoti make; </a>
- Parsisiųsti v1.0 versiją;
- Terminale atsidarius versijos direktoriją paleisti:
    - `make run_main` - norint paleisti antrą tyrimą _(v0.4)_
    - `make run1` - norint paleisti 1 strategiją 
    - `make run2` - norint paleisti 2 strategiją
    - `make run3` - norint paleisti 3 strategiją

# Programos aprašas:
Pagrindinės funkcijos:
-    `nuskaitymasFile()` - template funkcija skirta nuskaityti duomenis iš failo
-    `studentuIsskirstymas()` - pirmajai strategijai skirta funkcija studentus skirstyti į "pirmūnus" ir "nesimokančius"
-    `studentuIsskirstymas2()` - studentų išskirstymas nuo galo naudojant iteratorių
-    `studentuSkirstymas3()` - studentų išskirstymas "nesimokančius" perkeliant į kitą konteinerį
-    `studentuRusiavimas() / studentuRusiavimas2() / studentuRusiavimas3()` - studentai rikiuojami pagal pasirinktus kriterijus: vardą, pavardę arba galutinį balą, skaičiuojamą pagal vidurkį
## v1.1 versija | klasių implementacija
- Pasirinkta strategija: 3 strategija (STL algoritmų implementacija);
- Pasirinktas konteineris: sąrašas;
<table class ="fixed">
    <thead>
        <tr>
            <th width=100px></th>
            <th colspan =3><h2>Klasė</h2></th>
            <th colspan =3><h2> Struktūra</h2></th>
        </tr>
    </thead>
    <tbody>
        <tr>
            <td><b>Kompiliavimo vėliava</b></td>
            <td><b>Studentai100000.txt bendras programos vidutinis vykdymo laikas (s)</b></td>
            <td><b>Studentai1000000.txt bendras programos vidutinis vykdymo laikas (s)</b></td>
            <td><b>.exe failo dydis (KB)</b></td>
            <td><b>Studentai100000.txt bendras programos vidutinis vykdymo laikas (s)</b></td>
            <td><b>Studentai1000000.txt bendras programos vidutinis vykdymo laikas (s)</b></td>
            <td><b>.exe failo dydis (KB)</b></td>
        </tr>
        <tr>
            <td>-</td>
            <td>0.558468</td>
            <td>6.91962</td>
            <td>504</td>
            <td>0.409334</td>
            <td>4.94592</td>
            <td>659</td>
        </tr>
        <tr>
            <td>-O1</td>
            <td>0.322322</td>
            <td>4.40381</td>
            <td>283</td>
            <td>0.262666</td>
            <td>3.46008</td>
            <td>328</td>
        </tr>
        <tr>
            <td>-O2</td>
            <td>0.323005</td>
            <td>4.32484</td>
            <td>277</td>
            <td>0.255264</td>
            <td>3.59824</td>
            <td>325</td>
        </tr>
        <tr>
            <td>-O3</td>
            <td>0.370384</td>
            <td>4.12048</td>
            <td>273</td>
            <td>0.256171</td>
            <td>3.65432</td>
            <td>337</td>
        </tr>
    </tbody>
</table>

![image](https://github.com/user-attachments/assets/104a89cd-87d2-456e-a9f2-890a434c034f)

![image](https://github.com/user-attachments/assets/a10f7e54-e4fe-48ef-b793-c06ade5b914e)

![image](https://github.com/user-attachments/assets/4d3b6f9f-1f16-48e4-a388-ff54d30b1d3b)





## v0.4 implementacija naudojant funkcijų šablonus
<table class ="fixed">
    <thead>
        <tr>
            <th width=100px></th>
            <th width=100px> Konteinerio tipas</th>
            <th width=100px> Nuskaitymas iš failo (s)</th>
            <th width=100px> Rikiavimas (s) </th>
            <th width=100px> Skirstymas į "pirmūnus" ir "nesimokančius" (s) </th>
            <th width=100px> Bendras programos vykdymo laikas (s) </th>
        </tr>
    </thead>
    <tbody>
        <tr>
            <td rowspan=3>Studentai1000.txt</td>
            <td>Vektorius</td>
            <td>0</td>
            <td>0.004</td>
            <td>0</td>
            <td><b>0.004</b></td>
        </tr>
        <tr>
            <td>Dvipusė eilė</td>
            <td>0.002</td>
            <td>0.001</td>
            <td>0</td>
            <td><b>0.003</b></td>
        </tr>
        <tr>
            <td>Sąrašas</td>
            <td>0</td>
            <td>0.001</td>
            <td>0</td>
            <td><b>0.001</b></td>
        </tr>
        <tr>
            <td rowspan = 3>Studentai10000.txt</td>
            <td>Vektorius</td>
            <td>0.012</td>
            <td>0.004</td>
            <td>0</td>
            <td><b>0.016</b></td>
        </tr>
        <tr>
            <td>Dvipusė eilė</td>
            <td>0.014</td>
            <td>0.005</td>
            <td>0</td>
            <td><b>0.019</b></td>
        </tr>
        <tr>
            <td>Listas</td>
            <td>0.015</td>
            <td>0.001</td>
            <td>0.002</td>
            <td><b>0.018</b></td>
        </tr>
        <tr>
            <td rowspan=3>Studentai100000.txt</td>
            <td>Vektorius</td>
            <td>0.083</td>
            <td>0.076</td>
            <td>0.018</td>
            <td><b>0.177</b></td>
        </tr>
        <tr>
            <td>Dvipusė eilė</td>
            <td>0.095</td>
            <td>0.098</td>
            <td>0.017</td>
            <td><b>0.021</b></td>
        </tr>
        <tr>
            <td>Sąrašas</td>
            <td>0.098</td>
            <td>0.038</td>
            <td>0.021</td>
            <td><b>0.157</b></td>
        </tr>
      <tr>
            <td rowspan=3>Studentai1000000.txt</td>
            <td>Vektorius</td>
            <td>1.142</td>
            <td>1.027</td>
            <td>0.200</td>
            <td><b>2.369</b></td>
        </tr>
        <tr>
            <td>Dvipusė eilė</td>
            <td>1.207</td>
            <td>1.355</td>
            <td>0.176</td>
            <td><b>2.738</b></td>
        </tr>
        <tr>
            <td>Sąrašas</td>
            <td>1.288</td>
            <td>0.616</td>
            <td>0.209</td>
            <td><b>2.113</b></td>
        </tr>
      <tr>
            <td rowspan=3>Studentai10000000.txt</td>
            <td>Vektorius</td>
            <td>11.537</td>
            <td>13.629</td>
            <td>1.967</td>
            <td><b>27.133</b></td>
        </tr>
        <tr>
            <td>Dvipusė eilė</td>
            <td>12.135</td>
            <td>18.076</td>
            <td>1.771</td>
            <td><b>31.982</b></td>
        </tr>
        <tr>
            <td>Sąrašas</td>
            <td>13.013</td>
            <td>7.682</td>
            <td>2.116</td>
            <td><b>22.811</b></td>
        </tr>
    </tbody>
</table>











![image](https://github.com/user-attachments/assets/91d1abe2-b88f-4a38-9e7f-404530484eab)








-----
# Strategijų aprašymai:
-    Pirmoji strategija išskirsto studentus į dvi grupes: "nesimokantys" ir "pirmūnai" palikdama studentus ne tik naujame konteineryje, bet ir "studentai" pradiniame konteineryje.
-    Antroji strategija pirmiausia studentus surikiuoja, tuomet juos išskirsto: "nesimokantys" perkeliami į atskirą konteinerį, o "pirmūnai" paliekami studentų konteineryje.
-    Trečioji strategija tai antrosios strategijos implementacija naudojant `std::partition` , `std::copy` , `std::erase`.

<details>
    <summary><h2>1 strategija</h2></summary>
    <table class ="fixed">
    <thead>
        <tr>
            <th width=100px></th>
            <th width=100px> Konteinerio tipas</th>
            <th width=100px> Nuskaitymas iš failo (s)</th>
            <th width=100px> Rikiavimas (s) </th>
            <th width=100px> Skirstymas į "pirmūnus" ir "nesimokančius" (s) </th>
            <th width=100px> Bendras programos vykdymo laikas (s) </th>
        </tr>
    </thead>
    <tbody>
        <tr>
            <td rowspan=3>Studentai1000.txt</td>
            <td>Vektorius</td>
            <td>0.00823915</td>
            <td>0</td>
            <td>0</td>
            <td><b>0.00823915</b></td>
        </tr>
        <tr>
            <td>Dvipusė eilė</td>
            <td>0.0048692</td>
            <td>0.001</td>
            <td>0.00172235</td>
            <td><b>0.00759155</b></td>
        </tr>
        <tr>
            <td>Sąrašas</td>
            <td>0.0039488</td>
            <td>0</td>
            <td>0</td>
            <td><b>0.0039488</b></td>
        </tr>
        <tr>
            <td rowspan = 3>Studentai10000.txt</td>
            <td>Vektorius</td>
            <td>0.0262587</td>
            <td>0.0058331</td>
            <td>0.01</td>
            <td><b>0.0420918</b></td>
        </tr>
        <tr>
            <td>Dvipusė eilė</td>
            <td>0.0337307</td>
            <td>0.00829305</td>
            <td>0.0115557</td>
            <td><b>0.05357945</b></td>
        </tr>
        <tr>
            <td>Listas</td>
            <td>0.03489</td>
            <td>0.005</td>
            <td>0.01</td>
            <td><b>0.04989</b></td>
        </tr>
        <tr>
            <td rowspan=3>Studentai100000.txt</td>
            <td>Vektorius</td>
            <td>0.273982</td>
            <td>0.125936</td>
            <td>0.0947833</td>
            <td><b>0.4947013</b></td>
        </tr>
        <tr>
            <td>Dvipusė eilė</td>
            <td>0.288499</td>
            <td>0.155954</td>
            <td>0.080126</td>
            <td><b>0.524579</b></td>
        </tr>
        <tr>
            <td>Sąrašas</td>
            <td>0.207837</td>
            <td>0.03994</td>
            <td>0.09321</td>
            <td><b>0.340987</b></td>
        </tr>
      <tr>
            <td rowspan=3>Studentai1000000.txt</td>
            <td>Vektorius</td>
            <td>2.53419</td>
            <td>1.45217</td>
            <td>0.84538</td>
            <td><b>4.83174</b></td>
        </tr>
        <tr>
            <td>Dvipusė eilė</td>
            <td>2.6325</td>
            <td>1.79048</td>
            <td>0.741904</td>
            <td><b>5.164884</b></td>
        </tr>
        <tr>
            <td>Sąrašas</td>
            <td>2.72272</td>
            <td>0.608488</td>
            <td>0.845761</td>
            <td><b>4.176969</b></td>
        </tr>
      <tr>
            <td rowspan=3>Studentai10000000.txt</td>
            <td>Vektorius</td>
            <td>25.215</td>
            <td>18.9084</td>
            <td>8.07938</td>
            <td><b>52.20278</b></td>
        </tr>
        <tr>
            <td>Dvipusė eilė</td>
            <td>26.043</td>
            <td>23.1564</td>
            <td>7.65617</td>
            <td><b>56.85557</b></td>
        </tr>
        <tr>
            <td>Sąrašas</td>
            <td>27.1392</td>
            <td>7.11418</td>
            <td>8.69922</td>
            <td><b>42.9526</b></td>
        </tr>
    </tbody>
</table>







![image](https://github.com/user-attachments/assets/e5ab9812-702d-406b-88d8-bd6cbacd8929)


</details>

























<details>
    <summary><h2>2 strategija</h2></summary>
    <table class ="fixed">
    <thead>
        <tr>
            <th width=100px></th>
            <th width=100px> Konteinerio tipas</th>
            <th width=100px> Nuskaitymas iš failo (s)</th>
            <th width=100px> Rikiavimas (s) </th>
            <th width=100px> Skirstymas į "pirmūnus" ir "nesimokančius" (s) </th>
            <th width=100px> Bendras programos vykdymo laikas (s) </th>
        </tr>
    </thead>
    <tbody>
        <tr>
            <td rowspan=3>Studentai1000.txt</td>
            <td>Vektorius</td>
            <td>0.0065997</td>
            <td>0.007648</td>
            <td>0</td>
            <td><b>0.0142477</b></td>
        </tr>
        <tr>
            <td>Dvipusė eilė</td>
            <td>0</td>
            <td>0.0132348</td>
            <td>0</td>
            <td><b>0.0132348</b></td>
        </tr>
        <tr>
            <td>Sąrašas</td>
            <td>0</td>
            <td>0.0100254</td>
            <td>0</td>
            <td><b>0.0100254</b></td>
        </tr>
        <tr>
            <td rowspan = 3>Studentai10000.txt</td>
            <td>Vektorius</td>
            <td>0.0232996</td>
            <td>0.0219461</td>
            <td>0.0059915</td>
            <td><b>0.0512372</b></td>
        </tr>
        <tr>
            <td>Dvipusė eilė</td>
            <td>0.0277649</td>
            <td>0.0256593</td>
            <td>0.0012814</td>
            <td><b>0.0547056</b></td>
        </tr>
        <tr>
            <td>Listas</td>
            <td>0.028905</td>
            <td>0.0053132</td>
            <td>0</td>
            <td><b>0.0342182</b></td>
        </tr>
        <tr>
            <td rowspan=3>Studentai100000.txt</td>
            <td>Vektorius</td>
            <td>0.176522</td>
            <td>0.340928</td>
            <td>0.0350781</td>
            <td><b>0.5525281</b></td>
        </tr>
        <tr>
            <td>Dvipusė eilė</td>
            <td>0.189941</td>
            <td>0.435305</td>
            <td>0.0273773</td>
            <td><b>0.6526233</b></td>
        </tr>
        <tr>
            <td>Sąrašas</td>
            <td>0.210389</td>
            <td>0.171089</td>
            <td>0.0413665</td>
            <td><b>0.4228445</b></td>
        </tr>
      <tr>
            <td rowspan=3>Studentai1000000.txt</td>
            <td>Vektorius</td>
            <td>2.57467</td>
            <td>4.1003</td>
            <td>0.358227</td>
            <td><b>7.033197</b></td>
        </tr>
        <tr>
            <td>Dvipusė eilė</td>
            <td>2.62864</td>
            <td>5.06983</td>
            <td>0.349161</td>
            <td><b>8.047631</b></td>
        </tr>
        <tr>
            <td>Sąrašas</td>
            <td>2.75252</td>
            <td>1.60927</td>
            <td>0.367283</td>
            <td><b>4.729073</b></td>
        </tr>
      <tr>
            <td rowspan=3>Studentai10000000.txt</td>
            <td>Vektorius</td>
            <td>25.334</td>
            <td>50.6552</td>
            <td>3.23374</td>
            <td><b>79.22294</b></td>
        </tr>
        <tr>
            <td>Dvipusė eilė</td>
            <td>26.5166</td>
            <td>61.3732</td>
            <td>2.59927</td>
            <td><b>90.48907</b></td>
        </tr>
        <tr>
            <td>Sąrašas</td>
            <td>27.6354</td>
            <td>21.8511</td>
            <td>3.55478</td>
            <td><b>53.04128</b></td>
        </tr>
    </tbody>
</table>




![image](https://github.com/user-attachments/assets/f5694624-4663-44d2-b260-8a12cb6e4790)





</details>





<details>
    <summary><h2>3 strategija</h2></summary>
    <table class ="fixed">
    <thead>
        <tr>
            <th width=100px></th>
            <th width=100px> Konteinerio tipas</th>
            <th width=100px> Nuskaitymas iš failo (s)</th>
            <th width=100px> Rikiavimas (s) </th>
            <th width=100px> Skirstymas į "pirmūnus" ir "nesimokančius" (s) </th>
            <th width=100px> Bendras programos vykdymo laikas (s) </th>
        </tr>
    </thead>
    <tbody>
        <tr>
            <td rowspan=3>Studentai1000.txt</td>
            <td>Vektorius</td>
            <td>0.0020473</td>
            <td>0</td>
            <td>0</td>
            <td><b>0.0020473</b></td>
        </tr>
        <tr>
            <td>Dvipusė eilė</td>
            <td>0.0086449</td>
            <td>0.0010443</td>
            <td>0.000812</td>
            <td><b>0.0105012</b></td>
        </tr>
        <tr>
            <td>Sąrašas</td>
            <td>0</td>
            <td>0</td>
            <td>0</td>
            <td><b>0</b></td>
        </tr>
        <tr>
            <td rowspan = 3>Studentai10000.txt</td>
            <td>Vektorius</td>
            <td>0.0165151</td>
            <td>0.0153975</td>
            <td>0</td>
            <td><b>0.0319126</b></td>
        </tr>
        <tr>
            <td>Dvipusė eilė</td>
            <td>0.0159216</td>
            <td>0</td>
            <td>0.0119027</td>
            <td><b>0.0278243</b></td>
        </tr>
        <tr>
            <td>Listas</td>
            <td>0.0177284</td>
            <td>0.0075679</td>
            <td>0</td>
            <td><b>0.0252963</b></td>
        </tr>
        <tr>
            <td rowspan=3>Studentai100000.txt</td>
            <td>Vektorius</td>
            <td>0.791214</td>
            <td>0.0547273</td>
            <td>0.0224924</td>
            <td><b>0.8684337</b></td>
        </tr>
        <tr>
            <td>Dvipusė eilė</td>
            <td>0.0787565</td>
            <td>0.0674405</td>
            <td>0.0245542</td>
            <td><b>0.17007512</b></td>
        </tr>
        <tr>
            <td>Sąrašas</td>
            <td>0.0945634</td>
            <td>0.0335261</td>
            <td>0.0471157</td>
            <td><b>0.1752052</b></td>
        </tr>
      <tr>
            <td rowspan=3>Studentai1000000.txt</td>
            <td>Vektorius</td>
            <td>1.17731</td>
            <td>0.738691</td>
            <td>0.1469</td>
            <td><b>2.062901</b></td>
        </tr>
        <tr>
            <td>Dvipusė eilė</td>
            <td>1.22941</td>
            <td>0.887679</td>
            <td>0.24186</td>
            <td><b>2.358949</b></td>
        </tr>
        <tr>
            <td>Sąrašas</td>
            <td>1.29301</td>
            <td>0.517986</td>
            <td>0.341315</td>
            <td><b>2.152311</b></td>
        </tr>
      <tr>
            <td rowspan=3>Studentai10000000.txt</td>
            <td>Vektorius</td>
            <td>11.7892</td>
            <td>8.72044</td>
            <td>1.61681</td>
            <td><b>22.12645</b></td>
        </tr>
        <tr>
            <td>Dvipusė eilė</td>
            <td>12.3367</td>
            <td>11.0042</td>
            <td>2.53892</td>
            <td><b>25.87892</b></td>
        </tr>
        <tr>
            <td>Sąrašas</td>
            <td>13.0431</td>
            <td>7.14533</td>
            <td>3.44146</td>
            <td><b>23.62989</b></td>
        </tr>
    </tbody>
</table>



![image](https://github.com/user-attachments/assets/f67d643d-45d7-4a32-b509-6f024e9a695c)





</details>


