/*
Tibor Pelegrin
3.A SPSE KE
OBESENEC
*/

#include <stdio.h>
#include <stdlib.h>

const int TRUE = 1;					
const int FALSE = 0;
const int VELKOST_POLA = 50;

//deklaracia funkcii menucka
void menu();			
void instrukcie();
void hrat();
void pridat_slovo_subor();
void vypis_slov_zo_suboru();
void autor();
int ukoncenie_hry();

//deklaracia funckii pre hru
void hadanie(char slovo[]);
char hadany_znak();
void obesenec(int pocet_pokusov);
int volba_nacitania();

//deklaracia funkcii pre nacitavanie slov
void nacitanie_slova_pouzivatel(char slovo[]);
void nacitanie_slova_subor(char slovo[]);

//deklaracia funkcii pre vypis hadania
void vypis_uz_zadanych(char uz_zadane[], int pokus);
void vypis_hadania(char vypis[], int pocet_pismenok);

//deklaracia vseobecnych funkcii
int pocitanie_znakov(char slovo[]);
int pocet_riadkov_subor(FILE *fr);
int je_rovnake(char slovo1[], char slovo2[]);
int opakovanie(char co[]);

//deklaracia funkcii pre kreslenie
void vyhra();
void smrt0();
void smrt1();
void smrt2();
void smrt3();
void smrt4();
void smrt5();
void smrt6();
void smrt7();

int main(int argc, char *argv[]) {
	char znak;
	int id = TRUE;
	
	do{
		system("cls");		
		printf("##### Vitaj v hre obesenec! #####\n\n");
		
		menu(); //volanie funkcie na vypis menu
		
		do{
			printf("\nTvoja volba: ");
			znak = getchar();
			if(znak == '\n') znak = getchar();
			if(znak != 'i' && znak != 'h' && znak != 's' && znak != 'v' && znak != 'a' && znak != 'k') printf("\nNespravna volba!\n");
		}while(znak != 'i' && znak != 'h' && znak != 's' && znak != 'v' && znak != 'a' && znak != 'k');
		
		switch (znak){
			case 'i':
				instrukcie();
				break;
			case 'h':
				hrat();               
				break;
			case 's':
				pridat_slovo_subor();
				break;
			case 'v':
				vypis_slov_zo_suboru();
				break;
			case 'a':
				autor();
				break;
			case 'k':
				if(ukoncenie_hry()) id = FALSE; //volanie funkcie ktora nas uisti ze pozivatel naozaj chce ukoncit hru
				break;							//id sa zmeni na FALSE a ukocni sa program
		}
	}while(id);
	
	printf("\n#####   HRA UKONCENA   #####");
	
	return 0;
}

//definicia funkcie na vypis menu
void menu(){
	printf("MENU:\n");
	printf("Instrukcie (i)\n");
	printf("Hrat (h)\n");
	printf("Pridat slovo do suboru (s)\n");
	printf("Vypis vsetkych slov zo suboru (v)\n");
	printf("Autor (a)\n");
	printf("\nKoniec hry (k)\n");
}

//definicia funkcie na vypis instrukcii
void instrukcie(){
	system("cls");
	printf("###   Vitaj v sekcii Instrukcie   ###\n");
	printf("\nHra obesenec je hra v ktorej hrac hada nezname slovo po pismenkach.\n");
	printf("Ulohou hraca je zadat pismenko ktore sa nachadza v neznamom slove a uhadnut cele slovo.\n");
	printf("Na uhadnutie neznameho slova ma hrac 7 zivotov.\n");
	printf("Ak sa zadane pismenko nachadza v neznamom slove, objavi sa vo vypise.\n");
	printf("Ak sa zadane pismenko nenachadza v neznamom slove, stratite zivot.\n");
	printf("\nVela stastia :D\n");

	printf("\nPre navrat na Menu stlac ENTER");
	getchar();
	while(getchar() != '\n'){} //cyklus sa ukonci ked pouzivatel stlaci enter
}

