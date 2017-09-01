#include <iostream>
#include <stdio.h>
#include <vector>
#include <string.h>
#include <algorithm>

using namespace std;

struct interval
{
	int inf;
	int sup;
}interv;

bool compare(const interval &i1, const interval &i2){
	//return (i1.sup > i2.sup);
	return (i1.inf < i2.inf);
}

int greedySol(vector<int> points, vector<interval> intervals){

	int i = 0, j;
	int minNum = 0;
	int inf = 0, sup = 0;

	//sortare intervale descrescator dupa marginea superioara
	sort(intervals.begin(), intervals.end(), compare);

	if(intervals.size() == 1 && points.at(0) > intervals.at(0).inf && points.at(points.size() - 1) < intervals.at(0).sup){
		minNum++;
	} else {
		while(i < points.size()){
			if(points.at(i) >= inf && points.at(i) <= sup)
				i++;
			else {
					for(j = 0; j < intervals.size(); j++){
						if(points.at(i) >= intervals.at(j).inf && points.at(i) <= intervals.at(j).sup){
							if(intervals.at(j).sup > sup){
								inf = intervals.at(j).inf;
								sup = intervals.at(j).sup;
							}
						}
					}
					minNum++;
				}
			}
		}
	return minNum;
}

int main(int argc, char* argv[]) {

	//FILE* fin = fopen(argv[1], "r");
	FILE* fin = fopen("points.in", "r");
	FILE*  fout = fopen("points.out", "w");
	int N = 0;
	int M = 0;
	int i, num;
	int res;

	//citire numar de puncte si de intervale
	fscanf(fin, "%d %d", &N , &M);

	vector<int> points;
	vector<interval> intervals;

	//citire puncte din fisier si introducere in vector
	for(i = 0; i < N; i++){
		fscanf(fin, "%d", &num);
		points.push_back(num);
	}

	//citire intervale
	for(i = 0; i < M; i++){
		fscanf(fin, "%d %d", &interv.inf, &interv.sup);
		intervals.push_back(interv);
	}

	res = greedySol(points, intervals);
	//printf("Rez = %d\n", res);
	fprintf(fout, "%d\n", res);
	return 0;
}