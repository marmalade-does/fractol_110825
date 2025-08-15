
#include "../includes/fractol.h"



// this is all that his main is

int	main(int ac, char **av)
{
	t_fractal	fractal;


	if (2 == ac && !ft_strncmp(av[1], "mandelbrot", 10)
		|| 4 == ac && !ft_strncmp(av[1], "julia", 5))
	{
		fractal.name = av[1];
		if (!ft_strncmp(fractal.name, "julia", 5))
		{
			fractal.julia_x = atodbl(av[2]);
			fractal.julia_y = atodbl(av[3]);
		}
		//TL;DR
		//Prompt correct, kick off the application
		//1)
		fractal_init(&fractal);
		//2)
		fractal_render(&fractal);
		//3)
		mlx_loop(fractal.mlx_connection);
	}
	else
	{
		putstr_fd(ERROR_MESSAGE, STDERR_FILENO);
		exit(EXIT_FAILURE);
	}
}




// ////////////////  Things that I wrote --- integrate it soo othat it looks more like your codee
// void ft_fail(char *mmsg, int error);
// int main(int argc, char **argv)
// {
// 	t_fractal *fractal;

// 	if (ft_check_input(argc, argv))
// 	{
// 		// kick of aapliction
// 		// render the fractal
// 		// loop the rendering of the fractal, until the end
// 		fractal -> name = argv[1];
// 		initialise_fract();
// 		render_fractal();
// 		mlx_loop();
// 		write(1, "all good\n", 9);
// 		fractal = malloc(sizeof(fractal)); // hwo tf does he make a fracotl asi sin puntere

// 		if (fractal == NULL)
// 			ft_fail("main.c", errno);

// 	}
// 	else
// 	{
// 		ft_usage();
// 		ft_fail("fractal declaration failed", EXIT_FAILURE);
// 	}
// 	return (0);
// }

// int ft_check_input(int argc, char **argv)
// {
// 	float val1;
// 	float val2;

// 	if((argc == 2 && !ft_strncmp(argv[1], "mandelbrot", 10)))
// 		return (1);
// 	if ((argc == 2 && !ft_strncmp(argv[1], "burning_ship", 12)))
// 		return (1);
// 	if ((argc == 4 && !ft_strncmp(argv[1], "julia", 5) && ft_check_julia(argv[2], argv[3])))
// 		return (1);
// 	return (0);

// }

// static int	ft_is_valid_number(char *str, float *value)
// {
// 	char	*endptr;

// 	*value = ft_strtof(str, &endptr);
// 	if (*endptr != '\0')
// 		return (0);
// 	return (1);
// }

// static int	ft_is_in_range(float value)
// {
// 	return (value >= -2.0 && value <= 2.0);
// }

// /*
//  * @brief is a function that does perror and exit, you should pur errno as your exit value almost always
//  *
// **/
// void ft_fail(char *mmsg, int error)
// {
// 	perror(mmsg);
// 	exit(error);
// }

// int	ft_check_julia(char *str1, char *str2)
// {
// 	float	val1;
// 	float	val2;

// 	if (!str1 || !str2)
// 		return (0);
// 	if (!ft_is_valid_number(str1, &val1))
// 		return (0);
// 	if (!ft_is_valid_number(str2, &val2))
// 		return (0);
// 	if (!ft_is_in_range(val1) || !ft_is_in_range(val2))
// 		return (0);
// 	return (1);
// }

// /*
//  * almost always you should int error == errno
// */
// void ft_fail(const char *cntext, int error)
// {
// 	perror(cntext);
// 	exit(error);
// }

// void ft_usage(void)
// {
// 	ft_putstr_fd("Usage: ./fractol <fractol_name> [<param_1> <param_2>]\n", STDERR_FILENO);
// 	ft_putstr_fd("Options:\n", STDERR_FILENO);
// 	ft_putstr_fd("  mandelbrot: No parameters.\n", STDERR_FILENO);
// 	ft_putstr_fd("  julia: Requires <param_1> and <param_2> (-2 to +2).\n", STDERR_FILENO);
// 	ft_putstr_fd("  burning_ship: No parameters.\n", STDERR_FILENO);
// 	ft_putstr_fd("\033[1;31mError:\033[0m Invalid input! Read the instructions and try again :p\n", STDERR_FILENO);
// 	ft_putstr_fd("\033[1;35mBaka uwu~\033[0m You're so silly! Follow the instructions properly!\n", STDERR_FILENO);
// }