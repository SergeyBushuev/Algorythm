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
	bool check();
	bool evristika(map<int, int> &map, int cost, int maxO);
	map<string, int> names; //Хранит пару имя - номер продукта, служит для перевода из string в int
	vector<int> prices;     //Хранит цену в соответствии prices[i] = цена продукта i
	vector<pair<map<int, int>, int>> discounts; //вектор который хранит меню следующим способом: пары мэп<номер продукта, его количество>, цена
	map<int, int> needfull;						//хранит пары номер продукта - количество, необходимые нам
	map<map<int, int>, int> sostayanie;
	stack<map<int, int>> sostayanie2;
	stack<map<int, int>> solution;
	int finalPrice;
	int maxO;									//оценка сверху
};