LZ77

1. Lossless data compression algorithm
2. Published in 1977 by Abraham Lempel and Jacob Ziv
3. Variations: LZW, LZSS, LZMA and others

核心概念

LZ77持有在未压缩数据流出现过的数据的单一拷贝，并且将重复出现的的同样数据替换成对这一份数据的引用，以 实现数据压缩的目的。

匹配 每一个匹配都被编码成(length, distance)对，即长度为length的字符串中的每个字符与相同字符在未压缩的位置相差distance个字符。❓

滑动窗口 编码器追踪指定数量的最近数据，数量为2KB， 4KB 或 32KB。

伪代码

    while input is not empty do
        prefix := longest prefix of input that begins in window
    
        if prefix exists then
            i := distance to start of prefix
            l := length of prefix
            c := char following prefix in input
        else
            i := 0
            l := 0
            c := first char of input
        end if
    
        output (i, l, c)
    
        s := pop l+1 chars from front of input
        discard l+1 chars from front of window
        append s to back of window
    repeat

论文

压缩算法

字符串解析成长度不超过指定长度L_s的子串或者单词，编码框架将其映射为固定长度L_c的唯一可解密的编码。

二者之间的关系为：L_c = 1 + \lceil log(n - L_s) \rceil + \lceil logL_s \rceil(1)，其中对数的基底是字符集A的基Card(A) = \alpha

概念和定义

字符集：A = {0, 1, \cdots , \alpha - 1}

字符串长度：l(S) = k， 表示k元有序对S = s_1s_2\cdots s_k

子串：S(i, j)，当i \leq j时，S(i, j) = s_is_{i+1}\cdots s_j，当i \gt j时，S(i, j) = NULL

字符串结合：S = QR ，且l(S) = l(Q) + l(R)

(真)前缀：S(1, j)叫做字符串S的前缀，如果j \lt l(S)，那么S(1, j)叫做真前缀。0 \leq j \leq l(S)

给定真前缀S(1, j)和整数i \leq j， L(i) 表示满足l \leq l(S) - j的最大非负整数：S(i, i + l - 1) = S(j + 1, j + l)，并且让p是S(1, j)是其中一个位置满足L(p) = max_{1\leq i \leq j}\{L(i)\}

那么，子串S(j+1, j+L(p))就被称为字符串S中S(1, j)的可重现延伸

现在，为了描述编码过程，令S = s_1s_2\cdots表示源发出的字符串。S的序列化编码使得S解析成连续的源单词，S=S_1S_2\cdots，并且为每个S_i赋值一个编码C_i。对于有界延迟编码(bounded-delay encoding)，每个S_i的长度l_i最多等于已确定的参数L_s，而每个编码C_i的长度为固定长度L_c。

为了初始化编码过程，我们假定源的输出S前的字符串Z是n - L_s个零，并且我们将B_1 = ZS(1, L_s)存储在buffer中。如果S(1, j)是字符串ZS(1, L_s - 1)中Z的可重现延伸，那么S_1 = S(1, j+1)以及l_1 = j + 1。为了确定下一个源词，我们把前l_1个符号从缓存中移出，并且填入下l_1个S的符号得到字符串B_2 = B_1(l_1+1, n)S(L_s+1, L_s+l_1)。现在我们寻找B_2(1, n-1)中B_2(1, n-L_s)的可重现延伸E。并且令S_2 = Es，此处s是在B_2中紧接E的符号。总之，如果B_i表示buffer中的n个源符号的字符串当我们准备好确定第ith个源词S_i，连续的编码步骤可以形式化表达如下：

1. 设置B_1 = 0^{n-L_s}S(1, L_s)，也就是长度为n-L_s的全零字符串后面跟着S的前L_s个字符
2. 已经确定了B_i, i \leq 1。设S_i = B_i(n - L_s+1, n-L_s+l_i)，而S_i的长度为l_i - 1的前缀是B_i(1, n-1)中B_i(1, n - L_s)的可重现扩展
3. 如果p_i是用于确定S_i的可重现指针，那么S_i的编码C_i由C_i = C_{i1}C_{i2}C_{i3}给出，其中C_{i1}是p_i - 1和l(C_{i1}) = \lceil log(n-L_s)\rceil的radix-\alpha表示，C_{i2}是l_i - 1和l(C_{i2}) = \lceil logL_s\rceil的radix-\alpha表示，C_{i3}是S_i的最后的字符，即占据了B_i中的n-L_s + l_i位置。C_i的全部长度由下式给出：l(C_i) = \lceil log(n - L_s)\rceil + \lceil logL_s\rceil + 1
4. 为了更新buffer中的内容，移出buffer中前l_i个字符，同时从源中取出下l_i个字符填充进去，得到B_{i+1} = B_i(l_i + 1, n)S(h_i+1, h_i+l_i)，h_i表示B_i最后的字符在S中占据的位置。

