## stand

`stand` is a visual aid program to unobrusively notify you to stand up (and exercise) during workday.

### Dependencies

The program is written in python3 and uses tkinter to create a graphical window.

* python3
* tkinter

For linux distributions using `apt` package manager

```console
sudo apt install python3 python3-tk
```

### How it works

`stand` is a program that creates a 50x50 window to the top left of the screen,
that is 50 minutes one color (blackish) and 10 minutes another color (red).
When the window is red, then it signals that one should be standing up.
The window is always on top of other windows.

To run `stand`, run the following command in the terminal

```console
python3 stand.py &
```

## TODO:

* update documentations for windows setup

## Author

Meelis Utt