//definicia funkcie pre hru
void hrat(){
	char slovo[VELKOST_POLA];
	
	do{
		system("cls");		
		printf("###   Vitaj v sekcii Hra   ###\n\n");

		if(volba_nacitania()){			
			nacitanie_slova_pouzivatel(slovo);		//volanie funkcie na nacitanie slova od pouzivatela
		}else{
			nacitanie_slova_subor(slovo);			//volanie funkcie na nacitanie nahodneho slova zo suboru
		}
		
		hadanie(slovo); 							//volanie funkcie kde pouzivatel hada slovo
	}while(opakovanie("hru"));
}

//definicia funkcie pre pridanie slova do suboru
void pridat_slovo_subor(){
	FILE *fr;
	FILE *fw;
	char nazov_suboru[VELKOST_POLA];
	char slovo[VELKOST_POLA]; 
	int stop;
	
	do{
		system("cls");
		printf("##   Vitaj v sekcii pre pridanie slova do suboru   ##\n");
	
		do{
			printf("\nZadaj nazov suboru: ");
			scanf("%s", nazov_suboru);
			
			fr = fopen(nazov_suboru, "r");
			if(fr == NULL) printf("\nSubor sa nenasiel!\n");
		}while(fr == NULL);
		
		do{
			printf("\nZadaj slovo do suboru: ");
			scanf("%s", slovo);
				
			if(je_slovo_v_subore(slovo, fr)){				//ak zadane slovo sa uz nachadza v subore tak sa tam neprida
				printf("\nZadane slovo sa uz nachadza v subore!\nZadajte ine slovo!\n");
				stop = 1;
			}else{
				fclose(fr);
				
				fw = fopen(nazov_suboru, "a");
				
				fprintf(fw, "%s\n", slovo);
				printf("\nVase slovo bolo uspesne pridane do suboru.\n\n");
				stop = 0;
			}
		}while(stop);
	}while(opakovanie("zadavanie"));
}

//definicia funkcie pre vypis slov zo suboru
void vypis_slov_zo_suboru(){
	FILE *fr;
	int i;
	char slovo_zo_suboru[VELKOST_POLA];
	char vstup[VELKOST_POLA];
	
	system("cls");
	printf("###   VITAJ V SEKCII PRE VYPISANIE SLOV ZO SUBORU   ###\n\n");
	
	do{
		printf("Zadaj vstupny subor: ");
		scanf("%s", vstup);
		
		fr = fopen(vstup, "r");
		if(fr == NULL) printf("Subor sa nenasiel!\n");
	}while(fr == NULL);
	
	int pocet_slov_v_subore = pocet_riadkov_subor(fr);     //pocet riadkov suboru predstavuje pocet slov v subore
	rewind(fr);			//obnovenie suboru
	
	if(pocet_slov_v_subore == 0){		//slova sa vypisu len ak existuju
		printf("\nTento subor neobsahuje ziadne slovo!\nNacitajte slova do tohto suboru!\n");
	}else{
		printf("\nTento subor obsahuje %d slov.\n\n", pocet_slov_v_subore);  	
		
		for(i = 0; i < pocet_slov_v_subore; i++){		//vypisanie vsetkych slov zo suboru
			fscanf(fr, "%s", slovo_zo_suboru);
			printf("%d. slovo: %s\n", i + 1, slovo_zo_suboru);
		}
	}
	fclose(fr);
	
	printf("\nPre navrat na Menu stlac ENTER");
	getchar();
	while(getchar() != '\n'){} 		//cyklus sa ukonci ked pouzivatel stlaci enter
}

//definicia funkcie pre vypis informacii o autorovi
void autor(){
	system("cls");
	printf("###   Vitaj v sekcii Autor   ###\n\n");
	printf("Autor: Tibor Pelegrin\n");
	printf("Skola: Stredna priemyselna skola elektrotechnicka, Kosice\n");
	printf("Trieda: 3.A\n");
	printf("Datum ukoncenia uprav: 12.1.2021\n");
	printf("\nV pripade najdenia chyby ma nevahajte kontaktovat na tejto emailovej adrese:\n");
	printf("tibor.pelegrin@student.spseke.sk\n");
	
	printf("\nPre navrat na Menu stlac ENTER");
	getchar();
	while(getchar() != '\n'){}		//cyklus sa ukonci ked pouzivatel stlaci enter
}

