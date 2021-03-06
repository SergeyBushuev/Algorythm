#include "stdafx.h"
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <strstream>
#include <map>
#include <vector>
#include <string>
#include "algorythm.h"
#include<locale.h> 

#define pb push_back
using namespace std;
void main() {
	setlocale(LC_ALL, "RUS");
	ifstream fin;
	ofstream fout;
	fin.open("input.dat");
	int n, m;
	Algorythm alg;
	try
	{
		fin >> n >> m;
		for (int i(0); i < n; ++i) {
			map<int, int> saver;
			string s;
			int price;
			fin >> s >> price;
			alg.names[s] = i;
			saver[i] = 1;
			alg.discounts.pb(make_pair(saver, price));
		}
		for (int i(0); i < m + 1; ++i) {
			map<int, int> saver;				//структура для сохранения скидок <товар, количество>
			map<string, int> count;				//структура для подсчета одинаковых наименований
			int price, num;
			vector<string> parsed_str(0);
			fin >> num;
			for (int j(0); j < num; j++) {
				parsed_str.pb("");
				fin >> parsed_str[j];
			}
			fin >> price;
			strstream ff;
			if (parsed_str.size() <=0) {
				fout.open("output.ans");
				fout << "ERROR 1";
				fout.open("output.ans");
				return;
			}
			ff << parsed_str[parsed_str.size() - 1];
			ff >> price;
			for (int j(0); j < parsed_str.size(); ++j) {
				count[parsed_str[j]]++;
			}
			for (auto it = count.begin(); it != count.end(); ++it) {
				if (i < m) {
					saver[alg.names[it->first]] = it->second;
				}
				else {
					alg.needfull[alg.names[it->first]] = it->second;
				}
			}
			if (i < m) alg.discounts.pb(make_pair(saver, price));
		}
	} catch (std::ifstream::failure& e) {
		fout.open("output.ans");
		fout << "ERROR 2";
		fout.open("output.ans");
		return;
	}
	if ((alg.discounts.size() != n + m) || (alg.needfull.size() == 0)) {
		fout.open("output.ans");
		fout << "ERROR 3";
		fout.open("output.ans");
		return;
	}
	fin.close();
	alg.mainAlg();
	fout.open("output.ans");
	for (int i = 0; i < alg.solution.size(); i++) {
		for (auto it = alg.solution[i].begin(); it != alg.solution[i].end(); it++) {
			fout << (it->first + 1) << "-" << it->second << "; ";
		}
		fout << "\n";
	}
	fout << alg.finalPrice;
	fout.close();
}
