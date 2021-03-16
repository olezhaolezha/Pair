#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>

using namespace std;

template<typename T1, typename T2>
class Pair {
public:
    T1 first;
    T2 second;

    Pair () {
    }

    Pair (T1 x, T2 y){
        first = x;
        second = y;
    }

    Pair <T1, T2> (const Pair <T1, T2>& copied){
        first = copied.first;
        second = copied.second;
    }

    Pair <T1, T2>& operator= (const Pair <T1, T2>& other) {
        first = other.first;
        second = other.second;
        return *this;
    }

    bool operator< (const Pair& other){
        if (first > other.first){
            return false;
        }
        if (first < other.first) {
            return true;
        }
        return second<other.second;
    }

};

template<typename T>
void mySort(vector<T>& a) {
    for (int i = 1; i < a.size(); ++ i) {
        int j = 0;
        while (!(a[i] < a[j]) && j < i){
            ++ j;
        }
        T x = a[i];
        int k = i;
        while (k > j){
            a[k] = a[k - 1];
            --k;
        }
        a[j] = x;
    }
}

int main() {
    srand(time(NULL));
    int n = 10 + rand() % 10;
    vector<pair<int, double> > a(n);
    vector<Pair<int, double> > b(n);
    for (int i = 0; i < n; ++i) {
        a[i].first = rand() % 100;
        a[i].second = 0.5 + rand() % 100;
        b[i].first = a[i].first;
        b[i].second = a[i].second;
    }
    sort(a.begin(), a.end());
    mySort(b);
    for (int i = 0; i < n; ++i) {
        cout << a[i].first << " " << a[i].second << " " << b[i].first << " " << b[i].second << endl;
    }
    for (int i = 0; i < n; ++i) {
        if (a[i].first != b[i].first) {
            cout << "a[" << i << "].first != b[" << i << "].first: " << a[i].first << " != " << b[i].first << endl;
        }
        if (a[i].second != b[i].second) {
            cout << "a[" << i << "].second != b[" << i << "].second: " << a[i].second << " != " << b[i].second << endl;
        }
    }
}
