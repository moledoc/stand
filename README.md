# stand

`stand` is a visual aid program to unobrusively notify you to stand up (and exercise) during workday.

## Dependencies

[raylib](https://github.com/raysan5/raylib) - what an awesome project!!!

I'm using specific version.
So for example if you clone and `cd` to the root of this project, then

```sh
wget https://github.com/raysan5/raylib/releases/download/5.0/raylib-5.0_linux_amd64.tar.gz
tar -xvzf ./raylib-5.0_linux_amd64.tar.gz
rm ./raylib-5.0_linux_amd64.tar.gz
```

## Running the program

To compile and run the program

```sh
cc -Wall -Wpedantic -o stand stand.c -I./raylib-5.0_linux_amd64/include -L./raylib-5.0_linux_amd64/lib -l:libraylib.a -lm
./stand
```

## Author

Meelis Utt