//definica funkcie pre ukoncenie hry
int ukoncenie_hry(){
	char znak;
	
	system("cls");
	printf("#   Naozaj chces ukoncit hru ? y/n   #\n\n");
	
	do{
		printf("Tvoja volba: ");
		znak = getchar();
		if(znak == '\n') znak = getchar();
		if(znak != 'y' && znak != 'n') printf("\nNepsravna volba!\n\n");
	}while(znak != 'y' && znak != 'n');
	
	if(znak == 'y') return 1;		
	else if(znak == 'n') return 0;
}

//definicia funkcie pre volbu nacitanie
int volba_nacitania(){
	char znak;
	
	printf("\nPre hadanie slov zo suboru stlac (s)\n");
	printf("Pre zadanie hadaneho slova stlac (z)\n");
	
	do{
		printf("\nVasa volba: ");
		znak = getchar();
		if(znak == '\n') znak = getchar();
		
		if(znak != 'z' && znak != 's') printf("\nNespravna volba!\n");
	}while(znak != 'z' && znak != 's');
	
	if(znak == 'z'){
		return 1;
	}else if(znak == 's'){
		return 0;
	}
}

//definicia funkcie pre nacitanie slova od pouzivatela
void nacitanie_slova_pouzivatel(char slovo[]){
	
	printf("Zadaj slovo: ");
	scanf("%s", slovo);
}

//definicia funkcie pre nacitanie slova zo suboru
void nacitanie_slova_subor(char slovo[]){
	FILE *fr;
	char vstup[VELKOST_POLA];
	int pocet_slov, i, random_slovo;

	do{
		printf("Zadaj vstupny subor: ");
		scanf("%s", vstup);
		
		fr = fopen(vstup, "r");
		if(fr == NULL) printf("Subor sa nenasiel!\n");
	}while(fr == NULL);
	
	pocet_slov = pocet_riadkov_subor(fr);
	srand(time(0));    //pre generaciu nahodnych cisel zapiname pocitanie casu
	
	if(pocet_slov == 0){
		printf("V subore nie je slovo, pridajte slovo do suboru!\n");     
	}else{
		random_slovo = (rand() % pocet_slov) + 1;   		//generacia random cisla podla poctu slov v subore
		
		rewind(fr);
		
		for(i = 0; i < random_slovo; i++){
			fscanf(fr, "%s", slovo);						//retazec slovo sa bude prepisovat az do random cisla
		}	
	}
	fclose(fr);
}

//definicia funkce pre hadanie 
void hadanie(char slovo[]){
	int pocet_pokusov = 7, i, id, stop = TRUE, pokus = 1;
	int pocet_pismenok = pocitanie_znakov(slovo);
	char znak;
	char vypis[VELKOST_POLA];
	char uz_zadane[7];
	
	for(i = 0; i < pocet_pismenok; i++){
		vypis[i] = '-';										//cely vypis neobsahuje ziadne pismenko
	}														//prepiseme cely vypis na pomlcky

	while(stop){		
		system("cls");
		id = FALSE; 
	
		if(pocet_pokusov == 0){
			smrt0();
			
			printf("##### PREHRAL SI ######\n");
			printf("\nHadane slovo bolo: %s\n", slovo);
			stop = FALSE;	//stop ukonci cyklus hadania slova
		}else if(je_rovnake(vypis, slovo)){
			vyhra();
			
			printf("\n##### VYHRAL SI #####\n");
			printf("\nUhadnute slovo bolo: %s\n", slovo);
			stop = FALSE;	//stop ukonci cyklus hadania slova
		}else{
			obesenec(pocet_pokusov);	//volanie funkcie pre vykreslenie obesenca
		
			printf("\nPocet zivotov: %d\n", pocet_pokusov);
			printf("Uz vyskusane chybne pismenka: ");
			
			vypis_uz_zadanych(uz_zadane, pokus);		//vypis uz zadanych pismenok
			vypis_hadania(vypis, pocet_pismenok);		//vypis hadania
			
			znak = hadany_znak();
			
			for(i = 0; i < pocet_pismenok; i++){		//ak sa zadane pismenko nachadza v slove, vypise sa na tu 
				if(znak == slovo[i]){					//poziciu na ktorj sa nachadza 
					vypis[i] = znak;
					id = TRUE;	//id true znamena pouzivatel nestrati zivot
				}
			}
			
			for(i = 0; i < pocitanie_znakov(uz_zadane); i++){   //ak sa zadane pismenko opakuje tak pouzivatel nepride o zivot
				if(znak == uz_zadane[i]) id = TRUE;
			}
			
			if(!id){
				pocet_pokusov--;
				uz_zadane[pokus - 1] = znak;       //pridanie pismenka do retazca kde su vsetky chybne zadane pismenka
				pokus++;
			} 
		}
	}
}

