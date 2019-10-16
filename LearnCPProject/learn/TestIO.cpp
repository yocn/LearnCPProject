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

    void writeStudent2File() {
        Student s;
//        _Stu stu1 = new Student();
//        char *name1 = const_cast<char *>("aaaaaaaaaaaaaaaaaaaa");
//        memcpy(stu1->m_name, name1, sizeof(char) * 20);
//        stu1->m_age = 0;
//        cout << "写入name:" << stu1->m_name << " age:" << stu1->m_age << endl;
//        ofstream outFile("stu.dat", ios::out | ios::binary);
//        outFile.write((const char *) (&stu1), sizeof(Student));
//        outFile.close();


        ofstream outFile("students.dat", ios::out | ios::binary);
        while (cin >> s.m_name >> s.m_age)
            if (s.m_age == 'n') {
                break;
            }
        outFile.write((char *) &s, sizeof(s));
        outFile.close();
    }

    void readStudentFromDat() {
        ifstream inFile("stu.dat", ios::in | ios::binary);
        _Stu stu = new Student;
        Student student;
        while (inFile.read((char *) (&student), sizeof(student))) {
            int readByte = inFile.gcount();
            cout << "读取name:" << student.m_name << " age:" << student.m_age << "    read:" << readByte << endl;
        }
        inFile.close();

    }

    int getline(char *buf, int size, FILE *file) {
        char *start = buf;
        int cnt = 0;
        int eof = 0;
        int eol = 0;
        int c;

        if (size < 1) {
            return 0;
        }

        while (cnt < (size - 1)) {
            c = getc(file);
            if (c == EOF) {
                eof = 1;
                break;
            }

            *(buf + cnt) = c;
            cnt++;

            if (c == '\n') {
                eol = 1;
                break;
            }
        }

        /* Null terminate what we've read */
        *(buf + cnt) = '\0';

        if (eof) {
            return -1;
        } else if (eol) {
            return buf - start;
        } else {
            return -1; // longer than the size to read
        }
    }


    void tests() {
        std::ifstream ifstream("a.txt");

        fflush(stdout);
        if (ifstream.is_open()) {
            std::string temp;
            std::getline(ifstream, temp);
//            printf("temp:%s %d\n\n", temp.data(), 1);

            std::string line;
            while (std::getline(ifstream, line)) {
                printf("%s\n", line.data());
            }
            ifstream.close();
        }
        printf("---------------------------\n");


        FILE *fp;
        char line[1024];
        int len = 1024;
        int read;

        fp = fopen("a.txt", "r");
        if (fp != NULL) {
            while ((read = getline(line, len, fp)) != -1) {
                // TODO parse the line
                printf("%s", line);
            }

            fclose(fp);
        }

    }

    void test() {
//        testInOut();
//        testReverses();
//        testIn();
//        testOpenFile();
//        writeStudent2File();
//        readStudentFromDat();
//        tests();
        int a = 1;
        int b = 9;
        string sss = "sss";
        Student stu;
        stu.m_age = 101;

//        CHECK_EQ(a + b, stu.m_age);
//        cout << varName(stu) << endl;
//        printExp(a);
//        printExp(b);
//        printExp(sss);
//        printExp(stu);
    }
};