以上完整地描述了编码过程。很容易验证由(2)定义的解析法则在每次迭代中确保了一个有界，正的源词长度。实际上，1 \leq l_i \leq L_s对于每个i都成立，因此考虑到l_i - 1和来自于A的\lceil log（L_s)\rceil个字符的radix-\alpha表示。因为1 \leq p_i \leq n -L_s对于每个i都成立，表示p_i-1和来自A的\lceil log(n - L_s)\rceil个字符是可能的。

解码过程只要将编码过程逆过来即可。我们采用长度为n - L_s的buffer来存储最近的解码字符。最开始，buffer中填充n-L_s个零字符。如果D_i = d_1d_2\cdots d_{n-L_s}表示buffer中的内容在C_{i-1}已经被解码成S_i - 1，然后

S_{i-1} = D_i(n - L_s - l_{i-1} + 1， n - L_s),\quad l_{i-1} = l(s_{i-1})

同时，D_{i+1}可以根据D_i和C_i获取，具体方式如下：

可以根据第一个\lceil log(n - L_s)\rceil和C_i的下\lceil logL_s\rceil个字符确定p_i - 1和l_i - 1。然后，在填充p_i到n-L_s的同时进行l_i-1次位移操作。第一次移位操作会将缓存内容由D_i变成：

D_{i}^{(1)} = d_2d_3\cdots d_{n-L_s}d_{p_i}= d_{1}^{(1)}d_{2}^{(1)}\cdots d_{n-L_s}^{(1)} 

类似地，如果j \lt l(S_i - 1)，第j个移位将D_{i}^{(j-1)} = d_1^{(j-1)}d_2^{(j-1)}\cdots d_{n-L_s}^{(j-1)}转换为D_{i}^{(j)} = d_1^{(j)}d_2^{(j)}\cdots d_{n-L_s}^{(j)}，完成l_i - 1次移位操作之后，再移位一次，把C_i的最后一个字符移入buffer的位置n-L_s。很容易验证buffer在最后的l_i = l(S_i)个位置上包含S_i。



示例

\alpha = 3

S = 001010210210212021021200\cdots

L_s = 9

n = 18

根据(1)得到L_c = 1 + log_{3}(18 - 9) + log_{3}9 = 5

最开始buffer填充n - L_s = 9个零值，紧接着是S的前L_s = 9个字符，即

B_1 = \underbrace{000000000}_{n - L_s = 9} + \underbrace{001010210}_{L_s = 9}



 为了确定第一个源词S_1，我们必须找到B_1(10, 17) = 00101021的最长前缀B_1(10, 9+l_1-1)。匹配B_1中起始位置p_1 \leq 9的子串然后设S_1 = B_1(10, 9+l_1)。易得S_1 = 001,\ l_1 = 3。指针p_1可以是1-9之间的任何一个数。令p_1 = 9。以3为基数的p_1 - 1 = 8两位数表示为C_{11} = 22，C_{12} = 02，C_{i3}是S_i的最后一个字符，即C_{13} = 1。由此得出C_1 = 22021。

为了得到buffer内容B_2，将前l_1 = 3个字符移出并填入下3个字符S(10, 12) = 210。第2，3和4步的细节展示如下：

B_2 = 000000000\overset{\downarrow}{0}1010210, \quad C_2 = 21102 \\
B_3 = 000010\overset{\downarrow}{1}02102102120, \quad C_3 = 20212\\
B_4 = 21\overset{\downarrow}{0}210212021021200, \quad C_4 = 02220







[1]: https://en.wikipedia.org/wiki/LZ77_and_LZ78	"LZ77 and LZ78"
[2]: https://www2.cs.duke.edu/courses/spring03/cps296.5/papers/ziv_lempel_1977_universal_algorithm.pdf	"Ziv_Lempel 1977"
[3]: http://jens.jm-s.de/comp/LZ77-JensMueller.pdf	"LZ77-JensMueller"
[4]: https://fenix.tecnico.ulisboa.pt/downloadFile/3779571247713/LempelZiv_Zeeh.pdf	"LempelZiv_Zeeh"
[5]: http://math.mit.edu/~goemans/18310S15/lempel-ziv-notes.pdf	"Lempel-ziv-notes"

