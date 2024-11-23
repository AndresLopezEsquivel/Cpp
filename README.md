Print executables to be removed:

```
find . -type d -name ".git" -prune -o -type f -executable -print
```

Remove executables:

```
find . -type d -name ".git" -prune -o -type f -executable -exec rm -v {} +
```

Example of how to compile:

```
g++ -o main main.cpp
```
