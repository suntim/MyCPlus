#include<iostream>
using namespace std;

class Jose
{
public:
	Jose(int boys = 10, int begin = 1, int m = 3)
	{
		numOfBoys_ = boys;
		beginPos_ = begin;
		interval_ = m;
	}
	void Initial();
	void GetWinner();
	~Jose();

private:
	int numOfBoys_;
	int beginPos_;
	int interval_;

};

