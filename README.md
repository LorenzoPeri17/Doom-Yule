# Doom-Yule

## Because you didn't know you wanted to set fire to your terminal

![fire gif](Assets/fire-only.gif)

Have you ever had a terminal that you wanted to keep open, but your mind has now switched to another task and now you feel bad leaving it alone and abandoned? This is a normal feeling, right? It's not jusy me, right?

Well, if you have ever ran into this emotional conundrum, I have got u covered! With `doom-yule` you can have the doom fire algorithm ripping-and-tearing your terminal like a yule log (and rendered completely in ACSCII for max compatibility) to keep you warm and cozy during those long debugging nights.

![startup](Assets/startup.gif)

`doom-yule` is written in C, so the fire starts up like the bottom of your terminal is made of paraffine, and I have done my very best to restore all of your terminal and cursor settings right as I found them, so when you `ctrl-C` out you can pick up right where you left off!

## Installation

`doom-yule` is written in pure C, with no external dependencies apart from `libc`, so if you clone this repo and

```bash
make
```

you should be good to go!

If you love `doom-yule` and want to be able to set fire to _any_ terminal with a few key strokes, you can even

```bash
make install
```

to keep it in you path!

> ### Install tips
>
> * By default I'll try to install the binary in `/usr/local`, but you can specify a `PREFIX` to change the location, i.e.
>
>```bash
> PREFIX=/opt/homebrew make install
>```
>
> * You may need to
>
>```bash
> sudo make install
>```
>
> to get it to stick :)

## Usage

`doom-yule` tries to pick sensible settings for your terminal window, but if you want to customize your fire

```bash
doom-yule -h
```

should be your friend.

At the moment the binary supports the following flags:

* `-f` to cap the maximum fps of the fire (default 30), so I don't rip and tear your battery or CPY too much. `-f 0` uncaps the framerate - not for the faint of heart!

* `-s` sets roughly the vertical fire size. If you say nothing, by default `doom-yule` will pick a reasonable value based on the height of your terminal. But if you want to experiment, any number between `-s 2` and `-s 5` will work! Just avoid `-s 3` because, imho, it does not look very nice :)

## Credits

Huge kudos to the wonderful [DOOM-fire-zig](https://github.com/const-void/DOOM-fire-zig/) for the inspiration and for some tricks in the implementation I have shamelessly copied. Also shoutout to [DOOM-fire-algorithm](https://github.com/filipedeschamps/doom-fire-algorithm) for dor documenting the doom fire algorithm!
