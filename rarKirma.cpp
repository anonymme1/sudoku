#include <iostream>
#include <cstdlib>
#include <string.h>
#include <fstream>

int main() {
	char komut[100];
	std::string dosyaAdi;
	std::cout<<"\nDosya adi gir: ";
	std::cin>>dosyaAdi;

	int choice;
	std::cout<<"\n\n\nRakamsal sifreler icin >> 1\n";
	std::cout<<"\nKarisik sifreler icin  >> 2\n";
	std::cout<<"\nWordlist sifreler icin >> 3\n\n";
	std::cout<<"\n\nSecim: ";
	std::cin>>choice;

	int denemeSayisi,haneSayisi;
	std::string harf = "zxcvbnmlkjhgfdsawerqtyuiop1234567890";

	if(choice == 1) {
		std::cout<<"\nKac kez denensin: ";
		std::cin>>denemeSayisi;
		for(int i=1000;i<denemeSayisi;i++) {
			sprintf(komut, "unrar e -p%d %s", i, dosyaAdi.c_str());
			int a = system(komut);
			if(a == EXIT_SUCCESS) {
				std::cout<<"\n\e[92mSifre bulundu >> "<<i<<"\n";
				break;
			}

			else {
				std::cout<<"\n\e[91mYanlis sifre >> "<<i<<"\n";
			}
		}
	}

	else if(choice == 2) {
		std::cout<<"\nKac kez denensin: ";
		std::cin>>denemeSayisi;
		std::cout<<"\nKac haneli sifre olcak: ";
		std::cin>>haneSayisi;
		for(int i=0;i<denemeSayisi;i++) {
			std::string sifre;

			for(int i=0;i<haneSayisi;i++) {
				sifre += harf[rand()%harf.size()+0];
			}
			sprintf(komut, "unrar e -p%s %s", sifre.c_str(), dosyaAdi.c_str());
			int b = system(komut);
			if(b == EXIT_SUCCESS) {
				std::cout<<"\n\e[92mSifre bulundu >> "<<sifre<<"\n";
				break;
			}

			else {
				std::cout<<"\n\e[91mYanlis sifre >> "<<sifre<<"\n";
			}
		}
	}

	else if(choice == 3) {
		std::string word;
		std::cout<<"\nWordlist dosyasi gir: ";
		std::cin>>word;

		std::ifstream oku(word);
		std::string satir;
		while(!oku.eof()) {
			getline(oku, satir);
			sprintf(komut, "unrar e -p%s %s", satir.c_str(), dosyaAdi.c_str());
			int c = system(komut);
			if(c == EXIT_SUCCESS) {
				std::cout<<"\n\e[92mSifre bulundu >> "<<satir<<"\n";
				break;
			}

			else {
				std::cout<<"\n\e[91mYanlis sifre >> "<<satir<<"\n";
			}
		}
	}

	else {
		std::cout<<"\nByyyys.\n";
		exit(1);
	}

	return 0;
}

