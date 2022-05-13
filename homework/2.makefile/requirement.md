### homework 2

#### Makefile文件改写

要求：

- 将以下`makefile`文件改写并在`./src/`目录下 `make`, 不能使用: 文件名、`gcc`
- 可以使用的符号: `$, CC, @, <, ^, (), % `， 可以使用的函数：`wildcard , patsubst`

```makefile
app:sub.o add.o mult.o div.o main.o
	gcc sub.o add.o mult.o div.o main.o -o app

sub.o:sub.c
	gcc -c sub.c -o sub.o

add.o:add.c
	gcc -c add.c -o add.o

mult.o:mult.c
	gcc -c mult.c -o mult.o

div.o:div.c
	gcc -c div.c -o div.o

main.o:main.c
	gcc -c main.c -o main.o
```

