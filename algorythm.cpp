#include "stdafx.h"
#include "iostream"
#include "algorythm.h"
#include <algorithm>
#define pb push_back
using namespace std;
Algorythm::Algorythm() {};
Algorythm::~Algorythm() {};
void Algorythm::mainAlg() {
	maxO = 0;
	for (auto it = needfull.begin(); it != needfull.end(); it++) {
		maxO = maxO + discounts[it->second].second*needfull[it->first];
	}
	finalPrice = maxO;
	cout <<"\nPervaya ocenka sverhu = " << maxO;
	int cost = 0;
	iter(cost);
}
bool Algorythm::evristika(map<int, int> &map, int cost, int maxO) {
	if (cost > maxO) return true;
	else return false;
}
bool Algorythm::check() {
	for (auto it = needfull.begin(); it != needfull.end(); it++) {
		if (it->second > 0) return false; 
	}
	return true;
}

void Algorythm::iter(int cost) {

	if (sostayanie.find(needfull) != sostayanie.end() && sostayanie[needfull] <= cost) return;
	else sostayanie[needfull] = cost; //(��� ������ ����� ������� �������� it = sostayanie.find(needfull), ��� ��� ���� ��� ����� �� ��������)
	//cout << " "<< cost;
	
	if (cost > finalPrice) return;

	if (check()) {
		if (cost < finalPrice) {
			finalPrice = cost;
		}
	//	cout << " SOLUTION COST =" << finalPrice;
		return;
	}
	for (auto it = discounts.begin(); it != discounts.end(); it++) {        //�������� �� ������� discount
		auto skidon = it->first;                                            //����������� ���������� skidon ��������� �� ����� ��������� � ������
		bool flag = false;                                                  //���� ��������� ������. ������ - ������ ����� �������� � �������. ������ - ������ �� �������� � �������
		vector<pair<int, int> > added(0);
		for (auto itt = skidon.begin(); itt != skidon.end(); itt++) {       //�������� �� ��������� � ���������� skidon
			if (needfull.find(itt->first) != needfull.end() && needfull[itt->first] > 0) { added.pb(make_pair(itt->first, itt->second)); flag = true; needfull[itt->first] -= itt->second; } //���� � ������ ������� ���������� � ������� ��������, �� �� � ��������. � ����� ������ ��������� ����, �������� ���������� �� ������ �������� �� �������������.
		}
		if (!flag) continue;
		sostayanie2.push(skidon);
		iter(cost + it->second); //���� ���� ������ - ���������� ��������� ������������� ��������� � ����������� �������, � ��������� ����� �������� �� ������
		sostayanie2.pop();
		for (int i(0); i < added.size(); ++i) {
			needfull[added[i].first] += added[i].second;
		}
	}
	return;
}