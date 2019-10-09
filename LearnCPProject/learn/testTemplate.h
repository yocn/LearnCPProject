//
// Created by 赵英坤 on 2019/9/27.
//

#ifndef LEARNCPPROJECT_TESTTEMPLATE_H
#define LEARNCPPROJECT_TESTTEMPLATE_H

#include <iostream>
#include <ostream>

namespace templateNS {

    template<typename T1, typename T2>
    class TemplateClass {
    private:
        char *m_desc{};
        T1 m_left;
        T2 m_right;
    public:
        TemplateClass() = default;

        void setDesc(char *desc);

        void setLeft(T1 left);

        void setRight(T2 right);

        char *getDesc() const;

        T1 getLeft() const;

        T2 getRight() const;

        TemplateClass(char *desc, T1 t1, T2 t2) : m_desc(desc), m_left(t1), m_right(t2) {}

        void show();

    };

    /**
     * 如何让template和typedef同时使用
     * @tparam T1
     * @tparam T2
     */
    template<typename T1, typename T2>
    class TemplateClassDef {
    private:
        char *m_desc{};
        T1 m_left;
        T2 m_right;
    public:
        TemplateClassDef(char *desc, T1 t1, T2 t2) : m_desc(desc), m_left(t1), m_right(t2) {}

        void show();

    };

    template<typename T1, typename T2>
    void TemplateClassDef<T1, T2>::show() {
        std::cout << m_desc << "-> " << m_left << " " << m_right << std::endl;
    }

    template<typename T1, typename T2>
    char *TemplateClass<T1, T2>::getDesc() const {
        return m_desc;
    }

    template<typename T1, typename T2>
    void TemplateClass<T1, T2>::setDesc(char *desc) {
        TemplateClass::m_desc = desc;
    }

    template<typename T1, typename T2>
    T1 TemplateClass<T1, T2>::getLeft() const {
        return m_left;
    }

    template<typename T1, typename T2>
    void TemplateClass<T1, T2>::setLeft(T1 left) {
        TemplateClass::m_left = left;
    }

    template<typename T1, typename T2>
    T2 TemplateClass<T1, T2>::getRight() const {
        return m_right;
    }

    template<typename T1, typename T2>
    void TemplateClass<T1, T2>::setRight(T2 right) {
        TemplateClass::m_right = right;
    }

    template<typename T1, typename T2>
    void TemplateClass<T1, T2>::show() {
        std::cout << m_desc << "-> " << m_left << " " << m_right << std::endl;
    }

    //模板方法，传入指针
    template<typename T>
    void Swap(T *a, T *b) {
        T c = *a;
        *a = *b;
        *b = c;
    }

    //模板方法，传入引用
    template<typename TT>
    void Swap(TT &a, TT &b) {
        TT c = a;
        a = b;
        b = c;
    }

    void test();
}


#endif //LEARNCPPROJECT_TESTTEMPLATE_H
