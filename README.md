# CPP-Snake
### by Shaunik Musukula

A simple console-based snake game. The base `.cpp` files are fit to compile in MacOS and the only build I have created is for MacOS (located in the builds folder).

To compile the file yourself run this set of commands (assuming you start in base directory):
```
cd src
g++ main.cpp -lncurses -o ../build/main
```

I have not created a version for Windows as some tools that I have used in the project cannot be compiled on Windows. To overcome this, I may rewrite some code to be able to be compiled on Windows.