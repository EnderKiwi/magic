# magic lib

A magical library with big plans ahead

I finally got around to making a pretty printing function... I've been plotting for YEARS at this point, and I decided I was going to do it.

## Usage

### `void print(const char *fmt)` function

Basic pretty printing function. Can format any number of arguments like you would with `printf` but slightly different (and not yet complete). Also has support for colors, and other styles!

To substitute values you use `{TYPE}` with `TYPE` being either `i` for integer, `f` for floats/doubles, `s` for strings (`char *`), `c` for chars, and `p` for pointers. That's it for now, there will be more in the future, and maybe even an extensible type... For now, it ignores all but the first character, so you could have `{integer}` or `{int}` or `{float}` and it would work fine. Formatting options coming soon also...

To add colors and other styles, use `[STYLE]` with `STYLE` being a color, a style like 'bold', or reset. Most styles have two aliases you can use. For background colors there are two options, the actual option (i.e. `redbg`, `bluebg`) or the color with 'background' (i.e. `red background`, `blue background`). More info on colors is in `src/colors.h`.

## License

This project uses the GNU AFFERO GENERAL PUBLIC LICENSE. Refer to `LICENSE`