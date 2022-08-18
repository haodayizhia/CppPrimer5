#include <iostream>
#include <string>
#include <vector>

using std::cerr;
using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

template <typename T>
void print(const T &a)
{
	cout << a.size() << ' ';
	for (auto i : a)
		cout << i << ' ';
	cout << endl;
}

int main(int argc, char *argv[])
{
	vector<int> v1;
	print(v1);
	vector<int> v2(10);
	print(v2);
	vector<int> v3(10, 42);
	print(v3);
	vector<int> v4{10};
	print(v4);
	vector<int> v5{10, 42};
	print(v5);
	vector<string> v6{10};
	print(v6);
	vector<string> v7{10, "hi"};
	print(v7);
	return 0;
}

// 高级版本
#include <iostream>
#include <string>
#include <vector>
#include <memory>

using std::cerr;
using std::cin;
using std::cout;
using std::endl;
using std::make_shared;
using std::shared_ptr;
using std::string;
using std::vector;

class vec
{
public:
	vec() = default;
	virtual void print() const {};
	virtual ~vec() = default;
};

class vec_int : public vec
{
public:
	vec_int() = default;
	vec_int(const vector<int> &ini) : vi(ini)
	{
	}
	void print() const override
	{
		cout << "size:" << vi.size() << ' ' << "value:";
		for (auto &i : vi)
		{
			cout << i << ' ';
		}
		cout << endl;
	}

private:
	vector<int> vi = {};
};

class vec_str : public vec
{
public:
	vec_str();
	vec_str(const vector<string> &ini) : vs(ini)
	{
	}
	void print() const override
	{
		cout << "size:" << vs.size() << ' ' << "value:";
		for (auto &i : vs)
		{
			cout << i << ' ';
		}
		cout << endl;
	}

private:
	vector<string> vs;
};

int main(int argc, char *argv[])
{
	int count = 1;
	vector<shared_ptr<vec>> vv;
	shared_ptr<vec_int> v1 = make_shared<vec_int>(vector<int>());
	vv.push_back(v1);
	shared_ptr<vec_int> v2 = make_shared<vec_int>(vector<int>(10));
	vv.push_back(v2);
	shared_ptr<vec_int> v3 = make_shared<vec_int>(vector<int>(10, 42));
	vv.push_back(v3);
	shared_ptr<vec_int> v4 = make_shared<vec_int>(vector<int>{10});
	vv.push_back(v4);
	shared_ptr<vec_int> v5 = make_shared<vec_int>(vector<int>{10, 42});
	vv.push_back(v5);
	shared_ptr<vec_str> v6 = make_shared<vec_str>(vector<string>{10});
	vv.push_back(v6);
	shared_ptr<vec_str> v7 = make_shared<vec_str>(vector<string>{10, "hi"});
	vv.push_back(v7);
	for (auto i : vv)
	{
		cout << 'v' << count << ':';
		i->print();
		++count;
	}
	return 0;
}