//definicia funkcie pre opakovanie 
int opakovanie(char co[]){
	char znak;
	
	printf("Chces opakovat %s? y/n\n", co);
	
	do{
		printf("\nTvoja volba: ");
		znak = getchar();
		if(znak == '\n') znak = getchar();
		
		if(znak != 'y' && znak != 'n') printf("\nNespravna volba!\n");
	}while(znak != 'y' && znak != 'n');
	
	if(znak == 'y') return 1;
	else if(znak == 'n') return 0;
}

//definicia funkcie pre vypis uz zadanych pismenok
void vypis_uz_zadanych(char uz_zadane[], int pokus){
	int i;
	for(i = 0; i < pokus - 1; i++){
		printf("%c, ", uz_zadane[i]);
	}
}

//definicia funkcie pre vypis retazca hadaneho slova
void vypis_hadania(char vypis[], int pocet_pismenok){
	int i;
	printf("\n\n# ");
	for(i = 0; i < pocet_pismenok; i++){
		printf("%c", *(vypis + i));
	}
	printf(" #\n\n");
}

//definicia funkcie ktora porovnava dve slova ci su rovnake
int je_rovnake(char slovo1[], char slovo2[]){
	int i, id = FALSE;

	for(i = 0; i < pocitanie_znakov(slovo2); i++){
		id = TRUE;
		if(slovo1[i] != slovo2[i]){    //akonahle sa jedno pismenko nerovna druhemu pismenku na rovnakom indexe 
			id = FALSE;				   //tak sa id zmeni na false
			break;
		}
	}	
	
	if(id){
		//printf("\n%s a %s su rovnake\n", slovo1, slovo2);
		return 1;
	}else{
		//printf("\n%s a %s nie su rovnake\n", slovo1, slovo2);
		return 0;	
	}
	
}

//definicia funkcie pre pocitanie znakov v slove
int pocitanie_znakov(char slovo[]){
	int pocet_znakov = 0;
	int i;
	
	for(i = 0; slovo[i] != '\0' ; i++){
		pocet_znakov++;
	}
	
	return pocet_znakov;
}

//definicia funkcie pre nacitanie hadaneho pismenka
char hadany_znak(){
	char znak;
	
	printf("Pismenko: ");
	znak = getchar();
	if(znak == '\n') znak = getchar();		//ak je znak enter tak sa zoberie a tym sa getchar dostane ku znaku
	
	return znak;
}

//definicia funkcie ktora zisti ci sa slovo nachadza v subore
int je_slovo_v_subore(char slovo[], FILE *fr){
	int i, pocet_riadkov = pocet_riadkov_subor(fr);
	char porovnavacie_slovo[VELKOST_POLA];
	
	rewind(fr);
	
	for(i = 0; i < pocet_riadkov; i++){
		fscanf(fr, "%s", porovnavacie_slovo);
		if(je_rovnake(porovnavacie_slovo, slovo)) return 1; //ak sa slovo nachadza v subore tak sa ukonci funkcia a vrati sa 1
	}
	
	return 0;
}

//definicia funkcie pre zistenie poctu riadkov v subore, teda poctu slov v subore
int pocet_riadkov_subor(FILE *fr){
	int pocet = 0;
	char znak;
	
	rewind(fr);
	
	while((znak = fgetc(fr)) != EOF){
		if(znak == '\n') pocet++;	
	}
	
	return pocet;
}

