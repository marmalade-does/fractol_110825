/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lroberts <marvin@42.barcelona>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 08:04:12 by lroberts          #+#    #+#             */
/*   Updated: 2025/08/15 13:43:11 by lroberts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

/*
 * [0..799] -> [-2..+2]
 *
*/
double map(double unscaled_num, double new_min, double new_max, double old_min, double old_max)
{
    return (new_max - new_min) * (unscaled_num - old_min) / (old_max - old_min) + new_min;
}


/*
 * SUM complex
 *
 * fairly easy is vector addition
*/
t_complex   sum_complex(t_complex z1, t_complex z2)
{
    t_complex   result;

    result.x = z1.x + z2.x;
    result.y = z1.y + z2.y;
    return result;
}


/*
 * SQUARE is trickier
 *
 * real = (x^2 - y^2)
 * i =  2*x*y
*/
t_complex   square_complex(t_complex z)
{
    t_complex   result;
    
    result.x = (z.x * z.x) - (z.y * z.y);
    result.y = 2 * z.x * z.y;
    return result;
}

// // This functin actually scales things
// double map(double unscaled_num, double new_min, double new_max, double old_min, double old_max)
// {
// 	return ((new_max - new_min) * ((unscaled_num - old_min) / (old_max - old_min) + new_min));
// }

// /*
//  * SUM complex
//  *
//  * fairly easy is vector addition
// */
// t_complex   sum_complex(t_complex z1, t_complex z2)
// {
//     t_complex   result;

//     result.re = z1.re + z2.re;
//     result.im = z1.im + z2.im;
//     return result;
// }


// /*
//  * SQUARE is trickier
//  *
//  * real = (x^2 - y^2)
//  * i =  2*x*y
// */
// t_complex   square_complex(t_complex z)
// {
//     t_complex   result;
    
//     result.re = (z.re * z.re) - (z.im * z.im);
//     result.im = 2 * z.re * z.im;
//     return result;
// }
