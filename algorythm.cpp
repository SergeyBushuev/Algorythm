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
	else sostayanie[needfull] = cost; //(тут есесно лучше сделать итератор it = sostayanie.find(needfull), шоб три раза эту хуйню не вызывать)
	//cout << " "<< cost;
	
	if (cost > finalPrice) return;

	if (check()) {
		if (cost < finalPrice) {
			finalPrice = cost;
		}
	//	cout << " SOLUTION COST =" << finalPrice;
		return;
	}
	for (auto it = discounts.begin(); it != discounts.end(); it++) {        //проходим по массиву discount
		auto skidon = it->first;                                            //присваиваем переменной skidon указатель на набор продуктов в скидке
		bool flag = false;                                                  //флаг состояния скидки. Поднят - скидку можно включить в решение. Опущен - скидка не подходит к решению
		vector<pair<int, int> > added(0);
		for (auto itt = skidon.begin(); itt != skidon.end(); itt++) {       //проходим по продуктам в переменной skidon
			if (needfull.find(itt->first) != needfull.end() && needfull[itt->first] > 0) { added.pb(make_pair(itt->first, itt->second)); flag = true; needfull[itt->first] -= itt->second; } //если в скидке имеются оставшиеся к покупке продукты, то мы её покупаем. В таком случае поднимаем флаг, вычитаем полученные по скидке продукты из требовавшихся.
		}
		if (!flag) continue;
		sostayanie2.push(skidon);
		iter(cost + it->second); //если флаг поднят - прибавляем стоимость приобретённого комплекта к потраченным деньгам, и запускаем новую итерацию от данной
		sostayanie2.pop();
		for (int i(0); i < added.size(); ++i) {
			needfull[added[i].first] += added[i].second;
		}
	}
	return;
}