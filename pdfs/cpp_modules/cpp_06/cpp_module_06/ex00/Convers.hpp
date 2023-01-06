#ifndef CONVERS_HPP
#define CONVERS_HPP

#include <iostream>
#include <string>
#include<stdio.h>
#include<string.h>
#include <cstdlib>
#include <fstream>
#include <limits>

enum e_type{
    NONE,
    INT,
    FLOAT,
    CHAR,
    DOUBLE,
    LITERALS
};

class Converter{
    private:
        char _c;
        int  _i;
        float _f;
        double _d;
        bool _impossible;
        std::string _s;
        e_type _type;

    public:
        Converter(void);
        Converter(const Converter& src);
        ~Converter(void);

        Converter& operator=(const Converter& src);

        char getC(void) const;
        void setC(char c);

        int getI(void) const;
        void setI(int i);

        float getF(void) const;
        void setF(float f);

        double getD(void) const;
        void setD(double d);

        std::string getStr(void) const;
        void setStr(std::string str);

        e_type getType(void) const;
        /* void setType(e_type t); */
        void setType();
        bool isChar(void) const;
        bool isInt(void) const;
        bool isFloat(void) const;
        bool isDouble(void) const;
        bool isImpossible(void);
        bool isLiterals(void) const;


        void printChar(void) const;
        void printInt(void) const;
        void printFloat(void) const;
        void printDouble(void) const;

        void convert(void);

        int dot_count(void)const;
        int f_count(void)const;

        class ConverterException: public std::exception{
            virtual const char* what() const throw(){
                return "Unknow type";
            };
        };
};

std::ostream& operator<<(std::ostream& out, const Converter& src);

#endif