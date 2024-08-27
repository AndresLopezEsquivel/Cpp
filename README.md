To identify executables in the repository and add them to the .gitignore file, run

```
find . -path './.git' -prune -o -type f -perm -u=x -print >> .gitignore
```
