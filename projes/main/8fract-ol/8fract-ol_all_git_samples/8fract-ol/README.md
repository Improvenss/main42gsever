# 42-fractol

Fract`ol is on of the first computer graphics projects in the 42 core curriculum, where you work with the miniLibx-Library. The project is meant to create graphically beautiful fractals. Its really inspiring to dive into this topic and create some sort of psychedelic effects on the screen.

For further information about this topic I recommend to read this [Bachelor Thesis](https://theses.liacs.nl/pdf/2018-2019-JonckheereLSde.pdf) from Luc de Jonckheere. It describes methods to generate the Mandelbrot and Julia sets efficiently and how to implement a good coloring. For me this thesis was really helpful to get a better understanding of the project.

### 🧭 Start here

**The only supported and tested operating system to compile this programm is ```macOS```.**

1. Clone Repo and run: ```make release```
2. To see the possible arguments to run it, just start the "fractol": ```./fractol```

**General example:** ```./fractol mandelbrot```
* [julia-fractal] start the programm with 2 additional arguments, for example: ```./fractol julia 0.28 0.008```

<hr>

### 🕹 Take the control:
| Key / Input  | What it does |
| :---         | :---         |
| ```ARROWS```  | move through the picture |
| ```.```  | change color scheme |
| ```+``` & ```-``` | change the max iteration depth |
| ```SPACE BAR```  | [just julia-fractal] hit it ones and you be able to move the mouse to change the julia constant |
| ```Num Keys (1, 2, 3, ...)```  | change into different fractals |
| ```R```  | reset to default parameters |
| ```ESC```  | exit the Programm |

<hr>

<br>
<h3 align="center">Sample output:</h3>

<img width="1112" alt="Startup Screen / Fractal Mandelbrot" src="https://user-images.githubusercontent.com/56789534/134894764-b97280e8-534f-46d7-93f6-c1eea4464934.png">
<img width="992" alt="Seahorse paradise in Mandelbrot" src="https://user-images.githubusercontent.com/56789534/134895035-e320a04b-d25c-4e45-b5b4-bab20d4b1737.png">
<img width="993" alt="Some random are in a fractal" src="https://user-images.githubusercontent.com/56789534/134894702-52a09d27-586c-4b5f-a7f5-f1fb3577869f.png">



<br>
<hr>
<b>*All 42 projects must be written in C (later C++) in accordance to the 42 School Norm.<br></b>
<br>

> #### Sample restrictions:
> - All variables have to be declared and aligned at the top of each function
> - Each function can not have more then 25 lines
> - Projects should be created with allowed std functions otherwise it is cheating
