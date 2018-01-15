#pragma once

#include<map>
#include<vector>
#include<string>
#include <stack>
using namespace std;

class Algorythm {
public:
	Algorythm();
	~Algorythm();
	void mainAlg();
	void iter(int cost);
	bool check();	//Проверка, является ли текущая ветка решением
	map<string, int> names; //Хранит пару имя - номер продукта, служит для перевода из string в int
	vector<pair<map<int, int>, int>> discounts; //вектор который хранит меню следующим способом: пары мэп<номер продукта, его количество>, цена
	map<int, int> needfull;						//хранит пары номер продукта - количество, необходимые нам
	map<map<int, int>, int> sostayanie;
	vector<map<int, int>> sostayanie2;
	vector<map<int, int>> solution;
	int finalPrice;								//оценка сверху, в конце приближается к 
};
