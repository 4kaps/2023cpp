#ifndef _MYRATIONAL_H_
#define _MYRATIONAL_H_
#include <iostream>
#include <vector>
using namespace std;

class myRational
{
private:
 // 분수는 항상 내부적으로 기약분수로 표현하며, 또한 항상 _den>0 이다. long _num; // numerator
    long _num;
    long _den; // denominator
    long gcd(long m, long n); // 최대공약수
    void reduce();
public:
    myRational(long num = 0, long den = 1) : _num(num), _den(den){reduce();}
    myRational(const myRational& r) : _num(r._num), _den(r._den){reduce();}
    friend ostream &operator <<(ostream &outStream, const myRational& r);
    friend istream &operator >>(istream &inStream, myRational& r);
    long getNumerator() const{return _num;}
    long getDenominator() const{return _den;}
    myRational reciprocal() const{return myRational(_den, _num);}
    myRational operator +(const myRational& r);
    myRational operator +(int value);
    friend myRational operator +(int value, const myRational& r);
    myRational operator -(const myRational& r);
    myRational operator -(int value);
    friend myRational operator -(int value, const myRational& r);
    myRational operator *(const myRational& r);
    myRational operator *(int value);
    friend myRational operator *(int value, const myRational& r);
    myRational operator /(const myRational& r);
    myRational operator /(int value);
    friend myRational operator /(int value, const myRational& r);
    myRational operator ++(int);
    myRational& operator ++();
    myRational operator --(int);
    myRational& operator --();
    myRational operator -();
    bool operator ==(const myRational& r) const;
    bool operator >(const myRational& r) const;
    bool operator <(const myRational& r) const;
    bool operator >=(const myRational& r) const;
    bool operator <=(const myRational& r) const;
    bool operator !=(const myRational& r) const;
    myRational& operator =(const myRational& r);
    myRational& operator +=(const myRational& r);
    myRational& operator -=(const myRational& r);
    myRational& operator *=(const myRational& r);
    myRational& operator /=(const myRational& r);
    friend bool compare(const myRational& r1, const myRational& r2);
}; 

ostream &operator <<(ostream &outStream, const myRational& r){
    if (r._num == 0){
        outStream << 0; 
    }else if (r._den == 1){
        outStream << r._num;
    }else{
        outStream << r._num << "/" << r._den;
    }
    return outStream;
}

istream &operator >>(istream &inStream, myRational& r){
    inStream >> r._num >> r._den;
    if(r._den == 0){
        r._num = 0;
        r._den = 1;
    }
    r.reduce();
    return inStream;
}

myRational myRational::operator +(const myRational& r){
    long newNum = _num * r._den + r._num * _den;
    long newDen = _den * r._den;
    myRational result(newNum, newDen);
    result.reduce();
    return result;
}
myRational myRational::operator +(int value){
    long newNum = _num + value * _den;
    myRational result(newNum, _den);
    result.reduce();
    return result;
}
myRational operator +(int value, const myRational& r){
    long newNum = r._num + value * r._den;
    myRational result(newNum, r._den);
    result.reduce();
    return result;
}
myRational myRational::operator -(const myRational& r){
    long newNum = _num * r._den - r._num * _den;
    long newDen = _den * r._den;
    myRational result(newNum, newDen);
    result.reduce();
    return result;
}
myRational myRational::operator -(int value){
    long newNum = _num - value * _den;
    myRational result(newNum, _den);
    result.reduce();
    return result;
}
myRational operator -(int value, const myRational& r){
    long newNum = value * r._den - r._num;
    myRational result(newNum, r._den);
    result.reduce();
    return result;
}
myRational myRational::operator *(const myRational& r){
    long newNum = _num * r._num;
    long newDen = _den * r._den;
    myRational result(newNum, newDen);
    result.reduce();
    return result;
}
myRational myRational::operator *(int value){
    long newNum = _num * value;
    myRational result(newNum, _den);
    result.reduce();
    return result;
}
myRational operator *(int value, const myRational& r){
    long newNum = value * r._num;
    myRational result(newNum, r._den);
    result.reduce();
    return result;
}
myRational myRational::operator /(const myRational& r){
    if(_den == 0 || r._den == 0){return 0;}
    long newNum = _num * r._den;
    long newDen = _den * r._num;
    myRational result(newNum, newDen);
    result.reduce();
    return result;
}
myRational myRational::operator /(int value){
    if(_den == 0){
        return 0;
    }else{
        long newDen = _den * value;
        myRational result(_num, newDen);
        result.reduce();
        return result;
    }
}
myRational operator /(int value, const myRational& r){
    if(r._den == 0){
        return 0;
    }else{
        long newNum = value * r._den;
        long newDen = r._num;
        myRational result(newNum, newDen);
        result.reduce();
        return result;
    }
}
bool myRational::operator ==(const myRational& r) const{
    return (_num == r._num && _den == r._den);
}
bool myRational::operator >(const myRational& r) const{
    long a = _num * r._den;
    long b = r._num * _den;
    return (a > b);
}
bool myRational::operator <(const myRational& r) const{
    long a = _num * r._den;
    long b = r._num * _den;
    return (a < b);
}
bool myRational::operator >=(const myRational& r) const{
    long a = _num * r._den;
    long b = r._num * _den;
    return (a >= b);
}
bool myRational::operator <=(const myRational& r) const{
    long a = _num * r._den;
    long b = r._num * _den;
    return (a <= b);
}
bool myRational::operator !=(const myRational& r) const{
    long a = _num * r._den;
    long b = r._num * _den;
    return (a != b);
}

