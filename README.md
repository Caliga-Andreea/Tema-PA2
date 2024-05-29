Tema 2
 Pentru a realiza tema 2 am utilizat 3 cozi, una in care adaugam echipele pentru a organiza meciurile, una pentru echipele castigatoare si una pentru echipele pierzatoare. Structura unui nod al cozii avea 
 urmatoarele campuri: nuemele echipei(char), numarul de victorii(int)-notat cu r,  punctajul(float), pozitia (int)-in cadrul primei cozi si un pointer catre urmatorul element din coada. Am utilizat functii
 pentru a aloca memorie pentru nodurile de tip coada, iar apoi am creat cele 3 cozi. Cunoscand numarul de echipe din fisier, am parcurs fisierul si am citit datele corespunzatoare, respectiv punctajul si numele
 echipei si am adaugat nodul in prima coada de meciuri(am alocat dinamic memorie pentru nume,iar apoi am realocat memoria tinand cont de dimensiunea sirului de caractere). Pentru a rezolva primul exercitiu am 
 alocat memorie pentru o structura de tip graf(contine nr de varfuri=nr echipe si matricea de adiacenta). Cat timp in coada era mai mult de o echipa, verificam daca exista echipe in coada de castigatori, 
 pentru a-i adauga in coada de meciuri si a elimina echipele din coada de castigatori, apoi organizam meciuri intre echipe, 2 cate 2, scotand in acelasi timp echipele care au jucat meciuri din coada de meciuri,
 iar la final injumatatind numarul de echipe.Pentru a organiza un meci adaugam echipa cu punctaj mai mare in coada de castigatori, iar pe cea cu punctaj mai mic in coada de invinsi. In cazul in care punctajul 
 era egal, se adauga in coada de castigatori echipa care avea prioritate din punct de vedere alfabetic. In acelasi timp in cadrul meciurilor se incrementa numarul de victorii al echipei castigatoare
 (initializat la inceput cu 0) si se punea 1 in matricea de adiacenta pe pozitia a[i][j] in cazul in care j a fost adaugat in lista de castigatori. Pentru a incheia exercitiul 1 am afisat matricea de adiacenta
 a campionatului. In cazul exercitiului 2 am calculat scorul utilizand formula data. Pentru a afisa punctajul in ordine crescatoare, am utilizat coada de invinsi, iar variabilele r si l din formula le-am 
 ales astfel r=numarul de victorii a primei echipe din coada de invinsi, l=numarul de victorii a echipei campioane a turneului+1, dupa afisarea punctajului astfel obtinut si al numelui echipei am aliminat
 din coada de invinsi prima echipa (am realizat acest proces pana la golirea cozii de invinsi). La final am afisat si punctajul si numele campionului avand r=numarul de victorii a primei echipe de coada de 
 castigatori, l=r+1, dupa afisarea punctajului si a numelui castigatorului am eliminat si ultimul elemt din coada de castigatori.
