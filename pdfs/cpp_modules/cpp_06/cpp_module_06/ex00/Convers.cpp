#include "Convers.hpp"

Converter::Converter(void){
    this->_c = '\0';
    this->_i = 0;
    this->_f = 0.0f;
    this->_d = 0.0;
}

Converter::Converter(const Converter& src){
    *this = src;
}

Converter::~Converter(void){

}

Converter& Converter::operator=(const Converter&src){
    if(this != &src){
        this->_c = src.getC();
        this->_i = src.getI();
        this->_f = src.getF();
        this->_d = src.getD();
    }
    return *this;
}

char Converter::getC(void) const{
    return this->_c;
}

void Converter::setC(char c){
    this->_c = c;
}

int Converter::getI(void) const{
    return this->_i;
}

void Converter::setI(int i){
    this->_i = i;
}

float Converter::getF(void) const{
    return this->_f;
}

void Converter::setF(float f){
    this->_f = f;
}

double Converter::getD(void) const{
    return this->_d;
}

void Converter::setD(double d){
    this->_d = d;
}

std::string Converter::getStr(void) const{
    return this->_s;
}

void Converter::setStr(std::string str){
    this->_s = str;
    this->setType();//?
    if (getType() == NONE){
        throw Converter::ConverterException();
    }
}

e_type Converter::getType(void) const{
    return this->_type;
}

bool Converter::isChar(void) const{
    return _s.length() == 1 && std::isalpha(_s[0]) && std::isprint(_s[0]);
}

bool Converter::isInt(void) const{
    int i = 0;
    if (_s[i] == '-' || _s[i] == '+')
        i++;
    while(_s[i]){
        if (std::isdigit(_s[i]) == 0)
            return false;
        i++;
    }
    return true;
}

int Converter::dot_count(void)const{
    int i = 0;
    int count = 0;
    while(_s[i]){
        if(_s[i] == '.')
            count++;
        i++;
    }
    return count;
}

bool Converter::isDouble(void) const{
    int i = 0;
    while(_s[i + 1]){
        if(dot_count() != 1 && std::isdigit(_s[i]) != 0)
            return false;
        if(_s[i] == '.' && std::isdigit(_s[i + 1]) != 0)
            return false;
        i++;
    }
    return true;
    
}

int Converter::f_count(void)const{
    int i = 0;
    int count = 0;
    while(_s[i]){
        if(_s[i] == 'f')
            count++;
        i++;
    }
    return count;
}

bool Converter::isFloat(void) const{
    long unsigned int i = 0;
    while(_s[i + 1]){
        if(dot_count() != 1 && std::isdigit(_s[i]) != 0 && f_count() != 1)
            return false;
/*         if(_s[i] == '.' && std::isdigit(_s[i + 1]) != 0)
            return false; */
        if(_s[i] == 'f' && i != _s.length() - 1)
            return false;
        i++;
    }
    return true;
    
}

void    Converter::printChar( void ) const {
    if ( this->isLiterals() || ( !std::isprint( _i ) && ( _i >= 127 ) ) ) {
        std::cout << "Impossible";
    } else if ( !std::isprint( this->_i ) ) {
        std::cout << "None displayable";
    } else {
        std::cout << "'" << getC() << "'";
    }
    std::cout << std::endl;
}

void    Converter::printInt( void ) const {
   // std::cout<<_i<<"printint"<<std::endl;
    if ( this->isLiterals() || ( !std::isprint( _i ) && ( _i >= 127 ) ) ) {
        std::cout << "Impossible";
    } else {
        std::cout << getI();
    }
    std::cout << std::endl;
}

void Converter::printFloat(void) const{
    if (_s.compare("nan") == 0 || _s.compare("nanf") == 0)
        std::cout<<"nanf"<<std::endl;
    else if(_s.compare("+inf") == 0 || _s.compare("+inff") == 0)
        std::cout<<"+inff"<<std::endl;
    else if(_s.compare("-inf") == 0 || _s.compare("-inff") == 0)
        std::cout<<"-inff"<<std::endl;
    else{
        if (_f - static_cast<int > (_f) == 0)
            std::cout<< _f << ".0f"<<std::endl;
        else
            std::cout<< getF()<<"f"<<std::endl;
    }
}

void Converter::printDouble(void) const{
    if (_s.compare("nan") == 0 || _s.compare("nanf") == 0)
        std::cout<<"nan"<<std::endl;
    else if(_s.compare("+inf") == 0 || _s.compare("+inff") == 0)
        std::cout<<"+inf"<<std::endl;
    else if(_s.compare("-inf") == 0 || _s.compare("-inff") == 0)
        std::cout<<"-inff"<<std::endl;
    else{
        if ( _d - static_cast< int > ( _d ) == 0 )
            std::cout<< _d << ".0"<<std::endl;
        else
            std::cout<< getD()<<std::endl;
    }
}

/* void Converter::setType(e_type t){
    _type = t;
} */

void Converter::setType(void){
    if (isChar())
        _type = CHAR;
    else if(isInt())
        _type = INT;
    else if(isDouble())
        _type = DOUBLE;
    else if(isFloat())
        _type = FLOAT;
    else if(isLiterals())
        _type = LITERALS;
    else
        _type = NONE;
}

bool Converter::isImpossible(void){
    try{
        if (_type == INT)
            _i = std::atoi(_s.c_str());
        else if(_type == FLOAT)
            _f = std::atof(_s.c_str());
        else if(_type == DOUBLE)
            _d = std::atof(_s.c_str());
    }
    catch(std::exception& e){
        _impossible = true;
        return true;
    }
    return false;
}

bool Converter::isLiterals(void) const{//infinitive?
    std::string f_infi[][3] = {{"-inff"}, {"+inff"}, {"nanf"}};
    std::string d_infi[][3] = {{"-inf"}, {"+inf"}, {"nan"}};
    int i = 0;

    while (i < 3)
    {
        if (_s == f_infi[0][i] )
            return true;
        if (_s == d_infi[0][i] )
            return true;
        i++;
    }
    return false;
}

void Converter::convert(void){
    if (isImpossible())
        return ;
    if(_type == CHAR){
        _c = _s[0];
        _i = static_cast<int>(_c);
        _f = static_cast<float>(_c);
        _d = static_cast<double>(_c);
    }
    else if (_type == INT){
        _i = std::atoi(_s.c_str());
        _f = static_cast<float>(_i);
        _d = static_cast<double>(_i);
        _c = static_cast<char>(_i);
        //std::cout<<_i<<"are you here"<<std::endl;
    }
    else if(_type == FLOAT){
        _f = std::atof(_s.c_str());
        _i = static_cast<int > (_f);
        _d = static_cast<double>(_f);
        _c = static_cast<char>(_f);
    }
    else if(_type == DOUBLE){
        _d = std::atof(_s.c_str());
        _i = static_cast<int>(_d);
        _f = static_cast<float>(_d);
        _c = static_cast<char>(_d);
    }
}

std::ostream& operator<<(std::ostream& out, const Converter& src){
    out<<"char: "; src.printChar();
    out<<"int: "; src.printInt();
    out<<"float: "; src.printFloat();
    out<<"double: "; src.printDouble();
    return out;
}