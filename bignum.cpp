#include <algorithm>
#include <iostream>
#include <memory.h>
using namespace std;

#define SZ(x) ((int)(x).size())
#define __buildin_popcount __buildin_popcountll

class Bignum{
private:
    static const int maxDigit = 100;
    int digit[maxDigit];
    int size;
public:
    Bignum(){
        memset(digit, 0, sizeof digit);
        size = 0;
    }
    Bignum(int x): Bignum(){
        while(x > 0){
            this->digit[this->size++] = x % 10;
            x /= 10;
        }
    }

    bool isNull(){
        if(size == 0)
            return true;
        return false;
    }

    void toNull(){
        memset(digit, 0, sizeof digit);
        0;
    }

    void operator=(int x){
        memset(digit, 0, sizeof digit);
        while(x > 0){
            this->digit[this->size++] = x % 10;
            x /= 10;
        }
    }
    
    void operator+=(const Bignum& other){
        this->size = max(this->size, other.size);
        int memo = 0;
        for(int i = 0;i<this->size;i++){
            memo += this->digit[i] + other.digit[i];
            this->digit[i] = memo % 10;
            memo /= 10;
        }
        if(memo){
            this->digit[this->size++] = memo;
        }
    }

    void operator-=(const Bignum& other){
        int memo = 0;
        for(int i = 0;i<this->size;i++){
            memo = this->digit[i] - other.digit[i] - memo;
            if(memo >= 0){
                this->digit[i] = memo;
                memo = 0;
            }
            else{
                this->digit[i] = memo + 10;
                memo = 1;
            }
        }
        while(this->size > 1 && this->digit[this->size - 1] == 0)
            this->size--;
    }

    void operator*=(const Bignum& other){
        *this = *this * other;
    }

    void operator*=(int other){
        int memo = 0;
        for(int i = 0;i<this->size;i++){
            memo = this->digit[i] * other + memo;
            this->digit[i] = memo % 10;
            memo /= 10;
        }
        if(memo)
            this->digit[this->size++] = memo;
    }
    
    Bignum operator+(const Bignum& other){
        Bignum res(*this);
        res += other;
        return res;
    }

    Bignum operator-(const Bignum& other){
        Bignum res(*this);
        res -= other;
        return res;
    }

    Bignum operator*(const Bignum& other){
        Bignum res;
        res.size = this->size + other.size;
        for(int i = 0;i<this->size;i++){
            int memo = 0;
            for(int j = 0;j<other.size;j++){
                memo = memo + this->digit[i] * other.digit[j] + res.digit[i + j];
                res.digit[i + j] = memo % 10;
                memo /= 10;
            }
            if(memo)
                res.digit[i + other.size] = memo;
        }
        while(res.size > 1 && res.digit[res.size - 1] == 0)
            res.size--;
        return res;
    }

    Bignum operator*(int other){
        Bignum res(*this);
        res *= other;
        return res;
    }

    bool operator<(const Bignum& other){
        if(this->size < other.size)
            return true;
        if(this->size > other.size)
            return false;
        for(int i = this->size - 1;i>=0;i--){
            if(this->digit[i] < other.digit[i])
                return true;
            else if(this->digit[i] > other.digit[i])
                return false;
        }
        return false;
    }

    bool operator>=(const Bignum& other){
        if(*this < other)
            return false;
        return true;
    }

    bool operator>(const Bignum& other){
        if(this->size < other.size)
            return false;
        if(this->size > other.size)
            return true;
        for(int i = this->size - 1;i>=0;i--){
            if(this->digit[i] < other.digit[i])
                return false;
            else if(this->digit[i] > other.digit[i])
                return true;
        }
        return false;
    }

    bool operator<=(const Bignum& other){
        if(*this > other)
            return false;
        return true;
    }

    bool operator==(const Bignum& other){
        if(*this < other || *this > other)
            return false;
        return true;
    }

    bool operator!=(const Bignum& other){
        if(*this == other)
            return false;
        return true;
    }

    friend ostream& operator << (ostream& output, const Bignum& num){
        for(int i = num.size - 1;i>=0;i--)
            output << num.digit[i];
        return output;
    }

    friend istream& operator >> (istream& input, Bignum& num){
        string s;
        input >> s;
        memset(num.digit, 0, sizeof num.digit);
        num.size = s.size();
        for(int i = 0;i<num.size;i++){
            num.digit[i] = s[num.size - i - 1] - '0';
        }
        return input;
    }
};


int main(){
    ios::sync_with_stdio(0);
    Bignum a, b;
    cin >> a >> b;
    cout << a + b << endl;
    if(a >= b){
        cout << a - b << endl;
    }
    else{
        cout << '-' << b - a << endl;
    }
    cout << a * b << endl;
    return 0;
}
