

Makefile
	$(NAME) all clean fclean re bonus all

-lm man 3 math

//////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////

## Things from the video
[link](https://youtu.be/ANLW1zYbLcs)
[video only starts here](https://youtu.be/ANLW1zYbLcs?t=941)

just check this


## input -- done already in your main.c
* TODO: adapt your .h files and Makefile so that they compile the minilibx

to compile use this 
gcc *.c -Lminilibx-linux -lmlx_Linux -lX11 -lXext -o fratotl

The flags:
-lmlx_Linux -lX11 -lXext 
are explained in the 




























//////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////







//////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////



### requirements (obligatorty)
* use miniLibx

Renderising:
* Julia  + Mandelbrot
* wheel of computer does (near) infinite zoom
* Can change the parameters of Julia
* Some things about parameters
* colours

graphic representation
* image in a window
* **fluid** windows (change windows ,minimising, etc)
* propperly clean up when they press x
* use the images stuff that there is in MiniLbiX (not your own things)

Bonus:
* one more fractal (of your choice)
* zom follows the position of the mouse
* also, move around with the arrows
* Mkae the colour range change

double chek everythign beefore you hand in (no stupid machine will check ur work)

> Don't use `mlx_pixel_put` like I did at first. It’s slow and you can’t re-render the canvas. Use `mlx_put_image_to_window`


during linking time,need to do the `-lmlx -lXest -lX11` links

### Notes from the [documentation](https://qst0.github.io/ft_libgfx/man_mlx.html)

Function: `mlx_init()` 
Purpose: Function will creates connection software-display connection. Used for initalisation
Arguemnts: *none*
Return: void* identifier

**managing windows**
Function: `void *mlx_new_window(void *mlx_ptr, int size_x, int size_y, char *title)` 
Purpose: New window
Arguemnts: sizes ofo new window and title
Return: void* identifier to the new_window

Function: `mlx_clear_window ( void *mlx_ptr, void *win_ptr )` 
Purpose: clears in black
Arguemnts: mlx_ptr, the mlx_identifier; win_ptr, the window ptr
Return: nothing

Function: `int mlx_destroy_window ( void *mlx_ptr, void *win_ptr );`
Purpose: destroys the windoow
Arguemnts: mlx_ptr, the mlx_identifier; win_ptr, the window ptr
Return: nothing

**Drawing inside windows**

Function: `int mlx_pixel_put (void *mlx_ptr, void *win_ptr, int x, int y, int color);`
Purpose: put a colour in the speecifed point.
Arguemnts: mlx_ptr, win_ptr, coordinates, colour
Return: !!not sure, check the function prototypes in *.h to make sure!!

Function: `int mlx_string_put ( void *mlx_ptr, void *win_ptr, int x, int y, int color, char *string );`
Purpose: Puts string of points along x axis.
Arguemnts: mlx_ptr, the mlx_identifier; win_ptr, the window ptr
Return: !!not sure, check the function prototypes in *.h to make sure!!

**manipulating images**

Function: `void * mlx_new_image(void *mlx_ptr, int width, int height );`
Purpose: new image
Arguemnts: mlx_ptr and size
Return: void *ptr identifier for later

Function: `char *mlx_get_data_addr ( void *img_ptr, int *bits_per_pixel, int *size_line, int *endian );`
Purpose: puts gets data from image allowing user modification
Arguemnts: img_ptr, ptr to the image; int *bits_per_pixel, number of bits to represent a pixel colour (8 * 4 in our case [?]); size_line # of bytes to store one line of image in memory; endian, weather to store pixel colour in little `(endian == 0)`, or big `(endian == 1)`.
Return: char * to memory with image (if you add bits_per_pixel you moove to the next pixel, if you add size_line you moove to the next line)

Function: `int mlx_put_image_to_window(void*mlx_ptr, void *win_ptr, void *img_ptr, int x, int y);`
Purpose: puts the image to the window
Arguemnts: mlx_ptr, win_ptr, img_ptr, cordinates in window
Return: !not sure!

Function: `unsigned int mlx_get_color_value(void *mlx_ptr, int color );`
Purpose: turns the int colour encoding into an unsigned int for computer to understand.
Arguemnts: mlx_ptr, colur encoding
Return: unsigned int 

Function: `mlx_xpm_to_image ( void *mlx_ptr, char **xpm_data, int *width, int *height );`
Purpose: Fill xlm with a specific xmp image_data
Arguemnts: mlx_ptr, xmp_data, size
Return: unsigned int 

Function: `void *mlx_xpm_file_to_image(void *mlx_ptr, char *filename, int *width, int *height);`
Purpose: Fill the mlx iwth the data from a give file
Arguemnts: mlx_ptr, filename
Return: unsigned int

Function: `int mlx_destroy_image(void *mlx_ptr, void *img_ptr );`
Purpose: destroys memory for a given image
Arguemnts: mlx_ptr and img_ptr
Return: 

**Dealing with hooks**


int mlx_key_hook(void *win_ptr, int (*funct_ptr)(), void *param );
int mlx_mouse_hook(void *win_ptr, int (*funct_ptr)(), void *param );
int mlx_expose_hook(void *win_ptr, int (*funct_ptr)(), void *param );
int mlx_loop_hook(void *mlx_ptr, int (*funct_ptr)(), void *param );

Function: `mlx_*_hook`
Purpose: excutes the func_ptr with fixed parameters. below are example functions that you could make for each one
Arguemnts: mlx_ptr and img_ptr
Return: int type.

#### How do the events work
* There are 3 events: key pressing, mouse button pressing, widow should be redrawn "expose event"
* so you need to have the mlx_key_hook, mlx_mouse_hook, mlx_espose_hook, mlx_loop_hook in you main and then seperatly define functions for (these are the ones that you pass with the funciton-ptr to the mlx_*_hook)
expose_hook(void *param);
key_hook(int keycode,void *param);
mouse_hook(int button,int x,int y,void *param);
loop_hook(void *param);

#### How the colour encoding works
Colour is stored in an int:
ints have 4 bytes
* first byte = nothing;
* second byte = red component
* third byte = green component
* fourth byte = blue component

**playing with byte encodings**
* '<<' left shift, used with '|' OR to build things 
* '>>' right shift, used with '&' AND to extract things




### Some code snippets that will be useful

```c
/* In the parent function, say which one you need. do 
`fractol -> type = 'm'; fractol -> type = 'j'; fractol -> 
type = 'b'` for the three types */ 

// this woul need to be calculated for every hook that you have.
void ft_calculate_mandelbrot( ) 
{
	size_t i;
	size_t j;
	i = 0; // i has to be under some __MAX__
	j = 0; // j has to be under some __MAX__
	t_point *point;

	while(j < /*max len of y*/)
	{
		while(i < /*max len of x*/)
		{
			point -> x = i;
			point -> y = j;
			point -> iter = 0;
			ft_compute_m(point);
			ft_get_colour(point -> iter);
			ft_put_point(point -> point);
			i++;
		}
		j++;
	}
}

void ft_calculate_n(t_point *point)
{
	//something like the below
}
```

```c
for (int row = 0; row < height; row++) {
    for (int col = 0; col < width; col++) {
        double c_re = (col - width/2.0)*4.0/width;
        double c_im = (row - height/2.0)*4.0/width;
        double x = 0, y = 0;
        int iteration = 0;
        while (x*x+y*y <= 4 && iteration < max) {
            double x_new = x*x - y*y + c_re;
            y = 2*x*y + c_im;
            x = x_new;
            iteration++;
        }
        if (iteration < max) putpixel(col, row, colours[iterations]);
        else putpixel(col, row, black);
    }
}
```



The OG looks like this
```c

for (int row = 0; row < height; row++) {
    for (int col = 0; col < width; col++) {
        double c_re = (col - width/2.0)*4.0/width;
        double c_im = (row - height/2.0)*4.0/width;
        double x = 0, y = 0;
        int iteration = 0;
        while (x*x+y*y <= 4 && iteration < max) {
            double x_new = x*x - y*y + c_re;
            y = 2*x*y + c_im;
            x = x_new;
            iteration++;
        }
        if (iteration < max) putpixel(col, row, colours[iterations]);
        else putpixel(col, row, black);
    }
}
```

$x_{k+1} = x_k^2 - y_k^2 + \text{Re } c$

$y_{k+1} = 2x_k y_k + \text{Im } c$


#### Here is the code from the guide on the three fractools that you can calculate:

**Mandelbrot**
```c
void calculate_mandelbrot(t_fractal *fractal)
{
 int  i;
 double x_temp;

 fractal->name = "mandel";
 i = 0;
 fractal->zx = 0.0;
 fractal->zy = 0.0;
 fractal->cx = (fractal->x / fractal->zoom) + fractal->offset_x;
 fractal->cy = (fractal->y / fractal->zoom) + fractal->offset_y;
 while (++i < fractal->max_iterations)
 {
  x_temp = fractal->zx * fractal->zx - fractal->zy * fractal->zy
   + fractal->cx;
  fractal->zy = 2. * fractal->zx * fractal->zy + fractal->cy;
  fractal->zx = x_temp;
  if (fractal->zx * fractal->zx + fractal->zy
   * fractal->zy >= __DBL_MAX__)
   break ;
 }
 if (i == fractal->max_iterations)
  put_color_to_pixel(fractal, fractal->x, fractal->y, 0x000000);
 else
  put_color_to_pixel(fractal, fractal->x, fractal->y, (fractal->color
    * i));
}
```

**Julia**
```c
void calculate_julia(t_fractal *fractal, double cx, double cy)
{
 int  i;
 double tmp;

 fractal->name = "julia";
 fractal->cx = cx;
 fractal->cy = cy;
 fractal->zx = fractal->x / fractal->zoom + fractal->offset_x;
 fractal->zy = fractal->y / fractal->zoom + fractal->offset_y;
 i = 0;
 while (++i < fractal->max_iterations)
 {
  tmp = fractal->zx;
  fractal->zx = fractal->zx * fractal->zx - fractal->zy * fractal->zy
   + fractal->cx;
  fractal->zy = 2 * fractal->zy * tmp + fractal->cy;
  if (fractal->zx * fractal->zx + fractal->zy
   * fractal->zy >= __DBL_MAX__)
   break ;
 }
 if (i == fractal->max_iterations)
  put_color_to_pixel(fractal, fractal->x, fractal->y, 0x000000);
 else
  put_color_to_pixel(fractal, fractal->x, fractal->y, (fractal->color * (i
     % 255)));
}

```

**Burning ship**
```c
void calculate_burning_ship(t_fractal *fractal)
{
 int  i;
 double x_temp;

 fractal->name = "ship";
 i = 0;
 fractal->zx = 0.0;
 fractal->zy = 0.0;
 fractal->cx = (fractal->x / fractal->zoom) + fractal->offset_x;
 fractal->cy = (fractal->y / fractal->zoom) + fractal->offset_y;
 while (++i < fractal->max_iterations)
 {
  x_temp = fractal->zx * fractal->zx - fractal->zy * fractal->zy
   + fractal->cx;
  fractal->zy = fabs(2.0 * fractal->zx * fractal->zy) + fractal->cy;
  fractal->zx = fabs(x_temp);
  if (fractal->zx * fractal->zx + fractal->zy
   * fractal->zy >= __DBL_MAX__)
   break ;
 }
 if (i == fractal->max_iterations)
  put_color_to_pixel(fractal, fractal->x, fractal->y, 0x000000);
 else
  put_color_to_pixel(fractal, fractal->x, fractal->y, (fractal->color
    * i));
}

```


