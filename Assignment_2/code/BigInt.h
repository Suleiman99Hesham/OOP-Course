#ifndef BIGINT_H
#define BIGINT_H
#include<string>
using namespace std;
class BigInt
{
    private:
        string str_num;
    public:
        int sizee;
        BigInt();
        BigInt(string);
        BigInt(int);
        BigInt operator+ (BigInt &);
        BigInt operator- (BigInt &);
        BigInt operator++ (int);
        BigInt operator-- (int);
        bool operator== (BigInt &);
        bool operator!= (BigInt &);
        bool operator> (BigInt &);
        bool operator< (BigInt &);
        friend istream &operator>>(istream &input,BigInt &getting_nums);
        friend ostream &operator<<(ostream &output,const BigInt &print_sum);
};

#endif // BIGINT_H
