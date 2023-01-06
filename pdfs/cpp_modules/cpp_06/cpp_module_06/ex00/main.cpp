#include "Convers.hpp"
/* char find_type(char *s)
{
    int i = 0;
    int f_flag = 0;
    int d_flag = 0;
    // int n_flag = 0;
    while (s[i])
    {
        if (!isdigit(s[i]) && s[i] != '.' && s[i] != 'f')
        {
            return 'c';
        }
        if (s[i] == '.')
            d_flag = 1;
        if (s[i] == 'f' && d_flag == 1)
            f_flag = 1;
        i++;
    }
    if (d_flag == 1 && f_flag == 1)
        return 'f';
    else if (d_flag == 1 && f_flag == 0)
        return 'd';
    return 'i';
}

void conversation(char *s){

} 

void conversation_int(char *s)
{
    std::cout << "char: Non displayable" << std::endl;
    std::cout << "int: " << atoi(s) << std::endl;
    std::cout << "float: " << atof(s) << ".0f" << std::endl;
    std::cout << "double: " << atoi(s) << ".0" << std::endl;
}

void conversation_f(char *s)
{
    int number = atoi(s);
    float fnumber = (float)number;
    std::cout << "char: Non displayable" << std::endl;
    std::cout << "int: " << number << std::endl;
    std::cout<< "float: "<<fnumber<<std::endl;
}

std::string is_pseudo_literals(char *s)
{
    std::string f_infi[1][3] = {"-inff", "+inff", "nanf"};
    std::string d_infi[1][3] = {"-inf", "+inf", "nan"};
    int i = 0;

    while (i < 3)
    {
        if (s == f_infi[0][i])
            return s;
        if (s == d_infi[0][i])
            return s;
        i++;
    }
    return "NULL";
}

void conversation_inf(char *s)
{
    std::string f_infi[1][3] = {"-inff", "+inff", "nanf"};
    std::string d_infi[1][3] = {"-inf", "+inf", "nan"};
    int i = 0;

    while (i < 3)
    {
        if (s == f_infi[0][i])
            break;
        if (s == d_infi[0][i])
            break;
        i++;
    }
    std::cout << "char: impossible" << std::endl;
    std::cout << "int: impossible" << std::endl;
    std::cout << "float: " << f_infi[0][i] << std::endl;
    std::cout << "double " << d_infi[0][i] << std::endl;
}
int main(int ac, char **av)
{
    if (ac == 2)
    {
        if (is_pseudo_literals(av[1]) != "NULL")
        {
            conversation_inf(av[1]);
            return (0);
        }
        char t = find_type(av[1]);
        std::cout << t << std::endl;
        if (t == 'i')
            conversation_int(av[1]);
        else if (t == 'f')
            conversation_f(av[1]);
               else if (t == 'd')
                    conversation_d(av[1]);
         conversation(av[1]);
    }
    else
        std::cout << "where is your number??" << std::endl;
} */

int main(int ac, char **av){
    if(ac != 2){
        std::cout << "where is your number??" << std::endl;
        return (0);
    }
    Converter c;

    try{
        c.setStr(av[1]);
        c.convert();
        std::cout<< c;
    }
    catch(const std::exception& err){
        std::cout<<"Error: "<<err.what()<<std::endl;
    }
}