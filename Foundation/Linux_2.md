# 基础知识-Linux
> Created by wffx, 2019/8/24

本文主要介绍find，grep，awk，sed命令的基本知识和使用。这四个命令广泛应用与Linux中的字符串查找，匹配，处理等等。
之前在twitter上看到一个投票，问在linux中最被忽略但实际非常好用的命令，给了四个选项，就是本文分享的四个指令，find, grep, awk, sed。

## grep (global regular expression print)

顾名思义，grep将从输入的文件中找出匹配的字符串，并打印出对应的行。  
它的实现就是将文件中的每一行读书到buffer中，并开始匹配，如果在该行找到匹配的字符串就输出，直到最后一行。

> 具体使用，man grep

## awk
awk是一个文本模式扫描和处理的语言，由Aho, Weinberger & Kernighan创建，即名字由来。功能十分强大，可以做简单数据处理。
它的使用也非常广泛，本科当时做的NS2的网络仿真实验，仿真输出就是awk脚本处理的。

这里主要不是侧重如何去写awk脚本，而是侧重在命令行中常用的一些文本处理。

### 基本结构
awk脚本文件结构：

~~~
BEGIN { …. initialization awk commands …}
{ …. awk commands for each line of the file…}
END { …. finalization awk commands …}
~~~
begin部分是预处理,变量的初始化；第二个大括号才是文本处理的主题部分；end是awk运行结束后的操作。

awk做文本处理时，是一行一行处理的，每一个行会按照分隔符划分成不同的域，我们分别用$0表示整行，$1表示第一列，$9表示第九列。（awk中的固定字符FS用来表示分隔符，eg:FS=":"）。

实例：

~~~
$ ll
total 52K
drwxr-xr-x 9 bjf bjf 4.0K Aug 19 23:23 Desktop
drwxr-xr-x 3 bjf bjf 4.0K Aug  6 17:08 Documents
drwxr-xr-x 6 bjf bjf 4.0K Aug  7 15:52 Downloads
drwxr-xr-x 8 bjf bjf 4.0K Aug  5 17:15 Git
drwxr-xr-x 3 bjf bjf 4.0K May 15 20:02 Music
drwxr-xr-x 2 bjf bjf 4.0K Aug 20 10:49 Pictures
drwxr-xr-x 2 bjf bjf 4.0K May 15 21:15 Program
drwxr-xr-x 2 bjf bjf 4.0K May 15 16:58 Public
drwxr-xr-x 6 bjf bjf 4.0K Jul 27 14:41 snap
drwxr-xr-x 2 bjf bjf 4.0K May 15 16:58 Templates
drwxrwxr-x 3 bjf bjf 4.0K May 25 11:34 Tex
drwxr-xr-x 2 bjf bjf 4.0K May 15 16:58 Videos
drwxrwxr-x 3 bjf bjf 4.0K Jun 26 21:35 Workspace

$ ll | awk '{print $9}'

Desktop
Documents
Downloads
Git
Music
Pictures
Program
Public
snap
Templates
Tex
Videos
Workspace

~~~

### 基本语法

awk控制语句包括：
~~~
if (condition) statement [ else statement ]
while (condition) statement
do statement while (condition)
for (expr1; expr2; expr3) statement
for (var in array) statement
break
continue
~~~

此外，awk还有丰富的输入输出，数字函数，字符串处理函数等内置函数供调用。

> 具体参考，man awk

## sed （stream editor）
sed在一次通过流的过程中，对输入流（文件或者来自管道的输入）进行文本转换，因此效率非常高。

### 基础用法
sed也是一行一行处理，默认在执行完命令后会将替换的文本直接输出到终端，当然也可以让他输出到新的文件，或者在源文件上进行修改。

常用：
~~~
sed -n -e 's/origin/replace/g' my_file 
sed -i -e 's/origin/replace' my_file
~~~
> man sed 获取更多的选项option

### regexps
sed能够完美的配合正则表达式的使用。

实例：
> sed -e 's/\/bin/\/usr\/local\/bin/' my_file > new_file

其中‘\/’为'/'的转义，最终将'/bin'替换成'/usr/local/bin'。可以将‘/\/’理解成分割两部分的标记。

> sed -e 's/[0-9]*/(&)/' my_file

其中"[0-9]*"匹配一串数字，‘&’代表匹配的数字，最终将匹配的数字左右分别加上括号。

### 其他用法
- 一般形式1
> sed -e '/pattern/ command' my_file  

其中'pattern'是正则表达式，'command'是sed支持的指令，比如's' = search & replace, 'p' = print, 'd' =
delete, 'i'=insert, 'a'=append等等。

实例：
> ls -l | sed -n -e '/^d/ p'  

'^d'表示文件夹，所以最终会将ls下所有的文件夹输出
> sed -e '/^#/ d' my_file

将所有'#'开头的行删除，输出。

- 一般形式2
> sed -e '1,100 command' my_file

将my_file中的1-100执行command命令。

实例：
> sed -e '5,$ d' my_file

表示将my_file从第五行到最后一行给删除，其中$表示最后一行。

## find 

find用来在指定目录下查找文件。和前面三个命令不同的地方在于，前面三者主要是用来处理具体文件内容，后者是用来查找文件名。

> man find

## Futher Reading

[See grep]( http://gnosis.cx/publish/programming/regular_expressions.html)  
[See sed]( http://www.grymoire.com/Unix/Sed.html)  
[Reference file](https://www-users.york.ac.uk/~mijp1/teaching/2nd_year_Comp_Lab/guides/grep_awk_sed.pdf)