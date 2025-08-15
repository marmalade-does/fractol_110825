/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lroberts <marvin@42.barcelona>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 21:23:38 by lroberts          #+#    #+#             */
/*   Updated: 2025/08/15 13:44:27 by lroberts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../includes/fractol.h"

///////////////////// HERE ARE THE THINGS THAT HE WROTE ////////////////
/*
 * If MALLOC goes bad (improbable)
*/
static void	malloc_error(void)
{
	perror("Problems with malloc");
	exit(EXIT_FAILURE);
}



static void	data_init(t_fractal *fractal)
{
	fractal->escape_value = 4; // 2 ^ 2, my hypotenuse
	fractal->iterations_defintion = 42; 
	fractal->shift_x = 0.0;
	fractal->shift_y = 0.0;
	// zoom factor
	fractal->zoom = 1.0;
}


static void	events_init(t_fractal *fractal)
{
	mlx_hook(fractal->mlx_window,
			KeyPress,
			KeyPressMask,
			key_handler,
			fractal);
	mlx_hook(fractal->mlx_window,
			ButtonPress,
			ButtonPressMask,
			mouse_handler,
			fractal);
	mlx_hook(fractal->mlx_window,
			DestroyNotify,
			StructureNotifyMask,
			close_handler,
			fractal);
	mlx_hook(fractal->mlx_window,
			MotionNotify,
			PointerMotionMask,
			julia_track,
			fractal);
}

/*
 * INIT 
 * ~mlx
 * ~listening events
 * ~hooks data
*/
void	fractal_init(t_fractal *fractal)
{
	//MLX stuff
	fractal->mlx_connection = mlx_init();
	if (NULL == fractal->mlx_connection)
		malloc_error();
	fractal->mlx_window = mlx_new_window(fractal->mlx_connection,
										WIDTH,
										HEIGHT,
										fractal->name);
	if (NULL == fractal->mlx_window)
	{
		mlx_destroy_display(fractal->mlx_connection);
		free(fractal->mlx_connection);
		malloc_error();
	}
	fractal->img.img_ptr = mlx_new_image(fractal->mlx_connection,
										WIDTH, HEIGHT);
	if (NULL == fractal->img.img_ptr)
	{
		mlx_destroy_window(fractal->mlx_connection, fractal->mlx_window);
		mlx_destroy_display(fractal->mlx_connection);
		free(fractal->mlx_connection);
		malloc_error();
	}
	fractal->img.pixels_ptr = mlx_get_data_addr(fractal->img.img_ptr,
												&fractal->img.bpp,
												&fractal->img.line_len,
												&fractal->img.endian);
	events_init(fractal);
	data_init(fractal);
}


//////////////////// HERE ARE THE THINGS THAT I WROTE ///////////////

// #include "../includes/fractol.h"

// void    fractal_init(t_fractal *fractal)
// {
//     // MLX stuff
//     fractal->mlx_connection = mlx_init();
//     if (NULL == fractal->mlx_connection)
//         malloc_error(); // TODO
//     fractal->mlx_window = mlx_new_window(fractal->mlx_connection,
//                                          WIDTH, size_x,
//                                          HEIGHT, size_y,
//                                          fractal->name);

//     if (NULL == fractal->mlx_window)
//     {
//         mlx_destroy_display(fractal->mlx_connection);
//         free(fractal->mlx_connection);
//         malloc_error();
//     }

//     fractal->img.img_ptr = mlx_new_image(fractal->mlx_connection,
//                                          WIDTH, HEIGHT);
//     if (NULL == fractal->img.img_ptr)
//     {
//         mlx_destroy_window(fractal->mlx_connection, win_ptr);
//         mlx_destroy_display(fractal->mlx_connection);
//         free(fractal->mlx_connection);
//         malloc_error();
//     }
// }




// void data_init(t_fractal *fractal)
// {
// 	fractal->escape_value = 4; // 2 + 2s
// 	fractal->iterations_defintion - 25; // hee did 42 here

// }


// void initialise_fract(t_fractol *fractol);
// {
// 	// MLX things
// 	fractol->connect_ptr_disp = mlx_init();
// 	if (fractol -> connect_ptr_win == NULL)
// 	{
// 		// TODO
// 		// he put "malloc_error()"
// 		// I think that ft_fail() is fine.
// 	}
// 	fractol-> win_ptr_disp = mlx_new_window(fractol -> connect_ptr_disp,
// 										WIDTH,
// 										HEIGHT,
// 										fractol->name);
// 	if (fractol -> win_ptr_disp == NULL)
// 	{
// 		mlx_destroy_display(fractol->connect_ptr_win);
// 		free(fractol->connect_ptr_win);
// 		ft_fail() // he put malloc_error
// 	}
// 	fracol->_idata_char_ptr = mlx_new_image(fractol->mlx_connection, WIDTH, HEIGHT);
// 	if (fracol->_idata_char_ptr == NULL)
// 	{
// 		mlx_destroy_window(fractol->connect_ptr_win ,fractol-> win_ptr_disp); //  something aint right with how I have named these variables -- is different for oceano.
// 		mlx_destroy_display(fractol->connect_ptr_win);
// 		free(fractol->connect_ptr_win);

// 		ft_fail() // he put malloc_error
// 	}

// }
// void render_fractal(t_fractol *fractol);
// mlx_loop(t_fractol *fractol);


