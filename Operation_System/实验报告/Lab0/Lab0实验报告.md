# Lab0实验报告
## 思考题
### Thinking 0.1
Untracted.txt：`Unaracted files`，因为没被跟踪；

Stage.txt：`Changes to be committed`，add到暂存区，暂存了修改，可以被提交；

Modified.txt：`Changes not staged for commit`，跟踪过了，已修改未暂存；
### Thinking 0.2
add the file：`git add`

stage the file：`git add`

commit：`git commit`
### Thinking 0.3
1. `git checkout -- printf.c`，把文件恢复到工作区
2. `git reset HEAD printf.c`，`git checkout -- printf.c`,先撤销在暂存区删除文件的操作，再恢复到工作区
3. `git rm --cached Tucao.txt`，停止跟踪文件
### Thinking 0.4
第一次回退后，三次提交（3、2、1）变成两次（2、1），HEAD位于2；第二次回退后，变成一次（1）以及之前的提交，HEAD位于1；第三次操作，回到第三次提交HEAD位于3
### Thinking 0.5
1. 终端显示first
2. output.txt显示second
3. output.txt覆盖成third
4. output.txt显示third，第二行追加forth
### Thinking 0.6
command：
```
echo 'echo Shell Start...' > test
echo 'echo set a = 1' >> test
echo 'a=1' >> test
echo 'echo set b = 2' >> test
echo 'b=2' >> test
echo 'echo set c = a+b' >> test
echo 'c=$[$a+$b]' >> test
echo 'echo c = $c' >> test
echo 'echo save c to ./file1' >> test
echo 'echo $c>file1' >> test
echo 'echo save b to ./file2' >> test
echo 'echo $b>file2' >> test
echo 'echo save a to ./file3' >> test
echo 'echo $a>file3' >> test
echo 'echo save file1 file2 file3 to file4' >> test
echo 'cat file1>file4' >> test
echo 'cat file2>>file4' >> test
echo 'cat file3>>file4' >> test
echo 'echo save file4 to ./result' >> test
echo 'cat file4>>result' >> test
```
写入新文件时使用>覆盖写入，后续使用>>追加写入
result：
```
3
2
1
```
得到test后运行，终端显示：
```
Shell Start...
set a = 1
set b = 2
set c = a+b
c = 3
save c to ./file1
save b to ./file2
save a to ./file3
save file1 file2 file3 to file4
save file4 to ./result
```
执行test的时候，普通echo命令将内容输出到控制台，重定向echo和cat输出到对应文件，>覆盖>>追加
`echo echo Shell Start`：`echo Shell Start` ，作为echo的参数被输出
``echo `echo Shell Start` ``：反引号中的命令将子命令输出结果`Shell Start`作为参数传递给echo命令，并被输出
`echo echo $c>file1`：假设c赋值为111，则会创建文件file1并且写入`echo 111`，其中`echo $c`作为参数
`` echo `echo $c>file1` ``：反引号里的命令使c的值重定向输入file1，子命令的标准输出为空，传递给外层echo，控制台无输出

## 实验难点
思考题0.3中涉及使用checkout恢复文件，受其他课程中用于切换分支的干扰，不甚理解原理。后想通checkout本质是将文件或整个工作区恢复到某个特定状态，即用一些文件替换另一些文件，本质相同。

在Makefile的修改中，因为不能对代码文件头文件所修改，而失去方向，转而求助AI工具，得到不知所云的改路径、改头文件、改命令等诸多不知所云的内容。因此转回阅读指导手册，发现添加选项即可轻易解决此类问题，大道至简。
## 心得体会
初始操作系统，对许多并未涉足过的技术不甚了解，诸如git, Makefile此类。在实验的过程中边学文档、边动手实践是我加深了许多理解。

与之前诸多课程不同的是，感受到本门课的学习并非空中楼阁，而是与生产实际紧紧相依的学科，学起来颇有乐趣。