//definicia funkcie pre volanie funkcii na vykreslenie obesenca
void obesenec(int pocet_pokusov){
	if(pocet_pokusov == 1) smrt1();
	if(pocet_pokusov == 2) smrt2();
	if(pocet_pokusov == 3) smrt3();
	if(pocet_pokusov == 4) smrt4();
	if(pocet_pokusov == 5) smrt5();
	if(pocet_pokusov == 6) smrt6();
	if(pocet_pokusov == 7) smrt7();
}

//definicie funkcii pre kreslenie
void vyhra(){
	printf("\n   _________________________________\n");
	printf("  |                                 | \n");
	printf("  |                                 | \n");
	printf("  |        _________________        | \n");
	printf("  |    .-'|        .        |'-.    | \n");
	printf("  |   /   |       /|        |   \\   |\n");
	printf("  |  (    |      / |        |    )  | \n");
	printf("  |   \\   |        |        |   /   |\n");
	printf("  |    '--|        |        |--'    | \n");
	printf("  |        '-.     |      .-'       | \n");
	printf("  |           '-.     .-'           | \n");
	printf("  |             /     \\             |\n");
	printf("  |            /       \\            |\n");
	printf("  |           /         \\           |\n");
	printf("  |          /___________\\          |\n");
	printf("  |         |             |         | \n");
	printf("  |         |\\ / .-.  | | |         |\n");
	printf("  |        /  | (   ) | |  \\        |\n");
	printf("  |       |   |  '-'  '-'   |       | \n");
	printf("  |       |_________________|       | \n");
	printf("  |_________________________________| \n\n");
}

void smrt0(){
	printf("\n   __________________            \n");
	printf("  |    /             |            \n");
	printf("  |   /              |            \n");
	printf("  |  /           ____|___         \n");
	printf("  | /           |( x  x )|        \n");
	printf("  |/            |   --   |        \n");
	printf("  |             |  ____  |        \n");
	printf("  |             |________|        \n");
	printf("  |            ______|_____       \n");
	printf("  |           /  | .  . |  \\     \n");
	printf("  |          /   |      |   \\    \n");
	printf("  |         /    |   o  |    \\   \n");
	printf("  |              |______|         \n");
	printf("  |\\             /      \\       \n");
	printf("  | \\           /        \\      \n");
	printf("  |  \\         /          \\     \n");
	printf("  |   \\       /            \\    \n");
	printf("  |    \\                         \n");
	printf("  |     \\                        \n");
	printf("  |      \\                       \n");
	printf("  |_______\\____________________  \n");
	printf("        |                |        \n\n");
}

void smrt1(){
	printf("\n   __________________            \n");
	printf("  |    /             |            \n");
	printf("  |   /              |            \n");
	printf("  |  /           ____|___         \n");
	printf("  | /           |        |        \n");
	printf("  |/            |        |        \n");
	printf("  |             |        |        \n");
	printf("  |             |________|        \n");
	printf("  |            ______|_____       \n");
	printf("  |           /  | .  . |  \\     \n");
	printf("  |          /   |      |   \\    \n");
	printf("  |         /    |   o  |    \\   \n");
	printf("  |              |______|         \n");
	printf("  |\\             /      \\       \n");
	printf("  | \\           /        \\      \n");
	printf("  |  \\         /          \\     \n");
	printf("  |   \\       /            \\    \n");
	printf("  |    \\                         \n");
	printf("  |     \\                        \n");
	printf("  |      \\                       \n");
	printf("  |_______\\____________________  \n");
	printf("        |                |        \n");
}

