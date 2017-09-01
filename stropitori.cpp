#include <iostream>
#include <stdio.h>
#include <vector>
#include <string.h>
#include <algorithm>

using namespace std;

struct stropitoare
{
	int point;
	int power;
}strop;

int maxStrop(vector<stropitoare> stropitori, int n, int s){
	int maxNum = 0;
	int limit = 0;
	int i;

	for(i = 0; i < stropitori.size(); i++){
		if(i == 0){
			if(stropitori.at(i).point - stropitori.at(i).power > 0){
				maxNum++;
				limit = stropitori.at(i).point;
			} else {
				if(stropitori.at(i).point + stropitori.at(i).power < stropitori.at(i + 1).point){
					maxNum++;
					limit = stropitori.at(i).point + stropitori.at(i).power;
				} else {
					limit = stropitori.at(i).point;
				}
			}
		}

			if(i != 0 && i != stropitori.size() - 1){
					if(stropitori.at(i).point - stropitori.at(i).power > limit){
						maxNum++;
						limit = stropitori.at(i).point;
					} else {
						if(stropitori.at(i).point + stropitori.at(i).power < stropitori.at(i + 1).point){
							maxNum++;
							limit = stropitori.at(i).point + stropitori.at(i).power;
						} else {
							limit = stropitori.at(i).point;
						}
					}
				}

			if(i == stropitori.size() - 1){
			if(stropitori.at(i).point - stropitori.at(i).power > limit){
				maxNum++;
				limit = stropitori.at(i).point;
			} else {
				if(stropitori.at(i).point + stropitori.at(i).power < s){
					maxNum++;
					limit = stropitori.at(i).point + stropitori.at(i).power;
				} else {
					limit = stropitori.at(i).point;
				}
			}
		}
					
		}	

	return maxNum;
}

int main(int argc, char* argv[]) {

	FILE* fin = fopen(argv[1], "r");
	//FILE* fin = fopen("stropitori.in", "r");
	//FILE*  fout = fopen("stropitori.out", "w");
	char name[130];
	int n, s;
	int i;
	int point, power;
	vector<stropitoare> stropitori;
	int res;
	

	fgets(name, 130, fin);
	//printf("%s\n", name);
	fscanf(fin, "%d %d", &n, &s);
	//printf("%d %d\n", n, s);
	for(i = 0; i < n; i++){
		fscanf(fin, "%d", &strop.point);
		stropitori.push_back(strop);
	}

	for(i = 0; i < n; i++){
		fscanf(fin, "%d", &strop.power);
		stropitori.at(i).power = strop.power;
	}

	/*for(i = 0; i < n; i++){
		cout<< stropitori.at(i).point << "   " << stropitori.at(i).power << endl;
	}*/
	res = maxStrop(stropitori, n, s);
	printf("res = %d\n", res);
	//fprintf(fout, "%d\n", res);

	return 0;
}