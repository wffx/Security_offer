## 网络安全-注入篇

Reference: [CTF Wiki][ctf_wiki], 白帽子讲Web安全等

### SQL注入
通过在用户可控参数中注入 SQL 语法，破坏原有 SQL 结构，达到编写程序时意料之外结果的攻击行为。其成因可以归结为以下两个原因叠加造成的：

1. 程序编写者在处理应用程序和数据库交互时，使用字符串拼接的方式构造SQL语句
2. 未对用户可控参数进行足够的过滤便将参数内容拼接进入到SQL语句中

#### 盲注
所谓盲注，就是在服务器没有回显的情况下，或者没有其他任何信息的情况下，进行sql注入。主要目的是为了获取“调试信息”，如：判断sql是否注入成功，数据库信息，系统信息等等。

例子：
1. 在url后面添加“and 1=2”这种恒为错的条件，判断是否能获取查询结果。
~~~
url: http://newspaper.com/items.php?id=2 and 1=2
select title, description, body from items where id = 2 and 1=2
~~~
2. Timing Attack or 其他数据库函数调用
针对不同的数据库函数提供的api，执行相应api，获取不同执行结果，从而判断sql是否被执行
例子：
~~~
Mysql: benchmark(count, expr); database(), system_user(), current_user(), last_insert_id();
~~~

#### 常用技巧

猜测表名，字段名等等，进而获取我们想要的用户名，一般可以用自动化注入工具如sqlmap尝试
~~~
union select 1,2,3 from user;
union select 1,1,user_passwd from user;
~~~

> 在[书][ref_book]中还给出当注入的数据库用户有创建文件权限时的一个攻击例子。过程是这样，首先通过LOAD_FILE()将系统文件读出，再通过INTO_DUMPFIFE将该文件写入到系统中，
> 然后通过LOAD DATA INFILE将文件导入到创建的表中，最后就可以通过一般的注入技巧直接操作表数据了。
> 但其实在我本地的Ubuntu测试时失败，LOAD_FILE()返回为NULL，需要把Ubuntu的AppArmor给关掉才能执行成功或者AppArmor关掉对mysql的防护。

### 命令执行
在注入中执行自定义的函数，称之为命令执行，比如调用数据库中sys_eval, sys_exec等执行自定义的函数。

> 在[书][ref_book]中给出了一个例子，使用LOAD_FILE从本地的文件系统中导入一个共享库问价作为自定义函数。

[ctf_wiki]: https://ctf-wiki.github.io/ctf-wiki/
[ref_book]: 白帽子讲Web安全