void smrt2(){
	printf("\n   __________________            \n");
	printf("  |    /             |            \n");
	printf("  |   /              |            \n");
	printf("  |  /           ____|___         \n");
	printf("  | /           |        |        \n");
	printf("  |/            |        |        \n");
	printf("  |             |        |        \n");
	printf("  |             |________|        \n");
	printf("  |            ______|_____       \n");
	printf("  |              | .  . |         \n");
	printf("  |              |      |         \n");
	printf("  |              |   o  |         \n");
	printf("  |              |______|         \n");
	printf("  |\\                             \n");
	printf("  | \\                            \n");
	printf("  |  \\                           \n");
	printf("  |   \\                          \n");
	printf("  |    \\                         \n");
	printf("  |     \\                        \n");
	printf("  |      \\                       \n");
	printf("  |_______\\____________________  \n");
	printf("        |                |        \n");
}

void smrt3(){
	printf("\n   __________________            \n");
	printf("  |    /             |            \n");
	printf("  |   /              |            \n");
	printf("  |  /           ____|___         \n");
	printf("  | /           |        |        \n");
	printf("  |/            |        |        \n");
	printf("  |             |        |        \n");
	printf("  |             |________|        \n");
	printf("  |                               \n");
	printf("  |                               \n");
	printf("  |                               \n");
	printf("  |                               \n");
	printf("  |                               \n");
	printf("  |\\                             \n");
	printf("  | \\                            \n");
	printf("  |  \\                           \n");
	printf("  |   \\                          \n");
	printf("  |    \\                         \n");
	printf("  |     \\                        \n");
	printf("  |      \\                       \n");
	printf("  |_______\\____________________  \n");
	printf("        |                |        \n");
}

void smrt4(){
	printf("\n   __________________           \n");
	printf("  |    /                          \n");
	printf("  |   /                           \n");
	printf("  |  /                            \n");
	printf("  | /                             \n");
	printf("  |/                              \n");
	printf("  |                               \n");
	printf("  |                               \n");
	printf("  |                               \n");
	printf("  |                               \n");
	printf("  |                               \n");
	printf("  |                               \n");
	printf("  |                               \n");
	printf("  |\\                             \n");
	printf("  | \\                            \n");
	printf("  |  \\                           \n");
	printf("  |   \\                          \n");
	printf("  |    \\                         \n");
	printf("  |     \\                        \n");
	printf("  |      \\                       \n");
	printf("  |_______\\____________________  \n");
	printf("        |                |        \n");
}

void smrt5(){
	printf("\n                               \n");
	printf("  |                               \n");
	printf("  |                               \n");
	printf("  |                               \n");
	printf("  |                               \n");
	printf("  |                               \n");
	printf("  |                               \n");
	printf("  |                               \n");
	printf("  |                               \n");
	printf("  |                               \n");
	printf("  |                               \n");
	printf("  |                               \n");
	printf("  |                               \n");
	printf("  |\\                             \n");
	printf("  | \\                            \n");
	printf("  |  \\                           \n");
	printf("  |   \\                          \n");
	printf("  |    \\                         \n");
	printf("  |     \\                        \n");
	printf("  |      \\                       \n");
	printf("  |_______\\____________________  \n");
	printf("        |                |        \n");
}

void smrt6(){
	printf("\n                               \n");
	printf("                                  \n");
	printf("                                  \n");
	printf("                                  \n");
	printf("                                  \n");
	printf("                                  \n");
	printf("                                  \n");
	printf("                                  \n");
	printf("                                  \n");
	printf("                                  \n");
	printf("                                  \n");
	printf("                                  \n");
	printf("                                  \n");
	printf("                                  \n");
	printf("                                  \n");
	printf("                                  \n");
	printf("                                  \n");
	printf("                                  \n");
	printf("                                  \n");
	printf("                                  \n");
	printf("   _____________________________  \n");
	printf("        |                |        \n");
}

void smrt7(){
	printf("\n                               \n");
	printf("                                  \n");
	printf("                                  \n");
	printf("                                  \n");
	printf("                                  \n");
	printf("                                  \n");
	printf("                                  \n");
	printf("                                  \n");
	printf("                                  \n");
	printf("                                  \n");
	printf("                                  \n");
	printf("                                  \n");
	printf("                                  \n");
	printf("                                  \n");
	printf("                                  \n");
	printf("                                  \n");
	printf("                                  \n");
	printf("                                  \n");
	printf("                                  \n");
	printf("                                  \n");
	printf("                                  \n");
	printf("                                  \n");
}

