#include <iostream>
#include <fstream>
#define Max 400

int Isood(int n);
int Compare(int a,int b);
using namespace std;


int main() {
    int a[Max]{};//文件所有数字输入的数组
    int b[Max]{};//第一个数组,从a数组的第二个数开始分配,分配Num个
    int c[Max]{};//第二个数组,a数组Num+1个开始分配,分配Num个
    int Num;//每个数组中分别有多少个数
    int Mid;//Num = 2*Mid+1
    int MidNumber;
    int pos = 0;
    bool flag = true;
    ifstream Infile("/Users/CristinaSt/Documents/算法设计/test1/test1.txt");//输入的文件
    ofstream Outfile("/Users/CristinaSt/Documents/算法设计/test1/test2.txt");//输出的文件
    if(Infile){
        while (!Infile.eof()){
            Infile >> a[pos];
            pos++;
        }
    }
    else{
        cout << "this is file not exist"<<endl;
    }
    Infile.close();


    Num = a[0];
    //第一个数组
    for (int i = 1; i <= Num; ++i) {
        b[i-1] = a[i];
    }

    //第二个数组
    for (int i = Num+1; i <= 2*Num; ++i) {
        c[i- Num - 1] = a[i];
    }

    //分治法进行查找中位数
    while (flag){
        if(Isood(Num)!=0){
            if(Mid==1) {
                MidNumber = Compare(b[Mid],c[Mid]);
                flag = false;
            }
            Mid = (Num-1)/2;
            if (b[Mid] < c[Mid]){
                for (int i = Mid; i <= 2*Mid-1; ++i) {
                    b[i - Mid] = b[i];
                    cout <<b[i - Mid]<<" ";
                }
                for (int i = 0; i <= Mid-1; ++i) {
                    c[i] = c[i];
                }
                Num = Mid;

            }
            if(b[Mid] > c[Mid]){
                for (int i = Mid; i <= 2*Mid-1; ++i) {
                    c[i - Mid] = c[i];
                }
                for (int i = 0; i <= Mid-1; ++i) {
                    b[i] = b[i];
                }
                Num = Mid;

            }
            if (b[Mid] == c[Mid]){
                MidNumber = b[Mid];
                flag = false;
            }
        }
        else {
            Mid = Num / 2;
            if(Mid==1) {
                MidNumber = Compare(b[Mid],c[Mid]);
                flag = false;
            }
            if (b[Mid] < c[Mid]) {
                for (int i = Mid + 1; i <= 2*Mid-1; ++i) {
                    b[i - Mid - 1] = b[i];
                }
                cout << endl;
                for (int i = 0; i <= Mid-1; ++i) {
                    c[i] = c[i];
                }
                Num = Mid;
            }
            if (b[Mid] > c[Mid]) {
                for (int i = Mid + 1; i <= 2 * Mid - 1; ++i) {
                    c[i - Mid - 1] = c[i];
                }
                cout << endl;
                for (int i = 0; i <= Mid - 1; ++i) {
                    b[i] = b[i];
                }
                Num = Mid;
            }
            if (b[Mid] == c[Mid]){
                MidNumber = b[Mid];
                flag = false;
            }
        }
    }

    cout<<"The middle number in the file is: "<< MidNumber;

    Outfile << MidNumber<<endl;

    return 0;
}

int Isood(int n) {
    return n%2;
}
int Compare(int a,int b){
    if(a>b)return b;
    if(a<b)return a;
    if(a==b)return (a+b)/2;
}


