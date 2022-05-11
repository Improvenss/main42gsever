# Fract'ol @ 42

![screenshot](/screens/screen.png?raw=true)

A multithreaded fractal renderer.

## Features
* Render different fractals: mandelbrot, julia, burning ship
* Different color schemes (rotated and linear)
* Smooth and linear coloring

### Planned features
* Calculate values with OpenCL
* Selective anti-aliasing
* Chunked rendering to buffer while moving around

## Compiling and running
Run `make`. An executable will compile. Runs on OS X and Linux.

Run it with `./fractol [fractal]`. Possible fractals are: `mandelbrot`, `julia`,
`burningship`. Cycle color-schemes with `1-9` on the top row. Increase/decrease
maximum iterations with `*` and `/` on the numpad. Zoom in and out with the
mousewheel or with `+` and `-`. Press `Enter` on the numpad to switch between
smooth coloring and linear coloring.

## License
This project is licensed under the GNU General Public License 3.
