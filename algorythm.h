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
	map<string, int> names; //������ ���� ��� - ����� ��������, ������ ��� �������� �� string � int
	vector<int> prices;     //������ ���� � ������������ prices[i] = ���� �������� i
	vector<pair<map<int, int>, int>> discounts; //������ ������� ������ ���� ��������� ��������: ���� ���<����� ��������, ��� ����������>, ����
	map<int, int> needfull;						//������ ���� ����� �������� - ����������, ����������� ���
	map<map<int, int>, int> sostayanie;
	stack<map<int, int>> sostayanie2;
	stack<map<int, int>> solution;
	int finalPrice;
	int maxO;									//������ ������
};