#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include "D.hpp"

int lucky;

Base* generate(){
    if(lucky == 0){
        std::cout<<"generated A class"<<std::endl;
        return new A();
    }
    else if(lucky == 1){
        std::cout<<"generated B class"<<std::endl;
        return new B();
    }
    else if(lucky == 2){
        std::cout<<"generated C class"<<std::endl;
        return new C();
    }
    else if(lucky == 3){
        std::cout<<"generated D class"<<std::endl;
        new D;
    }
    std::cout<<"your number is not lucky, any class can't generated"<<std::endl;
    return NULL;
}

void identify(Base* b){
    if (dynamic_cast<A*>(b) != NULL)
        std::cout<<"A class was identified"<<std::endl;
    else if (dynamic_cast<B*>(b) != NULL)
        std::cout<<"B class was identified"<<std::endl;
    else if (dynamic_cast<C*>(b) != NULL)
        std::cout<<"C class was identified"<<std::endl;
    else if (dynamic_cast<D*>(b) != NULL)
        std::cout<<"D class was identified"<<std::endl;
    else
        std::cout<<"Cant identify class"<<std::endl;
}

void identify(Base& p){
    try{
        A& a = dynamic_cast<A&>(p);
        std::cout<<"A"<<std::endl;
        (void)a;
    }catch(const std::exception& e){

    }
    try{
        B& b = dynamic_cast<B&>(p);
        std::cout<<"B"<<std::endl;
        (void)b;
    }catch(const std::exception& e){

    }try{
        C& c = dynamic_cast<C&>(p);
        std::cout<<"C"<<std::endl;
        (void)c;
    }catch(const std::exception& e){

    }
}



int main(){
    std::cout<<"give me a number...{0/1/2}"<<std::endl;
    std::cin>>lucky;
    Base *base;
    base = generate();
    identify(base);
    identify(*base);

    
}