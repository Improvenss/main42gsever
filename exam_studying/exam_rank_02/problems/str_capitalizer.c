/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_capitalizer.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsever <gsever@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 18:47:30 by gsever            #+#    #+#             */
/*   Updated: 2022/09/16 19:07:43 by gsever           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int main(int argc, char **argv)
{
    int i;
    int j;

    if (argc >= 2)
    {
		i = 0;
    	j = 1;
        while(argv[j])
        {
            while(argv[j][i] != '\0')
            {
                if(argv[j][i] >='a' && argv[j][i] <= 'z' && i == 0)
                {
                    argv[j][i] = argv[j][i] - 32;
                    write(1,&argv[j][i],1);
                }
                else if(argv[j][i] >='A' && argv[j][i] <= 'Z' && i == 0)
                {
                    write(1,&argv[j][i],1);
                }
                else if(argv[j][i] >='a' && argv[j][i] <= 'z' && argv[j][i-1] == ' ')
                {
                	argv[j][i] = argv[j][i] - 32;
                    write(1,&argv[j][i],1);
                }
                 else if(argv[j][i] >='A' && argv[j][i] <= 'Z' && argv[j][i-1] != ' ')
                {
                    argv[j][i] = argv[j][i] + 32;
                    write(1,&argv[j][i],1);
                }
                else
					write(1,&argv[j][i],1);
                i++;
            }
            write(1,"\n",1);
            i=0;
            j++;
        }
    }
    else
    write(1,"\n",1);
    return (0);
}