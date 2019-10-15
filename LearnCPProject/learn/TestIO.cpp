//
// Created by 赵英坤 on 2019/10/14.
//

#include <iostream>
#include <fstream>
#include "TestIO.h"

namespace TestIONS {

    void testInOut() {
        int x, y;
        cin >> x >> y;
        //将标准输出重定向到 test.txt文件
        freopen("test.txt", "w", stdout);
        cout << "x:" << x << " y:" << y << endl;
        cerr << "no error!" << endl;
    };

    void testReverses() {
        string str = "abcdefg";
        for (int i = str.length() - 1; i >= 0; --i) {
            cout.put(str[i]);
        }
        cout.put('\n');
    }

    void testIn() {
        int n;
        int maxN = 0;
        while (cin >> n) {
            maxN = n > maxN ? n : maxN;
            if (n == 'n') {
                break;
            }
        }
        cout << "max:" << maxN << endl;
    }

    void testOpenFile() {
        ifstream inFile2("test.txt", ios_base::in);
        inFile2.close();
        ifstream inFile;
        inFile.open("test.txt", ios_base::in);
        if (inFile) {
            //打开成功
            char i;
            while (inFile >> i) {
                cout << i << endl;
            }
            inFile.close();
        } else {
            cout << "打开失败" << endl;
        }

    }

    void test() {
//        testInOut();
//        testReverses();
//        testIn();
        testOpenFile();
    }
};