myRational& myRational::operator =(const myRational& r){
    this->_num = r._num;
    this->_den = r._den;
    reduce();
    return *this;
}
myRational& myRational::operator +=(const myRational& r){
    _num = _num * r._den + r._num * _den;
    _den *= r._den;
    reduce();
    return *this;
}
myRational& myRational::operator -=(const myRational& r){
    _num = _num * r._den - r._num * _den;
    _den *= r._den;
    reduce();
    return *this;
}
myRational& myRational::operator *=(const myRational& r){
    _den *= r._den;
    _num *= r._num;
    reduce();
    return *this;
}
myRational& myRational::operator /=(const myRational& r){
    if(_den == 0 || r._den == 0){
        _num = 0;
        return *this;
    }else{
        _den *= r._num;
        _num *= r._den;
        reduce();
        return *this;
    }
}

myRational myRational::operator ++(int){
    myRational temp(*this);
    _num += _den;
    return temp;
}
myRational& myRational::operator ++(){
    _num += _den;
    return *this;
}
myRational myRational::operator --(int){
    myRational temp(*this);
    _num -= _den;
    return temp;
}
myRational& myRational::operator --(){
    _num -= _den;
    return *this;
}
myRational myRational::operator -(){
    return myRational(-_num, _den);
}

long myRational::gcd(long m, long n)
{
    if (m == n)
        return n;
    else if (m < n)
        return gcd(m, n - m);
    else
        return gcd(m - n, n);
}

void myRational::reduce()
{
    if (_num == 0 || _den == 0)
    {
        _num = 0;
        _den = 1;
        return;
    }
    if (_den < 0)
    {
        _den *= -1;
        _num *= -1;
    }
    if (_num == 1)
        return;
    
    int sgn = (_num < 0 ? -1 : 1);
    long g = gcd(sgn * _num, _den);
    _num /= g;
    _den /= g;
}

void testSimpleCase();

bool compare(const myRational& r1, const myRational& r2){
    if(r1._num * r2._den == r2._num * r1._den){
        return r1._den < r2._den;
    }
    return r1._num * r2._den < r2._num * r1._den;
}

int main(){
    testSimpleCase();
    int k;
    cin >> k;
    for(int i=0; i<k; i++){
        int n;
        cin >> n;
        vector<myRational> fraction;
        for(int j=0; j<n; j++){
            int a, b;
            cin >> a >> b;
            myRational frac(a, b);
            fraction.push_back(frac);
        }
        for (int j = 0; j < n - 1; j++) {
            for (int l = 0; l < n - j - 1; l++) {
                if (!compare(fraction[l], fraction[l + 1])) {
                    swap(fraction[l], fraction[l + 1]);
                }
            }
        }
        // 정렬된 유리수를 출력합니다.
        for (int j = 0; j < n; j++) {
            cout << fraction[j] << " ";
        }
        cout << endl;
    }
    return 0;
}

void testSimpleCase(){
    myRational frac1(2), frac2(3, 2), frac3(6, 4), frac4(12, 8), frac5, frac6, frac7;

    cout << frac1 << " " << frac2 << " " << frac3 << " " << frac4 << " " << frac5 << endl;
    cout << frac1.getNumerator() << " " << frac1.getDenominator() << endl;

    // Check arithmetic operators
    cout << frac1 * frac2 << " " << frac1 + frac3 << " " << frac2 - frac1 << " " << frac3 / frac2 << endl;
    // Check comparison operators
    cout << ((frac1 < frac2) ? 1 : 0) << " "
         << ((frac1 <= frac2) ? 1 : 0) << " "
         << ((frac1 > frac2) ? 1 : 0) << " "
         << ((frac1 >= frac2) ? 1 : 0) << " "
         << ((frac1 == frac2) ? 1 : 0) << " "
         << ((frac1 != frac2) ? 1 : 0) << " "
         << ((frac2 < frac3) ? 1 : 0) << " "
         << ((frac2 <= frac3) ? 1 : 0) << " "
         << ((frac2 > frac3) ? 1 : 0) << " "
         << ((frac2 >= frac3) ? 1 : 0) << " "
         << ((frac2 == frac3) ? 1 : 0) << " "
         << ((frac2 != frac3) ? 1 : 0) << endl;
    
    cout << (frac6 = frac3) << " ";
    cout << (frac6 += frac3) << " ";
    cout << (frac6 -= frac3) << " ";
    cout << (frac6 *= frac3) << " ";
    cout << (frac6 /= frac3) << endl;
    
    cout << -frac6 << endl;

    frac6 = (++frac4) + 2;
    frac7 = 2 + (frac4++);
    cout << frac4 << " " << frac6 << " " << frac7 << endl;

    frac6 = (--frac4) - 2;
    frac7 = 2 - (frac4--);
    cout << frac4 << " " << frac6 << " " << frac7 << endl;

    cout << 2 * frac3 << " " << frac3 * 2 << " " << 2 / frac3 << " " << frac3 / 2 << endl;
}

#endif
