#include <stdio.h>
#include <math.h>

int pocet_riadkov();
float nacitanie_cisla(FILE *fr);
void zapis_cisla(FILE *fw, float strana, char nazov_strany);
void vypis(float stranaA, float stranaB, float stranaC, FILE *fw);

float objem_kvadra(float obdlznik, float vyska);
float povrch_kvadra(float obdlznik1, float obdlznik2, float obdlznik3);
float uhlopriecka_kvadra(float uhloprieckaT, float vyska);

float uhlopriecka_trojuholnika(float stranaA, float stranaB);
float obsah_obdlznika(float stranaA, float stranaB);


int main(){
	
	float stranaA;
	float stranaB;
	float stranaC;
	int i;
	int riadky = pocet_riadkov();
	int pocet_opakovani = riadky / 3;
	
	FILE *fr = fopen("data.txt", "r");
	FILE *fw = fopen("vystup.txt", "w");
	
	if(fr != NULL){
		if(fw != NULL){
			for(i = 1; i <= pocet_opakovani; i++){
				stranaA = nacitanie_cisla(fr);
				stranaB = nacitanie_cisla(fr);
				stranaC = nacitanie_cisla(fr);
				
				zapis_cisla(fw, stranaA, 'A');
				zapis_cisla(fw, stranaB, 'B');
				zapis_cisla(fw, stranaC, 'C');
			
				vypis(stranaA, stranaB, stranaC, fw);
				
				if(i < pocet_opakovani){
					fprintf(fw, "\n# Dalsi kvader #\n\n");
				}
			}
			
			fprintf(fw, "\n# Koniec #");	
		}else{
			printf("Subor sa nevytvoril!");
		}
		
	}else{
		printf("Subor sa nenasiel!");
	}
	
	fclose(fr);
	fclose(fw);
	
	return 0;
}

int pocet_riadkov(){
	FILE *fr = fopen("data.txt", "r");
	
	char znak;
	int pocet_riadkov = 0;
	
	if(fr != NULL){
		while((znak = fgetc(fr)) != EOF){
			if(znak == '\n') pocet_riadkov++;
		}
	}
	
	fclose(fr);
	
	return pocet_riadkov;
}
float nacitanie_cisla(FILE *fr){
	float cislo;
	
	fscanf(fr, "%f", &cislo);
	if(cislo < 0){
		printf("Nasla sa zaporna hodnota!\nNavstiv data.txt");
		return 0;
	}
	
	return cislo;
}

void zapis_cisla(FILE *fw, float strana, char nazov_strany){
	fprintf(fw, "strana %c = %.1f\n", nazov_strany, strana);
}

void vypis(float stranaA, float stranaB, float stranaC, FILE *fw){
	fprintf(fw, "######\n");
	fprintf(fw, "objem = %.2f\n", objem_kvadra(obsah_obdlznika(stranaA, stranaB), stranaC));
	fprintf(fw, "povrch = %.2f\n", povrch_kvadra(obsah_obdlznika(stranaA, stranaB), obsah_obdlznika(stranaB, stranaC), obsah_obdlznika(stranaA, stranaC)));
	fprintf(fw, "uhlopriecka = %.2f\n", uhlopriecka_kvadra(uhlopriecka_trojuholnika(stranaA, stranaB), stranaC));
}

float objem_kvadra(float obdlznik, float vyska){
	return obdlznik * vyska;
}

float povrch_kvadra(float obdlznik1, float obdlznik2, float obdlznik3){
	return 2 * (obdlznik1 + obdlznik2 + obdlznik3);
}

float uhlopriecka_kvadra(float uhloprieckaT, float vyska){
	return sqrt(pow(uhloprieckaT, 2) + pow(vyska, 2));
}

float uhlopriecka_trojuholnika(float stranaA, float stranaB){
	return sqrt(pow(stranaA, 2) + pow(stranaB, 2));
}

float obsah_obdlznika(float stranaA, float stranaB){
	return stranaA * stranaB;
}









