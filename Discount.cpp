// Discount.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <strstream>
#include <map>
#include <vector>
#include <string>
#include "algorythm.h"
#define pb push_back
using namespace std;
void main() {
	ifstream fin;
	fin.open("input.test");
	int n, m, need;
	Algorythm alg;
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
	for (int i(0); i < m+1; ++i) {
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
		ff << parsed_str[parsed_str.size() - 1];
		ff >> price;
		for (int j(0); j < parsed_str.size() ; ++j) {
			count[parsed_str[j]]++;
		}
		for (auto it = count.begin(); it != count.end(); ++it) {
			if (i < m) {
				saver[alg.names[it->first]]= it->second;
			}
			else {
				alg.needfull[alg.names[it->first]] = it->second;
			}
		}
		if (i < m) alg.discounts.pb(make_pair(saver, price));
	}
	cout << "\n"; 
	for (int i = 0; i < alg.discounts.size(); i++)
	{
		cout << "Skidka #" << i << " veshi ";
		for (auto it = alg.discounts[i].first.begin(); it != alg.discounts[i].first.end(); it++) {
			cout << it->first << "-" << it->second << " ";
		}
		cout << "Price "<< alg.discounts[i].second << "\n";
	}
	cout << "Nujno ";
	for (auto it = alg.needfull.begin(); it != alg.needfull.end(); it++) {
		cout << it->first << "-" << it->second << "; ";
	}
	fin.close();
	alg.mainAlg();
	ofstream fout;
	fout.open("output.ans");
	fout << alg.finalPrice;
	fout.close();
	cout << "\nfinal price = " << alg.finalPrice;
	getchar();
}